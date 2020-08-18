/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename Tv, typename Te> struct BfsPU { //���BFS�㷨�Ķ������ȼ�������
   virtual void operator() ( Graph<Tv, Te>* g, int uk, int v ) {
      if ( g->status ( v ) == UNDISCOVERED ) //����ukÿһ��δ�����ֵ��ڽӶ���v
         if ( g->priority ( v ) > g->priority ( uk ) + 1 ) { //���䵽���ľ�����Ϊ���ȼ���
            g->priority ( v ) = g->priority ( uk ) + 1; //�������ȼ�������
            g->parent ( v ) = uk; //���¸��ڵ�
         } //���Ч����ͬ�ڣ��ȱ�����������
   }
};