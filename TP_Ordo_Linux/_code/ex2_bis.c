#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <sys/time.h>
#include <sched.h>

#include <pthread.h>
#include <syscall.h>

/*MIF18 : Lab 5 Linux Scheduling, ex2 version threads*/
/* Grégoire Pichon, 2022 */ 

#define NB_CALLS 100000
#define ONE_MILLION 1000000 // pour convertir les secondes en microsecondes

void* work(void *useless){


  while(1){

    unsigned long elapsedMicroseconds;
    struct timeval startTime, endTime;
    
    gettimeofday(&startTime, NULL);

    // TODO : boucle qui effectue NB_CALLS appels à sched_yield
    // (3 lignes)
        for (int n = 0; n < NB_CALLS; n++)
    {
      sched_yield();
    }

    gettimeofday(&endTime, NULL);

    elapsedMicroseconds = (endTime.tv_sec - startTime.tv_sec) * ONE_MILLION + (endTime.tv_usec - startTime.tv_usec);
    printf("Calling 100 000 sched_yield() took %8lu microseconds id %d\n", elapsedMicroseconds, syscall(SYS_gettid));
  }
  return NULL;
}

int main(){

  int i;
  int nb = 4; // Nombre de threads à passer en paramètre du programme
  pthread_t t[nb];
  for (i=0; i<nb; i++){
    pthread_create(&t[i], NULL, &work, NULL);
  }

  for (i=0; i<nb; i++){
    pthread_join(t[i], NULL);
  }
  
  return 0;
}
