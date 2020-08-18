/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> Rank Vector<T>::bubble ( Rank lo, Rank hi ) { //һ��ɨ�轻��
   Rank last = lo; //���Ҳ������Գ�ʼ��Ϊ[lo - 1, lo]
   while ( ++lo < hi ) //�������ң���һ����������Ԫ��
      if ( _elem[lo - 1] > _elem[lo] ) { //��������
         last = lo; //�������Ҳ������λ�ü�¼����
         swap ( _elem[lo - 1], _elem[lo] ); //ͨ������ʹ�ֲ�����
      }
   return last; //�������Ҳ�������λ��
}