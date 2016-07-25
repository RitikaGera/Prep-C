#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n; 
    int steps=0;
    scanf("%d",&n);
    int *c = malloc(sizeof(int) * n);
    for(int c_i = 0; c_i < n;c_i++){
       scanf("%d",&c[c_i]);
    }
    for(int c_i = 0; c_i < n; ){
       if(c[c_i+2]==0)
            {
            c_i+=2;
            steps++;
	    printf("first %d",c_i);
		if(c_i==n-1)
			break;
            }
       else if(c[c_i+2]!=0&&c[c_i+1]==0)
            {
            c_i++;
            steps++;
	printf("\nsecond %d",c_i);
		if (c_i==n-1)
			break;
            }
	
    }
    printf("\n%d",steps);
    return 0;
}

