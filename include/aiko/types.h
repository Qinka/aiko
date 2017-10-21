/***
 * basic types for aiko
 * 
 */

 #ifndef _AIKO_TYPES_H_
 #define _AIKO_TYPES_H_


/**
 * job's function type
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

 
 #endif // !_AIKO_TYPES_H_