/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*
 * ջ�ӿ�
 */

package dsa;

public interface Stack {
   public int getSize();//����ջ��Ԫ����Ŀ
   public boolean isEmpty();//�ж�ջ�Ƿ�Ϊ��
   public Object top() throws ExceptionStackEmpty;//ȡջ��Ԫ�أ�����ɾ����
   public void push (Object ele);//��ջ
   public Object pop() throws ExceptionStackEmpty;//��ջ
}