/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> int Vector<T>::uniquify() { //���������ظ�Ԫ���޳��㷨����Ч�棩
   Rank i = 0, j = 0; //���Ի��조���ڡ�Ԫ�ص���
   while ( ++j < _size ) //��һɨ�裬ֱ��ĩԪ��
      if ( _elem[i] != _elem[j] ) //������ͬ��
         _elem[++i] = _elem[j]; //���ֲ�ͬԪ��ʱ����ǰ����������ǰ���Ҳ�
   _size = ++i; shrink(); //ֱ�ӽس�β������Ԫ��
   return j - i; //������ģ�仯��������ɾ��Ԫ������
}