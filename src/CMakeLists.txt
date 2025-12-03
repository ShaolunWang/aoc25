file(GLOB DAY_SOURCES CONFIGURE_DEPENDS "day*.cpp")

file(COPY ${PROJECT_SOURCE_DIR}/input
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

foreach(day_src ${DAY_SOURCES})
    get_filename_component(day_name ${day_src} NAME_WE)
    add_executable(${day_name} ${day_src})
	target_include_directories(${day_name} PUBLIC ${PROJECT_SOURCE_DIR}/include)
	target_link_libraries(${day_name} PRIVATE fmt::fmt)
endforeach()
