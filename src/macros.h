#pragma once
#ifndef HYDROSIG_MACROS_H_INCLUDED
#define HYDROSIG_MACROS_H_INCLUDED

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

#include "src/config.h"


/**
 * Namespace boundary macros:
 * --------------------------
 */

/*******************************************************
 * Begins the hydrosig namespace. All contents of the
 * library are defined in this namespace.
 ******************************************************/
#ifdef  HYDROSIG_ENABLE_NAMESPACE
# define HYDROSIG_NAMESPACE_BEGIN    namespace hydrosig {
#else
# define HYDROSIG_NAMESPACE_BEGIN    ;
#endif

/*******************************************************
 * Closes the hydrosig namespace.
 ******************************************************/
#ifdef  HYDROSIG_ENABLE_NAMESPACE
# define HYDROSIG_NAMESPACE_END      }
#else
# define HYDROSIG_NAMESPACE_END      ;
#endif




/**
 * Multithreading synchrosisation macros:
 * --------------------------------------
 */

/****************************************************************
 * Defines the beginning of a data-race protected code block.
 ***************************************************************/
#ifdef HYDROSIG_SYNCHRONISE_THREADS
# define HYDROSIG_PROTECTED_BLOCK_BEGIN \
         HYDROSIG_LOCK_GUARD_TYPE guard(this->m_mutex);
#else
# define HYDROSIG_PROTECTED_BLOCK_BEGIN \
         ;
#endif

/****************************************************************
 * Defines the end of a data-race protected code block.
 ***************************************************************/
#ifdef HYDROSIG_SYNCHRONISE_THREADS
# define HYDROSIG_PROTECTED_BLOCK_END \
         guard.unlock();
#else
# define HYDROSIG_PROTECTED_BLOCK_END \
         ;
#endif

/****************************************************************
 * Defines the beginning of a data-race protected code block,
 * using a remote object of the same class.
 ***************************************************************/
#ifdef HYDROSIG_SYNCHRONISE_THREADS
# define HYDROSIG_REMOTE_PROTECTED_BLOCK_BEGIN \
         HYDROSIG_LOCK_GUARD_TYPE remoteGuard(src.m_mutex);
#else
# define HYDROSIG_REMOTE_PROTECTED_BLOCK_BEGIN \
         ;
#endif

/****************************************************************
 * Defines the end of a data-race protected code block,
 * using a remote object of the same class.
 ***************************************************************/
#ifdef HYDROSIG_SYNCHRONISE_THREADS
# define HYDROSIG_REMOTE_PROTECTED_BLOCK_END \
         remoteGuard.unlock();
#else
# define HYDROSIG_REMOTE_PROTECTED_BLOCK_END \
         ;
#endif




/**
 * Template declaration macros:
 * ----------------------------
 */

/************************************************************
 * Template declaration for zero arguments.
 ***********************************************************/
#define HYDROSIG_TEMPLATE_0_ARG                             \
                                                            \
template<class Return_type>                                 \

/************************************************************
 * Template declaration for one arguments.
 ***********************************************************/
#define HYDROSIG_TEMPLATE_1_ARG                             \
                                                            \
template<class Return_type,                                 \
         class Arg1_type>                                   \

/************************************************************
 * Template declaration for two arguments.
 ***********************************************************/
#define HYDROSIG_TEMPLATE_2_ARG                             \
                                                            \
template<class Return_type,                                 \
         class Arg1_type, class Arg2_type>                  \

/************************************************************
 * Template declaration for three arguments.
 ***********************************************************/
#define HYDROSIG_TEMPLATE_3_ARG                             \
                                                            \
template<class Return_type,                                 \
         class Arg1_type, class Arg2_type, class Arg3_type> \

/************************************************************
 * Template declaration for four arguments.
 ***********************************************************/
#define HYDROSIG_TEMPLATE_4_ARG                             \
                                                            \
template<class Return_type,                                 \
         class Arg1_type, class Arg2_type, class Arg3_type, \
         class Arg4_type>                                   \

/************************************************************
 * Template declaration for five arguments.
 ***********************************************************/
#define HYDROSIG_TEMPLATE_5_ARG                             \
                                                            \
template<class Return_type,                                 \
         class Arg1_type, class Arg2_type, class Arg3_type, \
         class Arg4_type, class Arg5_type>                  \

/************************************************************
 * Template declaration for six arguments.
 ***********************************************************/
#define HYDROSIG_TEMPLATE_6_ARG                             \
                                                            \
template<class Return_type,                                 \
         class Arg1_type, class Arg2_type, class Arg3_type, \
         class Arg4_type, class Arg5_type, class Arg6_type> \

/************************************************************
 * Template declaration for seven arguments.
 ***********************************************************/
#define HYDROSIG_TEMPLATE_7_ARG                             \
                                                            \
template<class Return_type,                                 \
         class Arg1_type, class Arg2_type, class Arg3_type, \
         class Arg4_type, class Arg5_type, class Arg6_type, \
         class Arg7_type>                                   \

/************************************************************
 * Template declaration for eight arguments.
 ***********************************************************/
#define HYDROSIG_TEMPLATE_8_ARG                             \
                                                            \
template<class Return_type,                                 \
         class Arg1_type, class Arg2_type, class Arg3_type, \
         class Arg4_type, class Arg5_type, class Arg6_type, \
         class Arg7_type, class Arg8_type>                  \




/**
 * Template declaration macros with object-type:
 * ---------------------------------------------
 */

/****************************************************************
 * Template declaration for zero arguments, with object-type.
 ***************************************************************/
#define HYDROSIG_TEMPLATE_OBJECT_0_ARG                          \
                                                                \
template<class Object_type,                                     \
         class Return_type>                                     \

/****************************************************************
 * Template declaration for one arguments, with object-type.
 ***************************************************************/
#define HYDROSIG_TEMPLATE_OBJECT_1_ARG                          \
                                                                \
template<class Object_type,                                     \
         class Return_type,                                     \
         class Arg1_type>                                       \

/****************************************************************
 * Template declaration for two arguments, with object-type.
 ***************************************************************/
#define HYDROSIG_TEMPLATE_OBJECT_2_ARG                          \
                                                                \
template<class Object_type,                                     \
         class Return_type,                                     \
         class Arg1_type, class Arg2_type>                      \

/****************************************************************
 * Template declaration for three arguments, with object-type.
 ***************************************************************/
#define HYDROSIG_TEMPLATE_OBJECT_3_ARG                          \
                                                                \
template<class Object_type,                                     \
         class Return_type,                                     \
         class Arg1_type, class Arg2_type, class Arg3_type>     \

/****************************************************************
 * Template declaration for four arguments, with object-type.
 ***************************************************************/
#define HYDROSIG_TEMPLATE_OBJECT_4_ARG                          \
                                                                \
template<class Object_type,                                     \
         class Return_type,                                     \
         class Arg1_type, class Arg2_type, class Arg3_type,     \
         class Arg4_type>                                       \

/****************************************************************
 * Template declaration for five arguments, with object-type.
 ***************************************************************/
#define HYDROSIG_TEMPLATE_OBJECT_5_ARG                          \
                                                                \
template<class Object_type,                                     \
         class Return_type,                                     \
         class Arg1_type, class Arg2_type, class Arg3_type,     \
         class Arg4_type, class Arg5_type>                      \

/****************************************************************
 * Template declaration for six arguments, with object-type.
 ***************************************************************/
#define HYDROSIG_TEMPLATE_OBJECT_6_ARG                          \
                                                                \
template<class Object_type,                                     \
         class Return_type,                                     \
         class Arg1_type, class Arg2_type, class Arg3_type,     \
         class Arg4_type, class Arg5_type, class Arg6_type>     \

/****************************************************************
 * Template declaration for seven arguments, with object-type.
 ***************************************************************/
#define HYDROSIG_TEMPLATE_OBJECT_7_ARG                          \
                                                                \
template<class Object_type,                                     \
         class Return_type,                                     \
         class Arg1_type, class Arg2_type, class Arg3_type,     \
         class Arg4_type, class Arg5_type, class Arg6_type,     \
         class Arg7_type>                                       \

/****************************************************************
 * Template declaration for eight arguments, with object-type.
 ***************************************************************/
#define HYDROSIG_TEMPLATE_OBJECT_8_ARG                          \
                                                                \
template<class Object_type,                                     \
         class Return_type,                                     \
         class Arg1_type, class Arg2_type, class Arg3_type,     \
         class Arg4_type, class Arg5_type, class Arg6_type,     \
         class Arg7_type, class Arg8_type>                      \




/**
 * Template declaration macros with callable-type:
 * -----------------------------------------------
 */

/****************************************************************
 * Template declaration for zero arguments, with callable-type.
 ***************************************************************/
#define HYDROSIG_TEMPLATE_CALLABLE_0_ARG                        \
                                                                \
template<class Callable_type,                                   \
         class Return_type>                                     \

/****************************************************************
 * Template declaration for one arguments, with callable-type.
 ***************************************************************/
#define HYDROSIG_TEMPLATE_CALLABLE_1_ARG                        \
                                                                \
template<class Callable_type,                                   \
         class Return_type,                                     \
         class Arg1_type>                                       \

/****************************************************************
 * Template declaration for two arguments, with callable-type.
 ***************************************************************/
#define HYDROSIG_TEMPLATE_CALLABLE_2_ARG                        \
                                                                \
template<class Callable_type,                                   \
         class Return_type,                                     \
         class Arg1_type, class Arg2_type>                      \

/****************************************************************
 * Template declaration for three arguments, with callable-type.
 ***************************************************************/
#define HYDROSIG_TEMPLATE_CALLABLE_3_ARG                        \
                                                                \
template<class Callable_type,                                   \
         class Return_type,                                     \
         class Arg1_type, class Arg2_type, class Arg3_type>     \

/****************************************************************
 * Template declaration for four arguments, with callable-type.
 ***************************************************************/
#define HYDROSIG_TEMPLATE_CALLABLE_4_ARG                        \
                                                                \
template<class Callable_type,                                   \
         class Return_type,                                     \
         class Arg1_type, class Arg2_type, class Arg3_type,     \
         class Arg4_type>                                       \

/****************************************************************
 * Template declaration for five arguments, with callable-type.
 ***************************************************************/
#define HYDROSIG_TEMPLATE_CALLABLE_5_ARG                        \
                                                                \
template<class Callable_type,                                   \
         class Return_type,                                     \
         class Arg1_type, class Arg2_type, class Arg3_type,     \
         class Arg4_type, class Arg5_type>                      \

/****************************************************************
 * Template declaration for six arguments, with callable-type.
 ***************************************************************/
#define HYDROSIG_TEMPLATE_CALLABLE_6_ARG                        \
                                                                \
template<class Callable_type,                                   \
         class Return_type,                                     \
         class Arg1_type, class Arg2_type, class Arg3_type,     \
         class Arg4_type, class Arg5_type, class Arg6_type>     \

/****************************************************************
 * Template declaration for seven arguments, with callable-type.
 ***************************************************************/
#define HYDROSIG_TEMPLATE_CALLABLE_7_ARG                        \
                                                                \
template<class Callable_type,                                   \
         class Return_type,                                     \
         class Arg1_type, class Arg2_type, class Arg3_type,     \
         class Arg4_type, class Arg5_type, class Arg6_type,     \
         class Arg7_type>                                       \

/****************************************************************
 * Template declaration for eight arguments, with callable-type.
 ***************************************************************/
#define HYDROSIG_TEMPLATE_CALLABLE_8_ARG                        \
                                                                \
template<class Callable_type,                                   \
         class Return_type,                                     \
         class Arg1_type, class Arg2_type, class Arg3_type,     \
         class Arg4_type, class Arg5_type, class Arg6_type,     \
         class Arg7_type, class Arg8_type>                      \




/**
 * Template parameter list macros:
 * -------------------------------
 */

/****************************************************************
 * Parameter list for zero arguments.
 ***************************************************************/
#define HYDROSIG_0_ARG      Return_type                         \

/****************************************************************
 * Parameter list for one arguments.
 ***************************************************************/
#define HYDROSIG_1_ARG      Return_type,                        \
                            Arg1_type                           \

/****************************************************************
 * Parameter list for two arguments.
 ***************************************************************/
#define HYDROSIG_2_ARG      Return_type,                        \
                            Arg1_type, Arg2_type                \

/****************************************************************
 * Parameter list for three arguments.
 ***************************************************************/
#define HYDROSIG_3_ARG      Return_type,                        \
                            Arg1_type, Arg2_type, Arg3_type     \

/****************************************************************
 * Parameter list for four arguments.
 ***************************************************************/
#define HYDROSIG_4_ARG      Return_type,                        \
                            Arg1_type, Arg2_type, Arg3_type,    \
                            Arg4_type                           \

/****************************************************************
 * Parameter list for five arguments.
 ***************************************************************/
#define HYDROSIG_5_ARG      Return_type,                        \
                            Arg1_type, Arg2_type, Arg3_type,    \
                            Arg4_type, Arg5_type                \

/****************************************************************
 * Parameter list for six arguments.
 ***************************************************************/
#define HYDROSIG_6_ARG      Return_type,                        \
                            Arg1_type, Arg2_type, Arg3_type,    \
                            Arg4_type, Arg5_type, Arg6_type     \

/****************************************************************
 * Parameter list for seven arguments.
 ***************************************************************/
#define HYDROSIG_7_ARG      Return_type,                        \
                            Arg1_type, Arg2_type, Arg3_type,    \
                            Arg4_type, Arg5_type, Arg6_type,    \
                            Arg7_type                           \

/****************************************************************
 * Parameter list for eight arguments.
 ***************************************************************/
#define HYDROSIG_8_ARG      Return_type,                        \
                            Arg1_type, Arg2_type, Arg3_type,    \
                            Arg4_type, Arg5_type, Arg6_type,    \
                            Arg7_type, Arg8_type                \




/**
 * Template parameter list macros with object-type:
 * ------------------------------------------------
 */

/************************************************************************
 * Parameter list for zero arguments, with object-type.
 ***********************************************************************/
#define HYDROSIG_OBJECT_0_ARG       Object_type,                        \
                                    Return_type                         \

/************************************************************************
 * Parameter list for one arguments, with object-type.
 ***********************************************************************/
#define HYDROSIG_OBJECT_1_ARG       Object_type,                        \
                                    Return_type,                        \
                                    Arg1_type                           \

/************************************************************************
 * Parameter list for two arguments, with object-type.
 ***********************************************************************/
#define HYDROSIG_OBJECT_2_ARG       Object_type,                        \
                                    Return_type,                        \
                                    Arg1_type, Arg2_type                \

/************************************************************************
 * Parameter list for three arguments, with object-type.
 ***********************************************************************/
#define HYDROSIG_OBJECT_3_ARG       Object_type,                        \
                                    Return_type,                        \
                                    Arg1_type, Arg2_type, Arg3_type     \

/************************************************************************
 * Parameter list for four arguments, with object-type.
 ***********************************************************************/
#define HYDROSIG_OBJECT_4_ARG       Object_type,                        \
                                    Return_type,                        \
                                    Arg1_type, Arg2_type, Arg3_type,    \
                                    Arg4_type                           \

/************************************************************************
 * Parameter list for five arguments, with object-type.
 ***********************************************************************/
#define HYDROSIG_OBJECT_5_ARG       Object_type,                        \
                                    Return_type,                        \
                                    Arg1_type, Arg2_type, Arg3_type,    \
                                    Arg4_type, Arg5_type                \

/************************************************************************
 * Parameter list for six arguments, with object-type.
 ***********************************************************************/
#define HYDROSIG_OBJECT_6_ARG       Object_type,                        \
                                    Return_type,                        \
                                    Arg1_type, Arg2_type, Arg3_type,    \
                                    Arg4_type, Arg5_type, Arg6_type     \

/************************************************************************
 * Parameter list for seven arguments, with object-type.
 ***********************************************************************/
#define HYDROSIG_OBJECT_7_ARG       Object_type,                        \
                                    Return_type,                        \
                                    Arg1_type, Arg2_type, Arg3_type,    \
                                    Arg4_type, Arg5_type, Arg6_type,    \
                                    Arg7_type                           \

/************************************************************************
 * Parameter list for eight arguments, with object-type.
 ***********************************************************************/
#define HYDROSIG_OBJECT_8_ARG       Object_type,                        \
                                    Return_type,                        \
                                    Arg1_type, Arg2_type, Arg3_type,    \
                                    Arg4_type, Arg5_type, Arg6_type,    \
                                    Arg7_type, Arg8_type                \




/**
 * Template parameter list macros with callable-type:
 * --------------------------------------------------
 */

/************************************************************************
 * Parameter list for zero arguments, with callable-type.
 ***********************************************************************/
#define HYDROSIG_CALLABLE_0_ARG     Callable_type,                      \
                                    Return_type                         \

/************************************************************************
 * Parameter list for one arguments, with callable-type.
 ***********************************************************************/
#define HYDROSIG_CALLABLE_1_ARG     Callable_type,                      \
                                    Return_type,                        \
                                    Arg1_type                           \

/************************************************************************
 * Parameter list for two arguments, with callable-type.
 ***********************************************************************/
#define HYDROSIG_CALLABLE_2_ARG     Callable_type,                      \
                                    Return_type,                        \
                                    Arg1_type, Arg2_type                \

/************************************************************************
 * Parameter list for three arguments, with callable-type.
 ***********************************************************************/
#define HYDROSIG_CALLABLE_3_ARG     Callable_type,                      \
                                    Return_type,                        \
                                    Arg1_type, Arg2_type, Arg3_type     \

/************************************************************************
 * Parameter list for four arguments, with callable-type.
 ***********************************************************************/
#define HYDROSIG_CALLABLE_4_ARG     Callable_type,                      \
                                    Return_type,                        \
                                    Arg1_type, Arg2_type, Arg3_type,    \
                                    Arg4_type                           \

/************************************************************************
 * Parameter list for five arguments, with callable-type.
 ***********************************************************************/
#define HYDROSIG_CALLABLE_5_ARG     Callable_type,                      \
                                    Return_type,                        \
                                    Arg1_type, Arg2_type, Arg3_type,    \
                                    Arg4_type, Arg5_type                \

/************************************************************************
 * Parameter list for six arguments, with callable-type.
 ***********************************************************************/
#define HYDROSIG_CALLABLE_6_ARG     Callable_type,                      \
                                    Return_type,                        \
                                    Arg1_type, Arg2_type, Arg3_type,    \
                                    Arg4_type, Arg5_type, Arg6_type     \

/************************************************************************
 * Parameter list for seven arguments, with callable-type.
 ***********************************************************************/
#define HYDROSIG_CALLABLE_7_ARG     Callable_type,                      \
                                    Return_type,                        \
                                    Arg1_type, Arg2_type, Arg3_type,    \
                                    Arg4_type, Arg5_type, Arg6_type,    \
                                    Arg7_type                           \

/************************************************************************
 * Parameter list for eight arguments, with callable-type.
 ***********************************************************************/
#define HYDROSIG_CALLABLE_8_ARG     Callable_type,                      \
                                    Return_type,                        \
                                    Arg1_type, Arg2_type, Arg3_type,    \
                                    Arg4_type, Arg5_type, Arg6_type,    \
                                    Arg7_type, Arg8_type                \




/**
 * Template declaration macro for portable syntax wrappers:
 * --------------------------------------------------------
 */

/****************************************************************************************
 * Template declaration for portable syntax wrapper base (eight arguments).
 ***************************************************************************************/
#define HYDROSIG_TEMPLATE_PORTABLE_WRAPPER_BASE                                         \
                                                                                        \
template<class Return_type,                                                             \
         class Arg1_type = no_arg, class Arg2_type = no_arg, class Arg3_type = no_arg,  \
         class Arg4_type = no_arg, class Arg5_type = no_arg, class Arg6_type = no_arg,  \
         class Arg7_type = no_arg, class Arg8_type = no_arg>                            \




/**
 * Template parameter list macro for portable syntax wrappers:
 * -----------------------------------------------------------
 */

/********************************************************************************
 * Parameter list for portable syntax wrapper for zero arguments.
 *******************************************************************************/
#define HYDROSIG_PORTABLE_WRAPPER_0_ARG     Return_type,                        \
                                            no_arg, no_arg, no_arg,             \
                                            no_arg, no_arg, no_arg,             \
                                            no_arg, no_arg                      \

/********************************************************************************
 * Parameter list for portable syntax wrapper for one arguments.
 *******************************************************************************/
#define HYDROSIG_PORTABLE_WRAPPER_1_ARG     Return_type,                        \
                                            Arg1_type, no_arg, no_arg,          \
                                            no_arg, no_arg, no_arg,             \
                                            no_arg, no_arg                      \

/********************************************************************************
 * Parameter list for portable syntax wrapper for two arguments.
 *******************************************************************************/
#define HYDROSIG_PORTABLE_WRAPPER_2_ARG     Return_type,                        \
                                            Arg1_type, Arg2_type, no_arg,       \
                                            no_arg, no_arg, no_arg,             \
                                            no_arg, no_arg                      \

/********************************************************************************
 * Parameter list for portable syntax wrapper for three arguments.
 *******************************************************************************/
#define HYDROSIG_PORTABLE_WRAPPER_3_ARG     Return_type,                        \
                                            Arg1_type, Arg2_type, Arg3_type,    \
                                            no_arg, no_arg, no_arg,             \
                                            no_arg, no_arg                      \

/********************************************************************************
 * Parameter list for portable syntax wrapper for four arguments.
 *******************************************************************************/
#define HYDROSIG_PORTABLE_WRAPPER_4_ARG     Return_type,                        \
                                            Arg1_type, Arg2_type, Arg3_type,    \
                                            Arg4_type, no_arg, no_arg,          \
                                            no_arg, no_arg                      \

/********************************************************************************
 * Parameter list for portable syntax wrapper for five arguments.
 *******************************************************************************/
#define HYDROSIG_PORTABLE_WRAPPER_5_ARG     Return_type,                        \
                                            Arg1_type, Arg2_type, Arg3_type,    \
                                            Arg4_type, Arg5_type, no_arg,       \
                                            no_arg, no_arg                      \

/********************************************************************************
 * Parameter list for portable syntax wrapper for six arguments.
 *******************************************************************************/
#define HYDROSIG_PORTABLE_WRAPPER_6_ARG     Return_type,                        \
                                            Arg1_type, Arg2_type, Arg3_type,    \
                                            Arg4_type, Arg5_type, Arg6_type,    \
                                            no_arg, no_arg                      \

/********************************************************************************
 * Parameter list for portable syntax wrapper for seven arguments.
 *******************************************************************************/
#define HYDROSIG_PORTABLE_WRAPPER_7_ARG     Return_type,                        \
                                            Arg1_type, Arg2_type, Arg3_type,    \
                                            Arg4_type, Arg5_type, Arg6_type,    \
                                            Arg7_type, no_arg                   \




/**
 * SFINAE enablers for connecting and disconnecting functions:
 * -----------------------------------------------------------
 */

/************************************************************************************
 * SFINAE enabler for signal connecter functions using untrackable objects.
 ***********************************************************************************/
#define HYDROSIG_CONNECT_ENABLER_UNTRACKABLE                                        \
                                                                                    \
template<class Object_type>                                                         \
typename std::enable_if<!std::is_base_of<trackable,Object_type>                     \
         ::value, connection_type>::type                                            \


/************************************************************************************
 * SFINAE enabler for signal connecter functions using trackable objects.
 ***********************************************************************************/
#define HYDROSIG_CONNECT_ENABLER_TRACKABLE                                          \
                                                                                    \
template<class Object_type>                                                         \
typename std::enable_if<std::is_base_of<trackable,Object_type>                      \
         ::value, connection_type>::type                                            \

/************************************************************************************
 * SFINAE enabler for signal disconnecter functions using untrackable objects.
 ***********************************************************************************/
#define HYDROSIG_DISCONNECT_ENABLER_UNTRACKABLE                                     \
                                                                                    \
template<class Object_type>                                                         \
typename std::enable_if<!std::is_base_of<trackable,Object_type>                     \
         ::value, void>::type                                                       \


/************************************************************************************
 * SFINAE enabler for signal disconnecter functions using trackable objects.
 ***********************************************************************************/
#define HYDROSIG_DISCONNECT_ENABLER_TRACKABLE                                       \
                                                                                    \
template<class Object_type>                                                         \
typename std::enable_if<std::is_base_of<trackable,Object_type>                      \
         ::value, void>::type                                                       \

/************************************************************************************
 * SFINAE enabler for connecter functions for untrackable objects, with 0 arguments.
 ***********************************************************************************/
#define HYDROSIG_CONNECT_ENABLER_UNTRACKABLE_IMPL_0                                 \
                                                                                    \
template<class Object_type>                                                         \
typename std::enable_if<!std::is_base_of<trackable,Object_type>                     \
         ::value, typename signal_0_base<HYDROSIG_0_ARG>::connection_type>::type    \

/************************************************************************************
 * SFINAE enabler for connecter functions for trackable objects, with 0 arguments.
 ***********************************************************************************/
#define HYDROSIG_CONNECT_ENABLER_TRACKABLE_IMPL_0                                   \
                                                                                    \
template<class Object_type>                                                         \
typename std::enable_if<std::is_base_of<trackable,Object_type>                      \
         ::value, typename signal_0_base<HYDROSIG_0_ARG>::connection_type>::type    \

/************************************************************************************
 * SFINAE enabler for connecter functions for untrackable objects, with 1 arguments.
 ***********************************************************************************/
#define HYDROSIG_CONNECT_ENABLER_UNTRACKABLE_IMPL_1                                 \
                                                                                    \
template<class Object_type>                                                         \
typename std::enable_if<!std::is_base_of<trackable,Object_type>                     \
         ::value, typename signal_1_base<HYDROSIG_1_ARG>::connection_type>::type    \

/************************************************************************************
 * SFINAE enabler for connecter functions for trackable objects, with 1 arguments.
 ***********************************************************************************/
#define HYDROSIG_CONNECT_ENABLER_TRACKABLE_IMPL_1                                   \
                                                                                    \
template<class Object_type>                                                         \
typename std::enable_if<std::is_base_of<trackable,Object_type>                      \
         ::value, typename signal_1_base<HYDROSIG_1_ARG>::connection_type>::type    \

/************************************************************************************
 * SFINAE enabler for connecter functions for untrackable objects, with 2 arguments.
 ***********************************************************************************/
#define HYDROSIG_CONNECT_ENABLER_UNTRACKABLE_IMPL_2                                 \
                                                                                    \
template<class Object_type>                                                         \
typename std::enable_if<!std::is_base_of<trackable,Object_type>                     \
         ::value, typename signal_2_base<HYDROSIG_2_ARG>::connection_type>::type    \

/************************************************************************************
 * SFINAE enabler for connecter functions for trackable objects, with 2 arguments.
 ***********************************************************************************/
#define HYDROSIG_CONNECT_ENABLER_TRACKABLE_IMPL_2                                   \
                                                                                    \
template<class Object_type>                                                         \
typename std::enable_if<std::is_base_of<trackable,Object_type>                      \
         ::value, typename signal_2_base<HYDROSIG_2_ARG>::connection_type>::type    \

/************************************************************************************
 * SFINAE enabler for connecter functions for untrackable objects, with 3 arguments.
 ***********************************************************************************/
#define HYDROSIG_CONNECT_ENABLER_UNTRACKABLE_IMPL_3                                 \
                                                                                    \
template<class Object_type>                                                         \
typename std::enable_if<!std::is_base_of<trackable,Object_type>                     \
         ::value, typename signal_3_base<HYDROSIG_3_ARG>::connection_type>::type    \

/************************************************************************************
 * SFINAE enabler for connecter functions for trackable objects, with 3 arguments.
 ***********************************************************************************/
#define HYDROSIG_CONNECT_ENABLER_TRACKABLE_IMPL_3                                   \
                                                                                    \
template<class Object_type>                                                         \
typename std::enable_if<std::is_base_of<trackable,Object_type>                      \
         ::value, typename signal_3_base<HYDROSIG_3_ARG>::connection_type>::type    \

/************************************************************************************
 * SFINAE enabler for connecter functions for untrackable objects, with 4 arguments.
 ***********************************************************************************/
#define HYDROSIG_CONNECT_ENABLER_UNTRACKABLE_IMPL_4                                 \
                                                                                    \
template<class Object_type>                                                         \
typename std::enable_if<!std::is_base_of<trackable,Object_type>                     \
         ::value, typename signal_4_base<HYDROSIG_4_ARG>::connection_type>::type    \

/************************************************************************************
 * SFINAE enabler for connecter functions for trackable objects, with 4 arguments.
 ***********************************************************************************/
#define HYDROSIG_CONNECT_ENABLER_TRACKABLE_IMPL_4                                   \
                                                                                    \
template<class Object_type>                                                         \
typename std::enable_if<std::is_base_of<trackable,Object_type>                      \
         ::value, typename signal_4_base<HYDROSIG_4_ARG>::connection_type>::type    \

/************************************************************************************
 * SFINAE enabler for connecter functions for untrackable objects, with 5 arguments.
 ***********************************************************************************/
#define HYDROSIG_CONNECT_ENABLER_UNTRACKABLE_IMPL_5                                 \
                                                                                    \
template<class Object_type>                                                         \
typename std::enable_if<!std::is_base_of<trackable,Object_type>                     \
         ::value, typename signal_5_base<HYDROSIG_5_ARG>::connection_type>::type    \

/************************************************************************************
 * SFINAE enabler for connecter functions for trackable objects, with 5 arguments.
 ***********************************************************************************/
#define HYDROSIG_CONNECT_ENABLER_TRACKABLE_IMPL_5                                   \
                                                                                    \
template<class Object_type>                                                         \
typename std::enable_if<std::is_base_of<trackable,Object_type>                      \
         ::value, typename signal_5_base<HYDROSIG_5_ARG>::connection_type>::type    \

/************************************************************************************
 * SFINAE enabler for connecter functions for untrackable objects, with 6 arguments.
 ***********************************************************************************/
#define HYDROSIG_CONNECT_ENABLER_UNTRACKABLE_IMPL_6                                 \
                                                                                    \
template<class Object_type>                                                         \
typename std::enable_if<!std::is_base_of<trackable,Object_type>                     \
         ::value, typename signal_6_base<HYDROSIG_6_ARG>::connection_type>::type    \

/************************************************************************************
 * SFINAE enabler for connecter functions for trackable objects, with 6 arguments.
 ***********************************************************************************/
#define HYDROSIG_CONNECT_ENABLER_TRACKABLE_IMPL_6                                   \
                                                                                    \
template<class Object_type>                                                         \
typename std::enable_if<std::is_base_of<trackable,Object_type>                      \
         ::value, typename signal_6_base<HYDROSIG_6_ARG>::connection_type>::type    \

/************************************************************************************
 * SFINAE enabler for connecter functions for untrackable objects, with 7 arguments.
 ***********************************************************************************/
#define HYDROSIG_CONNECT_ENABLER_UNTRACKABLE_IMPL_7                                 \
                                                                                    \
template<class Object_type>                                                         \
typename std::enable_if<!std::is_base_of<trackable,Object_type>                     \
         ::value, typename signal_7_base<HYDROSIG_7_ARG>::connection_type>::type    \

/************************************************************************************
 * SFINAE enabler for connecter functions for trackable objects, with 7 arguments.
 ***********************************************************************************/
#define HYDROSIG_CONNECT_ENABLER_TRACKABLE_IMPL_7                                   \
                                                                                    \
template<class Object_type>                                                         \
typename std::enable_if<std::is_base_of<trackable,Object_type>                      \
         ::value, typename signal_7_base<HYDROSIG_7_ARG>::connection_type>::type    \

/************************************************************************************
 * SFINAE enabler for connecter functions for untrackable objects, with 8 arguments.
 ***********************************************************************************/
#define HYDROSIG_CONNECT_ENABLER_UNTRACKABLE_IMPL_8                                 \
                                                                                    \
template<class Object_type>                                                         \
typename std::enable_if<!std::is_base_of<trackable,Object_type>                     \
         ::value, typename signal_8_base<HYDROSIG_8_ARG>::connection_type>::type    \

/************************************************************************************
 * SFINAE enabler for connecter functions for trackable objects, with 8 arguments.
 ***********************************************************************************/
#define HYDROSIG_CONNECT_ENABLER_TRACKABLE_IMPL_8                                   \
                                                                                    \
template<class Object_type>                                                         \
typename std::enable_if<std::is_base_of<trackable,Object_type>                      \
         ::value, typename signal_8_base<HYDROSIG_8_ARG>::connection_type>::type    \




/**
 * Template parameter list macro for elegant syntax wrappers:
 * ----------------------------------------------------------
 */

/********************************************************************
 * Parameter list for elegant syntax wrapper for zero arguments.
 *******************************************************************/
#define HYDROSIG_ELEGANT_WRAPPER_0_ARG                              \
                                                                    \
Return_type()                                                       \

/********************************************************************
 * Parameter list for elegant syntax wrapper for one arguments.
 *******************************************************************/
#define HYDROSIG_ELEGANT_WRAPPER_1_ARG                              \
                                                                    \
Return_type(Arg1_type)                                              \

/********************************************************************
 * Parameter list for elegant syntax wrapper for two arguments.
 *******************************************************************/
#define HYDROSIG_ELEGANT_WRAPPER_2_ARG                              \
                                                                    \
Return_type(Arg1_type, Arg2_type)                                   \

/********************************************************************
 * Parameter list for elegant syntax wrapper for three arguments.
 *******************************************************************/
#define HYDROSIG_ELEGANT_WRAPPER_3_ARG                              \
                                                                    \
Return_type(Arg1_type, Arg2_type, Arg3_type)                        \

/********************************************************************
 * Parameter list for elegant syntax wrapper for four arguments.
 *******************************************************************/
#define HYDROSIG_ELEGANT_WRAPPER_4_ARG                              \
                                                                    \
Return_type(Arg1_type, Arg2_type, Arg3_type,                        \
            Arg4_type)                                              \

/********************************************************************
 * Parameter list for elegant syntax wrapper for five arguments.
 *******************************************************************/
#define HYDROSIG_ELEGANT_WRAPPER_5_ARG                              \
                                                                    \
Return_type(Arg1_type, Arg2_type, Arg3_type,                        \
            Arg4_type, Arg5_type)                                   \

/********************************************************************
 * Parameter list for elegant syntax wrapper for six arguments.
 *******************************************************************/
#define HYDROSIG_ELEGANT_WRAPPER_6_ARG                              \
                                                                    \
Return_type(Arg1_type, Arg2_type, Arg3_type,                        \
            Arg4_type, Arg5_type, Arg6_type)                        \

/********************************************************************
 * Parameter list for elegant syntax wrapper for seven arguments.
 *******************************************************************/
#define HYDROSIG_ELEGANT_WRAPPER_7_ARG                              \
                                                                    \
Return_type(Arg1_type, Arg2_type, Arg3_type,                        \
            Arg4_type, Arg5_type, Arg6_type,                        \
            Arg7_type)                                              \

/********************************************************************
 * Parameter list for elegant syntax wrapper for eight arguments.
 *******************************************************************/
#define HYDROSIG_ELEGANT_WRAPPER_8_ARG                              \
                                                                    \
Return_type(Arg1_type, Arg2_type, Arg3_type,                        \
            Arg4_type, Arg5_type, Arg6_type,                        \
            Arg7_type, Arg8_type)                                   \



#endif // HYDROSIG_MACROS_H_INCLUDED
