cmake_minimum_required(VERSION 3.24)
project(AMaDEUS)
set(CMAKE_C_STANDARD 17)

# Set global include directory
include_directories(include)

# For creating object libraries
function(object_from_source_header name)
	add_library(${name} OBJECT src/${name}.c)
endfunction()
set(SOURCE_HEADERS prompt)

# Create main executable
add_executable(main main.c)

# Generate and link object libraries
foreach(source_header ${SOURCE_HEADERS})
	object_from_source_header(${source_header})
    target_link_libraries(main $<TARGET_OBJECTS:${source_header}>)
endforeach()

install(TARGETS main DESTINATION bin)
install(DIRECTORY include/amadeus TYPE INCLUDE)
