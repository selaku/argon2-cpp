// Copyright (c) 2019, Zpalmtree
//
// Please see the included LICENSE file for more information.

#pragma once

#include <cstdint>

#include "Argon2/Argon2.h"
#include "cpu_features/include/cpuinfo_x86.h"
#include "Intrinsics/X86/IncludeIntrinsics.h"

static const cpu_features::X86Features features = cpu_features::GetX86Info().features;

static const bool hasAVX512 = features.avx512f;
static const bool hasAVX2 = features.avx2;
static const bool hasSSE3 = features.sse3;
static const bool hasSSE2 = features.sse2;

void blamkaG1AVX2(
    __m256i& a0, __m256i& a1, __m256i& b0, __m256i& b1,
    __m256i& c0, __m256i& c1, __m256i& d0, __m256i& d1);

void blamkaG2AVX2(
    __m256i& a0, __m256i& a1, __m256i& b0, __m256i& b1,
    __m256i& c0, __m256i& c1, __m256i& d0, __m256i& d1);

void diagonalizeAVX2v1(__m256i& b0, __m256i& c0, __m256i& d0, __m256i& b1, __m256i& c1, __m256i& d1);

void diagonalizeAVX2v2(__m256i& b0, __m256i& b1, __m256i& c0, __m256i& c1, __m256i& d0, __m256i& d1);

void undiagonalizeAVX2v1(__m256i& b0, __m256i& c0, __m256i& d0, __m256i& b1, __m256i& c1, __m256i& d1);

void undiagonalizeAVX2v2(__m256i& b0, __m256i& b1, __m256i& c0, __m256i& c1, __m256i& d0, __m256i& d1);

void processBlockAVX512(
    Block &nextBlock,
    const Block &refBlock,
    const Block &prevBlock,
    const bool doXor);

void processBlockAVX2(
    Block &nextBlock,
    const Block &refBlock,
    const Block &prevBlock,
    const bool doXor);

void processBlockSSE3(
    Block &nextBlock,
    const Block &refBlock,
    const Block &prevBlock,
    const bool doXor);

void processBlockSSE2(
    Block &nextBlock,
    const Block &refBlock,
    const Block &prevBlock,
    const bool doXor);
