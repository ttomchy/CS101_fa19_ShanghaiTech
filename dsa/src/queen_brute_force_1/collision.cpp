/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#include "queen.h"

bool collide ( int* solu, int k ) { //�ж��Ƿ�����ڵ�ǰ�еĵ�k�з�����һ�ʺ�
   nCheck++;
   for ( int i = 0; i < k; i++ ) {
      if ( solu[k] == solu[i] )       return true; //��
      if ( solu[k] - solu[i] == k - i ) return true; //�Խ���
      if ( solu[k] - solu[i] == i - k ) return true; //���Խ���
   }
   return false;
}