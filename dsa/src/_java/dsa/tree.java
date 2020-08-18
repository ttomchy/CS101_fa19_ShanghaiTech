/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*
 * ��ADT�ӿ�
 */

package dsa;

public interface Tree {
   //���ص�ǰ�ڵ��д�ŵĶ���
   public Object getElem();
   //������obj���뵱ǰ�ڵ㣬�����ش�ǰ������
   public Object setElem(Object obj);

   //���ص�ǰ�ڵ�ĸ��ڵ�
   public TreeLinkedList getParent();

   //���ص�ǰ�ڵ�ĳ���
   public TreeLinkedList getFirstChild();

   //���ص�ǰ�ڵ�����ܵ�
   public TreeLinkedList getNextSibling();

   //���ص�ǰ�ڵ���Ԫ�ص���Ŀ�����Ե�ǰ�ڵ�Ϊ���������Ĺ�ģ
   public int getSize();

   //���ص�ǰ�ڵ�ĸ߶�
   public int getHeight();

   //���ص�ǰ�ڵ�����
   public int getDepth();
}