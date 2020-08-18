/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "../Vector/Vector.h" //�������ؼ̳л��ƣ���������
#include "../PQ/PQ.h" //�������ȼ�����ADTʵ�ֵ�
template <typename T> class PQ_ComplHeap : public PQ<T>, public Vector<T> { //��ȫ�����
   /*DSA*/friend class UniPrint; //��ʾ���ʹ�ã����򲻱���������
protected:
   Rank percolateDown ( Rank n, Rank i ); //����
   Rank percolateUp ( Rank i ); //����
   void heapify ( Rank n ); //Floyd�����㷨
public:
   PQ_ComplHeap() { } //Ĭ�Ϲ���
   PQ_ComplHeap ( T* A, Rank n ) { copyFrom ( A, 0, n ); heapify ( n ); } //��������
   void insert ( T ); //���ձȽ���ȷ�������ȼ����򣬲������
   T getMax(); //��ȡ���ȼ���ߵĴ���
   T delMax(); //ɾ�����ȼ���ߵĴ���
}; //PQ_ComplHeap
/*DSA*/#include "PQ_ComplHeap_macro.h"

#include "PQ_ComplHeap_implementation.h"
