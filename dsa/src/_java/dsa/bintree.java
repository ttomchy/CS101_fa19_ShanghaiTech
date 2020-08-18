/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*
 * �������ӿ�
 */

package dsa;

public interface BinTree {
   //��������
   public BinTreePosition getRoot();

   //�ж��Ƿ�����
   public boolean isEmpty();

   //�������Ĺ�ģ���������ĺ����Ŀ��
   public int getSize();

   //�������������ĸ߶�
   public int getHeight();

   //ǰ�����
   public Iterator elementsPreorder();

   //�������
   public Iterator elementsInorder();

   //�������
   public Iterator elementsPostorder();

   //��α���
   public Iterator elementsLevelorder();
}