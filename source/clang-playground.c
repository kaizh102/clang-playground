#include <stdio.h>
#include <stdbool.h>
#include "lib.h"

int main(void) {
    printf("externally defined variable a = %d\n", a);
    bool lf = true;
    bool ri = true;
    printf("lf = %d\n", lf);
    printf("ri = %d\n", ri);
    printf("lf+ri = %d\n", lf+ri);
    printf("lf?1:0 = %d\n", (lf?1:0));
    printf("lf+ri+(lf?1:0) = %d\n", lf+ri+(lf?1:0));
    printf("lf+ri+lf?1:0 = %d\n", lf+ri+lf?1:0);
    return 0;
}