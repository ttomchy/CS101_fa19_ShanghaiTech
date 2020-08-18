/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*
 * ������ͼ����DFSģ��Ŀɴ�����㷨
 */

package dsa;

public class DFSReachableComponent extends DFS {
   //���췽��
   public DFSReachableComponent(Graph g) { super(g); }

   //DFS�����жԶ���v�ľ�����ʲ�����infoʵ������һ��ջ����¼���пɴ�Ķ��㣩
   protected Object visit(Vertex v, Object info)
   { ((Stack)info).push(v); return null; }

   //����DFS�Ŀɴ����㷨��sΪ��ʼ���㣨infoʵ������һ��ջ����¼���пɴ�Ķ��㣩
   public Object algorithm(Vertex s, Object info) {
      reset(s);
      Stack S = new Stack_Array();//�������ʼ����ɴ�Ķ���
      traverse(s, info);//DFS
      return null;
   }
}
