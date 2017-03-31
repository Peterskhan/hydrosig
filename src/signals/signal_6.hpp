#pragma once
#ifndef HYDROSIG_SIGNAL_6_HPP_INCLUDED
#define HYDROSIG_SIGNAL_6_HPP_INCLUDED

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

/*****************************************/
#ifdef HYDROSIG_HYDROSIG_USE_HYDROGEN_CONTAINERS
#include "../HContainers/HList/HList.h"

#else
#include <list>

#endif // HYDROSIG_USE_HYDROGEN_CONTAINERS
/*****************************************/

#include <type_traits>
#include "signal_base/signal_base.h"
#include "make_funs/make_fun_6.h"
#include "slots/slot_6.hpp"
#include "connections/connection_6.hpp"
#include "macros.h"


HYDROSIG_NAMESPACE_BEGIN


template<class Return_type, class Arg1_type, class Arg2_type,
         class Arg3_type, class Arg4_type, class Arg5_type,
         class Arg6_type>
/**
 * @brief   This class represents a signal object, which
 *          expects six arguments for the connected slots.
 */
class signal_6 : public signal_base
{
protected:
    /**< Typedef for the slot type */
    typedef slot_6<Return_type, Arg1_type, Arg2_type,
                   Arg3_type, Arg4_type, Arg5_type,
                   Arg6_type>
    slot_type;

    /**< Typedef for the connection type */
    typedef connection_6<Return_type,
                         Arg1_type, Arg2_type, Arg3_type,
                         Arg4_type, Arg5_type, Arg6_type>
    connection_type;

    /**< Typedef for the list of slots */
    #ifdef HYDROSIG_USE_HYDROGEN_CONTAINERS
    typedef HList<slot_type*> slot_list;
    #else
    /**< Typedef for the list of slots */
    typedef std::list<slot_type*> slot_list;
    #endif

public:
    /**
     * @brief   Constructs a signal_6 object.
     */
    signal_6()
        : signal_base()
    {
        ;
    }

    /**
     * @brief   Constructs a signal_6 object by copying src.
     * @details Signals with connected slots are not meant
     *          to be copied, and should be only done so when
     *          the object encapsulating it is being copied.
     *          Established connections are not copied into the
     *          new object, and it is set into the default state.
     * @param   src The signal object to copy.
     */
    signal_6(const signal_6& src)
        : signal_base()
    {
        // Do not copy the list of slots
    }

    /**
     * @brief   Constructs a signal_6 by moving src.
     * @details In the moving process src loses all of
     *          it's connections, they are transferred
     *          to this signal and the slot's callbacks
     *          are relinked. The state of the constructed
     *          signal is matching the state of src before
     *          the move construction.
     * @param   src The signal to move.
     */
    signal_6(signal_6&& src)
    {
        #ifdef HYDROSIG_USE_THREAD_SYNCHRONISATION
        #ifdef HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
        HMutexLocker src_guard(src.m_mutex);
        HMutexLocker guard(m_mutex);

        #else
        std::lock_guard<std::recursive_mutex> src_guard(src.m_mutex);
        std::lock_guard<std::recursive_mutex> guard(m_mutex);

        #endif // HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
        #endif // HYDROSIG_USE_THREAD_SYNCHRONISATION

        m_blocked = src.isBlocked();

        typename slot_list::iterator itBegin(src.m_slots.begin());
        typename slot_list::iterator itEnd(src.m_slots.end());

        while(itBegin != itEnd)
        {
            // Relink the slot with this signal, and
            // remove it's callbacks to the signal
            // moved from.
            (*itBegin)->remove_destroy_notify_callback(&src);
            (*itBegin)->add_destroy_notify_callback(this,
                                                    static_cast<void(notifyable::*)(notifyable*)>
                                                   (signal_6<Return_type,
                                                             Arg1_type,Arg2_type,Arg3_type,
                                                             Arg4_type,Arg5_type,Arg6_type>::on_destruction_notification));

            m_slots.push_back(*itBegin);
            itBegin++;
        }
        src.m_slots.clear();
    }

    /**
     * @brief   Copy assigns src to this signal.
     * @details Signals with connected slots are not meant
     *          to be copied, and should be only done so when
     *          the object encapsulating it is being copied.
     *          Established connections are not copied into the
     *          new object, and it is set into the default state.
     * @param   src The signal object to copy.
     */
    signal_6& operator=(const signal_6& /*src*/)
    {
        // Do not copy the list of slots

        m_blocked = false;

        return *this;
    }

    /**
     * @brief   Move assigns src to this signal.
     * @details In the moving process src loses all of
     *          it's connections, they are transferred
     *          to this signal and the slot's callbacks
     *          are relinked. The state of this signal
     *          is matching the state of src before the
     *          move assignment.
     * @param   src The signal to move.
     */
    signal_6& operator=(signal_6&& src)
    {
        if(this == &src) return *this;

        #ifdef HYDROSIG_USE_THREAD_SYNCHRONISATION
        #ifdef HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
        HMutexLocker src_guard(src.m_mutex);
        HMutexLocker guard(m_mutex);

        #else
        std::lock_guard<std::recursive_mutex> src_guard(src.m_mutex);
        std::lock_guard<std::recursive_mutex> guard(m_mutex);

        #endif // HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
        #endif // HYDROSIG_USE_THREAD_SYNCHRONISATION

        m_blocked = src.isBlocked();

        typename slot_list::iterator itBegin(src.m_slots.begin());
        typename slot_list::iterator itEnd(src.m_slots.end());

        while(itBegin != itEnd)
        {
            // Relink the slot with this signal, and
            // remove it's callbacks to the signal
            // moved from.
            (*itBegin)->remove_destroy_notify_callback(&src);
            (*itBegin)->add_destroy_notify_callback(this,
                                                    static_cast<void(notifyable::*)(notifyable*)>
                                                   (signal_6<Return_type,
                                                             Arg1_type,Arg2_type,Arg3_type,
                                                             Arg4_type,Arg5_type,Arg6_type>::on_destruction_notification));

            m_slots.push_back(*itBegin);
            itBegin++;
        }
        src.m_slots.clear();

        return *this;
    }

    /**
     * @brief   Returns the number of connected slots.
     * @return  The number of connected slots.
     */
    unsigned int size() const
    {
        return m_slots.size();
    }

    /**
     * @brief   Returns whether no slots are connected
     *          to the signal.
     * @return  True if there are no slots connected.
     */
    bool empty() const
    {
        return m_slots.empty();
    }

    /**
     * @brief   Removes all slots connected to the signal.
     */
    void clear()
    {
        #ifdef HYDROSIG_USE_THREAD_SYNCHRONISATION
        #ifdef HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
        HMutexLocker guard(m_mutex);

        #else
        std::lock_guard<std::recursive_mutex> guard(m_mutex);

        #endif // HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
        #endif // HYDROSIG_USE_THREAD_SYNCHRONISATION

        typename slot_list::iterator itBegin(m_slots.begin());
        typename slot_list::iterator itEnd(m_slots.end());

        while(itBegin != itEnd)
        {
            (*itBegin)->remove_destroy_notify_callback(this);
            delete (*itBegin);

            itBegin++;
        }
        m_slots.clear();
    }

    /**
     * @brief   Connects a free function to the signal.
     * @param   function Pointer to the free function.
     */
    connection_type connect(Return_type(*function)(Arg1_type, Arg2_type, Arg3_type,
                                        Arg4_type, Arg5_type, Arg6_type))
    {
        slot_6<Return_type, Arg1_type, Arg2_type,
               Arg3_type, Arg4_type, Arg5_type,
               Arg6_type>*
        newSlot;

        try {
            newSlot = new slot_6<Return_type, Arg1_type, Arg2_type,
                                 Arg3_type, Arg4_type, Arg5_type,
                                 Arg6_type>
                      (make_fun(function));
        }
        catch(...)
        {
            throw connection_failure();
        }

        try {
            #ifdef HYDROSIG_USE_THREAD_SYNCHRONISATION
            #ifdef HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
            HMutexLocker guard(m_mutex);

            #else
            std::lock_guard<std::recursive_mutex> guard(m_mutex);

            #endif // HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
            #endif // HYDROSIG_USE_THREAD_SYNCHRONISATION

            m_slots.push_back(newSlot);
        }
        catch(...)
        {
            delete newSlot;
            throw connection_failure();
        }

        return connection_type(newSlot);
    }

    template<class Object_type>
    /**
     * @brief   Connects an object and it's member function
     *          (with no specifiers) to the signal.
     * @details This version is used for untrackable objects.
     * @param   object Pointer to the object.
     * @param   function Pointer to the member function.
     */
    typename std::enable_if<!std::is_base_of<trackable,Object_type>::value, connection_type>::type
    connect(Object_type* object, Return_type(Object_type::*function)(Arg1_type, Arg2_type, Arg3_type,
                                                                     Arg4_type, Arg5_type, Arg6_type))
    {
        slot_6<Return_type, Arg1_type, Arg2_type,
               Arg3_type, Arg4_type, Arg5_type,
               Arg6_type>*
        newSlot;

        try {
            newSlot = new slot_6<Return_type, Arg1_type, Arg2_type,
                                 Arg3_type, Arg4_type, Arg5_type,
                                 Arg6_type>
                      (make_fun(object, function));
        }
        catch(...)
        {
            throw connection_failure();
        }

        try {
            #ifdef HYDROSIG_USE_THREAD_SYNCHRONISATION
            #ifdef HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
            HMutexLocker guard(m_mutex);

            #else
            std::lock_guard<std::recursive_mutex> guard(m_mutex);

            #endif // HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
            #endif // HYDROSIG_USE_THREAD_SYNCHRONISATION

            m_slots.push_back(newSlot);
        }
        catch(...)
        {
            delete newSlot;
            throw connection_failure();
        }

        return connection_type(newSlot);
    }

    template<class Object_type>
    /**
     * @brief   Connects an object and it's member function
     *          (with no specifiers) to the signal.
     * @details This version is used for trackable objects.
     * @param   object Pointer to the object.
     * @param   function Pointer to the member function.
     */
    typename std::enable_if<std::is_base_of<trackable,Object_type>::value, connection_type>::type
    connect(Object_type* object, Return_type(Object_type::*function)(Arg1_type, Arg2_type, Arg3_type,
                                                                     Arg4_type, Arg5_type, Arg6_type))
    {
        slot_6<Return_type, Arg1_type, Arg2_type,
               Arg3_type, Arg4_type, Arg5_type,
               Arg6_type>*
        newSlot;

        try {
            newSlot = new slot_6<Return_type, Arg1_type, Arg2_type,
                                 Arg3_type, Arg4_type, Arg5_type,
                                 Arg6_type>
                      (make_fun(object, function));
        }
        catch(...)
        {
            throw connection_failure();
        }

        try {
            // Object notifies the slot
            object->add_destroy_notify_callback(newSlot,
                                                static_cast<void(notifyable::*)(notifyable*)>
                                               (slot_6<Return_type, Arg1_type, Arg2_type,
                                                       Arg3_type, Arg4_type, Arg5_type,
                                                       Arg6_type>::on_destruction_notification));

            // Slot notifies the object
            newSlot->add_destroy_notify_callback(object,
                                                 static_cast<void(notifyable::*)(notifyable*)>
                                                 (Object_type::on_destruction_notification));

            // Slot notifies the holding signal
            newSlot->add_destroy_notify_callback(this,
                                                 static_cast<void(notifyable::*)(notifyable*)>
                                                 (signal_6<Return_type, Arg1_type, Arg2_type,
                                                           Arg3_type, Arg4_type, Arg5_type,
                                                           Arg6_type>::on_destruction_notification));

            #ifdef HYDROSIG_USE_THREAD_SYNCHRONISATION
            #ifdef HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
            HMutexLocker guard(m_mutex);

            #else
            std::lock_guard<std::recursive_mutex> guard(m_mutex);

            #endif // HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
            #endif // HYDROSIG_USE_THREAD_SYNCHRONISATION

            m_slots.push_back(newSlot);
        }
        catch(...)
        {
            newSlot->remove_destroy_notify_callback(this);
            delete newSlot;
            throw connection_failure();
        }

        return connection_type(newSlot);
    }

    /**
     * @brief   Connects an object and it's member function
     *          (with const specifier) to the signal.
     * @details This version is used for untrackable objects.
     * @param   object Pointer to the object.
     * @param   function Pointer to the member function.
     */
    template<class Object_type>
    typename std::enable_if<!std::is_base_of<trackable,Object_type>::value, connection_type>::type
    connect(Object_type* object, Return_type(Object_type::*function)(Arg1_type, Arg2_type, Arg3_type,
                                                                     Arg4_type, Arg5_type, Arg6_type) const)
    {
        slot_6<Return_type, Arg1_type, Arg2_type,
               Arg3_type, Arg4_type, Arg5_type,
               Arg6_type>*
        newSlot;

        try {
            newSlot = new slot_6<Return_type, Arg1_type, Arg2_type,
                                 Arg3_type, Arg4_type, Arg5_type,
                                 Arg6_type>
                      (make_fun(object, function));
        }
        catch(...)
        {
            throw connection_failure();
        }

        try {
            #ifdef HYDROSIG_USE_THREAD_SYNCHRONISATION
            #ifdef HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
            HMutexLocker guard(m_mutex);

            #else
            std::lock_guard<std::recursive_mutex> guard(m_mutex);

            #endif // HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
            #endif // HYDROSIG_USE_THREAD_SYNCHRONISATION

            m_slots.push_back(newSlot);
        }
        catch(...)
        {
            delete newSlot;
            throw connection_failure();
        }

        return connection_type(newSlot);
    }

    /**
     * @brief   Connects an object and it's member function
     *          (with const specifier) to the signal.
     * @details This version is used for trackable objects.
     * @param   object Pointer to the object.
     * @param   function Pointer to the member function.
     */
    template<class Object_type>
    typename std::enable_if<std::is_base_of<trackable,Object_type>::value, connection_type>::type
    connect(Object_type* object, Return_type(Object_type::*function)(Arg1_type, Arg2_type, Arg3_type,
                                                                     Arg4_type, Arg5_type, Arg6_type) const)
    {
        slot_6<Return_type, Arg1_type, Arg2_type,
               Arg3_type, Arg4_type, Arg5_type,
               Arg6_type>*
        newSlot;

        try {
            newSlot = new slot_6<Return_type, Arg1_type, Arg2_type,
                                 Arg3_type, Arg4_type, Arg5_type,
                                 Arg6_type>
                      (make_fun(object, function));
        }
        catch(...)
        {
            throw connection_failure();
        }

        try {
            // Object notifies the slot
            object->add_destroy_notify_callback(newSlot,
                                                static_cast<void(notifyable::*)(notifyable*)>
                                                (slot_6<Return_type, Arg1_type, Arg2_type,
                                                        Arg3_type, Arg4_type, Arg5_type,
                                                        Arg6_type>::on_destruction_notification));

            // Slot notifies the object
            newSlot->add_destroy_notify_callback(object,
                                                 static_cast<void(notifyable::*)(notifyable*)>
                                                 (Object_type::on_destruction_notification));

            // Slot notifies the holding signal
            newSlot->add_destroy_notify_callback(this,
                                                 static_cast<void(notifyable::*)(notifyable*)>
                                                 (signal_6<Return_type, Arg1_type, Arg2_type,
                                                           Arg3_type, Arg4_type, Arg5_type,
                                                           Arg6_type>::on_destruction_notification));

            #ifdef HYDROSIG_USE_THREAD_SYNCHRONISATION
            #ifdef HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
            HMutexLocker guard(m_mutex);

            #else
            std::lock_guard<std::recursive_mutex> guard(m_mutex);

            #endif // HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
            #endif // HYDROSIG_USE_THREAD_SYNCHRONISATION

            m_slots.push_back(newSlot);
        }
        catch(...)
        {
            newSlot->remove_destroy_notify_callback(this);
            delete newSlot;
            throw connection_failure();
        }

        return connection_type(newSlot);
    }

    /**
     * @brief   Connects an object and it's member function
     *          (with volatile specifier) to the signal.
     * @details This version is used for untrackable objects.
     * @param   object Pointer to the object.
     * @param   function Pointer to the member function.
     */
    template<class Object_type>
    typename std::enable_if<!std::is_base_of<trackable,Object_type>::value, connection_type>::type
    connect(Object_type* object, Return_type(Object_type::*function)(Arg1_type, Arg2_type, Arg3_type,
                                                                     Arg4_type, Arg5_type, Arg6_type) volatile)
    {
        slot_6<Return_type, Arg1_type, Arg2_type,
               Arg3_type, Arg4_type, Arg5_type,
               Arg6_type>*
        newSlot;

        try {
            newSlot = new slot_6<Return_type, Arg1_type, Arg2_type,
                                 Arg3_type, Arg4_type, Arg5_type,
                                 Arg6_type>
                      (make_fun(object, function));
        }
        catch(...)
        {
            throw connection_failure();
        }

        try {
            #ifdef HYDROSIG_USE_THREAD_SYNCHRONISATION
            #ifdef HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
            HMutexLocker guard(m_mutex);

            #else
            std::lock_guard<std::recursive_mutex> guard(m_mutex);

            #endif // HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
            #endif // HYDROSIG_USE_THREAD_SYNCHRONISATION

            m_slots.push_back(newSlot);
        }
        catch(...)
        {
            delete newSlot;
            throw connection_failure();
        }

        return connection_type(newSlot);
    }

    /**
     * @brief   Connects an object and it's member function
     *          (with volatile specifier) to the signal.
     * @details This version is used for trackable objects.
     * @param   object Pointer to the object.
     * @param   function Pointer to the member function.
     */
    template<class Object_type>
    typename std::enable_if<std::is_base_of<trackable,Object_type>::value, connection_type>::type
    connect(Object_type* object, Return_type(Object_type::*function)(Arg1_type, Arg2_type, Arg3_type,
                                                                     Arg4_type, Arg5_type, Arg6_type) volatile)
    {
        slot_6<Return_type, Arg1_type, Arg2_type,
               Arg3_type, Arg4_type, Arg5_type,
               Arg6_type>*
        newSlot;

        try {
            newSlot = new slot_6<Return_type, Arg1_type, Arg2_type,
                                 Arg3_type, Arg4_type, Arg5_type,
                                 Arg6_type>
                      (make_fun(object, function));
        }
        catch(...)
        {
            throw connection_failure();
        }

        try {
            // Object notifies the slot
            object->add_destroy_notify_callback(newSlot,
                                                static_cast<void(notifyable::*)(notifyable*)>
                                                (slot_6<Return_type, Arg1_type, Arg2_type,
                                                        Arg3_type, Arg4_type, Arg5_type,
                                                        Arg6_type>::on_destruction_notification));

            // Slot notifies the object
            newSlot->add_destroy_notify_callback(object,
                                                 static_cast<void(notifyable::*)(notifyable*)>
                                                 (Object_type::on_destruction_notification));

            // Slot notifies the holding signal
            newSlot->add_destroy_notify_callback(this,
                                                 static_cast<void(notifyable::*)(notifyable*)>
                                                 (signal_6<Return_type, Arg1_type, Arg2_type,
                                                           Arg3_type, Arg4_type, Arg5_type,
                                                           Arg6_type>::on_destruction_notification));

            #ifdef HYDROSIG_USE_THREAD_SYNCHRONISATION
            #ifdef HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
            HMutexLocker guard(m_mutex);

            #else
            std::lock_guard<std::recursive_mutex> guard(m_mutex);

            #endif // HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
            #endif // HYDROSIG_USE_THREAD_SYNCHRONISATION

            m_slots.push_back(newSlot);
        }
        catch(...)
        {
            newSlot->remove_destroy_notify_callback(this);
            delete newSlot;
            throw connection_failure();
        }

        return connection_type(newSlot);
    }

    /**
     * @brief   Connects an object and it's member function
     *          (with const volatile specifiers) to the signal.
     * @details This version is used for untrackable objects.
     * @param   object Pointer to the object.
     * @param   function Pointer to the member function.
     */
    template<class Object_type>
    typename std::enable_if<!std::is_base_of<trackable,Object_type>::value, connection_type>::type
    connect(Object_type* object, Return_type(Object_type::*function)(Arg1_type, Arg2_type, Arg3_type,
                                                                     Arg4_type, Arg5_type, Arg6_type) const volatile)
    {
        slot_6<Return_type, Arg1_type, Arg2_type,
               Arg3_type, Arg4_type, Arg5_type,
               Arg6_type>*
        newSlot;

        try {
            newSlot = new slot_6<Return_type, Arg1_type, Arg2_type,
                                 Arg3_type, Arg4_type, Arg5_type,
                                 Arg6_type>
                      (make_fun(object, function));
        }
        catch(...)
        {
            throw connection_failure();
        }

        try {
            #ifdef HYDROSIG_USE_THREAD_SYNCHRONISATION
            #ifdef HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
            HMutexLocker guard(m_mutex);

            #else
            std::lock_guard<std::recursive_mutex> guard(m_mutex);

            #endif // HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
            #endif // HYDROSIG_USE_THREAD_SYNCHRONISATION

            m_slots.push_back(newSlot);
        }
        catch(...)
        {
            delete newSlot;
            throw connection_failure();
        }

        return connection_type(newSlot);
    }

    /**
     * @brief   Connects an object and it's member function
     *          (with const volatile specifiers) to the signal.
     * @details This version is used for trackable objects.
     * @param   object Pointer to the object.
     * @param   function Pointer to the member function.
     */
    template<class Object_type>
    typename std::enable_if<std::is_base_of<trackable,Object_type>::value, connection_type>::type
    connect(Object_type* object, Return_type(Object_type::*function)(Arg1_type, Arg2_type, Arg3_type,
                                                                     Arg4_type, Arg5_type, Arg6_type) const volatile)
    {
        slot_6<Return_type, Arg1_type, Arg2_type,
               Arg3_type, Arg4_type, Arg5_type,
               Arg6_type>*
        newSlot;

        try {
            newSlot = new slot_6<Return_type, Arg1_type, Arg2_type,
                                 Arg3_type, Arg4_type, Arg5_type,
                                 Arg6_type>
                      (make_fun(object, function));
        }
        catch(...)
        {
            throw connection_failure();
        }

        try {
            // Object notifies the slot
            object->add_destroy_notify_callback(newSlot,
                                                static_cast<void(notifyable::*)(notifyable*)>
                                                (slot_6<Return_type, Arg1_type, Arg2_type,
                                                        Arg3_type, Arg4_type, Arg5_type,
                                                        Arg6_type>::on_destruction_notification));

            // Slot notifies the object
            newSlot->add_destroy_notify_callback(object,
                                                 static_cast<void(notifyable::*)(notifyable*)>
                                                 (Object_type::on_destruction_notification));

            // Slot notifies the holding signal
            newSlot->add_destroy_notify_callback(this,
                                                 static_cast<void(notifyable::*)(notifyable*)>
                                                 (signal_6<Return_type, Arg1_type, Arg2_type,
                                                           Arg3_type, Arg4_type, Arg5_type,
                                                           Arg6_type>::on_destruction_notification));

            #ifdef HYDROSIG_USE_THREAD_SYNCHRONISATION
            #ifdef HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
            HMutexLocker guard(m_mutex);

            #else
            std::lock_guard<std::recursive_mutex> guard(m_mutex);

            #endif // HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
            #endif // HYDROSIG_USE_THREAD_SYNCHRONISATION

            m_slots.push_back(newSlot);
        }
        catch(...)
        {
            newSlot->remove_destroy_notify_callback(this);
            delete newSlot;
            throw connection_failure();
        }

        return connection_type(newSlot);
    }

    template<class Callable_type>
    /**
     * @brief   Connects a callable object to the signal.
     * @param   callable The callable object.
     */
    connection_type connect(Callable_type callable)
    {
        slot_6<Return_type,Arg1_type,Arg2_type,
               Arg3_type,Arg4_type,Arg5_type,
               Arg6_type>*
        newSlot;

        try {
            newSlot = new slot_6<Return_type,Arg1_type,Arg2_type,
                                 Arg3_type,Arg4_type,Arg5_type,
                                 Arg6_type>
                      (make_fun<Callable_type,Return_type,Arg1_type,
                                         Arg2_type,Arg3_type,Arg4_type,
                                         Arg5_type,Arg6_type>
                      (callable));
        }
        catch(...)
        {
           throw connection_failure();
        }

        try {
            #ifdef HYDROSIG_USE_THREAD_SYNCHRONISATION
            #ifdef HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
            HMutexLocker guard(m_mutex);

            #else
            std::lock_guard<std::recursive_mutex> guard(m_mutex);

            #endif // HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
            #endif // HYDROSIG_USE_THREAD_SYNCHRONISATION

            m_slots.push_back(newSlot);
        }
        catch(...)
        {
            delete newSlot;
            throw connection_failure();
        }

        return connection_type(newSlot);
    }

    /**
     * @brief   Disconnects a free function indicated by
     *          a pointer to it.
     * @param   function Pointer to the free function.
     */
    void disconnect(Return_type(*function)(Arg1_type, Arg2_type, Arg3_type,
                                           Arg4_type, Arg5_type, Arg6_type))
    {
        // Creating temporary functor from the given function to compare equality with
        functor_to_free_6<Return_type, Arg1_type, Arg2_type,
                          Arg3_type, Arg4_type, Arg5_type,
                          Arg6_type> tmp(function);

        #ifdef HYDROSIG_USE_THREAD_SYNCHRONISATION
        #ifdef HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
        HMutexLocker guard(m_mutex);

        #else
        std::lock_guard<std::recursive_mutex> guard(m_mutex);

        #endif // HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
        #endif // HYDROSIG_USE_THREAD_SYNCHRONISATION

        typename slot_list::iterator itBegin(m_slots.begin());
        typename slot_list::iterator itEnd(m_slots.end());

        while(itBegin != itEnd)
        {
            // Attempting to downcast the slot's functor to the type of the temporary functor
            functor_6_base<Return_type, Arg1_type, Arg2_type,
                      Arg3_type, Arg4_type, Arg5_type,
                      Arg6_type>* original =
            (*itBegin)->get_functor();

            functor_to_free_6<Return_type, Arg1_type, Arg2_type,
                              Arg3_type, Arg4_type, Arg5_type,
                              Arg6_type>* downcasted =
            dynamic_cast<functor_to_free_6<Return_type, Arg1_type, Arg2_type,
                                           Arg3_type, Arg4_type, Arg5_type,
                                           Arg6_type>*>
            (original);

            // If downcasting fails, skip to the next
            if(downcasted == nullptr)
            {
                itBegin++;
                continue;
            }
            // If downcasting succeeds, remove the slot
            else if(tmp == (*downcasted))
            {
                // Removing notification callback from the signal
                // to the slot. This is necessary, because upon
                // destruction the slot would notify the signal
                // again, causing an infinite loop
                (*itBegin)->remove_destroy_notify_callback(this);
                delete (*itBegin);

                // Removing the slot from the list
                m_slots.erase(itBegin);
                return;
            }

            itBegin++;
        }
    }

    template<class Object_type>
    /**
     * @brief   Disconnects a member function with no
     *          specifiers of the given object.
     * @param   object Pointer to the object.
     * @param   function Pointer to the member function.
     */
    void disconnect(Object_type* object, Return_type(Object_type::*function)(Arg1_type, Arg2_type, Arg3_type,
                                                                             Arg4_type, Arg5_type, Arg6_type))
    {
        // Creating temporary functor from the given function to compare equality with
        functor_to_member_6<Object_type, Return_type, Arg1_type, Arg2_type,
                            Arg3_type, Arg4_type, Arg5_type, Arg6_type> tmp(object,function);

        #ifdef HYDROSIG_USE_THREAD_SYNCHRONISATION
        #ifdef HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
        HMutexLocker guard(m_mutex);

        #else
        std::lock_guard<std::recursive_mutex> guard(m_mutex);

        #endif // HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
        #endif // HYDROSIG_USE_THREAD_SYNCHRONISATION

        typename slot_list::iterator itBegin(m_slots.begin());
        typename slot_list::iterator itEnd(m_slots.end());

        while(itBegin != itEnd)
        {
            // Attempting to downcast the slot's functor to the type of the temporary functor
            functor_6_base<Return_type, Arg1_type, Arg2_type,
                      Arg3_type, Arg4_type, Arg5_type,
                      Arg6_type>* original =
            (*itBegin)->get_functor();

            functor_to_member_6<Object_type, Return_type, Arg1_type, Arg2_type,
                                Arg3_type, Arg4_type, Arg5_type, Arg6_type>* downcasted =
            dynamic_cast<functor_to_member_6<Object_type, Return_type, Arg1_type, Arg2_type,
                                             Arg3_type, Arg4_type, Arg5_type, Arg6_type>*>
            (original);

            // If downcasting fails, skip to the next
            if(downcasted == nullptr)
            {
                itBegin++;
                continue;
            }
            // If downcasting succeeds, remove the slot
            else if(tmp == (*downcasted))
            {
                // Removing notification callback from the signal
                // to the slot. This is necessary, because upon
                // destruction the slot would notify the signal
                // again, causing an infinite loop
                (*itBegin)->remove_destroy_notify_callback(this);
                delete (*itBegin);

                // Removing the slot from the list
                m_slots.erase(itBegin);
                return;
            }

            itBegin++;
        }
    }

    template<class Object_type>
    /**
     * @brief   Disconnects a member function with const
     *          specifier of the given object.
     * @param   object Pointer to the object.
     * @param   function Pointer to the member function.
     */
    void disconnect(Object_type* object, Return_type(Object_type::*function)(Arg1_type, Arg2_type, Arg3_type,
                                                                             Arg4_type, Arg5_type, Arg6_type) const)
    {
        // Creating temporary functor from the given function to compare equality with
        functor_to_member_const_6<Object_type, Return_type, Arg1_type, Arg2_type,
                                  Arg3_type, Arg4_type, Arg5_type, Arg6_type> tmp(object,function);

        #ifdef HYDROSIG_USE_THREAD_SYNCHRONISATION
        #ifdef HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
        HMutexLocker guard(m_mutex);

        #else
        std::lock_guard<std::recursive_mutex> guard(m_mutex);

        #endif // HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
        #endif // HYDROSIG_USE_THREAD_SYNCHRONISATION

        typename slot_list::iterator itBegin(m_slots.begin());
        typename slot_list::iterator itEnd(m_slots.end());

        while(itBegin != itEnd)
        {
            // Attempting to downcast the slot's functor to the type of the temporary functor
            functor_6_base<Return_type, Arg1_type, Arg2_type,
                      Arg3_type, Arg4_type, Arg5_type,
                      Arg6_type>* original =
            (*itBegin)->get_functor();

            functor_to_member_const_6<Object_type, Return_type, Arg1_type, Arg2_type,
                                      Arg3_type, Arg4_type, Arg5_type, Arg6_type>* downcasted =
            dynamic_cast<functor_to_member_const_6<Object_type,Return_type, Arg1_type, Arg2_type,
                                                   Arg3_type, Arg4_type, Arg5_type, Arg6_type>*>
            (original);

            // If downcasting fails, skip to the next
            if(downcasted == nullptr)
            {
                itBegin++;
                continue;
            }
            // If downcasting succeeds, remove the slot
            else if(tmp == (*downcasted))
            {
                // Removing notification callback from the signal
                // to the slot. This is necessary, because upon
                // destruction the slot would notify the signal
                // again, causing an infinite loop
                (*itBegin)->remove_destroy_notify_callback(this);
                delete (*itBegin);

                // Removing the slot from the list
                m_slots.erase(itBegin);
                return;
            }

            itBegin++;
        }
    }

    template<class Object_type>
    /**
     * @brief   Disconnects a member function with volatile
     *          specifier of the given object.
     * @param   object Pointer to the object.
     * @param   function Pointer to the member function.
     */
    void disconnect(Object_type* object, Return_type(Object_type::*function)(Arg1_type, Arg2_type, Arg3_type,
                                                                             Arg4_type, Arg5_type, Arg6_type) volatile)
    {
        // Creating temporary functor from the given function to compare equality with
        functor_to_member_volatile_6<Object_type, Return_type, Arg1_type, Arg2_type,
                                     Arg3_type, Arg4_type, Arg5_type, Arg6_type> tmp(object,function);

        #ifdef HYDROSIG_USE_THREAD_SYNCHRONISATION
        #ifdef HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
        HMutexLocker guard(m_mutex);

        #else
        std::lock_guard<std::recursive_mutex> guard(m_mutex);

        #endif // HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
        #endif // HYDROSIG_USE_THREAD_SYNCHRONISATION

        typename slot_list::iterator itBegin(m_slots.begin());
        typename slot_list::iterator itEnd(m_slots.end());

        while(itBegin != itEnd)
        {
            // Attempting to downcast the slot's functor to the type of the temporary functor
            functor_6_base<Return_type, Arg1_type, Arg2_type,
                      Arg3_type, Arg4_type, Arg5_type,
                      Arg6_type>* original =
            (*itBegin)->get_functor();

            functor_to_member_volatile_6<Object_type, Return_type, Arg1_type, Arg2_type,
                                         Arg3_type, Arg4_type, Arg5_type, Arg6_type>* downcasted =
            dynamic_cast<functor_to_member_volatile_6<Object_type, Return_type, Arg1_type, Arg2_type,
                                                      Arg3_type, Arg4_type, Arg5_type, Arg6_type>*>
            (original);

            // If downcasting fails, skip to the next
            if(downcasted == nullptr)
            {
                itBegin++;
                continue;
            }
            // If downcasting succeeds, remove the slot
            else if(tmp == (*downcasted))
            {
                // Removing notification callback from the signal
                // to the slot. This is necessary, because upon
                // destruction the slot would notify the signal
                // again, causing an infinite loop
                (*itBegin)->remove_destroy_notify_callback(this);
                delete (*itBegin);

                // Removing the slot from the list
                m_slots.erase(itBegin);
                return;
            }

            itBegin++;
        }
    }

    template<class Object_type>
    /**
     * @brief   Disconnects a member function with const
     *          volatile specifier of the given object.
     * @param   object Pointer to the object.
     * @param   function Pointer to the member function.
     */
    void disconnect(Object_type* object, Return_type(Object_type::*function)(Arg1_type, Arg2_type, Arg3_type,
                                                                             Arg4_type, Arg5_type, Arg6_type) const volatile)
    {
        // Creating temporary functor from the given function to compare equality with
        functor_to_member_const_volatile_6<Object_type, Return_type, Arg1_type, Arg2_type,
                                           Arg3_type, Arg4_type, Arg5_type, Arg6_type> tmp(object,function);

        #ifdef HYDROSIG_USE_THREAD_SYNCHRONISATION
        #ifdef HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
        HMutexLocker guard(m_mutex);

        #else
        std::lock_guard<std::recursive_mutex> guard(m_mutex);

        #endif // HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
        #endif // HYDROSIG_USE_THREAD_SYNCHRONISATION

        typename slot_list::iterator itBegin(m_slots.begin());
        typename slot_list::iterator itEnd(m_slots.end());

        while(itBegin != itEnd)
        {
            // Attempting to downcast the slot's functor to the type of the temporary functor
            functor_6_base<Return_type, Arg1_type, Arg2_type,
                      Arg3_type, Arg4_type, Arg5_type,
                      Arg6_type>* original =
            (*itBegin)->get_functor();

            functor_to_member_const_volatile_6<Object_type, Return_type, Arg1_type, Arg2_type,
                                               Arg3_type, Arg4_type, Arg5_type, Arg6_type>* downcasted =
            dynamic_cast<functor_to_member_const_volatile_6<Object_type, Return_type, Arg1_type, Arg2_type,
                                                            Arg3_type, Arg4_type, Arg5_type, Arg6_type>*>
            (original);

            // If downcasting fails, skip to the next
            if(downcasted == nullptr)
            {
                itBegin++;
                continue;
            }
            // If downcasting succeeds, remove the slot
            else if(tmp == (*downcasted))
            {
                // Removing notification callback from the signal
                // to the slot. This is necessary, because upon
                // destruction the slot would notify the signal
                // again, causing an infinite loop
                (*itBegin)->remove_destroy_notify_callback(this);
                delete (*itBegin);

                // Removing the slot from the list
                m_slots.erase(itBegin);
                return;
            }

            itBegin++;
        }
    }

    /**
     * @brief   Disconnects a slot indicated by the connection object
     *          that was returned upon connecting it to the signal.
     * @param   con Reference to the connection object.
     */
    void disconnect(const connection_type& con)
    {
        #ifdef HYDROSIG_USE_THREAD_SYNCHRONISATION
        #ifdef HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
        HMutexLocker guard(m_mutex);

        #else
        std::lock_guard<std::recursive_mutex> guard(m_mutex);

        #endif // HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
        #endif // HYDROSIG_USE_THREAD_SYNCHRONISATION

        typename slot_list::iterator itBegin(m_slots.begin());
        typename slot_list::iterator itEnd(m_slots.end());

        while(itBegin != itEnd)
        {
            if((*itBegin) == con.m_slot)
            {
                // Removing notification callback from the signal
                // to the slot. This is necessary, because upon
                // destruction the slot would notify the signal
                // again, causing an infinite loop
                (*itBegin)->remove_destroy_notify_callback(this);
                delete (*itBegin);

                // Removing the slot from the list
                m_slots.erase(itBegin);
                return;
            }

            itBegin++;
        }
    }

    /**
     * @brief   Emits the signal by activating all of the
     *          connected slot's callback functions.
     * @details The slots are activated in the exact same
     *          order they were connected to the signal.
     */
    void emit(Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
              Arg4_type arg4, Arg5_type arg5, Arg6_type arg6)
    {
        if(isBlocked()) return;

        #ifdef HYDROSIG_USE_THREAD_SYNCHRONISATION
        #ifdef HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
        HMutexLocker guard(m_mutex);

        #else
        std::lock_guard<std::recursive_mutex> guard(m_mutex);

        #endif // HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
        #endif // HYDROSIG_USE_THREAD_SYNCHRONISATION

        typename slot_list::iterator itBegin(m_slots.begin());
        typename slot_list::iterator itEnd(m_slots.end());

        while(itBegin != itEnd)
        {
            // If the slot is blocked or empty jump to the next
            if((*itBegin)->isBlocked() || (*itBegin)->empty())
            {
                itBegin++;
                continue;
            }

            try {
                // Using a separate iterator, as the slot could
                // call disconnect, and invalidate the moving
                // iterator
                typename slot_list::iterator itCurrent = itBegin;
                itBegin++;

                (*itCurrent)->activate(arg1,arg2,arg3,arg4,arg5,arg6);
            }
            catch(...)
            {
                throw;
            }
        }

        // Return values of the functors are swallowed
    }

    /**
     * @brief   Emits the signal by activating all of the
     *          connected slot's callback functions.
     * @details The slots are activated in reverse order
     *          of they were connected to the signal.
     */
    void emit_reverse(Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                      Arg4_type arg4, Arg5_type arg5, Arg6_type arg6)
    {
        if(isBlocked()) return;

        #ifdef HYDROSIG_USE_THREAD_SYNCHRONISATION
        #ifdef HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
        HMutexLocker guard(m_mutex);

        #else
        std::lock_guard<std::recursive_mutex> guard(m_mutex);

        #endif // HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
        #endif // HYDROSIG_USE_THREAD_SYNCHRONISATION

        typename slot_list::reverse_iterator itBegin(m_slots.rbegin());
        typename slot_list::reverse_iterator itEnd(m_slots.rend());

        while(itBegin != itEnd)
        {
            // If the slot is blocked or empty jump to the next
            if((*itBegin)->isBlocked() || (*itBegin)->empty())
            {
                itBegin++;
                continue;
            }

            try {
                // Using a separate iterator, as the slot could
                // call disconnect, and invalidate the moving
                // iterator
                typename slot_list::reverse_iterator itCurrent = itBegin;
                itBegin++;

                (*itCurrent)->activate(arg1,arg2,arg3,arg4,arg5,arg6);
            }
            catch(...)
            {
                throw;
            }
        }

        // Return values of the functors are swallowed
    }

    /**
     * @brief   Emits the signal by activating all of the
     *          connected slot's callback functions.
     * @details The slots are activated in the exact same
     *          order they were connected to the signal.
     *          This is a convenience function, and simply
     *          calls emit().
     */
    void operator()(Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                    Arg4_type arg4, Arg5_type arg5, Arg6_type arg6)
    {
        try {
            emit(arg1,arg2,arg3,
                 arg4,arg5,arg6);
        }
        catch(...)
        {
            throw;
        }
    }

    /**< Nested class for emitting signals with collected results */
    class collected;

protected:
    /**
     * @brief   When notificated about that a slot has become
     *          invalid and requests deletion, it removes the
     *          slot.
     * @param   destroyed Pointer to the slot that wants to be
     *          deleted.
     */
    void on_destruction_notification(notifyable* destroyed)
    {
        trackable::on_destruction_notification(destroyed);

        #ifdef HYDROSIG_USE_THREAD_SYNCHRONISATION
        #ifdef HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
        HMutexLocker guard(m_mutex);

        #else
        std::lock_guard<std::recursive_mutex> guard(m_mutex);

        #endif // HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
        #endif // HYDROSIG_USE_THREAD_SYNCHRONISATION

        typename slot_list::iterator itBegin(m_slots.begin());
        typename slot_list::iterator itEnd(m_slots.end());

        while(itBegin != itEnd)
        {
            if((*itBegin) == destroyed)
            {
                // Removing notification callback from the signal
                // to the slot. This is necessary, because upon
                // destruction the slot would notify the signal
                // again, causing an infinite loop
                dynamic_cast<trackable*>(destroyed)->remove_destroy_notify_callback(this);
                delete destroyed;

                // Removing the slot from the list
                m_slots.erase(itBegin);

                break;
            }

            itBegin++;
        }
    }

protected:
    slot_list m_slots;      /**< The list of slots */

};

template<class Return_type,
         class Arg1_type, class Arg2_type, class Arg3_type,
         class Arg4_type, class Arg5_type, class Arg6_type>
/**
 * @brief   This nested class can be used to collect the
 *          results of signal emissions with six arguments.
 * @details Collection is achieved by extending the base
 *          signal type with two new emitting functions,
 *          suffixed with 'collected'. These methods return
 *          the list containing the results of each individual
 *          slot activations. Note that functions with 'void' as
 *          return type, can not be used with collected signals.
 */
class signal_6<Return_type,
               Arg1_type,Arg2_type,Arg3_type,
               Arg4_type,Arg5_type,Arg6_type>::collected
        : public signal_6<Return_type,
                          Arg1_type,Arg2_type,Arg3_type,
                          Arg4_type,Arg5_type,Arg6_type>
{
protected:
    /**< Typedef for the list of returned values */
    #ifdef HYDROSIG_USE_HYDROGEN_CONTAINERS
    typedef HList<Return_type> result_list_type;
    #else
    typedef std::list<Return_type> result_list_type;
    #endif // HYDROSIG_USE_HYDROGEN_CONTAINERS

public:
    result_list_type emit_collected(Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                                    Arg4_type arg4, Arg5_type arg5, Arg6_type arg6)
    {
        result_list_type resultList;
        if(isBlocked()) return resultList;

        #ifdef HYDROSIG_USE_THREAD_SYNCHRONISATION
        #ifdef HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
        HMutexLocker guard(m_mutex);

        #else
        std::lock_guard<std::recursive_mutex> guard(m_mutex);

        #endif // HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
        #endif // HYDROSIG_USE_THREAD_SYNCHRONISATION

        typename slot_list::iterator itBegin(m_slots.begin());
        typename slot_list::iterator itEnd(m_slots.end());

        while(itBegin != itEnd)
        {
            // If the slot is blocked or empty jump to the next
            if((*itBegin)->isBlocked() || (*itBegin)->empty())
            {
                itBegin++;
                continue;
            }

            try {
                // Using a separate iterator, as the slot could
                // call disconnect, and invalidate the moving
                // iterator
                typename slot_list::iterator itCurrent = itBegin;
                itBegin++;

                resultList.push_back((*itCurrent)->activate(arg1,arg2,arg3,arg4,arg5,arg6));
            }
            catch(...)
            {
                throw;
            }
        }

        return resultList;
    }

    result_list_type emit_reverse_collected(Arg1_type arg1, Arg2_type arg2, Arg3_type arg3,
                                            Arg4_type arg4, Arg5_type arg5, Arg6_type arg6)
    {
        result_list_type resultList;
        if(isBlocked()) return resultList;

        #ifdef HYDROSIG_USE_THREAD_SYNCHRONISATION
        #ifdef HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
        HMutexLocker guard(m_mutex);

        #else
        std::lock_guard<std::recursive_mutex> guard(m_mutex);

        #endif // HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
        #endif // HYDROSIG_USE_THREAD_SYNCHRONISATION

        typename slot_list::reverse_iterator itBegin(m_slots.rbegin());
        typename slot_list::reverse_iterator itEnd(m_slots.rend());

        while(itBegin != itEnd)
        {
            // If the slot is blocked or empty jump to the next
            if((*itBegin)->isBlocked() || (*itBegin)->empty())
            {
                itBegin++;
                continue;
            }

            try {
                // Using a separate iterator, as the slot could
                // call disconnect, and invalidate the moving
                // iterator
                typename slot_list::reverse_iterator itCurrent = itBegin;
                itBegin++;

                resultList.push_back((*itCurrent)->activate(arg1,arg2,arg3,arg4,arg5,arg6));
            }
            catch(...)
            {
                throw;
            }
        }

        return resultList;
    }

};


HYDROSIG_NAMESPACE_END


#endif // HYDROSIG_SIGNAL_6_HPP_INCLUDED
