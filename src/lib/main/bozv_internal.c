/**
 * \file bozv_internal.c
 * \addtogroup BOZ_VIDEO_INTERNAL
 * @{
 */

#include <stdio.h>

#include "boz/bozv_internal_p.h"

bozvideo const g_video_main_zero = BOZVIDEO_MAIN_ZERO;

bozvideo g_video_main;

__attribute__((constructor))
static void init() {
    fprintf(stderr, "boz video constructor\n");
    g_video_main = g_video_main_zero;
    goodrandom_init ();
    g_video_main.magic = goodrandom_int(0X5A5A5A5A);
    fprintf(stderr, "\tdicovery magic(%u)\n", g_video_main.magic);
}

__attribute__((destructor))
static void fini() {
    fprintf(stderr, "boz video destructor\n");
    gensetdyn_free (&g_video_main.handle);
    g_video_main = g_video_main_zero;
    goodrandom_finish ();
}

/**
 * @}
 */
