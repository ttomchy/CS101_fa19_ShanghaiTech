/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "../PQ/PQ.h" //�������ȼ�����ADT
#include "../BinTree/BinTree.h" //����������ڵ�ģ����

template <typename T>
class PQ_LeftHeap : public PQ<T>, public BinTree<T> { //���ڶ�����������ʽ����ʽʵ�ֵ�PQ
   /*DSA*/friend class UniPrint; //��ʾ���ʹ�ã����򲻱���������
public:
   PQ_LeftHeap() { } //Ĭ�Ϲ���
   PQ_LeftHeap ( T* E, int n ) //�������죺�ɸĽ�ΪFloyd�����㷨
   {  for ( int i = 0; i < n; i++ ) insert ( E[i] );  }
   void insert ( T ); //���ձȽ���ȷ�������ȼ��������Ԫ��
   T getMax(); //ȡ�����ȼ���ߵ�Ԫ��
   T delMax(); //ɾ�����ȼ���ߵ�Ԫ��
}; //PQ_LeftHeap

#include "PQ_LeftHeap_implementation.h"