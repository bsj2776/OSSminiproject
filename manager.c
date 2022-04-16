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
	printf("4.삭제\n");
	printf("5.저장\n");
	printf("6.이름검색\n");
	printf("7.가격검색\n");
	printf("8.정보검색\n");
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

	printf("수정이 완료되었습니다.\n");
	
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
	printf(" %s %s %dg %s %d원 %d\n", p.product_name, p.product_info,
			p.product_weight, p.product_origin, p.price,
			p.deli_method);
}

void listProduct(Product *p, int index){
	printf("***********************************\n");
	for(int i = 0; i < index; i++){
		if(p[i].price == -1){
			continue;
		}
		printf("%2d", i+1);
		readProduct(p[i]);
	}
	printf("\n\n");
}

int selectDataNo(Product *m, int index){
	int no;
	listProduct(m, index);
	printf("번호를 입력하세요(cancel:0)> ");
	scanf("%d", &no);
	return no;
}

void debugCheck(){
	printf("=====디버그확인=====\n");
}

int continueCheck(){
	char ch;
	printf("코드를 진행하시겠습니까?(y or n)>  ");
	scanf("%c",&ch);

	if(ch == 'y'|| ch == 'Y')
		return 1;
	else
		return 0;
}

void saveData(Product *p, int count){
	FILE *fp;
	fp = fopen("product.txt", "wt");
	for(int i = 0; i < count; i++){
		if(p[i].price == -1)
			continue;
		fprintf(fp,"%s %s %d %s %d %d\n",p[i].product_name,
			       	p[i].product_info,p[i].product_weight,
			       	p[i].product_origin, p[i].price, 
				p[i].deli_method);
	}
	fclose(fp);
	printf("=> 저장되었습니다! ");
	printf("\n");
}

int loadData(Product *p){
	int count = 0, i = 0;
       	FILE *fp;
	if(fp = fopen("product.txt", "rt")){
		for(; i < 100; i++){
			fscanf(fp, "%[^\n]s", p[i].product_name);
			if(feof(fp))
				break;
			fscanf(fp, "%[^\n]s", p[i].product_info);
			fscanf(fp, "%d", &p[i].product_weight);
			fscanf(fp, "%[^\n]s", p[i].product_origin);
			fscanf(fp, "%d", &p[i].price);
			fscanf(fp, "%d", &p[i].deli_method);
		}
	}
	else{
		printf("NO EXIST FILE!\n");
		return i;
	}
	fclose(fp);
	printf("=> Loading success!\n");
	return i;
}

void search_Name(Product *p, int count){
	int scnt = 0; //검색된 데이터 개수 확인
	char search[20];
	printf("검색할 이름? ");
	scanf("%s", search);
	printf("***********************************\n");
	for(int i = 0; i < count; i++){
		if(p[i].price == -1)
			continue;
		if(strstr(p[i].product_name, search)){
			printf("%d", i+1);
			readProduct(p[i]);
			scnt++;
		}
	}
	if(scnt == 0)
		printf("=> 검색된 데이터 없음!");
	printf("\n");	
}

void search_LowPrice(Product *p, int count){

}

void search_Info(Product *p, int count){
	int scnt = 0;
	char search[20];
	printf("검색할 단어? ");
	scanf("%s", search);
	prinf("************************************\n");
	for(int i = 0; i < count; i++){
		if(p[i].price == -1)
			continue;
		if(strstr(p[i].product_info, search)){
			printf("%d", i+1);
			readProduct(p[i]);
			scnt++;
		}
	}
	if(scnt == 0)
		printf("=> 검색된 데이터 없음!");
	printf("\n");
}

