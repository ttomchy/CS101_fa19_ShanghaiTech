/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/*
 * ��ģʽƥ�䣺KMP�㷨
 * ������λ��i > length(T) - length(P)����˵��ʧ��
 * ����iΪƥ��λ��
 */
import dsa.*;
import java.io.*;

public class PM_KMP {
   //////////////////////////////////////////////////////////////////////////
   // T: 0     1     .     .     .     i     i+1   .     .     .     i+k   .     .     n-1
   //    --------------------|-------------------|------------
   // P:                               j     j+1   .     .     .     j+k   .     .
   //                                  |-------------------|
   //////////////////////////////////////////////////////////////////////////
   public static int PM(String T, String P) {//KMP�㷨
      int[]    next = BuildNextImproved(P);//����next[]��
      int      i = 0;//�ı���ָ��
      int      j = 0;//ģʽ��ָ��
      while(j < P.length() && i < T.length()) { //������������Ƚ��ַ�
         ShowProgress(T, P, i - j, j);      ShowNextTable(next, i - j, P.length());  System.out.println();
         if (0 > j || T.charAt(i) == P.charAt(j)) { //��ƥ�䣬��P���Ƴ�����ࣨ���ʣ������������ܷ񽻻����򣿣�
            i++;  j++;//��ת����һ���ַ�
         } else//����
            j = next[j];//ģʽ�����ƣ�ע�⣺�ı������û��ˣ�
      }//while
      return(i - j);
   }

   protected static int[] BuildNext(String   P) {//����ģʽ��P��next[]��
      int[]    next = new int[P.length()];//next[]��
      int      j = 0;//��������ָ��
      int      t = next[0] = -1;//��ģʽ����ָ��
      while (j < P.length() - 1)
         if (0 > t || P.charAt(j) == P.charAt(t)) {//ƥ��
            j++;  t++;
            next[j] = t;//�˾���ԸĽ�...
         } else//ʧ��
            t = next[t];
      for (j = 0; j < P.length(); j++)  System.out.print("\t" + P.charAt(j)); System.out.print("\n");
      ShowNextTable(next, 0, P.length());
      return(next);
   }

   protected static int[] BuildNextImproved(String P) {//����ģʽ��P��next[]���Ľ��汾��
      int[]    next = new int[P.length()];;//next[]��
      int      j = 0;//��������ָ��
      int      t = next[0] = -1;//��ģʽ����ָ��
      while (j < P.length() - 1)
         if (0 > t || P.charAt(j) == P.charAt(t)) {//ƥ��
            j++;  t++;
            next[j] = (P.charAt(j) != P.charAt(t)) ? t : next[t];//ע��˾���δ�Ľ�֮ǰ������
         } else//ʧ��
            t = next[t];
      for (j = 0; j < P.length(); j++)  System.out.print("\t" + P.charAt(j)); System.out.print("\n");
      ShowNextTable(next, 0, P.length());
      return(next);
   }


   protected static void ShowNextTable(//��ʾnext[]������ʾ����
      int[] N,
      int      offset,
      int      length) {
      int      i;
      for (i = 0; i < offset; i++)   System.out.print("\t");
      for (i = 0; i < length; i++)   System.out.print("\t" + N[i]);  System.out.print("\n\n");
   }

   protected static void ShowProgress(//��̬��ʾƥ���չ
      String   T,//�ı���
      String   P,//ģʽ��
      int         i,//ģʽ��������ı�������ʼλ��
      int         j) { //ģʽ���ĵ�ǰ�ַ�
      int         t;
      System.out.println("-------------------------------------------");
      for (t = 0; t < T.length(); t++)  System.out.print("\t" + T.charAt(t)); System.out.print("\n");
      if (0 <= i + j) {
         for (t = 0; t < i + j; t++)  System.out.print("\t");
         System.out.print("\t|");
      }
      System.out.println();
      for (t = 0; t < i; t++) System.out.print("\t");
      for (t = 0; t < P.length(); t++)  System.out.print("\t" + P.charAt(t)); System.out.print("\n");
      System.out.println();
   }
}
