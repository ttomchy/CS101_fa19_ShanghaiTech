/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "../_share/util.h"
/*DSA*/#include "../UniPrint/print_int_array.h"

void bubblesort2 ( int A[], int n ) { //���������㷨���汾2����0 <= n
   /*DSA*/int cmp = 0, swp = 0;
   for ( int m; 1 < n; n = m ) { //����δȷ����ȫ������֮ǰ�����˽���ɨ�轻��
      for ( int i = m = 1; i < n; i++ ) { //����������Լ�鵱ǰ��ΧA[0, m)�ڵĸ�����Ԫ��
         if ( A[i-1] > A[i] ) { //һ��A[i-1]��A[i]������
            swap ( A[i-1], A[i] ); //����֮����
            m = i; //���´���������ĳ���
            /*DSA*/swp++; printf ( "%3d: ", n ); print ( A, n, i - 1, i + 1 );
         }
         /*DSA*/cmp++;
      }
   }
   /*DSA*/printf ( "#comparison = %d, #swap = %d\n", cmp, swp );
} //��������m������������������䣺�ȿ���ǰ�˳������ɼ���ÿ�ˣ������У�ɨ�轻����Ԫ�رȽϲ���
//��β�����򣨻�ӽ����򣩵����룬�㷨�������ٶȴ�����
//Ԫ�ؽ����Ĵ�����ȡ�����������У���汾0�Ͱ汾1��ͬ