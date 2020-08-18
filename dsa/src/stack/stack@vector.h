/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "../Vector/Vector.h" //������Ϊ���࣬������ջģ����
template <typename T> class Stack: public Vector<T> { //����������/ĩ����Ϊջ��/��
public: //size()��empty()�Լ��������Žӿڣ�����ֱ������
   void push ( T const& e ) { insert ( size(), e ); } //��ջ����Ч�ڽ���Ԫ����Ϊ������ĩԪ�ز���
   T pop() { return remove ( size() - 1 ); } //��ջ����Ч��ɾ��������ĩԪ��
   T& top() { return ( *this ) [size() - 1]; } //ȡ����ֱ�ӷ���������ĩԪ��
};
