// frkhash: C/C++ implementation of Frankohash, the Expanse Proof of Work algorithm.
// Copyright 2021-Present Christopher Franko.
// Licensed under the Apache License, Version 2.0.

#pragma once

#include <frkhash/hash_types.h>

namespace frkhash
{
using hash256 = frankohash_hash256;
using hash512 = frankohash_hash512;
using hash1024 = frankohash_hash1024;
using hash2048 = frankohash_hash2048;
}  // namespace frkhash
