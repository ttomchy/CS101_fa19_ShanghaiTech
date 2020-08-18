/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> void Vector<T>::sort ( Rank lo, Rank hi ) { //��������[lo, hi)����
   switch ( rand() % 5 ) { //���ѡȡ�����㷨���ɸ��ݾ���������ص����ѡȡ������
      case 1:  bubbleSort ( lo, hi ); break; //��������
      case 2:  selectionSort ( lo, hi ); break; //ѡ������ϰ�⣩
      case 3:  mergeSort ( lo, hi ); break; //�鲢����
      case 4:  heapSort ( lo, hi ); break; //�������Ժ���ܣ�
      default: quickSort ( lo, hi ); break; //���������Ժ���ܣ�
   }
   /*DSA*/ //selectionSort(lo, hi);
}