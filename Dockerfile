FROM osrf/ros:foxy-desktop

RUN apt-get update && apt-get install -y \
    python3-pip \
    python3-colcon-common-extensions \
    git \
    cmake \
    build-essential \
    nano \
    curl \
    wget \
    && rm -rf /var/lib/apt/lists/*

# Installation d'Eigen 3.3.7
RUN cd /tmp && \
    wget https://gitlab.com/libeigen/eigen/-/archive/3.3.7/eigen-3.3.7.tar.gz && \
    tar -xzvf eigen-3.3.7.tar.gz && \
    cd eigen-3.3.7 && \
    mkdir build && \
    cd build && \
    cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local && \
    make install && \
    rm -rf /tmp/eigen-3.3.7*

# Installation de Ceres Solver 1.14.0
RUN apt-get update && apt-get install -y \
    libgoogle-glog-dev \
    libgflags-dev \
    libatlas-base-dev \
    libeigen3-dev \
    libsuitesparse-dev \
    && rm -rf /var/lib/apt/lists/*

RUN cd /tmp && \
    wget http://ceres-solver.org/ceres-solver-1.14.0.tar.gz && \
    tar -xzvf ceres-solver-1.14.0.tar.gz && \
    cd ceres-solver-1.14.0 && \
    mkdir build && \
    cd build && \
    cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local && \
    make -j4 && \
    make install && \
    rm -rf /tmp/ceres-solver-1.14.0*

RUN echo "source /opt/ros/foxy/setup.bash" >> /root/.bashrc

WORKDIR /workspace
