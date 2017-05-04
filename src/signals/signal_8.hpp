#pragma once
#ifndef HYDROSIG_SIGNAL_8_HPP_INCLUDED
#define HYDROSIG_SIGNAL_8_HPP_INCLUDED

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

#include <type_traits>

#include "macros.h"
#include "signal_base/signal_base.h"
#include "make_funs/make_fun_8.h"
#include "comp_funs/comp_fun_8.h"
#include "slots/slot_8.hpp"
#include "connections/connection_8.hpp"


HYDROSIG_NAMESPACE_BEGIN

/**
 * Forward declarations:
 * ---------------------
 */

HYDROSIG_TEMPLATE_8_ARG
class connection_8;




/**
 * Class declarations:
 * -------------------
 */

/**
 * @brief   This class forms the base of signal types
 *          with 8 arguments. It is responsible for
 *          implementing the connection and disconnection
 *          mechanism, construction and copy/move semantics.
 */
HYDROSIG_TEMPLATE_8_ARG
class signal_8_base : public signal_base
{
public:
    /**< Typedef for the slot type */
    typedef slot_8<HYDROSIG_8_ARG>
    slot_type;

    /**< Typedef for the connection type */
    typedef connection_8<HYDROSIG_8_ARG>
    connection_type;

    /**< Typedef for the list of slots */
    typedef HYDROSIG_LIST_TYPE<HYDROSIG_SHARED_PTR_TYPE<slot_type>>
    slot_list;

    /**
     * @brief   Constructs a signal_8 object.
     */
    signal_8_base();

    /**
     * @brief   Constructs a signal_8_base object by copying src.
     * @details Signals with connected slots are not meant
     *          to be copied, and should be only done so when
     *          the object encapsulating it is being copied.
     *          Established connections are not copied into the
     *          new object, and it is set into a default state.
     * @param   src The signal object to copy.
     */
    signal_8_base(const signal_8_base& /*src*/);

    /**
     * @brief   Constructs a signal_8 by moving src.
     * @details In the moving process src loses all of
     *          it's connections, they are transferred
     *          to this signal. The state of the constructed
     *          signal is matching the state of src before
     *          the move construction.
     * @param   src The signal to move.
     */
    signal_8_base(signal_8_base&& src);

    /**
     * @brief   Copy assigns src to this signal.
     * @details Signals with connected slots are not meant
     *          to be copied, and should be only done so when
     *          the object encapsulating it is being copied.
     *          Established connections are not copied into the
     *          new object, and it is set into a default state.
     * @param   src The signal object to copy.
     */
    signal_8_base& operator=(const signal_8_base& /*src*/);

    /**
     * @brief   Move assigns src to this signal.
     * @details In the moving process src loses all of
     *          it's connections, they are transferred
     *          to this signal. The state of the constructed
     *          signal is matching the state of src before
     *          the move assignment.
     * @param   src The signal to move.
     */
    signal_8_base& operator=(signal_8_base&& src);

    /**
     * @brief   Destroys the signal_8.
     */
    virtual ~signal_8_base();

    /**
     * @brief   Returns the number of connected slots.
     * @return  The number of connected slots.
     */
    unsigned int size() const;

    /**
     * @brief   Returns whether there are no slots
     *          are connected to the signal.
     * @return  True if there are no slots connected,
     *          false otherwise.
     */
    bool empty() const;

    /**
     * @brief   Removes all slots connected to the signal.
     */
    void clear();

    /**
     * @brief   Connects a free function to the signal.
     * @param   function Pointer to the free function.
     */
    connection_type connect(Return_type(*function)(
                                Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                                Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                                Arg7_type arg7, Arg8_type arg8));

    /**
     * @brief   Connects an object and it's member function
     *          (with no specifiers) to the signal.
     * @details This version is used for untrackable objects.
     * @param   object Pointer to the object.
     * @param   function Pointer to the member function.
     */
    HYDROSIG_CONNECT_ENABLER_UNTRACKABLE
    connect(Object_type* object,
            Return_type(Object_type::*function)(
                Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                Arg7_type arg7, Arg8_type arg8));

    /**
     * @brief   Connects an object and it's member function
     *          (with no specifiers) to the signal.
     * @details This version is used for trackable objects.
     * @param   object Pointer to the object.
     * @param   function Pointer to the member function.
     */
    HYDROSIG_CONNECT_ENABLER_TRACKABLE
    connect(Object_type* object,
            Return_type(Object_type::*function)(
                Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                Arg7_type arg7, Arg8_type arg8));

    /**
     * @brief   Connects an object and it's member function
     *          (with const specifier) to the signal.
     * @details This version is used for untrackable objects.
     * @param   object Pointer to the object.
     * @param   function Pointer to the member function.
     */
    HYDROSIG_CONNECT_ENABLER_UNTRACKABLE
    connect(Object_type* object,
            Return_type(Object_type::*function)(
                Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                Arg7_type arg7, Arg8_type arg8) const);

    /**
     * @brief   Connects an object and it's member function
     *          (with const specifier) to the signal.
     * @details This version is used for trackable objects.
     * @param   object Pointer to the object.
     * @param   function Pointer to the member function.
     */
    HYDROSIG_CONNECT_ENABLER_TRACKABLE
    connect(Object_type* object,
            Return_type(Object_type::*function)(
                Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                Arg7_type arg7, Arg8_type arg8) const);

    /**
     * @brief   Connects an object and it's member function
     *          (with volatile specifier) to the signal.
     * @details This version is used for untrackable objects.
     * @param   object Pointer to the object.
     * @param   function Pointer to the member function.
     */
    HYDROSIG_CONNECT_ENABLER_UNTRACKABLE
    connect(Object_type* object,
            Return_type(Object_type::*function)(
                Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                Arg7_type arg7, Arg8_type arg8) volatile);

    /**
     * @brief   Connects an object and it's member function
     *          (with volatile specifier) to the signal.
     * @details This version is used for trackable objects.
     * @param   object Pointer to the object.
     * @param   function Pointer to the member function.
     */
    HYDROSIG_CONNECT_ENABLER_TRACKABLE
    connect(Object_type* object,
            Return_type(Object_type::*function)(
                Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                Arg7_type arg7, Arg8_type arg8) volatile);

    /**
     * @brief   Connects an object and it's member function
     *          (with const volatile specifiers) to the signal.
     * @details This version is used for untrackable objects.
     * @param   object Pointer to the object.
     * @param   function Pointer to the member function.
     */
    HYDROSIG_CONNECT_ENABLER_UNTRACKABLE
    connect(Object_type* object,
            Return_type(Object_type::*function)(
                Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                Arg7_type arg7, Arg8_type arg8) const volatile);

    /**
     * @brief   Connects an object and it's member function
     *          (with const volatile specifiers) to the signal.
     * @details This version is used for trackable objects.
     * @param   object Pointer to the object.
     * @param   function Pointer to the member function.
     */
    HYDROSIG_CONNECT_ENABLER_TRACKABLE
    connect(Object_type* object,
            Return_type(Object_type::*function)(
                Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                Arg7_type arg7, Arg8_type arg8) const volatile);

    /**
     * @brief   Connects a callable object to the signal.
     * @details A copy of the callable object is made
     *          and stored in the created slot.
     * @param   callable The callable object.
     */
    template<class Callable_type>
    connection_type connect(Callable_type callable);

    /**
     * @brief   Disconnects a free function indicated by
     *          a pointer to it.
     * @param   function Pointer to the free function.
     * @param   disconnectAll Whether all matching connections
     *                        should be disconnected, or only
     *                        the first match.
     */
    void disconnect(Return_type(*function)(
                        Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                        Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                        Arg7_type arg7, Arg8_type arg8),
                    bool disconnectAll = false);

    /**
     * @brief   Disconnects a member function with no
     *          specifiers of the given object.
     * @details This version is used for untrackable objects.
     * @param   object Pointer to the object.
     * @param   function Pointer to the member function.
     * @param   disconnectAll Whether all matching connections
     *                        should be disconnected, or only
     *                        the first match.
     */
    HYDROSIG_DISCONNECT_ENABLER_UNTRACKABLE
    disconnect(Object_type* object,
               Return_type(Object_type::*function)(
                   Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                   Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                   Arg7_type arg7, Arg8_type arg8),
               bool disconnectAll = false);

    /**
     * @brief   Disconnects a member function with no
     *          specifiers of the given object.
     * @details This version is used for trackable objects.
     * @param   object Pointer to the object.
     * @param   function Pointer to the member function.
     * @param   disconnectAll Whether all matching connections
     *                        should be disconnected, or only
     *                        the first match.
     */
    HYDROSIG_DISCONNECT_ENABLER_TRACKABLE
    disconnect(Object_type* object,
               Return_type(Object_type::*function)(
                   Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                   Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                   Arg7_type arg7, Arg8_type arg8),
               bool disconnectAll = false);

    /**
     * @brief   Disconnects a member function with const
     *          specifier of the given object.
     * @details This version is used for untrackable objects.
     * @param   object Pointer to the object.
     * @param   function Pointer to the member function.
     * @param   disconnectAll Whether all matching connections
     *                        should be disconnected, or only
     *                        the first match.
     */
    HYDROSIG_DISCONNECT_ENABLER_UNTRACKABLE
    disconnect(Object_type* object,
               Return_type(Object_type::*function)(
                   Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                   Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                   Arg7_type arg7, Arg8_type arg8) const,
               bool disconnectAll = false);

    /**
     * @brief   Disconnects a member function with const
     *          specifier of the given object.
     * @details This version is used for trackable objects.
     * @param   object Pointer to the object.
     * @param   function Pointer to the member function.
     * @param   disconnectAll Whether all matching connections
     *                        should be disconnected, or only
     *                        the first match.
     */
    HYDROSIG_DISCONNECT_ENABLER_TRACKABLE
    disconnect(Object_type* object,
               Return_type(Object_type::*function)(
                   Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                   Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                   Arg7_type arg7, Arg8_type arg8) const,
               bool disconnectAll = false);

    /**
     * @brief   Disconnects a member function with volatile
     *          specifier of the given object.
     * @details This version is used for untrackable objects.
     * @param   object Pointer to the object.
     * @param   function Pointer to the member function.
     * @param   disconnectAll Whether all matching connections
     *                        should be disconnected, or only
     *                        the first match.
     */
    HYDROSIG_DISCONNECT_ENABLER_UNTRACKABLE
    disconnect(Object_type* object,
               Return_type(Object_type::*function)(
                   Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                   Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                   Arg7_type arg7, Arg8_type arg8) volatile,
               bool disconnectAll = false);

    /**
     * @brief   Disconnects a member function with volatile
     *          specifier of the given object.
     * @details This version is used for trackable objects.
     * @param   object Pointer to the object.
     * @param   function Pointer to the member function.
     * @param   disconnectAll Whether all matching connections
     *                        should be disconnected, or only
     *                        the first match.
     */
    HYDROSIG_DISCONNECT_ENABLER_TRACKABLE
    disconnect(Object_type* object,
               Return_type(Object_type::*function)(
                   Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                   Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                   Arg7_type arg7, Arg8_type arg8) volatile,
               bool disconnectAll = false);

    /**
     * @brief   Disconnects a member function with const
     *          volatile specifier of the given object.
     * @details This version is used for untrackable objects.
     * @param   object Pointer to the object.
     * @param   function Pointer to the member function.
     * @param   disconnectAll Whether all matching connections
     *                        should be disconnected, or only
     *                        the first match.
     */
    HYDROSIG_DISCONNECT_ENABLER_UNTRACKABLE
    disconnect(Object_type* object,
               Return_type(Object_type::*function)(
                   Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                   Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                   Arg7_type arg7, Arg8_type arg8) const volatile,
               bool disconnectAll = false);

    /**
     * @brief   Disconnects a member function with const
     *          volatile specifier of the given object.
     * @details This version is used for trackable objects.
     * @param   object Pointer to the object.
     * @param   function Pointer to the member function.
     * @param   disconnectAll Whether all matching connections
     *                        should be disconnected, or only
     *                        the first match.
     */
    HYDROSIG_DISCONNECT_ENABLER_TRACKABLE
    disconnect(Object_type* object,
               Return_type(Object_type::*function)(
                   Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                   Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                   Arg7_type arg7, Arg8_type arg8) const volatile,
               bool disconnectAll = false);

    /**
     * @brief   Disconnects a slot indicated by a pointer to it.
     * @details This function is not designed for client code, and
     *          is used for disconnection by connection objects.
     * @param   slot_ptr A shared pointer to the slot.
     */
    void disconnect(const HYDROSIG_SHARED_PTR_TYPE<slot_type> slot_ptr);

    /**
     * @brief   Removes all invalidated slots from the slot-list.
     * @details This function is used upon signal emission, to
     *          remove invalidated slots before emitting. You
     *          may need to call this function manually when you
     *          have objects connected to the signal which are
     *          frequently destroyed without manual disconnection.
     *          Otherwise, such connections are automatically
     *          cleaned up upon the next emission.
     */
    void removeInvalidated();

protected:
    /**< The list of slots */
    slot_list m_slots;

};

/**
 * @brief   This class represents signals with 8 arguments,
 *          using the normal (non-returning) emission mode.
 */
HYDROSIG_TEMPLATE_8_ARG
class signal_8 : public signal_8_base<HYDROSIG_8_ARG>
{
public:
    /**< Typedef for the slot type */
    typedef slot_8<HYDROSIG_8_ARG>
    slot_type;

    /**< Typedef for the list of slots */
    typedef HYDROSIG_LIST_TYPE<HYDROSIG_SHARED_PTR_TYPE<slot_type>>
    slot_list;

    /**
     * @brief   Emits the signal by activating all of the
     *          connected slot's callback functions.
     * @details The slots are activated in the exact same
     *          order they were connected to the signal.
     * @param   arg1 The first argument.
     * @param   arg2 The second argument.
     * @param   arg3 The third argument.
     * @param   arg4 The fourth argument.
     * @param   arg5 The fifth argument.
     * @param   arg6 The sixth argument.
     * @param   arg7 The seventh argument.
     * @param   arg8 The eighth argument.
     */
    void emit(Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
              Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
              Arg7_type arg7, Arg8_type arg8);

    /**
     * @brief   Emits the signal by activating all of the
     *          connected slot's callback functions.
     * @details The slots are activated in reverse order
     *          of they were connected to the signal.
     * @param   arg1 The first argument.
     * @param   arg2 The second argument.
     * @param   arg3 The third argument.
     * @param   arg4 The fourth argument.
     * @param   arg5 The fifth argument.
     * @param   arg6 The sixth argument.
     * @param   arg7 The seventh argument.
     * @param   arg8 The eighth argument.
     */
    void emit_reverse(Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                      Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                      Arg7_type arg7, Arg8_type arg8);

    /**
     * @brief   Emits the signal by activating all of the
     *          connected slot's callback functions.
     * @details The slots are activated in the exact same
     *          order they were connected to the signal.
     *          This is a convenience function, which
     *          calls emit().
     * @param   arg1 The first argument.
     * @param   arg2 The second argument.
     * @param   arg3 The third argument.
     * @param   arg4 The fourth argument.
     * @param   arg5 The fifth argument.
     * @param   arg6 The sixth argument.
     * @param   arg7 The seventh argument.
     * @param   arg8 The eighth argument.
     */
    void operator()(Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                    Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                    Arg7_type arg7, Arg8_type arg8);

    /**< Nested class for emitting signals with collected results */
    class collected;

    /**< Nested class for emitting signals with combined results */
    template<class Combiner_type>
    class combined;

};

/**
 * @brief   This class represents signals with 8 arguments,
 *          using the collected emission mode.
 * @details Collected emission means, that the emitting
 *          functions return a list of the return values
 *          of slot activations.
 */
HYDROSIG_TEMPLATE_8_ARG
class signal_8<HYDROSIG_8_ARG>::collected : public signal_8_base<HYDROSIG_8_ARG>
{
    static_assert(!std::is_same<Return_type, void>::value,
                  "Return values with type 'void' can not be collected.");

public:
    /**
     * @brief   Emits the signal by activating all of the
     *          connected slot's callback functions.
     * @details The slots are activated in the exact same
     *          order they were connected to the signal.
     * @param   arg1 The first argument.
     * @param   arg2 The second argument.
     * @param   arg3 The third argument.
     * @param   arg4 The fourth argument.
     * @param   arg5 The fifth argument.
     * @param   arg6 The sixth argument.
     * @param   arg7 The seventh argument.
     * @param   arg8 The eighth argument.
     * @return  The list of returned values from each slot
     *          activation.
     *
     */
    HYDROSIG_LIST_TYPE<Return_type> emit(
            Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
            Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
            Arg7_type arg7, Arg8_type arg8);

    /**
     * @brief   Emits the signal by activating all of the
     *          connected slot's callback functions.
     * @details The slots are activated in reverse order
     *          of they were connected to the signal.
     * @param   arg1 The first argument.
     * @param   arg2 The second argument.
     * @param   arg3 The third argument.
     * @param   arg4 The fourth argument.
     * @param   arg5 The fifth argument.
     * @param   arg6 The sixth argument.
     * @param   arg7 The seventh argument.
     * @param   arg8 The eighth argument.
     * @return  The list of returned values from each slot
     *          activation.
     */
    HYDROSIG_LIST_TYPE<Return_type> emit_reverse(
            Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
            Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
            Arg7_type arg7, Arg8_type arg8);

    /**
     * @brief   Emits the signal by activating all of the
     *          connected slot's callback functions.
     * @details The slots are activated in the exact same
     *          order they were connected to the signal.
     *          This is a convenience function, which
     *          calls emit().
     * @param   arg1 The first argument.
     * @param   arg2 The second argument.
     * @param   arg3 The third argument.
     * @param   arg4 The fourth argument.
     * @param   arg5 The fifth argument.
     * @param   arg6 The sixth argument.
     * @param   arg7 The seventh argument.
     * @param   arg8 The eighth argument.
     * @return  The list of returned values from each slot
     *          activation.
     */
    HYDROSIG_LIST_TYPE<Return_type> operator()(
            Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
            Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
            Arg7_type arg7, Arg8_type arg8);

};

/**
 * @brief   This class represents signals with 8 arguments,
 *          using the combined emission mode.
 * @details Combined emission means, that the emitting
 *          functions return a combined result of the
 *          return values of slot activations using a
 *          custom combiner.
 */
HYDROSIG_TEMPLATE_8_ARG
template<class Combiner_type>
class signal_8<HYDROSIG_8_ARG>::combined
        : public signal_8_base<HYDROSIG_8_ARG>
{
    static_assert(!std::is_same<Return_type, void>::value,
                  "Return values with type 'void' can not be combined.");

public:
    /**
     * @brief   Constructs a combined signal with a
     *          default combiner.
     */
    combined();

    /**
     * @brief   Constructs a combined signal with a
     *          copy of the supplied combiner.
     * @param   combiner The combiner to use.
     */
    combined(const Combiner_type &combiner);

    /**
     * @brief   Constructs a combined signal by
     *          copying src.
     * @details The combiner is being copied, for
     *          other members, signal_base copy
     *          semantics are applied.
     * @param   src The other combined signal to copy.
     */
    combined(const combined &src);

    /**
     * @brief   Constructs a combined signal by
     *          moving src.
     * @details The combiner is being moved, for
     *          other members, signal_base move
     *          semantics are applied.
     * @param   src The other combined signal to move.
     */
    combined(combined &&src);

    /**
     * @brief   Copy assigns src to this combined signal.
     * @details The combiner is being copied, for
     *          other members, signal_base copy
     *          semantics are applied.
     * @param   src The other combined signal to copy
     *              assign from.
     */
    combined& operator=(const combined &src);

    /**
     * @brief   Move assigns src to this combined signal.
     * @details The combiner is being moved, for
     *          other members, signal_base move
     *          semantics are applied.
     * @param   src The other combined signal to move
     *              assign from.
     */
    combined& operator=(combined &&src);

    /**
     * @brief   Returns the combiner object used by
     *          the combined signal.
     * @return  The internal combiner.
     */
    Combiner_type& getCombiner();

    /**
     * @brief   Sets the combiner used by the
     *          combined signal.
     * @param   combiner The combiner to set.
     */
    void setCombiner(const Combiner_type &combiner);

    /**
     * @brief   Emits the signal by activating all of the
     *          connected slot's callback functions.
     * @details The slots are activated in the exact same
     *          order they were connected to the signal.
     * @param   arg1 The first argument.
     * @param   arg2 The second argument.
     * @param   arg3 The third argument.
     * @param   arg4 The fourth argument.
     * @param   arg5 The fifth argument.
     * @param   arg6 The sixth argument.
     * @param   arg7 The seventh argument.
     * @param   arg8 The eighth argument.
     * @return  The combined result of the return values
     *          of slot activations.
     */
    Return_type emit(Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                     Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                     Arg7_type arg7, Arg8_type arg8);

    /**
     * @brief   Emits the signal by activating all of the
     *          connected slot's callback functions.
     * @details The slots are activated in reverse order
     *          of they were connected to the signal.
     * @param   arg1 The first argument.
     * @param   arg2 The second argument.
     * @param   arg3 The third argument.
     * @param   arg4 The fourth argument.
     * @param   arg5 The fifth argument.
     * @param   arg6 The sixth argument.
     * @param   arg7 The seventh argument.
     * @param   arg8 The eighth argument.
     * @return  The combined result of the return values
     *          of slot activations.
     */
    Return_type emit_reverse(Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                             Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                             Arg7_type arg7, Arg8_type arg8);

    /**
     * @brief   Emits the signal by activating all of the
     *          connected slot's callback functions.
     * @details The slots are activated in the exact same
     *          order they were connected to the signal.
     *          This is a convenience function, which
     *          calls emit().
     * @param   arg1 The first argument.
     * @param   arg2 The second argument.
     * @param   arg3 The third argument.
     * @param   arg4 The fourth argument.
     * @param   arg5 The fifth argument.
     * @param   arg6 The sixth argument.
     * @param   arg7 The seventh argument.
     * @param   arg8 The eighth argument.
     * @return  The combined result of the return values
     *          of slot activations.
     */
    Return_type operator()(Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                           Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                           Arg7_type arg7, Arg8_type arg8);

protected:
    /**< The combiner used by the signal */
    HYDROSIG_SHARED_PTR_TYPE<Combiner_type> m_combiner;

};




/**
 * Member definitions:
 * -------------------
 */

HYDROSIG_TEMPLATE_8_ARG
signal_8_base<HYDROSIG_8_ARG>::signal_8_base()
    : signal_base()
{
    ;
}

HYDROSIG_TEMPLATE_8_ARG
signal_8_base<HYDROSIG_8_ARG>::signal_8_base(
        const signal_8_base& /*src*/)
    : signal_base()
{
    // Do not copy the list of slots
}

HYDROSIG_TEMPLATE_8_ARG
signal_8_base<HYDROSIG_8_ARG>::signal_8_base(
        signal_8_base&& src)
    : signal_base()
{
    // Move the list of slots

    HYDROSIG_REMOTE_PROTECTED_BLOCK_BEGIN

    m_slots = std::move(src.m_slots);
    m_blocked = src.m_blocked;

    HYDROSIG_REMOTE_PROTECTED_BLOCK_END
}

HYDROSIG_TEMPLATE_8_ARG
signal_8_base<HYDROSIG_8_ARG>& signal_8_base<HYDROSIG_8_ARG>::operator=(
        const signal_8_base& /*src*/)
{
    // Do not copy the list of slots

    m_blocked = false;

    return *this;
}

HYDROSIG_TEMPLATE_8_ARG
signal_8_base<HYDROSIG_8_ARG>& signal_8_base<HYDROSIG_8_ARG>::operator=(
        signal_8_base&& src)
{
    if(this == &src) return *this;

    HYDROSIG_REMOTE_PROTECTED_BLOCK_BEGIN
    HYDROSIG_PROTECTED_BLOCK_BEGIN

    // Move the list of slots
    m_slots = std::move(src.m_slots);

    // Copy the blocking state
    m_blocked = src.m_blocked;

    HYDROSIG_PROTECTED_BLOCK_END
    HYDROSIG_REMOTE_PROTECTED_BLOCK_END

    return *this;
}

HYDROSIG_TEMPLATE_8_ARG
signal_8_base<HYDROSIG_8_ARG>::~signal_8_base()
{
    ;
}

HYDROSIG_TEMPLATE_8_ARG
unsigned int signal_8_base<HYDROSIG_8_ARG>::size() const
{
    return m_slots.size();
}

HYDROSIG_TEMPLATE_8_ARG
bool signal_8_base<HYDROSIG_8_ARG>::empty() const
{
    return m_slots.empty();
}

HYDROSIG_TEMPLATE_8_ARG
void signal_8_base<HYDROSIG_8_ARG>::clear()
{
    HYDROSIG_PROTECTED_BLOCK_BEGIN

    m_slots.clear();

    HYDROSIG_PROTECTED_BLOCK_END
}

HYDROSIG_TEMPLATE_8_ARG
typename signal_8_base<HYDROSIG_8_ARG>::connection_type
signal_8_base<HYDROSIG_8_ARG>::connect(
        Return_type(*function)(Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                               Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                               Arg7_type arg7, Arg8_type arg8))
{
    HYDROSIG_SHARED_PTR_TYPE<connection_validator> validator;

    try {
        validator = std::make_shared<connection_validator>();
        HYDROSIG_SHARED_PTR_TYPE<slot_type> newSlot(
                    new slot_type(make_fun(function), validator));

        HYDROSIG_PROTECTED_BLOCK_BEGIN

        m_slots.push_back(newSlot);

        HYDROSIG_PROTECTED_BLOCK_END

        return connection_type(newSlot,this,validator);
    }
    catch(...)
    {
        throw connection_failure();
    }
}

HYDROSIG_TEMPLATE_8_ARG
HYDROSIG_CONNECT_ENABLER_UNTRACKABLE_IMPL_8
signal_8_base<HYDROSIG_8_ARG>::connect(Object_type* object,
                                       Return_type(Object_type::*function)(
                                           Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                                           Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                                           Arg7_type arg7, Arg8_type arg8))
{
    HYDROSIG_SHARED_PTR_TYPE<connection_validator> validator;

    try {
        validator = std::make_shared<connection_validator>();
        HYDROSIG_SHARED_PTR_TYPE<slot_type> newSlot(
                    new slot_type(make_fun(object, function), validator));

        HYDROSIG_PROTECTED_BLOCK_BEGIN

        m_slots.push_back(newSlot);

        HYDROSIG_PROTECTED_BLOCK_END

        return connection_type(newSlot,this,validator);
    }
    catch(...)
    {
        throw connection_failure();
    }
}

HYDROSIG_TEMPLATE_8_ARG
HYDROSIG_CONNECT_ENABLER_TRACKABLE_IMPL_8
signal_8_base<HYDROSIG_8_ARG>::connect(Object_type* object,
                                       Return_type(Object_type::*function)(
                                           Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                                           Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                                           Arg7_type arg7, Arg8_type arg8))
{
    HYDROSIG_SHARED_PTR_TYPE<connection_validator> validator;

    try {
        validator = std::make_shared<connection_validator>();
        HYDROSIG_SHARED_PTR_TYPE<slot_type> newSlot(
                    new slot_type(make_fun(object, function), validator));
        object->addValidator(validator);

        HYDROSIG_PROTECTED_BLOCK_BEGIN

        m_slots.push_back(newSlot);

        HYDROSIG_PROTECTED_BLOCK_END

        return connection_type(newSlot,this,validator);
    }
    catch(...)
    {
        object->removeValidator(validator);
        throw connection_failure();
    }
}

HYDROSIG_TEMPLATE_8_ARG
HYDROSIG_CONNECT_ENABLER_UNTRACKABLE_IMPL_8
signal_8_base<HYDROSIG_8_ARG>::connect(Object_type* object,
                                       Return_type(Object_type::*function)(
                                           Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                                           Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                                           Arg7_type arg7, Arg8_type arg8) const)
{
    HYDROSIG_SHARED_PTR_TYPE<connection_validator> validator;

    try {
        validator = std::make_shared<connection_validator>();
        HYDROSIG_SHARED_PTR_TYPE<slot_type> newSlot(
                    new slot_type(make_fun(object, function), validator));

        HYDROSIG_PROTECTED_BLOCK_BEGIN

        m_slots.push_back(newSlot);

        HYDROSIG_PROTECTED_BLOCK_END

        return connection_type(newSlot,this,validator);
    }
    catch(...)
    {
        throw connection_failure();
    }
}

HYDROSIG_TEMPLATE_8_ARG
HYDROSIG_CONNECT_ENABLER_TRACKABLE_IMPL_8
signal_8_base<HYDROSIG_8_ARG>::connect(Object_type* object,
                                       Return_type(Object_type::*function)(
                                           Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                                           Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                                           Arg7_type arg7, Arg8_type arg8) const)
{
    HYDROSIG_SHARED_PTR_TYPE<connection_validator> validator;

    try {
        validator = std::make_shared<connection_validator>();
        HYDROSIG_SHARED_PTR_TYPE<slot_type> newSlot(
                    new slot_type(make_fun(object, function), validator));
        object->addValidator(validator);

        HYDROSIG_PROTECTED_BLOCK_BEGIN

        m_slots.push_back(newSlot);

        HYDROSIG_PROTECTED_BLOCK_END

        return connection_type(newSlot,this,validator);
    }
    catch(...)
    {
        object->removeValidator(validator);
        throw connection_failure();
    }
}

HYDROSIG_TEMPLATE_8_ARG
HYDROSIG_CONNECT_ENABLER_UNTRACKABLE_IMPL_8
signal_8_base<HYDROSIG_8_ARG>::connect(Object_type* object,
                                       Return_type(Object_type::*function)(
                                           Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                                           Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                                           Arg7_type arg7, Arg8_type arg8) volatile)
{
    HYDROSIG_SHARED_PTR_TYPE<connection_validator> validator;

    try {
        validator = std::make_shared<connection_validator>();
        HYDROSIG_SHARED_PTR_TYPE<slot_type> newSlot(
                    new slot_type(make_fun(object, function), validator));

        HYDROSIG_PROTECTED_BLOCK_BEGIN

        m_slots.push_back(newSlot);

        HYDROSIG_PROTECTED_BLOCK_END

        return connection_type(newSlot,this,validator);
    }
    catch(...)
    {
        throw connection_failure();
    }
}

HYDROSIG_TEMPLATE_8_ARG
HYDROSIG_CONNECT_ENABLER_TRACKABLE_IMPL_8
signal_8_base<HYDROSIG_8_ARG>::connect(Object_type* object,
                                       Return_type(Object_type::*function)(
                                           Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                                           Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                                           Arg7_type arg7, Arg8_type arg8) volatile)
{
    HYDROSIG_SHARED_PTR_TYPE<connection_validator> validator;

    try {
        validator = std::make_shared<connection_validator>();
        HYDROSIG_SHARED_PTR_TYPE<slot_type> newSlot(
                    new slot_type(make_fun(object, function), validator));
        object->addValidator(validator);

        HYDROSIG_PROTECTED_BLOCK_BEGIN

        m_slots.push_back(newSlot);

        HYDROSIG_PROTECTED_BLOCK_END

        return connection_type(newSlot,this,validator);
    }
    catch(...)
    {
        object->removeValidator(validator);
        throw connection_failure();
    }
}

HYDROSIG_TEMPLATE_8_ARG
HYDROSIG_CONNECT_ENABLER_UNTRACKABLE_IMPL_8
signal_8_base<HYDROSIG_8_ARG>::connect(Object_type* object,
                                       Return_type(Object_type::*function)(
                                           Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                                           Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                                           Arg7_type arg7, Arg8_type arg8) const volatile)
{
    HYDROSIG_SHARED_PTR_TYPE<connection_validator> validator;

    try {
        validator = std::make_shared<connection_validator>();
        HYDROSIG_SHARED_PTR_TYPE<slot_type> newSlot(
                    new slot_type(make_fun(object, function), validator));

        HYDROSIG_PROTECTED_BLOCK_BEGIN

        m_slots.push_back(newSlot);

        HYDROSIG_PROTECTED_BLOCK_END

        return connection_type(newSlot,this,validator);
    }
    catch(...)
    {
        throw connection_failure();
    }
}

HYDROSIG_TEMPLATE_8_ARG
HYDROSIG_CONNECT_ENABLER_TRACKABLE_IMPL_8
signal_8_base<HYDROSIG_8_ARG>::connect(Object_type* object,
                                       Return_type(Object_type::*function)(
                                           Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                                           Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                                           Arg7_type arg7, Arg8_type arg8) const volatile)
{
    HYDROSIG_SHARED_PTR_TYPE<connection_validator> validator;

    try {
        validator = std::make_shared<connection_validator>();
        HYDROSIG_SHARED_PTR_TYPE<slot_type> newSlot(
                    new slot_type(make_fun(object, function), validator));
        object->addValidator(validator);

        HYDROSIG_PROTECTED_BLOCK_BEGIN

        m_slots.push_back(newSlot);

        HYDROSIG_PROTECTED_BLOCK_END

        return connection_type(newSlot,this,validator);
    }
    catch(...)
    {
        object->removeValidator(validator);
        throw connection_failure();
    }
}

HYDROSIG_TEMPLATE_8_ARG
template<class Callable_type>
typename signal_8_base<HYDROSIG_8_ARG>::connection_type
signal_8_base<HYDROSIG_8_ARG>::connect(Callable_type callable)
{
    HYDROSIG_SHARED_PTR_TYPE<connection_validator> validator;

    try {
        validator = std::make_shared<connection_validator>();
        HYDROSIG_SHARED_PTR_TYPE<slot_type> newSlot(
                    new slot_type(make_fun<HYDROSIG_CALLABLE_8_ARG>
                    (callable), validator));

        HYDROSIG_PROTECTED_BLOCK_BEGIN

        m_slots.push_back(newSlot);

        HYDROSIG_PROTECTED_BLOCK_END

        return connection_type(newSlot,this,validator);
    }
    catch(...)
    {
        throw connection_failure();
    }
}

HYDROSIG_TEMPLATE_8_ARG
void signal_8_base<HYDROSIG_8_ARG>::disconnect(Return_type(*function)(
                                                   Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                                                   Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                                                   Arg7_type arg7, Arg8_type arg8),
                                               bool disconnectAll)
{
    HYDROSIG_PROTECTED_BLOCK_BEGIN

    typename slot_list::iterator itBegin(m_slots.begin());
    typename slot_list::iterator itEnd(m_slots.end());

    while(itBegin != itEnd)
    {
        // Functor from the callable
        functor_to_free_8<HYDROSIG_8_ARG> supplied(function);

        // Comparing functors
        if(comp_fun(&supplied,(*itBegin)->get_functor()))
        {
            itBegin = m_slots.erase(itBegin);

            if(!disconnectAll)
            {
                return;
            }
        }
        else
        {
            itBegin++;
        }
    }

    HYDROSIG_PROTECTED_BLOCK_END
}

HYDROSIG_TEMPLATE_8_ARG
HYDROSIG_DISCONNECT_ENABLER_UNTRACKABLE
signal_8_base<HYDROSIG_8_ARG>::disconnect(Object_type* object,
                                          Return_type(Object_type::*function)(
                                              Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                                              Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                                              Arg7_type arg7, Arg8_type arg8),
                                          bool disconnectAll)
{
    HYDROSIG_PROTECTED_BLOCK_BEGIN

    typename slot_list::iterator itBegin(m_slots.begin());
    typename slot_list::iterator itEnd(m_slots.end());

    while(itBegin != itEnd)
    {
        // Functor from the callable
        functor_to_member_8<Object_type, HYDROSIG_8_ARG> supplied(object,function);

        // Comparing functors
        if(comp_fun(&supplied,(*itBegin)->get_functor()))
        {
            itBegin = m_slots.erase(itBegin);

            if(!disconnectAll)
            {
                return;
            }
        }
        else
        {
            itBegin++;
        }
    }

    HYDROSIG_PROTECTED_BLOCK_END
}

HYDROSIG_TEMPLATE_8_ARG
HYDROSIG_DISCONNECT_ENABLER_TRACKABLE
signal_8_base<HYDROSIG_8_ARG>::disconnect(Object_type* object,
                                          Return_type(Object_type::*function)(
                                              Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                                              Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                                              Arg7_type arg7, Arg8_type arg8),
                                          bool disconnectAll)
{
    HYDROSIG_PROTECTED_BLOCK_BEGIN

    typename slot_list::iterator itBegin(m_slots.begin());
    typename slot_list::iterator itEnd(m_slots.end());

    while(itBegin != itEnd)
    {
        // Functor from the callable
        functor_to_member_8<Object_type, HYDROSIG_8_ARG> supplied(object,function);

        // Comparing functors
        if(comp_fun(&supplied,(*itBegin)->get_functor()))
        {
            object->removeValidator((*itBegin)->getValidator());
            itBegin = m_slots.erase(itBegin);

            if(!disconnectAll)
            {
                return;
            }
        }
        else
        {
            itBegin++;
        }
    }

    HYDROSIG_PROTECTED_BLOCK_END
}

HYDROSIG_TEMPLATE_8_ARG
HYDROSIG_DISCONNECT_ENABLER_UNTRACKABLE
signal_8_base<HYDROSIG_8_ARG>::disconnect(Object_type* object,
                                          Return_type(Object_type::*function)(
                                              Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                                              Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                                              Arg7_type arg7, Arg8_type arg8) const,
                                          bool disconnectAll)
{
    HYDROSIG_PROTECTED_BLOCK_BEGIN

    typename slot_list::iterator itBegin(m_slots.begin());
    typename slot_list::iterator itEnd(m_slots.end());

    while(itBegin != itEnd)
    {
        // Functor from the callable
        functor_to_member_const_8<Object_type, HYDROSIG_8_ARG> supplied(object,function);

        // Comparing functors
        if(comp_fun(&supplied,(*itBegin)->get_functor()))
        {
            itBegin = m_slots.erase(itBegin);

            if(!disconnectAll)
            {
                return;
            }
        }
        else
        {
            itBegin++;
        }
    }

    HYDROSIG_PROTECTED_BLOCK_END
}

HYDROSIG_TEMPLATE_8_ARG
HYDROSIG_DISCONNECT_ENABLER_TRACKABLE
signal_8_base<HYDROSIG_8_ARG>::disconnect(Object_type* object,
                                          Return_type(Object_type::*function)(
                                              Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                                              Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                                              Arg7_type arg7, Arg8_type arg8) const,
                                          bool disconnectAll)
{
    HYDROSIG_PROTECTED_BLOCK_BEGIN

    typename slot_list::iterator itBegin(m_slots.begin());
    typename slot_list::iterator itEnd(m_slots.end());

    while(itBegin != itEnd)
    {
        // Functor from the callable
        functor_to_member_const_8<Object_type, HYDROSIG_8_ARG> supplied(object,function);

        // Comparing functors
        if(comp_fun(&supplied,(*itBegin)->get_functor()))
        {
            object->removeValidator((*itBegin)->getValidator());
            itBegin = m_slots.erase(itBegin);

            if(!disconnectAll)
            {
                return;
            }
        }
        else
        {
            itBegin++;
        }
    }

    HYDROSIG_PROTECTED_BLOCK_END
}

HYDROSIG_TEMPLATE_8_ARG
HYDROSIG_DISCONNECT_ENABLER_UNTRACKABLE
signal_8_base<HYDROSIG_8_ARG>::disconnect(Object_type* object,
                                          Return_type(Object_type::*function)(
                                              Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                                              Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                                              Arg7_type arg7, Arg8_type arg8) volatile,
                                          bool disconnectAll)
{
    HYDROSIG_PROTECTED_BLOCK_BEGIN

    typename slot_list::iterator itBegin(m_slots.begin());
    typename slot_list::iterator itEnd(m_slots.end());

    while(itBegin != itEnd)
    {
        // Functor from the callable
        functor_to_member_volatile_8<Object_type, HYDROSIG_8_ARG> supplied(object,function);

        // Comparing functors
        if(comp_fun(&supplied,(*itBegin)->get_functor()))
        {
            itBegin = m_slots.erase(itBegin);

            if(!disconnectAll)
            {
                return;
            }
        }
        else
        {
            itBegin++;
        }
    }

    HYDROSIG_PROTECTED_BLOCK_END
}

HYDROSIG_TEMPLATE_8_ARG
HYDROSIG_DISCONNECT_ENABLER_TRACKABLE
signal_8_base<HYDROSIG_8_ARG>::disconnect(Object_type* object,
                                          Return_type(Object_type::*function)(
                                              Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                                              Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                                              Arg7_type arg7, Arg8_type arg8) volatile,
                                          bool disconnectAll)
{
    HYDROSIG_PROTECTED_BLOCK_BEGIN

    typename slot_list::iterator itBegin(m_slots.begin());
    typename slot_list::iterator itEnd(m_slots.end());

    while(itBegin != itEnd)
    {
        // Functor from the callable
        functor_to_member_volatile_8<Object_type, HYDROSIG_8_ARG> supplied(object,function);

        // Comparing functors
        if(comp_fun(&supplied,(*itBegin)->get_functor()))
        {
            object->removeValidator((*itBegin)->getValidator());
            itBegin = m_slots.erase(itBegin);

            if(!disconnectAll)
            {
                return;
            }
        }
        else
        {
            itBegin++;
        }
    }

    HYDROSIG_PROTECTED_BLOCK_END
}

HYDROSIG_TEMPLATE_8_ARG
HYDROSIG_DISCONNECT_ENABLER_UNTRACKABLE
signal_8_base<HYDROSIG_8_ARG>::disconnect(Object_type* object,
                                          Return_type(Object_type::*function)(
                                              Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                                              Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                                              Arg7_type arg7, Arg8_type arg8) const volatile,
                                          bool disconnectAll)
{
    HYDROSIG_PROTECTED_BLOCK_BEGIN

    typename slot_list::iterator itBegin(m_slots.begin());
    typename slot_list::iterator itEnd(m_slots.end());

    while(itBegin != itEnd)
    {
        // Functor from the callable
        functor_to_member_const_volatile_8<Object_type, HYDROSIG_8_ARG> supplied(object,function);

        // Comparing functors
        if(comp_fun(&supplied,(*itBegin)->get_functor()))
        {
            itBegin = m_slots.erase(itBegin);

            if(!disconnectAll)
            {
                return;
            }
        }
        else
        {
            itBegin++;
        }
    }

    HYDROSIG_PROTECTED_BLOCK_END
}

HYDROSIG_TEMPLATE_8_ARG
HYDROSIG_DISCONNECT_ENABLER_TRACKABLE
signal_8_base<HYDROSIG_8_ARG>::disconnect(Object_type* object,
                                          Return_type(Object_type::*function)(
                                              Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                                              Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                                              Arg7_type arg7, Arg8_type arg8) const volatile,
                                          bool disconnectAll)
{
    HYDROSIG_PROTECTED_BLOCK_BEGIN

    typename slot_list::iterator itBegin(m_slots.begin());
    typename slot_list::iterator itEnd(m_slots.end());

    while(itBegin != itEnd)
    {
        // Functor from the callable
        functor_to_member_const_volatile_8<Object_type, HYDROSIG_8_ARG> supplied(object,function);

        // Comparing functors
        if(comp_fun(&supplied,(*itBegin)->get_functor()))
        {
            object->removeValidator((*itBegin)->getValidator());
            itBegin = m_slots.erase(itBegin);

            if(!disconnectAll)
            {
                return;
            }
        }
        else
        {
            itBegin++;
        }
    }

    HYDROSIG_PROTECTED_BLOCK_END
}

HYDROSIG_TEMPLATE_8_ARG
void signal_8_base<HYDROSIG_8_ARG>::disconnect(
        const HYDROSIG_SHARED_PTR_TYPE<slot_type> slot_ptr)
{
    HYDROSIG_PROTECTED_BLOCK_BEGIN

    typename slot_list::iterator itBegin(m_slots.begin());
    typename slot_list::iterator itEnd(m_slots.end());

    while(itBegin != itEnd)
    {
        if(*itBegin == slot_ptr)
        {
            m_slots.erase(itBegin);
            return;
        }
    }

    HYDROSIG_PROTECTED_BLOCK_END
}

HYDROSIG_TEMPLATE_8_ARG
void signal_8_base<HYDROSIG_8_ARG>::removeInvalidated()
{
    HYDROSIG_PROTECTED_BLOCK_BEGIN

    typename slot_list::iterator itBegin(m_slots.begin());
    typename slot_list::iterator itEnd(m_slots.end());

    while(itBegin != itEnd)
    {
        if(!(*itBegin)->isValid())
        {
            itBegin = m_slots.erase(itBegin);
            continue;
        }

        itBegin++;
    }

    HYDROSIG_PROTECTED_BLOCK_END
}

HYDROSIG_TEMPLATE_8_ARG
void signal_8<HYDROSIG_8_ARG>::emit(Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                                    Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                                    Arg7_type arg7, Arg8_type arg8)
{
    if(this->isBlocked()) return;

    this->removeInvalidated();

    HYDROSIG_PROTECTED_BLOCK_BEGIN

    slot_list copy = this->m_slots;
    typename slot_list::iterator itBegin(copy.begin());
    typename slot_list::iterator itEnd(copy.end());

    HYDROSIG_PROTECTED_BLOCK_END

    while(itBegin != itEnd)
    {
        // Skip the slot if blocked or invalid
        if(!(*itBegin)->isValid()
                ||
            (*itBegin)->isBlocked())
        {
            itBegin++;
            continue;
        }

        // Activating the slot
        try {
            (*itBegin)->activate(arg1,arg2,arg3,
                                 arg4,arg5,arg6,
                                 arg7,arg8);
            itBegin++;
        }
        catch(...)
        {
            throw;
        }
    }
}

HYDROSIG_TEMPLATE_8_ARG
void signal_8<HYDROSIG_8_ARG>::emit_reverse(Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                                            Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                                            Arg7_type arg7, Arg8_type arg8)
{
    if(this->isBlocked()) return;

    this->removeInvalidated();

    HYDROSIG_PROTECTED_BLOCK_BEGIN

    slot_list copy = this->m_slots;
    typename slot_list::reverse_iterator itBegin(copy.rbegin());
    typename slot_list::reverse_iterator itEnd(copy.rend());

    HYDROSIG_PROTECTED_BLOCK_END

    while(itBegin != itEnd)
    {
        // Skip the slot if blocked or invalid
        if(!(*itBegin)->isValid()
                ||
            (*itBegin)->isBlocked())
        {
            itBegin++;
            continue;
        }

        // Activating the slot
        try {
            (*itBegin)->activate(arg1,arg2,arg3,
                                 arg4,arg5,arg6,
                                 arg7,arg8);
            itBegin++;
        }
        catch(...)
        {
            throw;
        }
    }
}

HYDROSIG_TEMPLATE_8_ARG
void signal_8<HYDROSIG_8_ARG>::operator()(Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                                          Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
                                          Arg7_type arg7, Arg8_type arg8)
{
    try {
        emit(arg1,arg2,arg3,
             arg4,arg5,arg6,
             arg7,arg8);
    }
    catch(...)
    {
        throw;
    }
}

HYDROSIG_TEMPLATE_8_ARG
HYDROSIG_LIST_TYPE<Return_type> signal_8<HYDROSIG_8_ARG>::collected::emit(
        Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
        Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
        Arg7_type arg7, Arg8_type arg8)
{
    HYDROSIG_LIST_TYPE<Return_type> resultList;

    this->removeInvalidated();
    if(this->isBlocked()) return resultList;

    HYDROSIG_PROTECTED_BLOCK_BEGIN

    slot_list copy = this->m_slots;
    typename slot_list::iterator itBegin(copy.begin());
    typename slot_list::iterator itEnd(copy.end());

    HYDROSIG_PROTECTED_BLOCK_END

    while(itBegin != itEnd)
    {
        // Skip the slot if blocked or invalid
        if(!(*itBegin)->isValid()
                ||
            (*itBegin)->isBlocked())
        {
            itBegin++;
            continue;
        }

        // Activating the slot
        try {
            resultList.push_back((*itBegin)->activate(arg1,arg2,arg3,
                                                      arg4,arg5,arg6,
                                                      arg7,arg8));
            itBegin++;
        }
        catch(...)
        {
            throw;
        }
    }

    return resultList;
}

HYDROSIG_TEMPLATE_8_ARG
HYDROSIG_LIST_TYPE<Return_type> signal_8<HYDROSIG_8_ARG>::collected::emit_reverse(
        Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
        Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
        Arg7_type arg7, Arg8_type arg8)
{
    HYDROSIG_LIST_TYPE<Return_type> resultList;

    this->removeInvalidated();
    if(this->isBlocked()) return resultList;

    HYDROSIG_PROTECTED_BLOCK_BEGIN

    slot_list copy = this->m_slots;
    typename slot_list::reverse_iterator itBegin(copy.rbegin());
    typename slot_list::reverse_iterator itEnd(copy.rend());

    HYDROSIG_PROTECTED_BLOCK_END

    while(itBegin != itEnd)
    {
        // Skip the slot if blocked or invalid
        if(!(*itBegin)->isValid()
                ||
            (*itBegin)->isBlocked())
        {
            itBegin++;
            continue;
        }

        // Activating the slot
        try {
            resultList.push_back((*itBegin)->activate(arg1,arg2,arg3,
                                                      arg4,arg5,arg6,
                                                      arg7,arg8));
            itBegin++;
        }
        catch(...)
        {
            throw;
        }
    }

    return resultList;
}

HYDROSIG_TEMPLATE_8_ARG
HYDROSIG_LIST_TYPE<Return_type> signal_8<HYDROSIG_8_ARG>::collected::operator()(
        Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
        Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
        Arg7_type arg7, Arg8_type arg8)
{
    try {
        return emit(arg1,arg2,arg3,
                    arg4,arg5,arg6,
                    arg7,arg8);
    }
    catch(...)
    {
        throw;
    }
}

HYDROSIG_TEMPLATE_8_ARG
template<class Combiner_type>
signal_8<HYDROSIG_8_ARG>::combined<Combiner_type>::combined()
    : m_combiner(new Combiner_type())
{
    ;
}

HYDROSIG_TEMPLATE_8_ARG
template<class Combiner_type>
signal_8<HYDROSIG_8_ARG>::combined<Combiner_type>::combined(
        const Combiner_type &combiner)
    : m_combiner(new Combiner_type(combiner))
{
    ;
}

HYDROSIG_TEMPLATE_8_ARG
template<class Combiner_type>
signal_8<HYDROSIG_8_ARG>::combined<Combiner_type>::combined(
        const combined &src)
    : signal_8_base<HYDROSIG_8_ARG>(src)
{
    HYDROSIG_REMOTE_PROTECTED_BLOCK_BEGIN

    m_combiner = HYDROSIG_SHARED_PTR_TYPE<Combiner_type>(
                 new Combiner_type(*(src.m_combiner)));

    HYDROSIG_REMOTE_PROTECTED_BLOCK_END
}

HYDROSIG_TEMPLATE_8_ARG
template<class Combiner_type>
signal_8<HYDROSIG_8_ARG>::combined<Combiner_type>::combined(
        combined &&src)
    : signal_8_base<HYDROSIG_8_ARG>(
          std::forward<signal_8_base<HYDROSIG_8_ARG>>(src))
{
    HYDROSIG_REMOTE_PROTECTED_BLOCK_BEGIN

    m_combiner = std::move(src.m_combiner);

    HYDROSIG_REMOTE_PROTECTED_BLOCK_END
}

HYDROSIG_TEMPLATE_8_ARG
template<class Combiner_type>
signal_8<HYDROSIG_8_ARG>::combined<Combiner_type>&
signal_8<HYDROSIG_8_ARG>::combined<Combiner_type>::operator=(
        const combined &src)
{
    if(this == &src) return *this;

    signal_8_base<HYDROSIG_8_ARG>::operator =(src);

    HYDROSIG_REMOTE_PROTECTED_BLOCK_BEGIN
    HYDROSIG_PROTECTED_BLOCK_BEGIN

    m_combiner = HYDROSIG_SHARED_PTR_TYPE<Combiner_type>(
                 new Combiner_type(*(src.m_combiner)));

    HYDROSIG_PROTECTED_BLOCK_END
    HYDROSIG_REMOTE_PROTECTED_BLOCK_END

    return *this;
}

HYDROSIG_TEMPLATE_8_ARG
template<class Combiner_type>
signal_8<HYDROSIG_8_ARG>::combined<Combiner_type>&
signal_8<HYDROSIG_8_ARG>::combined<Combiner_type>::operator=(
        combined &&src)
{
    if(this == &src) return *this;

    signal_8_base<HYDROSIG_8_ARG>::operator =(
                std::forward<signal_8_base<HYDROSIG_8_ARG>>(src));

    HYDROSIG_REMOTE_PROTECTED_BLOCK_BEGIN
    HYDROSIG_PROTECTED_BLOCK_BEGIN

    m_combiner = std::move(src.m_combiner);

    HYDROSIG_PROTECTED_BLOCK_END
    HYDROSIG_REMOTE_PROTECTED_BLOCK_END

    return *this;
}

HYDROSIG_TEMPLATE_8_ARG
template<class Combiner_type>
Combiner_type& signal_8<HYDROSIG_8_ARG>::combined<Combiner_type>::getCombiner()
{
    return *m_combiner;
}

HYDROSIG_TEMPLATE_8_ARG
template<class Combiner_type>
void signal_8<HYDROSIG_8_ARG>::combined<Combiner_type>::setCombiner(
        const Combiner_type &combiner)
{
    HYDROSIG_PROTECTED_BLOCK_BEGIN

    m_combiner = HYDROSIG_SHARED_PTR_TYPE<Combiner_type>(combiner);

    HYDROSIG_PROTECTED_BLOCK_END
}

HYDROSIG_TEMPLATE_8_ARG
template<class Combiner_type>
Return_type signal_8<HYDROSIG_8_ARG>::combined<Combiner_type>::emit(
        Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
        Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
        Arg7_type arg7, Arg8_type arg8)
{
    if(this->isBlocked()) return m_combiner->value();

    this->removeInvalidated();

    HYDROSIG_PROTECTED_BLOCK_BEGIN

    HYDROSIG_SHARED_PTR_TYPE<Combiner_type> combiner(m_combiner);
    slot_list copy = this->m_slots;
    typename slot_list::iterator itBegin(copy.begin());
    typename slot_list::iterator itEnd(copy.end());

    HYDROSIG_PROTECTED_BLOCK_END

    while(itBegin != itEnd)
    {
        // Skip the slot if blocked or invalid
        if(!(*itBegin)->isValid()
                ||
            (*itBegin)->isBlocked())
        {
            itBegin++;
            continue;
        }

        // Activating the slot
        try {
            (*combiner)((*itBegin)->activate(arg1,arg2,arg3,
                                             arg4,arg5,arg6,
                                             arg7,arg8));
            itBegin++;
        }
        catch(...)
        {
            throw;
        }
    }

    return combiner->value();
}

HYDROSIG_TEMPLATE_8_ARG
template<class Combiner_type>
Return_type signal_8<HYDROSIG_8_ARG>::combined<Combiner_type>::emit_reverse(
        Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
        Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
        Arg7_type arg7, Arg8_type arg8)
{
    if(this->isBlocked()) return m_combiner->value();

    this->removeInvalidated();

    HYDROSIG_PROTECTED_BLOCK_BEGIN

    HYDROSIG_SHARED_PTR_TYPE<Combiner_type> combiner(m_combiner);
    slot_list copy = this->m_slots;
    typename slot_list::reverse_iterator itBegin(copy.rbegin());
    typename slot_list::reverse_iterator itEnd(copy.rend());

    HYDROSIG_PROTECTED_BLOCK_END

    while(itBegin != itEnd)
    {
        // Skip the slot if blocked or invalid
        if(!(*itBegin)->isValid()
                ||
            (*itBegin)->isBlocked())
        {
            itBegin++;
            continue;
        }

        // Activating the slot
        try {
            (*combiner)((*itBegin)->activate(arg1,arg2,arg3,
                                             arg4,arg5,arg6,
                                             arg7,arg8));
            itBegin++;
        }
        catch(...)
        {
            throw;
        }
    }

    return combiner->value();
}

HYDROSIG_TEMPLATE_8_ARG
template<class Combiner_type>
Return_type signal_8<HYDROSIG_8_ARG>::combined<Combiner_type>::operator()(
        Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
        Arg4_type arg4, Arg5_type arg5, Arg6_type arg6,
        Arg7_type arg7, Arg8_type arg8)
{
    try {
        return emit(arg1,arg2,arg3,
                    arg4,arg5,arg6,
                    arg7,arg8);
    }
    catch(...)
    {
        throw;
    }
}


HYDROSIG_NAMESPACE_END


#endif // HYDROSIG_SIGNAL_8_HPP_INCLUDED
