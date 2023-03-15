#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <gsl/gsl_vector.h>
#include <gnuplot_i.h>

// Rosenbrock function
double rosenbrock(double *x, int n) {
	double sum = 0.0;
	for (int i = 0; i < n - 1; i++) {
		double t = pow(x[i + 1] , 2) + pow(x[i], 2);
		sum += t;
	}
	return sum;
}

// Generate a random number between 0 and 1
double rand_double() {
	return (double)rand() / RAND_MAX;
}

// Generate a random number within a given range
double rand_double_range(double min, double max) {
	return min + (max - min) * rand_double();
}

// Initialize the population with random values
void init_population(double **population, int pop_size, int genome_size, double min_val, double max_val) {
	for (int i = 0; i < pop_size; i++) {
		for (int j = 0; j < genome_size; j++) {
			population[i][j] = rand_double_range(min_val, max_val);
		}
	}
}

// Evaluate the fitness of each individual in the population
void evaluate_fitness(double **population, int pop_size, int genome_size, double *fitness) {
	for (int i = 0; i < pop_size; i++) {
		fitness[i] = rosenbrock(population[i], genome_size);
	}
}

// Find the index of the individual with the best fitness
int find_best(double *fitness, int pop_size) {
	int best = 0;
	for (int i = 1; i < pop_size; i++) {
		if (fitness[i] < fitness[best]) {
			best = i;
		}
	}
	return best;
}

// Roulette wheel selection
int roulette_wheel(double *fitness, int pop_size) {
	double total_fitness = 0.0;
	for (int i = 0; i < pop_size; i++) {
		total_fitness += fitness[i];
	}
	double r = rand_double() * total_fitness;
	double s = 0.0;
	for (int i = 0; i < pop_size; i++) {
		s += fitness[i];
		if (s > r) {
			return i;
		}
	}
	return pop_size - 1;
}

// Uniform crossover
void uniform_crossover(double *parent1, double *parent2, double *child, int genome_size, double crossover_rate) {
	for (int i = 0; i < genome_size; i++) {
		if (rand_double() < crossover_rate) {
			child[i] = parent1[i];
		}
		else {
			child[i] = parent2[i];
		}
	}
}

// Mutation
void mutation(double *genome, int genome_size, double mutation_rate, double min_val, double max_val) {
	for (int i = 0; i < genome_size; i++) {
		if (rand_double() < mutation_rate) {
			genome[i] = rand_double_range(min_val, max_val);
		}
	}
}

void genetic_algorithm(int pop_size, int genome_size, int max_generations, double min_val, double max_val, double crossover_rate, double mutation_rate) {
	// Allocate memory for the population and fitness array
	double **population = (double **)malloc(pop_size * sizeof(double *));
	for (int i = 0; i < pop_size; i++) {
		population[i] = (double *)malloc(genome_size * sizeof(double));
	}
	double *fitness = (double *)malloc(pop_size * sizeof(double));

	// Initialize the random number generator
	srand(time(NULL));

	// Initialize the population
	init_population(population, pop_size, genome_size, min_val, max_val);

	// Evaluate the fitness of the initial population
	evaluate_fitness(population, pop_size, genome_size, fitness);

	// Find the individual with the best fitness
	int best_index = find_best(fitness, pop_size);
	double best_fitness = fitness[best_index];

	// Main loop
	for (int gen = 1; gen <= max_generations; gen++) {
		// Create a new population
		double **new_population = (double **)malloc(pop_size * sizeof(double *));
		for (int i = 0; i < pop_size; i++) {
			new_population[i] = (double *)malloc(genome_size * sizeof(double));
		}

		// Elitism: copy the best individual to the new population
		for (int i = 0; i < genome_size; i++) {
			new_population[0][i] = population[best_index][i];
		}

		// Generate the rest of the new population using crossover and mutation
		for (int i = 1; i < pop_size; i++) {
			// Select two parents using roulette wheel selection
			int parent1_index = roulette_wheel(fitness, pop_size);
			int parent2_index = roulette_wheel(fitness, pop_size);
			double *parent1 = population[parent1_index];
			double *parent2 = population[parent2_index];

			// Create a new child using uniform crossover
			double *child = new_population[i];
			uniform_crossover(parent1, parent2, child, genome_size, crossover_rate);

			// Mutate the child
			mutation(child, genome_size, mutation_rate, min_val, max_val);
		}

		// Replace the old population with the new population
		for (int i = 0; i < pop_size; i++) {
			for (int j = 0; j < genome_size; j++) {
				population[i][j] = new_population[i][j];
			}
		}

		// Evaluate the fitness of the new population
		evaluate_fitness(population, pop_size, genome_size, fitness);

		// Find the individual with the best fitness
		best_index = find_best(fitness, pop_size);
		double new_best_fitness = fitness[best_index];

		// Print the best fitness of each generation
		printf("Generation %d: Best fitness = %f\n", gen, new_best_fitness);

		// Update the best fitness and stop if the desired accuracy has been reached
		if (new_best_fitness < 1e-6) {
			printf("Solution found!\n");
			break;
		}
		else if (new_best_fitness < best_fitness) {
			best_fitness = new_best_fitness;
		}
	}

	// Free memory
	free(fitness);
	for (int i = 0; i < pop_size; i++) {
		free(population[i]);
	}
	free(population);
}

// Main function
int main() {
	int pop_size = 1000;
	int genome_size = 10;
	int max_generations = 9000;
	double min_val = -5.0;
	double max_val = 5.0;
	double crossover_rate = 0.8;
	double mutation_rate = 0.09;

	genetic_algorithm(pop_size, genome_size, max_generations, min_val, max_val, crossover_rate, mutation_rate);

	return 0;
}