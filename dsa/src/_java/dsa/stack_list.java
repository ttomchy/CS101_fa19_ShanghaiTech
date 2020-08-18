/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*
 * ���ڵ�����ʵ��ջ�ṹ
 */

package dsa;

public class Stack_List implements Stack {
   protected Node top;//ָ��ջ��Ԫ��
   protected int size;//ջ��Ԫ�ص���Ŀ

   //���췽������ջ��
   public Stack_List()
   {  top = null; size = 0; }

   //��ѯ��ǰջ�Ĺ�ģ
   public int getSize()
   {  return size; }

   //�ж��Ƿ�ջ��
   public boolean isEmpty()
   {  return (top == null) ? true : false; }

   //ѹջ
   public void push(Object elem) {
      Node v = new Node(elem, top);//����һ���½ڵ㣬������Ϊ�׽ڵ����
      top = v;//�����׽ڵ�����
      size++;//���¹�ģ��¼
   }

   //��ȡ������ɾ����ջ��
   public Object top() throws ExceptionStackEmpty {
      if (isEmpty())
         throw new ExceptionStackEmpty("���⣺ջ��");
      return top.getElem();
   }

   //����ջ��
   public Object pop() throws ExceptionStackEmpty {
      if (isEmpty())
         throw new ExceptionStackEmpty("���⣺ջ��");
      Object temp = top.getElem();
      top = top.getNext();//�����׽ڵ�����
      size--;//���¹�ģ��¼
      return temp;
   }
}