/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "rpn.h"

Operator optr2rank ( char op ) { //�������ת������
   switch ( op ) {
      case '+' : return ADD; //��
      case '-' : return SUB; //��
      case '*' : return MUL; //��
      case '/' : return DIV; //��
      case '^' : return POW; //�˷�
      case '!' : return FAC; //�׳�
      case '(' : return L_P; //������
      case ')' : return R_P; //������
      case '\0': return EOE; //��ʼ������ֹ��
      default  : exit ( -1 ); //δ֪�����
   }
}

char orderBetween ( char op1, char op2 ) //�Ƚ����������֮������ȼ�
{ return pri[optr2rank ( op1 ) ][optr2rank ( op2 ) ]; }
