// -*- C++ -*-
//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
// SPDX-FileCopyrightText: Copyright (c) 2022 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
//
//===----------------------------------------------------------------------===//

#ifndef _LIBCUDACXX___ITERATOR_REVERSE_ACCESS_H
#define _LIBCUDACXX___ITERATOR_REVERSE_ACCESS_H

#ifndef __cuda_std__
#include <__config>
#include <cstddef>
#include <initializer_list>
#endif // __cuda_std__

#include "../__iterator/reverse_iterator.h"

#if defined(_LIBCUDACXX_USE_PRAGMA_GCC_SYSTEM_HEADER)
#pragma GCC system_header
#endif

_LIBCUDACXX_BEGIN_NAMESPACE_STD

#if _LIBCUDACXX_STD_VER > 11

template <class _Tp, size_t _Np>
_LIBCUDACXX_INLINE_VISIBILITY _LIBCUDACXX_CONSTEXPR_AFTER_CXX14
reverse_iterator<_Tp*> rbegin(_Tp (&__array)[_Np])
{
    return reverse_iterator<_Tp*>(__array + _Np);
}

template <class _Tp, size_t _Np>
_LIBCUDACXX_INLINE_VISIBILITY _LIBCUDACXX_CONSTEXPR_AFTER_CXX14
reverse_iterator<_Tp*> rend(_Tp (&__array)[_Np])
{
    return reverse_iterator<_Tp*>(__array);
}

template <class _Ep>
_LIBCUDACXX_INLINE_VISIBILITY _LIBCUDACXX_CONSTEXPR_AFTER_CXX14
reverse_iterator<const _Ep*> rbegin(initializer_list<_Ep> __il)
{
    return reverse_iterator<const _Ep*>(__il.end());
}

template <class _Ep>
_LIBCUDACXX_INLINE_VISIBILITY _LIBCUDACXX_CONSTEXPR_AFTER_CXX14
reverse_iterator<const _Ep*> rend(initializer_list<_Ep> __il)
{
    return reverse_iterator<const _Ep*>(__il.begin());
}

template <class _Cp>
_LIBCUDACXX_INLINE_VISIBILITY _LIBCUDACXX_CONSTEXPR_AFTER_CXX14
auto rbegin(_Cp& __c) -> decltype(__c.rbegin())
{
    return __c.rbegin();
}

template <class _Cp>
_LIBCUDACXX_INLINE_VISIBILITY _LIBCUDACXX_CONSTEXPR_AFTER_CXX14
auto rbegin(const _Cp& __c) -> decltype(__c.rbegin())
{
    return __c.rbegin();
}

template <class _Cp>
_LIBCUDACXX_INLINE_VISIBILITY _LIBCUDACXX_CONSTEXPR_AFTER_CXX14
auto rend(_Cp& __c) -> decltype(__c.rend())
{
    return __c.rend();
}

template <class _Cp>
_LIBCUDACXX_INLINE_VISIBILITY _LIBCUDACXX_CONSTEXPR_AFTER_CXX14
auto rend(const _Cp& __c) -> decltype(__c.rend())
{
    return __c.rend();
}

template <class _Cp>
_LIBCUDACXX_INLINE_VISIBILITY _LIBCUDACXX_CONSTEXPR_AFTER_CXX14
auto crbegin(const _Cp& __c) -> decltype(_CUDA_VSTD::rbegin(__c))
{
    return _CUDA_VSTD::rbegin(__c);
}

template <class _Cp>
_LIBCUDACXX_INLINE_VISIBILITY _LIBCUDACXX_CONSTEXPR_AFTER_CXX14
auto crend(const _Cp& __c) -> decltype(_CUDA_VSTD::rend(__c))
{
    return _CUDA_VSTD::rend(__c);
}

#endif // _LIBCUDACXX_STD_VER > 11

_LIBCUDACXX_END_NAMESPACE_STD

#endif // _LIBCUDACXX___ITERATOR_REVERSE_ACCESS_H
