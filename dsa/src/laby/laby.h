/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

// �Թ�Ѱ���㷨���ڸ�Ԫs��t֮��滮һ��ͨ·�������ȷ���ڣ�
bool labyrinth ( Cell Laby[LABY_MAX][LABY_MAX], Cell* s, Cell* t ) {
   if ( ( AVAILABLE != s->status ) || ( AVAILABLE != t->status ) ) return false; //�˻����
   Stack<Cell*> path; //��ջ��¼ͨ·��Theseus��������
   s->incoming = UNKNOWN; s->status = ROUTE; path.push ( s ); //���
   do { //��������������̽�����ݣ�ֱ���ִ��յ㣬��������п���
      /*DSA*/displayLaby(); /*path.traverse(printLabyCell); printLabyCell(path.top());*/ getchar();
      Cell* c = path.top(); //��鵱ǰλ�ã�ջ����
      if ( c == t ) return true; //���ѵִ��յ㣬���ҵ���һ��ͨ·����������δ��̽�ķ��������̽
      while ( NO_WAY > ( c->outgoing = nextESWN ( c->outgoing ) ) ) //��һ������з���
         if ( AVAILABLE == neighbor ( c )->status ) break; //��ͼ�ҵ���δ��̽�ķ���
      if ( NO_WAY <= c->outgoing ) //�����з����ѳ��Թ�
         { c->status = BACKTRACKED; c = path.pop(); }//��������һ��
      else //������ǰ��̽һ��
         { path.push ( c = advance ( c ) ); c->outgoing = UNKNOWN; c->status = ROUTE; }
   } while ( !path.empty() );
   return false;
}