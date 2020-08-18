/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //��㹹���㷨��ͨ������Ԫ��λ�ù�������[lo, hi]����㣬����������
Rank Vector<T>::partition ( Rank lo, Rank hi ) { //�汾B�����Ż��������ؼ�����ͬ���˻����
   swap ( _elem[lo], _elem[lo + rand() % ( hi - lo + 1 ) ] ); //��ѡһ��Ԫ������Ԫ�ؽ���
   T pivot = _elem[lo]; //����Ԫ��Ϊ��ѡ��㡪�������Ͻ�������Ч�����ѡȡ
   while ( lo < hi ) { //�����������˽�������м�ɨ��
      while ( lo < hi )
         if ( pivot < _elem[hi] ) //�ڴ���pivot��ǰ����
            hi--; //������չ�Ҷ�������
         else //ֱ������������pivot��
            { _elem[lo++] = _elem[hi]; break; } //����������������
      while ( lo < hi )
         if ( _elem[lo] < pivot ) //��С��pivot��ǰ����
            lo++; //������չ���������
         else //ֱ��������С��pivot��
            { _elem[hi--] = _elem[lo]; break; } //��������Ҷ�������
   } //assert: lo == hi
   _elem[lo] = pivot; //�����ݵ�����¼����ǰ����������֮��
   return lo; //����������
}