/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "../Dictionary/Dictionary.h" //����ʵ�ADT
#include "../Bitmap/Bitmap.h" //����λͼ

template <typename K, typename V> //key��value
class Hashtable : public Dictionary<K, V> { //����Dictionary�ӿڵ�Hashtableģ����
   /*DSA*/friend class UniPrint;
private:
   Entry<K, V>** ht; //Ͱ���飬��Ŵ���ָ��
   int M; //Ͱ��������
   int N; //��������
   Bitmap* lazyRemoval; //����ɾ�����
#define lazilyRemoved(x)  (lazyRemoval->test(x))
#define markAsRemoved(x)  (lazyRemoval->set(x))
protected:
   int probe4Hit ( const K& k ); //�عؼ���k��Ӧ�Ĳ��������ҵ�����ƥ���Ͱ
   int probe4Free ( const K& k ); //�عؼ���k��Ӧ�Ĳ��������ҵ��׸����ÿ�Ͱ
   void rehash(); //��ɢ���㷨������Ͱ���飬��֤װ�������ھ���������
public:
   Hashtable ( int c = 5 ); //����һ��������С��c��ɢ�б�Ϊ������ʱѡ�ý�С��Ĭ��ֵ��
   ~Hashtable(); //�ͷ�Ͱ���鼰���и����ǿգ�Ԫ����ָ��Ĵ���
   int size() const { return N; } // ��ǰ�Ĵ�����Ŀ
   bool put ( K, V ); //���루��ֹ��ͬ�������ʿ���ʧ�ܣ�
   V* get ( K k ); //��ȡ
   bool remove ( K k ); //ɾ��
};

#include "Hashtable_implementation.h"
