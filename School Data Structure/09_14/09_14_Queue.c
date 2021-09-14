// 큐 구현
// FIFO, front, back, Enqueue, Dequeue
#include <stdio.h>

int queue[5]; // 큐 배열 생성

void menuf() {  // 메뉴 함수 function
    // 그저 메뉴
    printf("\n 1. 큐에 삽입 2. 큐에서 삭제\n");
    printf("3. 내용 보기 4. 종료\n");
}

// 넣는 값이 item
void Enqueue(int* back, int item) {     // 큐에 삽입
    if (*back == 4) {
        printf("큐가 가득참\n");
        return;
    } // 인덱스가 4가 최대라서
    queue[++ * back] = item; // 인덱스에서의 back이 +1하면서 큐의 끝을 가리키며 큐에 값 추가
    // ++가 앞에 있는 이유는 현재 back 값보다 1큰 값에 item값을 넣어야 한다.
    
}

int Dequeue(int* front, int back) { // 큐에서 빼기
    if(*front == back) {    // 끝과 시작이 같다는 것은 값이 없다.
        return -1;  // -1이면 큐가 비었다고 생각
        // 보통 0이 리턴되면 정상적인 종료
    }
    return queue[++ * front];   // 인덱스에서의 front가 +1하면서 큐의 처음을 가리키며 값 빼기
}

void Display(int front, int back) {
    if(front == back)
        printf("큐가 비었음\n");
    for (int i = front + 1; i <= back; i++) // front에 + 1을 붙인 이유는? front가
        // -1로 인덱스의 시작 0보다 1이 작은 값으로 되어있기 때문에
        printf("%4d", queue[i]);
}

int main() {
    //큐, 스택 모두 1차원 배열로 구현
    int front = -1, back = -1;
    // queue : front, back, stack : top
    int menu, item;
    while (1) {
        menuf();
        scanf("%d", &menu);
        switch (menu) {
            case 1:     // 큐에 데이터 또는 job 삽입
                printf("값을 입력 : ");
                scanf("%d", &item);
                Enqueue(&back, item);
                break;
            case 2:
                item = Dequeue(&front, back);
                if (item == -1)
                    printf("큐가 비었음");
                else
                    printf("%d가 삭제됨\n", item);
                break;
            case 3:
                Display(front, back);   //과제
                // 큐의 내용을 출력해 보시오
                break;
            case 4:
                return 0;
            default:
                printf("다시 입력하세요.\n");
        }
    }
}
