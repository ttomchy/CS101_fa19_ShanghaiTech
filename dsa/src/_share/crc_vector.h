/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "..\vector\vector.h"

template <typename T> void crc ( Vector<T> & V ) { //ͳ������������������Ԫ��֮�ͣ�
   T crc = 0; V.traverse ( Crc<T> ( crc ) ); //��crcΪ�����������б���
   printf ( "CRC =" ); print ( crc ); printf ( "\n" ); //���ͳ�Ƶõ�������
}