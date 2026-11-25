#include <stdio.h>
#include <math.h>

#define CABLES 4 // 케이블의 개수

// 케이블 이름
const char* cableNames[CABLES] =
{
    "Cable-1",
    "Cable-2",
    "Cable-3",
    "Cable-4"
};

// 각각의 케이블에 작용하는 힘
double cableForces[CABLES][3] =
{
    { 120.0,  50.0,  -30.0 }, // Cable-1
    { -80.0, 140.0,   60.0 }, // Cable-2
    { 45.0, -95.0,  110.0 }, // Cable-3
    { -60.0, -70.0, -150.0 }  // Cable-4
};

// 힘의 크기 계산 함수
double calculate(double* force)
{
    return sqrt(
        force[0] * force[0] +
        force[1] * force[1] +
        force[2] * force[2]
    );
}

// 가장 큰 힘을 가진 케이블 찾기
int findLargest(void)
{
    int index[CABLES] = { 0, 1, 2, 3 };
    int i, j, temp;

    // 버블 정렬 (내림차순)
    for (i = 0; i < CABLES - 1; i++)
    {
        for (j = 0; j < CABLES - i - 1; j++)
        {
            if (calculate(cableForces[index[j]]) <
                calculate(cableForces[index[j + 1]]))
            {
                temp = index[j];
                index[j] = index[j + 1];
                index[j + 1] = temp;
            }
        }
    }

    return index[0];
}

int main(void)
{
    int i, largestIndex;

    double result[3] = { 0.0, 0.0, 0.0 };

    printf("%-9s %8s %8s %8s | %8s\n",
        "Force", "F_x", "F_y", "F_z", "     |F|  [N]");

    // 각 케이블에 작용하는 힘 계산
    for (i = 0; i < CABLES; i++)
    {
        double* force = cableForces[i];

        // 각 방향의 힘 성분 합산
        result[0] += force[0];
        result[1] += force[1];
        result[2] += force[2];

        // 각 케이블의 정보 출력
        printf("%-9.9s %8.1f %8.1f %8.1f | %8.1f\n",
            cableNames[i],
            force[0],
            force[1],
            force[2],
            calculate(force));
    }

    // 전체 합력 출력
    printf("%-9s %8.1f %8.1f %8.1f | %8.1f\n",
        "Resultant",
        result[0],
        result[1],
        result[2],
        calculate(result));

    // 가장 큰 힘을 가진 케이블 찾기
    largestIndex = findLargest();

    printf("\nLargest force : %s (%.1f N)\n",
        cableNames[largestIndex],
        calculate(cableForces[largestIndex]));

    return 0;
}