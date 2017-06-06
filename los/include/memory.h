#ifndef __LOS_MEMORY_H
#define __LOS_MEMORY_H
#include <config.h>
#include <board.h>
#include <error.h>
#include <stdio.h>
#include <unistd.h>

_uint32_t g_piSource = 0x2000000;
#define MEMORYLENGTH  192*1024

struct stuMemoryNode;
typedef struct stuMemoryNode * pstuMemoryNode;
typedef struct stuMemoryNode * pstuMemoryNodeFreeList;
typedef struct stuMemoryNode * pstuMemoryNodeUsedList;

typedef struct stuMemoryNode{
	pstuMemoryNode * pPrvNode,
	pstuMemoryNode * pNextNode,
	_uint8_t bIsUsed,
	_uint32_t iAllSize;
	_uint32_t iFreeSize;
	_uint32_t iOffset;
	};

void * os_mem_malloc(_uint32_t iSize);
void * os_mem_calloc(_uint8_t cValue , _uint32_t iSize);
void * os_mem_free(void * p);

#endif //__LOS_MEMORY_H