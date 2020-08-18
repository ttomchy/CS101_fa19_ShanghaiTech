/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

int countOnes1 ( unsigned int n ) { //ͳ������������չ������λ1��������O(ones)��������λ1������
   int ones = 0; //��������λ
   while ( 0 < n ) { //��n������0֮ǰ��������
      ones++; //������������һλΪ1��
      n &= n - 1; //�����ǰ��ҵ�1
   }
   return ones; //���ؼ���
} //��Ч��glibc�����ú���int __builtin_popcount (unsigned int n)
