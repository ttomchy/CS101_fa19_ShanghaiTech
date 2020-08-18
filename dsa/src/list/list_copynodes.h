/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //�б��ڲ������������б�����λ��p���n��
void List<T>::copyNodes ( ListNodePosi(T) p, int n ) { //p�Ϸ�����������n-1�����̽ڵ�
   init(); //����ͷ��β�ڱ��ڵ㲢����ʼ��
   while ( n-- ) { insertAsLast ( p->data ); p = p->succ; } //������p��n��������Ϊĩ�ڵ����
}