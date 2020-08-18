/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "../BST/BST.h" //����BSTʵ��AVL��
template <typename T> class AVL : public BST<T> { //��BST����AVL��ģ����
public:
   BinNodePosi(T) insert ( const T& e ); //���루��д��
   bool remove ( const T& e ); //ɾ������д��
// BST::search()������ӿڿ�ֱ������
};

#include "AVL_implementation.h"