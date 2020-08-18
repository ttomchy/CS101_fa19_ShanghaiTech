/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename K, typename V> struct Entry { //����ģ����
   K key; V value; //�ؼ��롢��ֵ
   Entry ( K k = K(), V v = V() ) : key ( k ), value ( v ) {}; //Ĭ�Ϲ��캯��
   Entry ( Entry<K, V> const& e ) : key ( e.key ), value ( e.value ) {}; //���ڿ�¡�Ĺ��캯��
   bool operator< ( Entry<K, V> const& e ) { return key <  e.key; }  //�Ƚ�����С��
   bool operator> ( Entry<K, V> const& e ) { return key >  e.key; }  //�Ƚ���������
   bool operator== ( Entry<K, V> const& e ) { return key == e.key; } //�е���������
   bool operator!= ( Entry<K, V> const& e ) { return key != e.key; } //�е�����������
}; //�����ڱȽ������е������Ӵ����󣬲����ϸ����ִ��������Ӧ�Ĺؼ���