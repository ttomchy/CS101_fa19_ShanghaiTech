/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

int countOnes ( unsigned int n ) { //ͳ������������չ������λ1��������O(logn)
   int ones = 0; //��������λ
   while ( 0 < n ) { //��n������0֮ǰ��������
      ones += ( 1 & n ); //������λ����Ϊ1�����
      n >>= 1; //����һλ
   }
   return ones; //���ؼ���
} //��Ч��glibc�����ú���int __builtin_popcount (unsigned int n)
