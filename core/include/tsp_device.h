#ifndef TSP_DEVICE_H
#define TSP_DEVICE_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define TSP_DEVICE_NAME_MAX 128
#define TSP_DEVICE_PATH_MAX 160

typedef struct tsp_device_info {
    char name[TSP_DEVICE_NAME_MAX];
    char device_path[TSP_DEVICE_PATH_MAX];
    uint64_t size_bytes;
    int removable;
} tsp_device_info;

/*
 * Enumerate whole-disk devices using read-only operating-system metadata.
 * Returns the number of entries written, up to capacity.
 * This API never opens a device for writing or changes its contents.
 * On currently unsupported host platforms, returns 0.
 */
size_t tsp_list_devices(tsp_device_info *devices, size_t capacity);

#ifdef __cplusplus
}
#endif

#endif
