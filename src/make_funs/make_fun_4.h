#pragma once
#ifndef HYDROSIG_MAKE_FUN_4_H_INCLUDED
#define HYDROSIG_MAKE_FUN_4_H_INCLUDED

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

#include <stdexcept>

#include "src/macros.h"
#include "src/functors/functor_4.hpp"


HYDROSIG_NAMESPACE_BEGIN


/**
 * Function declarations:
 * ----------------------
 */

/**
 * @brief   Creates a functor from the given free function
 *          with four arguments.
 * @details Note that returned functor must be deleted
 *          manually.
 * @param   function Pointer to the free function.
 * @return  A pointer to the created functor.
 */
HYDROSIG_TEMPLATE_4_ARG
functor_4_base<HYDROSIG_4_ARG>* make_fun(Return_type(*function)
                                         (Arg1_type, Arg2_type, Arg3_type,
                                          Arg4_type));

/**
 * @brief   Creates a functor from the given callable
            object expecting four arguments.
 * @details Note that returned functor must be deleted
 *          manually.
 * @param   callable The callable object.
 * @return  A pointer to the created functor.
 */
HYDROSIG_TEMPLATE_CALLABLE_4_ARG
functor_4_base<HYDROSIG_4_ARG>* make_fun(Callable_type callable);

/**
 * @brief   Creates a functor from the given object
 *          and member function with four arguments.
 * @details Note that returned functor must be deleted
 *          manually.
 * @param   object The object to perform the member function on.
 * @param   function Pointer to the member function.
 * @return  A pointer to the created functor.
 */
HYDROSIG_TEMPLATE_OBJECT_4_ARG
functor_4_base<HYDROSIG_4_ARG>* make_fun(Object_type* object,
                                         Return_type(Object_type::*function)
                                         (Arg1_type, Arg2_type, Arg3_type,
                                          Arg4_type));

/**
 * @brief   Creates a functor from the given object
 *          and const member function with four arguments.
 * @details Note that returned functor must be deleted
 *          manually.
 * @param   object The object to perform the member function on.
 * @param   function Pointer to the member function.
 * @return  A pointer to the created functor.
 */
HYDROSIG_TEMPLATE_OBJECT_4_ARG
functor_4_base<HYDROSIG_4_ARG>* make_fun(Object_type* object,
                                         Return_type(Object_type::*function)
                                         (Arg1_type, Arg2_type, Arg3_type,
                                          Arg4_type)
                                         const);

/**
 * @brief   Creates a functor from the given object
 *          and volatile member function with four arguments.
 * @details Note that returned functor must be deleted
 *          manually.
 * @param   object The object to perform the member function on.
 * @param   function Pointer to the member function.
 * @return  A pointer to the created functor.
 */
HYDROSIG_TEMPLATE_OBJECT_4_ARG
functor_4_base<HYDROSIG_4_ARG>* make_fun(Object_type* object,
                                         Return_type(Object_type::*function)
                                         (Arg1_type, Arg2_type, Arg3_type,
                                          Arg4_type)
                                         volatile);

/**
 * @brief   Creates a functor from the given object
 *          and const volatile member function with four arguments.
 * @details Note that returned functor must be deleted
 *          manually.
 * @param   object The object to perform the member function on.
 * @param   function Pointer to the member function.
 * @return  A pointer to the created functor.
 */
HYDROSIG_TEMPLATE_OBJECT_4_ARG
functor_4_base<HYDROSIG_4_ARG>* make_fun(Object_type* object,
                                         Return_type(Object_type::*function)
                                         (Arg1_type, Arg2_type, Arg3_type,
                                          Arg4_type)
                                         const volatile);




/**
 * Function definitions:
 * ---------------------
 */

HYDROSIG_TEMPLATE_4_ARG
functor_4_base<HYDROSIG_4_ARG>* make_fun(Return_type(*function)
                                         (Arg1_type, Arg2_type, Arg3_type,
                                          Arg4_type))
{
    if(function == nullptr)
        throw std::invalid_argument("Nullptr provided as functor argument.");

    try {
        return new functor_to_free_4<HYDROSIG_4_ARG>
                   (function);
    }
    catch(...)
    {
        throw;
    }
}

HYDROSIG_TEMPLATE_CALLABLE_4_ARG
functor_4_base<HYDROSIG_4_ARG>* make_fun(Callable_type callable)
{
    try {
        return new functor_to_callable_4<HYDROSIG_CALLABLE_4_ARG>
                   (callable);
    }
    catch(...)
    {
        throw;
    }
}

HYDROSIG_TEMPLATE_OBJECT_4_ARG
functor_4_base<HYDROSIG_4_ARG>* make_fun(Object_type* object,
                                         Return_type(Object_type::*function)
                                         (Arg1_type, Arg2_type, Arg3_type,
                                          Arg4_type))
{
    if(function == nullptr || object == nullptr)
        throw std::invalid_argument("Nullptr provided as functor argument.");

    try {
        return new functor_to_member_4<HYDROSIG_OBJECT_4_ARG>
                   (object, function);
    }
    catch(...)
    {
        throw;
    }
}

HYDROSIG_TEMPLATE_OBJECT_4_ARG
functor_4_base<HYDROSIG_4_ARG>* make_fun(Object_type* object,
                                         Return_type(Object_type::*function)
                                         (Arg1_type, Arg2_type, Arg3_type,
                                          Arg4_type)
                                         const)
{
    if(function == nullptr || object == nullptr)
        throw std::invalid_argument("Nullptr provided as functor argument.");

    try {
        return new functor_to_member_const_4<HYDROSIG_OBJECT_4_ARG>
                   (object, function);
    }
    catch(...)
    {
        throw;
    }
}

HYDROSIG_TEMPLATE_OBJECT_4_ARG
functor_4_base<HYDROSIG_4_ARG>* make_fun(Object_type* object,
                                         Return_type(Object_type::*function)
                                         (Arg1_type, Arg2_type, Arg3_type,
                                          Arg4_type)
                                         volatile)
{
    if(function == nullptr || object == nullptr)
        throw std::invalid_argument("Nullptr provided as functor argument.");

    try {
        return new functor_to_member_volatile_4<HYDROSIG_OBJECT_4_ARG>
                   (object, function);
    }
    catch(...)
    {
        throw;
    }
}

HYDROSIG_TEMPLATE_OBJECT_4_ARG
functor_4_base<HYDROSIG_4_ARG>* make_fun(Object_type* object,
                                         Return_type(Object_type::*function)
                                         (Arg1_type, Arg2_type, Arg3_type,
                                          Arg4_type)
                                         const volatile)
{
    if(function == nullptr || object == nullptr)
        throw std::invalid_argument("Nullptr provided as functor argument.");

    try {
        return new functor_to_member_const_volatile_4<HYDROSIG_OBJECT_4_ARG>
                   (object, function);
    }
    catch(...)
    {
        throw;
    }
}


HYDROSIG_NAMESPACE_END


#endif // HYDROSIG_MAKE_FUN_4_H_INCLUDED
