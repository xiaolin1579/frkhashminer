// frankohash: C/C++ implementation of Frankohash, the Expanse Proof of Work algorithm.
// Copyright 2021-Present Christopher Franko.
// Licensed under the Apache License, Version 2.0.

#pragma once

#include <frankohash/keccak.h>
#include <frankohash/hash_types.hpp>

namespace frankohash
{
inline hash256 keccak256(const uint8_t* data, size_t size) noexcept
{
    return frankohash_keccak256(data, size);
}

inline hash256 keccak256(const hash256& input) noexcept
{
    return frankohash_keccak256_32(input.bytes);
}

inline hash512 keccak512(const uint8_t* data, size_t size) noexcept
{
    return frankohash_keccak512(data, size);
}

inline hash512 keccak512(const hash512& input) noexcept
{
    return frankohash_keccak512_64(input.bytes);
}

static constexpr auto keccak256_32 = frankohash_keccak256_32;
static constexpr auto keccak512_64 = frankohash_keccak512_64;

}  // namespace frankohash
