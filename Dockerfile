FROM ubuntu:16.04

ARG MONGO_C_DRIVER_VER=1.19.0
ARG MONGO_CXX_DRIVER_VER=3.6.0

RUN apt-get -y update \
    && apt-get -y upgrade

RUN apt-get install -y \
    openssh-server \
    g++ \
    cmake \
    git 

#installing the mongo-c-driver and mongo-cxx-driver dependencies
RUN apt-get install -y \
    pkg-config \
    libssl-dev \ 
    libsasl2-dev

# mongo-c-driver install
RUN cd ~ \
    && wget https://github.com/mongodb/mongo-c-driver/releases/download/${MONGO_C_DRIVER_VER}/mongo-c-driver-${MONGO_C_DRIVER_VER}.tar.gz \
    && tar xzf mongo-c-driver-${MONGO_C_DRIVER_VER}.tar.gz \
    && cd mongo-c-driver-${MONGO_C_DRIVER_VER} \
    && mkdir cmake-build \
    && cd cmake-build \
    && cmake -DENABLE_AUTOMATIC_INIT_AND_CLEANUP=OFF .. \
    && make install \
    && cd ~ \
    && rm mongo-c-driver-${MONGO_C_DRIVER_VER}.tar.gz \
    && rm -rf mongo-c-driver-${MONGO_C_DRIVER_VER}

# mongo-cxx-driver install
RUN cd ~ \
    && wget https://github.com/mongodb/mongo-cxx-driver/archive/r${MONGO_CXX_DRIVER_VER}.tar.gz \
    && tar -xzf r${MONGO_CXX_DRIVER_VER}.tar.gz \
    && cd mongo-cxx-driver-r${MONGO_CXX_DRIVER_VER}/build \
    && cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_VERSION=${MONGO_CXX_DRIVER_VER} -DBSONCXX_POLY_USE_MNMLSTC=1 -DCMAKE_INSTALL_PREFIX=/usr/local .. \
    && make \
    && make install \
    && cd ~ \
    && rm r${MONGO_CXX_DRIVER_VER}.tar.gz \
    && rm -rf mongo-cxx-driver-r${MONGO_CXX_DRIVER_VER}