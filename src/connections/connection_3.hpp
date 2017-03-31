#pragma once
#ifndef HYDROSIG_CONNECTION_3_HPP_INCLUDED
#define HYDROSIG_CONNECTION_3_HPP_INCLUDED

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

#include "connection_base/connection_base.h"
#include "slots/slot_3.hpp"
#include "macros.h"


HYDROSIG_NAMESPACE_BEGIN


/**
 * Forward declaration of the corresponding signal type.
 */
template<class Return_type,
         class Arg1_type, class Arg2_type, class Arg3_type>
class signal_3;


template<class Return_type,
         class Arg1_type, class Arg2_type, class Arg3_type>
/**
 * @brief   This class represents signal-slot connections,
 *          with three arguments.
 */
class connection_3 : public connection_base
{
private:
    /**< Friend declaration for the signal type */
    friend class signal_3<Return_type,
                          Arg1_type, Arg2_type, Arg3_type>;

    /**< Typedef for the slot type */
    typedef slot_3<Return_type,
                   Arg1_type, Arg2_type, Arg3_type>
    slot_type;

private:
    slot_type* m_slot;  /**< Pointer to the represented slot */

public:
    /**
     * @brief   Constructs a connection_3 object from the
     *          given slot pointer.
     * @param   slot_ptr Pointer to the slot to operate on.
     */
    connection_3(slot_type* slot_ptr)
        : connection_base(),
          m_slot(slot_ptr)
    {
        ;
    }

    /**
     * @brief   Destroys the connection_3 object.
     */
    ~connection_3()
    {
        ;
    }

    /**
     * @brief   Returns whether the represented slot is empty.
     * @return  True if the slot is empty.
     */
    bool empty() const
    {
        return m_slot->empty();
    }

    /**
     * @brief   Sets the blocking state of the represented slot.
     * @param   shouldBlock The state of blocking.
     */
    void block(bool shouldBlock = true)
    {
        m_slot->block(shouldBlock);
    }

    /**
     * @brief   Unblocks the represented slot.
     */
    void unblock()
    {
        m_slot->unblock();
    }

    /**
     * @brief   Returns whether the represented
     *          slot is blocked.
     * @return  True if the slot is blocked.
     */
    bool isBlocked() const
    {
        return m_slot->isBlocked();
    }

    /**
     * @brief   Activates the represented slot.
     */
    Return_type activate(Arg1_type arg1, Arg2_type arg2, Arg3_type arg3)
    {
        try {
            return m_slot->activate(arg1,arg2,arg3);
        }
        catch(...)
        {
            throw;
        }
    }

    /**
     * @brief   Activates the represented slot.
     * @details This is a convenience operator,
     *          and simply calls activate().
     */
    Return_type operator()(Arg1_type arg1, Arg2_type arg2, Arg3_type arg3)
    {
        try {
            return activate(arg1,arg2,arg3);
        }
        catch(...)
        {
            throw;
        }
    }

};


HYDROSIG_NAMESPACE_END


#endif // HYDROSIG_CONNECTION_3_HPP_INCLUDED
