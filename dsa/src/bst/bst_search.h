/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> BinNodePosi(T) & BST<T>::search ( const T& e ) //��BST�в��ҹؼ���e
{ return searchIn ( _root, e, _hot = NULL ); } //����Ŀ��ڵ�λ�õ����ã��Ա�������롢ɾ������
