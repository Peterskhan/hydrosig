#include "connection_base.h"


HYDROSIG_NAMESPACE_BEGIN


/**
 * Member definitions:
 * -------------------
 */

connection_base::connection_base(
        HYDROSIG_SHARED_PTR_TYPE<connection_validator> validator)
    : m_validator(validator)
{
    ;
}

bool connection_base::isConnected() const
{
    return m_validator->isValid();
}

const char* connection_failure::what() const noexcept
    {
        return "Hydrosig: Signal connection failed.";
    }


HYDROSIG_NAMESPACE_END
