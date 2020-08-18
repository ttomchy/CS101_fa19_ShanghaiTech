/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> T PQ_LeftHeap<T>::delMax() { //���ںϲ������Ĵ���ɾ���㷨����ǰ���зǿգ�
   BinNodePosi(T) lHeap = _root->lc; //���Ӷ�
   BinNodePosi(T) rHeap = _root->rc; //���Ӷ�
   T e = _root->data; delete _root; _size--; //ɾ�����ڵ�
   _root = merge ( lHeap, rHeap ); //ԭ�����ӶѺϲ�
//   if ( _root ) _root->parent = NULL; //���ѷǿգ�������Ӧ���ø�������
   return e; //����ԭ���ڵ��������
}