/**
 * @snapshot job scheduler
 * @file job_s.c
 * @copyright Copyright (C) 2017 Johann Lee <me@qinka.pro>
 */

#include <aiko/sys/job.h>
#include <aiko/sys/mem.h>

// lock for scheduler
char job_s_lock = 0;

/// the job queue's head
static struct job_t *job_queue_head_p = 0;

/// the job queue's tail
static struct job_t *job_queue_tail_p = 0;

/// the wait queue
static struct wait_t *wait_queue = 0;

/**
 * add a job to queue
 * @param j the job to be added
 */
int __job_add(struct job_t *j) {
  if (job_queue_tail_p) {
    // job queue not empty
    job_queue_tail_p->next_job_p = j;
    job_queue_tail_p = j;
    job_queue_tail_p->next_job_p = 0;
  } else {
    // job queue is empty
    job_queue_head_p = j;
    job_queue_tail_p = j;
    job_queue_head_p->next_job_p = 0;
  }
  return 0;
}

/**
 * add a job to wait queue
 * @param j the job to be added
 */
int __wait_add(struct job_t *j, int8_t t) {
  struct wait_t *w = (struct wait_t *)malloc(sizeof(struct wait_t));
  w->wait_job = j;
  w->wait_time = t;
  w->next_wait_p = wait_queue;
  wait_queue = w;
  return 0;
}

/**
 * add a job to queue
 * @param j the job to be added
 */
int job_add(struct job_t *j, int8_t w) {
  if (w < 0) {
    __job_add(j);
  } else {
    __wait_add(j, w);
  }
  return 0;
}

/**
 * get a job from queue
 * @return the point for job_t
 */

struct job_t *job_get() {
  struct job_t *rt;
  if (job_queue_head_p) {
    // job queue not empty
    rt = job_queue_head_p;
    if (job_queue_head_p == job_queue_tail_p)
      job_queue_tail_p = 0;
    job_queue_head_p = job_queue_head_p->next_job_p;
  } else
    rt = job_queue_head_p;
  return rt;
}

int job_scheduler_launch() {
  if (!job_s_lock) {
    job_s_lock = 1;
    // loop
    while (1) {
      struct job_t *cur = job_get();
      if (cur)
        cur->job_method(cur);
    }
    job_s_lock = 0;
    return 0;
  } else
    return 1;
}
void wait_handler(void) {
  struct wait_t *curr = wait_queue;
  struct wait_t *last = wait_queue;
  while (curr) {
    if (curr->wait_time > 0) {
      curr->wait_time -= 1;
      last = curr;
    } else {
      if(last != curr)
        last->next_wait_p = curr->next_wait_p;
      __job_add(curr->wait_job);
      free(curr);
    }
    curr = curr->next_wait_p;
  }
}