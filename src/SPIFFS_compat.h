#ifndef _SPIFFS_COMPAT_
#define _SPIFFS_COMPAT_

#ifdef ESP32
#include <dirent.h>
#include <SPIFFS.h>

#include <esp_spiffs.h>

#define _FILE FILE *
typedef struct {
    DIR *dir;
    struct dirent *dp;
} _DIR;

void _initFS()
{
    esp_vfs_spiffs_conf_t conf = {
      .base_path = "/spiffs",
      .partition_label = NULL,
      .max_files = 5,
      .format_if_mount_failed = true
    };
    
    // Use settings defined above to initialize and mount SPIFFS filesystem.
    // Note: esp_vfs_spiffs_register is an all-in-one convenience function.
    esp_vfs_spiffs_register(&conf);


}
void _opendir(_DIR &dir, const char *path) {
    dir.dir = opendir(path);
}

bool _nextdir(_DIR &dir) {
    dir.dp = readdir(dir.dir);
    return (dir.dp != NULL);
}

String _dirname(_DIR &dir) {
    return String(dir.dp->d_name);
}

#else
#define _initFS()
#define _DIR Dir
#define _opendir(dh, path) dh = SPIFFS.openDir(path)
#define _nextdir(dh) dh.next()
#define _dirname(dh) dh.fileName()

#endif

#endif //_SPIFFS_COMPAT_
