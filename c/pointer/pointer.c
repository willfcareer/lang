#include <stdlib.h>
#include <stdio.h>

void fun1(void);
int fun2(void);
int fun3(int a);


int main(void)
{
	short a = 0x1;
	short b = 0x2;
	short c = 0x3;
	short d = 0x4;
	printf("&a=%x,a=%x\n",&a,a);
	printf("&b=%x,b=%x\n",&b,b);
	printf("&c=%x,c=%x\n",&c,c);
        printf("&d=%x,d=%x\n",&d,d);


//	short *p1;
	short *p2 = &b;
	short *p3 = (short *)0x5;
	int *p4;
	int **p5;
	p3 = &c;

	/* 地址检查 */
//	printf("p1=%x,*p1=%x\n",p1,*p1);
	printf("p2=%x,*p2=%x\n",p2,*p2);
	printf("p3=%x\n",p3);
	printf("*p3=%x\n",*p3);
	
	printf("&p2=%x\n",&p2);
	printf("&p3=%x\n",&p3);
//	printf("&p2 - &c = %x",(int)(&p2 - &c));
	
	/* 长度检查 */
	printf("sizeof(p3) = %x,sizeof(p4) = %x\n", sizeof(p3), sizeof(p4));
	
	/* 运算检查 */
	printf("p3 = %x, (p3 + 1) = %x, p4 = %x, (p4 + 1) = %x\n", p3, (p3 + 1), p4, (p4 + 1));
	

	/* 赋值检查 */
	*p3 = d;
	printf("p3=%x,*p3=%x\n",p3,*p3);
	printf("&c=%x,c=%x\n",&c,c);

        *p3 = 6;
        printf("p3=%x,*p3=%x\n",p3,*p3);
        printf("&c=%x,c=%x\n",&c,c);

	/* 指针地址&类型转换 */
//	short e = 256;  
//	char *p6 = &e;  
//	printf("%d\n",*(short*)(*(int*)&p6)); 

	/* 函数指针 */
	void (*p8)();
	int (*p9)();
	int (*p10)(int a);
	p8 = fun1;
	p9 = fun2;
	p10 = fun3;
	p8();
	int r9 = p9();
	printf("r9 = %d\n", r9);
	int r10 = p10(2);
	printf("r10 = %d\n", r10);
	
	printf("p8 = %d, p8 + 1 = %d\n", p8, p8 + 1);
        printf("p9 = %d, p9 + 1 = %d\n", p9, p9 + 1);
        printf("p10 = %d, p10 + 1 = %d\n", p10, p10 + 1);


	/* 类型转换 */
	int *p12;
//	printf("p12 = %x\n", p12);
	char *p13 = (char *)p12; 
//	printf("&p12 = %x\n", &p12);
	printf("p12 = %x, p12 + 1 = %x, p13 = %x, p13 + 1 = %x\n", p12, p12 + 1, p13, p13 + 1);
	printf("p12 = %x, p12 + 1 = %x, p13 = %x, p13 + 1 = %x\n", p12, p12 + 1, p13, p13 + 1);
	printf("p12 = %x, p12 + 1 = %x, p13 = %x, p13 + 1 = %x\n", p12, p12 + 1, p13, p13 + 1);
	
	
	short e = 256;  
	char *p14 = &e;  
	printf("&p14 = %d\n", &p14);
	printf("*(short*)(*(int*)&p14) = %d\n", (short *)(*(int *)&p14));  //256 
//	printf("*(short*)(*(int*)&p14) = %x\n", *((short *)(*(int *)&p14)));  //256 
//	printf("&p14 = %d\n", &p14);

	return 0;
}


void fun1()
{
        printf("exec fun1\n");
}

int fun2()
{
        printf("exec fun2\n");
        return 2;
}

int fun3(int a)
{
        printf("exec fun3, param = %d\n", a);
        int b = 3;
        return b;
}


