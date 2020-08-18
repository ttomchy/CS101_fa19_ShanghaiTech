/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#include   "queen.h"

/******************************************************************************************
 * ȫ�ֱ���
 ******************************************************************************************/
RunMode runMode; //��ʾģʽ
int nSolu = 0; //�������
int nCheck = 0; //���Ե��ܴ���

/******************************************************************************************
 * �������
 ******************************************************************************************/
int main ( int argc, char* argv[] ) {
   if ( argc < 2 ) //��������и�ʽ
      { cout << "Usage: " << argv[0] << " <-step | -cont>" << endl; return -1; }
   if ( !strcmp ( "-step", argv[1] ) ) runMode = Step; //�趨Ϊ������ʾģʽ
   else if ( !strcmp ( "-cont", argv[1] ) ) runMode = Continuous; //�趨Ϊ������ʾģʽ
   else { cout << "Unrecognizable running mode" << endl; return -2; }
   place5Queens_BruteForce();
}