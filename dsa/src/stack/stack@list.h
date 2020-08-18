/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "../List/List.h" //���б�Ϊ���࣬������ջģ����
template <typename T> class Stack: public List<T> { //���б����/ĩ����Ϊջ��/��
public: //size()��empty()�Լ��������Žӿڣ�����ֱ������
   void push ( T const& e ) { insertAsLast ( e ); } //��ջ����Ч�ڽ���Ԫ����Ϊ�б����Ԫ�ز���
   T pop() { return remove ( last() ); } //��ջ����Ч��ɾ���б����Ԫ��
   T& top() { return last()->data; } //ȡ����ֱ�ӷ����б����Ԫ��
};
