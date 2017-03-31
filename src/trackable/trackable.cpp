#include "trackable.h"


HYDROSIG_NAMESPACE_BEGIN


/**
 * Methods for class: notifyable.
 * --------------------------------------------------
 */

/**
 * @brief   Virtual method to be used as callback when
 *          a destruction notification is received.
 * @details Override this method to implement the
 *          desired behaviour when notificated about
 *          an object's destruction.
 */
void notifyable::on_destruction_notification(notifyable* /*destroyed*/)
{
    ;
}

/**
 * @brief   Destroys the notifyable object.
 */
notifyable::~notifyable()
{
    ;
}


/**
 * Methods for class: destroy_notify_callback.
 * --------------------------------------------------
 */

/**
 * @brief Constructs a destroy_notify_callback.
 * @param target The target of the destruction notification callback.
 * @param callback The pointer to the callback executed on the target.
 */
destroy_notify_callback::destroy_notify_callback(notifyable* target,
                                                 callback_type callback)
    : m_target(target),
      m_callback(callback)
{
    ;
}

/**
 * @brief   Returns the target of the callback.
 * @return  Pointer to the target object.
 */
notifyable* destroy_notify_callback::get_target() const
{
    return m_target;
}

/**
 * @brief   Returns the callback function.
 * @return  Pointer to the callback function.
 */
destroy_notify_callback::callback_type
destroy_notify_callback::get_callback() const
{
    return m_callback;
}

/**
 * @brief   Activates the stored callback.
 * @param   destroyed Pointer to the object that sends the notification.
 */
void destroy_notify_callback::operator()(notifyable* destroyed)
{
    try {
        (m_target->*m_callback)(destroyed);
    }
    catch(...)
    {
        // Swallow the exception to prevent it from
        // getting into the destructor and causing
        // program termination.
    }
}


/**
 * Methods for class: destroy_notify_callback_list.
 * --------------------------------------------------
 */

/**
 * @brief Adds a destruction notification callback to the list.
 * @param target The target of the callback.
 * @param func The pointer to the callback function executed by the target.
 */
void destroy_notify_callback_list::add_destroy_notify_callback(notifyable* target,
                                                               callback_type func)
{
    try {
        m_callbacks.push_back(destroy_notify_callback(target,func));
    }
    catch(...)
    {
        throw;
    }
}

/**
 * @brief Removes a destruction notification callback from the list.
 * @param target The target to remove destroy_notify_callbacks associated with.
 */
void destroy_notify_callback_list::remove_destroy_notify_callback(notifyable* target)
{
    callback_list::iterator itBegin(m_callbacks.begin());
    callback_list::iterator itEnd(m_callbacks.end());

    while(itBegin != itEnd)
    {
        if(itBegin->get_target() == target)
        {
            itBegin = m_callbacks.erase(itBegin);
            continue;
        }
        itBegin++;
    }
}

/**
 * @brief   Executes and removes all destroy_notify_callbacks
 *          from the list.
 */
void destroy_notify_callback_list::clear(notifyable* observer)
{
    callback_list::iterator itBegin(m_callbacks.begin());
    callback_list::iterator itEnd(m_callbacks.end());

    while(itBegin != itEnd)
    {
        // Creating a copy of the callback, and removing
        // the original from the callback-list to prevent
        // running into a callback loop.
        destroy_notify_callback callback(itBegin->get_target(),
                                         itBegin->get_callback());

        itBegin = m_callbacks.erase(itBegin);

        callback(observer);
    }
}


/**
 * Methods for class: trackable.
 * --------------------------------------------------
 */

/**
 * @brief Constructs a trackable object.
 */
trackable::trackable()
    : notifyable()
{
    ;
}

/**
 * @brief Constructs a trackable object, by copying src.
 * @param src The object to copy construct from.
 */
trackable::trackable(const trackable& /*src*/)
{
    // Do not copy the list of callbacks
}

/**
 * @brief Constructs a trackable object, by moving src.
 * @param src The object to move construct from.
 */
trackable::trackable(trackable &&src)
{
    // Do not copy the list of callbacks.

    // Altough the source object may become invalid,
    // so call it's notify_callbacks() method
    src.notify_callbacks();
}

/**
 * @brief Assigns the value of another trackable object.
 * @param src The object to assign.
 */
trackable& trackable::operator=(const trackable& src)
{
    // Do not copy the list of callbacks

    // Notify all callbacks before replacing
    // the object.

    if(&src != this)
    {
        notify_callbacks();
    }

    return *this;
}

/**
 * @brief Move assigns the value of another trackable object.
 * @param src The object to move assign.
 */
trackable& trackable::operator=(trackable&& src)
{
    // Do not copy the list of callbacks

    // Notify all callbacks before replacing
    // the object.
    if(&src != this)
    {
        notify_callbacks();

        // Altough the source object may become invalid,
        // so call it's notify_callbacks() method
        src.notify_callbacks();
    }

    return *this;
}

/**
 * @brief   Destroys the trackable object.
 * @details Upon destruction the trackable object,
 *          executes all installed callbacks.
 */
trackable::~trackable()
{
    notify_callbacks();
}

/**
 * @brief Adds a destrouction notification callback.
 * @param target The target of the callback.
 * @param func The callback function to execute by the target.
 */
void trackable::add_destroy_notify_callback(notifyable* target,
                                            callback_type func)
{
    #ifdef HYDROSIG_USE_THREAD_SYNCHRONISATION
    #ifdef HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
    HMutexLocker guard(m_mutex);

    #else
    std::lock_guard<std::recursive_mutex> guard(m_mutex);

    #endif // HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
    #endif // HYDROSIG_USE_THREAD_SYNCHRONISATION

    try {
        m_callbacks.add_destroy_notify_callback(target,func);
    }
    catch(...)
    {
        throw;
    }
}

/**
 * @brief Removes a previously installed destruction notification callback.
 * @param target The target of the previously installed callback.
 */
void trackable::remove_destroy_notify_callback(notifyable* target)
{
    #ifdef HYDROSIG_USE_THREAD_SYNCHRONISATION
    #ifdef HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
    HMutexLocker guard(m_mutex);

    #else
    std::lock_guard<std::recursive_mutex> guard(m_mutex);

    #endif // HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
    #endif // HYDROSIG_USE_THREAD_SYNCHRONISATION

    m_callbacks.remove_destroy_notify_callback(target);
}

/**
 * @brief   When notificated, removes all callbacks
 *          associated with the destroyed object.
 * @param   destroyed The destroyed object.
 */
void trackable::on_destruction_notification(notifyable* destroyed)
{
    remove_destroy_notify_callback(destroyed);
}

/**
 * @brief Executes and removes all previously installed callbacks.
 */
void trackable::notify_callbacks()
{
    #ifdef HYDROSIG_USE_THREAD_SYNCHRONISATION
    #ifdef HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
    HMutexLocker guard(m_mutex);

    #else
    std::lock_guard<std::recursive_mutex> guard(m_mutex);

    #endif // HYDROSIG_USE_HYDROGEN_SYNCHRONISATION
    #endif // HYDROSIG_USE_THREAD_SYNCHRONISATION

    m_callbacks.clear(this);
}


HYDROSIG_NAMESPACE_END
