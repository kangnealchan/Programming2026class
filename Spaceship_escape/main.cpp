#include <stdio.h>

// 매크로 상수 정의
#define TARGET_ENERGY 1     // 우주선 탈출을 위한 목표 에너지 값
#define MULTIPLY_FACTOR 3   // 홀수 일 때 곱하는 값
#define ADD_FACTOR 1        // 홀수 일 때 더하는 값
#define EVEN_DIVISOR 2      // 짝수 일 때 나누는 값
#define MIN_ENERGY 1        // 최소 초기 에너지 값

int main(void)
{
    int energy;             // 사용자가 입력할 초기 엔진 에너지 저장 변수
    int steps = 0;          // 1에 도달하기까지 걸린 총 단계를 셀 변수
    int max_altitude = 0;   // 과정 중 도달한 최고 에너지 수치를 저장할 변수

    // 사용자로부터 초기 엔진 에너지 입력 받기
    printf("Enter the initial engine energy: ");

    // [예외 처리] scanf_s 반환값 확인
    if (scanf_s("%d", &energy) != 1)
    {
        printf("[Error] Invalid input. Please enter numbers only.\n");
        return 0;
    }

    // [예외 처리] 양의 정수가 아닌 경우 방어
    if (energy < MIN_ENERGY)
    {
        printf("[Error] Please enter a positive integer.\n");
        return 0;
    }

    // 초기 에너지가 최고 에너지의 후보가 되므로 먼저 설정
    max_altitude = energy;

    // 시퀀스 출력 시작
    printf("Sequence: %d", energy);

    // 에너지가 목표 값(1)이 될 때까지 while 문과 if 문을 이용해 반복
    while (energy > TARGET_ENERGY)
    {
        // 현재 에너지가 역대 최고치보다 높다면 max_altitude 갱신
        if (energy > max_altitude)
        {
            max_altitude = energy;
        }

        // 짝수와 홀수 조건에 따른 에너지 변환
        if (energy % EVEN_DIVISOR == 0)
        {
            energy = energy / EVEN_DIVISOR;
        }
        else
        {
            energy = (energy * MULTIPLY_FACTOR) + ADD_FACTOR;
        }

        // 변화하는 모든 과정을 화살표 형태로 출력
        printf("->%d", energy);

        // 단계 수 증가
        steps++;
    }
    printf("\n");

    // 탈출 성공 메시지 및 결과 통계 출력
    printf("Escape successful!\n");
    printf("Total steps: %d\n", steps);
    printf("Maximum altitude reached: %d\n", max_altitude);

    return 0;
}