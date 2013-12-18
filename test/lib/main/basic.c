
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "boz-video.h"

int main(int ac, char **av) {
    int ret = 0;
    bozv_handle_t vh = BOZV_HANDLE_ZERO;
    
    (void) ac;
    (void) av;

    ret = bozv_handle_open(&vh);
    if (ret < 0) {
        fprintf(stderr, "Unable to open video handle, errno(%d/%s)\n",
                errno, strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    fprintf(stdout, "Press key to continue\n");
    getchar();

    ret = bozv_handle_close(&vh);
    if (ret < 0) {
        fprintf(stderr, "Unable to close video handle, errno(%d/%s)\n",
                errno, strerror(errno));
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "All test succeeded\n");
    exit(EXIT_SUCCESS);
}
