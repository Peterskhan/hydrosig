#pragma once
#ifndef HYDROSIG_FUNCTOR_7_HPP_INCLUDED
#define HYDROSIG_FUNCTOR_7_HPP_INCLUDED

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

#include "src/macros.h"
#include "src/functors/functor_base/functor_base.hpp"


HYDROSIG_NAMESPACE_BEGIN


/**
 * Class declarations:
 * -------------------
 */

/**
 * @brief   This class encapsulates a free function, such
 *          as a global or static member method with seven
 *          arguments.
 */
HYDROSIG_TEMPLATE_7_ARG
class functor_to_free_7 : public functor_7_base<HYDROSIG_7_ARG>
{
public:
    /**< Typedef for the function type */
    typedef Return_type(*function_type)(Arg1_type, Arg2_type, Arg3_type,
                                        Arg4_type, Arg5_type, Arg6_type,
                                        Arg7_type);

    /**
     * @brief   Constructs a functor_to_free_7 from the
     *          given function pointer.
     */
    functor_to_free_7(function_type function);

    /**
     * @brief   Calls the encapsulated function.
     * @return  The result of the function call.
     * @param   arg1 The first argument.
     * @param   arg2 The second argument.
     * @param   arg3 The third argument.
     * @param   arg4 The fourth argument.
     * @param   arg5 The fifth argument.
     * @param   arg6 The sixth argument.
     * @param   arg7 The seventh argument.
     */
    Return_type operator()(Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                           Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                           Arg7_type arg7);

    /**
     * @brief   Compares this functor with another for equality.
     * @details seven functors compare equal, if they refer to the
     *          same free function.
     * @param   other The other functor.
     * @return  True if the functors compare equal.
     */
    bool operator==(const functor_to_free_7 &other);

private:
    /**< Pointer to the encapsulated function */
    function_type m_function;

};

/**
 * @brief   This class encapsulates a callable object, such
 *          as a lambda-expression, expecting seven arguments.
 */
HYDROSIG_TEMPLATE_CALLABLE_7_ARG
class functor_to_callable_7 : public functor_7_base<HYDROSIG_7_ARG>
{
public:
    /**
     * @brief   Constructs a functor_to_callable_7 from the
     *          copy of the given callable object.
     */
    functor_to_callable_7(Callable_type callable);

    /**
     * @brief   Calls the encapsulated function.
     * @return  The result of the function call.
     * @param   arg1 The first argument.
     * @param   arg2 The second argument.
     * @param   arg3 The third argument.
     * @param   arg4 The fourth argument.
     * @param   arg5 The fifth argument.
     * @param   arg6 The sixth argument.
     * @param   arg7 The seventh argument.
     */
    Return_type operator()(Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                           Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                           Arg7_type arg7);

private:
    /**< The callable object */
    Callable_type m_callable;

};

/**
 * @brief   This class encapsulates a bound member function
 *          with seven arguments.
 */
HYDROSIG_TEMPLATE_OBJECT_7_ARG
class functor_to_member_7 : public functor_7_base<HYDROSIG_7_ARG>
{
public:
    /**< Typedef for the function type */
    typedef Return_type(Object_type::*function_type)
            (Arg1_type, Arg2_type, Arg3_type,
             Arg4_type, Arg5_type, Arg6_type,
             Arg7_type);

    /**
     * @brief   Constructs a functor_to_member_7 from pointer to
     *          the given object and a member function pointer.
     */
    functor_to_member_7(Object_type* object,
                        function_type function);

    /**
     * @brief   Calls the encapsulated function on the object.
     * @return  The result of the function call.
     * @param   arg1 The first argument.
     * @param   arg2 The second argument.
     * @param   arg3 The third argument.
     * @param   arg4 The fourth argument.
     * @param   arg5 The fifth argument.
     * @param   arg6 The sixth argument.
     * @param   arg7 The seventh argument.
     */
    Return_type operator()(Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                           Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                           Arg7_type arg7);

    /**
     * @brief   Compares this functor with another for equality.
     * @details seven functors compare equal, if they refer to the
     *          same member function of the same object.
     * @param   other The other functor.
     * @return  True if the functors compare equal.
     */
    bool operator==(const functor_to_member_7 &other);

private:
    /**< Pointer to the target object */
    Object_type*  m_object;

    /**< Pointer to the encapsulated function */
    function_type m_function;

};

/**
 * @brief   This class encapsulates a const bound member function
 *          with seven arguments.
 */
HYDROSIG_TEMPLATE_OBJECT_7_ARG
class functor_to_member_const_7 : public functor_7_base<HYDROSIG_7_ARG>
{
public:
    /**< Typedef for the function type */
    typedef Return_type(Object_type::*function_type)
            (Arg1_type, Arg2_type, Arg3_type,
             Arg4_type, Arg5_type, Arg6_type,
             Arg7_type) const;

    /**
     * @brief   Constructs a functor_to_member_const_7 from pointer to
     *          the given object and a member function pointer.
     */
    functor_to_member_const_7(Object_type* object,
                              function_type function);

    /**
     * @brief   Calls the encapsulated function on the object.
     * @return  The result of the function call.
     * @param   arg1 The first argument.
     * @param   arg2 The second argument.
     * @param   arg3 The third argument.
     * @param   arg4 The fourth argument.
     * @param   arg5 The fifth argument.
     * @param   arg6 The sixth argument.
     * @param   arg7 The seventh argument.
     */
    Return_type operator()(Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                           Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                           Arg7_type arg7);

    /**
     * @brief   Compares this functor with another for equality.
     * @details seven functors compare equal, if they refer to the
     *          same member function of the same object.
     * @param   other The other functor.
     * @return  True if the functors compare equal.
     */
    bool operator==(const functor_to_member_const_7 &other);

private:
    /**< Pointer to the target object */
    Object_type*  m_object;

    /**< Pointer to the encapsulated function */
    function_type m_function;

};

/**
 * @brief   This class encapsulates a volatile bound member function
 *          with seven arguments.
 */
HYDROSIG_TEMPLATE_OBJECT_7_ARG
class functor_to_member_volatile_7 : public functor_7_base<HYDROSIG_7_ARG>
{
public:
    /**< Typedef for the function type */
    typedef Return_type(Object_type::*function_type)
            (Arg1_type, Arg2_type, Arg3_type,
             Arg4_type, Arg5_type, Arg6_type,
             Arg7_type) volatile;

    /**
     * @brief   Constructs a functor_to_member_volatile_7 from pointer to
     *          the given object and a member function pointer.
     */
    functor_to_member_volatile_7(Object_type* object,
                                 function_type function);

    /**
     * @brief   Calls the encapsulated function on the object.
     * @return  The result of the function call.
     * @param   arg1 The first argument.
     * @param   arg2 The second argument.
     * @param   arg3 The third argument.
     * @param   arg4 The fourth argument.
     * @param   arg5 The fifth argument.
     * @param   arg6 The sixth argument.
     * @param   arg7 The seventh argument.
     */
    Return_type operator()(Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                           Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                           Arg7_type arg7);

    /**
     * @brief   Compares this functor with another for equality.
     * @details seven functors compare equal, if they refer to the
     *          same member function of the same object.
     * @param   other The other functor.
     * @return  True if the functors compare equal.
     */
    bool operator==(const functor_to_member_volatile_7 &other);

private:
    /**< Pointer to the target object */
    Object_type*  m_object;

    /**< Pointer to the encapsulated function */
    function_type m_function;

};

/**
 * @brief   This class encapsulates a const volatile bound member function
 *          with seven arguments.
 */
HYDROSIG_TEMPLATE_OBJECT_7_ARG
class functor_to_member_const_volatile_7 : public functor_7_base<HYDROSIG_7_ARG>
{
public:
    /**< Typedef for the function type */
    typedef Return_type(Object_type::*function_type)
            (Arg1_type, Arg2_type, Arg3_type,
             Arg4_type, Arg5_type, Arg6_type,
             Arg7_type) const volatile;

    /**
     * @brief   Constructs a functor_to_member_const_volatile_7 from pointer to
     *          the given object and a member function pointer.
     */
    functor_to_member_const_volatile_7(Object_type* object,
                                       function_type function);

    /**
     * @brief   Calls the encapsulated function on the object.
     * @return  The result of the function call.
     * @param   arg1 The first argument.
     * @param   arg2 The second argument.
     * @param   arg3 The third argument.
     * @param   arg4 The fourth argument.
     * @param   arg5 The fifth argument.
     * @param   arg6 The sixth argument.
     * @param   arg7 The seventh argument.
     */
    Return_type operator()(Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                           Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                           Arg7_type arg7);

    /**
     * @brief   Compares this functor with another for equality.
     * @details seven functors compare equal, if they refer to the
     *          same member function of the same object.
     * @param   other The other functor.
     * @return  True if the functors compare equal.
     */
    bool operator==(const functor_to_member_const_volatile_7 &other);

private:
    /**< Pointer to the target object */
    Object_type*  m_object;

    /**< Pointer to the encapsulated function */
    function_type m_function;

};




/**
 * Member definitions:
 * -------------------
 */

HYDROSIG_TEMPLATE_7_ARG
functor_to_free_7<HYDROSIG_7_ARG>::functor_to_free_7(
        function_type function)
        : m_function(function)
{
    ;
}

HYDROSIG_TEMPLATE_7_ARG
Return_type functor_to_free_7<HYDROSIG_7_ARG>::operator()
    (Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
     Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
     Arg7_type arg7)
{
    try {
        return m_function(arg1, arg2, arg3,
                          arg4, arg5, arg6,
                          arg7);
    }
    catch(...)
    {
        throw;
    }
}

HYDROSIG_TEMPLATE_7_ARG
bool functor_to_free_7<HYDROSIG_7_ARG>::operator==(
        const functor_to_free_7 &other)
{
    if(m_function == other.m_function)
        return true;

    return false;
}

HYDROSIG_TEMPLATE_CALLABLE_7_ARG
functor_to_callable_7<HYDROSIG_CALLABLE_7_ARG>::functor_to_callable_7(
        Callable_type callable)
    : m_callable(callable)
{
    ;
}

HYDROSIG_TEMPLATE_CALLABLE_7_ARG
Return_type functor_to_callable_7<HYDROSIG_CALLABLE_7_ARG>::operator()
    (Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
     Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
     Arg7_type arg7)
{
    try {
        return m_callable(arg1, arg2, arg3,
                          arg4, arg5, arg6,
                          arg7);
    }
    catch(...)
    {
        throw;
    }
}

HYDROSIG_TEMPLATE_OBJECT_7_ARG
functor_to_member_7<HYDROSIG_OBJECT_7_ARG>::functor_to_member_7(
        Object_type* object,
        function_type function)
    : m_object(object),
      m_function(function)
{
    ;
}

HYDROSIG_TEMPLATE_OBJECT_7_ARG
Return_type functor_to_member_7<HYDROSIG_OBJECT_7_ARG>::operator()
    (Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
     Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
     Arg7_type arg7)
{
    try {
        return (m_object->*m_function)(arg1, arg2, arg3,
                                       arg4, arg5, arg6,
                                       arg7);
    }
    catch(...)
    {
        throw;
    }
}

HYDROSIG_TEMPLATE_OBJECT_7_ARG
bool functor_to_member_7<HYDROSIG_OBJECT_7_ARG>::operator==(
        const functor_to_member_7 &other)
{
    if(m_object == other.m_object
            &&
       m_function == other.m_function)
        return true;

    return false;
}

HYDROSIG_TEMPLATE_OBJECT_7_ARG
functor_to_member_const_7<HYDROSIG_OBJECT_7_ARG>::functor_to_member_const_7(
        Object_type* object,
        function_type function)
    : m_object(object),
      m_function(function)
{
    ;
}

HYDROSIG_TEMPLATE_OBJECT_7_ARG
Return_type functor_to_member_const_7<HYDROSIG_OBJECT_7_ARG>::operator()
    (Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
     Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
     Arg7_type arg7)
{
    try {
        return (m_object->*m_function)(arg1, arg2, arg3,
                                       arg4, arg5, arg6,
                                       arg7);
    }
    catch(...)
    {
        throw;
    }
}

HYDROSIG_TEMPLATE_OBJECT_7_ARG
bool functor_to_member_const_7<HYDROSIG_OBJECT_7_ARG>::operator==(
        const functor_to_member_const_7 &other)
{
    if(m_object == other.m_object
            &&
       m_function == other.m_function)
        return true;

    return false;
}

HYDROSIG_TEMPLATE_OBJECT_7_ARG
functor_to_member_volatile_7<HYDROSIG_OBJECT_7_ARG>::functor_to_member_volatile_7(
        Object_type* object,
        function_type function)
    : m_object(object),
      m_function(function)
{
    ;
}

HYDROSIG_TEMPLATE_OBJECT_7_ARG
Return_type functor_to_member_volatile_7<HYDROSIG_OBJECT_7_ARG>::operator()
    (Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
     Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
     Arg7_type arg7)
{
    try {
        return (m_object->*m_function)(arg1, arg2, arg3,
                                       arg4, arg5, arg6,
                                       arg7);
    }
    catch(...)
    {
        throw;
    }
}

HYDROSIG_TEMPLATE_OBJECT_7_ARG
bool functor_to_member_volatile_7<HYDROSIG_OBJECT_7_ARG>::operator==(
        const functor_to_member_volatile_7 &other)
{
    if(m_object == other.m_object
            &&
       m_function == other.m_function)
        return true;

    return false;
}


HYDROSIG_TEMPLATE_OBJECT_7_ARG
functor_to_member_const_volatile_7<HYDROSIG_OBJECT_7_ARG>::
functor_to_member_const_volatile_7(
        Object_type* object,
        function_type function)
    : m_object(object),
      m_function(function)
{
    ;
}

HYDROSIG_TEMPLATE_OBJECT_7_ARG
Return_type functor_to_member_const_volatile_7<HYDROSIG_OBJECT_7_ARG>
::operator()(Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
             Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
             Arg7_type arg7)
{
    try {
        return (m_object->*m_function)(arg1, arg2, arg3,
                                       arg4, arg5, arg6,
                                       arg7);
    }
    catch(...)
    {
        throw;
    }
}

HYDROSIG_TEMPLATE_OBJECT_7_ARG
bool functor_to_member_const_volatile_7<HYDROSIG_OBJECT_7_ARG>
::operator==(
        const functor_to_member_const_volatile_7 &other)
{
    if(m_object == other.m_object
            &&
       m_function == other.m_function)
        return true;

    return false;
}


HYDROSIG_NAMESPACE_END


#endif // HYDROSIG_FUNCTOR_7_HPP_INCLUDED
