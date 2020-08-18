/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> void PQ_LeftHeap<T>::insert ( T e ) { //���ںϲ������Ĵ��������㷨
   BinNodePosi(T) v = new BinNode<T> ( e ); //Ϊe����һ���������ڵ�
   _root = merge ( _root, v ); //ͨ���ϲ�����½ڵ�Ĳ���
//   _root->parent = NULL; //��Ȼ��ʱ�ѷǿգ�������Ӧ���ø�������
   _size++; //���¹�ģ
}