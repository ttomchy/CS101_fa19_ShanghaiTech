/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> BinNodePosi(T) BST<T>::insert ( const T& e ) { //���ؼ���e����BST����
   BinNodePosi(T) & x = search ( e ); if ( x ) return x; //ȷ��Ŀ�겻���ڣ������_hot�����ã�
   x = new BinNode<T> ( e, _hot ); //�����½ڵ�x����eΪ�ؼ��룬��_hotΪ��
   _size++; //����ȫ����ģ
   updateHeightAbove ( x ); //����x�����������ȵĸ߶�
   return x; //�²���Ľڵ㣬��ΪҶ��
} //����e�Ƿ������ԭ���У�����ʱ����x->data == e
