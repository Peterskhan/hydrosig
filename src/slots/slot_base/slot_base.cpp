#include "slot_base.h"


HYDROSIG_NAMESPACE_BEGIN


/**
 * Methods for class: slot_base.
 * --------------------------------------------------
 */

/**
 * @brief   Constructs a slot_base object.
 * @details The state of blocking will be
 *          initialized to false.
 */
slot_base::slot_base()
    : m_blocked(false)
{
    ;
}

/**
 * @brief   Destroys the slot_base.
 */
slot_base::~slot_base()
{
    ;
}

/**
 * @brief   Sets the blocking state of the slot.
 * @details If the connection is blocked by the slot,
 *          no callbacks will be executed when the holding
 *          signal is emitted.
 * @param   shouldBlock The state of blocking to set.
 */
void slot_base::block(bool shouldBlock)
{
    m_blocked = shouldBlock;
}

/**
 * @brief   Unblocks the slot.
 */
void slot_base::unblock()
{
    m_blocked = false;
}

/**
 * @brief   Returns whether the slot is blocked.
 * @return  True if the slot is blocked.
 */
bool slot_base::isBlocked() const
{
    return m_blocked;
}


HYDROSIG_NAMESPACE_END
