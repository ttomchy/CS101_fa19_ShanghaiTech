/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*
 * ��ȫ�������ӿ�
 */

package dsa;

public interface ComplBinTree extends BinTree {
   //���ɲ�����һ�����e���ⲿ�ڵ㣬�ýڵ��Ϊ�µ�ĩ�ڵ�
   public BinTreePosition addLast(Object e);

   //ɾ��ĩ�ڵ㣬���������д�ŵ�����
   public Object delLast();

   //���ذ��ղ�α������Ϊi�Ľڵ��λ�ã�0 <= i < size()
   public BinTreePosition posOfNode(int i);
}