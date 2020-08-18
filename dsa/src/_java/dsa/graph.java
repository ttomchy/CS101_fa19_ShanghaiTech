/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*
 * ������ͼ�ṹ�ӿ�
 * ����ͼҲ���Կ���������ͼ��Ϊ�ˣ�ֻ�轫ÿ��������滻Ϊ�ԳƵ�һ�������
 */

package  dsa;

public interface Graph {
   //ȡͼ�ж��㡢�ߵ���Ŀ
   public int vNumber();
   public int eNumber();

   //ȡͼ�����ж��㡢����λ�õĵ�����
   public Iterator vertices();
   public Iterator vPositions();

   //����ͼ�����бߡ���λ�õĵ�����
   public Iterator edges();
   public Iterator ePositions();

   //����Ƿ���ĳ���ߴӶ���uָ��v
   public boolean areAdjacent(Vertex u, Vertex v);
   //ȡ�Ӷ���uָ��v�ıߣ��������ڣ��򷵻�null
   public Edge edgeFromTo(Vertex u, Vertex v);

   //������v�Ӷ��㼯��ɾ����������֮
   public Vertex remove(Vertex v);
   //����e�ӱ߼���ɾ����������֮
   public Edge remove(Edge e);
   //�ڶ��㼯V�в����¶���v����������λ��
   public Position insert(Vertex v);
   //�ڱ߼�E�в����±�e����������λ��
   public Position insert(Edge e);
}