/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //ɾ��Quadlist��λ��p���Ľڵ㣬�������д�ŵĴ���
T Quadlist<T>::remove ( QlistNodePosi(T) p ) { //assert: pΪQuadlist�еĺϷ�λ��
   p->pred->succ = p->succ; p->succ->pred = p->pred; _size--;//ժ���ڵ�
   T e = p->entry; delete p; //���ݴ������ͷŽڵ�
   return e; //���ش���
}

template <typename T> int Quadlist<T>::clear() { //���Quadlist
   int oldSize = _size;
   while ( 0 < _size ) remove ( header->succ ); //���ɾ�����нڵ�
   return oldSize;
}