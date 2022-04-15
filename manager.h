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

int addProduct(Product *p);

void readProduct(Product p);

void listProduct(Product *p, int index);

int selectDataNo(Product *p, int index);

int updateProduct(Product *p);

int deleteProduct(Product *p);

int selectMenu();

void debugCheck();

int continueCheck();
