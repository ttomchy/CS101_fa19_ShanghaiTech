/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "RPN.h"

float evaluate ( char* S, char*& RPN ) { //�ԣ����޳��׿ո�ģ����ʽS��ֵ����ת��Ϊ�沨��ʽRPN
   Stack<float> opnd; Stack<char> optr; //������ջ�������ջ /*DSA*/�κ�ʱ�̣�����ÿ������Ԫ��֮�����Сһ��
   /*DSA*/ char* expr = S;
   optr.push ( '\0' ); //β�ڱ�'\0'Ҳ��Ϊͷ�ڱ�������ջ
   while ( !optr.empty() ) { //�������ջ�ǿ�֮ǰ�����������ʽ�и��ַ�
      if ( isdigit ( *S ) ) { //����ǰ�ַ�Ϊ����������
         readNumber ( S, opnd ); append ( RPN, opnd.top() ); //��������������������RPNĩβ
      } else //����ǰ�ַ�Ϊ���������
         switch ( orderBetween ( optr.top(), *S ) ) { //������ջ�������֮�����ȼ��ߵͷֱ���
            case '<': //ջ����������ȼ�����ʱ
               optr.push ( *S ); S++; //�����Ƴ٣���ǰ�������ջ
               break;
            case '=': //���ȼ���ȣ���ǰ�����Ϊ�����Ż���β���ڱ�'\0'��ʱ
               optr.pop(); S++; //�����Ų�������һ���ַ�
               break;
            case '>': { //ջ����������ȼ�����ʱ����ʵʩ��Ӧ�ļ��㣬�������������ջ
               char op = optr.pop(); append ( RPN, op ); //ջ���������ջ��������RPNĩβ
               if ( '!' == op ) { //������һԪ�����
                  float pOpnd = opnd.pop(); //ֻ��ȡ��һ������������
                  opnd.push ( calcu ( op, pOpnd ) ); //ʵʩһԪ���㣬�����ջ
               } else { //������������Ԫ�������
                  float pOpnd2 = opnd.pop(), pOpnd1 = opnd.pop(); //ȡ����ǰ������ /*DSA*/���ʣ��ɷ�ʡȥ������ʱ������
                  opnd.push ( calcu ( pOpnd1, op, pOpnd2 ) ); //ʵʩ��Ԫ���㣬�����ջ
               }
               break;
            }
            default : exit ( -1 ); //���﷨���󣬲�������ֱ���˳�
         }//switch
      /*DSA*/displayProgress ( expr, S, opnd, optr, RPN );
   }//while
   return opnd.pop(); //�������������ļ�����
}