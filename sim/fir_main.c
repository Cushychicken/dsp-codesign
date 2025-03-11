#include <stdio.h>
#include <stdlib.h>
#include "fir_filter.h"

#define MAX_SAMPLES 1000  // Define maximum number of samples

int main() {
    // FIR filter coefficients (from Python design)
    float coeffs[8] = {
        0.028, 0.067, 0.122, 0.181, 0.205, 0.181, 0.122, 0.067
    };

    // Initialize filter
    FIRFilter filter;
    fir_init(&filter, coeffs);

    // Open input file for reading
    FILE *input_file = fopen("input_signal.txt", "r");
    if (!input_file) {
        perror("Error opening input file");
        return 1;
    }

    // Open output file for writing
    FILE *output_file = fopen("output_signal.txt", "w");
    if (!output_file) {
        perror("Error opening output file");
        fclose(input_file);
        return 1;
    }

    float input_signal, output_signal;
    int sample_count = 0;

    // Process input signal from file
    while (fscanf(input_file, "%f", &input_signal) == 1 && sample_count < MAX_SAMPLES) {
        output_signal = fir_apply(&filter, input_signal);
        fprintf(output_file, "%f %f\n", input_signal, output_signal);
        sample_count++;
    }

    // Close files
    fclose(input_file);
    fclose(output_file);

    printf("Filtered output saved to output_signal.txt\n");
    return 0;
}

