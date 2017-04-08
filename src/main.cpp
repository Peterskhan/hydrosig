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

#include "hydrosig.h"
#include <iostream>
#include <mutex>

class Test : public hydrosig::trackable
{
public:
    // Members with zero arguments
    void f0() {std::cout << "Test::f0()" << std::endl;}
    void f0_const() const {std::cout << "Test::f0() const" << std::endl;}
    void f0_volatile() volatile {std::cout << "Test::f0() volatile" << std::endl;}
    void f0_const_volatile() const volatile {std::cout << "Test::f0() const volatile" << std::endl;}
    // Members with one arguments
    void f1(int) {std::cout << "Test::f1()" << std::endl;}
    void f1_const(int) const {std::cout << "Test::f1() const" << std::endl;}
    void f1_volatile(int) volatile {std::cout << "Test::f1() volatile" << std::endl;}
    void f1_const_volatile(int) const volatile {std::cout << "Test::f1() const volatile" << std::endl;}
    // Members with two arguments
    void f2(int,int) {std::cout << "Test::f2()" << std::endl;}
    void f2_const(int,int) const {std::cout << "Test::f2() const" << std::endl;}
    void f2_volatile(int,int) volatile {std::cout << "Test::f2() volatile" << std::endl;}
    void f2_const_volatile(int,int) const volatile {std::cout << "Test::f2() const volatile" << std::endl;}
    // Members with three arguments
    void f3(int,int,int) {std::cout << "Test::f3()" << std::endl;}
    void f3_const(int,int,int) const {std::cout << "Test::f3() const" << std::endl;}
    void f3_volatile(int,int,int) volatile {std::cout << "Test::f3() volatile" << std::endl;}
    void f3_const_volatile(int,int,int) const volatile {std::cout << "Test::f3() const volatile" << std::endl;}
    // Members with four arguments
    void f4(int,int,int,int) {std::cout << "Test::f4()" << std::endl;}
    void f4_const(int,int,int,int) const {std::cout << "Test::f4() const" << std::endl;}
    void f4_volatile(int,int,int,int) volatile {std::cout << "Test::f4() volatile" << std::endl;}
    void f4_const_volatile(int,int,int,int) const volatile {std::cout << "Test::f4() const volatile" << std::endl;}
    // Members with five arguments
    void f5(int,int,int,int,int) {std::cout << "Test::f5()" << std::endl;}
    void f5_const(int,int,int,int,int) const {std::cout << "Test::f5() const" << std::endl;}
    void f5_volatile(int,int,int,int,int) volatile {std::cout << "Test::f5() volatile" << std::endl;}
    void f5_const_volatile(int,int,int,int,int) const volatile {std::cout << "Test::f5() const volatile" << std::endl;}
    // Members with six arguments
    void f6(int,int,int,int,int,int) {std::cout << "Test::f6()" << std::endl;}
    void f6_const(int,int,int,int,int,int) const {std::cout << "Test::f6() const" << std::endl;}
    void f6_volatile(int,int,int,int,int,int) volatile {std::cout << "Test::f6() volatile" << std::endl;}
    void f6_const_volatile(int,int,int,int,int,int) const volatile {std::cout << "Test::f6() const volatile" << std::endl;}
    // Members with seven arguments
    void f7(int,int,int,int,int,int,int) {std::cout << "Test::f7()" << std::endl;}
    void f7_const(int,int,int,int,int,int,int) const {std::cout << "Test::f7() const" << std::endl;}
    void f7_volatile(int,int,int,int,int,int,int) volatile {std::cout << "Test::f7() volatile" << std::endl;}
    void f7_const_volatile(int,int,int,int,int,int,int) const volatile {std::cout << "Test::f7() const volatile" << std::endl;}
    // Members with eight arguments
    void f8(int,int,int,int,int,int,int,int) {std::cout << "Test::f8()" << std::endl;}
    void f8_volatile(int,int,int,int,int,int,int,int) volatile {std::cout << "Test::f8() volatile" << std::endl;}
    void f8_const_volatile(int,int,int,int,int,int,int,int) const volatile {std::cout << "Test::f8() const volatile" << std::endl;}
    void f8_const(int,int,int,int,int,int,int,int) const {std::cout << "Test::f8() const" << std::endl;}

};

class Static_test {
public:
    static void print() { std::cout << "Static" << std::endl; }
};

// Global functions

int colf0() {return 0;}
int colf1(int) {return 1;}
int colf2(int,int) {return 2;}
int colf3(int,int,int) {return 3;}
int colf4(int,int,int,int) {return 4;}
int colf5(int,int,int,int,int) {return 5;}
int colf6(int,int,int,int,int,int) {return 6;}
int colf7(int,int,int,int,int,int,int) {return 7;}
int colf8(int,int,int,int,int,int,int,int) {return 8;}

void f0() {std::cout << "f0()" << std::endl;}
void f1(int) {std::cout << "f1()" << std::endl;}
void f2(int,int) {std::cout << "f2()" << std::endl;}
void f3(int,int,int) {std::cout << "f3()" << std::endl;}
void f4(int,int,int,int) {std::cout << "f4()" << std::endl;}
void f5(int,int,int,int,int) {std::cout << "f5()" << std::endl;}
void f6(int,int,int,int,int,int) {std::cout << "f6()" << std::endl;}
void f7(int,int,int,int,int,int,int) {std::cout << "f7()" << std::endl;}
void f8(int,int,int,int,int,int,int,int) {std::cout << "f8()" << std::endl;}

// Test for multiple connections
void multiple_connection_test0() {std::cout << "multiple_connection_test0()" << std::endl;}
void multiple_connection_test1(int) {std::cout << "multiple_connection_test1()" << std::endl;}
void multiple_connection_test2(int,int) {std::cout << "multiple_connection_test2()" << std::endl;}
void multiple_connection_test3(int,int,int) {std::cout << "multiple_connection_test3()" << std::endl;}
void multiple_connection_test4(int,int,int,int) {std::cout << "multiple_connection_test4()" << std::endl;}
void multiple_connection_test5(int,int,int,int,int) {std::cout << "multiple_connection_test5()" << std::endl;}
void multiple_connection_test6(int,int,int,int,int,int) {std::cout << "multiple_connection_test6()" << std::endl;}
void multiple_connection_test7(int,int,int,int,int,int,int) {std::cout << "multiple_connection_test7()" << std::endl;}
void multiple_connection_test8(int,int,int,int,int,int,int,int) {std::cout << "multiple_connection_test8()" << std::endl;}

int main()
{
    
    // Signals
    hydrosig::signal<void()> sig0;
    hydrosig::signal<void(int)> sig1;
    hydrosig::signal<void(int,int)> sig2;
    hydrosig::signal<void(int,int,int)> sig3;
    hydrosig::signal<void(int,int,int,int)> sig4;
    hydrosig::signal<void(int,int,int,int,int)> sig5;
    hydrosig::signal<void(int,int,int,int,int,int)> sig6;
    hydrosig::signal<void(int,int,int,int,int,int,int)> sig7;
    hydrosig::signal<void(int,int,int,int,int,int,int,int)> sig8;

    // Test object
    Test t;

    // Connecting signals
    sig0.connect(f0);
    sig0.connect(&t,&Test::f0);
    sig0.connect(&t,&Test::f0_const);
    sig0.connect(&t,&Test::f0_volatile);
    sig0.connect(&t,&Test::f0_const_volatile);
    sig1.connect(f1);
    sig1.connect(&t,&Test::f1);
    sig1.connect(&t,&Test::f1_const);
    sig1.connect(&t,&Test::f1_volatile);
    sig1.connect(&t,&Test::f1_const_volatile);
    sig2.connect(f2);
    sig2.connect(&t,&Test::f2);
    sig2.connect(&t,&Test::f2_const);
    sig2.connect(&t,&Test::f2_volatile);
    sig2.connect(&t,&Test::f2_const_volatile);
    sig3.connect(f3);
    sig3.connect(&t,&Test::f3);
    sig3.connect(&t,&Test::f3_const);
    sig3.connect(&t,&Test::f3_volatile);
    sig3.connect(&t,&Test::f3_const_volatile);
    sig4.connect(f4);
    sig4.connect(&t,&Test::f4);
    sig4.connect(&t,&Test::f4_const);
    sig4.connect(&t,&Test::f4_volatile);
    sig4.connect(&t,&Test::f4_const_volatile);
    sig5.connect(f5);
    sig5.connect(&t,&Test::f5);
    sig5.connect(&t,&Test::f5_const);
    sig5.connect(&t,&Test::f5_volatile);
    sig5.connect(&t,&Test::f5_const_volatile);
    sig6.connect(f6);
    sig6.connect(&t,&Test::f6);
    sig6.connect(&t,&Test::f6_const);
    sig6.connect(&t,&Test::f6_volatile);
    sig6.connect(&t,&Test::f6_const_volatile);
    sig7.connect(f7);
    sig7.connect(&t,&Test::f7);
    sig7.connect(&t,&Test::f7_const);
    sig7.connect(&t,&Test::f7_volatile);
    sig7.connect(&t,&Test::f7_const_volatile);
    sig8.connect(f8);
    sig8.connect(&t,&Test::f8);
    sig8.connect(&t,&Test::f8_const);
    sig8.connect(&t,&Test::f8_volatile);
    sig8.connect(&t,&Test::f8_const_volatile);

    // Emitting signals
    std::cout << "Emitting signals in normal order:" << std::endl << std::endl;
    sig0.emit();
    sig1.emit(1);
    sig2.emit(1,2);
    sig3.emit(1,2,3);
    sig4.emit(1,2,3,4);
    sig5.emit(1,2,3,4,5);
    sig6.emit(1,2,3,4,5,6);
    sig7.emit(1,2,3,4,5,6,7);
    sig8.emit(1,2,3,4,5,6,7,8);
    std::cout << std::endl << std::endl;

    // Emitting signals reverse
    std::cout << "Emitting signals in reverse order:" << std::endl << std::endl;
    sig0.emit_reverse();
    sig1.emit_reverse(1);
    sig2.emit_reverse(1,2);
    sig3.emit_reverse(1,2,3);
    sig4.emit_reverse(1,2,3,4);
    sig5.emit_reverse(1,2,3,4,5);
    sig6.emit_reverse(1,2,3,4,5,6);
    sig7.emit_reverse(1,2,3,4,5,6,7);
    sig8.emit_reverse(1,2,3,4,5,6,7,8);
    std::cout << std::endl << std::endl;

    // Blocking signals
    std::cout << "Blocking signals:" << std::endl << std::endl;
    sig0.block();
    sig1.block();
    sig2.block();
    sig3.block();
    sig4.block();
    sig5.block();
    sig6.block();
    sig7.block();
    sig8.block();

    sig0.emit();
    sig1.emit(1);
    sig2.emit(1,2);
    sig3.emit(1,2,3);
    sig4.emit(1,2,3,4);
    sig5.emit(1,2,3,4,5);
    sig6.emit(1,2,3,4,5,6);
    sig7.emit(1,2,3,4,5,6,7);
    sig8.emit(1,2,3,4,5,6,7,8);
    std::cout << std::endl << std::endl;

    // Unblocking signals
    std::cout << "Unblocking signals:" << std::endl << std::endl;
    sig0.unblock();
    sig1.unblock();
    sig2.unblock();
    sig3.unblock();
    sig4.unblock();
    sig5.unblock();
    sig6.unblock();
    sig7.unblock();
    sig8.unblock();

    sig0.emit();
    sig1.emit(1);
    sig2.emit(1,2);
    sig3.emit(1,2,3);
    sig4.emit(1,2,3,4);
    sig5.emit(1,2,3,4,5);
    sig6.emit(1,2,3,4,5,6);
    sig7.emit(1,2,3,4,5,6,7);
    sig8.emit(1,2,3,4,5,6,7,8);
    std::cout << std::endl << std::endl;

    // Signal sizes (uncleared)
    std::cout << "Signal sizes (uncleared): " << std::endl << std::endl;
    std::cout << "Sig0: " << sig0.size() << std::endl;
    std::cout << "Sig1: " << sig1.size() << std::endl;
    std::cout << "Sig2: " << sig2.size() << std::endl;
    std::cout << "Sig3: " << sig3.size() << std::endl;
    std::cout << "Sig4: " << sig4.size() << std::endl;
    std::cout << "Sig5: " << sig5.size() << std::endl;
    std::cout << "Sig6: " << sig6.size() << std::endl;
    std::cout << "Sig7: " << sig7.size() << std::endl;
    std::cout << "Sig8: " << sig8.size() << std::endl;
    std::cout << std::endl << std::endl;

    // Signal sizes (cleared) and emptyness
    std::cout << "Signal sizes (cleared) and emptyness:" << std::endl << std::endl;
    sig0.clear();
    sig1.clear();
    sig2.clear();
    sig3.clear();
    sig4.clear();
    sig5.clear();
    sig6.clear();
    sig7.clear();
    sig8.clear();

    std::cout << "Sig0: " << sig0.size() << std::endl;
    std::cout << "Sig1: " << sig1.size() << std::endl;
    std::cout << "Sig2: " << sig2.size() << std::endl;
    std::cout << "Sig3: " << sig3.size() << std::endl;
    std::cout << "Sig4: " << sig4.size() << std::endl;
    std::cout << "Sig5: " << sig5.size() << std::endl;
    std::cout << "Sig6: " << sig6.size() << std::endl;
    std::cout << "Sig7: " << sig7.size() << std::endl;
    std::cout << "Sig8: " << sig8.size() << std::endl;

    std::cout << "Sig0 empty: " << sig0.empty() << std::endl;
    std::cout << "Sig1 empty: " << sig1.empty() << std::endl;
    std::cout << "Sig2 empty: " << sig2.empty() << std::endl;
    std::cout << "Sig3 empty: " << sig3.empty() << std::endl;
    std::cout << "Sig4 empty: " << sig4.empty() << std::endl;
    std::cout << "Sig5 empty: " << sig5.empty() << std::endl;
    std::cout << "Sig6 empty: " << sig6.empty() << std::endl;
    std::cout << "Sig7 empty: " << sig7.empty() << std::endl;
    std::cout << "Sig8 empty: " << sig8.empty() << std::endl;

    std::cout << std::endl << std::endl;

    // Disconnect tests
    std::cout << "Disconnect tests:" << std::endl << std::endl;

    sig0.connect(f0);
    sig0.connect(&t,&Test::f0);
    sig0.connect(&t,&Test::f0_const);
    sig0.connect(&t,&Test::f0_volatile);
    sig0.connect(&t,&Test::f0_const_volatile);
    sig1.connect(f1);
    sig1.connect(&t,&Test::f1);
    sig1.connect(&t,&Test::f1_const);
    sig1.connect(&t,&Test::f1_volatile);
    sig1.connect(&t,&Test::f1_const_volatile);
    sig2.connect(f2);
    sig2.connect(&t,&Test::f2);
    sig2.connect(&t,&Test::f2_const);
    sig2.connect(&t,&Test::f2_volatile);
    sig2.connect(&t,&Test::f2_const_volatile);
    sig3.connect(f3);
    sig3.connect(&t,&Test::f3);
    sig3.connect(&t,&Test::f3_const);
    sig3.connect(&t,&Test::f3_volatile);
    sig3.connect(&t,&Test::f3_const_volatile);
    sig4.connect(f4);
    sig4.connect(&t,&Test::f4);
    sig4.connect(&t,&Test::f4_const);
    sig4.connect(&t,&Test::f4_volatile);
    sig4.connect(&t,&Test::f4_const_volatile);
    sig5.connect(f5);
    sig5.connect(&t,&Test::f5);
    sig5.connect(&t,&Test::f5_const);
    sig5.connect(&t,&Test::f5_volatile);
    sig5.connect(&t,&Test::f5_const_volatile);
    sig6.connect(f6);
    sig6.connect(&t,&Test::f6);
    sig6.connect(&t,&Test::f6_const);
    sig6.connect(&t,&Test::f6_volatile);
    sig6.connect(&t,&Test::f6_const_volatile);
    sig7.connect(f7);
    sig7.connect(&t,&Test::f7);
    sig7.connect(&t,&Test::f7_const);
    sig7.connect(&t,&Test::f7_volatile);
    sig7.connect(&t,&Test::f7_const_volatile);
    sig8.connect(f8);
    sig8.connect(&t,&Test::f8);
    sig8.connect(&t,&Test::f8_const);
    sig8.connect(&t,&Test::f8_volatile);
    sig8.connect(&t,&Test::f8_const_volatile);

    std::cout << "Before disconnection: " << std::endl;
    sig0.emit();
    sig1.emit(1);
    sig2.emit(1,2);
    sig3.emit(1,2,3);
    sig4.emit(1,2,3,4);
    sig5.emit(1,2,3,4,5);
    sig6.emit(1,2,3,4,5,6);
    sig7.emit(1,2,3,4,5,6,7);
    sig8.emit(1,2,3,4,5,6,7,8);

    sig0.disconnect(f0);
    sig0.disconnect(&t,&Test::f0);
    sig0.disconnect(&t,&Test::f0_const);
    sig0.disconnect(&t,&Test::f0_volatile);
    sig0.disconnect(&t,&Test::f0_const_volatile);
    sig1.disconnect(f1);
    sig1.disconnect(&t,&Test::f1);
    sig1.disconnect(&t,&Test::f1_const);
    sig1.disconnect(&t,&Test::f1_volatile);
    sig1.disconnect(&t,&Test::f1_const_volatile);
    sig2.disconnect(f2);
    sig2.disconnect(&t,&Test::f2);
    sig2.disconnect(&t,&Test::f2_const);
    sig2.disconnect(&t,&Test::f2_volatile);
    sig2.disconnect(&t,&Test::f2_const_volatile);
    sig3.disconnect(f3);
    sig3.disconnect(&t,&Test::f3);
    sig3.disconnect(&t,&Test::f3_const);
    sig3.disconnect(&t,&Test::f3_volatile);
    sig3.disconnect(&t,&Test::f3_const_volatile);
    sig4.disconnect(f4);
    sig4.disconnect(&t,&Test::f4);
    sig4.disconnect(&t,&Test::f4_const);
    sig4.disconnect(&t,&Test::f4_volatile);
    sig4.disconnect(&t,&Test::f4_const_volatile);
    sig5.disconnect(f5);
    sig5.disconnect(&t,&Test::f5);
    sig5.disconnect(&t,&Test::f5_const);
    sig5.disconnect(&t,&Test::f5_volatile);
    sig5.disconnect(&t,&Test::f5_const_volatile);
    sig6.disconnect(f6);
    sig6.disconnect(&t,&Test::f6);
    sig6.disconnect(&t,&Test::f6_const);
    sig6.disconnect(&t,&Test::f6_volatile);
    sig6.disconnect(&t,&Test::f6_const_volatile);
    sig7.disconnect(f7);
    sig7.disconnect(&t,&Test::f7);
    sig7.disconnect(&t,&Test::f7_const);
    sig7.disconnect(&t,&Test::f7_volatile);
    sig7.disconnect(&t,&Test::f7_const_volatile);
    sig8.disconnect(f8);
    sig8.disconnect(&t,&Test::f8);
    sig8.disconnect(&t,&Test::f8_const);
    sig8.disconnect(&t,&Test::f8_volatile);
    sig8.disconnect(&t,&Test::f8_const_volatile);
    std::cout << std::endl;

    std::cout << "After disconnection: " << std::endl;
    sig0.emit();
    sig1.emit(1);
    sig2.emit(1,2);
    sig3.emit(1,2,3);
    sig4.emit(1,2,3,4);
    sig5.emit(1,2,3,4,5);
    sig6.emit(1,2,3,4,5,6);
    sig7.emit(1,2,3,4,5,6,7);
    sig8.emit(1,2,3,4,5,6,7,8);

    std::cout << std::endl << std::endl;

    // Multiple connections test
    std::cout << "Multiple connection test: " << std::endl << std::endl;

    sig0.connect(multiple_connection_test0);
    sig0.connect(multiple_connection_test0);
    sig1.connect(multiple_connection_test1);
    sig1.connect(multiple_connection_test1);
    sig2.connect(multiple_connection_test2);
    sig2.connect(multiple_connection_test2);
    sig3.connect(multiple_connection_test3);
    sig3.connect(multiple_connection_test3);
    sig4.connect(multiple_connection_test4);
    sig4.connect(multiple_connection_test4);
    sig5.connect(multiple_connection_test5);
    sig5.connect(multiple_connection_test5);
    sig6.connect(multiple_connection_test6);
    sig6.connect(multiple_connection_test6);
    sig7.connect(multiple_connection_test7);
    sig7.connect(multiple_connection_test7);
    sig8.connect(multiple_connection_test8);
    sig8.connect(multiple_connection_test8);

    std::cout << "Multiple connections before disconnecing once:" << std::endl;
    sig0.emit();
    sig1.emit(1);
    sig2.emit(1,2);
    sig3.emit(1,2,3);
    sig4.emit(1,2,3,4);
    sig5.emit(1,2,3,4,5);
    sig6.emit(1,2,3,4,5,6);
    sig7.emit(1,2,3,4,5,6,7);
    sig8.emit(1,2,3,4,5,6,7,8);

    sig0.disconnect(multiple_connection_test0);
    sig1.disconnect(multiple_connection_test1);
    sig2.disconnect(multiple_connection_test2);
    sig3.disconnect(multiple_connection_test3);
    sig4.disconnect(multiple_connection_test4);
    sig5.disconnect(multiple_connection_test5);
    sig6.disconnect(multiple_connection_test6);
    sig7.disconnect(multiple_connection_test7);
    sig8.disconnect(multiple_connection_test8);
    std::cout << std::endl;

    std::cout << "Multiple connections after disconnecting once:" << std::endl;
    sig0.emit();
    sig1.emit(1);
    sig2.emit(1,2);
    sig3.emit(1,2,3);
    sig4.emit(1,2,3,4);
    sig5.emit(1,2,3,4,5);
    sig6.emit(1,2,3,4,5,6);
    sig7.emit(1,2,3,4,5,6,7);
    sig8.emit(1,2,3,4,5,6,7,8);
    std::cout << std::endl << std::endl;

    // Lambda test
    std::cout << "Lambda test:" << std::endl << std::endl;
    sig0.clear();
    sig1.clear();
    sig2.clear();
    sig3.clear();
    sig4.clear();
    sig5.clear();
    sig6.clear();
    sig7.clear();
    sig8.clear();

    sig0.connect([](){std::cout << "lambda0()" << std::endl;});
    sig1.connect([](int){std::cout << "lambda1()" << std::endl;});
    sig2.connect([](int,int){std::cout << "lambda2()" << std::endl;});
    sig3.connect([](int,int,int){std::cout << "lambda3()" << std::endl;});
    sig4.connect([](int,int,int,int){std::cout << "lambda4()" << std::endl;});
    sig5.connect([](int,int,int,int,int){std::cout << "lambda5()" << std::endl;});
    sig6.connect([](int,int,int,int,int,int){std::cout << "lambda6()" << std::endl;});
    sig7.connect([](int,int,int,int,int,int,int){std::cout << "lambda7()" << std::endl;});
    sig8.connect([](int,int,int,int,int,int,int,int){std::cout << "lambda8()" << std::endl;});

    sig0.emit();
    sig1.emit(1);
    sig2.emit(1,2);
    sig3.emit(1,2,3);
    sig4.emit(1,2,3,4);
    sig5.emit(1,2,3,4,5);
    sig6.emit(1,2,3,4,5,6);
    sig7.emit(1,2,3,4,5,6,7);
    sig8.emit(1,2,3,4,5,6,7,8);
    std::cout << std::endl << std::endl;

    // Connection test
    std::cout << "Connection test:" << std::endl << std::endl;
    sig0.clear();
    sig1.clear();
    sig2.clear();
    sig3.clear();
    sig4.clear();
    sig5.clear();
    sig6.clear();
    sig7.clear();
    sig8.clear();

    auto con0 = sig0.connect(f0);
    auto con1 = sig1.connect(f1);
    auto con2 = sig2.connect(f2);
    auto con3 = sig3.connect(f3);
    auto con4 = sig4.connect(f4);
    auto con5 = sig5.connect(f5);
    auto con6 = sig6.connect(f6);
    auto con7 = sig7.connect(f7);
    auto con8 = sig8.connect(f8);

    std::cout << "Before disconnection: " << std::endl;
    sig0.emit();
    sig1.emit(1);
    sig2.emit(1,2);
    sig3.emit(1,2,3);
    sig4.emit(1,2,3,4);
    sig5.emit(1,2,3,4,5);
    sig6.emit(1,2,3,4,5,6);
    sig7.emit(1,2,3,4,5,6,7);
    sig8.emit(1,2,3,4,5,6,7,8);

    sig0.disconnect(con0);
    sig1.disconnect(con1);
    sig2.disconnect(con2);
    sig3.disconnect(con3);
    sig4.disconnect(con4);
    sig5.disconnect(con5);
    sig6.disconnect(con6);
    sig7.disconnect(con7);
    sig8.disconnect(con8);

    std::cout << "After disconnection: " << std::endl;
    sig0.emit();
    sig1.emit(1);
    sig2.emit(1,2);
    sig3.emit(1,2,3);
    sig4.emit(1,2,3,4);
    sig5.emit(1,2,3,4,5);
    sig6.emit(1,2,3,4,5,6);
    sig7.emit(1,2,3,4,5,6,7);
    sig8.emit(1,2,3,4,5,6,7,8);

    std::cout << std::endl << std::endl;

    // Callable test
    std::cout << "Callable test (catching lambdas):" << std::endl << std::endl;
    int capture0 = 0;
    int capture1 = 1;
    int capture2 = 2;
    int capture3 = 3;
    int capture4 = 4;
    int capture5 = 5;
    int capture6 = 6;
    int capture7 = 7;
    int capture8 = 8;

    auto c0 = sig0.connect([&](){std::cout << capture0 << std::endl;});
    auto c1 = sig1.connect([&](int){std::cout << capture1 << std::endl;});
    auto c2 = sig2.connect([&](int,int){std::cout << capture2 << std::endl;});
    auto c3 = sig3.connect([&](int,int,int){std::cout << capture3 << std::endl;});
    auto c4 = sig4.connect([&](int,int,int,int){std::cout << capture4 << std::endl;});
    auto c5 = sig5.connect([&](int,int,int,int,int){std::cout << capture5 << std::endl;});
    auto c6 = sig6.connect([&](int,int,int,int,int,int){std::cout << capture6 << std::endl;});
    auto c7 = sig7.connect([&](int,int,int,int,int,int,int){std::cout << capture7 << std::endl;});
    auto c8 = sig8.connect([&](int,int,int,int,int,int,int,int){std::cout << capture8 << std::endl;});

    std::cout << "Before disconnection:" << std::endl;
    sig0.emit();
    sig1.emit(1);
    sig2.emit(1,2);
    sig3.emit(1,2,3);
    sig4.emit(1,2,3,4);
    sig5.emit(1,2,3,4,5);
    sig6.emit(1,2,3,4,5,6);
    sig7.emit(1,2,3,4,5,6,7);
    sig8.emit(1,2,3,4,5,6,7,8);

    sig0.disconnect(c0);
    sig1.disconnect(c1);
    sig2.disconnect(c2);
    sig3.disconnect(c3);
    sig4.disconnect(c4);
    sig5.disconnect(c5);
    sig6.disconnect(c6);
    sig7.disconnect(c7);
    sig8.disconnect(c8);

    std::cout << "After disconnection:" << std::endl;
    sig0.emit();
    sig1.emit(1);
    sig2.emit(1,2);
    sig3.emit(1,2,3);
    sig4.emit(1,2,3,4);
    sig5.emit(1,2,3,4,5);
    sig6.emit(1,2,3,4,5,6);
    sig7.emit(1,2,3,4,5,6,7);
    sig8.emit(1,2,3,4,5,6,7,8);

    std::cout << std::endl << std::endl;

    // Collected signal test
    std::cout << "Collected signal test:" << std::endl << std::endl;

    hydrosig::signal<int>::collected col0;
    hydrosig::signal<int(int)>::collected col1;
    hydrosig::signal<int(int,int)>::collected col2;
    hydrosig::signal<int(int,int,int)>::collected col3;
    hydrosig::signal<int(int,int,int,int)>::collected col4;
    hydrosig::signal<int(int,int,int,int,int)>::collected col5;
    hydrosig::signal<int(int,int,int,int,int,int)>::collected col6;
    hydrosig::signal<int(int,int,int,int,int,int,int)>::collected col7;
    hydrosig::signal<int(int,int,int,int,int,int,int,int)>::collected col8;

    col0.connect(colf0);
    col1.connect(colf1);
    col2.connect(colf2);
    col3.connect(colf3);
    col4.connect(colf4);
    col5.connect(colf5);
    col6.connect(colf6);
    col7.connect(colf7);
    col8.connect(colf8);

    col0.block();
    col1.block();
    col2.block();
    col3.block();
    col4.block();
    col5.block();
    col6.block();
    col7.block();
    col8.block();

    std::list<int> clist0 = col0.emit_collected();
    std::list<int> clist1 = col1.emit_collected(1);
    std::list<int> clist2 = col2.emit_collected(1,2);
    std::list<int> clist3 = col3.emit_collected(1,2,3);
    std::list<int> clist4 = col4.emit_collected(1,2,3,4);
    std::list<int> clist5 = col5.emit_collected(1,2,3,4,5);
    std::list<int> clist6 = col6.emit_collected(1,2,3,4,5,6);
    std::list<int> clist7 = col7.emit_collected(1,2,3,4,5,6,7);
    std::list<int> clist8 = col8.emit_collected(1,2,3,4,5,6,7,8);

    for(std::list<int>::iterator it = clist0.begin(); it != clist0.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    for(std::list<int>::iterator it = clist1.begin(); it != clist1.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    for(std::list<int>::iterator it = clist2.begin(); it != clist2.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    for(std::list<int>::iterator it = clist3.begin(); it != clist3.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    for(std::list<int>::iterator it = clist4.begin(); it != clist4.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    for(std::list<int>::iterator it = clist5.begin(); it != clist5.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    for(std::list<int>::iterator it = clist6.begin(); it != clist6.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    for(std::list<int>::iterator it = clist7.begin(); it != clist7.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    for(std::list<int>::iterator it = clist8.begin(); it != clist8.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    std::cout << std::endl << std::endl;


    return 0;
}

