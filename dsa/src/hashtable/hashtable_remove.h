/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename K, typename V> bool Hashtable<K, V>::remove ( K k ) { //ɢ�б����ɾ���㷨
   int r = probe4Hit ( k ); if ( !ht[r] ) return false; //��Ӧ����������ʱ���޷�ɾ��
   release ( ht[r] ); ht[r] = NULL; markAsRemoved ( r ); N--; return true;
   //�����ͷ�Ͱ�д�������������ɾ����ǣ������´�������
}