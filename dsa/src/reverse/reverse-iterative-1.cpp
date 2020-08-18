/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "../_share/util.h"
/*DSA*/#include "../UniPrint/print_int_array.h"

void reverse ( int* A, int lo, int hi ) { //���鵹�ã��淶����֮��ĵ����棩
   while ( lo < hi ) //��while�滻��ת��־��if����ȫ��Ч
      swap ( A[lo++], A[hi--] ); //����A[lo]��A[hi]����������������
} //O(hi - lo + 1)