/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

//�������еĵ�i������ʵʩ���˲�����i < _size
template <typename T> Rank PQ_ComplHeap<T>::percolateUp ( Rank i ) {
   while ( ParentValid ( i ) ) { //ֻҪi�и��ף���δ�ִ�Ѷ�������
      Rank j = Parent ( i ); //��i֮������j
      if ( lt ( _elem[i], _elem[j] ) ) break; //һ����ǰ���Ӳ������������������
      swap ( _elem[i], _elem[j] ); i = j; //���򣬸��ӽ���λ�ã�������������һ��
   } //while
   return i; //�����������յִ��λ��
}
