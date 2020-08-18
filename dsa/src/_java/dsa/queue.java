/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*
 * ���нӿ�
 */

package dsa;

public interface Queue {
   public int getSize();//���ض�����Ԫ����Ŀ
   public boolean isEmpty();//�ж϶����Ƿ�Ϊ��
   public Object front()//ȡ����Ԫ�أ�����ɾ����
   throws ExceptionQueueEmpty;
   public void enqueue (Object obj)
   throws ExceptionQueueFull;//���
   public Object dequeue()//����
   throws ExceptionQueueEmpty;
   public void Traversal();//����
}