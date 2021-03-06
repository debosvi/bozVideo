
#include <unistd.h>

#include "boz-video-entry.h"
#include "boz/bozv_entry_internal_p.h"

int bozv_entry_delete(const char* const name) {
    if(!name)
        return (errno=EFAULT,-1);
    
    if(_bozv_entry_check_rootpath()<0)
        return -1;
    
    chdir(g_video_entry_main.root_path);
    
    if(unlink(name)<0) {
        return -1;
    }

    return (errno=0,0);
}


