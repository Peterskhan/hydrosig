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

#include "src/hydrosig.h"
#include <iostream>

template<class T>
class sum_combiner
{
public:
    void operator()(const T& val)
    {

        sum += val;
    }

    T value() const
    {
        return sum;
    }

private:
    T sum;
};

int test()
{
    std::cout << "test" << std::endl;
    return 1;
}

int test2()
{
    std::cout << "test2" << std::endl;
    return 2;
}

class Test : public hydrosig::trackable
{
public:
    int func() { std::cout << "Test::func" << std::endl; return 0; }
};

int main()
{
    hydrosig::signal<int()> sig;

    for(int i = 0; i < 5; i++)
    {
        Test t;
        sig.connect(&t,&Test::func);
    }


    sig.emit();




    return 0;
}







