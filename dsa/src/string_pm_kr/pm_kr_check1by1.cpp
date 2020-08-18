/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "pm_kr.h"

bool check1by1 ( char* P, char* T, size_t i ) { //ָ����ͬʱ����λ�ȶ���ȷ���Ƿ�����ƥ��
   for ( size_t m = strlen ( P ), j = 0; j < m; j++, i++ ) //������ҪO(m)ʱ��
      if ( P[j] != T[i] ) return false; //��ֻҪɢ�еõ������ñ����̲�����false�ĸ��ʽ�����
   return true;
}
