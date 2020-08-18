/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "../string_pm/string_pm_test.h"

int* buildNext ( char* P ) { //����ģʽ��P��next���Ľ��汾��
   size_t m = strlen ( P ), j = 0; //��������ָ��
   int* N = new int[m]; //next��
   int t = N[0] = -1; //ģʽ��ָ��
   while ( j < m - 1 )
      if ( 0 > t || P[j] == P[t] ) { //ƥ��
         N[j] = ( P[++j] != P[++t] ? t : N[t] ); //ע��˾���δ�Ľ�֮ǰ������
      } else //ʧ��
         t = N[t];
   /*DSA*/printString ( P ); printf ( "\n" );
   /*DSA*/printNext ( N, 0, strlen ( P ) );
   return N;
}
