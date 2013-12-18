/**
 * \file boz-video-entry.h
 * \defgroup BOZ_VIDEO_ENTRY Boz video entries public API
 * @{
 */

#ifndef _BOZ_VIDEO_ENTRIES_H_
#define _BOZ_VIDEO_ENTRIES_H_

/*!
 * \brief Set root path for all entries.
 * 
 * \param[in] path root path
 * \return error code
 * \retval 0 on success
 * \retval -1 on failure (errno set accordingly)
 *
 * errno managed:
 * - 0 on success
 * - EFAULT if \p path is NULL
 * 
 * \note Another way to set this is by BOZV_ENTRY_ROOT_PATH environment variable.
 */
int bozv_entry_set_rootpath(const char* const path);

/*!
 * \brief Prepare new entry.
 * 
 * \param[out] name new entry name
 * \return error code
 * \retval 0 on success
 * \retval -1 on failure (errno set accordingly)
 *
 * errno managed:
 * - 0 on success
 * - EFAULT if \p name is NULL.
 * - EACCES if neither root path created nor new entry created.
 * 
 * \note Take care freeing \p name out string.
 */
int bozv_entry_new(char** const name);


/*!
 * \brief Delete an entry.
 * 
 * \param[in] name entry name
 * \return error code
 * \retval 0 on success
 * \retval -1 on failure (errno set accordingly)
 *
 * errno managed:
 * - 0 on success
 * - EFAULT if \p name is NULL.
 * - EINVAL if \p name doesn't exist.
 * - EACCES if \p name is not deleted.
 * 
 */
int bozv_entry_delete(const char* const name);

#endif //_BOZ_VIDEO_ENTRIES_H_

/**
 * @}
 */
