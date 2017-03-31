#pragma once
#ifndef HYDROSIG_FUNCTOR_0_HPP_INCLUDED
#define HYDROSIG_FUNCTOR_0_HPP_INCLUDED

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

#include "functor_base/functor_base.hpp"
#include "macros.h"


HYDROSIG_NAMESPACE_BEGIN


/**
 * @brief   This class encapsulates a free function, such
 *          as a global or static member method with zero
 *          arguments.
 */
template<class Return_type>
class functor_to_free_0
        : public functor_0_base<Return_type>
{
private:
    /**< Typedef for the function type */
    typedef Return_type(*function_type)();

private:
    function_type m_function;   /**< Pointer to the encapsulated function */

public:
    /**
     * @brief   Constructs a functor_to_free_0 from the
     *          given function pointer.
     */
    functor_to_free_0(function_type function)
        : m_function(function)
    {}

    /**
     * @brief   Calls the encapsulated function.
     * @return  The result of the function call.
     */
    Return_type operator()()
    {
        if(m_function == nullptr)
            throw bad_function_call();

        try {
            return m_function();
        }
        catch(...)
        {
            throw;
        }
    }

    /**
     * @brief   Compares this functor with another for equality.
     * @details Two functors compare equal, if they refer to the
     *          same free function.
     * @param   other The other functor.
     * @return  True if the functors compare equal.
     */
    bool operator==(const functor_to_free_0 &other)
    {
        if(m_function == other.m_function)
            return true;
        return false;
    }

};


/**
 * @brief   This class encapsulates a callable object, such
 *          as a lambda-expression, expecting zero arguments.
 */
template<class Callable_type,
         class Return_type>
class functor_to_callable_0
        : public functor_0_base<Return_type>
{
private:
    Callable_type m_callable;   /**< The callable object */

public:
    /**
     * @brief   Constructs a functor_to_callable_0 from the
     *          copy of the given callable object.
     */
    functor_to_callable_0(Callable_type callable)
        : m_callable(callable)
    {}

    /**
     * @brief   Calls the encapsulated function.
     * @return  The result of the function call.
     */
    Return_type operator()()
    {
        try {
            return m_callable();
        }
        catch(...)
        {
            throw;
        }
    }

};


/**
 * @brief   This class encapsulates a bound member function
 *          with zero arguments.
 */
template<class Object_type,
         class Return_type>
class functor_to_member_0
        : public functor_0_base<Return_type>
{
private:
    /**< Typedef for the function type */
    typedef Return_type(Object_type::*function_type)();

private:
    Object_type*  m_object;     /**< Pointer to the target object */
    function_type m_function;   /**< Pointer to the encapsulated function */

public:
    /**
     * @brief   Constructs a functor_to_member_0 from pointer to
     *          the given object and a member function pointer.
     */
    functor_to_member_0(Object_type* object, function_type function)
        : m_object(object),
          m_function(function)
    {}

    /**
     * @brief   Calls the encapsulated function on the object.
     * @return  The result of the function call.
     */
    Return_type operator()()
    {
        if(m_object == nullptr)
            throw bad_function_call();

        if(m_function == nullptr)
            throw bad_function_call();

        try {
            return (m_object->*m_function)();
        }
        catch(...)
        {
            throw;
        }
    }

    /**
     * @brief   Compares this functor with another for equality.
     * @details Two functors compare equal, if they refer to the
     *          same member function of the same object.
     * @param   other The other functor.
     * @return  True if the functors compare equal.
     */
    bool operator==(const functor_to_member_0 &other)
    {
        if(m_object == other.m_object
                &&
           m_function == other.m_function)
        return true;

        return false;
    }

};


/**
 * @brief   This class encapsulates a const bound member function
 *          with no arguments.
 */
template<class Object_type,
         class Return_type>
class functor_to_member_const_0
        : public functor_0_base<Return_type>
{
private:
    /**< Typedef for the function type */
    typedef Return_type(Object_type::*function_type)() const;

private:
    Object_type*  m_object;     /**< Pointer to the target object */
    function_type m_function;   /**< Pointer to the encapsulated function */

public:
    /**
     * @brief   Constructs a functor_to_member_const_0 from pointer to
     *          the given object and a member function pointer.
     */
    functor_to_member_const_0(Object_type* object, function_type function)
        : m_object(object),
          m_function(function)
    {}

    /**
     * @brief   Calls the encapsulated function on the object.
     * @return  The result of the function call.
     */
    Return_type operator()()
    {
        if(m_object == nullptr)
            throw bad_function_call();

        if(m_function == nullptr)
            throw bad_function_call();

        try {
            return (m_object->*m_function)();
        }
        catch(...)
        {
            throw;
        }
    }

    /**
     * @brief   Compares this functor with another for equality.
     * @details Two functors compare equal, if they refer to the
     *          same member function of the same object.
     * @param   other The other functor.
     * @return  True if the functors compare equal.
     */
    bool operator==(const functor_to_member_const_0 &other)
    {
        if(m_object == other.m_object
                &&
           m_function == other.m_function)
        return true;

        return false;
    }

};

/**
 * @brief   This class encapsulates a volatile bound member function
 *          with no arguments.
 */
template<class Object_type,
         class Return_type>
class functor_to_member_volatile_0
        : public functor_0_base<Return_type>
{
private:
    /**< Typedef for the function type */
    typedef Return_type(Object_type::*function_type)() volatile;

private:
    Object_type*  m_object;     /**< Pointer to the target object */
    function_type m_function;   /**< Pointer to the encapsulated function */

public:
    /**
     * @brief   Constructs a functor_to_member_volatile_0 from pointer to
     *          the given object and a member function pointer.
     */
    functor_to_member_volatile_0(Object_type* object, function_type function)
        : m_object(object),
          m_function(function)
    {}

    /**
     * @brief   Calls the encapsulated function on the object.
     * @return  The result of the function call.
     */
    Return_type operator()()
    {
        if(m_object == nullptr)
            throw bad_function_call();

        if(m_function == nullptr)
            throw bad_function_call();

        try {
            return (m_object->*m_function)();
        }
        catch(...)
        {
            throw;
        }
    }

    /**
     * @brief   Compares this functor with another for equality.
     * @details Two functors compare equal, if they refer to the
     *          same member function of the same object.
     * @param   other The other functor.
     * @return  True if the functors compare equal.
     */
    bool operator==(const functor_to_member_volatile_0 &other)
    {
        if(m_object == other.m_object
                &&
           m_function == other.m_function)
        return true;

        return false;
    }

};

/**
 * @brief   This class encapsulates a const volatile bound member function
 *          with no arguments.
 */
template<class Object_type,
         class Return_type>
class functor_to_member_const_volatile_0
        : public functor_0_base<Return_type>
{
private:
    /**< Typedef for the function type */
    typedef Return_type(Object_type::*function_type)() const volatile;

private:
    Object_type*  m_object;     /**< Pointer to the target object */
    function_type m_function;   /**< Pointer to the encapsulated function */

public:
    /**
     * @brief   Constructs a functor_to_member_const_volatile_0 from pointer to
     *          the given object and a member function pointer.
     */
    functor_to_member_const_volatile_0(Object_type* object, function_type function)
        : m_object(object),
          m_function(function)
    {}

    /**
     * @brief   Calls the encapsulated function on the object.
     * @return  The result of the function call.
     */
    Return_type operator()()
    {
        if(m_object == nullptr)
            throw bad_function_call();

        if(m_function == nullptr)
            throw bad_function_call();

        try {
            return (m_object->*m_function)();
        }
        catch(...)
        {
            throw;
        }
    }

    /**
     * @brief   Compares this functor with another for equality.
     * @details Two functors compare equal, if they refer to the
     *          same member function of the same object.
     * @param   other The other functor.
     * @return  True if the functors compare equal.
     */
    bool operator==(const functor_to_member_const_volatile_0 &other)
    {
        if(m_object == other.m_object
                &&
           m_function == other.m_function)
        return true;

        return false;
    }

};


HYDROSIG_NAMESPACE_END


#endif // HYDROSIG_FUNCTOR_0_HPP_INCLUDED
