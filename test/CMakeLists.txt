################## add test lib #########################
if(CMAKE_BUILD_TYPE MATCHES DEBUG)
    include(FetchContent)
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    enable_testing()
    include(GoogleTest)

	file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/input
         DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

    # test + input
    file(GLOB DAY_TEST_SOURCES CONFIGURE_DEPENDS "test_day*.cpp")

    foreach(test_src ${DAY_TEST_SOURCES})
        get_filename_component(test_name ${test_src} NAME_WE)

        # Determine the corresponding day source
        string(REGEX REPLACE "test_(day[0-9]+)" "\\1" day_src_name ${test_name})
        set(day_src_path "${PROJECT_SOURCE_DIR}/src/${day_src_name}.cpp")

        if(EXISTS ${day_src_path})
            add_executable(${test_name} ${test_src} ${day_src_path})
			target_compile_definitions(${test_name} PRIVATE DEBUGTEST)
            target_include_directories(${test_name} PUBLIC ${PROJECT_SOURCE_DIR}/include)
            target_link_libraries(${test_name} PRIVATE fmt::fmt GTest::gtest_main)
            gtest_discover_tests(${test_name} DISCOVERY_ARGS "--gtest_color=yes" )
        else()
            message(WARNING "No source file found for ${test_name}: expected ${day_src_path}")
        endif()
    endforeach()
endif()
##########################################################

