/**
 * @snapshot job scheduler
 *           header
 * @file job_s.h
 * @copyright Copyright (C) 2017 Johann Lee <me@qinka.pro>
 */

#ifndef _JOB_S_H_
#define _JOB_S_H_

// include
#include <job/job_t.h>

// add a job in to queue
int job_add(struct job_t*);

// launch job scheduler
int job_scheduler_launch();

#endif // _JOB_S_H_ & end of job_s.h
