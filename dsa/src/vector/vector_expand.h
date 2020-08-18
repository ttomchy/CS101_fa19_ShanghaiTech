/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> void Vector<T>::expand() { //�����ռ䲻��ʱ����
   if ( _size < _capacity ) return; //��δ��Աʱ����������
   if ( _capacity < DEFAULT_CAPACITY ) _capacity = DEFAULT_CAPACITY; //��������С����
   T* oldElem = _elem;  _elem = new T[_capacity <<= 1]; //�����ӱ�
   for ( int i = 0; i < _size; i++ )
      _elem[i] = oldElem[i]; //����ԭ�������ݣ�TΪ�������ͣ��������ظ�ֵ������'='��
   /*DSA*/ //printf("\n_ELEM [%x]*%d/%d expanded and shift to [%x]*%d/%d\n", oldElem, _size, _capacity/2, _elem, _size, _capacity);
   delete [] oldElem; //�ͷ�ԭ�ռ�
}