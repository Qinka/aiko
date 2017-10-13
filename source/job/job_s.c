/**
 * @snapshot job scheduler
 * @file job_s.c
 * @copyright Copyright (C) 2017 Johann Lee <me@qinka.pro>
 */

#include <aiko/job/job_s.h>

// lock for scheduler
char job_s_lock = 0;

/**
 * the job queue's head
 */
static volatile struct job_t * job_queue_head_p = 0;
/**
 * the job queue's tail
 */
static volatile struct job_t * job_queue_tail_p = 0;

/**
 * add a job to queue
 * @param j the job to be added
 */
int job_add(struct job_t * j) {
  if(job_queue_tail_p) {
    // job queue not empty
    job_queue_tail_p -> next_job_p = j;
    job_queue_tail_p               = j;
    job_queue_tail_p -> next_job_p = 0;
  }
  else {
    // job queue is empty
    job_queue_head_p = j;
    job_queue_tail_p = j;
    job_queue_head_p  -> next_job_p = 0;
  }
  return 0;
}


/**
 * get a job from queue
 * @return the point for job_t
 */

struct job_t* job_get() {
  struct job_t* rt;
  if (job_queue_head_p) {
    // job queue not empty
    rt = job_queue_head_p;
    if (job_queue_tail_p == job_queue_tail_p)
      job_queue_tail_p = 0;
    job_queue_head_p = job_queue_head_p -> next_job_p;
  }
  else
    rt = job_queue_head_p;
  return rt;
}

int job_scheduler_launch() {
  if(!job_s_lock) {
    job_s_lock = 1;
    // loop
    while(1) {
      struct job_t * cur = job_get();
      if(job_get)
        cur -> job_method(cur);
    }
    job_s_lock = 0;
    return 0;
  }
  else
    return 1;
}
