//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
// SPDX-FileCopyrightText: Copyright (c) 2022 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
//
//===----------------------------------------------------------------------===//

// <cuda/std/iterator>

// template<class T>
// struct iterator_traits<T*>
// {
//   typedef ptrdiff_t                  difference_type;
//   typedef T                          value_type;
//   typedef T*                         pointer;
//   typedef T&                         reference;
//   typedef random_access_iterator_tag iterator_category;
// };

#include <cuda/std/iterator>
#include <cuda/std/type_traits>

#include "test_macros.h"

struct A {};

int main(int, char**)
{
    typedef cuda::std::iterator_traits<A*> It;
    static_assert((cuda::std::is_same<It::difference_type, cuda::std::ptrdiff_t>::value), "");
    static_assert((cuda::std::is_same<It::value_type, A>::value), "");
    static_assert((cuda::std::is_same<It::pointer, A*>::value), "");
    static_assert((cuda::std::is_same<It::reference, A&>::value), "");
    static_assert((cuda::std::is_same<It::iterator_category, cuda::std::random_access_iterator_tag>::value), "");

  return 0;
}
