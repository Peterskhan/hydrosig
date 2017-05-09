#pragma once
#ifndef HYDROSIG_SIGNAL_WRAPPER_HPP_INCLUDED
#define HYDROSIG_SIGNAL_WRAPPER_HPP_INCLUDED

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

#include "src/macros.h"
#include "src/wrappers/wrapper_helpers.h"

#include "src/signals/signal_0.hpp"
#include "src/signals/signal_1.hpp"
#include "src/signals/signal_2.hpp"
#include "src/signals/signal_3.hpp"
#include "src/signals/signal_4.hpp"
#include "src/signals/signal_5.hpp"
#include "src/signals/signal_6.hpp"
#include "src/signals/signal_7.hpp"
#include "src/signals/signal_8.hpp"


HYDROSIG_NAMESPACE_BEGIN


/**
 * Convenience signal wrappers - portable syntax.
 * --------------------------------------------------
 */

HYDROSIG_TEMPLATE_PORTABLE_WRAPPER_BASE
/**
 * @brief   Convenience wrapper for signals with eight arguments.
 * @details Signals with less arguments are specialized types of
 *          this template.
 */
class signal
        : public signal_8<HYDROSIG_8_ARG>
{

};

HYDROSIG_TEMPLATE_0_ARG
/**
 * @brief   Convenience wrapper for signals with no arguments.
 * @details Specialized from the template wrapper for eight arguments.
 */
class signal<HYDROSIG_PORTABLE_WRAPPER_0_ARG>
      : public signal_0<HYDROSIG_0_ARG>
{

};

HYDROSIG_TEMPLATE_1_ARG
/**
 * @brief   Convenience wrapper for signals with one arguments.
 * @details Specialized from the template wrapper for eight arguments.
 */
class signal<HYDROSIG_PORTABLE_WRAPPER_1_ARG>
      : public signal_1<HYDROSIG_1_ARG>
{

};

HYDROSIG_TEMPLATE_2_ARG
/**
 * @brief   Convenience wrapper for signals with two arguments.
 * @details Specialized from the template wrapper for eight arguments.
 */
class signal<HYDROSIG_PORTABLE_WRAPPER_2_ARG>
      : public signal_2<HYDROSIG_2_ARG>
{

};

HYDROSIG_TEMPLATE_3_ARG
/**
 * @brief   Convenience wrapper for signals with three arguments.
 * @details Specialized from the template wrapper for eight arguments.
 */
class signal<HYDROSIG_PORTABLE_WRAPPER_3_ARG>
      : public signal_3<HYDROSIG_3_ARG>
{

};

HYDROSIG_TEMPLATE_4_ARG
/**
 * @brief   Convenience wrapper for signals with four arguments.
 * @details Specialized from the template wrapper for eight arguments.
 */
class signal<HYDROSIG_PORTABLE_WRAPPER_4_ARG>
      : public signal_4<HYDROSIG_4_ARG>
{

};

HYDROSIG_TEMPLATE_5_ARG
/**
 * @brief   Convenience wrapper for signals with five arguments.
 * @details Specialized from the template wrapper for eight arguments.
 */
class signal<HYDROSIG_PORTABLE_WRAPPER_5_ARG>
      : public signal_5<HYDROSIG_5_ARG>
{

};

HYDROSIG_TEMPLATE_6_ARG
/**
 * @brief   Convenience wrapper for signals with six arguments.
 * @details Specialized from the template wrapper for eight arguments.
 */
class signal<HYDROSIG_PORTABLE_WRAPPER_6_ARG>
      : public signal_6<HYDROSIG_6_ARG>
{

};

HYDROSIG_TEMPLATE_7_ARG
/**
 * @brief   Convenience wrapper for signals with seven arguments.
 * @details Specialized from the template wrapper for eight arguments.
 */
class signal<HYDROSIG_PORTABLE_WRAPPER_7_ARG>
      : public signal_7<HYDROSIG_7_ARG>
{

};


/**
 * Convenience connection wrappers - elegant syntax.
 * -------------------------------------------------
 */

HYDROSIG_TEMPLATE_0_ARG
/**
 * @brief   Convenience wrapper for signals with no arguments.
 * @details This template version uses the elegant syntax.
 */
class signal<HYDROSIG_ELEGANT_WRAPPER_0_ARG>
    : public signal_0<HYDROSIG_0_ARG>
{

};

HYDROSIG_TEMPLATE_1_ARG
/**
 * @brief   Convenience wrapper for signals with one arguments.
 * @details This template version uses the elegant syntax.
 */
class signal<HYDROSIG_ELEGANT_WRAPPER_1_ARG>
    : public signal_1<HYDROSIG_1_ARG>
{

};

HYDROSIG_TEMPLATE_2_ARG
/**
 * @brief   Convenience wrapper for signals with two arguments.
 * @details This template version uses the elegant syntax.
 */
class signal<HYDROSIG_ELEGANT_WRAPPER_2_ARG>
    : public signal_2<HYDROSIG_2_ARG>
{

};

HYDROSIG_TEMPLATE_3_ARG
/**
 * @brief   Convenience wrapper for signals with three arguments.
 * @details This template version uses the elegant syntax.
 */
class signal<HYDROSIG_ELEGANT_WRAPPER_3_ARG>
    : public signal_3<HYDROSIG_3_ARG>
{

};

HYDROSIG_TEMPLATE_4_ARG
/**
 * @brief   Convenience wrapper for signals with four arguments.
 * @details This template version uses the elegant syntax.
 */
class signal<HYDROSIG_ELEGANT_WRAPPER_4_ARG>
    : public signal_4<HYDROSIG_4_ARG>
{

};

HYDROSIG_TEMPLATE_5_ARG
/**
 * @brief   Convenience wrapper for signals with five arguments.
 * @details This template version uses the elegant syntax.
 */
class signal<HYDROSIG_ELEGANT_WRAPPER_5_ARG>
    : public signal_5<HYDROSIG_5_ARG>
{

};

HYDROSIG_TEMPLATE_6_ARG
/**
 * @brief   Convenience wrapper for signals with six arguments.
 * @details This template version uses the elegant syntax.
 */
class signal<HYDROSIG_ELEGANT_WRAPPER_6_ARG>
    : public signal_6<HYDROSIG_6_ARG>
{

};

HYDROSIG_TEMPLATE_7_ARG
/**
 * @brief   Convenience wrapper for signals with seven arguments.
 * @details This template version uses the elegant syntax.
 */
class signal<HYDROSIG_ELEGANT_WRAPPER_7_ARG>
    : public signal_7<HYDROSIG_7_ARG>
{

};

HYDROSIG_TEMPLATE_8_ARG
/**
 * @brief   Convenience wrapper for signals with eight arguments.
 * @details This template version uses the elegant syntax.
 */
class signal<HYDROSIG_ELEGANT_WRAPPER_8_ARG>
    : public signal_8<HYDROSIG_8_ARG>
{

};


HYDROSIG_NAMESPACE_END


#endif // HYDROSIG_SIGNAL_WRAPPER_HPP_INCLUDED
