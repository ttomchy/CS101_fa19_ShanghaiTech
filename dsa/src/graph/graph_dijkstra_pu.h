/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename Tv, typename Te> struct DijkstraPU { //���Dijkstra�㷨�Ķ������ȼ�������
   virtual void operator() ( Graph<Tv, Te>* g, int uk, int v ) {
      if ( UNDISCOVERED == g->status ( v ) ) //����ukÿһ��δ�����ֵ��ڽӶ���v����Dijkstra����
         if ( g->priority ( v ) > g->priority ( uk ) + g->weight ( uk, v ) ) { //���ɳ�
            g->priority ( v ) = g->priority ( uk ) + g->weight ( uk, v ); //�������ȼ�������
            g->parent ( v ) = uk; //��ͬʱ���¸��ڵ�
         }
   }
};