/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> int List<T>::deduplicate() { //�޳������б��е��ظ��ڵ�
   if ( _size < 2 ) return 0; //ƽ���б���Ȼ���ظ�
   int oldSize = _size; //��¼ԭ��ģ
   ListNodePosi(T) p = header; Rank r = 0; //p���׽ڵ㿪ʼ
   while ( trailer != ( p = p->succ ) ) { //����ֱ��ĩ�ڵ�
      ListNodePosi(T) q = find ( p->data, r, p ); //��p��r�����棩ǰ���в�����ͬ��
      q ? remove ( q ) : r++; //����ȷ���ڣ���ɾ��֮�������ȼ�һ
   } //assert: ѭ�������е�����ʱ�̣�p������ǰ��������ͬ
   return oldSize - _size; //�б��ģ�仯��������ɾ��Ԫ������
}