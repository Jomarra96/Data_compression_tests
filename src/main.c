#include "main.h"

int main(void)
{
	uint8_t mem_page[PAGE_SIZE] = {0};

	populate_page_with_random_data(mem_page);
}