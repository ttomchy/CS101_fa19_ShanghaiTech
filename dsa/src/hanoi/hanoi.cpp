/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "hanoi.h"
// ����Hanoi���򣬽�����Sx�ϵ�nֻ���ӣ���������Sy��ת���Ƶ�����Sz��
void hanoi ( int n, Stack<Disk>& Sx, Stack<Disk>& Sy, Stack<Disk>& Sz ) {
   if ( n > 0 )   { //û������ʣ��ʱ�����ٵݹ�
      hanoi ( n - 1, Sx, Sz, Sy ); //�ݹ飺��Sx�ϵ�n - 1ֻ���ӣ�����Sz��ת���Ƶ�Sy��
      move ( Sx, Sz ); //ֱ�ӣ���Sx�����һֻ���ӣ��Ƶ�Sz��
      hanoi ( n - 1, Sy, Sx, Sz ); //�ݹ飺��Sy�ϵ�n - 1ֻ���ӣ�����Sx��ת���Ƶ�Sz��
   }
}
