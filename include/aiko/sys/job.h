/**
 * @snapshot job scheduler
 *           header
 * @file job_s.h
 * @copyright Copyright (C) 2017 Johann Lee <me@qinka.pro>
 */

#ifndef _AIKO_SYS_JOB_H_
#define _AIKO_SYS_JOB_H_

// include
#include <aiko/types.h>

// add a job in to queue
int job_add(struct job_t *, int8_t);

// launch job scheduler
int job_scheduler_launch();

// handler for timer
void wait_handler(void);
#endif // _AIKO_SYS_JOB_H_ & end of job_s.h
