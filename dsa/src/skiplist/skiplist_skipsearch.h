/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

/******************************************************************************************
 * Skiplist���������㷨�����ڲ����ã�
 * ��ڣ�qlistΪ�����б�pΪqlist���׽ڵ�
 * ���ڣ����ɹ���pΪ���йؼ����������Ķ����ڵ㣬qlistΪp�����б�
 *       ����pΪ�������Ļ�����������Ӧ�ڲ�����k���������ҹؼ��룬qlistΪ��
 * Լ���������������ʱ����������ȡ�����
 ******************************************************************************************/
template <typename K, typename V> bool Skiplist<K, V>::skipSearch (
   ListNode<Quadlist<Entry<K, V>>*>* &qlist, //��ָ����qlist��
   QuadlistNode<Entry<K, V>>* &p, //�׽ڵ�p����
   K& k ) { //���ҡ����²���Ŀ��ؼ���k
   while ( true ) { //��ÿһ��
      while ( p->succ && ( p->entry.key <= k ) ) //��ǰ������
         p = p->succ; //ֱ�����ָ����key�������trailer
      p = p->pred; //��ʱ����һ���������ж��Ƿ�
      if ( p->pred && ( k == p->entry.key ) ) return true; //����
      qlist = qlist->succ; //����ת����һ��
      if ( !qlist->succ ) return false; //���ѵ���͸�ײ㣬����ζ��ʧ��
      p = ( p->pred ) ? p->below : qlist->data->first(); //����ת����ǰ������һ�ڵ�
   }  //�κ�ͨ��ʵ��ͳ�ƣ���֤����ƽ�����ҳ��ȵĽ���
}
