#pragma once
#ifndef HYDROSIG_SLOT_2_HPP_INCLUDED
#define HYDROSIG_SLOT_2_HPP_INCLUDED

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

#include "slot_base/slot_base.h"
#include "functors/functor_2.hpp"
#include "macros.h"


HYDROSIG_NAMESPACE_BEGIN


template<class Return_type,
         class Arg1_type, class Arg2_type>
/**
 * @brief   This class represents a slot holding a
 *          functor which accept two arguments.
 */
class slot_2 : public slot_base
{
public:
    /**< Typedef for the functor type */
    typedef functor_2_base<Return_type,
                           Arg1_type, Arg2_type>
    functor_type;

private:
    functor_type* m_functor;        /**< The functor to the encapsulated function */

public:
    /**
     * @brief   Constructs a slot_2 from a pointer to
     *          a functor.
     * @details If no functor is provided the created
     *          slot is invalid, and empty() returns
     *          true. Activating an invalid slot does
     *          not result in undefined behaviour.
     * @param   functor_ptr Pointer to the functor object.
     */
    slot_2(functor_type* functor_ptr = nullptr)
        : slot_base(),
          m_functor(functor_ptr)
    {
        ;
    }

    /**
     * @brief   Copy constructing a slot is disallowed, because
     *          of the complicated callback relations with
     *          the (potentially) connected object and the
     *          holding signal object.
     */
    slot_2(const slot_2& /*src*/) = delete;

    /**
     * @brief   Move constructing a slot is disallowed, because
     *          of the complicated callback relations with
     *          the (potentially) connected object and the
     *          holding signal object.
     */
    slot_2(slot_2&& /*src*/) = delete;

    /**
     * @brief   Assignment of a slot is disallowed, because
     *          of the complicated callback relations with
     *          the (potentially) connected object and the
     *          holding signal object.
     */
    slot_2& operator=(const slot_2& /*src*/) = delete;

    /**
     * @brief   Move assignment of a slot is disallowed, because
     *          of the complicated callback relations with
     *          the (potentially) connected object and the
     *          holding signal object.
     */
    slot_2& operator=(slot_2&& /*src*/) = delete;

    /**
     * @brief   Destroys the slot_2 object.
     * @details Upon destruction the slot disconnects
     *          automatically it's connection, by deleting
     *          the internally stored functor and executing
     *          all installed destruction notification
     *          callbacks.
     */
    virtual ~slot_2()
    {
        cleanup();
        notify_callbacks();
    }

    /**
     * @brief   Returns the internally stored functor object.
     * @return  The functor object.
     */
    functor_type* get_functor() const
    {
        return m_functor;
    }

    /**
     * @brief   Returns whether the slot contains no functor.
     * @return  True if the slot is empty.
     */
    bool empty() const
    {
        return (m_functor == nullptr);
    }

    /**
     * @brief   Activates the internally stored functor object.
     * @param   The first argument.
     * @param   The second argument.
     * @return  The result of calling the functor.
     */
    Return_type activate(Arg1_type arg1, Arg2_type arg2)
    {
        try {
            return (*m_functor)(arg1,arg2);
        }
        catch(...)
        {
            throw;
        }
    }

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
    void on_destruction_notification(notifyable* destroyed)
    {
        // Removing callbacks associated with the
        // destroyed object
        trackable::on_destruction_notification(destroyed);

        // Notifying the holding signal to delete
        // this slot
        notify_callbacks();
    }

private:
    /**
     * @brief   Invalidates the slot by deleting
     *          the internally stored functor object.
     */
    void cleanup()
    {
        delete m_functor;
        m_functor = nullptr;
    }

};


HYDROSIG_NAMESPACE_END


#endif // HYDROSIG_SLOT_2_HPP_INCLUDED
