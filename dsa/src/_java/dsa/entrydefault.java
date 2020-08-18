/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*
 * Ĭ����Ŀ
 */

package  dsa;

public class EntryDefault implements Entry {
   protected Object key;
   protected Object value;

   /**************************** ���캯�� ****************************/
   public EntryDefault(Object k, Object v)
   { key = k;  value = v; }

   /**************************** Entry�ӿڷ��� ****************************/
   //ȡ��Ŀ�Ĺؼ���
   public Object getKey()
   { return key; }
   //�޸���Ŀ�Ĺؼ��룬���ش�ǰ��ŵĹؼ���
   public Object setKey(Object k)
   { Object oldK = key; key = k; return oldK; }

   //ȡ��Ŀ�����ݶ���
   public Object getValue()
   { return value; }
   //�޸���Ŀ�����ݶ��󣬷��ش�ǰ��ŵ����ݶ���
   public Object setValue(Object v)
   { Object oldV = value;  value = v;  return oldV; }
}