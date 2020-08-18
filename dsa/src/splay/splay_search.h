/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> BinNodePosi(T) & Splay<T>::search ( const T& e ) { //����չ���в���e
   BinNodePosi(T) p = searchIn ( _root, e, _hot = NULL );
   _root = splay ( p ? p : _hot ); //�����һ�������ʵĽڵ���չ����
   return _root;
} //������BST��ͬ�����۲��ҳɹ����_root��ָ����󱻷��ʵĽڵ�