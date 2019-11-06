const complex = require('./build/Release/complex');
exports.add = ([a, b], [c, d]) => complex.add(a, b, c, d);
exports.subtract = ([a, b], [c, d]) => complex.subtract(a, b, c, d);
exports.multiply = ([a, b], [c, d]) => complex.multiply(a, b, c, d);
exports.divide = ([a, b], [c, d]) => complex.divide(a, b, c, d);
exports.absolute = ([a, b]) => complex.absolute(a, b);
exports.conjugate = ([a, b]) => complex.conjugate(a, b);
