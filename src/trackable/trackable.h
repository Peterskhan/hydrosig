#pragma once
#ifndef HYDROSIG_TRACKABLE_H_INCLUDED
#define HYDROSIG_TRACKABLE_H_INCLUDED

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

#ifdef HYDROSIG_HYDROGEN_AVAILABLE
# include ../HContainers/HList/HList.hpp
# include ../HCore/HMemory/HMemory.h
# include ../HConcurrent/HConcurrent.h
#else
# include <list>
# include <memory>
# include <mutex>
#endif


HYDROSIG_NAMESPACE_BEGIN


/**
 * @brief   This class can be used to validate a
 *          signal-slot connection.
 */
class connection_validator
{
public:
    /**
     * @brief   Constructs a connection_validator object
     *          in a valid state by default.
     */
    connection_validator();

    /**
     * @brief   Invalidates the connection_validator.
     */
    void invalidate();

    /**
     * @brief   Returns whether the connection_validator is
     *          valid.
     * @return  True if the connection_validator is valid,
     *          false otherwise.
     */
    bool isValid() const;

private:
    /**< The state of validation */
    bool m_isValid;

};

/**
 * @brief   This base class can be used to track the participants
 *          of a signal-slot connection.
 * @details Trackable objects either have right to invalidate their
 *          connection validator, or they do not. Trackable objects
 *          that can invalidate their validators, will do so upon
 *          destruction. The status of validation can be checked at
 *          any time. Trackable objects reference their validator
 *          trough a shared_ptr, and it will be deleted automatically
 *          when the last trackable loses track of it.
 */
class trackable
{
public:
    /**
     * @brief   Destroys the trackable object.
     * @details The object will invalidate all
     *          of it's validators.
     */
    virtual ~trackable();

    /**
     * @brief   Adds a connection validator to the list of
     *          validators.
     * @param   validator Pointer to the validator object.
     */
    void addValidator(HYDROSIG_SHARED_PTR_TYPE<connection_validator> validator);

    /**
     * @brief   Removes a connection validator from the list
     *          of validators.
     * @param   validator Pointer to the validator object.
     */
    void removeValidator(HYDROSIG_SHARED_PTR_TYPE<connection_validator> validator);

    /**
     * @brief   Removes all invalidated connection validators
     *          from the lsit of validators.
     */
    void removeInvalidated();

private:
    /**< Pointer to the list of validators */
    HYDROSIG_LIST_TYPE<HYDROSIG_SHARED_PTR_TYPE<connection_validator>> m_validators;

    /**< Mutex used for synchronisation */
    HYDROSIG_MUTEX_TYPE m_mutex;

};


HYDROSIG_NAMESPACE_END


#endif // HYDROSIG_TRACKABLE_H_INCLUDED
