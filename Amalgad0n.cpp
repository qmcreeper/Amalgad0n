﻿// Amalgad0n.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//各种东西糅合在一块的融合巨怪
//天知道会最终会成什么样子
//数不尽的bug和不可能再看第二遍的代码

#include <iostream>
#include "hilbertcurve.h"
#include "pid.h"

using namespace std;

int main()
{
    /*hilbertcurve opt1(2);
    cout << "n of hilbertcurve: " << opt1.n << "\n";
    cout << "size: " << opt1.n << "\n";
    opt1.run();*/

    pid ctr(100,200,0.2,0.015,0.2,1);
    ctr.pidrun();

    getchar();
}

