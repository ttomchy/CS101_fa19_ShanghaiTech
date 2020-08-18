/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/


#include "hanoi.h"

int nDisk; //��������
Stack<int> Sx, Sy, Sz; //������ջģ���������ӣ�ÿ�����ӵİ뾶��������ʾ

/******************************************************************************************
 * �������
 ******************************************************************************************/
int main ( int argc, char* argv[] ) {
// ������
   if ( 2 > argc ) { fprintf ( stderr, "\a\a\nUsage: %s <number>\n\nFor example %s 6\n\n", argv[0], argv[0] ); return -1; }
   nDisk = atoi ( argv[1] ); //��������
   if ( nDisk < 0 ) { fprintf ( stderr, "\a\a\nMake sure the number of disks (%d?) is input correctly\n", nDisk ); return -2; }
   for ( Disk d = nDisk; d >= 1; d-- ) Sx.push ( d ); //�����������ηŵ�X��
   displayHanoi();
// ������Ϸ
   hanoi ( nDisk, Sx, Sy, Sz );
   return 0;
}