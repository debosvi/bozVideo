
#include <unistd.h>

#include "boz-video-entry.h"
#include "boz/bozv_entry_internal_p.h"

int bozv_entry_delete(const char* const name) {
    stralloc path = stralloc_zero ;
    
    if(!name)
        return(errno=EFAULT,-1);
    
    if(_bozv_entry_check_rootpath()<0)
        return -1;
    
    stralloc_catb(&path, g_video_entry_main.root_path, strlen(g_video_entry_main.root_path));
    stralloc_append(&path, '/');
    stralloc_catb(&path, name, strlen(name));
    
    if(unlink(path.s)<0) {
        return -1;
    }

    return (errno=0,0);
}


