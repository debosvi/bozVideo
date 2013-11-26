/**
 * \file bozv_internal_p.h
 * \defgroup BOZ_VIDEO_INTERNAL Boz video internal API
 * @{
 */

#ifndef _BOZV_INTERNAL_P_H_
#define _BOZV_INTERNAL_P_H_

#include <errno.h>
#include <pthread.h>
#include <skarnet/gensetdyn.h>
#include <skarnet/random.h>
#include <skarnet/tai.h>
#include <skarnet/skaclient.h>

#include "boz/bozv_p.h"

/*!
 * \struct bozvideo_s
 * \brief Global variables storage.
 *
 * bozv_handle_s is the only way to use global variables along boz-video public library.
 */
typedef struct bozvideo_s bozvideo, bozvideo_t, *bozvideo_ref, *bozvideo_t_ref ;
struct bozvideo_s {
    unsigned int        magic;      /*!< Magic number computed at library loading. */
    pthread_mutex_t     mutex;      /*!< Section locking mutex for handles creation/deletion. */
    gensetdyn           handle;     /*!< Handle storage. */
};

/*!
 * \brief \ref bozvideo_s default values.
 * This value must be the init values for handle storage data.
 */
#define BOZVIDEO_MAIN_ZERO { 0, PTHREAD_MUTEX_INITIALIZER, GENSETDYN_INIT(struct bozv_handle_s, 4, 0, 1) }

extern bozvideo const g_video_main_zero ;
extern bozvideo g_video_main;

/*!
 * \brief Mutex locking macro.
 */
#define BOZVIDEO_LOCK_MUTEX(x)      pthread_mutex_lock(&x)
/*!
 * \brief Mutex unlocking macro.
 */
#define BOZVIDEO_UNLOCK_MUTEX(x)    pthread_mutex_unlock(&x)

/*!
 * \param[in] p used as \ref bozvideo_s handle reference
 * \param[in,out] stuff used as private data
 * \return error code
 * \retval 1 on matching success
 * \retval 0 on matching failure
 */
extern int _bozv_handle_iter(char *p, void *stuff);

#endif

/**
 * @}
 */