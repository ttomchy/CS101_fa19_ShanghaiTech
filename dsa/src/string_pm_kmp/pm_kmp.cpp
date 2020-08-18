/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "../string_pm/string_pm_test.h"

int match ( char* P, char* T ) {  //KMP�㷨
   int* next = buildNext ( P ); //����next��
   int n = ( int ) strlen ( T ), i = 0; //�ı���ָ��
   int m = ( int ) strlen ( P ), j = 0; //ģʽ��ָ��
   while ( j < m  && i < n ) //������������ȶ��ַ�
      /*DSA*/{
      /*DSA*/showProgress ( T, P, i - j, j );
      /*DSA*/printNext ( next, i - j, strlen ( P ) );
      /*DSA*/getchar(); printf ( "\n" );
      if ( 0 > j || T[i] == P[j] ) //��ƥ�䣬��P���Ƴ�����ࣨ�����жϵĴ��򲻿ɽ�����
         { i ++;  j ++; } //��ת����һ�ַ�
      else //����
         j = next[j]; //ģʽ�����ƣ�ע�⣺�ı������û��ˣ�
      /*DSA*/}
   delete [] next; //�ͷ�next��
   return i - j;
}