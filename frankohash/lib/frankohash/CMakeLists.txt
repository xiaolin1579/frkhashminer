# frankohash: C/C++ implementation of Frankohash, the Expanse Proof of Work algorithm.
# Copyright 2021-Present Christopher Franko.
# Licensed under the Apache License, Version 2.0.

add_library(frankohash)
add_library(frankohash::frankohash ALIAS frankohash)
target_link_libraries(frankohash PRIVATE frankohash::keccak)
target_include_directories(frankohash PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_sources(frankohash PRIVATE
    bit_manipulation.h
    builtins.h
    endianness.hpp
    ${PROJECT_SOURCE_DIR}/include/frankohash/frankohash.h
    ${PROJECT_SOURCE_DIR}/include/frankohash/frankohash.hpp
    frankohash-internal.hpp
    frankohash.cpp
    ${PROJECT_SOURCE_DIR}/include/frankohash/hash_types.h
    #managed.cpp
    kiss99.hpp
    primes.h
    primes.c
)


if(CABLE_COMPILER_GNULIKE AND NOT SANITIZE MATCHES undefined)
    target_compile_options(frankohash PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>)
endif()
