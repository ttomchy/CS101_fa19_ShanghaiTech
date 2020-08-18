/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*
 * �����򣩴�Ȩͼ��С��������Prim-Jarnik�㷨
 */

package dsa;

public class BestFSPrim extends BestFS {
   //���췽��
   public BestFSPrim(Graph g) { super(g); }

   //������δ���ʵĶ��㵽�ѷ��ʼ�����̾���
   protected void updateDistanceAfter(Vertex v) {
      for (Iterator it = v.outEdges(); it.hasNext();) {//����붥��v
         Edge e = (Edge)it.getNext();//ͨ����e = (v, w)
         Vertex w = (Vertex)e.getVPosInV(1).getElem();//������ÿһ����w
         int   weight = ((Integer)e.getInfo()).intValue();//���ݱ�(v, w)��Ȩ��
         if (w.getDistance() > weight) {//ȡԭ�������¾����е�С��
            w.setDistance(weight);
            w.setBFSParent(v);
         }
      }
   }
}
