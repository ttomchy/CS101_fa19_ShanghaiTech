/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> void Quadlist<T>::init() { //Quadlist��ʼ��������Quadlist����ʱͳһ����
   header = new QuadlistNode<T>; //����ͷ�ڱ��ڵ�
   trailer = new QuadlistNode<T>; //����β�ڱ��ڵ�
   header->succ = trailer; header->pred = NULL; //�غ��������ڱ�
   trailer->pred = header; trailer->succ = NULL; //�غ��������ڱ�
   header->above = trailer->above = NULL; //����ĺ���ÿ�
   header->below = trailer->below = NULL; //�����ǰ���ÿ�
   _size = 0; //��¼��ģ
} //��˹���������������κ�ʵ�ʵĽڵ㣬����ʱ�������������໥����