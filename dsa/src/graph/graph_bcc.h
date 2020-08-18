/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename Tv, typename Te> void Graph<Tv, Te>::bcc ( int s ) { //����DFS��BCC�ֽ��㷨
   reset(); int clock = 0; int v = s; Stack<int> S; //ջS���Լ�¼�ѷ��ʵĶ���
   do
      if ( UNDISCOVERED == status ( v ) ) { //һ������δ���ֵĶ��㣨����ͨ������
         BCC ( v, clock, S ); //���Ӹö����������һ��BCC
         S.pop(); //�������غ󣬵���ջ�����һ�����㡪����ǰ��ͨ������
      }
   while ( s != ( v = ( ++v % n ) ) );
}
#define hca(x) (fTime(x)) //���ô˴����õ�fTime[]�䵱hca[]
template <typename Tv, typename Te> //�������͡�������
void Graph<Tv, Te>::BCC ( int v, int& clock, Stack<int>& S ) { //assert: 0 <= v < n
   hca ( v ) = dTime ( v ) = ++clock; status ( v ) = DISCOVERED; S.push ( v ); //v�����ֲ���ջ
   for ( int u = firstNbr ( v ); -1 < u; u = nextNbr ( v, u ) ) //ö��v�������ھ�u
      switch ( status ( u ) ) { //����u��״̬�ֱ���
         case UNDISCOVERED:
            parent ( u ) = v; type ( v, u ) = TREE; BCC ( u, clock, S ); //�Ӷ���u������
            if ( hca ( u ) < dTime ( v ) ) //�������غ�������u��ͨ������ߣ���ָ��v��������
               hca ( v ) = min ( hca ( v ), hca ( u ) ); //��v������
            else { //������vΪ�ؽڵ㣨u���¼���һ��BCC�������ж����ʱ��������ջS�Ķ�����
               /*DSA*/printf ( "BCC rooted at %c:", vertex ( v ) );
               /*DSA*/Stack<int> temp; do { temp.push ( S.pop() ); print ( vertex ( temp.top() ) ); } while ( v != temp.top() ); while ( !temp.empty() ) S.push ( temp.pop() );
               while ( v != S.pop() ); //���ε�����ǰBCC�еĽڵ㣬��ɸ���ʵ������ת���������ṹ
               S.push ( v ); //���һ�����㣨�ؽڵ㣩������ջ������̯����һ��
               /*DSA*/printf ( "\n" );
            }
            break;
         case DISCOVERED:
            type ( v, u ) = BACKWARD; //���(v, u)�������ա�ԽСԽ�ߡ���׼��
            if ( u != parent ( v ) ) hca ( v ) = min ( hca ( v ), dTime ( u ) ); //����hca[v]
            break;
         default: //VISITED (digraphs only)
            type ( v, u ) = ( dTime ( v ) < dTime ( u ) ) ? FORWARD : CROSS;
            break;
      }
   status ( v ) = VISITED; //��v�ķ��ʽ���
}
#undef hca