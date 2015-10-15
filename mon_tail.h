#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define STRINGSIZE 1024
#define STREAMSIZE 8
#define TAIL_SIMPLE

#ifdef TAIL_SIMPLE

/*
 */
int tail(const char *path, int nline) ;

#endif

#ifdef TAIL_RELATIVE

/*
 */
int index_tail_buffer(const char *buffer, int bufsize, int ntail, int *nlines);

/*
 */
int tail_before_pos(int fd, unsigned int pos, int ntail);

#endif

#ifdef TAIL_EFFICACE

/*
 */
int tail(const char *path, int ntail);

#endif

#ifdef TAIL_UTILE

#endif
