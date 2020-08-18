/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> BinNodePosi(T) RedBlack<T>::insert ( const T& e ) { //��e��������
   BinNodePosi(T) & x = search ( e ); if ( x ) return x; //ȷ��Ŀ�겻���ڣ������_hot�����ã�
   x = new BinNode<T> ( e, _hot, NULL, NULL, -1 ); _size++; //������ڵ�x����_hotΪ�����ڸ߶�-1
   solveDoubleRed ( x ); return x ? x : _hot->parent; //��˫�������󣬼��ɷ���
} //����e�Ƿ������ԭ���У�����ʱ����x->data == e
