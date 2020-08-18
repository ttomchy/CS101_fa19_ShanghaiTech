/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename Tv, typename Te> //�����������DFS�㷨��ȫͼ��
void Graph<Tv, Te>::dfs ( int s ) { //assert: 0 <= s < n
   reset(); int clock = 0; int v = s; //��ʼ��
   do //��һ������ж���
      if ( UNDISCOVERED == status ( v ) ) //һ��������δ���ֵĶ���
         DFS ( v, clock ); //���Ӹö����������һ��DFS
   while ( s != ( v = ( ++v % n ) ) ); //����ż�飬�ʲ�©����
}

template <typename Tv, typename Te> //�����������DFS�㷨��������ͨ��
void Graph<Tv, Te>::DFS ( int v, int& clock ) { //assert: 0 <= v < n
   dTime ( v ) = ++clock; status ( v ) = DISCOVERED; //���ֵ�ǰ����v
   for ( int u = firstNbr ( v ); -1 < u; u = nextNbr ( v, u ) ) //ö��v�������ھ�u
      switch ( status ( u ) ) { //������״̬�ֱ���
         case UNDISCOVERED: //u��δ���֣���ζ��֧�������ڴ���չ
            type ( v, u ) = TREE; parent ( u ) = v; DFS ( u, clock ); break;
         case DISCOVERED: //u�ѱ����ֵ���δ������ϣ�Ӧ�������ָ�������
            type ( v, u ) = BACKWARD; break;
         default: //u�ѷ�����ϣ�VISITED������ͼ�������ӳ�Ϯ��ϵ��Ϊǰ��߻���
            type ( v, u ) = ( dTime ( v ) < dTime ( u ) ) ? FORWARD : CROSS; break;
      }
   status ( v ) = VISITED; fTime ( v ) = ++clock; //���ˣ���ǰ����v����������
}