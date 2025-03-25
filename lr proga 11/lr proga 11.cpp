#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <cctype> // Для функції isdigit()

using namespace std;

// Функція для обчислення середнього арифметичного чисел у векторі
double calculateArithmeticMean(const vector<double>& numbers) {
    double sum = 0;
    for (double num : numbers) {
        sum += num;
    }
    return sum / numbers.size();
}

// Функція для обчислення середнього геометричного чисел у векторі
double calculateGeometricMean(const vector<double>& numbers) {
    double product = 1;
    for (double num : numbers) {
        product *= num;
    }
    return pow(product, 1.0 / numbers.size());
}

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt"); 

    if (!inputFile.is_open()) {
        cout << "Unable to open input file." << endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        cout << "Unable to create output file." << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        vector<double> numbers;
        string currentNumber;

        for (char c : line) {
            if (isdigit(c)) {
                currentNumber += c;
            }
            else {
                if (!currentNumber.empty()) {
                    numbers.push_back(stod(currentNumber));
                    currentNumber.clear(); 
                }
            }
        }

        if (!currentNumber.empty()) {
            numbers.push_back(stod(currentNumber));
        }

        double arithmeticMean = calculateArithmeticMean(numbers);
        double geometricMean = calculateGeometricMean(numbers);

        outputFile << "Numbers: ";
        for (double num : numbers) {
            outputFile << num << " ";
        }
        outputFile << endl;
        outputFile << "Arithmetic Mean: " << arithmeticMean << endl;
        outputFile << "Geometric Mean: " << geometricMean << endl;
        outputFile << endl;
    }

    inputFile.close();
    outputFile.close();

    cout << "Calculation complete. Results written to output.txt." << endl;

    return 0;
}
