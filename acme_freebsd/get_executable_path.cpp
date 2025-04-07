//
// Created by camilo on 2025-04-06 23:58 <3ThomasBorregaardSorensen!!
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sysctl.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

int get_executable_path(long long llPid, char *path, size_t path_len) {
    int mib[4];
    size_t len = path_len;
pid_t pid =(pid_t) llPid;

    mib[0] = CTL_KERN;
    mib[1] = KERN_PROC;
    mib[2] = KERN_PROC_PATHNAME;
    mib[3] = pid;

    if (sysctl(mib, 4, path, &len, NULL, 0) == -1) {
        perror("sysctl failed at get_executable_path");
        return -1;
    }

    return 0;
}