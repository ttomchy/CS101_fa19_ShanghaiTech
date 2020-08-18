/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //�����鲢����
void Vector<T>::mergeSort ( Rank lo, Rank hi ) { //0 <= lo < hi <= size
   /*DSA*/printf ( "\tMERGEsort [%3d, %3d)\n", lo , hi );
   if ( hi - lo < 2 ) return; //��Ԫ��������Ȼ���򣬷���...
   int mi = ( lo + hi ) / 2; //���е�Ϊ��
   mergeSort ( lo, mi ); mergeSort ( mi, hi ); //�ֱ�����
   merge ( lo, mi, hi ); //�鲢
}