/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "../_share/util.h"
#include "../UniPrint/print.h"
#include "../vector/vector.h"
#include "../random/randomSortedVector.h"
#include "trivialMedian.h"
#include "median.h"

/******************************************************************************************
 * ��λ���㷨����
 ******************************************************************************************/
int main ( int argc, char* argv[] ) {
// ����������
   if ( 7 > argc ) { printf ( "Usage:\n\t%s <#tests> <n> <min1> <max1> <min2> <max2>\a\a\n", argv[0] ); return 1; }
   int nTest = atoi ( argv[1] ); //��������
   int n = atoi ( argv[2] ); //��������
   int min1 = atoi ( argv[3] ), max1 = atoi ( argv[4] ); //��ֵ��Χ
   int min2 = atoi ( argv[5] ), max2 = atoi ( argv[6] ); //��ֵ��Χ
   if ( ( nTest < 1 ) || ( n < 1 ) || ( max1 + 1 < min1 + n ) || ( max2 + 1 < min2 + n ) )
      { printf ( "arguments error\a\a\n" ); return 1; }
// �������
   srand ( ( unsigned int ) time ( NULL ) );
// ÿ�β���100��
   for ( int i = 0; i < nTest; i++ ) {
      // �����������
      Vector<int> A1 = randomSortedVector ( n, min1, max1 ); print ( A1 );
      Vector<int> A2 = randomSortedVector ( n, min2, max2 ); print ( A2 );
      // ������λ�������������㷨�������׳����Ľ���Ա�
      int m1 = median ( A1, 0, A2, 0, n );
      int m2 = trivialMedian ( A1, 0, n, A2, 0, n );
      if ( m1 == m2 ) { printf ( "\nmedian: %d = %d\a\n\n\n", m1, m2 ); }
      else          { printf ( "\nmedian: %d <Error> %d\a\a\n\n\n", m1, m2 ); getchar(); }
   }
   // ����
   return 0;
}