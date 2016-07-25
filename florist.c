/* Sample program illustrating input/output methods */
#include<stdio.h>
int f=0;
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)b - *(int*)a );
}
int main(){

//Helpers for input/output
   int i, N, K;
   int C[102];
   int x[102];
    int result=0;
    int result_1=0;
    int result_2=0;

   scanf("%d %d", &N, &K);
    
    for(int j=0;j<K;j++)
    {
        x[j]=0;
    }
   for(int i=0; i<N; i++){
      scanf("%d", &(C[i]));//costs
   }

    if(N<=K)
    {
        for(int i=0;i<N;i++)
            result_1+=C[i];   
        // result=result_1;
    }
    else
    {
    //qsort(C,N,sizeof(int),cmpfunc);//sort array C
    
	//printf("else");        
   
   for (int i = 0; i < N; ++i)

    {

        for (int j = i + 1; j < N; ++j)

        {

            if (C[i] < C[j])

            {

               int a =C[i];

               C[i] = C[j];

                C[j] = a;

            }

        }

    }



    int g=0;
    for(int f=0;f<N;f++)
    {
        if(f<K)
        {
        result_2=result_2+C[f];
	//printf("inside if %d %d\n",g%K,x[g]);
        x[g%K]=x[g]+1;
	g++;
	//printf("down %d %d\n",g,x[g-1]);
	}
g=g%K;
        if(f>=K)
        {
	    // printf("second %d %d\n",g%K,x[g]);
            result_2+=(x[g]+1)*C[f];
            x[g%K]=x[g%K]+1;
	g++;
            
        }
    }
    
     
}    
   if(N<=K)
       result=result_1;
    else
       result=result_2;
  printf("%d\n", result);

}

