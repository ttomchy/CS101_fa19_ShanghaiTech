/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

#include "../_share/util.h"
#include "../UniPrint/print.h"

#include "huffman_PQ.h"

extern int* statistics ( char* ); //���������ļ�ͳ�Ƹ��ַ�����Ƶ��
extern HuffForest* initForest ( int* ); //����������ɭ��
extern HuffTree* generateTree ( HuffForest* ); //���������
extern HuffTable* generateTable ( HuffTree* ); //�ɱ�����ת��Ϊ�����
extern int encode ( HuffTable*, Bitmap*, char* ); //���ĵı��룬���ر��볤��
extern void decode ( HuffTree*, Bitmap*, int ); //�����ƴ��Ľ���