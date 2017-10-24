/**
 * @snapshot Memory manage for aiko
 * (header file)
 * @file job_s.h
 * @copyright Copyright (C) 2017 Johann Lee <me@qinka.pro>
 */

#ifndef _AIKO_SYS_MEM_H_
#define _AIKO_SYS_MEM_H_ 

#include <aiko/types.h>
#include <stdint.h>

#define AIKO_MEM_POOL_MAX_SIZE   (AIKO_MEM_BLK_SIZE * AIKO_MEM_TABLE_MAX_SIZE)
#define AIKO_MEM_TABLE_MAX_SIZE  0xFF
#define AIKO_MEM_BLK_SIZE        4

struct mem_pool_t {
  uint8_t* MP_pool;
  int16_t* MP_table;
  bool MP_inited;
};

void __mem_init(void);

void* malloc(size_t);
void free(void*);
void memset(void*,uint8_t,size_t);
void memcpy(void*,void*,size_t);


#endif // !_AIKO_SYS_MEM_H_