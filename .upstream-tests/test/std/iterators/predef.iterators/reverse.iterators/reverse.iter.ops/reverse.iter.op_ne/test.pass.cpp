//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
// SPDX-FileCopyrightText: Copyright (c) 2022 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
//
//===----------------------------------------------------------------------===//

// <cuda/std/iterator>

// reverse_iterator

// template <BidirectionalIterator Iter1, BidirectionalIterator Iter2>
//   requires HasEqualTo<Iter1, Iter2>
//   constexpr bool
//   operator!=(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y);
//
//   constexpr in C++17

#include <cuda/std/iterator>
#include <cuda/std/cassert>

#include "test_macros.h"
#include "test_iterators.h"

template <class It>
__host__ __device__
void
test(It l, It r, bool x)
{
    const cuda::std::reverse_iterator<It> r1(l);
    const cuda::std::reverse_iterator<It> r2(r);
    assert((r1 != r2) == x);
}

int main(int, char**)
{
    const char* s = "1234567890";
    test(bidirectional_iterator<const char*>(s), bidirectional_iterator<const char*>(s), false);
    test(bidirectional_iterator<const char*>(s), bidirectional_iterator<const char*>(s+1), true);
    test(random_access_iterator<const char*>(s), random_access_iterator<const char*>(s), false);
    test(random_access_iterator<const char*>(s), random_access_iterator<const char*>(s+1), true);
    test(s, s, false);
    test(s, s+1, true);

#if TEST_STD_VER > 14
    {
        constexpr const char *p = "123456789";
        typedef cuda::std::reverse_iterator<const char *> RI;
        constexpr RI it1 = cuda::std::make_reverse_iterator(p);
        constexpr RI it2 = cuda::std::make_reverse_iterator(p);
        constexpr RI it3 = cuda::std::make_reverse_iterator(p+1);
        static_assert(!(it1 != it2), "");
        static_assert( (it1 != it3), "");
    }
#endif

  return 0;
}
