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

// explicit move_iterator(Iter i);
//
//  constexpr in C++17

#include <cuda/std/iterator>
#include <cuda/std/cassert>

#include "test_macros.h"
#include "test_iterators.h"

template <class It>
__host__ __device__
void
test(It i)
{
    cuda::std::move_iterator<It> r(i);
    assert(r.base() == i);
}

int main(int, char**)
{
    char s[] = "123";
    test(input_iterator<char*>(s));
    test(forward_iterator<char*>(s));
    test(bidirectional_iterator<char*>(s));
    test(random_access_iterator<char*>(s));
    test(s);

#if TEST_STD_VER > 14
    {
    constexpr const char *p = "123456789";
    constexpr cuda::std::move_iterator<const char *> it(p);
    static_assert(it.base() == p);
    }
#endif

  return 0;
}
