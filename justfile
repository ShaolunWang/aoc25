day := "day03"
test_day :="Day03"
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
	cd build && ninja clean; cd ../build_release && ninja clean
test:
	cd build && GTEST_COLOR=1 ctest -V -R {{test_day}}
run:
	./build_release/src/{{day}}
