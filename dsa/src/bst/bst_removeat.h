/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

/******************************************************************************************
 * BST�ڵ�ɾ���㷨��ɾ��λ��x��ָ�Ľڵ㣨ȫ�־�̬ģ�庯����������AVL��Splay��RedBlack�ȸ���BST��
 * Ŀ��x�ڴ�ǰ�����Ҷ�λ����ȷ�Ϸ�NULL���ʱ�ɾ���ɹ�����searchIn��ͬ������֮ǰ���ؽ�hot�ÿ�
 * ����ֵָ��ʵ�ʱ�ɾ���ڵ�Ľ����ߣ�hotָ��ʵ�ʱ�ɾ���ڵ�ĸ��ס������߾��п�����NULL
 ******************************************************************************************/
template <typename T>
static BinNodePosi(T) removeAt ( BinNodePosi(T) & x, BinNodePosi(T) & hot ) {
   BinNodePosi(T) w = x; //ʵ�ʱ�ժ���Ľڵ㣬��ֵͬx
   BinNodePosi(T) succ = NULL; //ʵ�ʱ�ɾ���ڵ�Ľ�����
   if ( !HasLChild ( *x ) ) //��*x��������Ϊ�գ����
      succ = x = x->rc; //ֱ�ӽ�*x�滻Ϊ��������
   else if ( !HasRChild ( *x ) ) //��������Ϊ�գ����
      succ = x = x->lc; //�ԳƵش�����ע�⣺��ʱsucc != NULL
   else { //���������������ڣ���ѡ��x��ֱ�Ӻ����Ϊʵ�ʱ�ժ���ڵ㣬Ϊ����Ҫ
      w = w->succ(); //�����������У��ҵ�*x��ֱ�Ӻ��*w
      swap ( x->data, w->data ); //����*x��*w������Ԫ��
      BinNodePosi(T) u = w->parent;
      ( ( u == x ) ? u->rc : u->lc ) = succ = w->rc; //����ڵ�*w
   }
   hot = w->parent; //��¼ʵ�ʱ�ɾ���ڵ�ĸ���
   if ( succ ) succ->parent = hot; //������ɾ���ڵ�Ľ�������hot����
   release ( w->data ); release ( w ); return succ; //�ͷű�ժ���ڵ㣬���ؽ�����
}
