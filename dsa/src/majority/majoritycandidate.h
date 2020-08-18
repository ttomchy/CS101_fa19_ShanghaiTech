/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> T majEleCandidate ( Vector<T> A ) { //ѡ���߱���Ҫ������������ѡ��
   T maj; //������ѡ��
// ����ɨ�裺����������c����¼maj������Ԫ�ص��������
   for ( int c = 0, i = 0; i < A.size(); i++ )
      if ( 0 == c ) { //ÿ��c���㣬����ζ�Ŵ�ʱ��ǰ׺P���Լ���
         maj = A[i]; c = 1; //������ѡ�߸�Ϊ�µĵ�ǰԪ��
      } else //����
         maj == A[i] ? c++ : c--; //��Ӧ�ظ��²�������
   return maj; //���ˣ�ԭ���������������ڣ���ֻ����maj ���� ���ܷ�֮��Ȼ
}