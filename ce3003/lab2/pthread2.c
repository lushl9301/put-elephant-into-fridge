#include <stdio.h>
#include <pthread.h>

int g_val = 0;

void* inc_gv() {
    int i, j;
    for (i = 0; i < 10; i++) {
        g_val++;
        for (j = 0; j < 5000000; j++);
        printf(" %d", g_val);
        fflush(stdout);
    }
}
int main() {
    pthread_t TA, TB;
    int TAret, TBret;
    TAret = pthread_create(&TA, NULL, inc_gv, (void* ) NULL);
    TBret = pthread_create(&TB, NULL, inc_gv, (void* ) NULL);
    
    pthread_join(TA, NULL);
    pthread_join(TB, NULL);
    printf("\nTA & TB return: %d, %d\n",TAret, TBret);
}


