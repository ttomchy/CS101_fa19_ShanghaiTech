/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*
 * ������ͼ�Ĺ�����ȱ����㷨ģ��
 */

package dsa;

public abstract class BFS extends GraphTraverse {
   //���췽��
   public BFS(Graph g) { super(g); }

   //������ȱ����㷨
   protected Object traverse(Vertex s, Object info) {//�Ӷ���s��������������Ȳ���
      if (UNDISCOVERED != s.getStatus())  return null;//�����ѷ��ʹ��Ķ��㣨��Է���ͨͼ��
      Queue Q = new Queue_List();//����һ������
      s.setStatus(DISCOVERED);//����s��
      Q.enqueue(s);//�漴�������
      visit(s, null);//������֮
      while (!Q.isEmpty()) {//�ڶ��б��֮ǰ
         Vertex v = (Vertex)Q.dequeue();//ȡ�����׶���v
         for (Iterator it = v.outEdges(); it.hasNext();) {//����붥��v
            Edge e = (Edge)it.getNext();//ͨ����e = (v, u)
            Vertex u = (Vertex)e.getVPosInV(1).getElem();//������ÿһ����u
            if (UNDISCOVERED == u.getStatus()) {//��u��δ�����֣���
               e.setType(TREE);//��e����Ϊ����
               u.setStatus(DISCOVERED);//����u��
               Q.enqueue(u);//�漴�������
               visit(u, v);//������֮
            } else {//��u�ѱ����֣������ѷ�����ϣ�����ͼ������
               e.setType(CROSS);//��e����Ϊ���
            }
         }//���ˣ�v�������ھӶ��ѷ��ʽ�������
         v.setStatus(VISITED);//��v���ΪVISITED
      }//while
      return null;
   }
}
