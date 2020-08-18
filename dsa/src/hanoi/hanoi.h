/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

#include <stdio.h>
#include <stdlib.h>

#include "../_share/util.h"
#include "../stack/stack.h"

typedef  int   Disk;

void displayHanoi();
void hanoi ( int, Stack<Disk>&, Stack<Disk>&, Stack<Disk>& );
void move ( Stack<Disk>&, Stack<Disk>& );

extern int nDisk; //��������
extern Stack<int> Sx, Sy, Sz; //������ջģ���������ӣ�ÿ�����ӵİ뾶��������ʾ
