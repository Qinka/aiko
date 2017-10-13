/**
 * @snapshot job types
 *           header
 * @file  job_t.h
 * @copyright Copyright (C) 2017 Johann Lee <me@qinka.pro>
 * 
 */

#ifndef _JOB_T_H_
#define _JOB_T_H_

/**
 * job's function typr
 */
struct job_t;
typedef void (*job_func_t)(struct job_t *);

/**
 * ADT for a job
 */
struct job_t {
  job_func_t    job_method;
  void*         job_data_p;
  unsigned int  job_data_s;
  struct job_t* next_job_p;
};

#endif // _JOB_T_H_ & end of job_t.h
