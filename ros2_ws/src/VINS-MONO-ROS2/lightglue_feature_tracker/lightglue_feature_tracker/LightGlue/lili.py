import torch
from pathlib import Path
from lightglue import LightGlue, SuperPoint
from lightglue.utils import load_image, rbd
import matplotlib.pyplot as plt

# Charger les images
images = Path("assets")
image0 = load_image(images / "DSC_0411.JPG")
image1 = load_image(images / "DSC_0410.JPG")

# Définir le dispositif (GPU ou CPU)
device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

# Initialiser les extracteurs et le matcher
extractor = SuperPoint(max_num_keypoints=2048).eval().to(device)
matcher = LightGlue(features="superpoint").eval().to(device)

# Extraire les caractéristiques des deux images
feats0 = extractor.extract(image0.to(device))
feats1 = extractor.extract(image1.to(device))
matches01 = matcher({"image0": feats0, "image1": feats1})

# Supprimer la dimension de batch
feats0, feats1, matches01 = [rbd(x) for x in [feats0, feats1, matches01]]

# Extraire les points-clés et les correspondances
kpts0, kpts1, matches = feats0["keypoints"], feats1["keypoints"], matches01["matches"]
m_kpts0, m_kpts1 = kpts0[matches[..., 0]], kpts1[matches[..., 1]]

# Créer une figure pour afficher les correspondances
fig, ax = plt.subplots(1, 2, figsize=(10, 5))

# Afficher les deux images côte à côte
ax[0].imshow(image0.permute(1, 2, 0).cpu().numpy(), cmap="gray")
ax[0].axis("off")
ax[1].imshow(image1.permute(1, 2, 0).cpu().numpy(), cmap="gray")
ax[1].axis("off")

# Calculer l'offset pour aligner les points entre les deux images
offset_x = image0.shape[2]  # Largeur de la première image

# Tracer les correspondances (lignes vertes)
for p0, p1 in zip(m_kpts0.cpu().numpy(), m_kpts1.cpu().numpy()):
    x0, y0 = p0
    x1, y1 = p1
    ax[0].plot(x0, y0, 'o', color='lime', markersize=2)  # Points sur l'image de gauche
    ax[1].plot(x1, y1, 'o', color='lime', markersize=2)  # Points sur l'image de droite
    plt.plot([x0, x1 + offset_x], [y0, y1], color="lime", linewidth=0.5)

# Sauvegarder l'image avec correspondances en PNG
plt.tight_layout()
plt.savefig("matches_simple.png", dpi=300)
plt.close()
