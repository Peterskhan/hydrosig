#pragma once
#ifndef HYDROSIG_COMP_FUN_1_H_INCLUDED
#define HYDROSIG_COMP_FUN_1_H_INCLUDED

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
#include "src/functors/functor_1.hpp"


HYDROSIG_NAMESPACE_BEGIN


/**
 * Function declarations:
 * ----------------------
 */

/**
 * @brief   Compares a functor_to_free_1 with
 *          another functor_1.
 * @return  True if the functors are equal.
 */
HYDROSIG_TEMPLATE_1_ARG
bool comp_fun(functor_to_free_1<HYDROSIG_1_ARG> *rhs,
              functor_1_base<HYDROSIG_1_ARG> *lhs);

/**
 * @brief   Compares a functor_to_member_1 with
 *          another functor_1.
 * @return  True if the functors are equal.
 */
HYDROSIG_TEMPLATE_OBJECT_1_ARG
bool comp_fun(functor_to_member_1<HYDROSIG_OBJECT_1_ARG> *rhs,
              functor_1_base<HYDROSIG_1_ARG> *lhs);

/**
 * @brief   Compares a functor_to_member_const_1 with
 *          another functor_1.
 * @return  True if the functors are equal.
 */
HYDROSIG_TEMPLATE_OBJECT_1_ARG
bool comp_fun(functor_to_member_const_1<HYDROSIG_OBJECT_1_ARG> *rhs,
              functor_1_base<HYDROSIG_1_ARG> *lhs);

/**
 * @brief   Compares a functor_to_member_volatile_1 with
 *          another functor_1.
 * @return  True if the functors are equal.
 */
HYDROSIG_TEMPLATE_OBJECT_1_ARG
bool comp_fun(functor_to_member_volatile_1<HYDROSIG_OBJECT_1_ARG> *rhs,
              functor_1_base<HYDROSIG_1_ARG> *lhs);

/**
 * @brief   Compares a functor_to_member_const_volatile_1 with
 *          another functor_1.
 * @return  True if the functors are equal.
 */
HYDROSIG_TEMPLATE_OBJECT_1_ARG
bool comp_fun(functor_to_member_const_volatile_1<HYDROSIG_OBJECT_1_ARG> *rhs,
              functor_1_base<HYDROSIG_1_ARG> *lhs);




/**
 * Function definitions:
 * --------------------
 */

HYDROSIG_TEMPLATE_1_ARG
bool comp_fun(functor_to_free_1<HYDROSIG_1_ARG> *rhs,
              functor_1_base<HYDROSIG_1_ARG> *lhs)
{
    // Attempting to downcast
    functor_to_free_1<HYDROSIG_1_ARG> *downCasted =
            dynamic_cast<functor_to_free_1<HYDROSIG_1_ARG>*>(lhs);

    if(downCasted != nullptr)
    {
        return (*downCasted == *rhs);
    }

    return false;
}

HYDROSIG_TEMPLATE_OBJECT_1_ARG
bool comp_fun(functor_to_member_1<HYDROSIG_OBJECT_1_ARG> *rhs,
              functor_1_base<HYDROSIG_1_ARG> *lhs)
{
    // Attempting to downcast
    functor_to_member_1<HYDROSIG_OBJECT_1_ARG> *downCasted =
            dynamic_cast<functor_to_member_1<HYDROSIG_OBJECT_1_ARG>*>(lhs);

    if(downCasted != nullptr)
    {
        return (*downCasted == *rhs);
    }

    return false;
}

HYDROSIG_TEMPLATE_OBJECT_1_ARG
bool comp_fun(functor_to_member_const_1<HYDROSIG_OBJECT_1_ARG> *rhs,
              functor_1_base<HYDROSIG_1_ARG> *lhs)
{
    // Attempting to downcast
    functor_to_member_const_1<HYDROSIG_OBJECT_1_ARG> *downCasted =
            dynamic_cast<functor_to_member_const_1<HYDROSIG_OBJECT_1_ARG>*>(lhs);

    if(downCasted != nullptr)
    {
        return (*downCasted == *rhs);
    }

    return false;
}

HYDROSIG_TEMPLATE_OBJECT_1_ARG
bool comp_fun(functor_to_member_volatile_1<HYDROSIG_OBJECT_1_ARG> *rhs,
              functor_1_base<HYDROSIG_1_ARG> *lhs)
{
    // Attempting to downcast
    functor_to_member_volatile_1<HYDROSIG_OBJECT_1_ARG> *downCasted =
            dynamic_cast<functor_to_member_volatile_1<HYDROSIG_OBJECT_1_ARG>*>(lhs);

    if(downCasted != nullptr)
    {
        return (*downCasted == *rhs);
    }

    return false;
}

HYDROSIG_TEMPLATE_OBJECT_1_ARG
bool comp_fun(functor_to_member_const_volatile_1<HYDROSIG_OBJECT_1_ARG> *rhs,
              functor_1_base<HYDROSIG_1_ARG> *lhs)
{
    // Attempting to downcast
    functor_to_member_const_volatile_1<HYDROSIG_OBJECT_1_ARG> *downCasted =
            dynamic_cast<functor_to_member_const_volatile_1<HYDROSIG_OBJECT_1_ARG>*>(lhs);

    if(downCasted != nullptr)
    {
        return (*downCasted == *rhs);
    }

    return false;
}


HYDROSIG_NAMESPACE_END


#endif // HYDROSIG_COMP_FUN_1_H_INCLUDED
