/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename Tv, typename Te> //�����������BFS�㷨��ȫͼ��
void Graph<Tv, Te>::bfs ( int s ) { //assert: 0 <= s < n
   reset(); int clock = 0; int v = s; //��ʼ��
   do //��һ������ж���
      if ( UNDISCOVERED == status ( v ) ) //һ��������δ���ֵĶ���
         BFS ( v, clock ); //���Ӹö����������һ��BFS
   while ( s != ( v = ( ++v % n ) ) ); //����ż�飬�ʲ�©����
}

template <typename Tv, typename Te> //�����������BFS�㷨��������ͨ��
void Graph<Tv, Te>::BFS ( int v, int& clock ) { //assert: 0 <= v < n
   Queue<int> Q; //���븨������
   status ( v ) = DISCOVERED; Q.enqueue ( v ); //��ʼ�����
   while ( !Q.empty() ) { //��Q���֮ǰ������
      int v = Q.dequeue(); dTime ( v ) = ++clock; //ȡ�����׶���v
      for ( int u = firstNbr ( v ); -1 < u; u = nextNbr ( v, u ) ) //ö��v�������ھ�u
         if ( UNDISCOVERED == status ( u ) ) { //��u��δ�����֣���
            status ( u ) = DISCOVERED; Q.enqueue ( u ); //���ָö���
            type ( v, u ) = TREE; parent ( u ) = v; //����������չ֧����
         } else { //��u�ѱ����֣����������ѷ�����ϣ���
            type ( v, u ) = CROSS; //��(v, u)�����ڿ��
         }
      status ( v ) = VISITED; //���ˣ���ǰ����������
   }
}