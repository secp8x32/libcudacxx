//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
// SPDX-FileCopyrightText: Copyright (c) 2022 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
//
//===----------------------------------------------------------------------===//

#ifndef _LIBCUDACXX___TYPE_TRAITS_REMOVE_VOLATILE_H
#define _LIBCUDACXX___TYPE_TRAITS_REMOVE_VOLATILE_H

#ifndef __cuda_std__
#include <__config>
#endif // __cuda_std__

#if defined(_LIBCUDACXX_USE_PRAGMA_GCC_SYSTEM_HEADER)
#pragma GCC system_header
#endif

_LIBCUDACXX_BEGIN_NAMESPACE_STD

#if defined(_LIBCUDACXX_REMOVE_VOLATILE) && !defined(_LIBCUDACXX_USE_REMOVE_VOLATILE_FALLBACK)
template <class _Tp>
struct remove_volatile {
  using type _LIBCUDACXX_NODEBUG_TYPE = _LIBCUDACXX_REMOVE_VOLATILE(_Tp);
};

template <class _Tp>
using __remove_volatile_t = _LIBCUDACXX_REMOVE_VOLATILE(_Tp);

#else
template <class _Tp> struct _LIBCUDACXX_TEMPLATE_VIS remove_volatile               {typedef _Tp type;};
template <class _Tp> struct _LIBCUDACXX_TEMPLATE_VIS remove_volatile<volatile _Tp> {typedef _Tp type;};

template <class _Tp>
using __remove_volatile_t = typename remove_volatile<_Tp>::type;

#endif // defined(_LIBCUDACXX_REMOVE_VOLATILE) && !defined(_LIBCUDACXX_USE_REMOVE_VOLATILE_FALLBACK)

#if _LIBCUDACXX_STD_VER > 11
template <class _Tp> using remove_volatile_t = __remove_volatile_t<_Tp>;
#endif

_LIBCUDACXX_END_NAMESPACE_STD

#endif // _LIBCUDACXX___TYPE_TRAITS_REMOVE_VOLATILE_H
