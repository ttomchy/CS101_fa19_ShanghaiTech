/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

/******************************************************************************************
 * RedBlack˫�ڵ����㷨������ڵ�x�뱻������Ľڵ��Ϊ��ɫ������
 * ��Ϊ�����๲���������
 *    BB-1 ��2����ɫ��ת��2�κڸ߶ȸ��£�1~2����ת�����ٵݹ�
 *    BB-2R��2����ɫ��ת��2�κڸ߶ȸ��£�0����ת�����ٵݹ�
 *    BB-2B��1����ɫ��ת��1�κڸ߶ȸ��£�0����ת����Ҫ�ݹ�
 *    BB-3 ��2����ɫ��ת��2�κڸ߶ȸ��£�1����ת��תΪBB-1��BB2R
 ******************************************************************************************/
template <typename T> void RedBlack<T>::solveDoubleBlack ( BinNodePosi(T) r ) {
   BinNodePosi(T) p = r ? r->parent : _hot; if ( !p ) return; //r�ĸ���
   BinNodePosi(T) s = ( r == p->lc ) ? p->rc : p->lc; //r���ֵ�
   if ( IsBlack ( s ) ) { //�ֵ�sΪ��
      BinNodePosi(T) t = NULL; //s�ĺ캢�ӣ������Һ��ӽԺ죬�������ȣ��Ժ�ʱΪNULL��
      if ( IsRed ( s->rc ) ) t = s->rc; //����
      if ( IsRed ( s->lc ) ) t = s->lc; //����
      if ( t ) { //��s�к캢�ӣ�BB-1
         //*DSA*/printf("  case BB-1: Child ("); print(s->lc); printf(") of BLACK sibling ("); print(s); printf(") is RED\n");
         RBColor oldColor = p->color; //����ԭ�������ڵ�p��ɫ������t���丸�ס��游
      // ���£�ͨ����ת��ƽ�⣬���������������Һ���Ⱦ��
         BinNodePosi(T) b = FromParentTo ( *p ) = rotateAt ( t ); //��ת
         if ( HasLChild ( *b ) ) { b->lc->color = RB_BLACK; updateHeight ( b->lc ); } //����
         if ( HasRChild ( *b ) ) { b->rc->color = RB_BLACK; updateHeight ( b->rc ); } //����
         b->color = oldColor; updateHeight ( b ); //���������ڵ�̳�ԭ���ڵ����ɫ
         //*DSA*/printBinTree(b, 0, 0);
      } else { //��s�޺캢��
         s->color = RB_RED; s->height--; //sת��
         if ( IsRed ( p ) ) { //BB-2R
            //*DSA*/printf("  case BB-2R: Both children ("); print(s->lc); printf(") and ("); print(s->rc); printf(") of BLACK sibling ("); print(s); printf(") are BLACK, and parent ("); print(p); printf(") is RED\n"); //s���Ӿ��ڣ�p��
            p->color = RB_BLACK; //pת�ڣ����ڸ߶Ȳ���
            //*DSA*/printBinTree(p, 0, 0);
         } else { //BB-2B
            //*DSA*/printf("  case BB-2R: Both children ("); print(s->lc); printf(") and ("); print(s->rc); printf(") of BLACK sibling ("); print(s); printf(") are BLACK, and parent ("); print(p); printf(") is BLACK\n"); //s���Ӿ��ڣ�p��
            p->height--; //p���ֺڣ����ڸ߶��½�
            //*DSA*/printBinTree(p, 0, 0);
            solveDoubleBlack ( p ); //�ݹ�����
         }
      }
   } else { //�ֵ�sΪ�죺BB-3
      //*DSA*/printf("  case BB-3: sibling ("); print(s); printf(" is RED\n"); //s�죨˫�Ӿ�ڣ�
      s->color = RB_BLACK; p->color = RB_RED; //sת�ڣ�pת��
      BinNodePosi(T) t = IsLChild ( *s ) ? s->lc : s->rc; //ȡt���丸sͬ��
      _hot = p; FromParentTo ( *p ) = rotateAt ( t ); //��t���丸�ס��游��ƽ�����
      //*DSA*/printBinTree<T>(s, 0, 0);
      solveDoubleBlack ( r ); //��������r��˫�ڡ�����ʱ��p��ת�죬�ʺ���ֻ����BB-1��BB-2R
   }
}
