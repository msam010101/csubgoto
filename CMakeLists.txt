cmake_minimum_required(VERSION 3.10)
project(csubgoto)

# Specify the path to the Clang installation
set(LLVM_ROOT "/usr/lib/llvm-10")

# Set the policy CMP0074 to NEW, which enables _ROOT variables
if(POLICY CMP0074)
  cmake_policy(SET CMP0074 NEW)
endif()

# Include Clang's include directories
include_directories(${LLVM_ROOT}/include)

# Add the executable
add_executable(csubgoto src/csubgoto.cpp)

# Explicitly link libclang
target_link_libraries(csubgoto ${LLVM_ROOT}/lib/libclang.so)
