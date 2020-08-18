/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define printString(s) { for (size_t m = strlen(s), k = 0; k < m; k++) printf("%4c", (s)[k]); }

void showProgress ( char*, char*, int, int ); //��ʾ�㷨����
void printNext ( int*, int, int ); //��ӡNext��
int* buildNext ( char* ); //����Next��
void printBC ( int* ); //��ӡBC��
int* buildBC ( char* ); //����BC��
void printGS ( char*, int* ); //��ӡGS��
int* buildGS ( char* ); //����GS��