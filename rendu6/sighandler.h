typedef void handler_t(int) ;

int sigaction_wrapper(int signum, handler_t *handler) ;
