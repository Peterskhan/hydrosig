#pragma once
#ifndef HYDROSIG_CONNECTION_BASE_H_INCLUDED
#define HYDROSIG_CONNECTION_BASE_H_INCLUDED

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
 * @brief   This abstract base class defines the common,
 *          type-independent interface of all connection
 *          classes.
 * @details Connection classes provide a handle to the
 *          underlying slot they represent. As most of
 *          the operations a connection can provide as
 *          an interface to the represented slot are
 *          type dependent, this base class only provides
 *          pure virtual methods for accessing the common,
 *          semantically type-independent interaface. The
 *          rest of the accessor methods are available in
 *          the derived connection classes.
 */
class connection_base
{
public:

    /**
     * @brief   Returns whether the represented slot is empty.
     * @return  True if the slot is empty.
     */
    virtual bool empty() const = 0;

    /**
     * @brief   Sets the blocking state of the represented slot.
     * @param   shouldBlock The state of blocking.
     */
    virtual void block(bool shouldBlock = true) = 0;

    /**
     * @brief   Unblocks the represented slot.
     */
    virtual void unblock() = 0;

    /**
     * @brief   Returns whether the represented
     *          slot is blocked.
     * @return  True if the slot is blocked.
     */
    virtual bool isBlocked() const = 0;

};

/**
 * @brief   This class represents a connection failure exception,
 *          which is thrown by signals, when the signal connection
 *          can not be established, due to internal memory allocation
 *          failure.
 */
class connection_failure : public std::exception
{
public:
    /**
     * @brief   Returns an explanatory string about the exception.
     * @return  The explanatory string.
     */
    virtual const char* what() const noexcept
    {
        return "Hydrosig++: Signal connection failed, due to memory allocation failure.";
    }
};


HYDROSIG_NAMESPACE_END


#endif // HYDROSIG_CONNECTION_BASE_H_INCLUDED
