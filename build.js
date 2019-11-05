const fs = require('fs');
const path = require('path');

const arithmetics = fs.readFileSync(path.resolve(__dirname, './src/inc/arithmetics.c'), 'utf8');

let index = 'const complex = require(\'./build/Release/complex\');\n';
let typings = 'export type Complex = [number, number];\n';

const re = /\/\/ (?<doc>.*)\nvoid (?<name>\w+)/g;
let match;
while ((match = re.exec(arithmetics)) !== null) {
  const { name, doc } = match.groups;
  index += `exports.${name} = complex.${name};\n`
  typings += `
/**
 * ${doc}
 *
 * @param c1 - The first complex number.
 * @param c2 - The second complex number.
 * @returns The result.
 */
export function ${name}(c1: Complex, c2: Complex): Complex;
`;
}

fs.writeFileSync(path.resolve(__dirname, './index.js'), index);
fs.writeFileSync(path.resolve(__dirname, './index.d.ts'), typings);
