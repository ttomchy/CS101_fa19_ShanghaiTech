/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#include "../nest_stack/nest.h"

/******************************************************************************************
 * ��ʾ���ʽƬ��exp[lo, hi]����ԭ���ʽ����
 ******************************************************************************************/
void displaySubstring ( const char exp[], int lo, int hi ) {
   for ( int i = 0; i < lo; i++ ) printf ( " " );
   for ( int i = lo; i <= hi; i++ ) printf ( "%c", exp[i] );
   printf ( "\n" );
}

/******************************************************************************************
 * ��ʾ���ʽɨ�����
 ******************************************************************************************/
void displayProgress ( const char exp[], int i, Stack<char> S ) {
// ���ʽ
   system ( "cls" );
   printf ( "\n%s\n", exp );
   for ( int j = 0; j < i; j++ )   printf ( "-" );
   printf ( "^\n\n\n" );
// ջ
   print ( S ); getchar();
}
