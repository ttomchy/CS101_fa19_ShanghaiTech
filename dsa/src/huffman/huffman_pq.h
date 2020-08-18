/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/******************************************************************************************
 * ֧��Huffman��������ݽṹ
 ******************************************************************************************
 * ����ͳһ�Ľӿڣ�ΪHuffman_PQ_ComplHeap��Huffman_PQ_LeftHeap����
 * ����֮ǰ����ͨ���ڶ�Ӧ�Ĺ���������DSA_PQ_ComplHeap��DSA_PQ_LeftHeapѡ��
 ******************************************************************************************/
#pragma once

#include <iostream>
using namespace std;

/*DSA*/#include "../UniPrint/print.h"

//Huffman��
#include "../Huffman/HuffChar.h" //����Huffman�������ַ�
#include "../Huffman/HuffTree.h" //����Huffman��
#include "../Huffman/HuffTable.h" //����Huffman�����
#include "../Huffman/HuffCode.h" //����HuffCode�����Ʊ���

// Huffmanɭ��
#if defined(DSA_PQ_LIST)
#include "../Huffman/Huffman_Forest_PQ_List.h"
#elif defined(DSA_PQ_COMPLHEAP)
#include "../Huffman/Huffman_Forest_PQ_ComplHeap.h"
#elif defined(DSA_PQ_LEFTHEAP)
#include "../Huffman/Huffman_Forest_PQ_LeftHeap.h"
#else //���ط�����ֱ����Listʵ�ֵ�Huffmanɭ��
#include "../Huffman/Huffman_Forest_List.h"
#endif