/**
 * @snapshot Memory manage for aiko
 * 
 * @file job_s.h
 * @copyright Copyright (C) 2017 Johann Lee <me@qinka.pro>
 */

#define _AIKO_SYS_MEM_C_
#include <aiko/sys/mem.h>

__align(4)
  uint8_t __mem_pool[AIKO_MEM_POOL_MAX_SIZE]
__attribute__((at(0X68000000)));

__align(4)
  uint16_t __mem_table[AIKO_MEM_TABLE_MAX_SIZE]
__attribute__((at(0X68000000 + sizeof(uint8_t) * AIKO_MEM_POOL_MAX_SIZE)));

struct mem_pool_t aiko_mem_pool = {
  .MP_pool   = __mem_pool,
  . MP_table = __mem_table,
  .MP_inited = false
};

void __mem_init(void) {
  memset(aiko_mem_pool.MP_pool,0,sizeof(uint8_t)*AIKO_MEM_POOL_MAX_SIZE);
  memset(aiko_mem_pool.MP_table,0,sizeof(uint16_t)*AIKO_MEM_TABLE_MAX_SIZE);
  aiko_mem_pool.MP_inited = true;
}

void memset(void* p,uint8_t d,size_t s) {
  uint8_t* rp = p;
  while(s --) *rp++ = d;
}
void memcpy(void* dst,void* src,size_t s) {
  uint8_t * rdst = dst;
  uint8_t * rsrc = src;
  while(s --) *rdst ++ = *rsrc++;
}

uint32_t __malloc(size_t s) 
  uint16_t needed_mem_blk;
  uint16_t contiue_mem_blk = 0;
  uint32_t i;
  if(s == 0) // need to alloc
    return 0XFFFFFFFF;
  needed_mem_blk = s / AIKO_MEM_BLK_SIZE;
  if(s % AIKO_MEM_BLK_SIZE)
    needed_mem_blk++;
  for(signed long  offset = AIKO_MEM_TABLE_MAX_SIZE - 1; offset >= 0; --offset) {
    if(!aiko_mem_pool.MP_table[offset])  
      ++ contiue_mem_blk;
    else
      contiue_mem_blk = 0;
    if(contiue_mem_blk == needed_mem_blk) {
      for(i=0;i<needed_mem_blk;i++)
        aiko_mem_pool.MP_table[offset+i] = needed_mem_blk;
      return (offset*AIKO_MEM_BLK_SIZE);
    }
  }
  return 0XFFFFFFFF;
}

uint8_t __free(uint32_t off) {
  if(off < AIKO_MEM_POOL_MAX_SIZE) {
    int index = off / AIKO_MEM_BLK_SIZE;
    int alloced_mem_blk = aiko_mem_pool.MP_table[index];
    for(int i = 0; i < alloced_mem_blk; ++i)
      aiko_mem_pool.MP_table[index+i] = 0;
    return 0;
  }
  else
    return 2;
}

void* malloc(size_t s) {
  uint32_t offset = __malloc(s);
  if(offset == 0XFFFFFFFF)
    return NULL;
  else
    return (void*)((uint32_t)aiko_mem_pool.MP_pool+offset);
}
void free(void* p) {
  if(p == NULL)
    return;
  u32 offset = (uint32_t)p-(uint32_t)aiko_mem_pool.MP_pool;
  __free(offset);
}