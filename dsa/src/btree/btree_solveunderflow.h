/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //�ؼ���ɾ�������ڵ����磬�����ڵ���ת��ϲ�����
void BTree<T>::solveUnderflow ( BTNodePosi(T) v ) {
   if ( ( _order + 1 ) / 2 <= v->child.size() ) return; //�ݹ������ǰ�ڵ㲢δ����
   BTNodePosi(T) p = v->parent;
   if ( !p ) { //�ݹ�����ѵ����ڵ㣬û�к��ӵ�����
      if ( !v->key.size() && v->child[0] ) {
         //��������Ϊ������v�Ѳ����ؼ��룬ȴ�У�Ψһ�ģ��ǿպ��ӣ���
         /*DSA*/printf ( "collapse\n" );
         _root = v->child[0]; _root->parent = NULL; //����ڵ�ɱ�����
         v->child[0] = NULL; release ( v ); //���������ö�������
      } //�����߶Ƚ���һ��
      return;
   }
   Rank r = 0; while ( p->child[r] != v ) r++;
   //ȷ��v��p�ĵ�r�����ӡ�����ʱv���ܲ����ؼ��룬�ʲ���ͨ���ؼ������
   //���⣬��ʵ���˺���ָ����е���֮��Ҳ��ֱ�ӵ���Vector::find()��λ
   /*DSA*/printf ( "\nrank = %d", r );
// ���1�������ֵܽ�ؼ���
   if ( 0 < r ) { //��v����p�ĵ�һ�����ӣ���
      BTNodePosi(T) ls = p->child[r - 1]; //���ֵܱش���
      if ( ( _order + 1 ) / 2 < ls->child.size() ) { //�����ֵ��㹻���֡�����
         /*DSA*/printf ( " ... case 1\n" );
         v->key.insert ( 0, p->key[r - 1] ); //p���һ���ؼ����v����Ϊ��С�ؼ��룩
         p->key[r - 1] = ls->key.remove ( ls->key.size() - 1 ); //ls�����ؼ���ת��p
         v->child.insert ( 0, ls->child.remove ( ls->child.size() - 1 ) );
         //ͬʱls�����Ҳຢ�ӹ��̸�v
         if ( v->child[0] ) v->child[0]->parent = v; //��Ϊv������ຢ��
         return; //���ˣ�ͨ����������ɵ�ǰ�㣨�Լ����в㣩�����紦��
      }
   } //���ˣ����ֵ�ҪôΪ�գ�Ҫô̫���ݡ�
// ���2�������ֵܽ�ؼ���
   if ( p->child.size() - 1 > r ) { //��v����p�����һ�����ӣ���
      BTNodePosi(T) rs = p->child[r + 1]; //���ֵܱش���
      if ( ( _order + 1 ) / 2 < rs->child.size() ) { //�����ֵ��㹻���֡�����
         /*DSA*/printf ( " ... case 2\n" );
         v->key.insert ( v->key.size(), p->key[r] ); //p���һ���ؼ����v����Ϊ���ؼ��룩
         p->key[r] = rs->key.remove ( 0 ); //ls����С�ؼ���ת��p
         v->child.insert ( v->child.size(), rs->child.remove ( 0 ) );
         //ͬʱrs������ຢ�ӹ��̸�v
         if ( v->child[v->child.size() - 1] ) //��Ϊv�����Ҳຢ��
            v->child[v->child.size() - 1]->parent = v;
         return; //���ˣ�ͨ����������ɵ�ǰ�㣨�Լ����в㣩�����紦��
      }
   } //���ˣ����ֵ�ҪôΪ�գ�Ҫô̫���ݡ�
// ���3�������ֵ�ҪôΪ�գ���������ͬʱ����Ҫô��̫���ݡ������ϲ�
   if ( 0 < r ) { //�����ֵܺϲ�
      /*DSA*/printf ( " ... case 3L\n" );
      BTNodePosi(T) ls = p->child[r - 1]; //���ֵܱش���
      ls->key.insert ( ls->key.size(), p->key.remove ( r - 1 ) ); p->child.remove ( r );
      //p�ĵ�r - 1���ؼ���ת��ls��v������p�ĵ�r������
      ls->child.insert ( ls->child.size(), v->child.remove ( 0 ) );
      if ( ls->child[ls->child.size() - 1] ) //v������ຢ�ӹ��̸�ls�����Ҳຢ��
         ls->child[ls->child.size() - 1]->parent = ls;
      while ( !v->key.empty() ) { //vʣ��Ĺؼ���ͺ��ӣ�����ת��ls
         ls->key.insert ( ls->key.size(), v->key.remove ( 0 ) );
         ls->child.insert ( ls->child.size(), v->child.remove ( 0 ) );
         if ( ls->child[ls->child.size() - 1] ) ls->child[ls->child.size() - 1]->parent = ls;
      }
      release ( v ); //�ͷ�v
   } else { //�����ֵܺϲ�
      /*DSA*/printf ( " ... case 3R\n" );
      BTNodePosi(T) rs = p->child[r + 1]; //���ֶȱش���
      rs->key.insert ( 0, p->key.remove ( r ) ); p->child.remove ( r );
      //p�ĵ�r���ؼ���ת��rs��v������p�ĵ�r������
      rs->child.insert ( 0, v->child.remove ( v->child.size() - 1 ) );
      if ( rs->child[0] ) rs->child[0]->parent = rs; //v������ຢ�ӹ��̸�ls�����Ҳຢ��
      while ( !v->key.empty() ) { //vʣ��Ĺؼ���ͺ��ӣ�����ת��rs
         rs->key.insert ( 0, v->key.remove ( v->key.size() - 1 ) );
         rs->child.insert ( 0, v->child.remove ( v->child.size() - 1 ) );
         if ( rs->child[0] ) rs->child[0]->parent = rs;
      }
      release ( v ); //�ͷ�v
   }
   solveUnderflow ( p ); //����һ�㣬���б�Ҫ��������ѡ�������ݹ�O(logn)��
   return;
}