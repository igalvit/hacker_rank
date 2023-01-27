#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

double triangle_area ( triangle tr) {
    double p = (tr.a + tr.b + tr.c) / 2.;
    return sqrt(p * (p - tr.a) * (p - tr.b) * (p - tr.c));
}

int compare (const void *tr1, const void *tr2){
    double tr1_area = triangle_area(*(triangle*)tr1);
    double tr2_area = triangle_area(*(triangle*)tr2);
    if (tr1_area < tr2_area) return -1;
    if (tr1_area > tr2_area) return 1;
    return 0;
}
void sort_by_area(triangle* tr, int n) {
    /**
    * Sort an array a of the length n
    */
    double tr_areas[n];
    for (int i = 0;i<n;i++) {
        tr_areas[i] = triangle_area(tr[i]);
        //printf("AREA %d; %f\n", i, tr_areas[i]);
    }
    qsort(tr, n, sizeof(triangle), &compare);
}




int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
