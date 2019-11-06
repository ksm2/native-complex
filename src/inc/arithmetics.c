#include <math.h>

// Adds two complex numbers
void add(int r1, int i1, int r2, int i2, int* real, int* imaginary) {
  *real = r1 + r2;
  *imaginary = i1 + i2;
}

// Subtracts two complex numbers
void subtract(int r1, int i1, int r2, int i2, int* real, int* imaginary) {
  *real = r1 - r2;
  *imaginary = i1 - i2;
}

// Multiplies two complex numbers
void multiply(int r1, int i1, int r2, int i2, int* real, int* imaginary) {
  *real = r1 * r2 - i1 * i2;
  *imaginary = r1 * i2 + r2 * i1;
}

// Divides two complex numbers
void divide(int r1, int i1, int r2, int i2, int* real, int* imaginary) {
  *real = (r1 * r2 + i1 * i2) / (r2 * r2 + i2 * i2);
  *imaginary = (r2 * i1 - r1 * i2) / (r2 * r2 + i2 * i2);
}

// Calculates the absolute value
void absolute(int r1, int i1, int* real, int* imaginary) {
  *real = sqrt(r1 * r1 + i1 * i1);
  *imaginary = 0;
}

// Calculates the number's conjugate
void conjugate(int r1, int i1, int* real, int* imaginary) {
  *real = r1;
  *imaginary = -i1;
}
