
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

#include "boz-video-entry.h"
#include "boz/bozv_entry_internal_p.h"

static const char* bozv_entry_tmpl = "bozvXXXXXX";

int bozv_entry_new(char** const name) {
    char *newname=NULL;
    int fd=-1;
    
    if(!name)
        return (errno=EFAULT,-1);
    
    if(_bozv_entry_check_rootpath()<0)
        return -1;
    
    chdir(g_video_entry_main.root_path);
    newname = strdup(bozv_entry_tmpl);
    fd=mkstemp(newname);
    if(fd<0) {
        free(newname);
        return -1;
    }

    close(fd);
    unlink(newname);
    mkdir(newname, 0775);
    
    (*name) = newname;
    return (errno=0,0);
}


