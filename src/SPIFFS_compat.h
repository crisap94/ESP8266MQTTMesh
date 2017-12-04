#ifndef _SPIFFS_COMPAT_
#define _SPIFFS_COMPAT_

#ifdef ESP32
#include <dirent.h>
#include <SPIFFS.h>

typedef struct {
    DIR *dir;
    struct dirent *dp;
} _DIR;

void _opendir(_DIR &dir, const char *path) {
    dir.dir = opendir(path);
}

bool _nextdir(_DIR &dir) {
    dir.dp = readdir(dir.dir);
    return (dir.dp != NULL);
}

const char *_dirname(_DIR &dir) {
    return dir.dp->d_name;
}
#else
#define _DIR Dir
#define _opendir(dh, path) dh = SPIFFS.openDir(path)
#define _nextdir(dh) dh.next()
#define _dirname(dh) dh.fileName()


#endif

#endif //_SPIFFS_COMPAT_
