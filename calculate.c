#include <stdio.h>

// 函数声明
int add(int a, int b);
int subtract(int a, int b);

int main() {
    // 调用加法和减法函数并输出结果
    int sum = add(5, 3);
    int difference = subtract(5, 3);

    printf("Sum: %d\n", sum);
    printf("Difference: %d\n", difference);

    return 0;
}

// 加法函数
int add(int a, int b) {
    return a + b;
}

// 减法函数
int subtract(int a, int b) {
    return a - b;
}
