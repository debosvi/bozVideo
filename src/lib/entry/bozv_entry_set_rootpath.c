
#include "boz-video-entry.h"
#include "boz/bozv_entry_internal_p.h"

int bozv_entry_set_rootpath(const char* const path) {
    if(!path)
        return(errno=EFAULT,-1);
    
    g_video_entry_main.root_path = path;
    return (errno=0,0);
}
