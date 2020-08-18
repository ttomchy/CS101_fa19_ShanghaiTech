/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

/******************************************************************************************
 * ��ɢ���㷨��װ�����ӹ���ʱ����ȡ����һȡ���ٲ��롱�����ز��ԣ���Ͱ��������
 * ���ɼ򵥵أ�ͨ��memcpy()����ԭͰ���鸴�Ƶ���Ͱ���飨����ǰ�ˣ�����������������⣺
 * 1����̳�ԭ�г�ͻ��2�����ܵ��²������ں�˶��ѡ�������Ϊ��������Ͱ��������ɾ����־Ҳ�޼�����
 ******************************************************************************************/
template <typename K, typename V> void Hashtable<K, V>::rehash() {
   int old_capacity = M; Entry<K, V>** old_ht = ht;
   M = primeNLT ( 2 * M, 1048576, "../../_input/prime-1048576-bitmap.txt" ); //�������ټӱ�
   N = 0; ht = new Entry<K, V>*[M]; memset ( ht, 0, sizeof ( Entry<K, V>* ) * M ); //��Ͱ����
   release ( lazyRemoval ); lazyRemoval = new Bitmap ( M ); //�¿�����ɾ����Ǳ���ͼ
   //*DSA*/printf("A bucket array has been created with capacity = %d\n\n", M);
   for ( int i = 0; i < old_capacity; i++ ) //ɨ��ԭͰ����
      if ( old_ht[i] ) //���ǿ�Ͱ�еĴ�����һ
         put ( old_ht[i]->key, old_ht[i]->value ); //�������µ�Ͱ����
   release ( old_ht ); //�ͷ�ԭͰ���顪����������ԭ�ȴ�ŵĴ�������ת�ƣ���ֻ���ͷ�Ͱ���鱾��
}
