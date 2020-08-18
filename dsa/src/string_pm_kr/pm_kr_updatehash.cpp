/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "pm_kr.h"

// �Ӵ�ָ�ƿ��ٸ����㷨
void updateHash ( HashCode& hashT, char* T, size_t m, size_t k, HashCode Dm ) {
   hashT = ( hashT - DIGIT ( T, k - 1 ) * Dm ) % M; //��ǰһָ�ƻ����ϣ�ȥ����λT[k - 1]
   hashT = ( hashT * R + DIGIT ( T, k + m - 1 ) ) % M; //���ĩλT[k + m - 1]
   if ( 0 > hashT ) hashT += M; //ȷ��ɢ�������ںϷ�������
}
