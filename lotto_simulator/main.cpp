#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PICKS 6          // 로또 번호의 개수
#define MAX_NUM 45       // 로또 번호의 최댓값

// 배열에 특정 번호가 이미 존재하는지 확인하는 함수
int contains(int arr[], int size, int number)
{
    int i;

    for (i = 0; i < size; i++)
    {
        if (arr[i] == number)
        {
            return 1;
        }
    }

    return 0;
}

// 서로 다른 당첨 번호 6개를 생성하는 함수
void generate_lotto(int lotto[])
{
    int i;
    int candidate;

    for (i = 0; i < PICKS; i++)
    {
        do
        {
            candidate = rand() % MAX_NUM + 1;
        } while (contains(lotto, i, candidate));

        lotto[i] = candidate;
    }
}

// 당첨 번호와 겹치지 않는 보너스 번호를 생성하는 함수
int generate_bonus(int lotto[])
{
    int bonus;

    do
    {
        bonus = rand() % MAX_NUM + 1;
    } while (contains(lotto, PICKS, bonus));

    return bonus;
}

// 포인터를 이용하여 버블 정렬을 수행하는 함수
void bubble_sort(int lotto[])
{
    int i, j;
    int temp;
    int* pa, * pb;

    for (i = 0; i < PICKS - 1; i++)
    {
        for (j = 0; j < PICKS - 1 - i; j++)
        {
            pa = &lotto[j];
            pb = &lotto[j + 1];

            if (*pa > *pb)
            {
                temp = *pa;
                *pa = *pb;
                *pb = temp;
            }
        }
    }
}

// 사용자에게 서로 다른 번호 6개를 입력받는 함수
int input_numbers(int user[])
{
    int i;

    printf("Enter 6 different numbers between 1 and 45.\n\n");

    for (i = 0; i < PICKS; i++)
    {
        while (1)
        {
            printf("Number %d: ", i + 1);

            if (scanf_s("%d", &user[i]) != 1)
            {
                printf("Invalid input. Please enter an integer.\n");
                return 0;
            }

            // 입력한 번호가 1~45 범위인지 확인
            if (user[i] < 1 || user[i] > MAX_NUM)
            {
                printf("Out of range. Please try again.\n\n");
                continue;
            }

            // 이미 입력한 번호인지 확인
            if (contains(user, i, user[i]))
            {
                printf("Duplicate number. Please try again.\n\n");
                continue;
            }

            break;
        }
    }

    return 1;
}

// 일치 개수와 보너스 번호 여부에 따라 등수를 판정하는 함수
int get_rank(int count, int bonus_match)
{
    if (count == 6)
    {
        return 1;
    }
    else if (count == 5 && bonus_match == 1)
    {
        return 2;
    }
    else if (count == 5)
    {
        return 3;
    }
    else if (count == 4)
    {
        return 4;
    }
    else if (count == 3)
    {
        return 5;
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    int lotto[PICKS];
    int user[PICKS];
    int bonus;
    int count = 0;
    int bonus_match = 0;
    int rank;
    int i, j;

    int* p;

    // 난수 초기화
    srand((unsigned int)time(NULL));

    // 당첨 번호와 보너스 번호 생성
    generate_lotto(lotto);
    bonus = generate_bonus(lotto);

    // 당첨 번호를 오름차순으로 정렬
    bubble_sort(lotto);

    // 사용자 번호 입력
    if (input_numbers(user) == 0)
    {
        return 1;
    }

    // 사용자 번호와 당첨 번호 비교
    for (i = 0; i < PICKS; i++)
    {
        for (j = 0; j < PICKS; j++)
        {
            if (user[i] == lotto[j])
            {
                count++;
                break;
            }
        }

        // 보너스 번호 일치 여부 확인
        if (user[i] == bonus)
        {
            bonus_match = 1;
        }
    }

    // 등수 판정
    rank = get_rank(count, bonus_match);

    // 포인터를 이용하여 당첨 번호 출력
    printf("\nWinning Numbers: ");

    for (p = lotto; p < lotto + PICKS; p++)
    {
        printf("%4d", *p);
    }

    printf("   + Bonus %d\n", bonus);

    // 일치 개수 출력
    printf("\nMatching Numbers: %d\n", count);

    // 결과 출력
    if (rank == 0)
    {
        printf("Result: No Prize\n");
    }
    else
    {
        printf("Result: %d Prize\n", rank);
    }

    return 0;
}