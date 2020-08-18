/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "../string_pm/string_pm_test.h"

int match ( char* P, char* T ) { //Boyer-Morre�㷨����ȫ�棬���Bad Character��Good Suffix��
   int* bc = buildBC ( P ); int* gs = buildGS ( P ); //����BC���GS��
   size_t i = 0; //ģʽ��������ı�������ʼλ�ã���ʼʱ���ı�������룩
   while ( strlen ( T ) >= i + strlen ( P ) ) { //�������ƣ�������ܲ�ֹһ���ַ���ģʽ��
      int j = strlen ( P ) - 1; //��ģʽ����ĩβ���ַ���ʼ
      while ( P[j] == T[i + j] ) //��������ȶ�
         if ( 0 > --j ) break; /*DSA*/showProgress ( T, P, i, j ); printf ( "\n" ); getchar();
      if ( 0 > j ) //������ƥ���׺ == ����ģʽ����˵���Ѿ���ȫƥ�䣩
         break; //����ƥ��λ��
      else //�����ʵ����ƶ�ģʽ��
         i += __max ( gs[j], j - bc[ T[i + j] ] ); //λ��������BC���GS��ѡ�����
   }
   delete [] gs; delete [] bc; //����GS���BC��
   return i;
}