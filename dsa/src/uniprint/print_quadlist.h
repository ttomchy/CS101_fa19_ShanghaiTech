/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

/******************************************************************************************
 * Quadlist
 ******************************************************************************************/

template <typename T> //Ԫ������
void UniPrint::p ( Quadlist<T>& q ) { //����
   printf ( "%s[%d]*%03d: ", typeid ( q ).name(), &q, q.size() ); //������Ϣ
   if ( q.size() <= 0 ) {  printf ( "\n" ); return;  }
   QuadlistNode<T>* curr = q.first()->pred; //��ǰ��֮header
   QuadlistNode<T>* base = q.first(); //��ǰ�ڵ�����
   while ( base->below ) base = base->below; //����
   while ( base->pred ) base = base->pred; //�ײ�֮header
   for ( int i = 0; i < q.size(); i++ ) { //���ڵ�ǰ���ÿһ�ڵ�
      curr = curr->succ; //curr
      QuadlistNode<T>* proj = curr; //�ҵ���curr��Ӧ��
      while ( proj->below ) proj = proj->below; //���׽ڵ㣨ͶӰ��
      while ( ( base = base->succ ) != proj ) //�ƶ�baseֱ��proj���ڼ䲻��
         printf ( "------------" ); //�ӳ�ˮƽ������
      print ( curr->entry ); //��������ǰ��ĵ�ǰ����
   }
   printf ( "\n" );
}
