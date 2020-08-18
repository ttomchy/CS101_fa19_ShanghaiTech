/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "../Entry/Entry.h"
#define QlistNodePosi(T)  QuadlistNode<T>* //��ת��ڵ�λ��

template <typename T> struct QuadlistNode { //QuadlistNodeģ����
   T entry; //�������
   QlistNodePosi(T) pred;  QlistNodePosi(T) succ; //ǰ�������
   QlistNodePosi(T) above; QlistNodePosi(T) below; //���ڡ�����
   QuadlistNode //������
   ( T e = T(), QlistNodePosi(T) p = NULL, QlistNodePosi(T) s = NULL,
     QlistNodePosi(T) a = NULL, QlistNodePosi(T) b = NULL )
      : entry ( e ), pred ( p ), succ ( s ), above ( a ), below ( b ) {}
   QlistNodePosi(T) insertAsSuccAbove //�����½ڵ㣬�Ե�ǰ�ڵ�Ϊǰ�����Խڵ�bΪ����
   ( T const& e, QlistNodePosi(T) b = NULL );
};

#include "QuadlistNode_implementation.h"