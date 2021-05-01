#include <stdio.h>

char compare(int x , int y)
        {

            if(x<y)
                return('<');
                else
                     if(x>y)
                return('>');

            else
                return('=');
        }



void main() {





   int m, n, i, j, l, k,p,q;
   int size1 = 0;
   int size2 = 0;
   printf("Enter the row and columns of the first matrix:\n");
   scanf("%d %d", &m, &n);
   int a[m][n];
   printf("Enter the elements of the matrix:\n");
   for(i = 0; i<m; i++){
    for(j = 0; j<n; j++){
        printf("a[%d][%d] = ", i, j);
        scanf("%d", &a[i][j]);
    }
   }
   for(i = 0; i<m; i++){
    for(j = 0; j<n; j++){
       if(a[i][j] != 0)
        size1++;
    }
   }
   printf("%d\n", size1);
   int m1[size1+1][3], s = 1;
   m1[0][0] = m;
   m1[0][1]= n;
   m1[0][2] = size1;
   for(i = 0; i<m; i++){
        for(j = 0; j<n; j++){
            if(a[i][j]!=0){
                m1[s][0] = i;
                m1[s][1] = j;
                m1[s][2] = a[i][j];
                s++;
            }
        }
   }
   printf("The first sparse matrix is:\n");
   for(i = 0; i<size1+1; i++){
        for(j = 0; j<3; j++){
                printf("%d\t", m1[i][j]);
        }
        printf("\n");
   }










 int size3 = 0;
   int size4 = 0;
   printf("Enter the row and columns of the second matrix:\n");
   scanf("%d %d", &p, &q);
   int b[p][q];
   printf("Enter the elements of the matrix:\n");
   for(i = 0; i<p; i++){
    for(j = 0; j<q; j++){
        printf("b[%d][%d] = ", i, j);
        scanf("%d", &b[i][j]);
    }
   }
   for(i = 0; i<p; i++){
    for(j = 0; j<q; j++){
       if(b[i][j] != 0)
        size3++;
    }
   }
   printf("%d\n", size3);
   int m2[size3+1][3], r = 1;
   m2[0][0] = p;
   m2[0][1]= q;
   m2[0][2] = size3;
   for(i = 0; i<p; i++){
        for(j = 0; j<q; j++){
            if(b[i][j]!=0){
                m2[r][0] = i;
                m2[r][1] = j;
                m2[r][2] = b[i][j];
                r++;
            }
        }
   }
   printf("The second sparse matrix is:\n");
   for(i = 0; i<size3+1; i++){
        for(j = 0; j<3; j++){
                printf("%d\t", m2[i][j]);
        }
        printf("\n");
   }
 add(m1,m2);
}


















        void add(int m1[][3], int m2[][3] )
        {
            int i=1,j=1,k=1, t1, t2;
            int m3[100][3];
            if(m1[0][0]!= m2[0][0] || m1[0][1]!= m2[0][1])
            exit(1);
            m3[0][0]= m1[0][0];
            m3[0][1]= m1[0][1];

            t1= m1[0][2];
            t2= m2[0][2];

            while(i<=t1 && j<= t2)
            {
                switch(compare(m1[i][0],m2[j][0]))
                       {
                       case '=' :
                        switch(compare(m1[i][1], m2[j][1]))
                       {
                       case'=':
                        m3[k][0] = m1[i][0];
                         m3[k][1] = m1[i][1];
                          m3[k][2] = m1[i][2]+ m2[j][2];
                          k++;
                           i++;
                            j++;
                          break;

                       case '<' :
                            m3[k][0] = m1[i][0];
                             m3[k][1] = m1[i][1];
                              m3[k][2] = m1[i][2];
                              k++;
                              i++;
                              break;

                       case '>' :
                         m3[k][0] = m1[j][0];
                          m3[k][1] = m1[j][1];
                           m3[k][1] = m1[j][2];
                           break;

                       }

                       case '<':
                         m3[k][0] = m1[i][0];
                          m3[k][1] = m1[i][1];
                           m3[k][2] = m1[i][2];
                           k++;
                           i++;
                           break;
                       case '>' :
                       m3[k][0]= m2[j][0];
                        m3[k][1]= m2[j][1];
                         m3[k][2]= m2[j][2];
                         k++;
                         j++;
                         break;
            }
        }

        while(i <=t1)
        {
            m3[k][0] = m1[i][0];
            m3[k][1] = m1[i][1];
            m3[k][2] = m1[i][2];
            k++;
            i++;
        }

        while(j<= t2)
        {
            m3[k][0]= m2[j][0];
            m3[k][1]= m2[j][1];
            m3[k][2]= m2[j][2];
            k++;
            j++;
        }
        m3[0][2]= k-1;

printf("the added sparse matrix is \n");

         for(int e = 0; e<k-1; e++)
    {
        for(int f = 0; f<3; f++)
        {
            printf("%d\t", m3[e][f]);
        }
        printf("\n");
    }

        }





















