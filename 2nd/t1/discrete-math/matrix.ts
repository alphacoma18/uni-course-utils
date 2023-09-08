
const matrix: Matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9],
];

const matrix2: Matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9],
];

type FixedLengthArray<T, L extends number> = L extends 0 ? never[] : {
    0: T;
    length: L;
} & ReadonlyArray<T>;

type Matrix = FixedLengthArray<FixedLengthArray<number, 3>, 3>;
type Op = "+" | "-" | "*" | "/";

type Func = (num1: number, num2: number) => number;

const add: Func = (num1, num2) => num1 + num2;
const subtract: Func = (num1, num2) => num1 - num2;
const multiply: Func = (num1, num2) => num1 * num2;
const divide: Func = (num1, num2) => num1 / num2;

const funcMap: Record<Op, Func> = {
    "+": add,
    "-": subtract,
    "*": multiply,
    "/": divide,
};

function matrixCalc(a: Matrix, b: Matrix, op: Op): Matrix {
    const result: number[][] = [];
    const aLen = a.length;
    for (let i = 0; i < aLen; ++i) {
        const row = [];
        const bLen = a[i].length;
        for (let j = 0; j < bLen; ++j) {
            const num1 = a[i][j];
            const num2 = b[i][j];
            row.push(funcMap[op](num1, num2));
        }
        result.push(row);
    }
    return result as unknown as Matrix;
}

console.log(matrixCalc(matrix, matrix2, "+"));
console.log(matrixCalc(matrix, matrix2, "-"));
console.log(matrixCalc(matrix, matrix2, "*"));
console.log(matrixCalc(matrix, matrix2, "/"));