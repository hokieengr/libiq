#include "libiq.h"

/* number of bytes to compress at a time */
#define   BLOCK_SIZE_BYTES     1048576

#define   COMP_NONE   0x00
#define   COMP_ZLIB   0x01


/* 
 * File header. Try to keep in mind the common problem of losing power, filling
 * up a tiny memory card, etc when designing this.
 */
typedef struct
{
    uint32_t id;
    uint32_t version;
    uint32_t tuner_freq;
    uint32_t samp_rate;
    uint32_t samp_type;
} filehdr_t;
    


/*
 * Data block header
 */
typedef struct
{
    uint32_t id;
    uint32_t flags; /* use to specify which compression algorithm */
    uint32_t crc;
    uint32_t nbytes_compressed;
    uint32_t nbytes_raw;
} blockhdr_t;





