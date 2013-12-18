/**
 * \file bozv_entry_internal_p.h
 * \defgroup BOZ_VIDEO_ENTRY_INTERNAL Boz video entry internal API
 * @{
 */

#ifndef _BOZV_ENTRY_INTERNAL_P_H_
#define _BOZV_ENTRY_INTERNAL_P_H_

#include <stdint.h>
#include <errno.h>
#include <pthread.h>

enum {
    BOZV_ENTRY_TMPPATH_OK = (1<<0),
    BOZV_ENTRY_ROOTPATH_OK = (1<<1),
};

/*!
 * \struct bozvideo_entry_s
 * \brief Global variables storage.
 *
 * bozv_handle_s is the only way to use global variables along boz-video public library.
 */
typedef struct bozvideo_entry_s bozvideo_entry, bozvideo_entry_t, *bozvideo_entry_ref, *bozvideo_entry_t_ref ;
struct bozvideo_entry_s {
    const char*         tmp_path;       /*!< working path. */
    const char*         root_path;      /*!< storing entries path. */
    uint32_t            status;         /*!< bitwise status. */
    pthread_mutex_t     mutex;          /*!< Section locking mutex. */
};

/*!
 * \brief \ref bozvideo_entry_s default values.
 * This value must be the init values for handle storage data.
 */
#define BOZVIDEO_ENTRY_MAIN_ZERO { 0, 0, 0, PTHREAD_MUTEX_INITIALIZER }

extern bozvideo_entry const g_video_entry_main_zero ;
extern bozvideo_entry g_video_entry_main;

/*!
 * \brief Mutex locking macro.
 */
#define BOZVIDEO_ENTRY_LOCK_MUTEX(x)      pthread_mutex_lock(&x)
/*!
 * \brief Mutex unlocking macro.
 */
#define BOZVIDEO_ENTRY_UNLOCK_MUTEX(x)    pthread_mutex_unlock(&x)

/*!
 * \brief Check and create root path.
 * 
 * \return error code
 * \retval 0 on success
 * \retval -1 on failure (errno set accordingly)
 *
 * errno managed:
 * - 0 on success
 * - EACCES if root path is not created.
 * 
 */
int _bozv_entry_check_rootpath(void);

#endif

/**
 * @}
 */