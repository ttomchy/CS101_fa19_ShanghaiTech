/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

/******************************************************************************************
 * Test of Graph
 ******************************************************************************************/
#include "Graph_test.h"

/******************************************************************************************
 * ������v�����㡢e���߹��ɵ����ͼ
 ******************************************************************************************/
template <typename Tv, typename Te> //�������͡�������
void randomGraph ( GraphMatrix<Tv, Te> & g, int n, int e ) { //assert: 0 < e(e-1) <= v
   while ( ( g.n < n ) || ( g.e < e ) ) { //�������
      if ( g.n < n ) { //����
         if ( dice ( 100 ) < 65 ) { //65%���ʲ��붥��
            Tv vertex = ( Tv ) ( 'A' + dice ( 26 ) );      /*DSA*/printf ( "Inserting vertex" ); print ( vertex ); printf ( " ..." );
            g.insert ( vertex );               /*DSA*/printf ( "done\n" );
         } else { //35%����ɾ������
            if ( 1 > g.n ) continue;
            int i = dice ( g.n );       /*DSA*/printf ( "Removing vertex %d ...", i );
            Tv v = g.remove ( i );        /*DSA*/printf ( "done with" ); print ( v ); printf ( "\n" );
         }
         /*DSA*/print ( g );
      }
      if ( ( 1 < g.n ) && ( g.e < e ) ) { //��
         if ( dice ( 100 ) < 65 ) { //65%���ʲ����
            int i = dice ( g.n ), j = dice ( g.n ); Te e = dice ( ( Te ) 3 * n );
            /*DSA*/printf ( "Inserting edge (%d, %d) = ", i, j ); print ( e ); printf ( " ..." );
            if ( g.exists ( i, j ) ) {
               /*DSA*/printf ( "already exists\n" );
            } else {
               g.insert ( e, e, i, j );      /*DSA*/printf ( "done\n" );
            }
         } else { //35%����ɾ����
            int i = dice ( g.n ), j = dice ( g.n );
            /*DSA*/printf ( "Removing edge (%d, %d) ...", i, j );
            if ( g.exists ( i, j ) ) {
               Te e = g.remove ( i, j );  /*DSA*/printf ( "done with" ); print ( e ); printf ( "\n" );
            } else {
               /*DSA*/printf ( "not exists\n" );
            }
         }
         /*DSA*/print ( g );
      }
   }
   for ( int i = 0; i < n; i++ ) g.vertex ( i ) = 'A' + i;
   /*DSA*/print ( g );
}

/******************************************************************************************
 * �������У��ļ��ض����е���ͼ
 ******************************************************************************************/
void importGraph ( GraphMatrix<char, int> & g ) {
   int n; scanf ( "%d\n", &n ); /*DSA*/printf ( "%d vertices\n", n );
   for ( int i = 0; i < n; i++ ) { //����v������
      char vertex; scanf ( "%c", &vertex );  /*DSA*/printf ( "Inserting vertex" ); print ( vertex ); printf ( " ..." );
      g.insert ( vertex );                  /*DSA*/printf ( "done\n" ); print ( g );
   }
   for ( int i = 0; i < n; i++ )
      for ( int j = 0; j < n; j++ ) { //�����
         int edge; scanf ( "%d", &edge );
         if ( 0 > edge ) continue;             /*DSA*/printf ( "Inserting edge (%d, %d) = ", i, j ); print ( edge ); printf ( " ..." );
         g.insert ( edge, edge, i, j );        /*DSA*/printf ( "done\n" );
      }
}

/******************************************************************************************
 * ͼ�ṹ��ͳһ����
 ******************************************************************************************/
int main ( int argc, char* argv[] ) {
   if ( 2 > argc ) { printf ( "Usage: %s -random <n> <e> | -import <n> <e> < <path>\a\a\n", argv[0] ); return -1; }
   // -import < ..\..\_input\graph.prim.0009+0028.txt  ..\..\_output\Graph_Matrix\graph.prim.0009+0028.txt
   // -random 13 29 > ..\..\_output\Graph_Matrix\graph.random.0013+0029.001.txt
   // -random 57 219 > ..\..\_output\Graph_Matrix\graph.random.0057+0219.001.txt
   srand ( ( unsigned int ) time ( NULL ) );
   //srand( 7654321 );
   GraphMatrix<char, int> g;
   if ( !strcmp ( "-random", argv[1] ) )
      randomGraph<char, int> ( g, atoi ( argv[2] ), atoi ( argv[3] ) ); //�������ַ���ţ���Ϊ����Ȩ��
   else if ( !strcmp ( "-import", argv[1] ) )
      importGraph ( g ); //�������У��ļ��ض����е���ͼ
   else return -1;
   /*DSA*/printf ( "\n" ); print ( g );
   /*DSA*/printf ( "=== BFS\n" );
   g.bfs ( 0 ); /*DSA*/print ( g );
   /*DSA*/printf ( "=== BFS (PFS)\n" );
   g.pfs ( 0, BfsPU<char, int>() ); /*DSA*/print ( g );
   /*DSA*/printf ( "=== DFS\n" );
   g.dfs ( 0 ); /*DSA*/print ( g );
   /*DSA*/printf ( "=== DFS (PFS)\n" );
   g.pfs ( 0, DfsPU<char, int>() ); /*DSA*/print ( g );
   /*DSA*/printf ( "=== TopoSort\n" );
   Stack<char>* ts = g.tSort ( 0 ); /*DSA*/ print ( ts ); print ( g ); release ( ts );
   /*DSA*/printf ( "=== BCC\n" );
   g.bcc ( 0 ); /*DSA*/print ( g );
   /*DSA*/printf ( "=== Prim\n" );
   g.prim ( 0 ); /*DSA*/print ( g );
   /*DSA*/printf ( "=== Prim (PFS)\n" );
   g.pfs ( 0, PrimPU<char, int>() ); /*DSA*/print ( g );
   /*DSA*/printf ( "=== Dijkstra\n" );
   g.dijkstra ( 0 ); /*DSA*/print ( g );
   /*DSA*/printf ( "=== Dijkstra (PFS)\n" );
   g.pfs ( 0, DijkstraPU<char, int>() ); /*DSA*/print ( g );
   return 0;
}