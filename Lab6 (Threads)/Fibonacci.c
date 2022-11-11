#include <stdio.h>
#include <pthread.h>

int n, arr[100], n1=0, n2=1;

void* fibonacci (void* param) {
        printf("Separate thread generating Fibonacci sequence\n");
        int nextTerm = n1 + n2;



       for(int i=2; i<=n; ++i) {
                arr[i] = nextTerm;
                n1 = n2;
                n2 = nextTerm;
                nextTerm = n1 + n2;
        }



       return arr;
}

int main() {
        printf("Main thread\n");
        printf("How many Fibonacci numbers to generate?\n");
        scanf("%d", &n);
        pthread_t thread;
        pthread_create(&thread, NULL, &fibonacci, NULL);
        pthread_join(thread, (void**)&arr);
        arr[0] = 0;
        arr[1] = 1;



       for (int i=0; i<n; i++)
                printf("%d ", arr[i]);



       printf("\n");
        return 0;
}