#include <stdio.h>
#include <stdlib.h>

int main()
{   
    int N = 0, count = 1, i,j;
    printf("nomer1 \n");
    scanf("%d",&N);
    int arr[N][N];
    
    for( i = 0; i < N; i++){
        for( j = 0; j < N; j++){
            arr[i][j] = count;
            count++;
            printf(" %d", arr[i][j]);
        }
        printf(" \n");
    }            
   
    printf("nomer2 \n");
    
    printf("vvedite razmer \n");
    scanf("%d",&N);
    
    int arr2[N], num;
    
    printf("zapolnite mass \n");
    for( i = 0; i < N; i++){
        scanf("%d", &num);
        arr2[i] = num;
    }
    
    for( i = 0; i < N; i++) 
        printf(" %d", arr2[i]);
        
    printf(" \n");
        
    for( i = N - 1; i >= 0; i--) 
        printf(" %d", arr2[i]);
        
    printf("\n nomer3\n");
    
    printf("vvedite razmer \n");
    scanf("%d",&N);
    
    int arr3[N][N], j2 = N-1;
    j = 0;
    
    for( i = 0; i < N; i++)
        for( j = 0; j < N; j++)
            arr3[i][j] = 0;
     
    for( i = 0; i < N; i++){
        for(j = N - 1; j >= j2; j--){
            arr3[i][j] = 1;
            
        }
        j2--;
    }
    
    for( i = 0; i < N; i++){
        for( j = 0; j < N; j++){
            printf(" %d", arr3[i][j]);
        }
        printf(" \n");
    }   
    
    printf("\n nomer4\n");
    printf("vvedite razmer \n");
    scanf("%d",&N);
    
    int arr4[N][N];
    
    for( i = 0; i < N; i++){
        for( j = 0; j < N; j++){
            arr4[i][j] = 0;
            printf(" %d", arr4[i][j]);
        }
        printf(" \n");
    }   
    
    int North = 0, S = N - 1, W = 0, E = N -1;
    count = 0;
    
    while (North <= S && W <= E){
        printf(" \n");
        printf("N= %d S= %d W= %d E= %d\n", North,S,W,E);
        
         for ( i = W; i <= E; i++) {
            arr4[North][i] = count++;
        }
        North++;

        for ( i = North; i <= S; i++) {
            arr4[i][E] = count++;
        }
        E--;

        if (North <= S) {
            for ( i = E; i >= W; i--) {
                arr4[S][i] = count++;
            }
            S--;
        }

        if (W <= E) {
            for ( i = S; i >= North; i--) {
                arr4[i][W] = count++;
            }
            W++;
        }
    }
        
    for( i = 0; i < N; i++){
        for( j = 0; j < N; j++){
            printf(" %d", arr4[i][j]);
        }
        printf(" \n");
    }   
    
        
    return 0;
}
