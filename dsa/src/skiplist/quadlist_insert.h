/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> QlistNodePosi(T) //��e��Ϊp�ĺ�̡�b�����ڲ���Quadlist
Quadlist<T>::insertAfterAbove ( T const& e, QlistNodePosi(T) p, QlistNodePosi(T) b = NULL )
{  _size++; return p->insertAsSuccAbove ( e, b );  } //�����½ڵ�λ�ã�below = NULL��