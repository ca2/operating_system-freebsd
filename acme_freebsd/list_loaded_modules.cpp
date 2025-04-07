//
// Created by camilo on 2025-04-07 00:07 <3ThomasBorregaardSorensen!!
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/queue.h>    // Required for STAILQ_ENTRY and related macros
#include <sys/types.h>
#include <sys/user.h>
#include <libprocstat.h>
#include <sys/param.h>
#include <sys/sysctl.h>
#include <sys/user.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

char ** list_loaded_modules(int & c, long long llPid) {
    struct procstat *ps;
    struct kinfo_proc *kip;
    struct kinfo_vmentry *vmmap;
    unsigned int count, vmmap_count;
    pid_t pid = (pid_t) llPid;
    c = 0;

    ps = procstat_open_sysctl();
    if (ps == NULL) {
        perror("procstat_open_sysctl");
        return nullptr;
    }

    kip = procstat_getprocs(ps, KERN_PROC_PID, pid, &count);
    if (kip == NULL || count != 1) {
        fprintf(stderr, "Could not get process info for PID %d\n", pid);
        procstat_close(ps);
        return nullptr;
    }

    vmmap = procstat_getvmmap(ps, &kip[0], &vmmap_count);
    if (vmmap == NULL) {
        fprintf(stderr, "Could not get vmmap for PID %d\n", pid);
        procstat_freeprocs(ps, kip);
        procstat_close(ps);
        return nullptr;
    }

    auto pp =(char **) malloc(sizeof(char*)*vmmap_count);
    printf("Loaded modules for PID %d:\n", pid);
    for (unsigned int i = 0; i < vmmap_count; i++) {
        if (vmmap[i].kve_path[0] != '\0') {
            //printf("  %s\n", vmmap[i].kve_path);
            bool bFound = false;
            for(unsigned int j = 0; j < c; j++)
            {
                if(!strcmp(pp[j], vmmap[i].kve_path))
                {

                    bFound = true;
                    break;

                }

            }
            if(!bFound) {
                pp[c++] = strdup(vmmap[i].kve_path);
            }
        }
    }

    procstat_freevmmap(ps, vmmap);
    procstat_freeprocs(ps, kip);
    procstat_close(ps);

    return pp;
}