cmake_minimum_required(VERSION 3.24)
project(amadeus)
set(CMAKE_CXX_STANDARD 20)

# Set global include directory
include_directories(include)

# Create object libraries
function(object_from_source_header name)
	add_library(${name} OBJECT src/${name}.cpp)
	list(APPEND OBJECT_LIBRARIES $<TARGET_OBJECTS:${name}>)
endfunction()
set(SOURCE_HEADERS "")
foreach(source_header ${SOURCE_HEADERS})
	object_from_source_header(${source_header})
endforeach()

# Create main executable
add_executable(main main.cpp)
target_link_libraries(main ${OBJECT_LIBRARIES})

install(TARGETS main DESTINATION bin)
install(DIRECTORY include/amadeus TYPE INCLUDE)
