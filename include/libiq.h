#ifndef __LIBIQ_H__
#define __LIBIQ_H__

/* Flags */
#define LIBIQ_RDONLY 0 // fix actual values
#define LIBIQ_RW 0 // fix actual values
#define LIBIQ_WRITE 0 // fix actual values
#define LIBIQ_APPEND 0 // fix actual values

/* FILEIQ Type */

/* maybe predefined structures to help */
typedef struct {
    uint8_t i;
    uint8_t q;
} iq_samp_u8_t;

typedef struct {
    float i;
    float q;
} iq_samp_f32_t;




/* Maybe user stuff */
#define   SAMPLE_DTYPE_UINT8   0x01
#define   SAMPLE_DTYPE_F32     0x02

/* not user stuff */
#define   BLOCK_SIZE_BYTES     1048576 /* number of bytes to compress at a time */

typedef struct {
    FILE *fp;
    uint32_t frequency;
    uint32_t samp_rate;
    int samp_type;
    /* compression buffers */
} FILEIQ;



/* Also need option for compression */

/* Open file (including specifying frequency and other things */
FILEIQ *libiq_open(const char *filename, uint16_t flags);
/* OR */


FILEIQ *libiq_open(const char *filename, const char *mode); // this doesn't handle types
// flags handle multiple types and actiosn

FILEIQ *fin;

fout = libiq_open("outputfile.iq", "w", 857000000, 2400000, SAMPLE_DTYPE_UINT8)
fout = libiq_open("outputfile.iq", "rw", 857000000, 2400000, SAMPLE_DTYPE_F32)
fin = libiq_open("outputfile.iq", "r", NULL, NULL);


/* An fwrite() type write function */
size_t libiq_write(const void *buf, size_t nsamp, FILEIQ* fout);

multipe writes for different types? or different opens?

/* An fread type read function */
size_t libiq_read(void *ptr, size_t nsamp, FILEIQ* fin);

/* Close file */
int libiq_close(FILEIQ *f);



/* Also need option for compression */

/* Open file (including specifying frequency and other things */
FILEIQ *libiq_open(const char *filename, uint16_t flags);
/* OR */
FILEIQ *libiq_open(const char *filename, const char *mode, uint8_t  flags);

/* An fwrite() type write function */
size_t libiq_write(const void *buf, size_t nsamp, FILEIQ* fout);

/* An fread type read function */
size_t libiq_read(void *ptr, size_t nsamp, FILEIQ* fin);

/* Close file */
int libiq_close(FILEIQ *f);

#endif /* __LIBIQ_H__ */

