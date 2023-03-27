#include<stdio.h> 
#include<time.h> 
#include<stdlib.h> 
int sumPow(int A[], int n);
long exponent(int base, int power); 
int sumPown2(int A[], int n); 
int main(void){
  
   // srand(time(NULL)); 
/*for(int i = 0; i <10;i++){
   // A[i]=rand()%20+1;
   A[i]=i;
}*/
int A[] = {1,2,3,4,5}; 
size_t n = sizeof(A)/sizeof(A[5]);
int sum1 = sumPow(A,n); 
printf("\t:\t%d\n\n",sum1); 


int sum2 =sumPown2(A,n); 
printf("\t:\t%d\n\n",sum2); 
int exp = exponent(2,3); 
printf("\n%d\n",exp); 
}

long exponent(int base, int power)
{
    // Initialize result to 1
    int result  = 1;
 
    // Multiply x for n times
    for (int i = 0; i < power; i++) {
        result *= base;
    }
 
    return result;
}
 
int sumPown2(int A[], int n){      //O(n2)            
    int sum,x;
    printf("define a constant:\t"); 
    scanf("%d",&x);
    for(int i = 0; i<n;i++){                        
        sum+=A[i] *exponent(x, i);                       
    }                                              
    return sum; 
}
int sumPow(int A[], int n){  //O(n)
    int sum, x; 
    printf("define a constant:\t"); 
    scanf("%d",&x);
    for(int i = 1; i <n; i++){
        sum = sum + (A[i]* A[i+1]);  
    }
    return sum; 
}

// 