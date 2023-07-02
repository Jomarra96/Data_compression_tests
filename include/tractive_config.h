#ifndef TRACTIVE_CONFIG_H
#define TRACTIVE_CONFIG_H

#define PAGE_SIZE 30000 //In bytes
#define DATAPOINT_ELEMENTS 5 //For given structure
#define DATAPOINTS PAGE_SIZE/DATAPOINT_ELEMENTS

#define DEBUG_OUTPUT 0

/* Common defs */
#define TS_INCREMENT_SEC 60

/* Structure restriction */
#if (PAGE_SIZE%5 != 0)
	#error PAGE_SIZE must be divisible by 5.
#endif

/* uint16_t restriction */
#if (PAGE_SIZE >= 32768)
	#error PAGE_SIZE must be lower than 32768.
#endif

#endif // TRACTIVE_CONFIG_H