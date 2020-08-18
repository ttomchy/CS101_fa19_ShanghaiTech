/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/


#include   "nest.h"

/******************************************************************************************
 * �����ʽ�����Ƿ�ƥ��
 ******************************************************************************************/
int main ( int argc, char* argv[] ) {
// ������
   if ( 2 > argc ) { //����Ҫ�ṩһ���������ַ���
      fprintf ( stderr, "\nUsage: %s <string#1> <string#2> ... \n", argv[0] );
      fprintf ( stderr, "For example %s (a[i-1][j+1])+a[i+1][j-1])*2\n", argv[0] );
      return -1;
   }
// ��һ�������Ƿ�ƥ��
   for ( int i = 1; i < argc; i++ ) {
      char* s = argv[i];   printf ( "\n��飺%s\n", s );
      paren ( s, 0, strlen ( s ) - 1 ) ?
      printf ( "\n%s: ƥ��\a\n", s ) :
      printf ( "\n%s: ��ƥ��\a\a\n", s );
      getchar();
   }
   return 0;
}