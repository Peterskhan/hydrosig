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

#include "src/macros.h"
#include "src/connections/connection_base/connection_base.h"
#include "src/slots/slot_3.hpp"
#include "src/signals/signal_3.hpp"


HYDROSIG_NAMESPACE_BEGIN


/**
 * Forward declarations:
 * ---------------------
 */

HYDROSIG_TEMPLATE_3_ARG
class connection_3;

HYDROSIG_TEMPLATE_3_ARG
class scoped_connection_3;




/**
 * Class declarations:
 * -------------------
 */

/**
 * @brief   This class represents signal-slot connections,
 *          with three arguments.
 */
HYDROSIG_TEMPLATE_3_ARG
class connection_3 : public connection_base
{
    /**< Friend declaration for scoped_connections */
    friend class scoped_connection_3<HYDROSIG_3_ARG>;

public:
    /**< Typedef for the slot type */
    typedef slot_3<HYDROSIG_3_ARG> slot_type;

    /**< Typedef for the signal type */
    typedef signal_3_base<HYDROSIG_3_ARG> signal_type;

    /**
     * @brief   Constructs a connection_3 object from the
     *          given slot pointer, signal pointer and validator.
     * @param   slot_ptr Pointer to the slot to represent.
     * @param   signal_ptr Pointer to the represented slot's
     *                     holder signal.
     * @param   validator The validator of the represented slot.
     */
    connection_3(HYDROSIG_WEAK_PTR_TYPE<slot_type> slot_ptr,
                 signal_type *signal_ptr,
                 HYDROSIG_SHARED_PTR_TYPE<connection_validator> validator);

    /**
     * @brief   Constructs a connection_3 by copying src.
     * @param   src The connection to copy.
     */
    connection_3(const connection_3 &src);

    /**
     * @brief   Constructs a connection_3 by moving src.
     * @details Note that src should not be used after the move.
     * @param   src The connection to move.
     */
    connection_3(connection_3 &&src);

    /**
     * @brief   Destroys the connection_3 object.
     */
    virtual ~connection_3();

    /**
     * @brief   Copy assigns src to this connection_3.
     * @param   src The connection object to copy.
     */
    connection_3& operator=(const connection_3 &src);

    /**
     * @brief   Move assigns src to this connection_3.
     * @param   src The connection object to move.
     * @details Note that src should not be used after the move.
     */
    connection_3& operator=(connection_3 &&src);

    /**
     * @brief   Returns whether the represented slot is disconnected.
     * @return  True if the slot is disconnected.
     */
    bool isConnected() const;

    /**
     * @brief   Disconnects the represented slot from the signal.
     */
    void disconnect() const;

    /**
     * @brief   Sets the blocking state of the represented slot.
     * @param   shouldBlock The state of blocking.
     */
    void block(bool shouldBlock = true);

    /**
     * @brief   Unblocks the represented slot.
     */
    void unblock();

    /**
     * @brief   Returns whether the represented
     *          slot is blocked.
     * @return  True if the slot is blocked.
     */
    bool isBlocked() const;

    /**
     * @brief   Activates the represented slot.
     * @details Calling this function when the
     *          connection is disconnected yields
     *          undefined behaviour, make sure to
     *          check the state of connection before
     *          the activation.
     * @param   arg1 The first argument.
     * @param   arg2 The second argument.
     * @param   arg3 The third argument.
     * @return  The result of the slot activation.
     */
    Return_type activate(Arg1_type arg1, Arg2_type arg2, Arg3_type arg3);

    /**
     * @brief   Activates the represented slot.
     * @details This is a convenience operator,
     *          which calls activate().
     *          Calling this operator when the
     *          connection is disconnected yields
     *          undefined behaviour, make sure to
     *          check the state of connection before
     *          the activation.
     * @param   arg1 The first argument.
     * @param   arg2 The second argument.
     * @param   arg3 The third argument.
     * @return  The result of the slot activation.
     */
    Return_type operator()(Arg1_type arg1, Arg2_type arg2, Arg3_type arg3);

    /**
     * @brief   Swaps this connection_3 with another.
     * @param   src The other connection_3 object.
     */
    void swap(connection_3 &src);

    /**
     * @brief   Compares this connection_3 with another
     *          for equality.
     * @param   rhs The other connection_3 object.
     * @return  True if connections are equal.
     */
    bool operator==(const connection_3 &rhs);

    /**
     * @brief   Compares this connection_3 with another
     *          for unequality.
     * @param   rhs The other connection_3 object.
     * @return  True if connections are unequal.
     */
    bool operator!=(const connection_3 &rhs);

protected:
    /**< Pointer to the represented slot */
    HYDROSIG_WEAK_PTR_TYPE<slot_type> m_slot;

    /**< Pointer to the represented slot's holder signal */
    signal_type* m_signal;

};

/**
 * @brief   This class represents signal-slot connections,
 *          with three arguments, which will be automatically
 *          disconnected when the scoped_connection object is
 *          destroyed.
 */
HYDROSIG_TEMPLATE_3_ARG
class scoped_connection_3 : public connection_3<HYDROSIG_3_ARG>
{
public:
    /**
     * @brief   Copies an existing connection object to manage
     *          the scope of it's connection.
     * @param   src The connection object to copy.
     */
    scoped_connection_3(const connection_3<HYDROSIG_3_ARG> &src);

    /**
     * @brief   Constructs a scoped_connection_3 by moving src.
     * @details Note that src should not be used after the move.
     * @param   src The connection object to move.
     */
    scoped_connection_3(scoped_connection_3 &&src);

    /**
     * @brief   Constructs a scoped_connection_3 by moving src.
     * @details Note that src should not be used after the move.
     * @param   src The connection object to move.
     */
    scoped_connection_3(connection_3<HYDROSIG_3_ARG> &&src);

    /**
     * @brief   Destroys the scoped_connection_3 object.
     * @details The represented slot will also be disconnected
     *          from the holder signal.
     */
    ~scoped_connection_3();

    /**
     * @brief   Copies an existing connection object to manage
     *          the scope of it's connection.
     * @return  src The connection object to copy.
     */
    scoped_connection_3& operator=(const connection_3<HYDROSIG_3_ARG> &src);

    /**
     * @brief   Copy assignment of a scoped_connection_3 is disabled.
     */
    scoped_connection_3& operator=(const scoped_connection_3& /*src*/) = delete;

    /**
     * @brief   Move assigns src to this scoped_connection_3.
     * @details Note that src should not be used after the move.
     * @param   src The connection object to move.
     */
    scoped_connection_3& operator=(scoped_connection_3 &&src);

    /**
     * @brief   Move assigns src to this scoped_connection_3.
     * @details Note that src should not be used after the move.
     * @param   src The connection object to move.
     */
    scoped_connection_3& operator=(connection_3<HYDROSIG_3_ARG> &&src);

    /**
     * @brief   Releases the connection and returns a normal
     *          connection object.
     * @details The scoped_connection_3 will be reset, and
     *          will not disconnect the connection upon
     *          destruction.
     * @return  A connection_3 object, referring the connection.
     */
    connection_3<HYDROSIG_3_ARG> release();

};




/**
 * Function declarations:
 * ----------------------
 */

/**
 * @brief   Swaps three connection_3 objects.
 * @param   lhs The left side operand.
 * @param   rhs The right side operand.
 */
HYDROSIG_TEMPLATE_3_ARG
void swap(connection_3<HYDROSIG_3_ARG> &lhs,
          connection_3<HYDROSIG_3_ARG> &rhs);




/**
 * Member definitions:
 * -------------------
 */

HYDROSIG_TEMPLATE_3_ARG
connection_3<HYDROSIG_3_ARG>::connection_3(
        HYDROSIG_WEAK_PTR_TYPE<slot_type> slot_ptr,
        signal_type *signal_ptr,
        HYDROSIG_SHARED_PTR_TYPE<connection_validator> validator)
    : connection_base(validator),
      m_slot(slot_ptr),
      m_signal(signal_ptr)
{
    ;
}

HYDROSIG_TEMPLATE_3_ARG
connection_3<HYDROSIG_3_ARG>::connection_3(const connection_3 &src)
    : connection_base()
{
    HYDROSIG_REMOTE_PROTECTED_BLOCK_BEGIN

    m_validator = src.m_validator;
    m_slot = src.m_slot;
    m_signal = src.m_signal;

    HYDROSIG_REMOTE_PROTECTED_BLOCK_END
}

HYDROSIG_TEMPLATE_3_ARG
connection_3<HYDROSIG_3_ARG>::connection_3(connection_3 &&src)
    : connection_base()
{
    HYDROSIG_REMOTE_PROTECTED_BLOCK_BEGIN

    m_validator = std::move(src.m_validator);
    m_slot = std::move(src.m_slot);
    m_signal = std::move(src.m_signal);

    HYDROSIG_REMOTE_PROTECTED_BLOCK_END

}

HYDROSIG_TEMPLATE_3_ARG
connection_3<HYDROSIG_3_ARG>::~connection_3()
{
    ;
}

HYDROSIG_TEMPLATE_3_ARG
connection_3<HYDROSIG_3_ARG>& connection_3<HYDROSIG_3_ARG>::operator=(
        const connection_3 &src)
{
    if(this == &src) return *this;

    HYDROSIG_REMOTE_PROTECTED_BLOCK_BEGIN
    HYDROSIG_PROTECTED_BLOCK_BEGIN

    m_validator = src.m_validator;
    m_slot = src.m_slot;
    m_signal = src.m_signal;

    HYDROSIG_PROTECTED_BLOCK_END
    HYDROSIG_REMOTE_PROTECTED_BLOCK_END

    return *this;
}

HYDROSIG_TEMPLATE_3_ARG
connection_3<HYDROSIG_3_ARG>& connection_3<HYDROSIG_3_ARG>::operator=(
        connection_3 &&src)
{
    if(this == &src) return *this;

    HYDROSIG_REMOTE_PROTECTED_BLOCK_BEGIN
    HYDROSIG_PROTECTED_BLOCK_BEGIN

    m_validator = std::move(src.m_validator);
    m_slot = std::move(src.m_slot);
    m_signal = std::move(src.m_signal);

    HYDROSIG_PROTECTED_BLOCK_END
    HYDROSIG_REMOTE_PROTECTED_BLOCK_END

    return *this;
}

HYDROSIG_TEMPLATE_3_ARG
bool connection_3<HYDROSIG_3_ARG>::isConnected() const
{
    if(m_validator == nullptr) return false;

    return m_validator->isValid();
}

HYDROSIG_TEMPLATE_3_ARG
void connection_3<HYDROSIG_3_ARG>::disconnect() const
{
    if(!isConnected()) return;

    m_signal->disconnect(m_slot.lock());
}

HYDROSIG_TEMPLATE_3_ARG
void connection_3<HYDROSIG_3_ARG>::block(bool shouldBlock)
{
    if(!isConnected()) return;

    m_slot.lock()->block(shouldBlock);
}

HYDROSIG_TEMPLATE_3_ARG
void connection_3<HYDROSIG_3_ARG>::unblock()
{
    if(!isConnected()) return;

    m_slot.lock()->unblock();
}

HYDROSIG_TEMPLATE_3_ARG
bool connection_3<HYDROSIG_3_ARG>::isBlocked() const
{
    if(!isConnected()) return true;

    return m_slot.lock()->isBlocked();
}

HYDROSIG_TEMPLATE_3_ARG
Return_type connection_3<HYDROSIG_3_ARG>::activate(
        Arg1_type arg1, Arg2_type arg2, Arg3_type arg3)
{
    try {
        return m_slot.lock()->activate(arg1, arg2, arg3);
    }
    catch(...)
    {
        throw;
    }
}

HYDROSIG_TEMPLATE_3_ARG
Return_type connection_3<HYDROSIG_3_ARG>::operator()(
        Arg1_type arg1, Arg2_type arg2, Arg3_type arg3)
{
    try {
        return activate(arg1, arg2, arg3);
    }
    catch(...)
    {
        throw;
    }
}

HYDROSIG_TEMPLATE_3_ARG
void connection_3<HYDROSIG_3_ARG>::swap(connection_3 &src)
{
    HYDROSIG_REMOTE_PROTECTED_BLOCK_BEGIN
    HYDROSIG_PROTECTED_BLOCK_BEGIN

    std::swap(m_validator, src.m_validator);
    std::swap(m_slot, src.m_slot);
    std::swap(m_signal, src.m_signal);

    HYDROSIG_PROTECTED_BLOCK_END
    HYDROSIG_REMOTE_PROTECTED_BLOCK_END
}

HYDROSIG_TEMPLATE_3_ARG
bool connection_3<HYDROSIG_3_ARG>::operator==(const connection_3 &rhs)
{
    return (m_validator == rhs.m_validator);
}

HYDROSIG_TEMPLATE_3_ARG
bool connection_3<HYDROSIG_3_ARG>::operator!=(const connection_3 &rhs)
{
    return (m_validator != rhs.m_validator);
}

HYDROSIG_TEMPLATE_3_ARG
scoped_connection_3<HYDROSIG_3_ARG>::scoped_connection_3(
        const connection_3<HYDROSIG_3_ARG> &src)
    : connection_3<HYDROSIG_3_ARG>(src.m_slot,
                                   src.m_signal,
                                   src.m_validator)
{
    ;
}

HYDROSIG_TEMPLATE_3_ARG
scoped_connection_3<HYDROSIG_3_ARG>::scoped_connection_3(
        scoped_connection_3 &&src)
    : connection_3<HYDROSIG_3_ARG>(std::move(src.m_slot),
                                   std::move(src.m_signal),
                                   std::move(src.m_validator))
{
    ;
}

HYDROSIG_TEMPLATE_3_ARG
scoped_connection_3<HYDROSIG_3_ARG>::scoped_connection_3(
        connection_3<HYDROSIG_3_ARG> &&src)
    : connection_3<HYDROSIG_3_ARG>(std::move(src.m_slot),
                                   std::move(src.m_signal),
                                   std::move(src.m_validator))
{
    ;
}

HYDROSIG_TEMPLATE_3_ARG
scoped_connection_3<HYDROSIG_3_ARG>::~scoped_connection_3()
{
    this->disconnect();
}

HYDROSIG_TEMPLATE_3_ARG
scoped_connection_3<HYDROSIG_3_ARG>& scoped_connection_3<HYDROSIG_3_ARG>::operator=(
        const connection_3<HYDROSIG_3_ARG> &src)
{
    if(this == &src) return *this;

    connection_3<HYDROSIG_3_ARG>::operator=(src);

    return *this;
}

HYDROSIG_TEMPLATE_3_ARG
scoped_connection_3<HYDROSIG_3_ARG>& scoped_connection_3<HYDROSIG_3_ARG>::operator=(
        scoped_connection_3 &&src)
{
    if(this == &src) return *this;

    connection_3<HYDROSIG_3_ARG>::operator=(
                std::forward<connection_3<HYDROSIG_3_ARG>>(src));

    return *this;
}

HYDROSIG_TEMPLATE_3_ARG
scoped_connection_3<HYDROSIG_3_ARG>& scoped_connection_3<HYDROSIG_3_ARG>::operator=(
        connection_3<HYDROSIG_3_ARG> &&src)
{
    if(this == &src) return *this;

    connection_3<HYDROSIG_3_ARG>::operator=(
                std::forward<connection_3<HYDROSIG_3_ARG>>(src));

    return *this;
}

HYDROSIG_TEMPLATE_3_ARG
connection_3<HYDROSIG_3_ARG> scoped_connection_3<HYDROSIG_3_ARG>::release()
{
    HYDROSIG_PROTECTED_BLOCK_BEGIN

    connection_3<HYDROSIG_3_ARG> released(this->m_slot,
                                          this->m_signal,
                                          this->m_validator);

    this->m_validator = nullptr;
    this->m_signal = nullptr;
    this->m_slot.reset();

    HYDROSIG_PROTECTED_BLOCK_END

    return released;
}




/**
 * Function definitions:
 * ---------------------
 */

HYDROSIG_TEMPLATE_3_ARG
void swap(connection_3<HYDROSIG_3_ARG> &lhs,
          connection_3<HYDROSIG_3_ARG> &rhs)
{
    lhs.swap(rhs);
}


HYDROSIG_NAMESPACE_END


#endif // HYDROSIG_CONNECTION_3_HPP_INCLUDED
