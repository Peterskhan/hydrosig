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

#include "src/macros.h"
#include "src/trackable/trackable.h"


HYDROSIG_NAMESPACE_BEGIN


/**
 * Class declarations:
 * -------------------
 */

/**
 * @brief   This abstract base class defines the common,
 *          type-independent interface of all connection
 *          classes.
 * @details Connection classes provide a handle to the
 *          underlying slot they represent. This base class
 *          provides virtual methods for accessing the
 *          blocking mechanism and validation of the
 *          represented slot object.
 */
class connection_base
{
public:
    /**
     * @brief   Constructs a connection_base with the provided
     *          connection_validator.
     * @param   validator The connection_validator to use.
     */
    connection_base(HYDROSIG_SHARED_PTR_TYPE<connection_validator> validator);

    /**
     * @brief   Returns whether the represented slot is connected.
     * @return  True if the slot is connected.
     */
    bool isConnected() const;

    /**
     * @brief   Disconnects the represented slot from the signal.
     */
    virtual void disconnect() const = 0;

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
     * @brief   Returns whether the represented slot is blocked.
     * @return  True if the slot is blocked, false otherwise.
     */
    virtual bool isBlocked() const = 0;

protected:
    /**< The connection validator of the represented slot */
    HYDROSIG_SHARED_PTR_TYPE<connection_validator> m_validator;

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
    virtual const char* what() const noexcept;

};




/**
 * Function declarations:
 * ----------------------
 */


/**
 * Function definitions:
 * ---------------------
 */


HYDROSIG_NAMESPACE_END


#endif // HYDROSIG_CONNECTION_BASE_H_INCLUDED
