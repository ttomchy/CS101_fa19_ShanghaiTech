/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "Huffman_PQ.h"

// ���ݱ������Գ�Ϊn��Bitmap����Huffman����
void decode ( HuffTree* tree, Bitmap* code, int n ) {
   BinNodePosi ( HuffChar ) x = tree->root();
   for ( int i = 0; i < n; i++ ) {
      x = code->test ( i ) ? x->rc : x->lc;
      if ( IsLeaf ( *x ) ) {  printf ( "%c", x->data.ch ); x = tree->root();  }
   }
   /*DSA*/if ( x != tree->root() ) printf ( "..." ); printf ( "\n" );
} //��������룬�ڴ�ֱ�Ӵ�ӡ�����ʵ���пɸ�Ϊ������Ҫ�����ϲ������