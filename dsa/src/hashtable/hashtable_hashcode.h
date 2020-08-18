/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

static size_t hashCode ( char c ) { return ( size_t ) c; } //�ַ�
static size_t hashCode ( int k ) { return ( size_t ) k; } //�����Լ���������
static size_t hashCode ( long long i ) { return ( size_t ) ( ( i >> 32 ) + ( int ) i ); }
static size_t hashCode ( char s[] ) { //�����ַ�����ѭ����λɢ���루cyclic shift hash code��
   int h = 0; //ɢ����
   for ( size_t n = strlen ( s ), i = 0; i < n; i++ ) //�������ң��������ÿһ�ַ�
      { h = ( h << 5 ) | ( h >> 27 ); h += ( int ) s[i]; } //ɢ����ѭ������5λ�����ۼӵ�ǰ�ַ�
   return ( size_t ) h; //������õ�ɢ���룬ʵ���Ͽ����Ϊ���Ƶġ�����ʽɢ���롱
} //����Ӣ�ﵥ�ʣ�"ѭ������5λ"��ʵ��ͳ�Ƶó������ֵ
