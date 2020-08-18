/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "Huffman_PQ.h"

HuffForest* initForest ( int* freq ) { //����Ƶ��ͳ�Ʊ�Ϊÿ���ַ�����һ����
   HuffForest* forest = new HuffForest; //��Listʵ�ֵ�Huffmanɭ��
   for ( int i = 0; i < N_CHAR; i++ ) { //Ϊÿ���ַ�
      forest->insertAsLast ( new HuffTree ); //����һ�����������ַ�����Ƶ��
      forest->last()->data->insertAsRoot ( HuffChar ( 0x20 + i, freq[i] ) ); //��������
   }
   return forest;
}