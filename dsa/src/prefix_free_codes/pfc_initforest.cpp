/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "PFC.h"

PFCForest* initForest() { //PFC����ɭ�ֳ�ʼ��
   PFCForest* forest = new PFCForest; //���ȴ�����ɭ�֣�Ȼ��
   for ( int i = 0; i < N_CHAR; i++ ) { //��ÿһ���ɴ�ӡ�ַ�[0x20, 0x80)
      forest->insert ( i, new PFCTree() ); //����һ�ö�Ӧ��PFC����������ʼʱ����
      ( *forest ) [i]->insertAsRoot ( 0x20 + i ); //ֻ������Ӧ��һ����Ҷ�������ڵ�
   }
   return forest; //���ذ���N_CHAR������ɭ�֣�����ÿ����������һ���ַ�
}