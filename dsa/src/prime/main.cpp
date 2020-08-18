/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#include <stdio.h>
#include "../_share/rand.h"
#include "../Bitmap/Bitmap.h"
#include "Eratosthenes.h"
#include "primeNLT.h"

/******************************************************************************************
 * ������
 ******************************************************************************************/
#define PRIMEFILE "prime-bitmap.txt" //���ڼ�¼ָ�������������ֲ��ı���ͼ�ļ�
int main ( int argc, char* argv[] ) {
   srand ( ( unsigned int ) time ( NULL ) ); //�����������
   if ( 2 > argc ) { printf ( "Usage: %s <maxInt>\n", argv[0] ); return -1; }
   int n = atoi ( argv[1] ); //������������Ƿ��������
   Eratosthenes ( n, PRIMEFILE );
   for ( int i = 0; i < 13; i++ ) { //��13��������ԣ�����MAX_RAND�����Ƿ�Χ������0x7FFF��
      int low = dice ( n );
      printf ( "The smallest prime number no less than %8d (%05X) is %8d\n", low, low, primeNLT ( low, n, PRIMEFILE ) );
   }
   for ( int i = 0; i < 13; i++ ) { //��13�εȼ�����
      printf ( "The smallest prime number no less than %8d (%05X) is %8d\n", n * i / 13, n * i / 13, primeNLT ( n * i / 13, n, PRIMEFILE ) );
   }
   return 0;
}