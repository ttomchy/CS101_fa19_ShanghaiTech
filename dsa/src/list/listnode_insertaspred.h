/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //��e������ǰ�ڵ�֮ǰ�����ڵ�ǰ�ڵ������б������ڱ�ͷ�ڵ�header��
ListNodePosi(T) ListNode<T>::insertAsPred ( T const& e ) {
   ListNodePosi(T) x = new ListNode ( e, pred, this ); //�����½ڵ�
   pred->succ = x; pred = x; //������������
   return x; //�����½ڵ��λ��
}