#include "sighandler.h"
#include "jobs.h"



int sigaction_wrapper(int signum, handler_t *handler){
  struct sigaction sa ;
  sa.sa_handler =  &sigint_handler ;
  sa.sa_flags = 0 ;
  sigemptyset(&s = sa.sa_mask) ; 
}

void sigint_handler(int sig){
  pid_t pid ;
  pid = fgpid() ;
  if(pid > 0)
    kill(pid, sig) ;
}

void sigchld_handler(int sig){
  while((pid=waitpid(-1, &status, WUNTRACED|WNOHANG)>0) {
      /*met a jour les infos (struct job_s) pour pid
	WIFEXITED
	WIFSIGNALED
	WIFSTOPPED*/
    }
}
