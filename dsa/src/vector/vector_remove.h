/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> T Vector<T>::remove ( Rank r ) { //ɾ����������Ϊr��Ԫ�أ�0 <= r < size
   T e = _elem[r]; //���ݱ�ɾ��Ԫ��
   remove ( r, r + 1 ); //��������ɾ���㷨����Ч�ڶ�����[r, r + 1)��ɾ��
   return e; //���ر�ɾ��Ԫ��
}