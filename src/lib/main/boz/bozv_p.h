/**
 * \file bozv_p.h
 * \defgroup BOZ_VIDEO_PRIVATE Boz video private API
 * @{
 */

#ifndef _BOZ_VIDEO_P_H_
#define _BOZ_VIDEO_P_H_

#include "boz-video.h"

/*!
 * \struct bozv_handle_s
 * \brief Internal video handle storage.
 *
 * bozv_handle_s is the only way to use global variables along boz-video public library
 */
struct bozv_handle_s {
    unsigned int    magic;      /*!< Magic number to identify and check first in all public APIs */
    unsigned int    idx;        /*!< Index storage (see \ref bozvideo_s) */
    pthread_mutex_t mutex;      /*!< Section locking mutex for handle creation/deletion */
};

#endif

/**
 * @}
 */