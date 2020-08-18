/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> bool AVL<T>::remove ( const T& e ) { //��AVL����ɾ���ؼ���e
   BinNodePosi(T) & x = search ( e ); if ( !x ) return false; //ȷ��Ŀ����ڣ�����_hot�����ã�
   removeAt ( x, _hot ); _size--; //�Ȱ�BST����ɾ��֮���˺�ԭ�ڵ�֮��_hot�������Ⱦ�����ʧ�⣩
   for ( BinNodePosi(T) g = _hot; g; g = g->parent ) { //��_hot�������ϣ�������������g
      if ( !AvlBalanced ( *g ) ) //һ������gʧ�⣬�򣨲��á�3 + 4���㷨��ʹ֮���⣬��������������
         g = FromParentTo ( *g ) = rotateAt ( tallerChild ( tallerChild ( g ) ) ); //ԭ����
      updateHeight ( g ); //��������߶ȣ�ע�⣺����gδʧ�⣬�߶�����ܽ��ͣ�
   } //��������Omega(logn)�ε������������Ƿ�����������ȫ���߶Ⱦ����ܽ���
   return true; //ɾ���ɹ�
} //��Ŀ��ڵ�����ұ�ɾ��������true�����򷵻�false
