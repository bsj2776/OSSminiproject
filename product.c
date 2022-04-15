#include <stdio.h>
#include "product.h"
#include <string.h>

int selectMenu(){
	int menu;
	printf("\n***상품확인***\n");
	printf("1.조회\n");
	printf("2.추가\n");
	printf("3.수정\n");
	printf("4.삭제\n");
	printf("0.종료\n");
	printf("=> 원하는 메뉴는?\n");
	scanf("%d", &menu);
	return menu;
}

int addProduct(Product *p){
	getchar();
	printf("상품이름은? \n");
	fgets(p->product_name, 50, stdin);
	
	printf("상품정보는? \n");
	fgets(p->product_info, 100, stdin);

	printf("상품중량은? \n");
	scanf("%d", &p->product_weight);
	
	getchar();
	printf("상품원산지는? \n");
	fgets(p->product_origin, 20, stdin);

	printf("상품가격은? \n");
	scanf("%d", &p->price);

	printf("배송방법은?(1:새벽배송 2:택배배송)\n");
	scanf("%d", &p->deli_method);
	
	return 1;
}

int updateProduct(Product *p){
	getchar();
	printf("상품이름은? \n");
	fgets(p->product_name, 50, stdin);
	
	printf("상품정보는? \n");
	fgets(p->product_info, 100, stdin);

	printf("상품중량은? \n");
	scanf("%d", &p->product_weight);
	
	getchar();
	printf("상품원산지는? \n");
	fgets(p->product_origin, 20, stdin);

	printf("상품가격은? \n");
	scanf("%d", &p->price);

	printf("배송방법은?(1:새벽배송 2:택배배송)\n");
	scanf("%d", &p->deli_method);

	printf("수정이 완료되었습니다!\n");

	return 1;
}

int deleteProduct(Product *p){
	strcpy(p->product_name, "---");
	strcpy(p->product_info, "---");
	p->product_weight = 0;
	strcpy(p->product_origin, "---");
	p->price = -1;
	p->deli_method = 0;

	printf("삭제가 완료되었습니다!");

	return 1;
}

void readProduct(Product p){
	printf("**********************************\n");
	printf("1. %s %s %dg %s %d원 %d\n", p.product_name, p.product_info,
			p.product_weight, p.product_origin, p.price,
			p.deli_method);
}

int main(void){
	Product p;
	int result = 0, menu;

	while(1){
		menu = selectMenu();
		if(menu == 0) break;
		if(menu == 1){
			readProduct(p);
		}
		else if(menu == 2){
			result = addProduct(&p);
		}
		else if(menu == 3){
			result = updateProduct(&p);
		}
		else if(menu == 4){
			result = deleteProduct(&p);
		}
	}

	printf("종료되었습니다!\n");

	return 0;
}
