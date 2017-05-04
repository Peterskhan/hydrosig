#include "trackable.h"


HYDROSIG_NAMESPACE_BEGIN


/**
 * Member definitions:
 * -------------------
 */

connection_validator::connection_validator()
    : m_isValid(true)
{
    ;
}

void connection_validator::invalidate()
{
    m_isValid = false;
}

bool connection_validator::isValid() const
{
    return m_isValid;
}

trackable::~trackable()
{
    removeInvalidated();

    HYDROSIG_PROTECTED_BLOCK_BEGIN

    HYDROSIG_LIST_TYPE<HYDROSIG_SHARED_PTR_TYPE<connection_validator>>
            ::iterator itBegin(m_validators.begin());

    HYDROSIG_LIST_TYPE<HYDROSIG_SHARED_PTR_TYPE<connection_validator>>
            ::iterator itEnd(m_validators.end());

    while(itBegin != itEnd)
    {
        (*itBegin)->invalidate();
        itBegin++;
    }

    HYDROSIG_PROTECTED_BLOCK_END
}

void trackable::addValidator(HYDROSIG_SHARED_PTR_TYPE<connection_validator> validator)
{
    removeInvalidated();

    HYDROSIG_PROTECTED_BLOCK_BEGIN

    try {
        m_validators.push_back(validator);
    }
    catch(...)
    {
        throw;
    }

    HYDROSIG_PROTECTED_BLOCK_END
}

void trackable::removeValidator(HYDROSIG_SHARED_PTR_TYPE<connection_validator> validator)
{
    HYDROSIG_PROTECTED_BLOCK_BEGIN

    HYDROSIG_LIST_TYPE<HYDROSIG_SHARED_PTR_TYPE<connection_validator>>
            ::iterator itBegin(m_validators.begin());

    HYDROSIG_LIST_TYPE<HYDROSIG_SHARED_PTR_TYPE<connection_validator>>
            ::iterator itEnd(m_validators.end());

    while(itBegin != itEnd)
    {
        if(*itBegin == validator)
        {
            m_validators.erase(itBegin);
            break;
        }
        itBegin++;
    }

    HYDROSIG_PROTECTED_BLOCK_END
}

void trackable::removeInvalidated()
{
    HYDROSIG_PROTECTED_BLOCK_BEGIN

    HYDROSIG_LIST_TYPE<HYDROSIG_SHARED_PTR_TYPE<connection_validator>>
            ::iterator itBegin(m_validators.begin());

    HYDROSIG_LIST_TYPE<HYDROSIG_SHARED_PTR_TYPE<connection_validator>>
            ::iterator itEnd(m_validators.end());

    while(itBegin != itEnd)
    {
        if(!(*itBegin)->isValid())
        {
            itBegin = m_validators.erase(itBegin);
            continue;
        }
        itBegin++;
    }

    HYDROSIG_PROTECTED_BLOCK_END
}


HYDROSIG_NAMESPACE_END
