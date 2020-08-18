/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename K, typename V> bool Hashtable<K, V>::put ( K k, V v ) { //ɢ�б��������
   if ( ht[probe4Hit ( k ) ] ) return false; //��ͬԪ�ز����ظ�����
   int r = probe4Free ( k ); //Ϊ�´����Ҹ���Ͱ��ֻҪװ�����ӿ��Ƶõ�����Ȼ�ɹ���
   ht[r] = new Entry<K, V> ( k, v ); ++N; //���루ע�⣺����ɾ��������踴λ��
   if ( N * 2 > M ) rehash(); //װ�����Ӹ���50%����ɢ��
   return true;
}