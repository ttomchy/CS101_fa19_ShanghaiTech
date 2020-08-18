/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename K, typename V> Hashtable<K, V>::~Hashtable() { //����ǰ�ͷ�Ͱ���鼰�ǿմ���
   for ( int i = 0; i < M; i++ ) //��һ����Ͱ
      if ( ht[i] ) release ( ht[i] ); //�ͷŷǿյ�Ͱ
   release ( ht ); //�ͷ�Ͱ����
   release ( lazyRemoval ); //�ͷ�����ɾ�����
}