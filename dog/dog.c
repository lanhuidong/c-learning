#include <stdio.h>
#include <sys/statvfs.h>

int main(int argc, char *argv[])
{
    struct statvfs vfs;
    if(statvfs("/", &vfs) == 0)
    {
        unsigned long total_space = vfs.f_bsize * vfs.f_blocks;
        unsigned long free_space = vfs.f_bsize * vfs.f_bavail;
        printf("total disk space: %lu\n", total_space / 1024);
        printf("free disk space: %lu\n", free_space / 1024);

        FILE *fp;
	unsigned long total_mem;
        unsigned long free_mem;
	if((fp = fopen("/proc/meminfo", "r")) != NULL){
            fscanf(fp, "MemTotal: %lu kB\n", &total_mem);
            fscanf(fp, "MemFree: %lu kB\n", &free_mem);
	    printf("MemTotal: %lu kB\n", total_mem);
	    printf("MemFree: %lu kB\n", free_mem);
	}
	fclose(fp);
    }
}
