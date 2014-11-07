// The template and inlines for the -*- C++ -*- indirect_array class.

// Copyright (C) 1997, 1998, 1999, 2000, 2001, 2002
//  Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 2, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING.  If not, write to the Free
// Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307,
// USA.

// As a special exception, you may use this file as part of a free software
// library without restriction.  Specifically, if other files instantiate
// templates or use macros or inline functions from this file, or you compile
// this file and link it with other files to produce an executable, this
// file does not by itself cause the resulting executable to be covered by
// the GNU General Public License.  This exception does not however
// invalidate any other reasons why the executable file might be covered by
// the GNU General Public License.

// Written by Gabriel Dos Reis <Gabriel.Dos-Reis@DPTMaths.ENS-Cachan.Fr>

/** @file indirect_array.h
 *  This is an internal header file, included by other library headers.
 *  You should not attempt to use it directly.
 */

#ifndef _CPP_BITS_INDIRECT_ARRAY_H
#define _CPP_BITS_INDIRECT_ARRAY_H 1

#pragma GCC system_header

namespace std
{
  template <class _Tp>
     class indirect_array
     {
     public:
       typedef _Tp value_type;

       // XXX: This is a proposed resolution for DR-253.
       indirect_array& operator=(const indirect_array&);
       
       void operator=(const valarray<_Tp>&) const;
       void operator*=(const valarray<_Tp>&) const;
       void operator/=(const valarray<_Tp>&) const;
       void operator%=(const valarray<_Tp>&) const; 
       void operator+=(const valarray<_Tp>&) const;
       void operator-=(const valarray<_Tp>&) const;  
       void operator^=(const valarray<_Tp>&) const;
       void operator&=(const valarray<_Tp>&) const;
       void operator|=(const valarray<_Tp>&) const;
       void operator<<=(const valarray<_Tp>&) const;
       void operator>>=(const valarray<_Tp>&) const; 
       void operator= (const _Tp&) const;
       //    ~indirect_array();
       
       template<class _Dom>
         void operator=(const _Expr<_Dom, _Tp>&) const;
       template<class _Dom>
         void operator*=(const _Expr<_Dom, _Tp>&) const;
       template<class _Dom>
         void operator/=(const _Expr<_Dom, _Tp>&) const;
       template<class _Dom>
         void operator%=(const _Expr<_Dom, _Tp>&) const;
       template<class _Dom>
         void operator+=(const _Expr<_Dom, _Tp>&) const;
       template<class _Dom>
         void operator-=(const _Expr<_Dom, _Tp>&) const;
       template<class _Dom>
         void operator^=(const _Expr<_Dom, _Tp>&) const;
       template<class _Dom>
         void operator&=(const _Expr<_Dom, _Tp>&) const;
       template<class _Dom>
         void operator|=(const _Expr<_Dom, _Tp>&) const;
       template<class _Dom>
         void operator<<=(const _Expr<_Dom, _Tp>&) const;
       template<class _Dom>
         void operator>>=(const _Expr<_Dom, _Tp>&) const; 

     private:
       indirect_array(const indirect_array&);
       indirect_array(_Array<_Tp>, size_t, _Array<size_t>);

       friend class valarray<_Tp>;
       friend class gslice_array<_Tp>;
       
       const size_t 	 _M_sz;
       const _Array<size_t> _M_index;
       const _Array<_Tp> 	 _M_array;
       
       // not implemented
       indirect_array();
     };

  template<typename _Tp>
    inline 
    indirect_array<_Tp>::indirect_array(const indirect_array<_Tp>& __a)
      : _M_sz(__a._M_sz), _M_index(__a._M_index), _M_array(__a._M_array) {}

  template<typename _Tp>
     inline
     indirect_array<_Tp>::indirect_array(_Array<_Tp> __a, size_t __s, 
					 _Array<size_t> __i)
       : _M_sz(__s), _M_index(__i), _M_array(__a) {}

  template<typename _Tp>
     inline indirect_array<_Tp>&
     indirect_array<_Tp>::operator=(const indirect_array<_Tp>& __a)
     {
       __valarray_copy(__a._M_array, _M_sz, __a._M_index, _M_array, _M_index);
       return *this;
     }


  template<typename _Tp>
     inline void
     indirect_array<_Tp>::operator=(const _Tp& __t) const
     { __valarray_fill(_M_array, _M_index, _M_sz, __t); }

  template<typename _Tp>
     inline void
     indirect_array<_Tp>::operator=(const valarray<_Tp>& __v) const
     { __valarray_copy(_Array<_Tp>(__v), _M_sz, _M_array, _M_index); }

  template<typename _Tp>
     template<class _Dom>
       inline void
       indirect_array<_Tp>::operator=(const _Expr<_Dom,_Tp>& __e) const
       { __valarray_copy(__e, _M_sz, _M_array, _M_index); }

#undef _DEFINE_VALARRAY_OPERATOR
#define _DEFINE_VALARRAY_OPERATOR(_Op, _Name)				\
  template<typename _Tp>						\
    inline void								\
    indirect_array<_Tp>::operator _Op##=(const valarray<_Tp>& __v) const\
    {									\
      _Array_augmented_##_Name(_M_array, _M_index, _Array<_Tp>(__v), _M_sz); \
    }									\
									\
  template<typename _Tp>                                                \
    template<class _Dom>				                \
      inline void							\
      indirect_array<_Tp>::operator _Op##=(const _Expr<_Dom,_Tp>& __e) const\
      {									\
	_Array_augmented_##_Name(_M_array, _M_index, __e, _M_sz);	\
      }

_DEFINE_VALARRAY_OPERATOR(*, __multiplies)
_DEFINE_VALARRAY_OPERATOR(/, __divides)
_DEFINE_VALARRAY_OPERATOR(%, __modulus)
_DEFINE_VALARRAY_OPERATOR(+, __plus)
_DEFINE_VALARRAY_OPERATOR(-, __minus)
_DEFINE_VALARRAY_OPERATOR(^, __bitwise_xor)
_DEFINE_VALARRAY_OPERATOR(&, __bitwise_and)
_DEFINE_VALARRAY_OPERATOR(|, __bitwise_or)
_DEFINE_VALARRAY_OPERATOR(<<, __shift_left)
_DEFINE_VALARRAY_OPERATOR(>>, __shift_right)

#undef _DEFINE_VALARRAY_OPERATOR

} // std::

#endif /* _CPP_BITS_INDIRECT_ARRAY_H */

// Local Variables:
// mode:c++
// End:
