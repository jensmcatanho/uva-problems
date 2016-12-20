#include <stdio.h>

int main() {
	unsigned int i;
	unsigned int j;

	unsigned int temp_i;
	unsigned int temp_j;

	unsigned int n;
	unsigned int max_cycle = 0;
	unsigned int cycle_length;

	while (scanf("%d %d", &temp_i, &temp_j) != EOF) {
		i = temp_i > temp_j ? temp_j : temp_i;
		j = temp_i > temp_j ? temp_i : temp_j;

		max_cycle = 0;

		while (i <= j) {
			cycle_length = 1;
			n = i;

			while (n != 1) {
				if (n % 2) {
					n = (3 * n + 1) >> 1;
					cycle_length += 2;

				} else {
					n >>= 1;
					cycle_length++;
				}
			}

			if (cycle_length > max_cycle)
				max_cycle = cycle_length;

			i++;
		}

		printf("%d %d %d\n", temp_i, temp_j, max_cycle);
	}

	return 0;
}