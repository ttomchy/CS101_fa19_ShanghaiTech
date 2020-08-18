/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*
 * ��������ѭ������ʵ��Queue�ӿ�
 */

package dsa;

public class Queue_Array implements Queue {
   public static final int CAPACITY = 1000;//�����Ĭ������
   protected int capacity;//�����ʵ������
   protected Object[] Q;//��������
   protected int f = 0;//����Ԫ�ص�λ��
   protected int r = 0; //��βԪ�ص�λ��

   //���췽�����ն��У�
   public Queue_Array()
   {  this(CAPACITY);   }

   //��ָ��������������
   public Queue_Array(int cap)
   {  capacity = cap;   Q = new Object[capacity];  }

   //��ѯ��ǰ���еĹ�ģ
   public int getSize()
   {  return (capacity - f + r) % capacity;   }

   //�ж϶����Ƿ�Ϊ��
   public boolean isEmpty()
   {  return (f == r);  }

   //���
   public void enqueue(Object obj) throws ExceptionQueueFull {
      if (getSize() == capacity - 1)
         throw new ExceptionQueueFull("Queue overflow.");
      Q[r] = obj;
      r = (r + 1) % capacity;
   }

   //����
   public Object dequeue() {
      Object elem;
      if (isEmpty())
         throw new ExceptionQueueEmpty("���⣺���п�");
      elem = Q[f];
      Q[f] = null;
      f = (f + 1) % capacity;
      return elem;
   }

   //ȡ������ɾ��������Ԫ��
   public Object front() throws ExceptionQueueEmpty {
      if (isEmpty())
         throw new ExceptionQueueEmpty("���⣺���п�");
      return Q[f];
   }

   //������������ADT��
   public void Traversal() {
      for (int i = f; i < r; i++)
         System.out.print(Q[i] + " ");
      System.out.println();
   }
}