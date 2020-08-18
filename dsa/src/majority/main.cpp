/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "../_share/util.h"
#include "../UniPrint/print.h"
#include "../vector/vector.h"
#include "majority.h"
#include "majorityCandidate.h"
#include "majorityCheck.h"

/******************************************************************************************
 * �����㷨����
 ******************************************************************************************/
int main ( int argc, char* argv[] ) {
   if ( 2 > argc ) { printf ( "Usage: %s <n>\a\a\n", argv[0] ); return 1; }
   int n = atoi ( argv[1] );
   if ( n < 1 ) { printf ( "Invalid arguments\a\a\n" ); return 1; }
   srand ( ( unsigned int ) time ( NULL ) );
// �����������
   Vector<int> A; //������Ϊ��
   int maj = rand() % n; printf ( "%d is highly possible to be a majority\n", maj ); //���ȷ��һ��majEle��ѡ
   while ( A.size() < n ) { //�������ϲ���n��ֱ������n��Ԫ��
      int ele = ( rand() % 100 < 50 ) ? maj : rand() % n; //49%�ĸ���ȷ����maj��51%�������ʵ�鲻ͬ���ʵ�Ч����
      A.insert ( A.size(), ele );
   }
   print ( A ); //�����������
// ��������
   majority ( A, maj ) ?
   printf ( "Majority element found as %d\n", maj ) :
   printf ( "Majority element NOT found\n" );
// ͨ�������һ����֤
   A.sort(); print ( A );
// ����
   return 0;
}