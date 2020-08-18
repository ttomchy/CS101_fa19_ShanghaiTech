/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "simu.h"

void simulate ( int nWin, int servTime ) { //��ָ����������������ʱ��ģ������ҵ��
   Queue<Customer>* windows = new Queue<Customer>[nWin]; //Ϊÿһ���ڴ���һ������
   for ( int now = 0; now < servTime; now++ ) { //���°�֮ǰ��ÿ��һ����λʱ��
      if ( rand() % ( 1 + nWin ) ) { //�¹˿���nWin/(nWin + 1)�ĸ��ʵ���
         Customer c ; c.time = 1 + rand() % 98; //�¹˿͵������ʱ�����ȷ��
         c.window = bestWindow ( windows, nWin ); //�ҳ���ѣ���̣��ķ��񴰿�/*DSA*/ToDo: ����ϸ�Ĳ���
         windows[c.window].enqueue ( c ); //�¹˿ͼ����Ӧ�Ķ���
      }
      for ( int i = 0; i < nWin; i++ ) //�ֱ���
         if ( !windows[i].empty() ) //���ǿն���
            if ( -- windows[i].front().time <= 0 ) //���׹˿͵ķ���ʱ������һ����λ
               windows[i].dequeue(); //������ϵĹ˿ͳ��У��ɺ�̹˿ͽ���
      /*DSA*/displayProgress ( windows, nWin, now ); //��ʾ��ǰ�������ڣ��������
      /*DSA*/delay > 0 ? //��������ָ����ʱ����Ϊ����
      /*DSA*/  _sleep ( delay ) : //������Ӧ���ӳ�
      /*DSA*/  getchar(); //�������ֶ���ʽ������ʾ
   } //for
   delete [] windows; //�ͷ����ж��У���ǰ��~List()���Զ���ն��У�
}