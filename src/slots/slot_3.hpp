#pragma once
#ifndef HYDROSIG_SLOT_3_HPP_INCLUDED
#define HYDROSIG_SLOT_3_HPP_INCLUDED

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

#include "macros.h"
#include "slot_base/slot_base.h"
#include "functors/functor_3.hpp"


HYDROSIG_NAMESPACE_BEGIN


/**
 * Class declarations:
 * -------------------
 */

/**
 * @brief   This class represents a slot holding a
 *          functor which accept three arguments.
 */
HYDROSIG_TEMPLATE_3_ARG
class slot_3 : public slot_base
{
public:
    /**< Typedef for the functor type */
    typedef functor_3_base<HYDROSIG_3_ARG>
    functor_type;

    /**
     * @brief   Constructs a slot_3 from a pointer to
     *          a functor.
     * @param   functor_ptr Pointer to the functor object.
     */
    slot_3(functor_type* functor_ptr,
           HYDROSIG_SHARED_PTR_TYPE<connection_validator> validator);

    /**
     * @brief   Copy constructing a slot is disallowed.
     */
    slot_3(const slot_3& /*src*/) = delete;

    /**
     * @brief   Move constructing a slot is disallowed.
     */
    slot_3(slot_3&& /*src*/) = delete;

    /**
     * @brief   Assignment of a slot is disallowed.
     */
    slot_3& operator=(const slot_3& /*src*/) = delete;

    /**
     * @brief   Move assignment of a slot is disallowed.
     */
    slot_3& operator=(slot_3&& /*src*/) = delete;

    /**
     * @brief   Destroys the slot_3 object.
     */
    virtual ~slot_3();

    /**
     * @brief   Returns the internally stored functor object.
     * @return  Pointer to the functor object.
     */
    functor_type* get_functor() const;

    /**
     * @brief   Activates the internally stored functor object.
     * @return  The result of calling the functor.
     * @param   arg1 The first argument.
     * @param   arg2 The second argument.
     * @param   arg3 The third argument.
     */
    Return_type activate(Arg1_type arg1, Arg2_type arg2, Arg3_type arg3);

private:
    /**< The functor to the encapsulated function */
    HYDROSIG_UNIQUE_PTR_TYPE<functor_type> m_functor;

};

/**
 * Member definitions:
 * -------------------
 */

HYDROSIG_TEMPLATE_3_ARG
slot_3<HYDROSIG_3_ARG>::slot_3(
        functor_type* functor_ptr,
        HYDROSIG_SHARED_PTR_TYPE<connection_validator> validator)
    : slot_base(validator),
      m_functor(functor_ptr)
{
    ;
}

HYDROSIG_TEMPLATE_3_ARG
slot_3<HYDROSIG_3_ARG>::~slot_3()
{
    ;
}

HYDROSIG_TEMPLATE_3_ARG
typename slot_3<HYDROSIG_3_ARG>::functor_type*
slot_3<HYDROSIG_3_ARG>::get_functor() const
{
    return m_functor.get();
}

HYDROSIG_TEMPLATE_3_ARG
Return_type slot_3<HYDROSIG_3_ARG>::activate(
        Arg1_type arg1, Arg2_type arg2, Arg3_type arg3)
{
    HYDROSIG_PROTECTED_BLOCK_BEGIN

    try {
        return (*m_functor)(arg1, arg2, arg3);
    }
    catch(...)
    {
        throw;
    }

    // HYDROSIG_PROTECTED_BLOCK_END
}


HYDROSIG_NAMESPACE_END


#endif // HYDROSIG_SLOT_3_HPP_INCLUDED
