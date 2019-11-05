export type Complex = [number, number];

/**
 * Adds two complex numbers
 *
 * @param c1 - The first complex number.
 * @param c2 - The second complex number.
 * @returns The result.
 */
export function add(c1: Complex, c2: Complex): Complex;

/**
 * Subtracts two complex numbers
 *
 * @param c1 - The first complex number.
 * @param c2 - The second complex number.
 * @returns The result.
 */
export function subtract(c1: Complex, c2: Complex): Complex;

/**
 * Multiplies two complex numbers
 *
 * @param c1 - The first complex number.
 * @param c2 - The second complex number.
 * @returns The result.
 */
export function multiply(c1: Complex, c2: Complex): Complex;

/**
 * Divides two complex numbers
 *
 * @param c1 - The first complex number.
 * @param c2 - The second complex number.
 * @returns The result.
 */
export function divide(c1: Complex, c2: Complex): Complex;
