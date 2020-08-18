/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

typedef enum { AVAILABLE, ROUTE, BACKTRACKED, WALL } Status; //�Թ���Ԫ״̬
//ԭʼ���õġ��ڵ�ǰ·���ϵġ����з��������ʧ�ܺ���ݹ��ġ�����ʹ�õģ�ǽ��

typedef enum { UNKNOWN, EAST, SOUTH, WEST, NORTH, NO_WAY } ESWN; //��Ԫ������ڽӷ���
//δ���������ϡ�����������·��ͨ

inline ESWN nextESWN ( ESWN eswn ) { return ESWN ( eswn + 1 ); } //����ת����һ�ڽӷ���

struct Cell { //�Թ����
   int x, y; Status status; //x���ꡢy���ꡢ����
   ESWN incoming, outgoing; //���롢�߳�����
};

#define LABY_MAX 24 //����Թ��ߴ�
Cell laby[LABY_MAX][LABY_MAX]; //�Թ�