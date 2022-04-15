typedef struct{
	//상품이름
	char product_name [50];
	//상품정보
	char product_info [100];
	//상품무게
	int product_weight;
	//상품원산지
	char product_origin [10];
	//가격
	int price;
	//배송방법
	int deli_method;
}Product;

//상품등록
int addProduct(Product *p);
//상품정보 업데이트
int updateProduct(Product *p);
//상품삭제
int deleteProduct(Product *p);
//메뉴선택
int selectMenu();
//상품리스트 출력문(출력양식)&특정 n번째 리스트 출력
void readProduct(Product p);
//상품리스트 출력문(모든 리스트 -  readProduct호출)
void listProduct(Product *p, int count);
//상품의 업데이트 및 삭제시 원하는 상품번호 입력
int selectDataNo(Product *p, int count);
//정보 File 저장
void saveData(Product *p, int count);
//File 정보를 읽어오기
int loadData(Product *p);
//제품이름으로 검색
void search_Name(Product *p, int count);
//특정가격보다 낮은 제품검색
void search_LowPrice(Product *p, int count);
//설명의 sublist로 검색
void search_Info(Product *p, int count);
