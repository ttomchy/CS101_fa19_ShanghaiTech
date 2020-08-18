/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "Huffman_PQ.h"

/******************************************************************************************
 * Huffman�������㷨���Դ����Huffmanɭ��forest�𲽺ϲ���ֱ����Ϊһ����
 ******************************************************************************************
 * forest�������ȼ�����ʵ�֣����㷨�����ڷ���PQ�ӿڵ��κ�ʵ�ַ�ʽ
 * ΪHuffman_PQ_List��Huffman_PQ_ComplHeap��Huffman_PQ_LeftHeap����
 * ����ǰ��Ӧ����ֻ��������Ӧ��־��DSA_PQ_List��DSA_PQ_ComplHeap��DSA_PQ_LeftHeap
 ******************************************************************************************/
HuffTree* generateTree ( HuffForest* forest ) {
   while ( 1 < forest->size() ) {
      HuffTree* s1 = forest->delMax(); HuffTree* s2 = forest->delMax();
      HuffTree* s = new HuffTree();
      /*DSA*/printf ( "Merging " ); print ( s1->root()->data ); printf ( " with " ); print ( s2->root()->data ); printf ( " ...\n" );
      s->insertAsRoot ( HuffChar ( '^', s1->root()->data.weight + s2->root()->data.weight ) );
      s->attachAsLC ( s->root(), s1 ); s->attachAsRC ( s->root(), s2 );
      forest->insert ( s ); //���ϲ����Huffman�����Huffmanɭ��
   }
   HuffTree* tree = forest->delMax(); //���ˣ�ɭ���е����һ����
   return tree; //��ȫ��Huffman������
}