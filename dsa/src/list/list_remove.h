/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> T List<T>::remove ( ListNodePosi(T) p ) { //ɾ���Ϸ��ڵ�p����������ֵ
   T e = p->data; //���ݴ�ɾ���ڵ����ֵ���ٶ�T���Ϳ�ֱ�Ӹ�ֵ��
   p->pred->succ = p->succ; p->succ->pred = p->pred; //��̡�ǰ��
   delete p; _size--; //�ͷŽڵ㣬���¹�ģ
   return e; //���ر��ݵ���ֵ
}