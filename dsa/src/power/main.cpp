/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#include<iostream>
using namespace std;

__int64 powerBF ( __int64, int );
__int64 power ( __int64, int );
__int64 power2BF_I ( int );
__int64 power2_I ( int );
__int64 power2BF ( int );
__int64 power2 ( int );

/******************************************************************************************
 * ����Power
 ******************************************************************************************/
int main ( int argc, char* argv[] ) {
   __int64 a; int r;
   if ( 3 > argc ) {  cout << "Usage: " << argv[0] << "<base><exponent>" << endl; return 1;  } //������
   a = _atoi64 ( argv[1] ); r = atoi ( argv[2] ); //��ȡ����
   printf ( "\n2 ^ %d  =  %I64d  =  %I64d\n\n", r, power2BF_I ( r ), power2_I ( r ) ); //������
   printf ( "\n2 ^ %d  =  %I64d  =  %I64d\n\n", r, power2BF ( r ), power2 ( r ) ); //�ݹ��
   printf ( "\n%I64d ^ %d  =  %I64d  =  %I64d\n\n", a, r, powerBF ( a, r ), power ( a, r ) ); //ͨ���㷨������
   return 0;
}