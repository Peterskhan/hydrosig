#include "signal_base.h"


HYDROSIG_NAMESPACE_BEGIN


/**
 * Member definitions:
 * -------------------
 */

signal_base::signal_base()
    : m_blocked(false)
{
    ;
}

signal_base::~signal_base()
{
    ;
}

bool signal_base::isBlocked() const
{
    return m_blocked;
}

void signal_base::block(bool shouldBlock)
{
    m_blocked = shouldBlock;
}

void signal_base::unblock()
{
    m_blocked = false;
}


HYDROSIG_NAMESPACE_END
