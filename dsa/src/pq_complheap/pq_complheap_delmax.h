/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> T PQ_ComplHeap<T>::delMax() { //ɾ���ǿ���ȫ����������ȼ���ߵĴ���
   T maxElem = _elem[0]; _elem[0] = _elem[ --_size ]; //ժ���Ѷ����״���������֮��ĩ����
   percolateDown ( _size, 0 ); //���¶Ѷ�ʵʩ����
   return maxElem; //���ش�ǰ���ݵ�������
}
