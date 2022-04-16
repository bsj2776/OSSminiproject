#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "manager.h"

int main(void){
#ifdef DEBUG
	int check;
	debugCheck();
	check = continueCheck();
	if(check == 0)
		exit(0);
#endif
	Product pList[20];
	int index = 0;
	int count = 0;
	int menu;
	count = loadData(pLIst);
	index = count;

	while(1){
		menu = selectMenu();
		if(menu == 0) break;
		if(menu == 1){
			if(count > 0){
				listProduct(pList, index);
			}else{
				printf("저장된 데이터가 존재하지 않습니다.\n");
			}
		}
		else if(menu == 2){
			if(count < 20){
				count += addProduct(&pList[index++]);
			}else{
				printf("저장공간이 충분하지 않습니다.\n");
			}
		}
		else if(menu == 3){
			int no = selectDataNo(pList, index);
			if(no == 0){
				printf("취소되었습니다.\n");
				continue;
			}
			updateProduct(&pList[no-1]);
		}
		else if(menu == 4){
			int no = selectDataNo(pList, index);
			if(no == 0){
				printf("취소되었습니다.\n");
				continue;
			}
			int deleteOk;
			printf("정말로 삭제하겠습니까?(삭제:1)> ");
			scanf("%d", &deleteOk);
			if(deleteOk == 1){
				deleteProduct(&pList[no-1]);
				count--;
			}
		}
		else if(menu == 5){
			saveData(pList, index);
		}
		else if(menu == 6){
			search_Name(pList, index);
		}
		else if(menu == 7){
			search_LowPrice(pList, index);
		}
		else if(menu == 8){
			search_Info(pList, index);
		}
	}

	printf("종료되었습니다!\n");

	return 0;
}
