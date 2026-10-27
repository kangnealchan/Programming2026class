#include <stdio.h>

// 매크로 상수 정의
#define DIVISOR 10          // 자릿수를 분리하기 위한 기준 값
#define LIMIT 9             // 한 자리 숫자가 될 때까지 반복하기 위한 기준 값
#define MIN_DATE 10000000   // 8자리 생년월일 최소값 (예: 1000년 01월 01일)
#define MAX_DATE 99991231   // 8자리 생년월일 최대값 (예: 9999년 12월 31일)

int main(void) 
{
    int birthdate;          // 사용자가 입력할 8자리 생년월일 저장 변수
    int sum = 0;            // 자릿수의 합을 저장할 변수
    int temp;               // 자릿수 연산을 위해 값을 임시로 담아둘 변수
    int year, month, day;   // 년, 월, 일 유효성 검사용 변수

    // 사용자로부터 8자리 생년월일 입력 받기
    printf("Enter your 8-digit birthdate (YYYYMMDD): ");
    
    // [예외 처리] scanf_s 반환값 확인
    if (scanf_s("%d", &birthdate) != 1) 
    {
        printf("[Error] Invalid input. Please enter numbers only.\n");
        return 0;
    }

    // [예외 처리] 8자리 범위(년, 월, 일)를 벗어난 숫자가 입력된 경우 방어
    if (birthdate < MIN_DATE || birthdate > MAX_DATE) 
    {
        printf("[Error] Please enter a valid 8-digit positive birthdate (e.g., 20041225).\n");
        return 0; // 프로그램 안전 종료
    }

    // [예외 처리] 월·일 유효성 검사
    year = birthdate / 10000;
    month = (birthdate % 10000) / 100;
    day = birthdate % 100;

    if (month < 1 || month > 12) 
    {
        printf("[Error] Invalid month. Month must be between 1 and 12.\n");
        return 0;
    }

    if (day < 1 || day > 31) 
    {
        printf("[Error] Invalid day. Day must be between 1 and 31.\n");
        return 0;
    }

    // 2월, 4월, 6월, 9월, 11월 등 월별 최대 일수 유효성 확인
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) 
    {
        printf("[Error] Invalid day for the given month.\n");
        return 0;
    }
    if (month == 2 && day > 29) 
    {
        printf("[Error] Invalid day for February.\n");
        return 0;
    }

    printf("Calculating...\n");

    // 입력받은 생년월일의 각 자리 숫자 합 구하기
    temp = birthdate;
    while (temp > 0) 
    {
        sum += temp % DIVISOR;  // 가장 끝자리를 추출하여 sum에 누적
        temp /= DIVISOR;        // 계산이 끝난 끝자리를 제거
    }
    printf("Sum of digits: %d\n", sum);

    // 합이 한 자리 숫자(1~9)가 될 때까지 반복하여 더하기
    while (sum > LIMIT) 
    {
        temp = sum;
        sum = 0;              // 새로운 자릿수 합을 구하기 위해 0으로 초기화
        while (temp > 0) 
        {
            sum += temp % DIVISOR;
            temp /= DIVISOR;
        }
        printf("Sum of digits: %d\n", sum);
    }

    // 최종 운명의 숫자 출력
    printf("Your Destiny Number is %d!\n", sum);
    printf("[Destiny Message]\n");

    switch (sum)
    {
    case 1: printf("You are a natural-born leader and pioneer!\n");
        break;

    case 2: printf("You are a peaceful mediator and a great listener.\n");
        break;

    case 3: printf("You have a creative soul and infinite imagination!\n");
        break;

    case 4: printf("You are a hardworking and reliable builder.\n");
        break;

    case 5: printf("You love freedom and adventurous journeys!\n");
        break;

    case 6: printf("You are a warm-hearted protector of your loved ones.\n");
        break;

    case 7: printf("You are an analytical thinker and a seeker of truth!\n");
        break;

    case 8: printf("You are destined for great success and abundance!\n");
        break;

    case 9: printf("You have a compassionate heart and a global perspective.\n");
        break;

    default: printf("Error: Invalid destiny number.\n");
        break;
    }

    return 0;
}