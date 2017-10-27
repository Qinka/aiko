/***
 * basic types for aiko
 *
 */

#ifndef _AIKO_TYPES_H_
#define _AIKO_TYPES_H_

#include <stdbool.h>
#include <stdint.h>

/**
 * job's function type
 */
typedef void (*job_func_t)(struct job_t *);

/**
 * ADT for a job
 */
struct job_t {
  job_func_t job_method;
  void *job_data_p;
  unsigned int job_data_s;
  struct job_t *next_job_p;
};

/**
 * ADT for job wait timer
 */
struct wait_t {
  job_t *wait_job;
  int8_t wait_time;
  wait_t *next_wait_p;
};
#endif // !_AIKO_TYPES_H_