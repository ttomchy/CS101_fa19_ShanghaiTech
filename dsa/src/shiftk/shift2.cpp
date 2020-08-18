/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "../reverse/reverse.h"
/*DSA*/#include "../UniPrint/print_int_array.h"

int shift2 ( int* A, int n, int k ) { //���������㷨��������ѭ������kλ��O(3n)
   k %= n; //ȷ��k <= n
   reverse ( A, k ); //������A[0, k)���ã�O(3k/2)�β���
   /*DSA*/print ( A, n, 0, k );
   reverse ( A + k, n - k ); //������A[k, n)���ã�O(3(n - k)/2)�β���
   /*DSA*/print ( A, n, k, n );
   reverse ( A, n ); //������������A[0, n)��O(3n/2)�β���
   /*DSA*/print ( A, n );
   return 3 * n; //�����ۼƲ����������Ա��������㷨�Ƚϣ�3/2 * (k + (n - k) + n) = 3n
}
