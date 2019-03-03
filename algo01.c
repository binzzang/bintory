#pragma warning(disable :4996)
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct d_node { //��� ����ü
	int n;
	struct d_node *next; //�����������
	struct d_node *prev; //�����������
}NODE;

typedef struct d_list { //���� ��ũ�� ����Ʈ ���� ����ü
	NODE *head;
	NODE *curr;
	NODE *curr2;
	NODE *tail;
}D_LIST;

typedef D_LIST LIST;

int list_cnt(LIST *list);											 //�� ��� ���� ����
void list_insert_head(LIST *list, int data);					     //����Ʈ ���ۿ� ��� ����
void list_insert_tail(LIST *list, int data);						 //����Ʈ ���� ��� ����							
void list_insert_index(LIST *list, int data, int index);			 //�ε��� ��ġ�� ��� ����
void list_delete_head(LIST *list);									 //����Ʈ ���ۿ� ���� ��� ����
void list_delete_tail(LIST *list);									 //����Ʈ ���� ���� ��� ����
void list_delete_data(LIST *list, int data);						 //�����Ϳ� ���� ��� ����
void list_delete_index(LIST *list, int index);						 //�ε����� ���� ��� ����
void list_search_index(LIST *list, int index);						 //�ε����� ���� ��� �˻�
void list_search_data(LIST *list, int data);						 //�����Ϳ� ���� ��� �˻�
void list_clear(LIST * list);										 //����Ʈ ��ü ����
void list_copy(LIST *list, LIST *copy_list);						 //����Ʈ ����
void list_sort_asc(LIST *list);										 //�������� ����
void list_sort_dec(LIST *list);										 //�������� ����
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
		printf("1.  �� ��� ����\n");
		printf("2.  ��� ����\n");
		printf("3.  ��� ����\n");
		printf("4.  ��� �˻�\n");
		printf("5.  ����Ʈ ��ü ����\n");
		printf("6.  ����Ʈ ī��\n");
		printf("7.  �������� ����\n");
		printf("8.  �������� ����\n");
		printf("9.  ����Ʈ ����\n");
		printf("10. ����\n");
		printf("====================================================\n");
		
		scanf("%d", &ch);
		switch (ch) {
		case 1:
			cnt = list_cnt(list);
			printf("\n�� %d��", cnt);
			break;
		case 2: // ��� ����
			printf("====================================================\n");
			printf("1. ����Ʈ ���ۿ� ��� ����\n");
			printf("2. ����Ʈ ���� ��� ����\n");
			printf("====================================================\n");
			scanf("%d", &ch2);
			if (ch2 == 1) {
				printf("������ ��带 �Է� �� �ּ���. : ");
				scanf("%d", &data);
				list_insert_head(list, data);
			}
			else if(ch2 == 2){
				printf("������ ��带 �Է� �� �ּ���. : ");
				scanf("%d", &data);
				list_insert_tail(list, data);
			}
			else if (ch2 == 3) {
				printf("������ �����Ϳ� �ε����� �Է� �� �ּ���. \n ");
				printf("������ : ");
				scanf("%d", &data);
				printf(" �ε��� : ");
				scanf("%d", &index);
				list_insert_index(list, data, index);
			}
			break;
		case 3: // ��� ����
			printf("====================================================\n");
			printf("1. ����Ʈ ���ۿ� ���� ��� ����\n");
			printf("2. ����Ʈ ���� ���� ��� ����\n");
			printf("3. �����Ϳ� ���� ��� ����\n");
			printf("4. �ε����� ���� ��� ����\n");
			printf("====================================================\n");
			scanf("%d", &ch2);
			if (ch2 == 1) {
				list_delete_head(list);
			}
			else if (ch2 == 2) {
				list_delete_tail(list);
			}
			else if (ch2 == 3) {
				printf("������ �����͸� �Է� �� �ּ���. : ");
				scanf("%d", &data);
				list_delete_data(list, data);
			}
			else if (ch2 == 4) {
				printf("������ �ε����� �Է� �� �ּ���. : ");
				scanf("%d", &index);
				list_delete_index(list, index);
			}
			break;
		case 4: // ��� �˻�
			printf("====================================================\n");
			printf("1. �����Ϳ� ���� ��� �˻�\n");
			printf("4. �ε����� ���� ��� �˻�\n");
			printf("====================================================\n");
			scanf("%d", &ch2);
			if (ch2 == 1) {
				printf("�˻��� ����� �ε����� �Է� �� �ּ���. : ");
				scanf("%d", &index);
				list_search_index(list, index);
			}
			else if (ch2 == 2) {
				printf("�˻��� ���� �Է� �� �ּ���. : ");
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
	printf("���α׷� ����.");
	return 0;
}

//����Ʈ����
void print_list(LIST *list) {
	int cnt;
	cnt = list_cnt(list);

	list->curr = list->head; // ���������Ϳ� ����� ��ġ�� ������
	if (cnt == 0) {
		printf("����Ʈ�� �����ϴ�.\n");
	}else {
		list->curr = list->head; // ���������Ϳ� ����� ��ġ�� ������
		printf("\n");
		while (list->curr != NULL) {
			printf(" %d  ", list->curr->n);
			list->curr = list->curr->next; // ���� �����͸� ����Ű����
		}
	}
}

//�� ��� ���� ����
int list_cnt(LIST *list) {
	int cnt;
	if (list->head == NULL) {
		cnt = 0;
	}
	else {
		cnt = 0;
		list->curr = list->head; // ���������Ϳ� ����� ��ġ�� ������
		while (list->curr != NULL) {
			cnt++;
			list->curr = list->curr->next; // ���� �����͸� ����Ű����
		}
	}
	return cnt;
}

//����Ʈ �տ� ��� ����
void list_insert_head(LIST *list, int data) {
	NODE *new_node = (NODE *)malloc(sizeof(NODE)); // ���ο� ��� ���� �����Ҵ�
	new_node->n = data; // ������ ������ �Ҵ�� ��ġ�� ����
	
	if (list->head == NULL) { // ����Ʈ�� ���� ���
		list->head = new_node; // �� ��尡 ���
		list->tail = new_node; // �� ��尡 ����
		new_node->prev = NULL; // �Ǿ��� NULL�� ����Ŵ
		new_node->next = NULL; // �ǵڴ� NULL�� ����Ŵ
	}
	else {
		list->head->prev = new_node; // ����Ʈ�� ��� �����̱� ������ ���տ� ���ο� ��带 �־���
		new_node->next = list->head; // ���ο� ��� �ڴ� ���
		list->head = new_node; // ���� �ٽ� ���ο� ���� 
	}
	new_node->prev = NULL; // �Ǿ��� NULL�� ����Ű����
}

//����Ʈ ���� ��� ����
void list_insert_tail(LIST *list, int data) {
	NODE *new_node = (NODE *)malloc(sizeof(NODE)); 
	new_node->n = data;

	if (list->head == NULL) { // ����Ʈ�� ���� ���
		list->head = new_node; // �� ��尡 ���
		list->tail = new_node; // �� ��尡 ����
		new_node->prev = NULL; // �Ǿ��� NULL�� ����Ŵ
		new_node->next = NULL; // �ǵڴ� NULL�� ����Ŵ
	}
	else {
		list->tail->next = new_node; // ���� ������尡 ���ο� ���
		new_node->prev = list->tail; // ���ο� ��� �� ��尡 ����
		list->tail = new_node; // ���ο� ���� ����
		new_node->next = NULL; // ���ο� ��� �ڴ� NULL
	}
}

//�ε��� ��ġ�� ������
void list_insert_index(LIST *list, int data, int index) {
	NODE *new_node = (NODE *)malloc(sizeof(NODE));
	int cnt = 0; // �� ��� ������ ��� ����
	cnt = list_cnt(list); 
	new_node->n = data; // ������ �����͸� �����Ҵ� ���� ��ġ�� ����

	if (list->head==NULL) {
		printf("����Ʈ�� �����ϴ�.\n");
	}
	else {
		list->curr = list->head; //Ž���� �����͸� head�� ���ٳ��� (����������)

		if (index == 1) { //��忡 �����϶�
			new_node->next = list->head;
			list->head->prev = new_node;
			list->head = new_node;
			new_node->prev = NULL;
		}else if (index <= cnt) { //�ε����� �ѳ������� ������
			for (int i = 1; i < index; i++) { //�ε�����ŭ ��������ġ�� �̵�
				list->curr = list->curr->next; // ���������Ͱ� �������� �̵�
			}
			list->curr->prev->next = new_node; // ���� �� ��� ������尡 ���ο� ���
			new_node->next = list->curr; // �� ����� ���� ��尡 ������
			new_node->prev = list->curr->prev; // �� ����� prev���� �������� prev
			list->curr->prev = new_node; // �������� �� ���� ���ο� ���
		}else {
			printf("�׸�ŭ�� ����Ʈ�� �����ϴ�.\n");
		}
	}
}

//����Ʈ ���ۿ� ���� ��� ����
void list_delete_head(LIST *list) {
	NODE *temp;
	int cnt;

	cnt = list_cnt(list);
	if (cnt == 0) { 		
		printf("����Ʈ�� �����ϴ�.\n");
	}
	else if(cnt==1){ //��尡 ��� ȥ���ϰ��
		free(list->head); // ��� ��� ��������
		list->head = NULL; // ��� ������ NULL
		list->tail = NULL; // ���� ������ NULL
	}
	else {
		temp = list->head; //����带 �ӽ�����
		list->head= list->head->next; //��������带 ���� ����
		list->head->prev = NULL; // �Ǿ��� NULL
		free(temp); // �ӽ������� ��� �������� (�����)
	}
}

//����Ʈ ���� ���� ��� ����
void list_delete_tail(LIST *list) {
	NODE *temp;
	int cnt;

	cnt = list_cnt(list);
	if (cnt == 0) {
		printf("����Ʈ�� �����ϴ�.\n");
	}
	else if (cnt == 1) { //��尡 ��� ȥ���ϰ��
		free(list->head);
		list->head = NULL;
		list->tail = NULL;
	}
	else {
		temp = list->tail; //���ϳ�带 �ӽ�����
		list->tail = list->tail->prev; //���� �� ��带 ���Ϸ� ����
		list->tail->next = NULL; // �� �������� NULL�� ����Ŵ
		free(temp); // ������ ��� ��������
	}
}

//�����Ϳ� ���� ��� ����
void list_delete_data(LIST *list, int data) {
	NODE *temp;
	int cnt=0, index_cnt=1,flag=0; 

	cnt = list_cnt(list);
	if (list->head == NULL) {
		printf("����Ʈ�� �����ϴ�.\n");
	}
	else {
		list->curr = list->head;
		while (list->curr != NULL) {
			flag = 0;
			if (data == list->curr->n) {
				printf("%d", list->curr->n);
				if (cnt==1) {		// �����Ϸ��³�尡 ���1��¥���ϰ��
					free(list->head);
					list->head = NULL;
					list->tail = NULL;
					break;
				}else {		// ����Ʈ���� �����Ϸ� �� ��
					if (list->head->n == data && index_cnt==1) {		// ����� ����
						temp = list->head; //  ����带 �ӽ�����
						list->head = list->head->next; // ��������带 ���� ����
						list->head->prev = NULL;
						free(temp);
						list->curr = list->head; // ���������Ͱ� �ٽ� ��带 ����Ű����
						index_cnt = 0; 
						flag = 1; // �����Ͱ� �������� ���� �ʵ��� �ϴ� �÷���
					}else if(list->tail->n == data && index_cnt==cnt-1){	// ���ϳ�� ����
						temp = list->tail; // ���ϳ�带 �ӽ�����
						list->tail = list->tail->prev; // ���ϴ�����带 ���Ϸ� ����
						list->tail->next = NULL;
						free(temp);
						break;
					}else {		// �߰���𿣰� �����ִ� ��� ����
						temp = list->curr; // �����带 �ӽó�忡 ����
						list->curr->prev->next = list->curr->next; // ������ prev����� ������ ����ٷ� ������带 ����Ŵ
						list->curr->next->prev = list->curr->prev; // ���� ������尡 ���� prev��带 ����Ŵ
						list->curr = list->curr->next; // ���� �����ͷ� �̵�
						free(temp); // ������ ���� ����
						flag = 1; // �����Ͱ� �������� �Ѿ�� �ʵ���
					}
				}
			}
			if(flag==0) list->curr = list->curr->next; // �������� ������ �̵�
			index_cnt++; // �����Ͱ� ���° �ε����� ����Ű���� �˱����� ������ ����
		}
	}
}

//�ε����� ���� ��� ����
void list_delete_index(LIST *list, int index) {
	NODE *temp;
	int flag = 0;
	int cnt = 0;
	cnt = list_cnt(list);

	if (list->head == NULL) {
		printf("����Ʈ�� �����ϴ�.\n");
	}
	else {
		if (cnt==1 && index==1) {		//�����Ϸ��� ��尡 ����� (���1��)
			free(list->head);
			list->head = NULL;
			list->tail = NULL;
		}
		else if(index >= 1 && index < cnt){ //1���� ũ�� ��� ������ ���ų� ���� �ε��� (�߰����)
			list->curr = list->head;
			if (index != 1) {
				for (int i = 1; i < index; i++) {
					list->curr = list->curr->next;
				}
				list->curr->prev->next = list->curr->next; // ���� ����� prev��尡 �������� ������带 ����Ŵ
				list->curr->next->prev = list->curr->prev; // �������� ������尡 �������� prev�� ����Ŵ
				free(list->curr); // ���� ����
			}else {
				temp = list->head; //����带 �ӽ�����
				list->head = list->head->next; //��������带 ���� ����
				list->head->prev = NULL;
				free(temp);
			}
		}else if(index == cnt) {
			temp = list->tail; //����带 �ӽ�����
			list->tail = list->tail->prev; //��������带 ���� ����
			list->tail->next = NULL;
			free(temp);
		}else {
			printf("�߸��� �ε��� �Դϴ�.\n");
		}
	}
}

//�ε����� ���� ��� �˻�
void list_search_index(LIST *list, int index) {

	if (list->head == NULL) {
		printf("����Ʈ�� �����ϴ�.\n");
	}else {
		list->curr = list->head;
		if (index == 1) {
			printf("1��° ��� : %d", list->curr->n);
		}else {
			for (int i = 1; i < index; i++) {
				list->curr = list->curr->next;
			}
			printf("%d��° ��� : %d", index, list->curr->n);
		}
	}
}

//�����Ϳ� ���� ��� �˻�
void list_search_data(LIST *list, int data) {
	int cnt=0;

	if (list->head == NULL) {
		printf("����Ʈ�� �����ϴ�.\n");
	}else {
		list->curr = list->head;
		while (list->curr != NULL) {
			if (data == list->curr->n) { // �����Ͱ� ���� ����� ���� ���ٸ�
				printf("%d��° ��� : %d\n", cnt+1, data);
			}cnt++;
			list->curr = list->curr->next;
		}
		if (cnt == 0) {
			printf("�׷� �����ʹ� �����ϴ�.\n");
		}
	}
}

//����Ʈ ��ü ����
void list_clear(LIST *list) {
	// ���۳�� ���� ��İ� ����ϰ� ������
	NODE *temp;
	int cnt=0, flag=0;
	cnt = list_cnt(list);

	list->curr = list->head;

	if (cnt == 0) {
		printf("������ ����Ʈ�� �����ϴ�.\n");
	}else {
		while (1) {
			if (cnt == 1) { //��尡 ��� ȥ���ϰ��
				free(list->head);
				list->head = NULL;
				list->tail = NULL;
			}else {
				temp = list->head; //����带 �ӽ�����
				list->head = list->head->next; //��������带 ���� ����
				list->head->prev = NULL;
				free(temp);
				list->curr = list->head;
			}
			cnt = list_cnt(list);
			if (cnt == 0) break;
		}
		printf("��ü ����Ʈ ���� �Ϸ�.\n");
	}
}
//����Ʈ ����
void list_copy(LIST *list, LIST *copy_list) {
	int index_cnt=1, cnt=0;
	NODE *copy_node = (NODE *)malloc(sizeof(NODE));

	cnt = list_cnt(list);

	if (list->head == NULL) {
		printf("������ ����Ʈ�� �����ϴ�.\n");
	}else {
		if (list_cnt(list) == 1) {		//����� �ϳ��϶�
			copy_node->n = list->head->n; // ��� ��尡 ī�ǳ��(���� ���� �Ҵ�)
			copy_list->head = copy_node;
			copy_list->tail = copy_node;
			copy_node->prev = NULL;
			copy_node->next = NULL;
		}
		else {		//��尳���� �������϶�
			list->curr = list->head; // ������� ������� ��ġ ����

			copy_node->n = list->head->n; // ��� ���� ī�ǳ��
			copy_list->head = copy_node; 
			copy_list->tail = copy_node;
			copy_node->prev = NULL;
			copy_node->next = NULL;
			copy_list->curr = copy_list->head; // ���� ����Ʈ�� ���絵 ��带 ����Ű��
			while (1) {
				NODE *copy_node = (NODE *)malloc(sizeof(NODE)); // �׶� �׶� �����Ҵ�
				list->curr = list->curr->next; // ���� �����͸� ����Ű��
				copy_node->n = list->curr->n; // ���� ��带 ���� �Ҵ���� ��忡 
				copy_list->curr->next = copy_node; // ���縮��Ʈ�� ���� ���� ī�ǳ��
				copy_list->tail = copy_node; // ���縮��Ʈ�� ������ ī�ǳ��
				copy_node->next = NULL; // �������� NULL
				index_cnt++; // ���° �ε������� Ȯ���ϴ� ��������
				if (index_cnt == cnt) break; // ���� ����Ʈ�� ��尳���� ������ break
				copy_list->curr = copy_list->curr->next; // ���縮��Ʈ�� �����͸� �������� �̵�
			}
		}
		printf("\n������ ����Ʈ\n");
		print_list(copy_list);
	}
}

// �������� ����
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

	if (ch == 1) {		// ��ȯ���� (��������)
		start_time = GetTickCount(); //ó�� �ð�
		printf("ó�� : ");
		print_list(list);

		list->curr = list->head;
		list->curr2 = list->head;

		for (int i = 1; i < cnt; i++) { //curr
			for (int j = i; j < cnt; j++) { //curr2
				list->curr2 = list->curr2->next; // �����͸� �������� �̵�
				if (list->curr2->n < list->curr->n) {
					temp = list->curr->n;
					list->curr->n = list->curr2->n;
					list->curr2->n = temp;
					print_list(list);
				}
			}list->curr = list->curr->next; // �����͸� �������� �̵�
			list->curr2 = list->curr; // curr2�� curr��ġ�� ������
		}
		end_time = GetTickCount();
		t_data = end_time - start_time; // �����½ð�
		printf("�ɸ��ð� : %d", t_data); // �ɸ��ð�
	}
	else if (ch == 2) {		 // Merge Sort

	}
	else if (ch == 3) {

	}
}
// �������� ����
void list_sort_dec(LIST *list) {
	int ch, cnt, temp;
	cnt = list_cnt(list);

	printf("====================================================\n");
	printf("1. Exchange Sort\n");
	printf("2. Merge Sort\n");
	printf("3. Quick Sort\n");
	printf("====================================================\n");
	scanf("%d", &ch);

	if (ch == 1) {		// ��ȯ���� 
		printf("ó�� : ");
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

