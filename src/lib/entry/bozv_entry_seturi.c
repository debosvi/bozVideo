
#include <unistd.h>
#include <fcntl.h>

#include "boz-video-entry.h"
#include "boz/bozv_entry_internal_p.h"
#include "skarnet/unix-transactional.h"

int bozv_entry_seturi(const char* const name, const char* const uri) {
    int dirfd=-1;
    
    if(!name || !uri)
        return (errno=EFAULT,-1);
    
    if(_bozv_entry_check_rootpath()<0)
        return -1;
    
    chdir(g_video_entry_main.root_path);
    
    dirfd=open(name, O_DIRECTORY);
    openwritenclose_at(dirfd, "URI", uri, strlen(uri));

    return (errno=0,0);
}


