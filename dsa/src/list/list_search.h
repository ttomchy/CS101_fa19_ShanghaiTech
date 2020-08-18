/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //�������б��ڽڵ�p��������trailer����n�����棩ǰ���У��ҵ�������e�������
ListNodePosi(T) List<T>::search ( T const& e, int n, ListNodePosi(T) p ) const {
// assert: 0 <= n <= rank(p) < _size
   /*DSA*/printf ( "searching for " ); print ( e ); printf ( " :\n" );
   while ( 0 <= n-- ) //����p�������n��ǰ����������������Ƚ�
      /*DSA*/{ printf ( "  <%4d>", p->pred->data );
      if ( ( ( p = p->pred )->data ) <= e ) break; //ֱ�����С���ֵԽ���ΧԽ��
      /*DSA*/} printf ( "\n" );
// assert: ����λ��p�ط����������Լ���������ܴ�ǰ���һ�ιؼ���ȽϿ���û�����壨��Ч����-inf�Ƚϣ�
   return p; //���ز�����ֹ��λ��
} //ʧ��ʱ������������߽��ǰ����������header�����������߿�ͨ��valid()�жϳɹ����