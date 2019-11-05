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
