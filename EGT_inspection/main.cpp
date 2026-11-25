#include <stdio.h>

#define NUM_ENGINES 3        // 점검 대상 엔진 수 
#define NUM_SAMPLES 5        // 엔진당 EGT 측정 샘플 수 
#define INITIAL_INDEX 0      // 배열 시작 인덱스 
#define FIRST_SAMPLE_NUM 1   // 출력용 첫 번째 측정 회차 번호(#1) 
#define SORT_TEMP_ZERO 0.0   // 최대 변동폭 초기값

// 원본 배열 순서를 유지하기 위해 복사본을 만든 뒤 오름차순 정렬하는 함수
void Sorting(const double* src, double* sortedOut, int n)
{
    int i, j;
    double temp;

    for (i = INITIAL_INDEX; i < n; i++)
    {
        sortedOut[i] = src[i];
    }

    // 버블 정렬 (오름차순)
    for (i = INITIAL_INDEX; i < n - 1; i++)
    {
        for (j = INITIAL_INDEX; j < n - i - 1; j++)
        {
            if (sortedOut[j] > sortedOut[j + 1])
            {
                temp = sortedOut[j];
                sortedOut[j] = sortedOut[j + 1];
                sortedOut[j + 1] = temp;
            }
        }
    }
}

int main(void)
{
    // 엔진별 EGT 측정값 배열(단위: 섭씨)
    double dArrEngATemp[NUM_SAMPLES] = { 612.5, 618.0, 615.3, 620.1, 616.4 };
    double dArrEngBTemp[NUM_SAMPLES] = { 605.2, 640.8, 598.7, 652.3, 610.0 };
    double dArrEngCTemp[NUM_SAMPLES] = { 630.0, 628.4, 633.9, 631.2, 629.5 };

    // 1차원 배열 3개를 가리키는 포인터 배열
    double* dEgt[NUM_ENGINES] = { dArrEngATemp, dArrEngBTemp, dArrEngCTemp };
    const char* stringName[NUM_ENGINES] = { "ENG-A", "ENG-B", "ENG-C" };

    double sortedTemp[NUM_SAMPLES]; // 정렬 결과를 저장할 임시 배열 
    double minVal, maxVal, rangeVal;
    int maxRangeIdx = INITIAL_INDEX;       // 변동폭이 가장 큰 엔진의 인덱스
    double maxRangeVal = SORT_TEMP_ZERO;   // 가장 큰 변동폭 값

    // 표 출력
    printf("%-6s", "Engine");
    for (int j = INITIAL_INDEX; j < NUM_SAMPLES; j++)
    {
        char label[8];
        snprintf(label, sizeof(label), "#%d", j + FIRST_SAMPLE_NUM);
        printf(" %6s", label);
    }
    printf(" | %6s  %6s  %5s\n", "Min", "Max", "Range");

    // 엔진별 측정값 출력 및 최소값, 최대값, 변동폭 계산
    for (int i = INITIAL_INDEX; i < NUM_ENGINES; i++)
    {
        printf("%-6s", stringName[i]);
        for (int j = INITIAL_INDEX; j < NUM_SAMPLES; j++)
        {
            printf(" %6.1f", dEgt[i][j]);
        }

        Sorting(dEgt[i], sortedTemp, NUM_SAMPLES);
        minVal = sortedTemp[INITIAL_INDEX];     // 정렬 후 첫 번째 원소가 최소값
        maxVal = sortedTemp[NUM_SAMPLES - 1];   // 정렬 후 마지막 원소가 최대값
        rangeVal = maxVal - minVal;             // 변동폭 계산

        printf(" | %6.1f  %6.1f  %5.1f\n", minVal, maxVal, rangeVal);

        // 현재 엔진의 변동폭이 기존 최대 변동폭보다 크면 갱신
        if (i == INITIAL_INDEX || rangeVal > maxRangeVal)
        {
            maxRangeVal = rangeVal;
            maxRangeIdx = i;
        }
    }

    // 변동폭이 가장 큰 엔진 이름과 값 출력
    printf("\nLargest variation : %s (%.1f deg C)\n", stringName[maxRangeIdx], maxRangeVal);

    return INITIAL_INDEX;
}