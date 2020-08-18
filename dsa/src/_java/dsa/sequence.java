/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*
 * ���нӿ�
 */

package dsa;

public interface Sequence extends Vector, List {
   //��0 <= r < getSize()���򷵻���Ϊr��Ԫ�����ڵ�λ�ã����򣬱���
   public Position rank2Pos(int r)
   throws ExceptionBoundaryViolation;

   //��p�������еĺϷ�λ�ã��򷵻ش����p����Ԫ�ص��ȣ����򣬱���
   public int pos2Rank(Position p)
   throws ExceptionPositionInvalid;
}