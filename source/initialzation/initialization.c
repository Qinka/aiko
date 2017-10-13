#include <aiko/job/job_s.h>

/**
 * these two init-function should be defined in
 * where main function should be.
 */
extern struct job_t* job_initialization;
extern struct job_t* sys_initialization;


void aiko_initialization(void) {
  job_add(sys_initialization);
  job_add(job_initialization);
  while(1)
    job_scheduler_launch();
}
