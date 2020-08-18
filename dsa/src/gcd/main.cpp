/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#include "..\_share\util.h"

#define ABS(x) ( (0 < (x)) ? (x) : (-(x)) )

__int64 gcdEU_R ( __int64 a, __int64 b );
__int64 gcdEU ( __int64 a, __int64 b );
__int64 gcdCN ( __int64 a, __int64 b );

__int64 gcd ( __int64 a, __int64 b ) {
   switch ( rand() % 3 ) {
      case 0:  return gcdEU_R ( ABS ( a ), ABS ( b ) );
      case 1:  return gcdEU ( ABS ( a ), ABS ( b ) );
      default: return gcdCN ( ABS ( a ), ABS ( b ) );
   }
}

/******************************************************************************************
 * ����GCD
 ******************************************************************************************/
int main ( int argc, char* argv[] ) {
// ������
   if ( 3 > argc ) { fprintf ( stderr, "Usage: %s <a> <b>\n", argv[0] ); return 1; }
   srand ( ( unsigned int ) time ( NULL ) );
// ����GCD
   do {
      __int64 a = _atoi64 ( argv[1] ), b = _atoi64 ( argv[2] );
      printf ( "Chinese:   GCD(%22I64d, %22I64d) = %22I64d\n",   a, b, gcdCN ( ABS ( a ), ABS ( b ) ) );
      printf ( "Euclidean: GCD(%22I64d, %22I64d) = %22I64d = %22I64d\n",   a, b, gcdEU ( ABS ( a ), ABS ( b ) ), gcdEU_R ( ABS ( a ), ABS ( b ) ) );
      printf ( "Random:    GCD(%22I64d, %22I64d) = %22I64d = %22I64d\n\n",   a, b, gcd ( a, b ), gcd ( a, b ) );
      argc -= 2; argv += 2;
   } while ( 2 < argc );
// �������GCD
   for ( int i = 0; i < 9; i++ ) {
      __int64 a = 1, b = 1;
      for ( int k = 0; k < 4; k++ ) { //�������������a��b
         ( rand() & 1 ) ? a *= ( 1 + rand() ) : a += rand();
         ( rand() & 1 ) ? b *= ( 1 + rand() ) : b += rand();
      }
      printf ( "Chinese:   GCD(%22I64d, %22I64d) = %22I64d\n",   a, b, gcdCN ( ABS ( a ), ABS ( b ) ) );
      printf ( "Euclidean: GCD(%22I64d, %22I64d) = %22I64d = %22I64d\n",   a, b, gcdEU ( ABS ( a ), ABS ( b ) ), gcdEU_R ( ABS ( a ), ABS ( b ) ) );
      printf ( "Random:    GCD(%22I64d, %22I64d) = %22I64d = %22I64d\n\n",   a, b, gcd ( a, b ), gcd ( a, b ) );
   }
   return 0;
}
