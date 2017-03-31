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

/**
 * Configuration macros:
 * ---------------------
 */

/*****************************************************
 * Enables the usage of containers provided by the
 * Hydrogen framework. Define this macro if the
 * sources of Hydrogen are available. If the sources
 * are not available and this macro is left undefined,
 * the STL containers will be used across the library.
 ****************************************************/
/// #define HYDROSIG_USE_HYDROGEN_CONTAINERS

/*****************************************************
 * Enables the usage of thread synchronisation
 * primitives. Define this macro if multithreading
 * support is needed. In single threaded applications
 * it is better not to define this macro, to avoid
 * the overhead of unnecessary synchronisation.
 ****************************************************/
 #define HYDROSIG_USE_THREAD_SYNCHRONISATION

/*****************************************************
 * Enables the usage of thread synchronisation
 * primitives provided by the Hydrogen framework.
 * Define this macro if the sources of Hydrogen are
 * available. If the sources are not available and
 * this macro is left undefined, the standard C++11
 * implementation will be used across the library.
 ****************************************************/
/// #define HYDROSIG_USE_HYDROGEN_SYNCHRONISATION


/**
 * Internal convenience macros:
 * ----------------------------
 */

/*****************************************************
 * Begins the hydrosig namespace. All contents of the
 * library are defined in this namespace.
 ****************************************************/
#define HYDROSIG_NAMESPACE_BEGIN   namespace hydrosig {

/*****************************************************
 * Closes the hydrosig namespace.
 ****************************************************/
#define HYDROSIG_NAMESPACE_END     }


#endif // HYDROSIG_MACROS_H_INCLUDED
