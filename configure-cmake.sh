CC=icx
CXX=icpx

SYCL_ROOT=${CMPROOT}/linux

# Default build parameters
: ${BUILD_DIR:=`pwd`/build}
: ${INSTALL_DIR:=`pwd`/install}
: ${BUILD_TYPE:="RelWithDebInfo"}

: ${CC:="gcc"}
: ${CXX:="g++"}

: ${MPICC:="mpicc"}
: ${MPICXX:="mpicxx"}

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
  -DEXTERNAL_OCCA=${EXTERNAL_OCCA}
