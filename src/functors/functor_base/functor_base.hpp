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

#include "src/macros.h"


HYDROSIG_NAMESPACE_BEGIN


/**
 * Class declarations:
 * -------------------
 */

/**
 * @brief   This class template forms the base of functors,
 *          holding callable objects or functions with zero
 *          arguments. Note that this class is abstract.
 */
HYDROSIG_TEMPLATE_0_ARG
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
     * @brief   Destroys a functor_0_base object.
     */
    virtual ~functor_0_base();

};

/**
 * @brief   This class template forms the base of functors,
 *          holding callable objects or functions with one
 *          arguments. Note that this class is abstract.
 */
HYDROSIG_TEMPLATE_1_ARG
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
     * @brief   Destroys a functor_1_base object.
     */
    virtual ~functor_1_base();

};

/**
 * @brief   This class template forms the base of functors,
 *          holding callable objects or functions with two
 *          arguments. Note that this class is abstract.
 */
HYDROSIG_TEMPLATE_2_ARG
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
     * @brief   Destroys a functor_2_base object.
     */
    virtual ~functor_2_base();

};

/**
 * @brief   This class template forms the base of functors,
 *          holding callable objects or functions with three
 *          arguments. Note that this class is abstract.
 */
HYDROSIG_TEMPLATE_3_ARG
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
     * @brief   Destroys a functor_3_base object.
     */
    virtual ~functor_3_base();

};

/**
 * @brief   This class template forms the base of functors,
 *          holding callable objects or functions with four
 *          arguments. Note that this class is abstract.
 */
HYDROSIG_TEMPLATE_4_ARG
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
     * @brief   Destroys a functor_4_base object.
     */
    virtual ~functor_4_base();

};

/**
 * @brief   This class template forms the base of functors,
 *          holding callable objects or functions with five
 *          arguments. Note that this class is abstract.
 */
HYDROSIG_TEMPLATE_5_ARG
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
     * @brief   Destroys a functor_5_base object.
     */
    virtual ~functor_5_base();

};

/**
 * @brief   This class template forms the base of functors,
 *          holding callable objects or functions with six
 *          arguments. Note that this class is abstract.
 */
HYDROSIG_TEMPLATE_6_ARG
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
     * @brief   Destroys a functor_6_base object.
     */
    virtual ~functor_6_base();

};

/**
 * @brief   This class template forms the base of functors,
 *          holding callable objects or functions with sever
 *          arguments. Note that this class is abstract.
 */
HYDROSIG_TEMPLATE_7_ARG
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
     * @brief   Destroys a functor_7_base object.
     */
    virtual ~functor_7_base();

};

/**
 * @brief   This class template forms the base of functors,
 *          holding callable objects or functions with eight
 *          arguments. Note that this class is abstract.
 */
HYDROSIG_TEMPLATE_8_ARG
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
     * @brief   Destroys a functor_8_base object.
     */
    virtual ~functor_8_base();

};




/**
 * Member definitions:
 * -------------------
 */

HYDROSIG_TEMPLATE_0_ARG
functor_0_base<HYDROSIG_0_ARG>::~functor_0_base()
{
    ;
}

HYDROSIG_TEMPLATE_1_ARG
functor_1_base<HYDROSIG_1_ARG>::~functor_1_base()
{
    ;
}

HYDROSIG_TEMPLATE_2_ARG
functor_2_base<HYDROSIG_2_ARG>::~functor_2_base()
{
    ;
}

HYDROSIG_TEMPLATE_3_ARG
functor_3_base<HYDROSIG_3_ARG>::~functor_3_base()
{
    ;
}

HYDROSIG_TEMPLATE_4_ARG
functor_4_base<HYDROSIG_4_ARG>::~functor_4_base()
{
    ;
}

HYDROSIG_TEMPLATE_5_ARG
functor_5_base<HYDROSIG_5_ARG>::~functor_5_base()
{
    ;
}

HYDROSIG_TEMPLATE_6_ARG
functor_6_base<HYDROSIG_6_ARG>::~functor_6_base()
{
    ;
}

HYDROSIG_TEMPLATE_7_ARG
functor_7_base<HYDROSIG_7_ARG>::~functor_7_base()
{
    ;
}

HYDROSIG_TEMPLATE_8_ARG
functor_8_base<HYDROSIG_8_ARG>::~functor_8_base()
{
    ;
}


HYDROSIG_NAMESPACE_END


#endif // HYDROSIG_FUNCTOR_BASE_HPP_INCLUDED
