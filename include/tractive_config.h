#ifndef TRACTIVE_CONFIG_H
#define TRACTIVE_CONFIG_H

#define PAGE_SIZE 1000 //In bytes
#define DATAPOINT_ELEMENTS 5 //For given structure
#define DATAPOINTS PAGE_SIZE/DATAPOINT_ELEMENTS

#define DEBUG_OUTPUT 0

// Common defs
#define SECONDS_IN_A_MINUTE 60


#if (PAGE_SIZE%5 != 0)
	#error PAGE_SIZE must be divisible by 5.
#endif

#endif // TRACTIVE_CONFIG_H