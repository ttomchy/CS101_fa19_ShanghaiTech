/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "BTNode.h" //����B-���ڵ���

template <typename T> class BTree { //B-��ģ����
protected:
   int _size; //��ŵĹؼ�������
   int _order; //B-���Ľ״Σ�����Ϊ3��������ʱָ����һ�㲻���޸�
   BTNodePosi(T) _root; //���ڵ�
   BTNodePosi(T) _hot; //BTree::search()�����ʵķǿգ��������գ��Ľڵ�λ��
   void solveOverflow ( BTNodePosi(T) ); //����������֮��ķ��Ѵ���
   void solveUnderflow ( BTNodePosi(T) ); //��ɾ��������֮��ĺϲ�����
public:
   BTree ( int order = 3 ) : _order ( order ), _size ( 0 ) //���캯����Ĭ��Ϊ��͵�3��
   { _root = new BTNode<T>(); }
   ~BTree() { if ( _root ) release ( _root ); } //�����������ͷ����нڵ�
   int const order() { return _order; } //�״�
   int const size() { return _size; } //��ģ
   BTNodePosi(T) & root() { return _root; } //����
   bool empty() const { return !_root; } //�п�
   BTNodePosi(T) search ( const T& e ); //����
   bool insert ( const T& e ); //����
   bool remove ( const T& e ); //ɾ��
}; //BTree

#include "BTree_implementation.h"