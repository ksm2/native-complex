export type Complex = [number, number];

/**
 * Adds two complex numbers.
 *
 * @param c1 - The first complex number.
 * @param c2 - The second complex number.
 * @returns The sum of both complex numbers.
 */
export function add(c1: Complex, c2: Complex): Complex;

/**
 * Subtracts two complex numbers.
 *
 * @param c1 - The first complex number.
 * @param c2 - The second complex number.
 * @returns The difference of both complex numbers.
 */
export function subtract(c1: Complex, c2: Complex): Complex;

export function multiply(c1: Complex, c2: Complex): Complex;
