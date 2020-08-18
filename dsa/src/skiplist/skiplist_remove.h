/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename K, typename V> bool Skiplist<K, V>::remove ( K k ) { //��ת�����ɾ���㷨
   if ( empty() ) return false; //�ձ����
   ListNode<Quadlist<Entry<K, V>>*>* qlist = first(); //�Ӷ���Quadlist��
   QuadlistNode<Entry<K, V>>* p = qlist->data->first(); //�׽ڵ㿪ʼ
   if ( !skipSearch ( qlist, p, k ) ) return false; //Ŀ����������ڣ�ֱ�ӷ���
   do { //��Ŀ��������ڣ����������֮��Ӧ����
      QuadlistNode<Entry<K, V>>* lower = p->below; //��ס��һ��ڵ㣬��
      qlist->data->remove ( p ); //ɾ����ǰ��ڵ㣬��
      p = lower; qlist = qlist->succ; //ת����һ��
   } while ( qlist->succ ); //���ϲ����ظ���ֱ������
   while ( !empty() && first()->data->empty() ) //��һ��
      List::remove ( first() ); //����ѿ��ܲ��������Ķ���Quadlist
   return true; //ɾ�������ɹ����
}