#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define CHROM_LEN 16
#define POP_SIZE 100
#define ITER_NUM 1000
#define MUT_RATE 0.05

// Define the system matrix using matrix coding
double sys_mat[2][8] = { { 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0 },
{ 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 } };

// Define the range of each parameter for real coding
double param_range[2][8] = { { 0.1, 10.0, 0.1, 10.0, 0.1, 10.0, 0.1, 10.0 },
{ 0.1, 10.0, 0.1, 10.0, 0.1, 10.0, 0.1, 10.0 } };

// Function to generate a random number within a range
double rand_range(double min, double max) {
	double range = max - min;
	double num = (double)rand() / RAND_MAX;
	return min + num * range;
}

// Function to initialize a population with random chromosomes
void init_population(double population[POP_SIZE][CHROM_LEN]) {
	int i, j;
	for (i = 0; i < POP_SIZE; i++) {
		for (j = 0; j < CHROM_LEN; j++) {
			if (j < 8) {
				population[i][j] = rand_range(param_range[0][j], param_range[1][j]);
			}
			else {
				population[i][j] = (double)rand() / RAND_MAX;
			}
		}
	}
}

// Function to evaluate the fitness of a chromosome
double evaluate_fitness(double chromosome[CHROM_LEN]) {
	int i, j;
	double sys_mat_temp[2][8];
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 8; j++) {
			sys_mat_temp[i][j] = sys_mat[i][j] * chromosome[j];
		}
	}
	double det = sys_mat_temp[0][0] * sys_mat_temp[1][1] - sys_mat_temp[0][1] * sys_mat_temp[1][0];
	double bandwidth = fmin(sys_mat_temp[0][0] / sys_mat_temp[0][1], sys_mat_temp[1][1] / sys_mat_temp[1][0]);
	double efficiency = det / (bandwidth * CHROM_LEN);
	return efficiency;
}

// Function to select a chromosome for crossover
int select_chromosome(double fitness[POP_SIZE]) {
	double total_fitness = 0.0;
	int i;
	for (i = 0; i < POP_SIZE; i++) {
		total_fitness += fitness[i];
	}
	double rand_num = rand_range(0.0, total_fitness);
	double sum_fitness = 0.0;
	for (i = 0; i < POP_SIZE; i++) {
		sum_fitness += fitness[i];
		if (sum_fitness >= rand_num) {
			return i;
		} 
	}
}

void main()
{

}