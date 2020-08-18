/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

// ��λ���㷨�����棺Ч�ʵͣ���������max(n1, n2)��С�����
template <typename T> //������S1[lo1, lo1 + n1)��S2[lo2, lo2 + n2)�ֱ���������������ظ�
T trivialMedian ( Vector<T>& S1, int lo1, int n1, Vector<T>& S2, int lo2, int n2 ) {
   /*DSA*/printf ( "trivial median\n" );
   int hi1 = lo1 + n1, hi2 = lo2 + n2;
   Vector<T> S; //�����������������鲢Ϊһ����������
   while ( ( lo1 < hi1 ) && ( lo2 < hi2 ) ) {
      while ( ( lo1 < hi1 ) && S1[lo1] <= S2[lo2] ) S.insert ( S1[lo1 ++] );
      while ( ( lo2 < hi2 ) && S2[lo2] <= S1[lo1] ) S.insert ( S2[lo2 ++] );
   }
   while ( lo1 < hi1 ) S.insert ( S1[lo1 ++] );
   while ( lo2 < hi2 ) S.insert ( S1[lo2 ++] ); /*DSA*/print ( S );
   return S[ ( n1 + n2 ) / 2]; //ֱ�ӷ��ع鲢��������λ��
}