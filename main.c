#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fib_recursive(int num){
    if(num==1){return 0;}
    if(num==2){return 1;}
    return fib_recursive(num-1)+fib_recursive(num-2);
}
int fibo[100];

int fib_TopDown(int num){
    if(fibo[num]!=-1){return fibo[num];}
    if(num<=1){return 0;}
    if(num==2){return 1;}
    fibo[num]=fib_TopDown(num-1)+fib_TopDown(num-2);
    return fibo[num];
}

int fib_BottomUp(int num){
    static int fibo[100];
    fibo[1]=0;
    fibo[2]=1;
    for(int j=3;j<=num;j++){
        fibo[j]=fibo[j-1]+fibo[j-2];
    }
    return fibo[num];
}
int main()
{
    for(int i=0;i<100;i++){
    fibo[i]=-1;
    }
    fibo[1]=0;
    fibo[2]=1;

    /*finding execution time of nth Fibonacci number with recursive approach*/
    clock_t t;
    t = clock();
    printf("47th fib number by recursive approach is %d\n",fib_recursive(47));;
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("fib_recursive(47) took %f seconds to execute \n", time_taken);

    /*finding execution time of nth Fibonacci number with TopDown approach*/
    clock_t t_td;
    t_td = clock();
    printf("47th fib number by TopDown approach is %d\n",fib_TopDown(47));;
    t_td = clock() - t_td;
    double time_taken_td = ((double)t_td)/CLOCKS_PER_SEC; // in seconds
    printf("fib_TopDown(47) took %f seconds to execute \n", time_taken_td);

    /*finding execution time of nth Fibonacci number with BottomUp approach*/
    clock_t t_bu;
    t_bu = clock();
    printf("47th fib number by BottomUp approach is %d\n",fib_BottomUp(47));;
    t_bu = clock() - t_bu;
    double time_taken_bu = ((double)t_td)/CLOCKS_PER_SEC; // in seconds
    printf("fib_BottomUp(47) took %f seconds to execute \n", time_taken_bu);

    /*finding Fibonacci numbers till nth position*/
   for(int i=1;i<=47;i++){
        printf("Fibonacci %d is ",i);
        printf("%d\n",fibo[i]);
    }
    return 0;
}
