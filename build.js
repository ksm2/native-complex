const fs = require('fs');
const path = require('path');

const arithmetics = fs.readFileSync(path.resolve(__dirname, './src/inc/arithmetics.c'), 'utf8');

let index = 'const complex = require(\'./build/Release/complex\');\n';
let typings = 'export type Complex = [number, number];\n';

const re = /\/\/ (?<doc>.*)\nvoid (?<name>\w+)\((?<args>.*)\)/g;
let match;
while ((match = re.exec(arithmetics)) !== null) {
  const { name, doc, args } = match.groups;
  const numArgs = args.split(', ').length / 2 - 1;
  const argStr = new Array(numArgs).fill('').map((_, idx) => `c${idx + 1}: Complex`).join(', ');
  index += `exports.${name} = complex.${name};\n`
  typings += `
/**
 * ${doc}
 */
export function ${name}(${argStr}): Complex;
`;
}

fs.writeFileSync(path.resolve(__dirname, './index.js'), index);
fs.writeFileSync(path.resolve(__dirname, './index.d.ts'), typings);
