const native = require('../');
const fast = require('fast-complex');
const basic = require('complex');

class TestResult {
  constructor(name) {
    this.name = name;
    this.times = [];
    this.sorted = false;
  }

  add(start, end) {
    this.times.push(Number(end - start));
  }

  sum() {
    return this.times.reduce((sum, time) => sum + time, 0);
  }

  avg() {
    return this.sum() / this.times.length;
  }

  min() {
    this.ensureSorted();
    return this.times[0];
  }

  max() {
    this.ensureSorted();
    return this.times[this.times.length - 1];
  }

  med() {
    this.ensureSorted();
    return this.times[Math.floor(this.times.length / 2)];
  }

  stdDeviation() {
    const avg = this.avg()
    const variance = this.times.reduce((sum, time) => sum + Math.pow(time - avg, 2), 0) / this.times.length;
    return Math.sqrt(variance)
  }

  ensureSorted() {
    if (!this.sorted) {
      this.times.sort((a, b) => a - b);
      this.sorted = true;
    }
  }

  toString() {
    return `
Test Results for ${this.name}
-----------------${'-'.repeat(this.name.length)}

n: ${this.times.length}
Avg: ${this.avg()} ns    
Min: ${this.min()} ns    
Max: ${this.max()} ns    
Med: ${this.med()} ns    
Std: ${this.stdDeviation()} ns    
`;
  }
}

const numberOfRuns = 100000;
let i;

const basicResults = new TestResult('complex');
for (i = 0; i < numberOfRuns; i += 1) {
  const start = process.hrtime.bigint();
  new basic(6, 10).divide(new basic(1, 1));
  const end = process.hrtime.bigint();
  basicResults.add(start, end);
}
console.log(basicResults.toString());

const fastResults = new TestResult('fast-complex');
for (i = 0; i < numberOfRuns; i += 1) {
  const start = process.hrtime.bigint();
  fast.div([6, 10], [1, 1]);
  const end = process.hrtime.bigint();
  fastResults.add(start, end);
}
console.log(fastResults.toString());

const nativeResults = new TestResult('native-complex');
for (i = 0; i < numberOfRuns; i += 1) {
  const start = process.hrtime.bigint();
  native.divide([6, 10], [1, 1]);
  const end = process.hrtime.bigint();
  nativeResults.add(start, end);
}
console.log(nativeResults.toString());
