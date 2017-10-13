#include <job/job_s.h>

/**
 * these two init-function should be defined in
 * where main function should be.
 */
extern void job_initialzation(void);
extern void sys_initialzation(void);


void aiko_initialztion(void) {
  sys_initialzation();
  job_initialzation();
  while(1)
    job_scheduler_launch();
}
