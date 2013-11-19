/**
 * \file bozv_open.c
 * \addtogroup BOZ_VIDEO
 * @{
 */

#include "boz/bozv_internal_p.h"

int bozv_handle_open(bozv_handle_t *vh) {
    unsigned int idx=-1;
    int ret=-1;
    
    if((*vh)!=BOZV_HANDLE_ZERO)
        return(errno=EINVAL,-1);
    
    BOZDISCO_LOCK_MUTEX(g_video_main.mutex);
    ret=gensetdyn_new (&g_video_main.handle, &idx);
    BOZDISCO_UNLOCK_MUTEX(g_video_main.mutex);
    
    if(ret<0) 
        return (errno=EIO,-1);
    
    (*vh)=GENSETDYN_P(struct bozv_handle_s, &g_video_main.handle, idx);
    (*vh)->magic=g_video_main.magic;
    (*vh)->idx=idx;
    pthread_mutex_init(&(*vh)->mutex, NULL);
    
    return (errno=0,0);   
}

/**
 * @}
 */
