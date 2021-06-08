#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <algorithm>

struct Point {
	double x, y;
};

void info();
double Dist(double x1,double y1,double x2,double y2);
double Sq(Point A, Point B, Point C);
int tupe(Point A, Point B, Point C);
double H(Point A, Point B, double G);

int main()
{
	setlocale(LC_ALL, "Russian");
	Point A,B,C;
	char filename[256];
	double fread, Array[6], d1, d2, d3;
	int i=0;
	FILE *f;
	info();
   	printf("Введите имя файла: ");
	scanf("%[^\n]",filename);
	if ((f=fopen(filename,"r"))==NULL) {
		printf("Ошибка! Не удалось открыть файл\n");
		system("pause");
	}
	printf("Распознаю содержимое файла \"%s\":\n", filename);
	while (fscanf(f,"%lf",&fread)>0 && i<6) {
		Array[i] = fread;
		i++;
	}
	fclose(f);
	if (i != 6) {
		printf("Ошибка! В файле не содержится достаточного количества данных\n");
		system("pause");
	}
	A.x=Array[0];A.y=Array[1];B.x=Array[2];B.y=Array[3];C.x=Array[4];C.y=Array[5];
	printf("  точки A(%g;%g), B(%g;%g), C(%g;%g) заданы успешно!\n",A.x,A.y,B.x,B.y,C.x,C.y);

	d1 = Dist(A.x, A.y, B.x, B.y);
	d2 = Dist(A.x, A.y, C.x, C.y);
	d3 = Dist(B.x, B.y, C.x, C.y);
	
	switch (tupe( A,  B,  C))
	{
	case 1:
		printf("Правильный треугольник со сторонами: %g \n", d1);
		break;
	case 2:
		printf("Прямоугольный треугольник со сторонами: %g, %g и %g \n", d1, d2, d3);
		break;
	case 3:
		printf("Остроугольный треугольник со сторонами: %g, %g и %g \n", d1, d2, d3);
		break;
	case 4:
		printf("Тупоугольный треугольник со сторонами: %g, %g и %g \n", d1, d2, d3);
		break;
	case 5:
		printf("Треугольник с такими точками не существует\n");
		system("pause");
		exit(0);
	}
	printf("Площадь:%g\n",Sq(A, B, C));
	printf("Высоты:%g, %g, %g\n", H(A, B, Sq(A,B,C)), H(A, C, Sq(A, B, C)), H(C, B, Sq(A, B, C)));
	system("pause");
}

void info() {
	printf("************[ О ПРОГРАММЕ ]***********\n");
	printf("* Программа определяет тип треуг.,   *\n");
	printf("* его площадь, длины высот и сторон. *\n");
	printf("* Авторы: Шалагин Д.Д. Басорин И.А.  *\n");
	printf("* Группа: КЭ-218                     *\n");
	printf("*       Челябинск, ЮУрГУ, 2021       *\n");
	printf("**************************************\n");
}

double Dist(double x1, double y1, double x2, double y2) {
	double temp = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	return temp;
}

int tupe(Point A, Point B, Point C) {
	double d[3];
	int t;
	d[0] = Dist(A.x, A.y, B.x, B.y);
	d[1] = Dist(A.x, A.y, C.x, C.y);
	d[2] = Dist(B.x, B.y, C.x, C.y);
	std::sort(d, d + 3);
	if (d[0] + d[1] > d[2]) {
		if (d[1] == d[2] == d[0])
			t = 1;
		else if (d[2] * d[2] == d[0] * d[0] + d[1] * d[1])
			t = 2;
		else if (d[2] * d[2] > d[0] * d[0] + d[1] * d[1])
			t = 3;
		else
			t = 4;
	}
	else
		t = 5;
	return t;
}

double Sq(Point A, Point B, Point C){
	double S,p,d[3];
	d[0] = Dist(A.x, A.y, B.x, B.y);
	d[1] = Dist(A.x, A.y, C.x, C.y);
	d[2] = Dist(B.x, B.y, C.x, C.y);
	p = (d[0] + d[1] + d[2]) / 2;
	S = sqrt((p*(p-d[0])*(p-d[1])*(p-d[2])));
	return S;
 }

double H( Point A, Point B, double G) {
	double h;
	h=(2*G) / Dist(A.x, A.y, B.x, B.y);
	return h;
}
