/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

inline Cell* neighbor ( Cell* cell ) { //��ѯ��ǰλ�õ����ڸ��
   switch ( cell->outgoing ) {
      case EAST  : return cell + LABY_MAX; //��
      case SOUTH : return cell + 1;        //����
      case WEST  : return cell - LABY_MAX; //����
      case NORTH : return cell - 1;        //��
      default    : exit ( -1 );
   }
}