/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

struct Queen { //�ʺ���
   int x, y; //�ʺ��������ϵ�λ������
   Queen ( int xx = 0, int yy = 0 ) : x ( xx ), y ( yy ) {};
   bool operator== ( Queen const& q ) const { //�����еȲ��������Լ�ⲻͬ�ʺ�֮����ܵĳ�ͻ
      return    ( x == q.x ) //�г�ͻ����һ�����ʵ�����ᷢ������ʡ�ԣ�
                || ( y == q.y ) //�г�ͻ
                || ( x + y == q.x + q.y ) //�����Խ��߳�ͻ
                || ( x - y == q.x - q.y ); //�ط��Խ��߳�ͻ
   }
   bool operator!= ( Queen const& q ) const { return ! ( *this == q ); } //���ز��Ȳ����� /*DSA*/�ɷ�д�ɣ�return *this != q��
};