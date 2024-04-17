set -ev

CC=icx
CXX=icpx
CFLAGS="-O3 -g"
CXXFLAGS="-O3 -g -fsycl"
GPU_AWARE_MPI="ON"

export SYCL_ROOT=${CMPROOT}
if [ -d ${CMPROOT}/linux ]; then
  export SYCL_ROOT=${CMPROOT}/linux
fi

# Default build parameters
: ${BUILD_DIR:=`pwd`/build}
: ${INSTALL_DIR:=`pwd`/install}
: ${BUILD_TYPE:="RelWithDebInfo"}

: ${CC:="gcc"}
: ${CXX:="g++"}

: ${MPICC:="mpicc"}
: ${MPICXX:="mpicxx"}
: ${GPU_AWARE_MPI:="OFF"}
: ${NBUILD:=8}

if [ -d ${BUILD_DIR} ]; then
  echo "Removing existing build directory"
  rm -r ${BUILD_DIR}
fi

if [ -d ${INSTALL_DIR} ]; then
  echo "Removing existing install directory"
  rm -r ${INSTALL_DIR}
fi

cmake -S . -B ${BUILD_DIR} \
  -DCMAKE_BUILD_TYPE=${BUILD_TYPE} \
  -DCMAKE_INSTALL_PREFIX=${INSTALL_DIR} \
  -DCMAKE_PREFIX_PATH=${PREFIX_PATHS} \
  -DCMAKE_C_COMPILER=${CC} \
  -DCMAKE_CXX_COMPILER=${CXX} \
  -DCMAKE_C_FLAGS="${CFLAGS}" \
  -DCMAKE_CXX_FLAGS="${CXXFLAGS}" \
  -DMPI_C_COMPILER=${MPICC} \
  -DMPI_CXX_COMPILER=${MPICXX} \
  -DGPU_AWARE_MPI=${GPU_AWARE_MPI} \
  -DEXTERNAL_OCCA=${EXTERNAL_OCCA} &&
cmake --build ${BUILD_DIR} --parallel ${NBUILD} &&
cmake --install ${BUILD_DIR}
