#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 64

typedef struct {
    char name[MAX_LEN];
    char roll[MAX_LEN];
    int marks;
} Student;

int my_strcmp(const char a[], const char b[]) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) return (a[i] < b[i]) ? -1 : 1;
        i++;
    }
    if (a[i] == '\0' && b[i] == '\0') return 0;
    return (a[i] == '\0') ? -1 : 1;
}


int cmp_marks_desc_name_asc(const Student* x, const Student* y) {
    if (x->marks != y->marks) return (y->marks - x->marks);
    return my_strcmp(x->name, y->name);
}


int cmp_name_asc(const Student* x, const Student* y) {
    return my_strcmp(x->name, y->name);
}

void merge(Student* a, Student* temp, int left, int mid, int right,
           int (*cmp)(const Student*, const Student*)) {
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        if (cmp(&a[i], &a[j]) <= 0) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }
    while (i <= mid) temp[k++] = a[i++];
    while (j <= right) temp[k++] = a[j++];
    for (i = left; i <= right; i++) a[i] = temp[i];
}

void mergesort(Student* a, Student* temp, int left, int right,
               int (*cmp)(const Student*, const Student*)) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergesort(a, temp, left, mid, cmp);
    mergesort(a, temp, mid + 1, right, cmp);
    merge(a, temp, left, mid, right, cmp);
}

int main(void) {
    int N, M;

    printf("Enter number of students (N) and passing marks (M): ");
    if (scanf("%d %d", &N, &M) != 2 || N <= 0) {
        printf("Invalid input.\n");
        return 0;
    }

    Student* students = (Student*)malloc(sizeof(Student) * N);
    Student* temp = (Student*)malloc(sizeof(Student) * N);
    if (!students || !temp) {
        printf("Memory allocation failed.\n");
        free(students); free(temp);
        return 0;
    }

    printf("Enter each student as: <Name> <Roll> <Marks>\n");
    for (int i = 0; i < N; i++) {
        printf("Student %d: ", i + 1);

        if (scanf("%63s %63s %d", students[i].name, students[i].roll, &students[i].marks) != 3) {
            printf("Invalid input.\n");
            free(students); free(temp);
            return 0;
        }
    }


    mergesort(students, temp, 0, N - 1, cmp_marks_desc_name_asc);


    for (int i = 0; i < N; i++) {
        printf("%s %s %d\n", students[i].name, students[i].roll, students[i].marks);
    }


    int pCount = 0;
    for (int i = 0; i < N; i++) if (students[i].marks >= M) pCount++;

    if (pCount > 0) {
        Student* promoted = (Student*)malloc(sizeof(Student) * pCount);
        Student* ptemp = (Student*)malloc(sizeof(Student) * pCount);
        if (!promoted || !ptemp) {
            printf("Memory allocation failed.\n");
            free(students); free(temp); free(promoted); free(ptemp);
            return 0;
        }

        int idx = 0;
        for (int i = 0; i < N; i++) if (students[i].marks >= M) promoted[idx++] = students[i];


        mergesort(promoted, ptemp, 0, pCount - 1, cmp_name_asc);

        printf("List of passed and promoted students:\n");
        for (int i = 0; i < pCount; i++) {
            printf("%s %s %d\n", promoted[i].name, promoted[i].roll, promoted[i].marks);
        }

        free(promoted);
        free(ptemp);
    } else {
        printf("List of passed and promoted students:\n");

    }

    free(students);
    free(temp);
    return 0;
}