
#include <sys/stat.h>
#include "boz/bozv_entry_internal_p.h"

int _bozv_entry_check_rootpath(void) {
    int ret=0;
    
    BOZVIDEO_ENTRY_LOCK_MUTEX(g_video_entry_main.mutex);
    
    if(g_video_entry_main.status&BOZV_ENTRY_ROOTPATH_OK)
        goto exit;
    
    ret=mkdir(g_video_entry_main.root_path, 0755);
    if(ret<0) {
        if(errno!=EEXIST)
            goto exit;
        else 
            ret=0;
    }
    
    g_video_entry_main.status |= BOZV_ENTRY_ROOTPATH_OK;
    
exit:
    BOZVIDEO_ENTRY_UNLOCK_MUTEX(g_video_entry_main.mutex);
    return (errno=(!ret?0:errno),ret);
}