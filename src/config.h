#pragma once
#ifndef HYDROSIG_CONFIG_H_INCLUDED
#define HYDROSIG_CONFIG_H_INCLUDED

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

/**
 * Configuration macros:
 * ---------------------
 */

/************************************************************
 * Enables the usage of the "hydrosig" namespace. If this
 * macro is defined, all content of the library is available
 * in this namespace. If left undefined, all library content
 * will be available in the global namespace (may cause name
 * conflicts). It is recommended to define this macro.
 ***********************************************************/
#define HYDROSIG_ENABLE_NAMESPACE

/*****************************************************
 * Enables the usage of thread synchronisation
 * primitives. Define this macro if multithreading
 * support is needed. In single threaded applications
 * it is better not to define this macro, to avoid
 * the overhead of unnecessary synchronisation.
 ****************************************************/
#define HYDROSIG_SYNCHRONISE_THREADS

/*****************************************************
 * Enables the usage of classes provided by the
 * Hydrogen framework. If this macro is defined, the
 * library will make use of containers, multithreading
 * classes and smart pointers available in Hydrogen.
 * It is advised to define this macro if the sources
 * of Hydrogen are available.
 ****************************************************/
///#define HYDROSIG_HYDROGEN_AVAILABLE




/**
 * Macros for configurative types used in the library:
 * ---------------------------------------------------
 */

/*******************************************************
 * Defines the list-type used in the library.
 ******************************************************/
#ifdef  HYDROSIG_HYDROGEN_AVAILABLE
# define HYDROSIG_LIST_TYPE          HList
#else
# define HYDROSIG_LIST_TYPE          std::list
#endif

/*******************************************************
 * Defines the shared_ptr type used in the library.
 ******************************************************/
#ifdef  HYDROSIG_HYDROGEN_AVAILABLE
# define HYDROSIG_SHARED_PTR_TYPE    HShared_ptr
#else
# define HYDROSIG_SHARED_PTR_TYPE    std::shared_ptr
#endif

/*******************************************************
 * Defines the unique_ptr type used in the library.
 ******************************************************/
#ifdef  HYDROSIG_HYDROGEN_AVAILABLE
# define HYDROSIG_UNIQUE_PTR_TYPE    HUnique_ptr
#else
# define HYDROSIG_UNIQUE_PTR_TYPE    std::unique_ptr
#endif

/*******************************************************
 * Defines the weak_ptr type used in the library.
 ******************************************************/
#ifdef  HYDROSIG_HYDROGEN_AVAILABLE
# define HYDROSIG_WEAK_PTR_TYPE      HWeak_ptr
#else
# define HYDROSIG_WEAK_PTR_TYPE      std::weak_ptr
#endif

/*******************************************************
 * Defines the mutex type used in the library.
 ******************************************************/
#ifdef  HYDROSIG_HYDROGEN_AVAILABLE
# define HYDROSIG_MUTEX_TYPE         HMutex
#else
# define HYDROSIG_MUTEX_TYPE         std::recursive_mutex
#endif

/****************************************************************************
 * Defines the lock-guard type used in the library.
 ***************************************************************************/
#ifdef  HYDROSIG_HYDROGEN_AVAILABLE
# define HYDROSIG_LOCK_GUARD_TYPE    HMutexLocker
#else
# define HYDROSIG_LOCK_GUARD_TYPE    std::unique_lock<std::recursive_mutex>
#endif


#endif // HYDROSIG_CONFIG_H_INCLUDED
