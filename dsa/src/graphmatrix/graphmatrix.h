/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "../Vector/Vector.h" //��������
#include "../Graph/Graph.h" //����ͼADT

template <typename Tv> struct Vertex { //�������Ϊ���������δ�ϸ��װ��
   Tv data; int inDegree, outDegree; VStatus status; //���ݡ����������״̬
   int dTime, fTime; //ʱ���ǩ
   int parent; int priority; //�ڱ������еĸ��ڵ㡢���ȼ���
   Vertex ( Tv const& d = ( Tv ) 0 ) : //�����¶���
      data ( d ), inDegree ( 0 ), outDegree ( 0 ), status ( UNDISCOVERED ),
      dTime ( -1 ), fTime ( -1 ), parent ( -1 ), priority ( INT_MAX ) {} //�ݲ�����Ȩ�����
};

template <typename Te> struct Edge { //�߶���Ϊ���������δ�ϸ��װ��
   Te data; int weight; EType type; //���ݡ�Ȩ�ء�����
   Edge ( Te const& d, int w ) : data ( d ), weight ( w ), type ( UNDETERMINED ) {} //����
};

template <typename Tv, typename Te> //�������͡�������
class GraphMatrix : public Graph<Tv, Te> { //�������������ڽӾ�����ʽʵ�ֵ�ͼ
private:
   Vector< Vertex< Tv > > V; //���㼯��������
   Vector< Vector< Edge< Te > * > > E; //�߼����ڽӾ���
public:
   GraphMatrix() { n = e = 0; } //����
   ~GraphMatrix() { //����
      for ( int j = 0; j < n; j++ ) //���ж�̬������
         for ( int k = 0; k < n; k++ ) //�߼�¼
            delete E[j][k]; //�������
   }
// ����Ļ�����������ѯ��i�����㣨0 <= i < n��
   virtual Tv& vertex ( int i ) { return V[i].data; } //����
   virtual int inDegree ( int i ) { return V[i].inDegree; } //���
   virtual int outDegree ( int i ) { return V[i].outDegree; } //����
   virtual int firstNbr ( int i ) { return nextNbr ( i, n ); } //�׸��ڽӶ���
   virtual int nextNbr ( int i, int j ) //����ڶ���j����һ�ڽӶ��㣨�����ڽӱ�����Ч�ʣ�
   { while ( ( -1 < j ) && ( !exists ( i, --j ) ) ); return j; } //����������̽
   virtual VStatus& status ( int i ) { return V[i].status; } //״̬
   virtual int& dTime ( int i ) { return V[i].dTime; } //ʱ���ǩdTime
   virtual int& fTime ( int i ) { return V[i].fTime; } //ʱ���ǩfTime
   virtual int& parent ( int i ) { return V[i].parent; } //�ڱ������еĸ���
   virtual int& priority ( int i ) { return V[i].priority; } //�ڱ������е����ȼ���
// ����Ķ�̬����
   virtual int insert ( Tv const& vertex ) { //���붥�㣬���ر��
      for ( int j = 0; j < n; j++ ) E[j].insert ( NULL ); n++; //������Ԥ��һ��Ǳ�ڵĹ�����
      E.insert ( Vector<Edge<Te>*> ( n, n, ( Edge<Te>* ) NULL ) ); //�����¶����Ӧ�ı�����
      return V.insert ( Vertex<Tv> ( vertex ) ); //������������һ������
   }
   virtual Tv remove ( int i ) { //ɾ����i�����㼰������ߣ�0 <= i < n��
      for ( int j = 0; j < n; j++ ) //���г���
         if ( exists ( i, j ) ) { delete E[i][j]; V[j].inDegree--; } //����ɾ��
      E.remove ( i ); n--; //ɾ����i��
      Tv vBak = vertex ( i ); V.remove ( i ); //ɾ������i
      for ( int j = 0; j < n; j++ ) //�������
         if ( Edge<Te> * e = E[j].remove ( i ) ) { delete e; V[j].outDegree--; } //����ɾ��
      return vBak; //���ر�ɾ���������Ϣ
   }
// �ߵ�ȷ�ϲ���
   virtual bool exists ( int i, int j ) //��(i, j)�Ƿ����
   { return ( 0 <= i ) && ( i < n ) && ( 0 <= j ) && ( j < n ) && E[i][j] != NULL; }
// �ߵĻ�����������ѯ����i��j֮������ߣ�0 <= i, j < n��exists(i, j)��
   virtual EType & type ( int i, int j ) { return E[i][j]->type; } //��(i, j)������
   virtual Te& edge ( int i, int j ) { return E[i][j]->data; } //��(i, j)������
   virtual int& weight ( int i, int j ) { return E[i][j]->weight; } //��(i, j)��Ȩ��
// �ߵĶ�̬����
   virtual void insert ( Te const& edge, int w, int i, int j ) { //����Ȩ��Ϊw�ı�e = (i, j)
      if ( exists ( i, j ) ) return; //ȷ���ñ��в�����
      E[i][j] = new Edge<Te> ( edge, w ); //�����±�
      e++; V[i].outDegree++; V[j].inDegree++; //���±߼������������Ķ���
   }
   virtual Te remove ( int i, int j ) { //ɾ������i��j֮������ߣ�exists(i, j)��
      Te eBak = edge ( i, j ); delete E[i][j]; E[i][j] = NULL; //���ݺ�ɾ���߼�¼
      e--; V[i].outDegree--; V[j].inDegree--; //���±߼������������Ķ���
      return eBak; //���ر�ɾ���ߵ���Ϣ
   }
};