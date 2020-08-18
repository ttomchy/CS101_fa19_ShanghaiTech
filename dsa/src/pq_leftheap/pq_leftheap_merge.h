/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //����������ȼ�ȷ�����˵ķ�ʽ���ϲ���a��bΪ���ڵ��������ʽ��
static BinNodePosi(T) merge ( BinNodePosi(T) a, BinNodePosi(T) b ) {
   if ( ! a ) return b; //�˻����
   if ( ! b ) return a; //�˻����
   if ( lt ( a->data, b->data ) ) swap ( a, b ); //һ�����������ȷ��b����
   a->rc = merge ( a->rc, b ); //��a�����Ӷѣ���b�ϲ�
   a->rc->parent = a; //�����¸��ӹ�ϵ
   if ( !a->lc || a->lc->npl < a->rc->npl ) //���б�Ҫ
      swap ( a->lc, a->rc ); //����a�������Ӷѣ���ȷ�����Ӷѵ�npl����
   a->npl = a->rc ? a->rc->npl + 1 : 1; //����a��npl
   return a; //���غϲ���ĶѶ�
} //���㷨ֻʵ�ֽṹ�ϵĺϲ����ѵĹ�ģ�����ϲ�����߸������