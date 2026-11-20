#include "tsp_device.h"

#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int read_text_file(const char *path, char *buffer, size_t capacity) {
    FILE *file;
    size_t length;

    if (capacity < 2) return 0;
    file = fopen(path, "r");
    if (file == NULL) return 0;

    length = fread(buffer, 1, capacity - 1, file);
    buffer[length] = '\0';
    fclose(file);

    while (length > 0 &&
           (buffer[length - 1] == '\n' || buffer[length - 1] == '\r' ||
            buffer[length - 1] == ' ' || buffer[length - 1] == '\t')) {
        buffer[--length] = '\0';
    }
    return length > 0;
}

static int should_skip_device(const char *name) {
    return strncmp(name, "loop", 4) == 0 ||
           strncmp(name, "ram", 3) == 0 ||
           strncmp(name, "zram", 4) == 0;
}

size_t tsp_list_devices(tsp_device_info *devices, size_t capacity) {
    DIR *directory;
    struct dirent *entry;
    size_t count = 0;

    if (devices == NULL || capacity == 0) return 0;

    directory = opendir("/sys/block");
    if (directory == NULL) return 0;

    while ((entry = readdir(directory)) != NULL && count < capacity) {
        char size_path[256];
        char removable_path[256];
        char value[64];
        unsigned long long sectors;
        char *end = NULL;
        tsp_device_info item;

        if (entry->d_name[0] == '.' || should_skip_device(entry->d_name))
            continue;

        if (snprintf(size_path, sizeof(size_path), "/sys/block/%s/size",
                     entry->d_name) >= (int)sizeof(size_path) ||
            snprintf(removable_path, sizeof(removable_path),
                     "/sys/block/%s/removable", entry->d_name) >=
                     (int)sizeof(removable_path)) {
            continue;
        }

        if (!read_text_file(size_path, value, sizeof(value))) continue;
        errno = 0;
        sectors = strtoull(value, &end, 10);
        if (errno != 0 || end == value || *end != '\0' ||
            sectors > UINT64_MAX / 512ULL) {
            continue;
        }

        memset(&item, 0, sizeof(item));
        if (snprintf(item.name, sizeof(item.name), "%s", entry->d_name) >=
                (int)sizeof(item.name) ||
            snprintf(item.device_path, sizeof(item.device_path), "/dev/%s",
                     entry->d_name) >= (int)sizeof(item.device_path)) {
            continue;
        }

        item.size_bytes = (uint64_t)sectors * 512ULL;
        item.removable = read_text_file(removable_path, value, sizeof(value))
                             ? (value[0] == '1')
                             : 0;
        devices[count++] = item;
    }

    closedir(directory);
    return count;
}
