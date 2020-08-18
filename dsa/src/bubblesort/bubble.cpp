/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "../_share/util.h"
/*DSA*/#include "../UniPrint/print_int_array.h"

void bubblesort ( int A[], int n ) { //���������㷨���汾0����0 <= n
   /*DSA*/int cmp = 0, swp = 0;
   while ( n-- ) { //����δȷ����ȫ������֮ǰ�����˽���ɨ�轻��
      for ( int i = 0; i < n; i++ ) { //����������Լ�鵱ǰ��ΧA[0, n)�ڵĸ�����Ԫ��
         if ( A[i] > A[i+1] ) { //һ��A[i]��A[i+1]������
            swap ( A[i], A[i+1] ); //����֮����
            /*DSA*/swp++; printf ( "%3d: ", n ); print ( A, n, i, i + 2 );
         }
         /*DSA*/cmp++;
      }
   }
   /*DSA*/printf ( "#comparison = %d, #swap = %d\n", cmp, swp );
} //�����㷨�����ܼ�ʱ��ǰ�˳������Ǳ�����n-1��ɨ�轻��