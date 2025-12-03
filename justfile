day := "day01"
@print:
	echo $(just --list)
conf:
	cmake -Wno-dev  -B build -D CMAKE_BUILD_TYPE=DEBUG  -G Ninja
build:
	cmake --build build
release: 
	cmake -B build_release -D CMAKE_BUILD_TYPE=RELEASE -G Ninja
release_build:
	cmake --build build_release 
clean:
	rm -rf build/ build_release
test:
	cd build && GTEST_COLOR=1 ctest -V

