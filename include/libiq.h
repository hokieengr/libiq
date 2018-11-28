#ifndef __LIBIQ_H__
#define __LIBIQ_H__


#define   SAMPLE_DTYPE_UINT8   0x01
#define   SAMPLE_DTYPE_F32     0x02


/* move this to .c file if possible */
typedef struct {
    FILE       *fp;
    uint32_t    tuner_freq;
    uint32_t    samp_rate;
    int         samp_type;
    /* compression buffers */
} FILEIQ;


/*
 * Routine to open file for writing/reading
 */
FILEIQ *
libiq_open(const char *filename, const char *mode, uint32_t tuner_freq, 
           uint32_t samp_rate, int samp_type);

/*
 * Some useage examples for future reference
 *
fout = libiq_open("outputfile.iq", "w", 857000000, 2400000, SAMPLE_DTYPE_UINT8)
fout = libiq_open("outputfile.iq", "rw", 857000000, 2400000, SAMPLE_DTYPE_F32)
fin = libiq_open("outputfile.iq", "r", NULL, NULL);
*/


/* 
 * Write to file
 */
size_t
libiq_write(const void *buf, size_t nsamp, FILEIQ* fout);



/*
 * Read from file
 */
size_t
libiq_read(void *ptr, size_t nsamp, FILEIQ* fin);

/* Close file */
int
libiq_close(FILEIQ *f);




#endif /* __LIBIQ_H__ */

