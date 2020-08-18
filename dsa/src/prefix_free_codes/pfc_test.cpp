/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "PFC_test.h"
int main ( int argc, char* argv[] ) { //PFC���롢�����㷨ͳһ�������
   /*DSA*/if ( 2 > argc ) { printf ( "Usage: %s <message#1> [message#2] ...\a\n", argv[0] ); return -1; }
   PFCForest* forest = initForest(); //��ʼ��PFCɭ��
   PFCTree* tree = generateTree ( forest ); release ( forest ); //����PFC������
   /*DSA*/print ( tree );
   PFCTable* table = generateTable ( tree ); //��PFC������ת��Ϊ�����
   /*DSA*/for ( int i = 0; i < N_CHAR; i++ ) printf ( " %c: %s\n", i + 0x20, * ( table->get ( i + 0x20 ) ) ); //��������
   for ( int i = 1; i < argc; i++ ) { //���������д����ÿһ���Ĵ�
      /*DSA*/printf ( "\nEncoding: %s\n", argv[i] ); //��ʼ����
      Bitmap codeString; //�����Ʊ��봮
      int n = encode ( table, codeString, argv[i] ); //�����ݱ�������ɣ�����Ϊn��
      /*DSA*/printf ( "%s\n", codeString.bits2string ( n ) ); //�����ǰ�ı��ı��봮
      /*DSA*/printf ( "Decoding: " ); //��ʼ����
      decode ( tree, codeString, n ); //���ñ��������Գ���Ϊn�Ķ����Ʊ��봮���루ֱ�������
   }
   release ( table ); release ( tree ); return 0; //�ͷű����������
}