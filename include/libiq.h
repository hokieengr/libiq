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

