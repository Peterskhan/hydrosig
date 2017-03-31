#pragma once
#ifndef HYDROSIG_MAKE_FUN_0_H_INCLUDED
#define HYDROSIG_MAKE_FUN_0_H_INCLUDED

/*
 * MIT License
 *
 * Copyright (c) 2017 Peter Gyulai
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#include "functors/functor_0.hpp"
#include "macros.h"


HYDROSIG_NAMESPACE_BEGIN


template<class Return_type>
/**
 * @brief   Creates a functor from the given free function
 *          with zero arguments.
 * @details Note that returned functor must be deleted
 *          manually.
 * @param   function Pointer to the free function.
 * @return  A pointer to the created functor.
 */
functor_0_base<Return_type>*
make_fun(Return_type(*function)())
{
    try {
        return new functor_to_free_0<Return_type>
                   (function);
    }
    catch(...)
    {
        return nullptr;
    }
}

template<class Callable_type,
         class Return_type>
/**
 * @brief   Creates a functor from the given callable
            object expecting zero arguments.
 * @details Note that returned functor must be deleted
 *          manually.
 * @param   callable The callable object.
 * @return  A pointer to the created functor.
 */
functor_0_base<Return_type>*
make_fun(Callable_type callable)
{
    try {
        return new functor_to_callable_0<Callable_type,
                                         Return_type>
                   (callable);
    }
    catch(...)
    {
        return nullptr;
    }
}

template<class Object_type,
         class Return_type>
/**
 * @brief   Creates a functor from the given object
 *          and member function with zero arguments.
 * @details Note that returned functor must be deleted
 *          manually.
 * @param   object The object to perform the member function on.
 * @param   function Pointer to the member function.
 * @return  A pointer to the created functor.
 */
functor_0_base<Return_type>*
make_fun(Object_type* object, Return_type(Object_type::*function)())
{
    try {
        return new functor_to_member_0<Object_type,
                                       Return_type>
                   (object, function);
    }
    catch(...)
    {
        return nullptr;
    }
}

template<class Object_type,
         class Return_type>
/**
 * @brief   Creates a functor from the given object
 *          and const member function with zero arguments.
 * @details Note that returned functor must be deleted
 *          manually.
 * @param   object The object to perform the member function on.
 * @param   function Pointer to the member function.
 * @return  A pointer to the created functor.
 */
functor_0_base<Return_type>*
make_fun(Object_type* object, Return_type(Object_type::*function)() const)
{
    try {
        return new functor_to_member_const_0<Object_type,
                                             Return_type>
                   (object, function);
    }
    catch(...)
    {
        return nullptr;
    }
}

template<class Object_type,
         class Return_type>
/**
 * @brief   Creates a functor from the given object
 *          and volatile member function with zero arguments.
 * @details Note that returned functor must be deleted
 *          manually.
 * @param   object The object to perform the member function on.
 * @param   function Pointer to the member function.
 * @return  A pointer to the created functor.
 */
functor_0_base<Return_type>*
make_fun(Object_type* object, Return_type(Object_type::*function)() volatile)
{
    try {
        return new functor_to_member_volatile_0<Object_type,
                                                Return_type>
                   (object, function);
    }
    catch(...)
    {
        return nullptr;
    }
}

template<class Object_type,
         class Return_type>
/**
 * @brief   Creates a functor from the given object
 *          and const volatile member function with zero arguments.
 * @details Note that returned functor must be deleted
 *          manually.
 * @param   object The object to perform the member function on.
 * @param   function Pointer to the member function.
 * @return  A pointer to the created functor.
 */
functor_0_base<Return_type>*
make_fun(Object_type* object, Return_type(Object_type::*function)() const volatile)
{
    try {
        return new functor_to_member_const_volatile_0<Object_type,
                                                      Return_type>
                   (object, function);
    }
    catch(...)
    {
        return nullptr;
    }
}


HYDROSIG_NAMESPACE_END


#endif // HYDROSIG_MAKE_FUN_0_H_INCLUDED