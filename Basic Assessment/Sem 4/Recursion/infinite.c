#include <stdio.h>
#include <time.h>

void infinite(int i, int limit){
    if(i > limit)
        return;
    printf("%d ", i);
    return infinite(i + 1, limit);
}

int main(){
    clock_t start, end;
    double total;
    printf("Enter the limit: ");
    int limit;
    scanf("%d", &limit);
    start = clock();
    infinite(0, limit);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Total time : %lf\n", total);

    return 0;
}