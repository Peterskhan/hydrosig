#pragma once
#ifndef HYDROSIG_SLOT_7_HPP_INCLUDED
#define HYDROSIG_SLOT_7_HPP_INCLUDED

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
#include "src/slots/slot_base/slot_base.h"
#include "src/functors/functor_7.hpp"


HYDROSIG_NAMESPACE_BEGIN


/**
 * Class declarations:
 * -------------------
 */

/**
 * @brief   This class represents a slot holding a
 *          functor which accept seven arguments.
 */
HYDROSIG_TEMPLATE_7_ARG
class slot_7 : public slot_base
{
public:
    /**< Typedef for the functor type */
    typedef functor_7_base<HYDROSIG_7_ARG>
    functor_type;

    /**
     * @brief   Constructs a slot_7 from a pointer to
     *          a functor.
     * @param   functor_ptr Pointer to the functor object.
     */
    slot_7(functor_type* functor_ptr,
           HYDROSIG_SHARED_PTR_TYPE<connection_validator> validator);

    /**
     * @brief   Copy constructing a slot is disallowed.
     */
    slot_7(const slot_7& /*src*/) = delete;

    /**
     * @brief   Move constructing a slot is disallowed.
     */
    slot_7(slot_7&& /*src*/) = delete;

    /**
     * @brief   Assignment of a slot is disallowed.
     */
    slot_7& operator=(const slot_7& /*src*/) = delete;

    /**
     * @brief   Move assignment of a slot is disallowed.
     */
    slot_7& operator=(slot_7&& /*src*/) = delete;

    /**
     * @brief   Destroys the slot_7 object.
     */
    virtual ~slot_7();

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
     * @param   arg4 The fourth argument.
     * @param   arg5 The fifth argument.
     * @param   arg6 The sixth argument.
     * @param   arg7 The seventh argument.
     */
    Return_type activate(Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                         Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                         Arg7_type arg7);

private:
    /**< The functor to the encapsulated function */
    HYDROSIG_UNIQUE_PTR_TYPE<functor_type> m_functor;

};

/**
 * Member definitions:
 * -------------------
 */

HYDROSIG_TEMPLATE_7_ARG
slot_7<HYDROSIG_7_ARG>::slot_7(
        functor_type* functor_ptr,
        HYDROSIG_SHARED_PTR_TYPE<connection_validator> validator)
    : slot_base(validator),
      m_functor(functor_ptr)
{
    ;
}

HYDROSIG_TEMPLATE_7_ARG
slot_7<HYDROSIG_7_ARG>::~slot_7()
{
    ;
}

HYDROSIG_TEMPLATE_7_ARG
typename slot_7<HYDROSIG_7_ARG>::functor_type*
slot_7<HYDROSIG_7_ARG>::get_functor() const
{
    return m_functor.get();
}

HYDROSIG_TEMPLATE_7_ARG
Return_type slot_7<HYDROSIG_7_ARG>::activate(
        Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
        Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
        Arg7_type arg7)
{
    HYDROSIG_PROTECTED_BLOCK_BEGIN

            try {
        return (*m_functor)(arg1, arg2, arg3,
                            arg4, arg5, arg6,
                            arg7);
    }
    catch(...)
    {
        throw;
    }

    // HYDROSIG_PROTECTED_BLOCK_END
}


HYDROSIG_NAMESPACE_END


#endif // HYDROSIG_SLOT_7_HPP_INCLUDED
