/**
 * \file bozv_close.c
 * \addtogroup BOZ_VIDEO
 * @{
 */

#include "boz/bozv_internal_p.h"

int bozv_handle_close(bozv_handle_t *vh) {
    int ret=-1;
    
    if(!vh || !(*vh))
        return (errno=EINVAL,-1);
    
    if((*vh)->magic!=g_video_main.magic)
        return (errno=EINVAL,-1);
    
    BOZVIDEO_LOCK_MUTEX(g_video_main.mutex);
    ret=gensetdyn_delete (&g_video_main.handle, (*vh)->idx);
    
    if(!ret) {
        BOZVIDEO_UNLOCK_MUTEX(g_video_main.mutex);
        return (errno=EIO,-1);
    }
    
    (*vh)->idx = -1;
    (*vh)->magic = 0;
    pthread_mutex_destroy(&(*vh)->mutex);
    BOZVIDEO_UNLOCK_MUTEX(g_video_main.mutex);
    
    (*vh)=BOZV_HANDLE_ZERO;
    return (errno=0,0);   
}

/**
 * @}
 */