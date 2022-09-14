#include "hiredis.h"
#include <future>

int main(int argc, char **argv) {

    printf("sdshdr5  = %ld bytes\n", sizeof(struct sdshdr5));
    printf("sdshdr8  = %ld bytes\n", sizeof(struct sdshdr8));
    printf("sdshdr16 = %ld bytes\n", sizeof(struct sdshdr16));
    printf("sdshdr32 = %ld bytes\n", sizeof(struct sdshdr32));
    printf("sdshdr64 = %ld bytes\n", sizeof(struct sdshdr64));

    printf("Done\n");
    return 0;
}
