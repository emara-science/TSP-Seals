#include <stdio.h>
#include <inttypes.h>
#include "tsp_core.h"
#include "tsp_device.h"

#define TSP_MAX_DEVICES 64

static void print_size(uint64_t bytes) {
    static const char *units[] = {"B", "KB", "MB", "GB", "TB"};
    double value = (double)bytes;
    size_t unit = 0;

    while (value >= 1024.0 && unit < 4) {
        value /= 1024.0;
        ++unit;
    }
    printf("%.2f %s", value, units[unit]);
}

int main(void) {
    tsp_device_info devices[TSP_MAX_DEVICES];
    size_t count;
    size_t i;

    puts("================================");
    puts(tsp_product_name());
    puts(TSP_PRODUCT_TAGLINE);
    puts("Read-only storage diagnostics");
    puts("================================");
    printf("Core version: %s\n", tsp_core_version());
    puts("Safety mode: READ ONLY");
    puts("");

    count = tsp_list_devices(devices, TSP_MAX_DEVICES);
    if (count == 0) {
        puts("No supported storage devices were reported.");
        puts("Device discovery is currently implemented on Linux only.");
        return 0;
    }

    printf("Detected whole-disk devices: %zu\n\n", count);
    for (i = 0; i < count; ++i) {
        printf("%zu. %s (%s)\n", i + 1, devices[i].name,
               devices[i].device_path);
        printf("   Capacity: ");
        print_size(devices[i].size_bytes);
        printf("\n   Removable flag: %s\n\n",
               devices[i].removable ? "yes" : "no");
    }

    puts("No disks were modified. USB writing is NOT IMPLEMENTED.");
    return 0;
}
