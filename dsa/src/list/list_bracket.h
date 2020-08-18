/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //�����±����������ͨ����ֱ�ӷ����б�ڵ㣨�䷽�㣬Ч�ʵͣ������ã�
T& List<T>::operator[] ( Rank r ) const { //assert: 0 <= r < size
   ListNodePosi(T) p = first(); //���׽ڵ����
   while ( 0 < r-- ) p = p->succ; //˳����r���ڵ㼴��
   return p->data; //Ŀ��ڵ㣬������������Ԫ��
}