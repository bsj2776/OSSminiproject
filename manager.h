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
//상품추가
int addProduct(Product *p);
//리스트출력
void readProduct(Product p);
//상품리스트 출력
void listProduct(Product *p, int index);
//수정,삭제 시 상품번호 선택
int selectDataNo(Product *p, int index);
//상품 수정
int updateProduct(Product *p);
//상품삭제
int deleteProduct(Product *p);
//선택메뉴
int selectMenu();
//디버그 파일확인
void debugCheck();
//디버그 진행확인
int continueCheck();
//정보파일저장
void saveData(Product *p, int count);
//정보파일로드
int loadData(Product *p);
//이름으로 리스트검색
void search_Name(Product *p, int count);
//특정가격보다 낮은 제품검색
void search_LowPrice(Product *p, int count);
//설명으로 리스트검색
void search_Info(Product *p, int count);
