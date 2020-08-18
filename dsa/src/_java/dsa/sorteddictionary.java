/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*
 * ����ʵ�ӿ�
 */

package dsa;

public interface SortedDictionary extends Dictionary {
   //���ʵ�ǿգ��򷵻����йؼ�����С����Ŀ�����򣬷���null
   public Entry first();

   //���ʵ�ǿգ��򷵻����йؼ���������Ŀ�����򣬷���null
   public Entry last();

   //�����ɹؼ��벻С��key����Ŀ���ǽ�����ɵĵ�����
   public Iterator successors(Object key);

   //�����ɹؼ��벻����key����Ŀ����������ɵĵ�����
   public Iterator predecessors(Object key);
}