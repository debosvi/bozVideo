/**
 * \file bozv_entry_internal.c
 * \addtogroup BOZ_VIDEO_ENTRY_INTERNAL
 * @{
 */

#include <stdio.h>
#include <stdlib.h>

#include "boz/bozv_entry_internal_p.h"

bozvideo_entry const g_video_main_entry_zero = BOZVIDEO_ENTRY_MAIN_ZERO;

bozvideo_entry g_video_entry_main;

static const char* bozv_entry_def_tmp_path = "/tmp/bozv_entries";
static const char* bozv_entry_def_root_path = "/opt/bozv_entries";

__attribute__((constructor))
static void init() {
    fprintf(stderr, "boz video entry constructor\n");
    g_video_entry_main = g_video_main_entry_zero;
    g_video_entry_main.tmp_path = bozv_entry_def_tmp_path;
    g_video_entry_main.root_path = bozv_entry_def_root_path;
    
    {
        char *root=getenv("BOZV_ENTRY_ROOT_PATH");
        if(root)
            g_video_entry_main.root_path = root;
    }
}

__attribute__((destructor))
static void fini() {
    fprintf(stderr, "boz video entry destructor\n");
    g_video_entry_main = g_video_main_entry_zero;
}

/**
 * @}
 */
