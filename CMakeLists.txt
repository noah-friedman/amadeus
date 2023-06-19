cmake_minimum_required(VERSION 3.24)
project(AMaDEUS)
set(CMAKE_C_STANDARD 17)

# Set global include directory
include_directories(include)

# Create object libraries
function(object_from_source_header name)
	add_library(${name} OBJECT src/${name}.c)
	list(APPEND OBJECT_LIBRARIES $<TARGET_OBJECTS:${name}>)
endfunction()
set(SOURCE_HEADERS prompt)
foreach(source_header ${SOURCE_HEADERS})
	object_from_source_header(${source_header})
endforeach()

# Create main executable
add_executable(main main.c)
target_link_libraries(main ${OBJECT_LIBRARIES})

install(TARGETS main DESTINATION bin)
install(DIRECTORY include/AMaDEUS TYPE INCLUDE)
