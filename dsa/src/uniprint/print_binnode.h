/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

/******************************************************************************************
 * BinTree�ڵ�
 ******************************************************************************************/
template <typename T> void UniPrint::p ( BinNode<T>& node ) {
   p ( node.data ); //��ֵ
   /******************************************************************************************
    * height & NPL
    ******************************************************************************************/
#if   defined(DSA_LEFTHEAP)
   printf ( "(%-2d)", node.npl ); //NPL
#elif defined(DSA_BST)
   printf ( "(%-2d)", node.height ); //�߶�
#elif defined(DSA_AVL)
   printf ( "(%-2d)", node.height ); //�߶�
#elif defined(DSA_REDBLACK)
   printf ( "(%-2d)", node.height ); //�߶�
#elif defined(DSA_SPLAY)
   printf ( "(%-2d)", node.height ); //�߶�
#endif
   /******************************************************************************************
    * ��������ָ��
    ******************************************************************************************/
   printf (
      (  ( node.lc && &node != node.lc->parent ) ||
         ( node.rc && &node != node.rc->parent )  ) ?
      "@" : " "
   );
   /******************************************************************************************
    * �ڵ���ɫ
    ******************************************************************************************/
#if defined(DSA_REDBLACK)
   printf ( node.color == RB_BLACK ? "B" : " " ); //�����Ժ�ڵ㣩
#endif
   /******************************************************************************************
    * ���ӣ��ڣ��߶ȡ�NPLƥ��
    ******************************************************************************************/
#if   defined(DSA_PQ_COMPLHEAP)
   //�߶Ȳ���ƥ��
#elif defined(DSA_PQ_LEFTHEAP)
   printf ( //NPL
      ( node.rc && node.npl != 1 + node.rc->npl ) ||
      ( node.lc && node.npl >  1 + node.lc->npl ) ?
      "%%" : " "
   );
#elif defined(DSA_REDBLACK)
   printf ( BlackHeightUpdated ( node ) ? " " : "!" ); //�ڸ߶�
#else
   printf ( HeightUpdated ( node ) ? " " : "!" ); //�����棩�߶�
#endif
   /******************************************************************************************
    * ����ƽ��
    ******************************************************************************************/
#if defined(DSA_AVL)
   if ( !AvlBalanced ( node ) ) printf ( "X" ); //AVLƽ��
   else if ( 0 < BalFac ( node ) ) printf ( "\\" ); //AVLƽ��
   else if ( BalFac ( node ) < 0 ) printf ( "/" ); //AVLƽ��
   else printf ( "-" ); //AVLƽ��
#elif defined(DSA_REDBLACK)
   if ( !Balanced ( node ) ) printf ( "X" ); //RBƽ��
   else if ( 0 < BalFac ( node ) ) printf ( "\\" ); //RBƽ��
   else if ( BalFac ( node ) < 0 ) printf ( "/" ); //RBƽ��
   else printf ( "-" ); //RBƽ��
#else
   //ƽ������ν
#endif
}