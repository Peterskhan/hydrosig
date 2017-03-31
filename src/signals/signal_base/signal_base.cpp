#include "signal_base.h"


HYDROSIG_NAMESPACE_BEGIN


/**
 * Methods for class: signal_base.
 * --------------------------------------------------
 */

/**
 * @brief   Constructs a signal in a non-blocked state.
 */
signal_base::signal_base()
    : m_blocked(false)
{
    ;
}

/**
 * @brief   Destroys the signal, and terminates all
 *          established connections.
 */
signal_base::~signal_base()
{
    ;
}

/**
 * @brief   Returns whether the signal is blocked.
 * @return  True if the signal is blocked.
 */
bool signal_base::isBlocked() const
{
    return m_blocked;
}

/**
 * @brief   Sets the blocking state of the signal.
 * @param   shouldBlock The state of blocking.
 */
void signal_base::block(bool shouldBlock)
{
    m_blocked = shouldBlock;
}

/**
 * @brief   Unblocks the signal.
 */
void signal_base::unblock()
{
    m_blocked = false;
}


HYDROSIG_NAMESPACE_END
