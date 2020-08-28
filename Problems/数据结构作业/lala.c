#include<windows.h>
#include <fcntl.h>      //open
#include <sys/mman.h>   //mmap
#include <sys/types.h>  //fstat
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    int i;
    char buff[1];
    struct stat statue;
    
    int fd = open("dictionary.txt", O_RDONLY);
    fstat(fd, &statue);
    char *pm = mmap(NULL, statue.st_size, PROT_READ, MAP_SHARED, fd, 0) ;

    for(i=0; i<statue.st_size; i++)
    {
        buff[0] = pm[i];
    }

    munmap(pm, statue.st_size);
    close(fd);
    
    return 0;
}
