/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

/******************************************************************************************
 * RedBlack˫������㷨������ڵ�x���丸��Ϊ��ɫ�����⡣��Ϊ�����������
 *    RR-1��2����ɫ��ת��2�κڸ߶ȸ��£�1~2����ת�����ٵݹ�
 *    RR-2��3����ɫ��ת��3�κڸ߶ȸ��£�0����ת����Ҫ�ݹ�
 ******************************************************************************************/
template <typename T> void RedBlack<T>::solveDoubleRed ( BinNodePosi(T) x ) { //x��ǰ��Ϊ��
   if ( IsRoot ( *x ) ) //���ѣ��ݹ飩ת������������ת�ڣ������ڸ߶�Ҳ��֮����
      {  _root->color = RB_BLACK; _root->height++; return;  } //����x�ĸ���p�ش���
   BinNodePosi(T) p = x->parent; if ( IsBlack ( p ) ) return; //��pΪ�ڣ������ֹ����������
   BinNodePosi(T) g = p->parent; //��ȻpΪ�죬��x���游�ش��ڣ��ұ�Ϊ��ɫ
   BinNodePosi(T) u = uncle ( x ); //���£���x�常u����ɫ�ֱ���
   if ( IsBlack ( u ) ) { //uΪ��ɫ����NULL��ʱ //*DSA*/printf("  case RR-1:\n");
      if ( IsLChild ( *x ) == IsLChild ( *p ) ) //��x��pͬ�ࣨ��zIg-zIg��zAg-zAg������
         p->color = RB_BLACK; //p�ɺ�ת�ڣ�x���ֺ�
      else //��x��p��ࣨ��zIg-zAg��zAg-zIg������
         x->color = RB_BLACK; //x�ɺ�ת�ڣ�p���ֺ�
      g->color = RB_RED; //g�ض��ɺ�ת��
///// �����䱣֤�ܹ�����Ⱦɫ�������������ж϶��ò���ʧ
///// ����ת�󽫸��úڡ������ú죬��������Ⱦɫ��Ч�ʸ���
      BinNodePosi(T) gg = g->parent; //���游��great-grand parent��
      BinNodePosi(T) r = FromParentTo ( *g ) = rotateAt ( x ); //��������������ڵ�
      r->parent = gg; //��ԭ���游����
   } else { //��uΪ��ɫ //*DSA*/printf("  case RR-2:\n");
      p->color = RB_BLACK; p->height++; //p�ɺ�ת��
      u->color = RB_BLACK; u->height++; //u�ɺ�ת��
      if ( !IsRoot ( *g ) ) g->color = RB_RED; //g���Ǹ�����ת��
      solveDoubleRed ( g ); //��������g��������β�ݹ飬���Ż�Ϊ������ʽ��
   }
}
