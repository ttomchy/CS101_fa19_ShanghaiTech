/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "rpn.h"

void append ( char*& rpn, float opnd ) { //������������RPNĩβ
   int n = strlen ( rpn ); //RPN��ǰ���ȣ���'\0'��β������n + 1��
   char buf[64];
   if ( opnd != ( float ) ( int ) opnd ) sprintf ( buf, "%.2f \0", opnd ); //�����ʽ����
   else                          sprintf ( buf, "%d \0", ( int ) opnd ); //������ʽ
   rpn = ( char* ) realloc ( rpn, sizeof ( char ) * ( n + strlen ( buf ) + 1 ) ); //��չ�ռ�
   strcat ( rpn, buf ); //RPN�ӳ�
}

void append ( char*& rpn, char optr ) { //�����������RPNĩβ
   int n = strlen ( rpn ); //RPN��ǰ���ȣ���'\0'��β������n + 1��
   rpn = ( char* ) realloc ( rpn, sizeof ( char ) * ( n + 3 ) ); //��չ�ռ�
   sprintf ( rpn + n, "%c ", optr ); rpn[n + 2] = '\0'; //����ָ���������
}