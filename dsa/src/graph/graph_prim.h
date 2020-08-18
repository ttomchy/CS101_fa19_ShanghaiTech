/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename Tv, typename Te> //Prim�㷨��������ͨͼ�����߱�ʾΪ�����桢Ȩ����ȵ�һ�Ա�
void Graph<Tv, Te>::prim ( int s ) { //assert: 0 <= s < n
   reset(); priority ( s ) = 0;
   for ( int i = 0; i < n; i++ ) { //��������n�������n-1����
      status ( s ) = VISITED;
      if ( -1 != parent ( s ) ) type ( parent ( s ), s ) = TREE; //���뵱ǰ��s
      for ( int j = firstNbr ( s ); -1 < j; j = nextNbr ( s, j ) ) //ö��s�������ھ�j
         if ( ( status ( j ) == UNDISCOVERED ) && ( priority ( j ) > weight ( s, j ) ) ) //���ڽӶ���j���ɳ�
            { priority ( j ) = weight ( s, j ); parent ( j ) = s; } //��Dijkstra�㷨Ψһ�Ĳ�֮ͬ��
      for ( int shortest = INT_MAX, j = 0; j < n; j++ ) //ѡ����һ���̿��
         if ( ( status ( j ) == UNDISCOVERED ) && ( shortest > priority ( j ) ) )
            { shortest = priority ( j ); s = j; }
   }
}