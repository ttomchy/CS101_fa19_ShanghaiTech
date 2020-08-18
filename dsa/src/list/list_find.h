/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //�������б��ڽڵ�p��������trailer����n�����棩ǰ���У��ҵ�����e�������
ListNodePosi(T) List<T>::find ( T const& e, int n, ListNodePosi(T) p ) const {
   while ( 0 < n-- ) //��0 <= n <= rank(p) < _size������p�������n��ǰ������������
      if ( e == ( p = p->pred )->data ) return p; //����ȶԣ�ֱ�����л�ΧԽ��
   return NULL; //pԽ����߽���ζ�������ڲ���e������ʧ��
} //ʧ��ʱ������NULL