//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
// SPDX-FileCopyrightText: Copyright (c) 2022 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
//
//===----------------------------------------------------------------------===//

// <cuda/std/iterator>

// move_iterator

// template <RandomAccessIterator Iter1, RandomAccessIterator Iter2>
//   requires HasLess<Iter2, Iter1>
//   bool
//   operator<=(const move_iterator<Iter1>& x, const move_iterator<Iter2>& y);
//
//  constexpr in C++17

#include <cuda/std/iterator>
#include <cuda/std/cassert>

#include "test_macros.h"
#include "test_iterators.h"

template <class It>
__host__ __device__
void
test(It l, It r, bool x)
{
    const cuda::std::move_iterator<It> r1(l);
    const cuda::std::move_iterator<It> r2(r);
    assert((r1 <= r2) == x);
}

int main(int, char**)
{
    char s[] = "1234567890";
    test(random_access_iterator<char*>(s), random_access_iterator<char*>(s), true);
    test(random_access_iterator<char*>(s), random_access_iterator<char*>(s+1), true);
    test(random_access_iterator<char*>(s+1), random_access_iterator<char*>(s), false);
    test(s, s, true);
    test(s, s+1, true);
    test(s+1, s, false);

#if TEST_STD_VER > 14
    {
    constexpr const char *p = "123456789";
    typedef cuda::std::move_iterator<const char *> MI;
    constexpr MI it1 = cuda::std::make_move_iterator(p);
    constexpr MI it2 = cuda::std::make_move_iterator(p + 5);
    constexpr MI it3 = cuda::std::make_move_iterator(p);
    static_assert( (it1 <= it2), "");
    static_assert( (it1 <= it3), "");
    static_assert(!(it2 <= it3), "");
    }
#endif

  return 0;
}
