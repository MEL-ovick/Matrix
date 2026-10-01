#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

void TestOnedemensionalArray   (void);
void TestMultidemensionalArray (void);
void TestTriangularArray           (void);
void PrintMtx                            (int data[], int sizeX, int sizeY);
bool CheckTriangularArray        (int size);
void PrintTRMtx                       (int *data, int size);
void PrintTRMtxSim                  (int *data, int size, int row, int n);

const int SizeX = 4, SizeY = 5;

int main(void) {
    TestMultidemensionalArray();
    return 0;
}

void TestOnedemensionalArray(void) {
    typedef double real;          // ј вы любите приколы?
    real deal = 0;

    int canary1 = 3802;              // 3802 eda в шестнадцатиричной системе исчислени€
    int data[5] = {10, 20, 30};
    int canary2 = 3802;
    printf("%d\n", data[-1]);

    if (data[2] == 3802) {       //?? [-1] not arrbiten! only [5]!
        printf("error\n");
    }
    printf("%d\n", *(int*)( (int)data + 2*sizeof(int) ));         //data[2] = *(data + 2) = *(int*)( (int)data + 2*sizeof(int) )
}

void TestMultidemensionalArray(void) {
    int canary1 = 3802;
    int data[SizeY][SizeX] = {{10,  11, 12,  13},                  // создаем матрицу
                                          {20, 21, 22, 23},
                                          {30, 31, 32, 33},
                                          {40, 41, 42, 43},
                                          {50, 51, 52, 53}};
    int canary2 = 3802;
    int  sizeX = SizeX, sizeY = SizeY;
    //int x = 2, y = 4; // элемент data[4][2]  = 52
    //printf("%d\n", data[y][x]);         // data[y][x] = *( (int*)data + y*sizeX + x )
    PrintMtx(*data, sizeX, sizeY);
}

void PrintMtx(int data[], int sizeX, int sizeY) {
    int y = 0, x = 0;
    for (; y < sizeY; y++) {
        for (; x < sizeX; x++) {
            printf("%d ", *( (int*)data + y*sizeX + x ));
        }
        x = 0;
        printf("\n");
    }
}

void TestTriangularArray(void) {
    int canary1 = 3802;
    int data[] = {1,
                      2, 3,
                      4, 5, 6,
                      7, 8, 9, 10};
    int canary2 = 3802;
    int size = sizeof(data)/sizeof(int);
    if (CheckTriangularArray(size)) {
        PrintTRMtx(data, size);
        PrintTRMtxSim(data, size, 3, 2);
    }
}

bool CheckTriangularArray(int size) {
    int i = 0, row = 1;
    while (i < size) {
        i += row;
        row++;
    }
    if (i == size) {
        return true;
    }
    else {
        printf("NE ok\nArray not triangular\n");
        return false;
    }
}

void PrintTRMtx(int *data, int size) {
    assert(data != NULL);
    int i = 0, row = 1;
    while (i < size) {
        int k_row = 0;
        for (; k_row < row; k_row++) {
            printf("%d ", data[i+k_row]);
        }
        printf("\n");
        i += row;
        row++;
    }
}

void PrintTRMtxSim(int *data, int size, int row, int n) {
    assert(data != NULL);
    int k_row = 1, i = 0;
    while (k_row < row) {
        i += k_row;
        k_row++;
    }
    printf("%d\n", data[i+(n-1)]);
}

 // todo qSort bogo/any other
