/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/


#include "hanoi.h"

/******************************************************************************************
 * ���ջS�ڸ߶�i�ķֲ�
 ******************************************************************************************/
void display ( Stack<int>& S, int i ) {
   int diskR = ( i < S.size() ) ? S[i] : 0; //ͨ��Vecotr[]�ӿڣ���ȡ�߶�i�����ӵİ뾶
   for ( int j = 0; j < nDisk - diskR; j++ )   printf ( " " );
   for ( int j = 0; j < diskR; j++ )    printf ( "=" );
   printf ( "|" );
   for ( int j = 0; j < diskR; j++ )    printf ( "=" );
   for ( int j = 0; j < nDisk - diskR; j++ )   printf ( " " );
}

/******************************************************************************************
 * ��ʾ����ջ���ݣ�ʹ��ȫ�ֱ�����
 ******************************************************************************************/
void displayHanoi() {
   system ( "cls" );   printf ( "\n\n" );
   for ( int i = nDisk - 1; i >= 0; i-- ) //�Զ����£���ÿһ�߶Ȳ�Σ���������ࣩ��������
      { display ( Sx, i ); display ( Sy, i ); display ( Sz, i ); printf ( "\n" ); }
   for ( int j = 0; j < 3 * ( 2 * nDisk + 1 ); j++ )   printf ( "=" );   printf ( "\n" ); //��ʾ����
   getchar();
}