/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

#pragma warning(disable : 4996 4800)
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include "../_share/release.h"

class Bitmap { //λͼBitmap�ࣺ�Կռ���Ϊ��������ʡ��ʼ��ʱ�䣨��������룬��֧��ɾ����
private:
   Rank* F; Rank N; //��ģΪN������F����¼[k]����ǵĴ��򣨼�����ջT[]�е��ȣ�
   Rank* T; Rank top; //����ΪN��ջT����¼����Ǹ�λ�ȵ�ջ���Լ�ջ��ָ��

protected:
   inline bool valid ( Rank r ) { return ( 0 <= r ) && ( r < top ); }
   inline bool erased ( Rank k ) //�ж�[k]�Ƿ�������ǹ����Һ����ֱ����
   { return valid ( F[k] ) && ! ( T[ F[k] ] + 1 + k ); } //����Լ����T[ F[k] ] = - 1 - k

public:
   Bitmap ( Rank n = 8 ) //��ָ������Ĭ�ϣ���ģ��������ͼ��Ϊ������ʱѡ�ý�С��Ĭ��ֵ��
   { N = n; F = new Rank[N]; T = new Rank[N]; top = 0; } //��O(1)ʱ������ʽ�س�ʼ��
   ~Bitmap() { delete [] F; delete [] T; } //����ʱ�ͷſռ�

// �ӿ�
   inline void set ( Rank k ) { //����
      if ( test ( k ) ) return; //�����Ѵ���ǵ�λ
      if ( !erased ( k ) ) F[k] = top++; //��ϵ���α�ǣ��򴴽���У�黷
      T[ F[k] ] = k; //��ϵ������Ǻ��������ָ�ԭУ�黷
   }
   inline void clear ( Rank k ) //ɾ��
   {  if ( test ( k ) ) T[ F[k] ] = - 1 - k;  } //���Բ�����ǵ�λ
   inline bool test ( Rank k ) //����
   {  return valid ( F[k] ) && ( k == T[ F[k] ] );  }
};
