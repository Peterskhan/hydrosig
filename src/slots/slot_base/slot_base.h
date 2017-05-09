#pragma once
#ifndef HYDROSIG_SLOT_BASE_H_INCLUDED
#define HYDROSIG_SLOT_BASE_H_INCLUDED

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
#include "src/trackable/trackable.h"


HYDROSIG_NAMESPACE_BEGIN


/**
 * @brief   This abstract base class defines the common,
 *          type-independent interface of all slot classes.
 * @details Slot classes operate as a logical layer over the
 *          functor object they encapsulate. This base class
 *          implements the blocking mechanism for individual
 *          slots, informing the holding signal if it should
 *          skip the activation of the slot upon being emitted.
 */
class slot_base
{
public:
    /**
     * @brief   Constructs a slot_base object.
     * @details The state of blocking will be
     *          initialized to false.
     */
    slot_base(HYDROSIG_SHARED_PTR_TYPE<connection_validator> validator);

    /**
     * @brief   Destroys the slot_base.
     */
    virtual ~slot_base();

    /**
     * @brief   Returns whether the slot is valid.
     * @return  True if the slot is valid, false otherwise.
     */
    bool isValid() const;

    /**
     * @brief   Returns a shared pointer to the validator
     *          of the slot.
     * @return  Pointer to the slot's validator.
     */
    HYDROSIG_SHARED_PTR_TYPE<connection_validator> getValidator() const;

    /**
     * @brief   Sets the blocking state of the slot.
     * @details If the connection is blocked by the slot,
     *          no callbacks will be executed when the holding
     *          signal is emitted.
     * @param   shouldBlock The state of blocking to set.
     */
    void block(bool shouldBlock = true);

    /**
     * @brief   Unblocks the slot.
     */
    void unblock();

    /**
     * @brief   Returns whether the slot is blocked.
     * @return  True if the slot is blocked.
     */
    bool isBlocked() const;

protected:
    /**< The state of blocking */
    bool m_blocked;

    /**< The connection validator for the slot */
    HYDROSIG_SHARED_PTR_TYPE<connection_validator> m_validator;

    /**< The mutex used for synchronisation */
    HYDROSIG_MUTEX_TYPE m_mutex;

};


HYDROSIG_NAMESPACE_END


#endif // HYDROSIG_SLOT_BASE_H_INCLUDED
