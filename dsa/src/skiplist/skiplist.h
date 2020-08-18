/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "../List/List.h" //�����б�
#include "../Entry/Entry.h" //�������
#include "Quadlist.h" //����Quadlist
#include "../Dictionary/Dictionary.h" //����ʵ�

template <typename K, typename V> //key��value
//����Dictionary�ӿڵ�Skiplistģ���ࣨ����������Ԫ��֮��ɱȽϴ�С��
class Skiplist : public Dictionary<K, V>, public List<Quadlist<Entry<K, V>>*> {
protected:
   bool skipSearch (
      ListNode<Quadlist<Entry<K, V>>*>* &qlist,
      QuadlistNode<Entry<K, V>>* &p,
      K& k );
public:
   int size() const { return empty() ? 0 : last()->data->size(); } //�ײ�Quadlist�Ĺ�ģ
   int level() { return List::size(); } //��� == #Quadlist����һ��Ҫ����
   bool put ( K, V ); //���루ע����Map�б𡪡�Skiplist��������ظ����ʱ�Ȼ�ɹ���
   V* get ( K k ); //��ȡ
   bool remove ( K k ); //ɾ��
};

#include "Skiplist_implementation.h"