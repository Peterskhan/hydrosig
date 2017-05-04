#pragma once
#ifndef HYDROSIG_CONNECTION_WRAPPER_HPP_INCLUDED
#define HYDROSIG_CONNECTION_WRAPPER_HPP_INCLUDED

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
#include "wrappers/wrapper_helpers.h"

#include "connections/connection_0.hpp"
#include "connections/connection_1.hpp"
#include "connections/connection_2.hpp"
#include "connections/connection_3.hpp"
#include "connections/connection_4.hpp"
#include "connections/connection_5.hpp"
#include "connections/connection_6.hpp"
#include "connections/connection_7.hpp"
#include "connections/connection_8.hpp"


HYDROSIG_NAMESPACE_BEGIN


/**
 * Convenience connection wrappers - portable syntax.
 * --------------------------------------------------
 */

HYDROSIG_TEMPLATE_PORTABLE_WRAPPER_BASE
/**
 * @brief   Convenience wrapper for connections with eight arguments.
 * @details Connections with less arguments are specialized types of
 *          this template.
 */
class connection
        : public connection_8<HYDROSIG_8_ARG>
{
public:
    connection(const connection_8<HYDROSIG_8_ARG> &src)
        : connection_8<HYDROSIG_8_ARG>(src)
    {}
};

HYDROSIG_TEMPLATE_0_ARG
/**
 * @brief   Convenience wrapper for connections with zero arguments.
 * @details Specialized from the template wrapper for eight arguments.
 */
class connection<HYDROSIG_PORTABLE_WRAPPER_0_ARG>
      : public connection_0<HYDROSIG_0_ARG>
{
public:
    connection(const connection_0<HYDROSIG_0_ARG> &src)
        : connection_0<HYDROSIG_0_ARG>(src)
    {}
};

HYDROSIG_TEMPLATE_1_ARG
/**
 * @brief   Convenience wrapper for connections with one arguments.
 * @details Specialized from the template wrapper for eight arguments.
 */
class connection<HYDROSIG_PORTABLE_WRAPPER_1_ARG>
      : public connection_1<HYDROSIG_1_ARG>
{
public:
    connection(const connection_1<HYDROSIG_1_ARG> &src)
        : connection_1<HYDROSIG_1_ARG>(src)
    {}
};

HYDROSIG_TEMPLATE_2_ARG
/**
 * @brief   Convenience wrapper for connections with two arguments.
 * @details Specialized from the template wrapper for eight arguments.
 */
class connection<HYDROSIG_PORTABLE_WRAPPER_2_ARG>
      : public connection_2<HYDROSIG_2_ARG>
{
public:
    connection(const connection_2<HYDROSIG_2_ARG> &src)
        : connection_2<HYDROSIG_2_ARG>(src)
    {}
};

HYDROSIG_TEMPLATE_3_ARG
/**
 * @brief   Convenience wrapper for connections with three arguments.
 * @details Specialized from the template wrapper for eight arguments.
 */
class connection<HYDROSIG_PORTABLE_WRAPPER_3_ARG>
      : public connection_3<HYDROSIG_3_ARG>
{
public:
    connection(const connection_3<HYDROSIG_3_ARG> &src)
        : connection_3<HYDROSIG_3_ARG>(src)
    {}
};

HYDROSIG_TEMPLATE_4_ARG
/**
 * @brief   Convenience wrapper for connections with four arguments.
 * @details Specialized from the template wrapper for eight arguments.
 */
class connection<HYDROSIG_PORTABLE_WRAPPER_4_ARG>
      : public connection_4<HYDROSIG_4_ARG>
{
public:
    connection(const connection_4<HYDROSIG_4_ARG> &src)
        : connection_4<HYDROSIG_4_ARG>(src)
    {}
};

HYDROSIG_TEMPLATE_5_ARG
/**
 * @brief   Convenience wrapper for connections with five arguments.
 * @details Specialized from the template wrapper for eight arguments.
 */
class connection<HYDROSIG_PORTABLE_WRAPPER_5_ARG>
      : public connection_5<HYDROSIG_5_ARG>
{
public:
    connection(const connection_5<HYDROSIG_5_ARG> &src)
        : connection_5<HYDROSIG_5_ARG>(src)
    {}
};

HYDROSIG_TEMPLATE_6_ARG
/**
 * @brief   Convenience wrapper for connections with six arguments.
 * @details Specialized from the template wrapper for eight arguments.
 */
class connection<HYDROSIG_PORTABLE_WRAPPER_6_ARG>
      : public connection_6<HYDROSIG_6_ARG>
{
public:
    connection(const connection_6<HYDROSIG_6_ARG> &src)
        : connection_6<HYDROSIG_6_ARG>(src)
    {}
};

HYDROSIG_TEMPLATE_7_ARG
/**
 * @brief   Convenience wrapper for connections with seven arguments.
 * @details Specialized from the template wrapper for eight arguments.
 */
class connection<HYDROSIG_PORTABLE_WRAPPER_7_ARG>
      : public connection_7<HYDROSIG_7_ARG>
{
public:
    connection(const connection_7<HYDROSIG_7_ARG> &src)
        : connection_7<HYDROSIG_7_ARG>(src)
    {}
};


/**
 * Convenience connection wrappers - elegant syntax.
 * -------------------------------------------------
 */

HYDROSIG_TEMPLATE_0_ARG
/**
 * @brief   Convenience wrapper for connections with no arguments.
 * @details This template version uses the elegant syntax.
 */
class connection<HYDROSIG_ELEGANT_WRAPPER_0_ARG>
    : public connection_0<HYDROSIG_0_ARG>
{
public:
    connection(const connection_0<HYDROSIG_0_ARG> &src)
        : connection_0<HYDROSIG_0_ARG>(src)
    {}
};

HYDROSIG_TEMPLATE_1_ARG
/**
 * @brief   Convenience wrapper for connections with one arguments.
 * @details This template version uses the elegant syntax.
 */
class connection<HYDROSIG_ELEGANT_WRAPPER_1_ARG>
    : public connection_1<HYDROSIG_1_ARG>
{
public:
    connection(const connection_1<HYDROSIG_1_ARG> &src)
        : connection_1<HYDROSIG_1_ARG>(src)
    {}
};

HYDROSIG_TEMPLATE_2_ARG
/**
 * @brief   Convenience wrapper for connections with two arguments.
 * @details This template version uses the elegant syntax.
 */
class connection<HYDROSIG_ELEGANT_WRAPPER_2_ARG>
    : public connection_2<HYDROSIG_2_ARG>
{
public:
    connection(const connection_2<HYDROSIG_2_ARG> &src)
        : connection_2<HYDROSIG_2_ARG>(src)
    {}
};

HYDROSIG_TEMPLATE_3_ARG
/**
 * @brief   Convenience wrapper for connections with three arguments.
 * @details This template version uses the elegant syntax.
 */
class connection<HYDROSIG_ELEGANT_WRAPPER_3_ARG>
    : public connection_3<HYDROSIG_3_ARG>
{
public:
    connection(const connection_3<HYDROSIG_3_ARG> &src)
        : connection_3<HYDROSIG_3_ARG>(src)
    {}
};

HYDROSIG_TEMPLATE_4_ARG
/**
 * @brief   Convenience wrapper for connections with four arguments.
 * @details This template version uses the elegant syntax.
 */
class connection<HYDROSIG_ELEGANT_WRAPPER_4_ARG>
    : public connection_4<HYDROSIG_4_ARG>
{
public:
    connection(const connection_4<HYDROSIG_4_ARG> &src)
        : connection_4<HYDROSIG_4_ARG>(src)
    {}
};

HYDROSIG_TEMPLATE_5_ARG
/**
 * @brief   Convenience wrapper for connections with five arguments.
 * @details This template version uses the elegant syntax.
 */
class connection<HYDROSIG_ELEGANT_WRAPPER_5_ARG>
    : public connection_5<HYDROSIG_5_ARG>
{
public:
    connection(const connection_5<HYDROSIG_5_ARG> &src)
        : connection_5<HYDROSIG_5_ARG>(src)
    {}
};

HYDROSIG_TEMPLATE_6_ARG
/**
 * @brief   Convenience wrapper for connections with six arguments.
 * @details This template version uses the elegant syntax.
 */
class connection<HYDROSIG_ELEGANT_WRAPPER_6_ARG>
    : public connection_6<HYDROSIG_6_ARG>
{
public:
    connection(const connection_6<HYDROSIG_6_ARG> &src)
        : connection_6<HYDROSIG_6_ARG>(src)
    {}
};

HYDROSIG_TEMPLATE_7_ARG
/**
 * @brief   Convenience wrapper for connections with seven arguments.
 * @details This template version uses the elegant syntax.
 */
class connection<HYDROSIG_ELEGANT_WRAPPER_7_ARG>
    : public connection_7<HYDROSIG_7_ARG>
{
public:
    connection(const connection_7<HYDROSIG_7_ARG> &src)
        : connection_7<HYDROSIG_7_ARG>(src)
    {}
};

HYDROSIG_TEMPLATE_8_ARG
/**
 * @brief   Convenience wrapper for connections with eight arguments.
 * @details This template version uses the elegant syntax.
 */
class connection<HYDROSIG_ELEGANT_WRAPPER_8_ARG>
    : public connection_8<HYDROSIG_8_ARG>
{
public:
    connection(const connection_8<HYDROSIG_8_ARG> &src)
        : connection_8<HYDROSIG_8_ARG>(src)
    {}
};

/**
 * Convenience scoped_connection wrappers - portable syntax.
 * ---------------------------------------------------------
 */

HYDROSIG_TEMPLATE_PORTABLE_WRAPPER_BASE
/**
 * @brief   Convenience wrapper for scoped_connections with eight arguments.
 * @details Connections with less arguments are specialized types of
 *          this template.
 */
class scoped_connection
        : public scoped_connection_8<HYDROSIG_8_ARG>
{
public:
    scoped_connection(const connection_8<HYDROSIG_8_ARG> &src)
        : scoped_connection_8<HYDROSIG_8_ARG>(src)
    {}
};

HYDROSIG_TEMPLATE_0_ARG
/**
 * @brief   Convenience wrapper for scoped_connections with zero arguments.
 * @details Specialized from the template wrapper for eight arguments.
 */
class scoped_connection<HYDROSIG_PORTABLE_WRAPPER_0_ARG>
      : public scoped_connection_0<HYDROSIG_0_ARG>
{
public:
    scoped_connection(const connection_0<HYDROSIG_0_ARG> &src)
        : scoped_connection_0<HYDROSIG_0_ARG>(src)
    {}
};

HYDROSIG_TEMPLATE_1_ARG
/**
 * @brief   Convenience wrapper for scoped_connections with one arguments.
 * @details Specialized from the template wrapper for eight arguments.
 */
class scoped_connection<HYDROSIG_PORTABLE_WRAPPER_1_ARG>
      : public scoped_connection_1<HYDROSIG_1_ARG>
{
public:
    scoped_connection(const connection_1<HYDROSIG_1_ARG> &src)
        : scoped_connection_1<HYDROSIG_1_ARG>(src)
    {}
};

HYDROSIG_TEMPLATE_2_ARG
/**
 * @brief   Convenience wrapper for scoped_connections with two arguments.
 * @details Specialized from the template wrapper for eight arguments.
 */
class scoped_connection<HYDROSIG_PORTABLE_WRAPPER_2_ARG>
      : public scoped_connection_2<HYDROSIG_2_ARG>
{
public:
    scoped_connection(const connection_2<HYDROSIG_2_ARG> &src)
        : scoped_connection_2<HYDROSIG_2_ARG>(src)
    {}
};

HYDROSIG_TEMPLATE_3_ARG
/**
 * @brief   Convenience wrapper for scoped_connections with three arguments.
 * @details Specialized from the template wrapper for eight arguments.
 */
class scoped_connection<HYDROSIG_PORTABLE_WRAPPER_3_ARG>
      : public scoped_connection_3<HYDROSIG_3_ARG>
{
public:
    scoped_connection(const connection_3<HYDROSIG_3_ARG> &src)
        : scoped_connection_3<HYDROSIG_3_ARG>(src)
    {}
};

HYDROSIG_TEMPLATE_4_ARG
/**
 * @brief   Convenience wrapper for scoped_connections with four arguments.
 * @details Specialized from the template wrapper for eight arguments.
 */
class scoped_connection<HYDROSIG_PORTABLE_WRAPPER_4_ARG>
      : public scoped_connection_4<HYDROSIG_4_ARG>
{
public:
    scoped_connection(const connection_4<HYDROSIG_4_ARG> &src)
        : scoped_connection_4<HYDROSIG_4_ARG>(src)
    {}
};

HYDROSIG_TEMPLATE_5_ARG
/**
 * @brief   Convenience wrapper for scoped_connections with five arguments.
 * @details Specialized from the template wrapper for eight arguments.
 */
class scoped_connection<HYDROSIG_PORTABLE_WRAPPER_5_ARG>
      : public scoped_connection_5<HYDROSIG_5_ARG>
{
public:
    scoped_connection(const connection_5<HYDROSIG_5_ARG> &src)
        : scoped_connection_5<HYDROSIG_5_ARG>(src)
    {}
};

HYDROSIG_TEMPLATE_6_ARG
/**
 * @brief   Convenience wrapper for scoped_connections with six arguments.
 * @details Specialized from the template wrapper for eight arguments.
 */
class scoped_connection<HYDROSIG_PORTABLE_WRAPPER_6_ARG>
      : public scoped_connection_6<HYDROSIG_6_ARG>
{
public:
    scoped_connection(const connection_6<HYDROSIG_6_ARG> &src)
        : scoped_connection_6<HYDROSIG_6_ARG>(src)
    {}
};

HYDROSIG_TEMPLATE_7_ARG
/**
 * @brief   Convenience wrapper for scoped_connections with seven arguments.
 * @details Specialized from the template wrapper for eight arguments.
 */
class scoped_connection<HYDROSIG_PORTABLE_WRAPPER_7_ARG>
      : public scoped_connection_7<HYDROSIG_7_ARG>
{
public:
    scoped_connection(const connection_7<HYDROSIG_7_ARG> &src)
        : scoped_connection_7<HYDROSIG_7_ARG>(src)
    {}
};

/**
 * Convenience scoped_connection wrappers - elegant syntax.
 * --------------------------------------------------------
 */

HYDROSIG_TEMPLATE_0_ARG
/**
 * @brief   Convenience wrapper for scoped_connections with no arguments.
 * @details This template version uses the elegant syntax.
 */
class scoped_connection<HYDROSIG_ELEGANT_WRAPPER_0_ARG>
    : public scoped_connection_0<HYDROSIG_0_ARG>
{
public:
    scoped_connection(const connection_0<HYDROSIG_0_ARG> &src)
        : scoped_connection_0<HYDROSIG_0_ARG>(src)
    {}
};

HYDROSIG_TEMPLATE_1_ARG
/**
 * @brief   Convenience wrapper for scoped_connections with one arguments.
 * @details This template version uses the elegant syntax.
 */
class scoped_connection<HYDROSIG_ELEGANT_WRAPPER_1_ARG>
    : public scoped_connection_1<HYDROSIG_1_ARG>
{
public:
    scoped_connection(const connection_1<HYDROSIG_1_ARG> &src)
        : scoped_connection_1<HYDROSIG_1_ARG>(src)
    {}
};

HYDROSIG_TEMPLATE_2_ARG
/**
 * @brief   Convenience wrapper for scoped_connections with two arguments.
 * @details This template version uses the elegant syntax.
 */
class scoped_connection<HYDROSIG_ELEGANT_WRAPPER_2_ARG>
    : public scoped_connection_2<HYDROSIG_2_ARG>
{
public:
    scoped_connection(const connection_2<HYDROSIG_2_ARG> &src)
        : scoped_connection_2<HYDROSIG_2_ARG>(src)
    {}
};

HYDROSIG_TEMPLATE_3_ARG
/**
 * @brief   Convenience wrapper for scoped_connections with three arguments.
 * @details This template version uses the elegant syntax.
 */
class scoped_connection<HYDROSIG_ELEGANT_WRAPPER_3_ARG>
    : public scoped_connection_3<HYDROSIG_3_ARG>
{
public:
    scoped_connection(const connection_3<HYDROSIG_3_ARG> &src)
        : scoped_connection_3<HYDROSIG_3_ARG>(src)
    {}
};

HYDROSIG_TEMPLATE_4_ARG
/**
 * @brief   Convenience wrapper for scoped_connections with four arguments.
 * @details This template version uses the elegant syntax.
 */
class scoped_connection<HYDROSIG_ELEGANT_WRAPPER_4_ARG>
    : public scoped_connection_4<HYDROSIG_4_ARG>
{
public:
    scoped_connection(const connection_4<HYDROSIG_4_ARG> &src)
        : scoped_connection_4<HYDROSIG_4_ARG>(src)
    {}
};

HYDROSIG_TEMPLATE_5_ARG
/**
 * @brief   Convenience wrapper for scoped_connections with five arguments.
 * @details This template version uses the elegant syntax.
 */
class scoped_connection<HYDROSIG_ELEGANT_WRAPPER_5_ARG>
    : public scoped_connection_5<HYDROSIG_5_ARG>
{
public:
    scoped_connection(const connection_5<HYDROSIG_5_ARG> &src)
        : scoped_connection_5<HYDROSIG_5_ARG>(src)
    {}
};

HYDROSIG_TEMPLATE_6_ARG
/**
 * @brief   Convenience wrapper for scoped_connections with six arguments.
 * @details This template version uses the elegant syntax.
 */
class scoped_connection<HYDROSIG_ELEGANT_WRAPPER_6_ARG>
    : public scoped_connection_6<HYDROSIG_6_ARG>
{
public:
    scoped_connection(const connection_6<HYDROSIG_6_ARG> &src)
        : scoped_connection_6<HYDROSIG_6_ARG>(src)
    {}
};

HYDROSIG_TEMPLATE_7_ARG
/**
 * @brief   Convenience wrapper for scoped_connections with seven arguments.
 * @details This template version uses the elegant syntax.
 */
class scoped_connection<HYDROSIG_ELEGANT_WRAPPER_7_ARG>
    : public scoped_connection_7<HYDROSIG_7_ARG>
{
public:
    scoped_connection(const connection_7<HYDROSIG_7_ARG> &src)
        : scoped_connection_7<HYDROSIG_7_ARG>(src)
    {}
};

HYDROSIG_TEMPLATE_8_ARG
/**
 * @brief   Convenience wrapper for connections with eight arguments.
 * @details This template version uses the elegant syntax.
 */
class scoped_connection<HYDROSIG_ELEGANT_WRAPPER_8_ARG>
    : public scoped_connection_8<HYDROSIG_8_ARG>
{
public:
    scoped_connection(const connection_8<HYDROSIG_8_ARG> &src)
        : scoped_connection_8<HYDROSIG_8_ARG>(src)
    {}
};


HYDROSIG_NAMESPACE_END


#endif // HYDROSIG_CONNECTION_WRAPPER_HPP_INCLUDED
