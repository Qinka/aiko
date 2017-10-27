#include <aiko/sys/job.h>

/**
 * these two init-function should be defined in
 * where main function should be.
 */
extern struct job_t job_initialization;
extern struct job_t sys_initialization;


void aiko_initialization(void) {
  job_add(&sys_initialization,-1);
  job_add(&job_initialization,-1);
  while(1)
    job_scheduler_launch();
}
