/* Private anonymous mapping example using mmap syscall */
#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void static inline errExit(const char* msg)
{
        printf("%s failed. Exiting the process\n", msg);
        exit(-1);
}

int main()
{
        int ret = -1;
        printf("Welcome to private anonymous mapping example::PID:%d\n", getpid());
        printf("Before mmap\n");
        getchar();
        int fd = open("./test/test.txt", O_RDONLY, S_IRUSR | S_IWUSR);
        struct stat sb; 
        if (fstat(fd, &sb) == -1) {
            perror("couldn't get file size.\n");
        }
        printf("file szie is %ld\n", sb.st_size);
        char* addr = NULL;
        addr = mmap(NULL, sb.st_size, PROT_READ|PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, fd, 0);
        if (addr == MAP_FAILED)
                errExit("mmap");
        printf("mmap allocated address:%p\n", addr);
        printf("After mmap\n");
        getchar();

        /* Unmap mapped region. */
        ret = munmap(addr, (size_t)132*1024);
        if(ret == -1)
                errExit("munmap");
        printf("After munmap\n");
        getchar();
        return 0;
}
