/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*
 * �����ӿ�
 */

package dsa;

public interface Vector {
   //����������Ԫ����Ŀ
   public int getSize();

   //�ж������Ƿ�Ϊ��
   public boolean isEmpty();

   //ȡ��Ϊr��Ԫ��
   public Object getAtRank(int r)
   throws ExceptionBoundaryViolation;

   //����Ϊr��Ԫ���滻Ϊobj
   public Object replaceAtRank(int r, Object obj)
   throws ExceptionBoundaryViolation;

   //����obj����Ϊ��Ϊr��Ԫ�أ����ظ�Ԫ��
   public Object insertAtRank(int r, Object obj)
   throws ExceptionBoundaryViolation;

   //ɾ����Ϊr��Ԫ��
   public Object removeAtRank(int r)
   throws ExceptionBoundaryViolation;
}