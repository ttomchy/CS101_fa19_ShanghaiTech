/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*
 * �����б�ʵ�ֵ�λ�õ�����
 */

package dsa;

public class IteratorPosition implements Iterator {
   private List list;//�б�
   private Position nextPosition;//��ǰ����һ����λ��

   //Ĭ�Ϲ��췽��
   public IteratorPosition() { list = null; }

   //���췽��
   public IteratorPosition(List L) {
      list = L;
      if (list.isEmpty())//���б�Ϊ�գ���
         nextPosition = null;//��ǰλ���ÿ�
      else//����
         nextPosition = list.first();//�ӵ�һ��λ�ÿ�ʼ
   }

   //�����������Ƿ���ʣ���λ��
   public boolean hasNext() { return (nextPosition != null); }

   //���ص������е���һλ��
   public Object getNext() throws ExceptionNoSuchElement {
      if (!hasNext()) throw new ExceptionNoSuchElement("���⣺û����һλ��");
      Position currentPosition = nextPosition;
      if (currentPosition == list.last())//���ѵ���βλ�ã���
         nextPosition = null;//��������һ��λ��
      else//����
         nextPosition = list.getNext(currentPosition);//ת����һλ��
      return currentPosition;
   }
}