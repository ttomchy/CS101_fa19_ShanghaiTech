/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "huffman_PQ.h"

HuffTree* minHChar ( HuffForest* forest ) { //��Huffmanɭ�����ҳ�Ȩ����С�ģ������ַ�
   ListNodePosi ( HuffTree* ) p = forest->first(); //���׽ڵ��������
   ListNodePosi ( HuffTree* ) minChar = p; //��СHuffman�����ڵĽڵ�λ��
   int minWeight = p->data->root()->data.weight; //Ŀǰ����СȨ��
   while ( forest->valid ( p = p->succ ) ) //�������нڵ�
      if ( minWeight > p->data->root()->data.weight ) //����ǰ�ڵ���������С����
         {  minWeight = p->data->root()->data.weight; minChar = p;  } //���¼�¼
   return forest->remove ( minChar ); //����ѡ����Huffman����ɭ����ժ����������
}

HuffTree* generateTree ( HuffForest* forest ) { //Huffman�����㷨
   while ( 1 < forest->size() ) {
      HuffTree* T1 = minHChar ( forest ); HuffTree* T2 = minHChar ( forest );
      HuffTree* S = new HuffTree(); /*DSA*/printf ( "\n################\nMerging " ); print ( T1->root()->data ); printf ( " with " ); print ( T2->root()->data ); printf ( " ...\n" );
      S->insertAsRoot ( HuffChar ( '^', T1->root()->data.weight + T2->root()->data.weight ) );
      S->attachAsLC ( S->root(), T1 ); S->attachAsRC ( S->root(), T2 );
      forest->insertAsLast ( S ); /*DSA*/ //print(forest);
   } //assert: ѭ������ʱ��ɭ����Ψһ���б��׽ڵ��У����ǿ�����Huffman������
   return forest->first()->data;
}