#include "tsp_device.h"

/* Platform-specific read-only enumeration is not implemented on this host yet. */
size_t tsp_list_devices(tsp_device_info *devices, size_t capacity) {
    (void)devices;
    (void)capacity;
    return 0;
}
