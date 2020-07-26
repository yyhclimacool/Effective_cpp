#!/bin/bash

CURRENT_DIR=`pwd`
BUILD_DIR=${BUILD_DIR:-${CURRENT_DIR}/cmake_build}
BUILD_TYPE=${BUILD_TYPE:-Debug}
INSTALL_DIR=${INSTALL_DIR:-${BUILD_DIR}/${BUILD_TYPE}_install}

if [ "$1"x = "clean"x ]
then
  if [ -d ${BUILD_DIR} ]
  then
    LOG WARNING "rm -rf ${BUILD_DIR}"
    rm -rf ${BUILD_DIR}
  fi
  exit 0
fi

if [ ! -d ${BUILD_DIR} ]
then
  LOG "mkdir -p ${BUILD_DIR}"
  mkdir -p ${BUILD_DIR}
fi

cmake \
  -H${CURRENT_DIR} -B${BUILD_DIR} \
  -DCMAKE_INSTALL_PREFIX=${INSTALL_DIR} \
  -DCMAKE_BUILD_TYPE=${BUILD_TYPE} \
  -DCMAKE_EXPORT_COMPILE_COMMANDS=TRUE && \
cmake --build ${BUILD_DIR} -- -j && \
cmake --build ${BUILD_DIR} --target install
