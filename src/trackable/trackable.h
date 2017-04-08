#pragma once
#ifndef HYDROSIG_TRACKABLE_H_INCLUDED
#define HYDROSIG_TRACKABLE_H_INCLUDED

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

#include "macros.h"

/*****************************************/
#ifdef HYDROSIG_USE_HYDROGEN_CONTAINERS
#include "../HContainers/HList/HList.h"

#else
#include <list>

#endif // HYDROSIG_USE_HYDROGEN_CONTAINERS
/*****************************************/

/*****************************************/
#ifdef HYDROSIG_USE_THREAD_SYNCHRONISATION
#ifdef HYDROSIG_USE_HYDROGEN_SYNCHRONISATION

#include "HConcurrent/HMutex/HMutex.h"
#include "HConcurrent/HMutexLocker/HMutexLocker.h"

#else
#include <mutex>

#endif // HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
#endif // HYDROSIG_USE_THREAD_SYNCHRONISATION
/*****************************************/


HYDROSIG_NAMESPACE_BEGIN


/**
 * @brief   Common baseclass for notifyable objects.
 * @details This class provides an overridable virtual
 *          method, which can be used to implement the
 *          desired behaviour when notificated about the
 *          destruction of an object. Trackable objects
 *          can use this override as their callback method.
 *          To make use of this, simply add a callback with
 *          add_destroy_notify_callback() using a pointer
 *          to the object which needs to be notificated,
 *          and a function pointer to the virtual method
 *          on_destruction_notification(). This method
 *          expects a pointer to the object which is being
 *          destroyed.
 */
class notifyable
{
protected:
    /**
     * @brief   Virtual method to be used as callback when
     *          a destruction notification is received.
     * @details Override this method to implement the
     *          desired behaviour when notificated about
     *          an object's destruction.
     */
    virtual void on_destruction_notification(notifyable* /*destroyed*/);

public:
    /**
     * @brief   Destroys the notifyable object.
     */
    virtual ~notifyable();

};

/**
 * @brief   This structure encapsulates a destroy notify callback.
 * @details Destroy_notify_callbacks contain a pointer to the actual
 *          callback method, and a pointer to the target object that
 *          the callback is executed by.
 */
class destroy_notify_callback
{
public:
    /**< Typedef for the callback function type */
    typedef void (notifyable::*callback_type)(notifyable*);

private:
    notifyable*     m_target;       /**< The target of the destrunction notification callback */
    callback_type   m_callback;     /**< The pointer to the callback executed on the target */

public:
    /**
     * @brief Constructs a destroy_notify_callback.
     * @param target The target of the destruction notification callback.
     * @param callback The pointer to the callback executed on the target.
     */
    destroy_notify_callback(notifyable* target,
                            callback_type callback);

    /**
     * @brief   Returns the target of the callback.
     * @return  Pointer to the target object.
     */
    notifyable* get_target() const;

    /**
     * @brief   Returns the callback function.
     * @return  Pointer to the callback function.
     */
    callback_type get_callback() const;

    /**
     * @brief   Activates the stored callback.
     * @param   destroyed Pointer to the object that sends the notification.
     */
    void operator()(notifyable* destroyed);

};

/**
 * @brief   This class encapsulates a list of destroy notify callbacks.
 * @details Destroy_notify_callback_lists are wrappers around a list of
 *          destroy_notify_callbacks. To add a destroy_notify_callback,
 *          use add_destroy_notify_callback(), to remove a previously
 *          installed one, use remove_destroy_notify_callback().
 *          To execute and remove all installed callbacks, use clear().
 */
class destroy_notify_callback_list
{
public:
    /**< Typedef for the callback function type */
    typedef destroy_notify_callback::callback_type callback_type;

    /**< Typedef for the list of callbacks */
    #ifdef HYDROSIG_USE_HYDROGEN_CONTAINERS
    typedef HList<destroy_notify_callback> callback_list;
    #else
    typedef std::list<destroy_notify_callback> callback_list;
    #endif // HYDROSIG_USE_HYDROGEN_CONTAINERS

    /**< Typedef for the callback list iterator */
    #ifdef HYDROSIG_USE_HYDROGEN_CONTAINERS
    typedef HList<destroy_notify_callback>::iterator iterator;
    #else
    typedef std::list<destroy_notify_callback>::iterator iterator;
    #endif // HYDROSIG_USE_HYDROGEN_CONTAINERS

private:
    callback_list m_callbacks;      /**< The list of callbacks */

public:
    /**
     * @brief Adds a destruction notification callback to the list.
     * @param target The target of the callback.
     * @param func The pointer to the callback function executed by the target.
     */
    void add_destroy_notify_callback(notifyable* target,
                                     callback_type func);

    /**
     * @brief Removes a destruction notification callback from the list.
     * @param target The target to remove destroy_notify_callbacks associated with.
     */
    void remove_destroy_notify_callback(notifyable* target);

    /**
     * @brief   Executes and removes all destroy_notify_callbacks
     *          from the list.
     */
    void clear(notifyable* observer);

};

/**
 * @brief   Common base class for automatic signal-disconnecting classes.
 * @details This class forms the base of classes that automatically
 *          disconnect from all signal-slot connections upon destruction.
 *          If you want your class to provide this automatic behaviour,
 *          derive it from the trackable class. Trackable objects ontain a list of
 *          destroy_notify_callbacks. Upon destruction, all of the installed
 *          callbacks will be executed, making possible for the object to
 *          automatically disconnect all signal-slot connections using these
 *          callbacks. To add a destrouction notification callback use
 *          add_destroy_notify_callback(), to remove a previously installed one,
 *          use remove_destroy_notify_callback(). To execute all installed
 *          destroy_notify_callbacks, use notify_callbacks().
 */
class trackable : public notifyable
{
public:
    /**< Typedef for the callback function type */
    typedef destroy_notify_callback::callback_type callback_type;

private:
    destroy_notify_callback_list m_callbacks;   /**< The list of installed callbacks */

protected:
    /**< The mutex used for thread synchronisation */
    #ifdef HYDROSIG_USE_THREAD_SYNCHRONISATION
    #ifdef HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
    HMutex m_mutex;

    #else
    std::recursive_mutex m_mutex;

    #endif // HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
    #endif // HYDROSIG_USE_THREAD_SYNCHRONISATION

public:
    /**
     * @brief Constructs a trackable object.
     */
    trackable();

    /**
     * @brief Constructs a trackable object, by copying src.
     * @param src The object to copy construct from.
     */
    trackable(const trackable& /*src*/);

    /**
     * @brief Constructs a trackable object, by moving src.
     * @param src The object to move construct from.
     */
    trackable(trackable &&src);

    /**
     * @brief Assigns the value of another trackable object.
     * @param src The object to assign.
     */
    trackable& operator=(const trackable& src);

    /**
     * @brief Move assigns the value of another trackable object.
     * @param src The object to move assign.
     */
    trackable& operator=(trackable&& src);

    /**
     * @brief   Destroys the trackable object.
     * @details Upon destruction the trackable object,
     *          executes all installed callbacks.
     */
    virtual ~trackable();

    /**
     * @brief Adds a destrouction notification callback.
     * @param target The target of the callback.
     * @param func The callback function to execute by the target.
     */
    void add_destroy_notify_callback(notifyable* target,
                                     callback_type func);

    /**
     * @brief Removes a previously installed destruction notification callback.
     * @param target The target of the previously installed callback.
     */
    void remove_destroy_notify_callback(notifyable* target);

    /**
     * @brief   When notificated, removes all callbacks
     *          associated with the destroyed object.
     * @param   destroyed The destroyed object.
     */
    virtual void on_destruction_notification(notifyable* destroyed);

protected:
    /**
     * @brief Executes and removes all previously installed callbacks.
     */
    void notify_callbacks();

};


HYDROSIG_NAMESPACE_END


#endif // HYDROSIG_TRACKABLE_H_INCLUDED
