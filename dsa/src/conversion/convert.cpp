/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "convert.h"

void convert ( Stack<char>& S, __int64 n, int base ) { //ʮ������n��base���Ƶ�ת���������棩
   static char digit[] //0 < n, 1 < base <= 16���½����µ���λ���ţ�����baseȡֵ��Χ�ʵ�����
   = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
   while ( n > 0 ) { //�ɵ͵��ߣ���һ������½����µĸ���λ
      int remainder = ( int ) ( n % base ); S.push ( digit[remainder] ); //��������ǰλ����ջ
      /*DSA*/printf ( "%20I64d =", n );
      n /= base; //n����Ϊ���base�ĳ���
      /*DSA*/printf ( "%20I64d * %d + %d\n", n, base, remainder );
      /*DSA*/print ( S );   getchar();
   }
} //�½������ɸߵ��͵ĸ���λ���Զ����±�����ջS��