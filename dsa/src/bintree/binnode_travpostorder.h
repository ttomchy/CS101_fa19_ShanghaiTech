/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

/*DSA*/#include "../stack/Stack.h" //����ջģ����
/*DSA*/#include "BinNode_TravPostorder_R.h"
/*DSA*/#include "BinNode_TravPostorder_I.h"
template <typename T> template <typename VST> //Ԫ�����͡�������
void BinNode<T>::travPost ( VST& visit ) { //��������������㷨ͳһ���
   switch ( rand() % 2 ) { //�˴������ѡ���������ԣ�������ѡ��
      case 1: travPost_I ( this, visit ); break; //������
      default: travPost_R ( this, visit ); break; //�ݹ��
   }
}