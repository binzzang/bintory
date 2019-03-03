#pragma warning(disable :4996)
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct d_node { //노드 구조체
	int n;
	struct d_node *next; //다음노드정보
	struct d_node *prev; //이전노드정보
}NODE;

typedef struct d_list { //이중 링크드 리스트 관리 구조체
	NODE *head;
	NODE *curr;
	NODE *curr2;
	NODE *tail;
}D_LIST;

typedef D_LIST LIST;

int list_cnt(LIST *list);											 //총 노드 개수 리턴
void list_insert_head(LIST *list, int data);					     //리스트 시작에 노드 삽입
void list_insert_tail(LIST *list, int data);						 //리스트 끝에 노드 삽입							
void list_insert_index(LIST *list, int data, int index);			 //인덱스 위치에 노드 삽입
void list_delete_head(LIST *list);									 //리스트 시작에 대한 노드 삭제
void list_delete_tail(LIST *list);									 //리스트 끝에 대한 노드 삭제
void list_delete_data(LIST *list, int data);						 //데이터에 대한 노드 삭제
void list_delete_index(LIST *list, int index);						 //인덱스에 대한 노드 삭제
void list_search_index(LIST *list, int index);						 //인덱스에 대한 노드 검색
void list_search_data(LIST *list, int data);						 //데이터에 대한 노드 검색
void list_clear(LIST * list);										 //리스트 전체 삭제
void list_copy(LIST *list, LIST *copy_list);						 //리스트 복사
void list_sort_asc(LIST *list);										 //오름차순 정렬
void list_sort_dec(LIST *list);										 //내림차순 정렬
void print_list(LIST *list);

int main() {
	LIST *list = (LIST *)malloc(sizeof(LIST));
	LIST *copy_list = (LIST *)malloc(sizeof(LIST));
	int ch, ch2, data, index, cnt;
	
	int temp;

	list->head = list->tail = NULL;

	while (1) {
		printf("\n\n====================================================\n");
		printf("\t\tDouble Linked List Program\n\n");
		printf("1.  총 노드 개수\n");
		printf("2.  노드 삽입\n");
		printf("3.  노드 삭제\n");
		printf("4.  노드 검색\n");
		printf("5.  리스트 전체 삭제\n");
		printf("6.  리스트 카피\n");
		printf("7.  오름차순 정렬\n");
		printf("8.  내림차순 정렬\n");
		printf("9.  리스트 보기\n");
		printf("10. 종료\n");
		printf("====================================================\n");
		
		scanf("%d", &ch);
		switch (ch) {
		case 1:
			cnt = list_cnt(list);
			printf("\n총 %d개", cnt);
			break;
		case 2: // 노드 삽입
			printf("====================================================\n");
			printf("1. 리스트 시작에 노드 삽입\n");
			printf("2. 리스트 끝에 노드 삽입\n");
			printf("====================================================\n");
			scanf("%d", &ch2);
			if (ch2 == 1) {
				printf("삽입할 노드를 입력 해 주세요. : ");
				scanf("%d", &data);
				list_insert_head(list, data);
			}
			else if(ch2 == 2){
				printf("삽입할 노드를 입력 해 주세요. : ");
				scanf("%d", &data);
				list_insert_tail(list, data);
			}
			else if (ch2 == 3) {
				printf("삽입할 데이터와 인덱스를 입력 해 주세요. \n ");
				printf("데이터 : ");
				scanf("%d", &data);
				printf(" 인덱스 : ");
				scanf("%d", &index);
				list_insert_index(list, data, index);
			}
			break;
		case 3: // 노드 삭제
			printf("====================================================\n");
			printf("1. 리스트 시작에 대한 노드 삭제\n");
			printf("2. 리스트 끝에 대한 노드 삭제\n");
			printf("3. 데이터에 대한 노드 삭제\n");
			printf("4. 인덱스에 대한 노드 삭제\n");
			printf("====================================================\n");
			scanf("%d", &ch2);
			if (ch2 == 1) {
				list_delete_head(list);
			}
			else if (ch2 == 2) {
				list_delete_tail(list);
			}
			else if (ch2 == 3) {
				printf("삭제할 데이터를 입력 해 주세요. : ");
				scanf("%d", &data);
				list_delete_data(list, data);
			}
			else if (ch2 == 4) {
				printf("삭제할 인덱스를 입력 해 주세요. : ");
				scanf("%d", &index);
				list_delete_index(list, index);
			}
			break;
		case 4: // 노드 검색
			printf("====================================================\n");
			printf("1. 데이터에 대한 노드 검색\n");
			printf("4. 인덱스에 대한 노드 검색\n");
			printf("====================================================\n");
			scanf("%d", &ch2);
			if (ch2 == 1) {
				printf("검색할 노드의 인덱스를 입력 해 주세요. : ");
				scanf("%d", &index);
				list_search_index(list, index);
			}
			else if (ch2 == 2) {
				printf("검색할 값을 입력 해 주세요. : ");
				scanf("%d", &data);
				list_search_data(list, data);
			}
			break;
		case 5:
			list_clear(list);
			break;
		case 6:
			list_copy(list, copy_list);
			break;
		case 7:
			list_sort_asc(list);
			break;
		case 8:
			list_sort_dec(list);
			break;
		case 9:
			print_list(list);
			break;
		case 10:
			exit(0);
			break;
		}
	}
	printf("프로그램 종료.");
	return 0;
}

//리스트보기
void print_list(LIST *list) {
	int cnt;
	cnt = list_cnt(list);

	list->curr = list->head; // 현재포인터와 헤드의 위치를 맞춰줌
	if (cnt == 0) {
		printf("리스트가 없습니다.\n");
	}else {
		list->curr = list->head; // 현재포인터와 헤드의 위치를 맞춰줌
		printf("\n");
		while (list->curr != NULL) {
			printf(" %d  ", list->curr->n);
			list->curr = list->curr->next; // 다음 포인터를 가르키도록
		}
	}
}

//총 노드 개수 리턴
int list_cnt(LIST *list) {
	int cnt;
	if (list->head == NULL) {
		cnt = 0;
	}
	else {
		cnt = 0;
		list->curr = list->head; // 현재포인터와 헤드의 위치를 맞춰줌
		while (list->curr != NULL) {
			cnt++;
			list->curr = list->curr->next; // 다음 포인터를 가르키도록
		}
	}
	return cnt;
}

//리스트 앞에 노드 삽입
void list_insert_head(LIST *list, int data) {
	NODE *new_node = (NODE *)malloc(sizeof(NODE)); // 새로운 노드 위한 동적할당
	new_node->n = data; // 삽입할 데이터 할당된 위치에 저장
	
	if (list->head == NULL) { // 리스트가 없을 경우
		list->head = new_node; // 새 노드가 헤드
		list->tail = new_node; // 새 노드가 테일
		new_node->prev = NULL; // 맨앞은 NULL을 가르킴
		new_node->next = NULL; // 맨뒤는 NULL을 가르킴
	}
	else {
		list->head->prev = new_node; // 리스트앞 노드 삽입이기 때문에 헤드앞에 새로운 노드를 넣어줌
		new_node->next = list->head; // 새로운 노드 뒤는 헤드
		list->head = new_node; // 헤드는 다시 새로운 노드로 
	}
	new_node->prev = NULL; // 맨앞은 NULL을 가르키도록
}

//리스트 끝에 노드 삽입
void list_insert_tail(LIST *list, int data) {
	NODE *new_node = (NODE *)malloc(sizeof(NODE)); 
	new_node->n = data;

	if (list->head == NULL) { // 리스트가 없을 경우
		list->head = new_node; // 새 노드가 헤드
		list->tail = new_node; // 새 노드가 테일
		new_node->prev = NULL; // 맨앞은 NULL을 가르킴
		new_node->next = NULL; // 맨뒤는 NULL을 가르킴
	}
	else {
		list->tail->next = new_node; // 테일 다음노드가 새로운 노드
		new_node->prev = list->tail; // 새로운 노드 전 노드가 테일
		list->tail = new_node; // 새로운 노드는 테일
		new_node->next = NULL; // 새로운 노드 뒤는 NULL
	}
}

//인덱스 위치에 노드삽입
void list_insert_index(LIST *list, int data, int index) {
	NODE *new_node = (NODE *)malloc(sizeof(NODE));
	int cnt = 0; // 총 노드 개수를 담는 변수
	cnt = list_cnt(list); 
	new_node->n = data; // 삽입을 데이터를 동적할당 받은 위치에 저장

	if (list->head==NULL) {
		printf("리스트가 없습니다.\n");
	}
	else {
		list->curr = list->head; //탐색할 포인터를 head로 갖다놓음 (시작점으로)

		if (index == 1) { //헤드에 삽입일때
			new_node->next = list->head;
			list->head->prev = new_node;
			list->head = new_node;
			new_node->prev = NULL;
		}else if (index <= cnt) { //인덱스가 총노드수보다 작을때
			for (int i = 1; i < index; i++) { //인덱스만큼 포인터위치를 이동
				list->curr = list->curr->next; // 현재포인터가 다음으로 이동
			}
			list->curr->prev->next = new_node; // 현재 전 노드 다음노드가 새로운 노드
			new_node->next = list->curr; // 새 노드의 다음 노드가 현재노드
			new_node->prev = list->curr->prev; // 새 노드의 prev노드는 현재노드의 prev
			list->curr->prev = new_node; // 현재노드의 전 노드는 새로운 노드
		}else {
			printf("그만큼의 리스트가 없습니다.\n");
		}
	}
}

//리스트 시작에 대한 노드 삭제
void list_delete_head(LIST *list) {
	NODE *temp;
	int cnt;

	cnt = list_cnt(list);
	if (cnt == 0) { 		
		printf("리스트가 없습니다.\n");
	}
	else if(cnt==1){ //노드가 헤드 혼자일경우
		free(list->head); // 헤드 노드 동적해제
		list->head = NULL; // 헤드 포인터 NULL
		list->tail = NULL; // 테일 포인터 NULL
	}
	else {
		temp = list->head; //헤드노드를 임시저장
		list->head= list->head->next; //헤드다음노드를 헤드로 설정
		list->head->prev = NULL; // 맨앞은 NULL
		free(temp); // 임시저장한 노드 동적해제 (헤드노드)
	}
}

//리스트 끝에 대한 노드 삭제
void list_delete_tail(LIST *list) {
	NODE *temp;
	int cnt;

	cnt = list_cnt(list);
	if (cnt == 0) {
		printf("리스트가 없습니다.\n");
	}
	else if (cnt == 1) { //노드가 헤드 혼자일경우
		free(list->head);
		list->head = NULL;
		list->tail = NULL;
	}
	else {
		temp = list->tail; //테일노드를 임시저장
		list->tail = list->tail->prev; //테일 전 노드를 테일로 설정
		list->tail->next = NULL; // 맨 마지막은 NULL을 가리킴
		free(temp); // 마지막 노드 동적해제
	}
}

//데이터에 대한 노드 삭제
void list_delete_data(LIST *list, int data) {
	NODE *temp;
	int cnt=0, index_cnt=1,flag=0; 

	cnt = list_cnt(list);
	if (list->head == NULL) {
		printf("리스트가 없습니다.\n");
	}
	else {
		list->curr = list->head;
		while (list->curr != NULL) {
			flag = 0;
			if (data == list->curr->n) {
				printf("%d", list->curr->n);
				if (cnt==1) {		// 삭제하려는노드가 노드1개짜리일경우
					free(list->head);
					list->head = NULL;
					list->tail = NULL;
					break;
				}else {		// 리스트에서 삭제하려 할 때
					if (list->head->n == data && index_cnt==1) {		// 헤드노드 삭제
						temp = list->head; //  헤드노드를 임시저장
						list->head = list->head->next; // 헤드다음노드를 헤드로 설정
						list->head->prev = NULL;
						free(temp);
						list->curr = list->head; // 현재포인터가 다시 헤드를 가리키도록
						index_cnt = 0; 
						flag = 1; // 포인터가 다음으로 가지 않도록 하는 플래그
					}else if(list->tail->n == data && index_cnt==cnt-1){	// 테일노드 삭제
						temp = list->tail; // 테일노드를 임시저장
						list->tail = list->tail->prev; // 테일다음노드를 테일로 설정
						list->tail->next = NULL;
						free(temp);
						break;
					}else {		// 중간어디엔가 끼어있는 노드 삭제
						temp = list->curr; // 현재노드를 임시노드에 저장
						list->curr->prev->next = list->curr->next; // 현재의 prev노드의 다음이 현재바로 다음노드를 가리킴
						list->curr->next->prev = list->curr->prev; // 현재 다음노드가 현재 prev노드를 가리킴
						list->curr = list->curr->next; // 다음 포인터로 이동
						free(temp); // 데이터 동적 해제
						flag = 1; // 포인터가 다음으로 넘어가지 않도록
					}
				}
			}
			if(flag==0) list->curr = list->curr->next; // 다음으로 포인터 이동
			index_cnt++; // 포인터가 몇번째 인덱스를 가리키는지 알기위한 변수의 증가
		}
	}
}

//인덱스에 대한 노드 삭제
void list_delete_index(LIST *list, int index) {
	NODE *temp;
	int flag = 0;
	int cnt = 0;
	cnt = list_cnt(list);

	if (list->head == NULL) {
		printf("리스트가 없습니다.\n");
	}
	else {
		if (cnt==1 && index==1) {		//삭제하려는 노드가 헤드노드 (노드1개)
			free(list->head);
			list->head = NULL;
			list->tail = NULL;
		}
		else if(index >= 1 && index < cnt){ //1보다 크고 노드 수보다 같거나 적은 인덱스 (중간노드)
			list->curr = list->head;
			if (index != 1) {
				for (int i = 1; i < index; i++) {
					list->curr = list->curr->next;
				}
				list->curr->prev->next = list->curr->next; // 현재 노드의 prev노드가 현재노드의 다음노드를 가리킴
				list->curr->next->prev = list->curr->prev; // 현재노드의 다음노드가 현재노드의 prev를 가리킴
				free(list->curr); // 동적 해제
			}else {
				temp = list->head; //헤드노드를 임시저장
				list->head = list->head->next; //헤드다음노드를 헤드로 설정
				list->head->prev = NULL;
				free(temp);
			}
		}else if(index == cnt) {
			temp = list->tail; //헤드노드를 임시저장
			list->tail = list->tail->prev; //헤드다음노드를 헤드로 설정
			list->tail->next = NULL;
			free(temp);
		}else {
			printf("잘못된 인덱스 입니다.\n");
		}
	}
}

//인덱스에 대한 노드 검색
void list_search_index(LIST *list, int index) {

	if (list->head == NULL) {
		printf("리스트가 없습니다.\n");
	}else {
		list->curr = list->head;
		if (index == 1) {
			printf("1번째 노드 : %d", list->curr->n);
		}else {
			for (int i = 1; i < index; i++) {
				list->curr = list->curr->next;
			}
			printf("%d번째 노드 : %d", index, list->curr->n);
		}
	}
}

//데이터에 대한 노드 검색
void list_search_data(LIST *list, int data) {
	int cnt=0;

	if (list->head == NULL) {
		printf("리스트가 없습니다.\n");
	}else {
		list->curr = list->head;
		while (list->curr != NULL) {
			if (data == list->curr->n) { // 데이터가 현재 노드의 값과 같다면
				printf("%d번째 노드 : %d\n", cnt+1, data);
			}cnt++;
			list->curr = list->curr->next;
		}
		if (cnt == 0) {
			printf("그런 데이터는 없습니다.\n");
		}
	}
}

//리스트 전체 삭제
void list_clear(LIST *list) {
	// 시작노드 삭제 방식과 비슷하게 구현함
	NODE *temp;
	int cnt=0, flag=0;
	cnt = list_cnt(list);

	list->curr = list->head;

	if (cnt == 0) {
		printf("삭제할 리스트가 없습니다.\n");
	}else {
		while (1) {
			if (cnt == 1) { //노드가 헤드 혼자일경우
				free(list->head);
				list->head = NULL;
				list->tail = NULL;
			}else {
				temp = list->head; //헤드노드를 임시저장
				list->head = list->head->next; //헤드다음노드를 헤드로 설정
				list->head->prev = NULL;
				free(temp);
				list->curr = list->head;
			}
			cnt = list_cnt(list);
			if (cnt == 0) break;
		}
		printf("전체 리스트 삭제 완료.\n");
	}
}
//리스트 복사
void list_copy(LIST *list, LIST *copy_list) {
	int index_cnt=1, cnt=0;
	NODE *copy_node = (NODE *)malloc(sizeof(NODE));

	cnt = list_cnt(list);

	if (list->head == NULL) {
		printf("복사할 리스트가 없습니다.\n");
	}else {
		if (list_cnt(list) == 1) {		//헤드노드 하나일때
			copy_node->n = list->head->n; // 헤드 노드가 카피노드(새로 동적 할당)
			copy_list->head = copy_node;
			copy_list->tail = copy_node;
			copy_node->prev = NULL;
			copy_node->next = NULL;
		}
		else {		//노드개수가 여러개일때
			list->curr = list->head; // 현재노드와 헤드노드의 위치 맞춤

			copy_node->n = list->head->n; // 헤드 노드는 카피노드
			copy_list->head = copy_node; 
			copy_list->tail = copy_node;
			copy_node->prev = NULL;
			copy_node->next = NULL;
			copy_list->curr = copy_list->head; // 복사 리스트의 현재도 헤드를 가르키게
			while (1) {
				NODE *copy_node = (NODE *)malloc(sizeof(NODE)); // 그때 그때 동적할당
				list->curr = list->curr->next; // 다음 포인터를 가리키게
				copy_node->n = list->curr->n; // 현재 노드를 새로 할당받은 노드에 
				copy_list->curr->next = copy_node; // 복사리스트의 다음 노드는 카피노드
				copy_list->tail = copy_node; // 복사리스트의 테일은 카피노드
				copy_node->next = NULL; // 마지막은 NULL
				index_cnt++; // 몇번째 인덱스인지 확인하는 증가변수
				if (index_cnt == cnt) break; // 원본 리스트와 노드개수가 같으면 break
				copy_list->curr = copy_list->curr->next; // 복사리스트의 포인터를 다음으로 이동
			}
		}
		printf("\n복사한 리스트\n");
		print_list(copy_list);
	}
}

// 오름차순 정렬
void list_sort_asc(LIST *list) {
	int ch, cnt, temp;
	int start_time, end_time, t_data;
	LIST *left_list = (LIST *)malloc(sizeof(LIST));
	LIST *right_list = (LIST *)malloc(sizeof(LIST));
	NODE *copy_node = (NODE *)malloc(sizeof(NODE));
	cnt = list_cnt(list);

	printf("====================================================\n");
	printf("1. Exchange Sort\n");
	printf("2. Merge Sort\n");
	printf("3. Quick Sort\n");
	printf("====================================================\n");
	scanf("%d", &ch);

	if (ch == 1) {		// 교환정렬 (오름차순)
		start_time = GetTickCount(); //처음 시간
		printf("처음 : ");
		print_list(list);

		list->curr = list->head;
		list->curr2 = list->head;

		for (int i = 1; i < cnt; i++) { //curr
			for (int j = i; j < cnt; j++) { //curr2
				list->curr2 = list->curr2->next; // 포인터를 다음으로 이동
				if (list->curr2->n < list->curr->n) {
					temp = list->curr->n;
					list->curr->n = list->curr2->n;
					list->curr2->n = temp;
					print_list(list);
				}
			}list->curr = list->curr->next; // 포인터를 다음으로 이동
			list->curr2 = list->curr; // curr2를 curr위치로 맞춰줌
		}
		end_time = GetTickCount();
		t_data = end_time - start_time; // 끝나는시간
		printf("걸린시간 : %d", t_data); // 걸린시간
	}
	else if (ch == 2) {		 // Merge Sort

	}
	else if (ch == 3) {

	}
}
// 내림차순 정렬
void list_sort_dec(LIST *list) {
	int ch, cnt, temp;
	cnt = list_cnt(list);

	printf("====================================================\n");
	printf("1. Exchange Sort\n");
	printf("2. Merge Sort\n");
	printf("3. Quick Sort\n");
	printf("====================================================\n");
	scanf("%d", &ch);

	if (ch == 1) {		// 교환정렬 
		printf("처음 : ");
		print_list(list);

		list->curr = list->head;
		list->curr2 = list->head;

		for (int i = 1; i < cnt; i++) { //curr
			for (int j = i; j < cnt; j++) { //curr2
				list->curr2 = list->curr2->next;
				if (list->curr2->n > list->curr->n) {
					temp = list->curr->n;
					list->curr->n = list->curr2->n;
					list->curr2->n = temp;
					print_list(list);
				}
			}list->curr = list->curr->next;
			list->curr2 = list->curr;
		}
	}
	else if (ch == 2) {

	}
	else if (ch == 3) {

	}
}

