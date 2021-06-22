/* frkhash: C/C++ implementation of Frankohash, the Expanse Proof of Work algorithm.
 * Copyright 2021-Present Christopher Franko.
 * Licensed under the Apache License, Version 2.0.
 */

#pragma once

#include <frkhash/hash_types.h>

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
#define NOEXCEPT noexcept
#else
#define NOEXCEPT
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**
 * The Frankohash algorithm revision implemented as specified in the Frankohash spec
 * https://github.com/ethereum/wiki/wiki/Frankohash.
 */
#define FRANKOHASH_REVISION "23"

struct frankohash_result
{
    union frankohash_hash256 final_hash;
    union frankohash_hash256 mix_hash;
};

struct frankohash_result frankohash_hash(
    const union frankohash_hash256* header_hash, uint64_t nonce) NOEXCEPT;

bool frankohash_verify(
    const union frankohash_hash256* header_hash, const union frankohash_hash256* mix_hash, uint64_t nonce,
    const union frankohash_hash256* boundary) NOEXCEPT;

bool frankohash_verify_final_hash(
    const union frankohash_hash256* mix_hash, uint64_t nonce,
    const union frankohash_hash256* boundary) NOEXCEPT;

#ifdef __cplusplus
}
#endif
