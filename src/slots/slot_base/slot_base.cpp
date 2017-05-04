#include "slot_base.h"


HYDROSIG_NAMESPACE_BEGIN


/**
 * Member definitions:
 * -------------------
 */

slot_base::slot_base(HYDROSIG_SHARED_PTR_TYPE<connection_validator> validator)
    : m_blocked(false),
      m_validator(validator)
{
    ;
}

slot_base::~slot_base()
{
    m_validator->invalidate();
}

HYDROSIG_SHARED_PTR_TYPE<connection_validator> slot_base::getValidator() const
{
    return m_validator;
}

bool slot_base::isValid() const
{
    return m_validator->isValid();
}

void slot_base::block(bool shouldBlock)
{
    m_blocked = shouldBlock;
}

void slot_base::unblock()
{
    m_blocked = false;
}

bool slot_base::isBlocked() const
{
    return m_blocked;
}


HYDROSIG_NAMESPACE_END
