/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*
 * �����򣩴�Ȩͼ������ȱ���
 */

package dsa;

public abstract class BestFS extends GraphTraverse {
   //���췽��
   public BestFS(Graph g) { super(g); }

   //������δ���ʵĶ��㵽�ѷ��ʵ㼯����̾��루ȡ���ھ�����㷨��
   protected abstract void updateDistanceAfter(Vertex v);

   //������ȱ����㷨
   protected Object traverse(Vertex s, Object info) {//�Ӷ���s��������������ȱ���
      if (UNDISCOVERED != s.getStatus())  return null;//�����ѷ��ʹ��Ķ��㣨��Է���ͨͼ��
      s.setDistance(0);//����s���ѷ��ʵ㼯�ľ���
      Vertex v;//��Ѷ���
      while (null != (v = bestVertex())) {//ֻҪ������Ѷ���
         visit(v, null);//�ڷ��ֲ�����v֮��
         updateDistanceAfter(v);//������δ���ʵĶ��㵽�ѷ��ʼ�����̾���
      }//while
      return null;
   }

   //������ʲ������ڱ��㷨�У�info����
   protected Object visit(Vertex v, Object info)   {
      v.setStatus(VISITED);//���á��ѷ��ʡ����
      return null;
   }

   //����BestFSʵ�ֵ���̾����㷨��sΪ��ʼ���㣬info���㷨���ݲ���
   public Object algorithm(Vertex s, Object info) {
      reset(s);//��ʼ������Ǹ�λ
      traverse(s, info);//BestFS����������̾����¼�ڸ������distance����
      return null;
   }

   //����δ���ʵĶ�����ѡ�������
   //����Dijkstra�㷨���ԣ��������ѷ��ʼ���ͨ����������Ķ��㣨�����벻�������������㣩
   //��û�������Ķ��㣬�򷵻�null
   protected Vertex bestVertex() {
      int bestValue = Integer.MAX_VALUE;//���ָ�꣨ԽСԽ�ã�
      Vertex bestVertex = null;//��Ѷ���
      for (Iterator it = G.vertices(); it.hasNext();) {//������
         Vertex u = (Vertex)it.getNext();//����
         if (UNDISCOVERED == u.getStatus())//��δ���ʵĶ���u
            if (bestValue > u.getDistance())//��u���ѷ��ʵ㼯�����������
               { bestValue = u.getDistance();  bestVertex = u; }//������Ѽ�¼
      }
      if ((null != bestVertex) && (null != bestVertex.getBFSParent()))//��Ѷ������丸��֮�������
         G.edgeFromTo(bestVertex.getBFSParent(), bestVertex).setType(TREE);//�����ΪTREE
      return bestVertex;
   }
}
