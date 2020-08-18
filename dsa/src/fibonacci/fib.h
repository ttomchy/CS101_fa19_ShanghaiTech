/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

class Fib { //Fibonacci������
private:
   int f, g; //f = fib(k - 1), g = fib(k)����Ϊint�ͣ��ܿ�ͻ���ֵ���
public:
   Fib ( int n ) //��ʼ��Ϊ��С��n����СFibonacci��
   { f = 1; g = 0; while ( g < n ) next(); } //fib(-1), fib(0)��O(log_phi(n))ʱ��
   int get()  { return g; } //��ȡ��ǰFibonacci�O(1)ʱ��
   int next() { g += f; f = g - f; return g; } //ת����һFibonacci�O(1)ʱ��
   int prev() { f = g - f; g -= f; return g; } //ת����һFibonacci�O(1)ʱ��
};