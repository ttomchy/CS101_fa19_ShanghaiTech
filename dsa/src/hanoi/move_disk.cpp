/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/


#include "hanoi.h"

void move ( Stack<Disk>& Sa, Stack<Disk>& Sb ) { //��Sa��������������Sb����
   Sb.push ( Sa.pop() ); //pop a disk from stack A and push it into stack B
   displayHanoi();
}