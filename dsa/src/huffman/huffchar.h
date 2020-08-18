/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

#define  N_CHAR  (0x80 - 0x20) //���Կɴ�ӡ�ַ�Ϊ��
struct HuffChar { //Huffman�������ַ�
   char ch; int weight; //�ַ���Ƶ��
   HuffChar ( char c = '^', int w = 0 ) : ch ( c ), weight ( w ) {};
// �Ƚ������е�����������һ���������в��䣩
   bool operator< ( HuffChar const& hc ) { return weight > hc.weight; } //�˴������С�ߵ�
   bool operator== ( HuffChar const& hc ) { return weight == hc.weight; }
};