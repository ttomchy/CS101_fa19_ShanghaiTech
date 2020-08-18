/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "../Bitmap/Bitmap.h"

int primeNLT ( int c, int n, char* file ) { //����file�ļ��еļ�¼����[c, n)��ȡ��С������
   Bitmap B ( file, n ); //file�Ѿ���λͼ��ʽ����¼��n���ڵ��������������ֻҪ
   while ( c < n ) //��c��ʼ����λ��
      if ( B.test ( c ) ) c++; //���ԣ�����
      else return c; //�����׸����ֵ�����
   return c; //��û������������������n��ʵ���в�����˼򻯴���
}
