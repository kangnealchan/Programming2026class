#include <stdio.h>

// 각 상품의 원래 가격을 #define 상수로 정의
#define PRICE_RED_POTION 1000
#define PRICE_MAGIC_SCROLL 2000
#define PRICE_ELIXIR 3000

// 메뉴 번호 정의
#define MENU_RED_POTION 1
#define MENU_MAGIC_SCROLL 2
#define MENU_ELIXIR 3
#define MENU_EXIT 0

#define DISCOUNT_RATE 2     // 50% 할인을 위한 나누기 값
#define BLESSING_CYCLE 3    // 도깨비의 축복이 내리는 구매 횟수 주기
#define MIN_BALANCE 0       // 최소 잔액 기준 값

int main(void)
{
    int balance;            // 사용자의 현재 잔액
    int choice;             // 사용자가 선택한 메뉴 번호
    int purchase_count = 0; // 물건을 구매한 횟수를 카운트할 변수
    int item_price = 0;     // 선택한 상품의 가격을 담을 변수
    const char* item_name = ""; // 선택된 상품 이름을 담을 변수

    // 초기 코인(잔액) 입력 받기
    printf("Insert coins (Current Balance): ");

    // [예외 처리] scanf_s 반환값 확인
    if (scanf_s("%d", &balance) != 1)
    {
        printf("[Error] Invalid input. Please enter numbers only.\n");
        return 0;
    }

    // [예외 처리] 잔액이 음수인 경우 방어
    if (balance < MIN_BALANCE)
    {
        printf("[Error] Initial balance cannot be negative. Please restart the program.\n");
        return 0;
    }

    // 무한 루프를 사용하여 메뉴 제공 및 구매 진행
    while (1)
    {
        // 자판기 메뉴판 출력
        printf("\n--- Goblin's Vending Machine ---\n");
        printf("1. Red Potion (%d G)\n", PRICE_RED_POTION);
        printf("2. Magic Scroll (%d G)\n", PRICE_MAGIC_SCROLL);
        printf("3. Elixir (%d G)\n", PRICE_ELIXIR);
        printf("0. Exit\n");
        printf("-----------------------------------\n");
        printf("Select an item: ");

        // [예외 처리] scanf_s 반환값 확인
        if (scanf_s("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter numbers only.\n");
            // 버퍼 비우기
            while (getchar() != '\n');
            continue;
        }

        // 프로그램 종료 조건 (0번 선택 시)
        if (choice == MENU_EXIT)
        {
            printf("Returning %d G. Goodbye!\n", balance);
            break;
        }

        // 선택한 메뉴에 따른 원래 가격 설정
        switch (choice)
        {
        case MENU_RED_POTION:
            item_price = PRICE_RED_POTION;
            item_name = "Red Potion";
            break;

        case MENU_MAGIC_SCROLL:
            item_price = PRICE_MAGIC_SCROLL;
            item_name = "Magic Scroll";
            break;

        case MENU_ELIXIR:
            item_price = PRICE_ELIXIR;
            item_name = "Elixir";
            break;

        default:
            printf("Invalid selection. Please choose again.\n");
            continue; // 잘못된 번호 입력 시 다시 메뉴로 돌아감
        }

        // 이번 구매가 3번째(축복 주기)인지 임시 계산하여 실제 적용 금액 파악
        int next_purchase_count = purchase_count + 1;
        int actual_price = item_price;

        if (next_purchase_count % BLESSING_CYCLE == 0)
        {
            actual_price = item_price / DISCOUNT_RATE; // 50% 할인 가격
        }

        // [예외 처리] 잔액 부족 여부를 축복 메시지 출력 전에 미리 확인
        if (balance < actual_price)
        {
            printf("Not enough balance!\n");
            continue;
        }

        // 잔액이 충분할 때 구매 카운트 증가 및 축복 메시지 출력
        purchase_count = next_purchase_count;

        if (purchase_count % BLESSING_CYCLE == 0)
        {
            printf("*** GOBLIN'S BLESSING! 50% DISCOUNT! ***\n");
        }

        // 구매 처리 (잔액 차감)
        balance -= actual_price;

        // 구매 결과 출력 (통합 처리로 중복 제거)
        if (purchase_count % BLESSING_CYCLE == 0)
        {
            printf("[Purchased] %s for %d G. Balance: %d G\n", item_name, actual_price, balance);
        }
        else
        {
            printf("[Purchased] %s. Balance: %d G\n", item_name, balance);
        }
    }

    return 0;
}