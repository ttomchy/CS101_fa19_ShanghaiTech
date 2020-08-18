/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> bool majEleCheck ( Vector<T> A, T maj ) { //��֤��ѡ���Ƿ�ȷΪ����
   int occurrence = 0; //maj��A[]�г��ֵĴ���
   for ( int i = 0; i < A.size(); i++ ) //��һ����A[]�ĸ���Ԫ��
      if ( A[i] == maj ) occurrence++; //ÿ����һ��maj�������¼�����
   /*DSA*/printf ( "%d found with %d/%d occurrence(s)\n", maj, occurrence, A.size() );
   return 2 * occurrence > A.size(); //�������յļ���ֵ�������ж��Ƿ��ȷ��ѡ
}