export type Complex = [number, number];

/**
 * Adds two complex numbers
 */
export function add(c1: Complex, c2: Complex): Complex;

/**
 * Subtracts two complex numbers
 */
export function subtract(c1: Complex, c2: Complex): Complex;

/**
 * Multiplies two complex numbers
 */
export function multiply(c1: Complex, c2: Complex): Complex;

/**
 * Divides two complex numbers
 */
export function divide(c1: Complex, c2: Complex): Complex;

/**
 * Calculates the absolute value
 */
export function absolute(c1: Complex): Complex;

/**
 * Calculates the number's conjugate
 */
export function conjugate(c1: Complex): Complex;
