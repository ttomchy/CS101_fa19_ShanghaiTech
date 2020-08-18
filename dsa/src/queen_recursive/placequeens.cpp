/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#include   "../queen_brute_force_1/queen.h"

/******************************************************************************************
 * n�ʺ��㷨���ݹ�棩
 * ��ʼ������placeQueens(nQueen, 0);
 ******************************************************************************************/
void placeQueens ( int nQueen, int k ) { //����n���ʺ��еĵ�k��������0��k-1���Ѿ�λ��
   static int solu[QUEEN_MAX]; //�ⷨ
   if ( nQueen <= k ) { //�����лʺ��Ѿ�λ����
      nSolu++; displaySolution ( solu, nQueen ); //������н�
   } else //����
      for ( int i = 0; i < nQueen; i++ ) { //����
         solu[k] = i; //���Ž���ǰ�ʺ���ڣ���ǰ�еģ�������
         if ( !collide ( solu, k ) ) //��û�г�ͻ����
            placeQueens ( nQueen, k + 1 ); //����������һ�ʺ�
      } //˼��������Ļ��ݣ�ͨ��ʲô����ʵ�֣�
}