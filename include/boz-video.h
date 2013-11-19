/**
 * \file boz-video.h
 * \defgroup BOZ_VIDEO Boz video public API
 * @{
 */

#ifndef _BOZ_VIDEO_H_
#define _BOZ_VIDEO_H_

/*!
 * Video handle type 
 * 
 * \note variable must be initialised to BOZV_HANDLE_ZERO.
 */
typedef struct bozv_handle_s *bozv_handle_t;

/*! 
 * Video handle type init value 
 */
#define BOZV_HANDLE_ZERO NULL

/*!
 * \param[in,out] vh video handle
 * \return error code
 * \retval 0 on success
 * \retval -1 on failure (errno set accordingly)
 *
 * errno managed:
 * - 0 on success
 * - EINVAL if \p vh is not set to BOZV_HANDLE_ZERO as input value
 * - EIO if \p vh can't be instanciated
 */
int bozv_handle_open(bozv_handle_t *vh);

/*!
 * \param[in,out] vh
 * \return error code
 * \retval 0 on success
 * \retval -1 on failure (errno set accordingly)
 *
 * errno managed:
 * - 0 on success
 * - EINVAL if \p vh has not been set with \ref boz_discovery_init
 * 
 * \note \p vh is reset to BOZV_HANDLE_ZERO on success
 */
int bozv_handle_close(bozv_handle_t *vh);

#endif

/**
 * @}
 */
