#include <stdio.h>
#include <sys/statvfs.h>

int main(int argc, char *argv[])
{
    struct statvfs vfs;
    if(statvfs("/", &vfs) == 0)
    {
        unsigned long total_space = vfs.f_bsize * vfs.f_blocks;
        unsigned long free_space = vfs.f_bsize * vfs.f_bavail;
        printf("total disk space: %lu\n", total_space / 1024 / 1024);
        printf("free disk space: %lu\n", free_space / 1024 / 1024);
    }
}
