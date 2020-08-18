/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "pm_kr.h"

HashCode prepareDm ( size_t m ) { //Ԥ��������R^(m - 1) % M ���������һ�Σ������Ż���
   HashCode  Dm = 1;
   for ( size_t i = 1; i < m; i++ ) Dm = ( R * Dm ) % M; //ֱ���۳�m - 1�Σ���ȡģ
   return Dm;
}