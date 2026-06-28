# paths
OBJ_DIR := build

$(OBJ_DIR):
	mkdir -p $@

# targets
.PHONY: all dev build test clean

dev:
	cmake -G Ninja -DCMAKE_BUILD_TYPE=Debug -S . -B build && ninja -C build

build:
	cmake -G Ninja -DCMAKE_BUILD_TYPE=Release -S . -B build && ninja -C build

clean:
	rm -rf $(OBJ_DIR)/

.DEFAULT_GOAL := dev
