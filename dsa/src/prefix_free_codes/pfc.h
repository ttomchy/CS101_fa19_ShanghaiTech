/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

/*DSA*/#include "../_share/util.h"
/*DSA*/#include "../UniPrint/print.h"

/******************************************************************************************
 * PFC����ʹ�õ����ݽṹ
 ******************************************************************************************/
#include "../BinTree/BinTree.h" //��BinTreeʵ��PFC��
typedef BinTree<char> PFCTree; //PFC��

#include "../Vector/Vector.h" //��Vectorʵ��PFCɭ��
typedef Vector<PFCTree*> PFCForest; //PFCɭ��

#include "../Bitmap/Bitmap.h" //ʹ��λͼ�ṹʵ�ֶ����Ʊ��봮
#include "../Skiplist/Skiplist.h" //����Skiplistʽ�ʵ�ṹʵ��
typedef Skiplist<char, char*> PFCTable; //PFC�����������ʽΪ��(key = �ַ�, value = ���봮)

#define  N_CHAR  (0x80 - 0x20) //ֻ���ǿɴ�ӡ�ַ�
