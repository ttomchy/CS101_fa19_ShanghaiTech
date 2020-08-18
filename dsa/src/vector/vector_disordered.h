/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> int Vector<T>::disordered() const { //������������������Ԫ�ضԵ�����
   int n = 0; //������
   for ( int i = 1; i < _size; i++ ) //��һ���_size - 1������Ԫ��
      if ( _elem[i - 1] > _elem[i] ) n++; //���������
   return n; //���������ҽ���n = 0
}
