/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "../_share/util.h"
/*DSA*/#include "../UniPrint/print_int_array.h"

void bubblesort1B ( int A[], int n ) { //���������㷨���汾1B����汾1A��ȫ�ȼۣ���0 <= n
   /*DSA*/int cmp = 0, swp = 0;
   for ( bool sorted = false; sorted = !sorted; n-- ) { //����δȷ����ȫ������֮ǰ�����˽���ɨ�轻��
      for ( int i = 1; i < n; i++ ) { //����������Լ�鵱ǰ��ΧA[0, n)�ڵĸ�����Ԫ��
         if ( A[i-1] > A[i] ) { //һ��A[i-1]��A[i]������
            swap ( A[i-1], A[i] ); //����֮����
            sorted = false; //�����������ܱ�֤����Ҫ��������־
            /*DSA*/swp++; printf ( "%3d: ", n ); print ( A, n, i - 1, i + 1 );
         }
         /*DSA*/cmp++;
      }
   }
   /*DSA*/printf ( "#comparison = %d, #swap = %d\n", cmp, swp );
} //���������ͱ�־λsorted���ɼ�ʱ��ǰ�˳�����������������n-1��ɨ�轻��
//��β�����򣨻�ӽ����򣩵����룬�㷨��Ȼ�ಽ����������������Ԫ�رȽϴ�������