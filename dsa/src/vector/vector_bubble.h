/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> bool Vector<T>::bubble ( Rank lo, Rank hi ) { //һ��ɨ�轻��
   bool sorted = true; //���������־
   while ( ++lo < hi ) //�������ң���һ����������Ԫ��
      if ( _elem[lo - 1] > _elem[lo] ) { //��������
         sorted = false; //��ζ����δ�������򣬲���Ҫ
         swap ( _elem[lo - 1], _elem[lo] ); //ͨ������ʹ�ֲ�����
      }
   return sorted; //���������־
}