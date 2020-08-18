/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

#include <assert.h>
#include "../_share/util.h"
#include "../UniPrint/print.h"

typedef int Rank; //��
#define DEFAULT_CAPACITY  3 //Ĭ�ϵĳ�ʼ������ʵ��Ӧ���п�����Ϊ����

template <typename T> class CursorList { //�α�ʽ�б�
protected:
   Rank _size; int _capacity; //��ģ������
   Rank* _link; T* _elem; //�α�ָ�롢������
   Rank _data, _free; //��������Ϳ�����������
public:
   CursorList ( int c = DEFAULT_CAPACITY ) { //����Ϊc
      _link = new Rank[_capacity = c]; //�α�ָ������
      _elem = new T[_capacity = c]; memset ( _elem, 0, c * sizeof ( T ) ); //��������
      _data = -1; _size = 0; //���������ʼΪ��
      _free = 0; //�������������е�Ԫ���δ��Ӷ���
      for ( Rank i = 0; i < c - 1; i++ ) _link[i] = i + 1;
      _link[c - 1] = -1;
   }
   ~CursorList() { delete [] _link; delete [] _elem; } //�ͷ��ڲ��ռ�
   Rank size() const { return _size; } //��ģ
   bool empty() const { return !_size; } //�п�
   Rank find ( T const& e ) const { //����
      Rank i = _data; //����������������
      while ( ( 0 <= i ) && ( e != _elem[i] ) ) i = _link[i]; //���αȶ�
      return i;
   }
   Rank insert ( T const& e ) { //����Ԫ��
      assert ( 0 <= _free );
      Rank k = _free; _free = _link[k]; _elem[k] = e;
      _link[k] = _data; _data = k;
      _size++; return k;
   }
   Rank remove ( Rank k ) { //ɾ����Ϊk��Ԫ��
      assert ( 0 <= k ); //��ǰ�����Ҳ�ȷ��k�Ϸ�
      if ( _data == k ) //��[k]Ϊ�׽ڵ�
         _data = _link[k];
      else { //����
         Rank i = _data; while ( k != _link[i] ) i = _link[i];
         _link[i] = _link[k];
      }
      _link[k] = _free; _free = k; _elem[k] = 0;
      _size--; return k;
   }
   void print() {
      printf ( "size = %d\t:\t", _size );
      for ( Rank i = _data; 0 <= i; i = _link[i] )
         UniPrint::p ( _elem[i] );
      printf ( "\n" );
      printf ( "\t" ); for ( Rank i = 0; i < _capacity; i++ ) UniPrint::p ( i ); printf ( "\n" );
      printf ( "%d\t", _free ); for ( Rank i = 0; i < _capacity; i++ ) UniPrint::p ( _link[i] ); printf ( "\n" );
      printf ( "%d\t", _data ); for ( Rank i = 0; i < _capacity; i++ ) UniPrint::p ( _elem[i] ); printf ( "\n" );
      printf ( "\n\n" );
   }
};

#include "cursor_list_implementation.h"