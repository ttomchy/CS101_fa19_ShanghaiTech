/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#include "queen_stack.h"

#define QUEEN_MAX 20 //�ʺ��������

/******************************************************************************************
 * ȫ�ֱ���
 ******************************************************************************************/
RunMode runMode; //��ʾģʽ
int nSolu = 0; //�������
int nCheck = 0; //���Ե��ܴ���

/******************************************************************************************
 * n�ʺ󣨵����棩
 ******************************************************************************************/
int main ( int argc, char* argv[] ) {
   for ( int i = 1; i < argc - 1; i++ ) //������
      if ( !strcmp ( "-step", argv[i] ) ) runMode = Step; //�趨Ϊ������ʾģʽ
   int nQueen = atoi ( argv[argc-1] ); //���̴�С = �ʺ�����
   if ( QUEEN_MAX < nQueen || 1 > nQueen ) { //������
      fprintf ( stderr, "\nUsage: %s [-step] <nQueen(%d)>\n", argv[0], QUEEN_MAX );
      return -1;
   }
   placeQueens ( nQueen ); //��������
   cout  << nSolu << " solution(s) found after "
         << nCheck << " check(s) for "
         << nQueen << " queen(s)\n"; //����������
   return 0;
}