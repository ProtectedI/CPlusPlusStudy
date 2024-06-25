#pragma once

/*
 * 在C++中
 * 1、函数的参数如果是class/struct，如果参数不是指针或者引用，则会默认创建一份副本，即使函数体内对参数进行修改也不会影响到原参数。
 * 2、如果函数的返回值是class/struct，则默认返回值是副本，即使函数体内对返回值进行修改也不会影响到原返回值。
 */

#include "CopyConstruct.h"
#include "Friend.h"
#include "IOTest.h"
#include "Pointer.h"
#include "TestString.h"
#include "VirtualTest.h"
#include "NewAndDelete.h"
#include "MethodTest.h"
#include "DuoTai.h"
#include "Template.hpp"
#include "PreprocessorDirective.h"
#include "ThreadTest.h"
#include <ctime>
#include <iostream>

void TestString();
void CopyConstruct();
void Pointer();
void Friend();
void VirtualTest();
void TimeTest();
void IOTest();
void NewAndDeleteTest();
void MethodTestUnit();
void DuoTaiTest();
void TemplateTest();
void PreprocessorDirectiveTest();
void ThreadTest22();