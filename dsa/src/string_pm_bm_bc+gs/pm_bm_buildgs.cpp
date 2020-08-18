/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "../string_pm/string_pm_test.h"

int* buildSS ( char* P ) { //�������ƥ���׺���ȱ�O(m)
   int m = strlen ( P ); int* ss = new int[m]; //Suffix Size��
   ss[m - 1]  =  m; //�����һ���ַ����ԣ���֮ƥ������׺��������P��
// ���£��ӵ����ڶ����ַ�����������ɨ��P�����μ����ss[]�������
   for ( int lo = m - 1, hi = m - 1, j = lo - 1; j >= 0; j -- )
      if ( ( lo < j ) && ( ss[m - hi + j - 1] <= j - lo ) ) //���һ
         ss[j] =  ss[m - hi + j - 1]; //ֱ�����ô�ǰ�Ѽ������ss[]
      else { //�����
         hi = j; lo = __min ( lo, hi );
         while ( ( 0 <= lo ) && ( P[lo] == P[m - hi + lo - 1] ) ) //����ѭ����
            lo--; //����Աȴ���(lo, hi]ǰ�˵��ַ�
         ss[j] = hi - lo;
      }
   /*DSA*/printf ( "-- ss[] Table -------\n" );
   /*DSA*/for ( int i = 0; i < m; i ++ ) printf ( "%4d", i ); printf ( "\n" );
   /*DSA*/printString ( P ); printf ( "\n" );
   /*DSA*/for ( int i = 0; i < m; i ++ ) printf ( "%4d", ss[i] ); printf ( "\n\n" );
   return ss;
}

int* buildGS ( char* P ) { //����ú�׺λ������O(m)
   int* ss = buildSS ( P ); //Suffix Size table
   size_t m = strlen ( P ); int* gs = new int[m]; //Good Suffix shift table
   for ( size_t j = 0; j < m; j ++ ) gs[j] = m; //��ʼ��
   for ( size_t i = 0, j = m - 1; j < UINT_MAX; j -- ) //������һɨ����ַ�P[j]
      if ( j + 1 == ss[j] ) //��P[0, j] = P[m - j - 1, m)����
         while ( i < m - j - 1 ) //����P[m - j - 1]����ÿ���ַ�P[i]���ԣ�����ѭ������
            gs[i++] = m - j - 1; //m - j - 1����gs[i]��һ��ѡ��
   for ( size_t j = 0; j < m - 1; j ++ ) //�����㷨������ɨ��P[]���ַ���gs[j]���ϵݼ���ֱ����С
      gs[m - ss[j] - 1] = m - j - 1; //m - j - 1������gs[m - ss[j] - 1]ֵ��һ��ѡ��
   /*DSA*/printGS ( P, gs );
   delete [] ss; return gs;
}
