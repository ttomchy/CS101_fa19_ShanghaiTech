/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "rpn.h"

void readNumber ( char*& p, Stack<float>& stk ) { //����ʼ��p���Ӵ�����Ϊ��ֵ�������������ջ
   stk.push ( ( float ) ( *p - '0' ) ); //��ǰ��λ��Ӧ����ֵ��ջ
   while ( isdigit ( * ( ++p ) ) ) //ֻҪ�������н��ڵ����֣�����λ���������������
      stk.push ( stk.pop() * 10 + ( *p - '0' ) ); //����ԭ��������׷������λ������ֵ������ջ
   if ( '.' != *p ) return; //�˺��С���㣬����ζ�ŵ�ǰ�������������
   float fraction = 1; //������ζ�Ż���С������
   while ( isdigit ( * ( ++p ) ) ) //��λ����
      stk.push ( stk.pop() + ( *p - '0' ) * ( fraction /= 10 ) ); //С������
}
