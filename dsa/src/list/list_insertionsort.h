/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //�б�Ĳ��������㷨������ʼ��λ��p��n��Ԫ������
void List<T>::insertionSort ( ListNodePosi(T) p, int n ) { //valid(p) && rank(p) + n <= size
   /*DSA*/printf ( "InsertionSort ...\n" );
   for ( int r = 0; r < n; r++ ) { //��һΪ���ڵ�
      insertA ( search ( p->data, r, p ), p->data ); //�����ʵ���λ�ò�����
      p = p->succ; remove ( p->pred ); //ת����һ�ڵ�
   }
}