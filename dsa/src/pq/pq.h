/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> struct PQ { //���ȼ�����PQģ����
   virtual void insert ( T ) = 0; //���ձȽ���ȷ�������ȼ�����������
   virtual T getMax() = 0; //ȡ�����ȼ���ߵĴ���
   virtual T delMax() = 0; //ɾ�����ȼ���ߵĴ���
};
