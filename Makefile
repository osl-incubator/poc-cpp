# path
ROOT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))

# build
ROOT=cd arx
COMPILER=$(ROOT) && clang++
CLEAN=0
CXX=clang++
CC=clang

ARGS:=

# build flags
BUILD_TYPE:=release

.PHONY: clean-optional
clean-optional:
	bash ./scripts/optclean.sh
	mkdir -p build


.ONESHELL:
.PHONY: build
build: clean-optional
	set -ex
	meson setup \
		--prefix ${CONDA_PREFIX} \
		--libdir ${CONDA_PREFIX}/lib \
		--includedir ${CONDA_PREFIX}/include \
		--buildtype=${BUILD_TYPE} \
		--native-file meson.native ${ARGS} \
		build .
	meson compile -C build


.ONESHELL:
.PHONY: install
install:
	meson install -C build


.ONESHELL:
.PHONY: run-tests
run-tests:
	./build/poccpp
