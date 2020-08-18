/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*
 * ��������ʵ�ֶ�����
 */

package dsa;

public class BinTree_LinkedList implements BinTree {
   protected BinTreePosition root;//���ڵ�

   /**************************** ���캯�� ****************************/
   public BinTree_LinkedList()
   { this(null); }

   public BinTree_LinkedList(BinTreePosition r)
   { root = r; }

   /**************************** BinaryTree�ӿڷ��� ****************************/
   //��������
   public BinTreePosition getRoot()
   { return root; }

   //�ж��Ƿ�����
   public boolean isEmpty()
   { return null == root; }

   //�������Ĺ�ģ���������ĺ����Ŀ��
   public int getSize()
   { return isEmpty() ? 0 : root.getSize(); }

   //�������������ĸ߶�
   public int getHeight()
   {return isEmpty() ? -1 : root.getHeight(); }

   //ǰ�����
   public Iterator elementsPreorder()
   { return root.elementsPreorder(); }

   //�������
   public Iterator elementsInorder()
   { return root.elementsInorder(); }

   //�������
   public Iterator elementsPostorder()
   { return root.elementsPostorder(); }

   //��α���
   public Iterator elementsLevelorder()
   { return root.elementsLevelorder(); }
}