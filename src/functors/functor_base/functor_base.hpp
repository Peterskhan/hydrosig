#pragma once
#ifndef HYDROSIG_FUNCTOR_BASE_HPP_INCLUDED
#define HYDROSIG_FUNCTOR_BASE_HPP_INCLUDED

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

#include <exception>
#include "macros.h"


HYDROSIG_NAMESPACE_BEGIN


/**
 * Abstract functor base classes
 * -----------------------------
 */

/**
 * @brief   This class template forms the base of functors,
 *          holding callable objects or functions with zero
 *          arguments. Note that this class is abstract.
 */
template<class Return_type>
class functor_0_base
{
public:
    /**
     * @brief   Pure virtual function call operator.
     * @details Override this operator, according to the
     *          structure of your functor to support the
     *          convenient functor interface.
     * @return  The result of the function call.
     */
    virtual Return_type operator()() = 0;

    /**
     * @brief   Virtual destructor for derived functors.
     */
    virtual ~functor_0_base()
    {
        ;
    }

};

/**
 * @brief   This class template forms the base of functors,
 *          holding callable objects or functions with one
 *          arguments. Note that this class is abstract.
 */
template<class Return_type,
         class Arg1_type>
class functor_1_base
{
public:
    /**
     * @brief   Pure virtual function call operator.
     * @details Override this operator, according to the
     *          structure of your functor to support the
     *          convenient functor interface.
     * @param   The type of the first argument.
     * @return  The result of the function call.
     */
    virtual Return_type operator()(Arg1_type) = 0;

    /**
     * @brief   Virtual destructor for derived functors.
     */
    virtual ~functor_1_base()
    {
        ;
    }

};

/**
 * @brief   This class template forms the base of functors,
 *          holding callable objects or functions with two
 *          arguments. Note that this class is abstract.
 */
template<class Return_type,
         class Arg1_type, class Arg2_type>
class functor_2_base
{
public:
    /**
     * @brief   Pure virtual function call operator.
     * @details Override this operator, according to the
     *          structure of your functor to support the
     *          convenient functor interface.
     * @param   The type of the first argument.
     * @param   The type of the second argument.
     * @return  The result of the function call.
     */
    virtual Return_type operator()(Arg1_type, Arg2_type) = 0;

    /**
     * @brief   Virtual destructor for derived functors.
     */
    virtual ~functor_2_base()
    {
        ;
    }

};

/**
 * @brief   This class template forms the base of functors,
 *          holding callable objects or functions with three
 *          arguments. Note that this class is abstract.
 */
template<class Return_type,
         class Arg1_type, class Arg2_type, class Arg3_type>
class functor_3_base
{
public:
    /**
     * @brief   Pure virtual function call operator.
     * @details Override this operator, according to the
     *          structure of your functor to support the
     *          convenient functor interface.
     * @param   The type of the first argument.
     * @param   The type of the second argument.
     * @param   The type of the third argument.
     * @return  The result of the function call.
     */
    virtual Return_type operator()(Arg1_type, Arg2_type, Arg3_type) = 0;

    /**
     * @brief   Virtual destructor for derived functors.
     */
    virtual ~functor_3_base()
    {
        ;
    }

};

/**
 * @brief   This class template forms the base of functors,
 *          holding callable objects or functions with four
 *          arguments. Note that this class is abstract.
 */
template<class Return_type,
         class Arg1_type, class Arg2_type, class Arg3_type,
         class Arg4_type>
class functor_4_base
{
public:
    /**
     * @brief   Pure virtual function call operator.
     * @details Override this operator, according to the
     *          structure of your functor to support the
     *          convenient functor interface.
     * @param   The type of the first argument.
     * @param   The type of the second argument.
     * @param   The type of the third argument.
     * @param   The type of the fourth argument.
     * @return  The result of the function call.
     */
    virtual Return_type operator()(Arg1_type, Arg2_type, Arg3_type,
                                   Arg4_type) = 0;

    /**
     * @brief   Virtual destructor for derived functors.
     */
    virtual ~functor_4_base()
    {
        ;
    }

};

/**
 * @brief   This class template forms the base of functors,
 *          holding callable objects or functions with five
 *          arguments. Note that this class is abstract.
 */
template<class Return_type,
         class Arg1_type, class Arg2_type, class Arg3_type,
         class Arg4_type, class Arg5_type>
class functor_5_base
{
public:
    /**
     * @brief   Pure virtual function call operator.
     * @details Override this operator, according to the
     *          structure of your functor to support the
     *          convenient functor interface.
     * @param   The type of the first argument.
     * @param   The type of the second argument.
     * @param   The type of the third argument.
     * @param   The type of the fourth argument.
     * @param   The type of the fifth argument.
     * @return  The result of the function call.
     */
    virtual Return_type operator()(Arg1_type, Arg2_type, Arg3_type,
                                   Arg4_type, Arg5_type) = 0;

    /**
     * @brief   Virtual destructor for derived functors.
     */
    virtual ~functor_5_base()
    {
        ;
    }

};

/**
 * @brief   This class template forms the base of functors,
 *          holding callable objects or functions with six
 *          arguments. Note that this class is abstract.
 */
template<class Return_type,
         class Arg1_type, class Arg2_type, class Arg3_type,
         class Arg4_type, class Arg5_type, class Arg6_type>
class functor_6_base
{
public:
    /**
     * @brief   Pure virtual function call operator.
     * @details Override this operator, according to the
     *          structure of your functor to support the
     *          convenient functor interface.
     * @param   The type of the first argument.
     * @param   The type of the second argument.
     * @param   The type of the third argument.
     * @param   The type of the fourth argument.
     * @param   The type of the fifth argument.
     * @param   The type of the sixth argument.
     * @return  The result of the function call.
     */
    virtual Return_type operator()(Arg1_type, Arg2_type, Arg3_type,
                                   Arg4_type, Arg5_type, Arg6_type) = 0;

    /**
     * @brief   Virtual destructor for derived functors.
     */
    virtual ~functor_6_base()
    {
        ;
    }

};

/**
 * @brief   This class template forms the base of functors,
 *          holding callable objects or functions with sever
 *          arguments. Note that this class is abstract.
 */
template<class Return_type,
         class Arg1_type, class Arg2_type, class Arg3_type,
         class Arg4_type, class Arg5_type, class Arg6_type,
         class Arg7_type>
class functor_7_base
{
public:
    /**
     * @brief   Pure virtual function call operator.
     * @details Override this operator, according to the
     *          structure of your functor to support the
     *          convenient functor interface.
     * @param   The type of the first argument.
     * @param   The type of the second argument.
     * @param   The type of the third argument.
     * @param   The type of the fourth argument.
     * @param   The type of the fifth argument.
     * @param   The type of the sixth argument.
     * @param   The type of the seventh argument.
     * @return  The result of the function call.
     */
    virtual Return_type operator()(Arg1_type, Arg2_type, Arg3_type,
                                   Arg4_type, Arg5_type, Arg6_type,
                                   Arg7_type) = 0;

    /**
     * @brief   Virtual destructor for derived functors.
     */
    virtual ~functor_7_base()
    {
        ;
    }

};

/**
 * @brief   This class template forms the base of functors,
 *          holding callable objects or functions with eight
 *          arguments. Note that this class is abstract.
 */
template<class Return_type,
         class Arg1_type, class Arg2_type, class Arg3_type,
         class Arg4_type, class Arg5_type, class Arg6_type,
         class Arg7_type, class Arg8_type>
class functor_8_base
{
public:
    /**
     * @brief   Pure virtual function call operator.
     * @details Override this operator, according to the
     *          structure of your functor to support the
     *          convenient functor interface.
     * @param   The type of the first argument.
     * @param   The type of the second argument.
     * @param   The type of the third argument.
     * @param   The type of the fourth argument.
     * @param   The type of the fifth argument.
     * @param   The type of the sixth argument.
     * @param   The type of the seventh argument.
     * @param   The type of the eight argument.
     * @return  The result of the function call.
     */
    virtual Return_type operator()(Arg1_type, Arg2_type, Arg3_type,
                                   Arg4_type, Arg5_type, Arg6_type,
                                   Arg7_type, Arg8_type) = 0;

    /**
     * @brief   Virtual destructor for derived functors.
     */
    virtual ~functor_8_base()
    {
        ;
    }

};


/**
 * Bad function call exception
 * ---------------------------
 */

/**
 * @brief   This class represents a bad function call exception
 *          which is thrown if an invalid functor is activated.
 */
class bad_function_call : public std::exception
{
public:
    /**
     * @brief   Returns an explanatory string about the exception.
     * @return  The explanatory string.
     */
    virtual const char* what() const noexcept
    {
        return "Hydrosig++: Bad call to invalid functor.";
    }
};


HYDROSIG_NAMESPACE_END


#endif // HYDROSIG_FUNCTOR_BASE_HPP_INCLUDED
