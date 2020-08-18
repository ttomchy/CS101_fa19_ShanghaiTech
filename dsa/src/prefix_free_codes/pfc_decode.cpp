/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "PFC.h"

void decode ( PFCTree* tree, Bitmap& code, int n ) { //PFC�����㷨
   BinNodePosi ( char ) x = tree->root(); //����PFC������
   for ( int i = 0; i < n; i++ ) { //�����루������λͼ��
      x = code.test ( i ) ? x->rc : x->lc; //ת��Ϊ���벢
      if ( IsLeaf ( *x ) ) { printf ( "%c", x->data ); x = tree->root(); } //��ӡ���
   }
   /*DSA*/if ( x != tree->root() ) printf ( " code seems to be incomplete ..." ); printf ( "\n" );
}