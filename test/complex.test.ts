import { add, subtract, multiply, divide } from '../';

describe('complex', () => {
  it('adds two numbers', () => {
    expect(add([0, 0], [0, 0])).toEqual([0, 0]);
    expect(add([1, 2], [3, 4])).toEqual([4, 6]);
    expect(add([1, 2], [-1, -2])).toEqual([0, 0]);
  });

  it('subtracts two numbers', () => {
    expect(subtract([0, 0], [0, 0])).toEqual([0, 0]);
    expect(subtract([3, 4], [1, 2])).toEqual([2, 2]);
    expect(subtract([1, 2], [-1, -2])).toEqual([2, 4]);
  });

  it('cannot add non-numbers', () => {
    // @ts-ignore
    expect(() => add(-1, [1, 2])).toThrow('Unable to destruct the first complex number');
    // @ts-ignore
    expect(() => add([1, 2], -1)).toThrow('Unable to destruct the second complex number');
  });

  it('multiplies two numbers', () => {
    expect(multiply([0, 0], [0, 0])).toEqual([0, 0]);
    expect(multiply([1, 2], [3, 4])).toEqual([-5, 10]);
    expect(multiply([1, 2], [-1, -2])).toEqual([3, -4]);
  });

  it('divides two numbers', () => {
    expect(divide([5, 5], [5, 5])).toEqual([1, 0]);
    expect(divide([10, 10], [5, 5])).toEqual([2, 0]);
    expect(divide([6, 10], [1, 1])).toEqual([8, 2]);
  });
});
