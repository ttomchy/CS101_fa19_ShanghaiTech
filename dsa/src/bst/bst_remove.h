/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> bool BST<T>::remove ( const T& e ) { //��BST����ɾ���ؼ���e
   BinNodePosi(T) & x = search ( e ); if ( !x ) return false; //ȷ��Ŀ����ڣ�����_hot�����ã�
   removeAt ( x, _hot ); _size--; //ʵʩɾ��
   updateHeightAbove ( _hot ); //����_hot�����������ȵĸ߶�
   return true;
} //ɾ���ɹ�����ɷ���ֵָʾ
