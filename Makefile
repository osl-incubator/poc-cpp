
clean:
	git clean -xfd

build: clean
	mkdir -p ./build
	cd ./build && cmake .. && make
