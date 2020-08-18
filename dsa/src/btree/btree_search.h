/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> BTNodePosi(T) BTree<T>::search ( const T& e ) { //��B-���в��ҹؼ���e
   BTNodePosi(T) v = _root; _hot = NULL; //�Ӹ��ڵ����
   while ( v ) { //������
      Rank r = v->key.search ( e ); //�ڵ�ǰ�ڵ��У��ҵ�������e�����ؼ���
      if ( ( 0 <= r ) && ( e == v->key[r] ) ) return v; //�ɹ����ڵ�ǰ�ڵ�������Ŀ��ؼ���
      _hot = v; v = v->child[r + 1]; //����ת���Ӧ������_hotָ���丸����������I/O�����ʱ��
   } //�������������Ƕ��ֲ��ң�����ͨ����_order��ֱ��˳�����
   return NULL; //ʧ�ܣ����յִ��ⲿ�ڵ�
}