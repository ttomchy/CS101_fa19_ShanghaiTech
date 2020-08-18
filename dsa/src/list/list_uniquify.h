/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> int List<T>::uniquify() { //�����޳��ظ�Ԫ�أ�Ч�ʸ���
   if ( _size < 2 ) return 0; //ƽ���б���Ȼ���ظ�
   int oldSize = _size; //��¼ԭ��ģ
   ListNodePosi(T) p = first(); ListNodePosi(T) q; //pΪ��������㣬qΪ����
   while ( trailer != ( q = p->succ ) ) //����������ڵĽڵ��(p, q)
      if ( p->data != q->data ) p = q; //�����죬��ת����һ����
      else remove ( q ); //������ͬ����ɾ������
   return oldSize - _size; //�б��ģ�仯��������ɾ��Ԫ������
}