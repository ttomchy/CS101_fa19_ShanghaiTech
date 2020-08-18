/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

__int64 fib ( int n, __int64& prev ) { //����Fibonacci���е�n����Եݹ�棩�������ʽfib(n, prev)
   if ( 0 == n ) //������ݹ������
      { prev = 1; return 0; } //ֱ��ȡֵ��fib(-1) = 1, fib(0) = 0
   else { //����
      __int64 prevPrev; prev = fib ( n - 1, prevPrev ); //�ݹ����ǰ����
      return prevPrev + prev; //��ͼ�Ϊ����
   }
} //�ø���������¼ǰһ��������еĵ�ǰ�O(n)