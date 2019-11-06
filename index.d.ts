export type Complex = [number, number];

/**
 * Adds two complex numbers
 */
export function add(a: number, b: number, c: number, d: number): Complex;

/**
 * Subtracts two complex numbers
 */
export function subtract(a: number, b: number, c: number, d: number): Complex;

/**
 * Multiplies two complex numbers
 */
export function multiply(a: number, b: number, c: number, d: number): Complex;

/**
 * Divides two complex numbers
 */
export function divide(a: number, b: number, c: number, d: number): Complex;

/**
 * Calculates the absolute value
 */
export function absolute(a: number, b: number): Complex;

/**
 * Calculates the number's conjugate
 */
export function conjugate(a: number, b: number): Complex;
