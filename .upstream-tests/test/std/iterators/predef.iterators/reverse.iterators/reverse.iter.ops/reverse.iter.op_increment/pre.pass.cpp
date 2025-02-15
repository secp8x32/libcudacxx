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

// constexpr reverse_iterator& operator++();
//
// constexpr in C++17

#include <cuda/std/iterator>
#include <cuda/std/cassert>

#include "test_macros.h"
#include "test_iterators.h"

template <class It>
__host__ __device__
void
test(It i, It x)
{
    cuda::std::reverse_iterator<It> r(i);
    cuda::std::reverse_iterator<It>& rr = ++r;
    assert(r.base() == x);
    assert(&rr == &r);
}

int main(int, char**)
{
    const char* s = "123";
    test(bidirectional_iterator<const char*>(s+1), bidirectional_iterator<const char*>(s));
    test(random_access_iterator<const char*>(s+1), random_access_iterator<const char*>(s));
    test(s+1, s);

#if TEST_STD_VER > 14
    {
        constexpr const char *p = "123456789";
        typedef cuda::std::reverse_iterator<const char *> RI;
        constexpr RI it1 = cuda::std::make_reverse_iterator(p);
        constexpr RI it2 = cuda::std::make_reverse_iterator(p+1);
        static_assert(it1 != it2, "");
        constexpr RI it3 = ++ cuda::std::make_reverse_iterator(p+1);
        static_assert(it1 == it3, "");
        static_assert(it2 != it3, "");
        static_assert(*(++cuda::std::make_reverse_iterator(p+2)) == '1', "");
    }
#endif

  return 0;
}
