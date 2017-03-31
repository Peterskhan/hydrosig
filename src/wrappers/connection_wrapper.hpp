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

template<class Return_type,
         class Arg1_type = no_arg, class Arg2_type = no_arg, class Arg3_type = no_arg,
         class Arg4_type = no_arg, class Arg5_type = no_arg, class Arg6_type = no_arg,
         class Arg7_type = no_arg, class Arg8_type = no_arg>
/**
 * @brief   Convenience wrapper for connections with eight arguments.
 * @details Connections with less arguments are specialized types of
 *          this template.
 */
class connection
        : public connection_8<Return_type,
                              Arg1_type, Arg2_type, Arg3_type,
                              Arg4_type, Arg5_type, Arg6_type,
                              Arg7_type, Arg8_type>
{

};


template<class Return_type>
/**
 * @brief   Convenience wrapper for connections with zero arguments.
 * @details Specialized from the template wrapper for eight arguments.
 */
class connection<Return_type,
                 no_arg, no_arg, no_arg,
                 no_arg, no_arg, no_arg,
                 no_arg, no_arg>
      : public connection_0<Return_type>
{

};

template<class Return_type,
         class Arg1_type>
/**
 * @brief   Convenience wrapper for connections with one arguments.
 * @details Specialized from the template wrapper for eight arguments.
 */
class connection<Return_type,
                 Arg1_type,
                 no_arg, no_arg, no_arg,
                 no_arg, no_arg, no_arg,
                 no_arg>
      : public connection_1<Return_type,
                            Arg1_type>
{

};

template<class Return_type,
         class Arg1_type, class Arg2_type>
/**
 * @brief   Convenience wrapper for connections with two arguments.
 * @details Specialized from the template wrapper for eight arguments.
 */
class connection<Return_type,
                 Arg1_type, Arg2_type,
                 no_arg, no_arg, no_arg,
                 no_arg, no_arg, no_arg>
      : public connection_2<Return_type,
                            Arg1_type, Arg2_type>
{

};

template<class Return_type,
         class Arg1_type, class Arg2_type, class Arg3_type>
/**
 * @brief   Convenience wrapper for connections with three arguments.
 * @details Specialized from the template wrapper for eight arguments.
 */
class connection<Return_type,
                 Arg1_type, Arg2_type, Arg3_type,
                 no_arg, no_arg, no_arg,
                 no_arg, no_arg>
      : public connection_3<Return_type,
                            Arg1_type, Arg2_type, Arg3_type>
{

};

template<class Return_type,
         class Arg1_type, class Arg2_type, class Arg3_type,
         class Arg4_type>
/**
 * @brief   Convenience wrapper for connections with four arguments.
 * @details Specialized from the template wrapper for eight arguments.
 */
class connection<Return_type,
                 Arg1_type, Arg2_type, Arg3_type,
                 Arg4_type,
                 no_arg, no_arg, no_arg,
                 no_arg>
      : public connection_4<Return_type,
                            Arg1_type, Arg2_type, Arg3_type,
                            Arg4_type>
{

};

template<class Return_type,
         class Arg1_type, class Arg2_type, class Arg3_type,
         class Arg4_type, class Arg5_type>
/**
 * @brief   Convenience wrapper for connections with five arguments.
 * @details Specialized from the template wrapper for eight arguments.
 */
class connection<Return_type,
                 Arg1_type, Arg2_type, Arg3_type,
                 Arg4_type, Arg5_type,
                 no_arg, no_arg, no_arg>
      : public connection_5<Return_type,
                            Arg1_type, Arg2_type, Arg3_type,
                            Arg4_type, Arg5_type>
{

};

template<class Return_type,
         class Arg1_type, class Arg2_type, class Arg3_type,
         class Arg4_type, class Arg5_type, class Arg6_type>
/**
 * @brief   Convenience wrapper for connections with six arguments.
 * @details Specialized from the template wrapper for eight arguments.
 */
class connection<Return_type,
                 Arg1_type, Arg2_type, Arg3_type,
                 Arg4_type, Arg5_type, Arg6_type,
                 no_arg, no_arg>
      : public connection_6<Return_type,
                            Arg1_type, Arg2_type, Arg3_type,
                            Arg4_type, Arg5_type, Arg6_type>
{

};

template<class Return_type,
         class Arg1_type, class Arg2_type, class Arg3_type,
         class Arg4_type, class Arg5_type, class Arg6_type,
         class Arg7_type>
/**
 * @brief   Convenience wrapper for connections with seven arguments.
 * @details Specialized from the template wrapper for eight arguments.
 */
class connection<Return_type,
                 Arg1_type, Arg2_type, Arg3_type,
                 Arg4_type, Arg5_type, Arg6_type,
                 Arg7_type,
                 no_arg>
      : public connection_7<Return_type,
                            Arg1_type, Arg2_type, Arg3_type,
                            Arg4_type, Arg5_type, Arg6_type,
                            Arg7_type>
{

};


/**
 * Convenience connection wrappers - elegant syntax.
 * -------------------------------------------------
 */

template<class Return_type>
/**
 * @brief   Convenience wrapper for connections with no arguments.
 * @details This template version uses the elegant syntax.
 */
class connection<Return_type()>
    : public connection_0<Return_type>
{

};

template<class Return_type,
         class Arg1_type>
/**
 * @brief   Convenience wrapper for connections with one arguments.
 * @details This template version uses the elegant syntax.
 */
class connection<Return_type(Arg1_type)>
    : public connection_1<Return_type,
                          Arg1_type>
{

};

template<class Return_type,
         class Arg1_type, class Arg2_type>
/**
 * @brief   Convenience wrapper for connections with two arguments.
 * @details This template version uses the elegant syntax.
 */
class connection<Return_type(Arg1_type,Arg2_type)>
    : public connection_2<Return_type,
                          Arg1_type,Arg2_type>
{

};

template<class Return_type,
         class Arg1_type, class Arg2_type, class Arg3_type>
/**
 * @brief   Convenience wrapper for connections with three arguments.
 * @details This template version uses the elegant syntax.
 */
class connection<Return_type(Arg1_type,Arg2_type,Arg3_type)>
    : public connection_3<Return_type,
                          Arg1_type,Arg2_type,Arg3_type>
{

};

template<class Return_type,
         class Arg1_type, class Arg2_type, class Arg3_type,
         class Arg4_type>
/**
 * @brief   Convenience wrapper for connections with four arguments.
 * @details This template version uses the elegant syntax.
 */
class connection<Return_type(Arg1_type,Arg2_type,Arg3_type,
                             Arg4_type)>
    : public connection_4<Return_type,
                          Arg1_type,Arg2_type,Arg3_type,
                          Arg4_type>
{

};

template<class Return_type,
         class Arg1_type, class Arg2_type, class Arg3_type,
         class Arg4_type, class Arg5_type>
/**
 * @brief   Convenience wrapper for connections with five arguments.
 * @details This template version uses the elegant syntax.
 */
class connection<Return_type(Arg1_type,Arg2_type,Arg3_type,
                             Arg4_type,Arg5_type)>
    : public connection_5<Return_type,
                          Arg1_type,Arg2_type,Arg3_type,
                          Arg4_type,Arg5_type>
{

};

template<class Return_type,
         class Arg1_type, class Arg2_type, class Arg3_type,
         class Arg4_type, class Arg5_type, class Arg6_type>
/**
 * @brief   Convenience wrapper for connections with six arguments.
 * @details This template version uses the elegant syntax.
 */
class connection<Return_type(Arg1_type,Arg2_type,Arg3_type,
                             Arg4_type,Arg5_type,Arg6_type)>
    : public connection_6<Return_type,
                          Arg1_type,Arg2_type,Arg3_type,
                          Arg4_type,Arg5_type,Arg6_type>
{

};

template<class Return_type,
         class Arg1_type, class Arg2_type, class Arg3_type,
         class Arg4_type, class Arg5_type, class Arg6_type,
         class Arg7_type>
/**
 * @brief   Convenience wrapper for connections with seven arguments.
 * @details This template version uses the elegant syntax.
 */
class connection<Return_type(Arg1_type,Arg2_type,Arg3_type,
                             Arg4_type,Arg5_type,Arg6_type,
                             Arg7_type)>
    : public connection_7<Return_type,
                          Arg1_type,Arg2_type,Arg3_type,
                          Arg4_type,Arg5_type,Arg6_type,
                          Arg7_type>
{

};

template<class Return_type,
         class Arg1_type, class Arg2_type, class Arg3_type,
         class Arg4_type, class Arg5_type, class Arg6_type,
         class Arg7_type, class Arg8_type>
/**
 * @brief   Convenience wrapper for connections with eight arguments.
 * @details This template version uses the elegant syntax.
 */
class connection<Return_type(Arg1_type,Arg2_type,Arg3_type,
                             Arg4_type,Arg5_type,Arg6_type,
                             Arg7_type,Arg8_type)>
    : public connection_8<Return_type,
                          Arg1_type,Arg2_type,Arg3_type,
                          Arg4_type,Arg5_type,Arg6_type,
                          Arg7_type,Arg8_type>
{

};


HYDROSIG_NAMESPACE_END


#endif // HYDROSIG_CONNECTION_WRAPPER_HPP_INCLUDED
