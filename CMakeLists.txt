cmake_minimum_required(VERSION 3.12)
project(datastructures
	VERSION 0.0.0.1
	DESCRIPTION "A C-library of datastructures"
	LANGUAGES C
)

include(CTest)

set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 23)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
find_program(CLANG_TIDY NAME clang-tidy REQUIRED)
set(CMAKE_C_CLANG_TIDY ${CLANG_TIDY};
	--quiet;
	-config-file=${CMAKE_SOURCE_DIR}/.clang-tidy;
	-p ${CMAKE_BUILD_DIR};
)

include_directories(PUBLIC ./src/lib/)

add_subdirectory(./src/lib/)
add_subdirectory(./src/test/)
add_subdirectory(./src/demo/)
