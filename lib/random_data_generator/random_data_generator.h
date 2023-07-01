#ifndef RANDOM_DATA_GENERATOR_H
#define RANDOM_DATA_GENERATOR_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "tractive_config.h"

#define INITIAL_EPOCH 1688141413 //copypasted from https://www.epochconverter.com/

void populate_page_with_random_data(uint8_t *mem_page);

#endif // RANDOM_DATA_GENERATOR_H