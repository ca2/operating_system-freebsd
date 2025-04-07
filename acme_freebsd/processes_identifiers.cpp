//
// Created by camilo on 2025-04-06 23:33 <3ThomasBorregaardSorensen!!
//

#include <stdio.h>
#include <stdlib.h>
#include <kvm.h>
#include <sys/param.h>
#include <sys/sysctl.h>
#include <sys/user.h>
#include <fcntl.h>
#include <nlist.h>
long long * freebsd_list_processes(int & c)
{


//#include <stdio.h>
//#include <stdlib.h>

    //void list_processes() {
    kvm_t *kd;
    char errbuf[BUFSIZ];
    struct kinfo_proc *procs;
    int count = 0;

    // Open kernel memory interface
    kd = kvm_open(NULL, "/dev/null", NULL, O_RDONLY, errbuf);
    if (kd == NULL) {
        fprintf(stderr, "kvm_open failed: %s\n", errbuf);
        return nullptr;
    }

    // Get list of all processes
    procs = kvm_getprocs(kd, KERN_PROC_ALL, 0, &count);
    if (procs == NULL) {
        fprintf(stderr, "kvm_getprocs failed: %s\n", kvm_geterr(kd));
        kvm_close(kd);
        return nullptr;
    }
    auto pll = (long long *)malloc(sizeof(long long) * count);
    // Print process IDs
    c = 0;
    for (int i = 0; i < count; i++) {
        //printf("PID: %d\n", procs[i].ki_pid);
        bool bFound = false;
        auto llItem =(long long)procs[i].ki_pid;
        for(int j = 0; j < c; j++)
        {

            if(pll[j] == llItem)
            {

                bFound = true;
                break;

            }

        }
        if(!bFound) {
            pll[c++] = llItem;
        }
    }

    // Clean up
    kvm_close(kd);
    //}
    return pll;
}