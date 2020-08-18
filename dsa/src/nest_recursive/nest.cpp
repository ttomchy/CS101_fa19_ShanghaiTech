/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "../nest_stack/nest.h"

void trim ( const char exp[], int& lo, int& hi ) { //ɾ��exp[lo, hi]�������ŵ��ǰ׺����׺
   while ( ( lo <= hi ) && ( exp[lo] != '(' ) && ( exp[lo] != ')' ) ) lo++; //���ҵ�һ����
   while ( ( lo <= hi ) && ( exp[hi] != '(' ) && ( exp[hi] != ')' ) ) hi--; //���һ������
}

int divide ( const char exp[], int lo, int hi ) { //�з�exp[lo, hi]��ʹexpƥ������ӱ��ʽƥ��
   int mi = lo; int crc = 1; //crcΪ[lo, mi]��Χ������������Ŀ֮��
   while ( ( 0 < crc ) && ( ++mi < hi ) ) //��������ַ���ֱ������������Ŀ��ȣ�����Խ��
      {  if ( exp[mi] == ')' )  crc--; if ( exp[mi] == '(' )  crc++;  } //�������ŷֱ����
   return mi; //��mi <= hi����Ϊ�Ϸ��зֵ㣻������ζ�žֲ�������ƥ��
}

bool paren ( const char exp[], int lo, int hi ) { //�����ʽexp[lo, hi]�Ƿ�����ƥ�䣨�ݹ�棩
   /*DSA*/displaySubstring ( exp, lo, hi );
   trim ( exp, lo, hi ); if ( lo > hi ) return true; //����������ŵ�ǰ׺����׺
   if ( exp[lo] != '(' ) return false; //���ַ��������ţ���ز�ƥ��
   if ( exp[hi] != ')' ) return false; //ĩ�ַ��������ţ���ز�ƥ��
   int mi = divide ( exp, lo, hi ); //ȷ���ʵ����зֵ�
   if ( mi > hi ) return false; //�зֵ㲻�Ϸ�����ζ�žֲ��������岻ƥ��
   return paren ( exp, lo + 1, mi - 1 ) && paren ( exp, mi + 1, hi ); //�ֱ��������ӱ��ʽ
}