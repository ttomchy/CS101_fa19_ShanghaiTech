/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> bool RedBlack<T>::remove ( const T& e ) { //�Ӻ������ɾ���ؼ���e
   BinNodePosi(T) & x = search ( e ); if ( !x ) return false; //ȷ��Ŀ����ڣ�����_hot�����ã�
   BinNodePosi(T) r = removeAt ( x, _hot ); if ( ! ( --_size ) ) return true; //ʵʩɾ��
// assert: _hotĳһ���Ӹձ�ɾ�����ұ�r��ָ�ڵ㣨������NULL�����档���¼���Ƿ�ʧ�⣬������Ҫ����
   if ( ! _hot ) //���ձ�ɾ�����Ǹ��ڵ㣬�����úڣ������ºڸ߶�
      { _root->color = RB_BLACK; updateHeight ( _root ); return true; }
// assert: ���£�ԭx����r���طǸ���_hot�طǿ�
   if ( BlackHeightUpdated ( *_hot ) ) return true; //���������ȵĺ������Ȼƽ�⣬���������
   if ( IsRed ( r ) ) //������rΪ�죬��ֻ������ת��
      { r->color = RB_BLACK; r->height++; return true; }
// assert: ���£�ԭx����r����Ϊ��ɫ
   //*DSA*/printBinTree(_hot, 0, 0);
   solveDoubleBlack ( r ); return true; //��˫�ڵ����󷵻�
} //��Ŀ��ڵ�����ұ�ɾ��������true�����򷵻�false
