#include <stdio.h>

int main(void) {
    // 사용자로부터 정수 입력 받아 출력하는 예시
    int input_num = 0;
    
    printf("정수를 입력하세요: ");
    scanf_s("%d", &input_num);
    
    printf("입력된 값: %d\n", input_num);
    
    return 0;
}