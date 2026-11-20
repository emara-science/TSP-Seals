#include <stdio.h>
#include <string.h>
#include "tsp_core.h"

int main(void) {
    if (strcmp(tsp_product_name(), "TSP SEALS") != 0) {
        fputs("FAIL: product name mismatch\n", stderr);
        return 1;
    }
    if (strcmp(tsp_core_version(), "0.1.0") != 0) {
        fputs("FAIL: core version mismatch\n", stderr);
        return 1;
    }
    puts("PASS: core identity and version");
    return 0;
}
