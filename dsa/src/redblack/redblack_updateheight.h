/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> int RedBlack<T>::updateHeight ( BinNodePosi(T) x ) { //���½ڵ�߶�
   x->height = max ( stature ( x->lc ), stature ( x->rc ) ); //����һ��ڸ߶���ȣ����ǳ���˫��
   /*DSA*/// ������и��ڵ����Һ��ӵĺڸ߶�ͨ�����
   /*DSA*/// ����֮����ȡ����ֵ���Ǳ�����ɾ���ڵ���ƽ����������У���ȷ���±�ɾ���ڵ㸸�׵ĺڸ߶�
   /*DSA*/// ����rotateAt()����ݱ�ɾ���ڵ������ߣ��߶�Сһ�����ø��ڵ�ĺڸ߶�
   return IsBlack ( x ) ? x->height++ : x->height; //����ǰ�ڵ�Ϊ�ڣ����������
} //��ͳһ����stature(NULL) = -1����height�Ⱥڸ߶���һ�����ڲ���Ӱ�쵽�����㷨�еıȽ��ж�
