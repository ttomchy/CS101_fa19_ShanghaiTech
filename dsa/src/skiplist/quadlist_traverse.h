/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //����Quadlist���Ը��ڵ�����ʵʩvisit����
void Quadlist<T>::traverse ( void ( *visit ) ( T& ) ) { //���ú���ָ����ƣ�ֻ����ֲ����޸�
   QlistNodePosi(T) p = header;
   while ( ( p = p->succ ) != trailer ) visit ( p->data );
}

template <typename T> template <typename VST> //����Quadlist���Ը��ڵ�����ʵʩvisit����
void Quadlist<T>::traverse ( VST& visit ) { //���ú���������ƣ���ȫ�����޸�
   QlistNodePosi(T) p = header;
   while ( ( p = p->succ ) != trailer ) visit ( p->data );
}