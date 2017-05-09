#pragma once
#ifndef HYDROSIG_SIGNAL_BASE_H_INCLUDED
#define HYDROSIG_SIGNAL_BASE_H_INCLUDED

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

#ifdef HYDROSIG_HYDROGEN_AVAILABLE
# include ../HContainers/HList/HList.hpp
# include ../HConcurrent/HMutex.h
#else
# include <list>
# include <mutex>
#endif

#include "src/trackable/trackable.h"


HYDROSIG_NAMESPACE_BEGIN


/**
 * @brief   This abstract base class defines the common,
 *          type-independent interface of all signal classes.
 * @details Signal classes keep track of established signal-slot
 *          connections, handle connection, disconnection and
 *          emission of these connections. The blocking mechanism
 *          is shared between all signal types, and is implemented
 *          in this base class. Certain informations, like the
 *          emptyness or size of the signal, are also common, but
 *          type-dependent, so pure virtual methods are provided
 *          to be overriden. Clearing a signal, and it's response
 *          when it receives a destruction notification is also
 *          implemented in the derived signal classes.
 */
class signal_base
{
public:
    /**
     * @brief   Constructs a signal in a non-blocked state.
     */
    signal_base();

    /**
     * @brief   Destroys the signal, and terminates all
     *          established connections.
     */
    virtual ~signal_base();

    /**
     * @brief   Returns whether the signal is blocked.
     * @return  True if the signal is blocked.
     */
    bool isBlocked() const;

    /**
     * @brief   Sets the blocking state of the signal.
     * @details If the signal is blocked, it will ignore
     *          calls to emission methods.
     * @param   shouldBlock The state of blocking.
     */
    void block(bool shouldBlock = true);

    /**
     * @brief   Unblocks the signal.
     */
    void unblock();

    /**
     * @brief   Returns the number of connected slots.
     * @return  The number of connected slots.
     */
    virtual unsigned int size() const = 0;

    /**
     * @brief   Returns whether no slots are connected
     *          to the signal.
     * @return  True if there are no slots connected.
     */
    virtual bool empty() const = 0;

    /**
     * @brief   Removes all slots connected to the signal.
     */
    virtual void clear() = 0;

protected:
    /**< The blocking state of the signal */
    bool m_blocked;

    /**< Mutex used for synchronisation */
    mutable HYDROSIG_MUTEX_TYPE m_mutex;

};


HYDROSIG_NAMESPACE_END


#endif // HYDROSIG_SIGNAL_BASE_H_INCLUDED
