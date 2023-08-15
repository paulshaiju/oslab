//PAGE REPLACEMENT ALGORITHM - FIFO
#include<stdio.h> 
void main() {
 int i, j, k, f, pf=0,ph=0, count=0, rs[25], m[10], n; 
 printf("\n Enter the length of reference string -- "); 
 scanf("%d",&n); printf("\n Enter the reference string -- "); 
 for(i=0;i<n;i++) scanf("%d",&rs[i]); 
 printf("\n Enter no. of frames -- "); 
 scanf("%d",&f); 
 for(i=0;i<f;i++) m[i]=-1;
 printf("\n The Page Replacement Process is -- \n");
 
 for(i=0;i<n;i++) 
    { 
         for(k=0;k<f;k++) 
         { 
             if(m[k]==rs[i]) 
             break; 
         } 
         if(k==f) 
         { 
             m[count++]=rs[i];
             pf++; 
         } 
         if(k!=f) 
         { 
             ph++; 
         }
         for(j=0;j<f;j++)
         printf("\t%d",m[j]); 
         if(k!=f) printf("\tPh No. %d",ph);
         if(k==f) 
         printf("\tPF No. %d",pf); 
         printf("\n"); 
         if(count==f) count=0; 
    } 
 printf("\n The number of Page Faults using FIFO are %d",pf);
 printf("\n The number of Page Hits using FIFO are %d",n-pf);
}

/*OUTPUT
 Enter the length of reference string -- 12

 Enter the reference string -- 2 3 2 1 5 2 4 5 3 2 5 2

 Enter no. of frames -- 3

 The Page Replacement Process is -- 
        2       -1      -1      PF No. 1
        2       3       -1      PF No. 2
        2       3       -1      Ph No. 1
        2       3       1       PF No. 3
        5       3       1       PF No. 4
        5       2       1       PF No. 5
        5       2       4       PF No. 6
        5       2       4       Ph No. 2
        3       2       4       PF No. 7
        3       2       4       Ph No. 3
        3       5       4       PF No. 8
        3       5       2       PF No. 9

 The number of Page Faults using FIFO are 9
 The number of Page Hits using FIFO are 3 */