/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "queen_stack.h"

void placeQueens ( int N ) { //N�ʺ��㷨�������棩��������̽/���ݵĲ��ԣ�����ջ��¼���ҵĽ��
   Stack<Queen> solu; //��ţ����֣����ջ
   Queen q ( 0, 0 ); //��ԭ��λ�ó���
   do { //������̽������
      if ( N <= solu.size() || N <= q.y ) { //���ѳ��磬��
         q = solu.pop(); q.y++; //����һ�У���������̽��һ��
      } else { //������̽��һ��
         while ( ( q.y < N ) && ( 0 <= solu.find ( q ) ) ) //ͨ�������лʺ�ıȶ�
            /*DSA*///while ((q.y < N) && (solu.find(q))) //��������Listʵ��Stack����find()����ֵ������������ͬ��
            { q.y++; nCheck++; } //�����ҵ��ɰڷ���һ�ʺ����
         if ( N > q.y ) { //�����ڿɰڷŵ��У���
            solu.push ( q ); //���ϵ�ǰ�ʺ󣬲�
            if ( N <= solu.size() ) nSolu++; //�����ֽ��ѳ�Ϊȫ�ֽ⣬��ͨ��ȫ�ֱ���nSolu����
            q.x++; q.y = 0; //ת����һ�У��ӵ�0�п�ʼ����̽��һ�ʺ�
         }
      }/*DSA*/if ( Step == runMode ) displayProgress ( solu, N );
   } while ( ( 0 < q.x ) || ( q.y < N ) ); //���з�֧���ѻ���ٻ��֦֮���㷨����
}