/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "../PQ/PQ.h" //�������ȼ�����ADT
#include "../List/List.h" //�����б�
template <typename T> class PQ_List : public PQ<T>, public List<T> { //�����б�ʵ�ֵ����ȼ�����
   /*DSA*/friend class UniPrint; //��ʾ���ʹ�ã����򲻱���������
public:
   PQ_List() { } //Ĭ�Ϲ���
   PQ_List ( T* E, int n ) { while ( 0 < n-- ) insertAsFirst ( ( E[n] ) ); } //��������
   void insert ( T e ) { insertAsLast ( e ); } //ֱ�ӽ���Ԫ�ز�������ĩβ
   T getMax() { return selectMax()->data; } //ȡ�����ȼ���ߵ�Ԫ��
   T delMax() { return remove ( selectMax() ); } //ɾ�����ȼ���ߵ�Ԫ��
}; //PQ_List
