/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

#define EQUAL(e, v)  (!(v) || (e) == (v)->data) //�ڵ�v��������ͨ���ڱ����Ĺؼ������e
template <typename T> //����vΪ���ģ�AVL��SPLAY��rbTree�ȣ�BST�����в��ҹؼ���e
static BinNodePosi(T) & searchIn ( BinNodePosi(T) & v, const T& e, BinNodePosi(T) & hot ) {
   if ( EQUAL ( e, v ) ) return v; hot = v; //�˻���������������ڵ�v������
   while ( 1 ) { //һ��أ��������ϵ�
      BinNodePosi(T) & c = ( e < hot->data ) ? hot->lc : hot->rc; //ȷ�����뷽��
      if ( EQUAL ( e, c ) ) return c; hot = c; //���з��أ���������һ��
   } //hotʼ��ָ�����һ��ʧ�ܽڵ�
} //����ʱ������ֵָ�����нڵ㣨������ͨ���ڱ�����hotָ���丸�ף��˻�ʱΪ��ʼֵNULL��