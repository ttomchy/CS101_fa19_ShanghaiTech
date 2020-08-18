/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "../BinTree/BinTree.h" //����BinTree

template <typename T> class BST : public BinTree<T> { //��BinTree����BSTģ����
protected:
   BinNodePosi(T) _hot; //�����С��ڵ�ĸ���
   BinNodePosi(T) connect34 ( //���ա�3 + 4���ṹ������3���ڵ㼰�Ŀ�����
      BinNodePosi(T), BinNodePosi(T), BinNodePosi(T),
      BinNodePosi(T), BinNodePosi(T), BinNodePosi(T), BinNodePosi(T) );
   BinNodePosi(T) rotateAt ( BinNodePosi(T) x ); //��x���丸�ס��游��ͳһ��ת����
public: //�����ӿڣ���virtual���Σ�ǿ��Ҫ�����������ࣨBST���֣����ݸ��ԵĹ��������д
   virtual BinNodePosi(T) & search ( const T& e ); //����
   virtual BinNodePosi(T) insert ( const T& e ); //����
   virtual bool remove ( const T& e ); //ɾ��
};

#include "BST_implementation.h"