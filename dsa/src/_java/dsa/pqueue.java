/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*
 * ���ȶ��нӿ�
 */

package dsa;

public interface PQueue {
   //ͳ�����ȶ��еĹ�ģ
   public int getSize();

   //�ж����ȶ����Ƿ�Ϊ��
   public boolean isEmpty();

   //��Q�ǿգ��򷵻����е���С��Ŀ������ɾ����;���򣬱���
   public Entry getMin() throws ExceptionPQueueEmpty;

   //������obj��ؼ���k�ϳ�һ����Ŀ���������Q�У������ظ���Ŀ
   public Entry insert(Object key, Object obj) throws ExceptionKeyInvalid;

   //��Q�ǿգ��������ժ���ؼ�����С����Ŀ�������ظ���Ŀ�����򣬱���
   public Entry delMin() throws ExceptionPQueueEmpty;
}