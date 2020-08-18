/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "PFC.h"

void generateCT //ͨ��������ȡ���ַ��ı���
( Bitmap* code, int length, PFCTable* table, BinNodePosi ( char ) v ) {
   if ( IsLeaf ( *v ) ) //����Ҷ�ڵ�
      { table->put ( v->data, code->bits2string ( length ) ); return; }
   if ( HasLChild ( *v ) ) //Left = 0
      { code->clear ( length ); generateCT ( code, length + 1, table, v->lc ); }
   if ( HasRChild ( *v ) ) //right = 1
      { code->set ( length ); generateCT ( code, length + 1, table, v->rc ); }
}

PFCTable* generateTable ( PFCTree* tree ) { //����PFC�����
   PFCTable* table = new PFCTable; //������Skiplistʵ�ֵı����
   Bitmap* code = new Bitmap; //���ڼ�¼RPS��λͼ
   generateCT ( code, 0, table, tree->root() ); //�����Ի�ȡ���ַ���Ҷ�ڵ㣩��RPS
   release ( code ); return table; //�ͷű���λͼ�����ر����
}