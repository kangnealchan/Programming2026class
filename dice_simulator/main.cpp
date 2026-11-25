#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROLLS 60000     // 주사위를 던지는 횟수
#define FACES 6          // 주사위의 면 개수
#define STAR_UNIT 50     // 별 하나가 나타내는 횟수

int main()
{
    int count[FACES] = { 0 };  // 각 눈이 나온 횟수를 저장하는 배열
    int* p = count;            // 배열의 시작 주소를 저장하는 포인터

    int roll, i, s, index;
    int hits, stars;
    double expected;
    double share, error;

    expected = (double)ROLLS / FACES;  // 각 눈의 기대 횟수 계산

    srand((unsigned)time(NULL));  // 현재 시간을 이용한 난수 초기화

    // 주사위를 ROLLS 횟수만큼 던지는 반복문
    for (roll = 0; roll < ROLLS; roll++) {
        index = rand() % FACES;  // 0~5 사이의 난수 생성
        count[index]++;          // 해당 눈의 횟수 증가
    }

    // 전체 시뮬레이션 결과 출력
    printf("Dice rolls: %d\n", ROLLS);
    printf("Expected per face: %.1f\n", expected);
    printf("Face   Count   Share(%%)   Error(%%)   Histogram\n");

    // 각 눈의 통계와 히스토그램 출력
    for (i = 0; i < FACES; i++) {

        hits = *(p + i);  // 포인터를 이용하여 배열 원소 접근

        share = 100.0 * hits / ROLLS;  // 각 눈의 출현 비율 계산
        error = 100.0 * (hits - expected) / expected;  // 오차 계산

        stars = hits / STAR_UNIT;  // 출력할 별의 개수 계산

        printf("%4d %7d %10.2f %+10.2f   ",
            i + 1, hits, share, error);

        // 계산된 개수만큼 별 출력
        for (s = 0; s < stars; s++) {
            putchar('*');
        }

        putchar('\n');
    }

    return 0;
}