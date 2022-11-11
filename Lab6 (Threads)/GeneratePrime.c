#include <stdio.h>
#include <pthread.h>
int m,n;
void* PrimeGenerate(void* param){
        for(int i=m; i<=n; i++){
                int flag=1;
                for(int j=2; j<i/2; j++){
                        if(i%j==0){
                                flag=0;
                                break;
                        }
                }
                if(flag==1){
                        printf("%d\t", i);
                }
        }
        printf("\n");
}

int main(){
        printf("Enter the lower and upper limits: ");
        scanf("%d %d", &m, &n);
        printf("Main thread\n");
        pthread_t t;
        pthread_create(&t, NULL, &PrimeGenerate, NULL);
        pthread_join(t,0);
        return 0;
}