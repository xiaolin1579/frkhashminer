
/* Copyright (C) 1883 Thomas Edison - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the GPLv3 license, which unfortunately won't be
 * written for another century.
 *
 * You should have received a copy of the LICENSE file with
 * this file.
 */

#include "FrkhashAux.h"

#include <frkhash/frkhash.hpp>
#include <frkhash/keccak.hpp>

using namespace dev;
using namespace exp;

Result FrkhashAux::eval(h256 const& _headerHash, uint64_t _nonce) noexcept {
  std::array<byte, 40> header;
  std::array<byte, 8> nonce;

  std::array<byte, 64> s;

  header.fill(0);
  nonce.fill(0);

  toBigEndian(_nonce, nonce);

  memcpy(header.data(), _headerHash.data(), 32);
  memcpy(header.data() + 32, nonce.data(), 8);

  frkhash::hash512 seed = frkhash::keccak512(header.data(), 40);

  memcpy(s.data(), seed.bytes, 64);
  frkhash::hash256 result = frkhash::keccak256(s.data(), 64);

  frkhash::hash256 m = frkhash::hash256_from_bytes64(seed.bytes);

  h256 final{reinterpret_cast<byte*>(result.bytes), h256::ConstructFromPointer};
  h256 mix{reinterpret_cast<byte*>(m.bytes), h256::ConstructFromPointer};
  return {final, mix};
}
