/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "Huffman_PQ.h"

int encode ( HuffTable* table, Bitmap* codeString, char* s ) { //���ձ�����Bitmap������
   int n = 0; //�����صı��봮�ܳ�n
   for ( size_t m = strlen ( s ), i = 0; i < m; i++ ) { //���������е�ÿ���ַ�
      char** pCharCode = table->get ( s[i] ); //ȡ�����Ӧ�ı��봮
      if ( !pCharCode ) pCharCode = table->get ( s[i] + 'A' - 'a' ); //Сд��ĸתΪ��д
      if ( !pCharCode ) pCharCode = table->get ( ' ' ); //�޷�ʶ����ַ�ͳһ�����ո�
      printf ( "%s", *pCharCode ); //�����ǰ�ַ��ı���
      for ( size_t m = strlen ( *pCharCode ), j = 0; j < m; j++ ) //����ǰ�ַ��ı��������봮
         '1' == * ( *pCharCode + j ) ? codeString->set ( n++ ) : codeString->clear ( n++ );
   }
   printf ( "\n" ); return n;
} //�����Ʊ��봮��¼��λͼcodeString��
