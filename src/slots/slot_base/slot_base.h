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

#include "trackable/trackable.h"
#include "macros.h"


HYDROSIG_NAMESPACE_BEGIN


/**
 * @brief   This abstract base class defines the common,
 *          type-independent interface of all slot classes.
 * @details Slot classes operate as a logical layer over the
 *          functor object they encapsulate. This base class
 *          implements the blocking mechanism for individual
 *          slots, informing the holding signal if it should
 *          skip the activation of the slot upon being emitted.
 *          Checking for functor validity, destruction notification
 *          handling and cleanup functionality are implemented
 *          in the derived slot classes.
 */
class slot_base : public trackable
{
private:
    bool m_blocked;                 /**< The state of blocking */

public:
    /**
     * @brief   Constructs a slot_base object.
     * @details The state of blocking will be
     *          initialized to false.
     */
    slot_base();

    /**
     * @brief   Destroys the slot_base.
     */
    virtual ~slot_base();

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

    /**
     * @brief   Returns whether the slot contains no functor.
     * @return  True if the slot is empty.
     */
    virtual bool empty() const = 0;

    /**
     * @brief   When notificated about the destruction of the
     *          object used in the slot, the slot becomes
     *          invalid, it removes callbacks associated with
     *          the destroyed object, and asks the signal holding
     *          the slot to delete it. Disconnection takes place
     *          in the destructor, when the slot is deleted by the
     *          signal.
     * @param   destroyed The destroyed object.
     */
    virtual void on_destruction_notification(notifyable* /*destroyed*/) = 0;

    /**
     * @brief   Invalidates the slot by deleting
     *          the internally stored functor object.
     */
    virtual void cleanup() = 0;

};


HYDROSIG_NAMESPACE_END


#endif // HYDROSIG_SLOT_BASE_H_INCLUDED
