/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*
 * Ĭ���е���
 */

package dsa;

public class EqualityTesterDefault implements EqualityTester {
   public EqualityTesterDefault() {}
   public boolean isEqualTo(Object a, Object b)
   {  return (a.equals(b)); }//ʹ��Java�ṩ���е���
}