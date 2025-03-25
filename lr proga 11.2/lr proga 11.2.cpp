#include <stdio.h>
#pragma warning(disable : 4996)
int main() {
    FILE* inputFile = fopen("F.txt", "r");
    FILE* outputFile = fopen("G.txt", "w");

    if (inputFile == NULL) {
        printf("Unable to open input file.\n");
        return 1;
    }
    if (outputFile == NULL) {
        printf("Unable to create output file.\n");
        return 1;
    }
    int flag = 0;
    int buffer[20];
    int num, totalNumbers = 0;

    while (fscanf(inputFile, "%d", &num) != EOF) {
        if (totalNumbers <20) {
            buffer[totalNumbers++] = num;
            flag ++;
        }
        if(flag==20) {
            for (int j = 0; j < 5; ++j) {
                fprintf(outputFile, "%d ", buffer[j]);
            }
            for (int j = 10; j < 15; ++j) {
                fprintf(outputFile, "%d ", buffer[j]);
            }
            for (int n = 5; n < 10; ++n) {
                fprintf(outputFile, "%d ", buffer[n]);
            }
            for (int k = 15; k < 20; ++k) {
                fprintf(outputFile, "%d ", buffer[k]);
            }
            fprintf(outputFile, "\n");

            // Reset totalNumbers to 0 to start filling buffer again
            totalNumbers = 0;
            flag = 0;
        }
      
    }

   

    fclose(inputFile);
    fclose(outputFile);
    printf("Transformation complete. Results written to G.txt.\n");
    return 0;
}
