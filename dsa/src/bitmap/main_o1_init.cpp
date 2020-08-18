/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma warning(disable : 4996 4800)
#include "../_share/util.h"
#include "Bitmap_O1_init.h"

/******************************************************************************************
 * ����λͼ
 ******************************************************************************************/
int testBitmap ( int n ) {
   bool* B = new bool[n]; memset ( B, 0, n * sizeof ( bool ) ); //����λͼ���������漴O(n)ʱ���ʼ��
   Bitmap M ( n );
   for ( int i = 0; i < 9 * n; i++ ) {
      Rank k = dice ( n );
      if ( dice ( 2 ) ) {
         printf ( "set(%d) ...", k ); //set(k)
         B[k] = true; M.set ( k );
      } else {
         printf ( "clear(%d) ...", k ); //clear(k)
         B[k] = false; M.clear ( k );
      }
      printf ( "done\n CRC: " );
      for ( int j = 0; j < n; j++ ) printf ( "%6c", B[j] == M.test ( j ) ? ' ' : '!' );
      printf ( "\n B[]: " );
      for ( int j = 0; j < n; j++ ) printf ( "%6c", B[j] ? 'x' : '.' );
      printf ( "\n M[]: " );
      for ( int j = 0; j < n; j++ ) printf ( "%6c", M.test ( j ) ? 'x' : '.' );
      printf ( "\n\n\n" );
   }
   delete [] B;
   return 0;
}

/******************************************************************************************
 * ����λͼ
 ******************************************************************************************/
int main ( int argc, char* argv[] ) {
   if ( 2 > argc ) { printf ( "Usage: %s <size of test>\a\a\n", argv[0] ); return 1; }
   srand ( ( unsigned int ) time ( NULL ) ); //�����������
   return testBitmap ( atoi ( argv[1] ) ); //��������
}