#include <iostream>
#include <iomanip>
#include <windows.h>
#include <math.h>
using namespace std;

void loading();
void permutation(int[], int[], int, int[]);
void shift(int[], int, int[], int[], int[]);
void generateKeys(int[], int[], int[], int[][8], int[], int[], int[], int[], int[], int[], int[]);
void inverseIP(int[], int[]);
void XOR(int[], int[], int, int[]);
void decimalToBinary(int, int[], int);
int binaryToDecimal(int[], int);
void substitutionBoxes(int[], int[][4], int[][4], int[]);
void F(int[], int[][4], int[][4], int[], int[], int[], int[], int[], int[], int[]);
void f(int[], int[], int[][4], int[][4], int[], int[], int[], int[], int[], int[], int[], int[], int[]);
void swap(int[], int[]);
void encrypt(int[], int[][8], int[][4], int[][4], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[]);
void decrypt(int[], int[][8], int[][4], int[][4], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[]);
void simpleDES(int[], int[], int[], int[], int[], int[], int[], int[], int[][4], int[][4], int[][8], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[]);
string convert(int[], int);
string convertP(int[], int);
void printS(int[][4]);
int menu(int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], bool);
void keyTable(int[] ,int[][8], int[], int[], int[], int[], int[], int[], int[]);
void encryptionTable(int[], int[], int[][8], int[][4], int[][4], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[]);
void decryptionTable(int[], int[], int[][8], int[][4], int[][4], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[]);
void defaltInit(int[], int[], int[], int[], int[], int[], int[]);
void input(int[], int);
void inputP(int[], int, string);

int main() {
    int S0[4][4] = {{1, 0, 3, 2}, {3, 2, 1, 0}, {0, 2, 1, 3}, {3, 1, 3, 2}};
    int S1[4][4] = {{0, 1, 2, 3}, {2, 0, 1, 3}, {3, 0, 1, 0}, {2, 1, 0, 3}};
    int plainText[8], key[10], P10[10], P8[8], IP[8], EP[8], P4[4], IPI[8], cipherText[8], decryptedText[8], keys[2][8], KG1[10], KG2[5], KG3[5], KG4[10], KG5[5], KG6[5], KG7[10], FResult1E[4], FResult2E[4], fK1E[8], fK2E[8], swapResultE[8], PE[8], FGE1[8], FGE2[8], FGE3[4], eor1E[4], FGE4[8], FGE5[8], FGE6[4], eor2E[4], FResult1D[4], FResult2D[4], fK1D[8], fK2D[8], swapResultD[8], PD[8], FGD1[8], FGD2[8], FGD3[4], eor1D[4], FGD4[8], FGD5[8], FGD6[4], eor2D[4];
    bool flag = false;

    while (1) {
        if (!flag) {
            switch (menu(key, plainText, cipherText, decryptedText, P10, P8, P4, IP, IPI, EP, flag)) {
                case 1:
                    defaltInit(plainText, key, P10, P8, IP, EP, P4);
                    simpleDES(plainText, key, P4, P8, P10, IP, IPI, EP, S0, S1, keys, cipherText, decryptedText, KG1, KG2, KG3, KG4, KG5, KG6, KG7, FResult1E, FResult2E, fK1E, fK2E, swapResultE, PE, FGE1, FGE2, FGE3, eor1E, FGE4, FGE5, FGE6, eor2E, FResult1D, FResult2D, fK1D, fK2D, swapResultD, PD, FGD1, FGD2, FGD3, eor1D, FGD4, FGD5, FGD6, eor2D);
                    flag = true;
                    break;

                case 2:
                    loading();
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t*** Good Bye ***";
                    Sleep(3000);
                    exit(1);

                default:
                    loading();
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
                    cout << "\n\n\n\n\t\t\t\tPlease enter correct option!";
                    Sleep(3000);
            }
        }
        else {
            switch (menu(key, plainText, cipherText, decryptedText, P10, P8, P4, IP, IPI, EP, flag)) {
                case 1:
                    defaltInit(plainText, key, P10, P8, IP, EP, P4);
                    simpleDES(plainText, key, P4, P8, P10, IP, IPI, EP, S0, S1, keys, cipherText, decryptedText, KG1, KG2, KG3, KG4, KG5, KG6, KG7, FResult1E, FResult2E, fK1E, fK2E, swapResultE, PE, FGE1, FGE2, FGE3, eor1E, FGE4, FGE5, FGE6, eor2E, FResult1D, FResult2D, fK1D, fK2D, swapResultD, PD, FGD1, FGD2, FGD3, eor1D, FGD4, FGD5, FGD6, eor2D);
                    break;

                case 2:
                    keyTable(key, keys, KG1, KG2, KG3, KG4, KG5, KG6, KG7);
                    break;

                case 3:
                    encryptionTable(cipherText, plainText, keys, S0, S1, FResult1E, FResult2E, fK1E, fK2E, swapResultE, PE, FGE1, FGE2, FGE3, eor1E, FGE4, FGE5, FGE6, eor2E);
                    break;

                case 4:
                    decryptionTable(decryptedText, cipherText, keys, S0, S1, FResult1D, FResult2D, fK1D, fK2D, swapResultD, PD, FGD1, FGD2, FGD3, eor1D, FGD4, FGD5, FGD6, eor2D);
                    break;

                case 5:
                    input(key, 10);
                    simpleDES(plainText, key, P4, P8, P10, IP, IPI, EP, S0, S1, keys, cipherText, decryptedText, KG1, KG2, KG3, KG4, KG5, KG6, KG7, FResult1E, FResult2E, fK1E, fK2E, swapResultE, PE, FGE1, FGE2, FGE3, eor1E, FGE4, FGE5, FGE6, eor2E, FResult1D, FResult2D, fK1D, fK2D, swapResultD, PD, FGD1, FGD2, FGD3, eor1D, FGD4, FGD5, FGD6, eor2D);
                    break;

                case 6:
                    input(plainText, 8);
                    simpleDES(plainText, key, P4, P8, P10, IP, IPI, EP, S0, S1, keys, cipherText, decryptedText, KG1, KG2, KG3, KG4, KG5, KG6, KG7, FResult1E, FResult2E, fK1E, fK2E, swapResultE, PE, FGE1, FGE2, FGE3, eor1E, FGE4, FGE5, FGE6, eor2E, FResult1D, FResult2D, fK1D, fK2D, swapResultD, PD, FGD1, FGD2, FGD3, eor1D, FGD4, FGD5, FGD6, eor2D);
                    break;

                case 7:
                    inputP(P10, 10, "P10");
                    simpleDES(plainText, key, P4, P8, P10, IP, IPI, EP, S0, S1, keys, cipherText, decryptedText, KG1, KG2, KG3, KG4, KG5, KG6, KG7, FResult1E, FResult2E, fK1E, fK2E, swapResultE, PE, FGE1, FGE2, FGE3, eor1E, FGE4, FGE5, FGE6, eor2E, FResult1D, FResult2D, fK1D, fK2D, swapResultD, PD, FGD1, FGD2, FGD3, eor1D, FGD4, FGD5, FGD6, eor2D);
                    break;

                case 8:
                    inputP(P8, 8, "P8");
                    simpleDES(plainText, key, P4, P8, P10, IP, IPI, EP, S0, S1, keys, cipherText, decryptedText, KG1, KG2, KG3, KG4, KG5, KG6, KG7, FResult1E, FResult2E, fK1E, fK2E, swapResultE, PE, FGE1, FGE2, FGE3, eor1E, FGE4, FGE5, FGE6, eor2E, FResult1D, FResult2D, fK1D, fK2D, swapResultD, PD, FGD1, FGD2, FGD3, eor1D, FGD4, FGD5, FGD6, eor2D);
                    break;

                case 9:
                    inputP(P4, 4, "P4");
                    simpleDES(plainText, key, P4, P8, P10, IP, IPI, EP, S0, S1, keys, cipherText, decryptedText, KG1, KG2, KG3, KG4, KG5, KG6, KG7, FResult1E, FResult2E, fK1E, fK2E, swapResultE, PE, FGE1, FGE2, FGE3, eor1E, FGE4, FGE5, FGE6, eor2E, FResult1D, FResult2D, fK1D, fK2D, swapResultD, PD, FGD1, FGD2, FGD3, eor1D, FGD4, FGD5, FGD6, eor2D);
                    break;

                case 10:
                    inputP(IP, 8, "IP");
                    simpleDES(plainText, key, P4, P8, P10, IP, IPI, EP, S0, S1, keys, cipherText, decryptedText, KG1, KG2, KG3, KG4, KG5, KG6, KG7, FResult1E, FResult2E, fK1E, fK2E, swapResultE, PE, FGE1, FGE2, FGE3, eor1E, FGE4, FGE5, FGE6, eor2E, FResult1D, FResult2D, fK1D, fK2D, swapResultD, PD, FGD1, FGD2, FGD3, eor1D, FGD4, FGD5, FGD6, eor2D);
                    break;

                case 11:
                    inputP(EP, 8, "E/P");
                    simpleDES(plainText, key, P4, P8, P10, IP, IPI, EP, S0, S1, keys, cipherText, decryptedText, KG1, KG2, KG3, KG4, KG5, KG6, KG7, FResult1E, FResult2E, fK1E, fK2E, swapResultE, PE, FGE1, FGE2, FGE3, eor1E, FGE4, FGE5, FGE6, eor2E, FResult1D, FResult2D, fK1D, fK2D, swapResultD, PD, FGD1, FGD2, FGD3, eor1D, FGD4, FGD5, FGD6, eor2D);
                    break;

                case 12:
                    loading();
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t*** Good Bye ***";
                    Sleep(3000);
                    exit(1);

                default:
                    loading();
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
                    cout << "\n\n\n\n\t\t\t\tPlease enter correct option!";
                    Sleep(3000);
            }
        }
    }
    return 0;
}


void loading() {
    system("cls");
    system("COLOR 0e");
    printf("\e[?25l");

    SetConsoleCP(437);
    SetConsoleOutputCP(437);
    int bar1 = 177, bar2 = 219;

    cout << "\n\n\n\n\t\t\t\tLoading...";
    cout << "\n\n\t\t\t\t";

    for(int i = 0; i < 25; i++)
        cout << (char)bar1;

    cout <<"\r";
    cout <<"\t\t\t\t";
    for(int i = 0; i < 25; i++) {
        cout << (char)bar2;
        Sleep(15);
    }
    Sleep(40);
    system("cls");
}

void permutation(int a[], int P[], int n, int result[]) {
    for (int i = 0; i < n; i++)
        result[i] = a[P[i] - 1];
}

void shift(int key[], int n, int seg1[], int seg2[], int result[]) {
    copy(key, key + 5, seg1);
    copy(key + 5, key + 10, seg2);
    for (int i = 0; i < n; i++) {
        int temp1 = seg1[0];
        int temp2 = seg2[0];
        for (int j = 0; j < 4; j++) {
            seg1[j] = seg1[j + 1];
            seg2[j] = seg2[j + 1];
        }
        seg1[4] = temp1;
        seg2[4] = temp2;
    }
    copy(seg1, seg1 + 5, result);
    copy(seg2, seg2 + 5, result + 5);
}

void generateKeys(int key[], int P8[], int P10[], int keys[][8], int KG1[], int KG2[], int KG3[], int KG4[], int KG5[], int KG6[], int KG7[]) {
    permutation(key, P10, 10, KG1);
    shift(KG1, 1, KG2 , KG3, KG4);
    permutation(KG4, P8, 8, keys[0]);
    shift(KG4, 2, KG5, KG6, KG7);
    permutation(KG7, P8, 8, keys[1]);
}

void inverseIP(int IP[], int IPI[]) {
    for (int i = 0; i < 8; i++)
        IPI[IP[i] - 1] = i + 1;
}

void XOR(int a[], int b[], int n, int result[]) {
    for (int i = 0; i < n; i++)
        result[i] = a[i] ^ b[i];
}

void decimalToBinary(int n, int binaryNum[], int size) {
    int i = 0;
    fill_n(binaryNum, size, 0);
    while (n) {
        binaryNum[size - 1 - i] = n % 2;
        n = n / 2;
        i++;
    }
}

int binaryToDecimal(int n[], int size) {
    int decimal = 0;
    for(int i = 0; i < size; i++) {
        decimal += n[i] * pow(2, size - 1 - i);
    }
    return decimal;
}

void substitutionBoxes(int R[], int S0[][4], int S1[][4], int result[]) {
    int seg1[2], seg2[2];
    int row1[2] = {R[0], R[3]};
    int col1[2] = {R[1], R[2]};
    int row2[2] = {R[4], R[7]};
    int col2[2] = {R[5], R[6]};
    int r1 = binaryToDecimal(row1, 2);
    int c1 = binaryToDecimal(col1, 2);
    int r2 = binaryToDecimal(row2, 2);
    int c2 = binaryToDecimal(col2, 2);
    int temp1 = S0[r1][c1];
    int temp2 = S1[r2][c2];
    decimalToBinary(temp1, seg1, 2);
    decimalToBinary(temp2, seg2, 2);
    copy(seg1, seg1 + 2, result);
    copy(seg2, seg2 + 2, result + 2);
}

void F(int R[], int S0[][4], int S1[][4], int EP[], int key[], int P4[], int FResult[], int FG1[], int FG2[], int FG3[]) {
    permutation(R, EP, 8, FG1);
    XOR(FG1, key, 8, FG2);
    substitutionBoxes(FG2, S0, S1, FG3);
    permutation(FG3, P4, 4, FResult);
}

void f(int L[], int R[], int S0[][4], int S1[][4], int EP[], int key[], int P4[], int FResult[], int fK[], int FG1[], int FG2[], int FG3[], int eor[]) {
    F(R, S0, S1, EP, key, P4, FResult, FG1, FG2, FG3);
    XOR(L, FResult, 4, eor);
    copy(eor, eor + 4, fK);
    copy(R, R + 4, fK + 4);
}

void swap(int fK[], int result[]) {
    copy(fK, fK + 4, result + 4);
    copy(fK + 4, fK + 8, result);
}

void encrypt(int plainText[], int keys[][8], int S0[][4], int S1[][4], int EP[], int P4[], int IP[], int IPI[], int cipherText[], int FResult1E[], int FResult2E[], int fK1E[], int fK2E[], int swapResultE[], int PE[], int FGE1[], int FGE2[], int FGE3[], int eor1E[], int FGE4[], int FGE5[], int FGE6[], int eor2E[]) {
    int L[4], R[4];
    permutation(plainText, IP, 8, PE);
    copy(PE, PE + 4, L);
    copy(PE + 4, PE + 8, R);
    f(L, R, S0, S1, EP, keys[0], P4, FResult1E, fK1E, FGE1, FGE2, FGE3, eor1E);
    swap(fK1E, swapResultE);
    copy(swapResultE, swapResultE + 4, L);
    copy(swapResultE + 4, swapResultE + 8, R);
    f(L, R, S0, S1, EP, keys[1], P4, FResult2E, fK2E, FGE4, FGE5, FGE6, eor2E);
    permutation(fK2E, IPI, 8, cipherText);
}

void decrypt(int cipherText[], int keys[][8], int S0[][4], int S1[][4], int EP[], int P4[], int IP[], int IPI[], int decryptedText[], int FResult1D[], int FResult2D[], int fK1D[], int fK2D[], int swapResultD[], int PD[], int FGD1[], int FGD2[], int FGD3[], int eor1D[], int FGD4[], int FGD5[], int FGD6[], int eor2D[]) {
    int L[4], R[4];
    permutation(cipherText, IP, 8, PD);
    copy(PD, PD + 4, L);
    copy(PD + 4, PD + 8, R);
    f(L, R, S0, S1, EP, keys[1], P4, FResult1D, fK2D, FGD1, FGD2, FGD3, eor1D);
    swap(fK2D, swapResultD);
    copy(swapResultD, swapResultD + 4, L);
    copy(swapResultD + 4, swapResultD + 8, R);
    f(L, R, S0, S1, EP, keys[0], P4, FResult2D, fK1D, FGD4, FGD5, FGD6, eor2D);
    permutation(fK1D, IPI, 8, decryptedText);
}

void simpleDES(int plainText[], int key[], int P4[], int P8[], int P10[], int IP[], int IPI[], int EP[], int S0[][4], int S1[][4], int keys[][8], int cipherText[], int decryptedText[], int KG1[], int KG2[], int KG3[], int KG4[], int KG5[], int KG6[], int KG7[], int FResult1E[], int FResult2E[], int fK1E[], int fK2E[], int swapResultE[], int PE[], int FGE1[], int FGE2[], int FGE3[], int eor1E[], int FGE4[], int FGE5[], int FGE6[], int eor2E[], int FResult1D[], int FResult2D[], int fK1D[], int fK2D[], int swapResultD[], int PD[], int FGD1[], int FGD2[], int FGD3[], int eor1D[], int FGD4[], int FGD5[], int FGD6[], int eor2D[]) {
    inverseIP(IP, IPI);
    generateKeys(key, P8, P10, keys, KG1, KG2, KG3, KG4, KG5, KG6, KG7);
    encrypt(plainText, keys, S0, S1, EP, P4, IP, IPI, cipherText, FResult1E, FResult2E, fK1E, fK2E, swapResultE, PE, FGE1, FGE2, FGE3, eor1E, FGE4, FGE5, FGE6, eor2E);
    decrypt(cipherText, keys, S0, S1, EP, P4, IP, IPI, decryptedText, FResult1D, FResult2D, fK1D, fK2D, swapResultD, PD, FGD1, FGD2, FGD3, eor1D, FGD4, FGD5, FGD6, eor2D);
}

string convert(int a[], int n) {
    string result;
    for (int i = 0; i < n; i++)
        result += to_string(a[i]);
    return result;
}

string convertP(int p[], int n) {
    string result = "[ ";
    for (int i = 0; i < n; i++) {
        result += to_string(p[i]);
        if(i != n - 1)
            result += ", ";
    }
    result += " ]";
    return result;
}

void printS(int S[][4]) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 1)
                cout << setw(6) << " ";
            else if (i == 0) {
                if (j == 0)
                    cout << setfill(' ') << setw(6) << " ";
                else {
                    string element = 'c' + to_string(j - 1);
                    cout << setw(6) << element;
                }
            }
            else if (j == 0) {
                string element = 'r' + to_string(i - 2);
                cout << setw(6) << element;
            } else
                cout << setw(6) << S[i-2][j-1];
        }
        cout << "\n\t\t\t\t";
    }
}

int menu(int key[], int plainText[], int cipherText[], int decryptedText[], int P10[], int P8[], int P4[], int IP[], int IPI[], int EP[], bool flag) {
    loading();
    int option;
    if (flag) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
        cout << "\n\n\n\n";
        cout << "\t\t\t\t[#] Simple DES [#]" << endl << endl;
        cout << "\t\t\t\t--------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
        cout <<  "\t\t\t\tKey => " << convert(key, 10) << endl;
        cout <<  "\n\t\t\t\tPlain Text => " << convert(plainText, 8) << endl;
        cout <<  "\n\t\t\t\tCipher Text => " << convert(cipherText, 8) << endl;
        cout <<  "\n\t\t\t\tDecrypted Text => " << convert(decryptedText, 8) << endl;
        cout << "\n\t\t\t\t--------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout << "\t\t\t\t[+] Menu [+]" << endl << endl;
        cout << "\t\t\t\t--------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
        cout << "\t\t\t\t[1] Simple DES with default initialization" << endl << endl;
        cout << "\t\t\t\t[2] Show key generation steps" << endl << endl;
        cout << "\t\t\t\t[3] Show encryption steps" << endl << endl;
        cout << "\t\t\t\t[4] Show decryption steps" << endl << endl;
        cout << "\t\t\t\t[5] Change Key";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << " => " << convert(key, 10) << endl << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout << "\t\t\t\t[6] Change Plain Text";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << " => " << convert(plainText, 8) << endl << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout << "\t\t\t\t[7] Change P10";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << " => " << convertP(P10, 10) << endl << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout << "\t\t\t\t[8] Change P8";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << " => " << convertP(P8, 8) << endl << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout << "\t\t\t\t[9] Change P4";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << " => " << convertP(P4, 4) << endl << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout << "\t\t\t\t[10] Change IP";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << " => IP = " << convertP(IP, 8) << " , IPI = "<< convertP(IPI, 8) << endl << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout << "\t\t\t\t[11] Change E/P";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << " => " << convertP(EP, 8) << endl << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout << "\t\t\t\t[12] Exit" << endl << endl;
    } else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout << "\n\n\n\n\t\t\t\t[+] Menu [+]" << endl << endl;
        cout << "\t\t\t\t--------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
        cout << "\t\t\t\t[1] Simple DES with default initialization" << endl << endl;
        cout << "\t\t\t\t[2] Exit" << endl << endl;
    }
    cout << "\t\t\t\t--------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
    cout << "\t\t\t\tPlease enter option : ";
    cin >> option;
    return option;
}

void keyTable(int key[] ,int keys[][8], int KG1[], int KG2[], int KG3[], int KG4[], int KG5[], int KG6[], int KG7[]) {
    int option = 1;
    while (option) {
        loading();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
        cout << "\n\n\n\n\t\t\t\t[#] Key Generation Steps Table [#]\n\n";
        cout << "\t\t\t\t--------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
        cout << "\t\t\t\tFirst Key = P8 ( Shift Left 1 ( P10 ( KEY ) ) )\n\n";
        cout << "\t\t\t\tSecond Key = P8 ( Shift Left 3 ( P10 ( KEY ) ) )\n\n";
        int rows = 12;
        int cols = 2;
        int width = 49;
        int i = 0;
        string data[rows][cols];
        data[i][0] = "Function";
        data[i++][1] = "Output";
        data[i][0] = "P10 ( " + convert(key, 8) + " )";
        data[i++][1] = convert(KG1, 10);
        data[i][0] = "Shift Left 1 ( " + convert(KG1, 5) + " )";
        data[i++][1] = convert(KG2, 5);
        data[i][0] = "Shift Left 1 ( " + convert(KG1 + 5, 5) + " )";
        data[i++][1] = convert(KG3, 5);
        data[i][0] = "Merge Segments";
        data[i++][1] = convert(KG4, 10);
        data[i][0] = "P8 ( " + convert(KG4, 10) + " )";
        data[i++][1] = convert(keys[0], 8);
        data[i][0] = "First Key";
        data[i++][1] = convert(keys[0], 8);
        data[i][0] = "Shift Left 3 ( " + convert(KG1, 5) + " )";
        data[i++][1] = convert(KG5, 5);
        data[i][0] = "Shift Left 3 ( " + convert(KG1 + 5, 5) + " )";
        data[i++][1] = convert(KG6, 5);
        data[i][0] = "Merge Segments";
        data[i++][1] = convert(KG7, 10);
        data[i][0] = "P8 ( " + convert(KG7, 10) + " )";
        data[i++][1] = convert(keys[1], 8);
        data[i][0] = "Second Key";
        data[i++][1] = convert(keys[1], 8);

        cout << "\t\t\t\t " << setfill((char)205) << setw(width*cols+cols-1) << (char)205 << endl;
        for (int i = 0; i < rows; i++) {
            cout << "\t\t\t\t";
            cout << (char)186;
            for (int j = 0; j < cols; j++) {
                int padding = (width - data[i][j].length()) / 2;
                cout << right << setfill(' ') << setw(padding) << ' ';
                cout << left << setfill(' ') << setw(width - padding) << data[i][j];
                cout << (char)186;
            }
            cout << endl;
            if (i != rows - 1)
                cout << "\t\t\t\t " << setfill((char)205) << setw(width*cols+cols-1) << (char)205 << endl;
        }
        cout << "\t\t\t\t " << setfill((char)205) << setw(width*cols+cols-1) << (char)205 << endl;
        cout << "\n\t\t\t\t--------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
        cout << "\t\t\t\t[0] Back to main menu" << endl << endl;
        cout << "\t\t\t\t--------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
        cout << "\t\t\t\tPlease enter option : ";
        cin >> option;
    }
}

void encryptionTable(int cipherText[], int plainText[], int keys[][8], int S0[][4], int S1[][4], int FResult1E[], int FResult2E[], int fK1E[], int fK2E[], int swapResultE[], int PE[], int FGE1[], int FGE2[], int FGE3[], int eor1E[], int FGE4[], int FGE5[], int FGE6[], int eor2E[]) {
    int option = 1;
    while (option) {
        loading();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
        cout << "\n\n\n\n\t\t\t\t[#] Encryption Steps Table [#]\n\n";
        cout << "\t\t\t\t--------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
        cout << "\t\t\t\tCipher Text = IPI ( fK2 ( SW ( fK1 ( IP ( PlainText ) ) ) ) )\n\n";
        cout << "\t\t\t\tfK ( L, R ) = L ^ F ( R, SK ), R\n\n";
        cout << "\t\t\t\tF ( R, SK ) = P4 ( S-Boxes ( Key ^ ( E/P ( R ) ) ) )\n\n";
        cout << "\t\t\t\t--------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
        cout << "\t\t\t\tS-Box 0:\n\n\t\t\t\t";
        printS(S0);
        cout << "\n\n\t\t\t\tS-Box 1:\n\n\t\t\t\t";
        printS(S1);
        cout << "\n\t\t\t\t--------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;

        int rows = 21;
        int cols = 2;
        int width = 49;
        int i = 0;
        string data[rows][cols];
        data[i][0] = "Function";
        data[i++][1] = "Output";
        data[i][0] = "IP ( " + convert(plainText, 8) + " )";
        data[i++][1] = convert(PE, 8);
        data[i][0] = "E/P ( " + convert(PE + 4, 4) + " )";
        data[i++][1] = convert(FGE1, 8);
        data[i][0] = convert(keys[0], 8) + " ^ "  + convert(FGE1, 8);
        data[i++][1] = convert(FGE2, 8);
        data[i][0] = "S-Boxes ( " + convert(FGE2, 8) + " )";
        data[i++][1] = convert(FGE3, 4);
        data[i][0] = "P4 ( " + convert(FGE3, 4) + " )";
        data[i++][1] = convert(FResult1E, 4);
        data[i][0] = "F ( " + convert(PE + 4, 4) + ", " + convert(keys[0], 8) + " )";
        data[i++][1] = convert(FResult1E, 4);
        data[i][0] = convert(PE, 4) + " ^ " + convert(FResult1E, 4);
        data[i++][1] = convert(eor1E, 4);
        data[i][0] = "Merge Segments";
        data[i++][1] = convert(fK1E, 8);
        data[i][0] = "f " + convert(keys[0], 8) + " ( " + convert(PE, 4) + ", " + convert(PE + 4, 4) + " )";
        data[i++][1] = convert(fK1E, 8);
        data[i][0] = "SW ( " + convert(fK1E, 8) + " )";
        data[i++][1] = convert(swapResultE, 8);
        data[i][0] = "E/P ( " + convert(swapResultE + 4, 4) + " )";
        data[i++][1] = convert(FGE4, 8);
        data[i][0] = convert(keys[1], 8) + " ^ "  + convert(FGE4, 8);
        data[i++][1] = convert(FGE5, 8);
        data[i][0] = "S-Boxes ( " + convert(FGE5, 8) + " )";
        data[i++][1] = convert(FGE6, 4);
        data[i][0] = "P4 ( " + convert(FGE6, 4) + " )";
        data[i++][1] = convert(FResult2E, 4);
        data[i][0] = "F ( " + convert(swapResultE + 4, 4) + ", " + convert(keys[0], 8) + " )";
        data[i++][1] = convert(FResult2E, 4);
        data[i][0] = convert(swapResultE, 4) + " ^ " + convert(FResult2E, 4);
        data[i++][1] = convert(eor2E, 4);
        data[i][0] = "Merge Segments";
        data[i++][1] = convert(fK2E, 8);
        data[i][0] = "f " + convert(keys[1], 8) + " ( " + convert(swapResultE, 4) + ", " + convert(swapResultE + 4, 4) + " )";
        data[i++][1] = convert(fK2E, 8);
        data[i][0] = "IPI ( " + convert(fK2E, 8) + " )";
        data[i++][1] = convert(cipherText, 8);
        data[i][0] = "Cipher Text";
        data[i++][1] = convert(cipherText, 8);

        cout << "\t\t\t\t " << setfill((char)205) << setw(width*cols+cols-1) << (char)205 << endl;
        for (int i = 0; i < rows; i++) {
            cout << "\t\t\t\t";
            cout << (char)186;
            for (int j = 0; j < cols; j++) {
                int padding = (width - data[i][j].length()) / 2;
                cout << right << setfill(' ') << setw(padding) << ' ';
                cout << left << setfill(' ') << setw(width - padding) << data[i][j];
                cout << (char)186;
            }
            cout << endl;
            if (i != rows - 1)
                cout << "\t\t\t\t " << setfill((char)205) << setw(width*cols+cols-1) << (char)205 << endl;
        }
        cout << "\t\t\t\t " << setfill((char)205) << setw(width*cols+cols-1) << (char)205 << endl;
        cout << "\n\t\t\t\t--------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
        cout << "\t\t\t\t[0] Back to main menu" << endl << endl;
        cout << "\t\t\t\t--------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
        cout << "\n\t\t\t\tPlease enter option : ";
        cin >> option;
    }
}

void decryptionTable(int decryptedText[], int cipherText[], int keys[][8], int S0[][4], int S1[][4], int FResult1D[], int FResult2D[], int fK1D[], int fK2D[], int swapResultD[], int PD[], int FGD1[], int FGD2[], int FGD3[], int eor1D[], int FGD4[], int FGD5[], int FGD6[], int eor2D[]) {
    int option = 1;
    while (option) {
        loading();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
        cout << "\n\n\n\n\t\t\t\t[#] Decryption Steps Table [#]\n\n";
        cout << "\t\t\t\t--------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
        cout << "\t\t\t\tPlain Text = IPI ( fK1 ( SW ( fK2 ( IP ( CipherText ) ) ) ) )\n\n";
        cout << "\t\t\t\tfK ( L, R ) = L ^ F ( R, SK ), R\n\n";
        cout << "\t\t\t\tF ( R, SK ) = P4 ( S-Boxes ( Key ^ ( E/P ( R ) ) ) )\n\n";
        cout << "\t\t\t\t--------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
        cout << "\t\t\t\tS-Box 0:\n\n\t\t\t\t";
        printS(S0);
        cout << "\n\n\t\t\t\tS-Box 1:\n\n\t\t\t\t";
        printS(S1);
        cout << "\n\t\t\t\t--------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;

        int rows = 21;
        int cols = 2;
        int width = 49;
        int i = 0;
        string data[rows][cols];
        data[i][0] = "Function";
        data[i++][1] = "Output";
        data[i][0] = "IP ( " + convert(cipherText, 8) + " )";
        data[i++][1] = convert(PD, 8);
        data[i][0] = "E/P ( " + convert(PD + 4, 4) + " )";
        data[i++][1] = convert(FGD1, 8);
        data[i][0] = convert(keys[1], 8) + " ^ "  + convert(FGD1, 8);
        data[i++][1] = convert(FGD2, 8);
        data[i][0] = "S-Boxes ( " + convert(FGD2, 8) + " )";
        data[i++][1] = convert(FGD3, 4);
        data[i][0] = "P4 ( " + convert(FGD3, 4) + " )";
        data[i++][1] = convert(FResult1D, 4);
        data[i][0] = "F ( " + convert(PD + 4, 4) + ", " + convert(keys[1], 8) + " )";
        data[i++][1] = convert(FResult1D, 4);
        data[i][0] = convert(PD, 4) + " ^ " + convert(FResult1D, 4);
        data[i++][1] = convert(eor1D, 4);
        data[i][0] = "Merge Segments";
        data[i++][1] = convert(fK2D, 8);
        data[i][0] = "f " + convert(keys[1], 8) + " ( " + convert(PD, 4) + ", " + convert(PD + 4, 4) + " )";
        data[i++][1] = convert(fK2D, 8);
        data[i][0] = "SW ( " + convert(fK2D, 8) + " )";
        data[i++][1] = convert(swapResultD, 8);
        data[i][0] = "E/P ( " + convert(swapResultD + 4, 4) + " )";
        data[i++][1] = convert(FGD4, 8);
        data[i][0] = convert(keys[0], 8) + " ^ "  + convert(FGD4, 8);
        data[i++][1] = convert(FGD5, 8);
        data[i][0] = "S-Boxes ( " + convert(FGD5, 8) + " )";
        data[i++][1] = convert(FGD6, 4);
        data[i][0] = "P4 ( " + convert(FGD6, 4) + " )";
        data[i++][1] = convert(FResult2D, 4);
        data[i][0] = "F ( " + convert(swapResultD + 4, 4) + ", " + convert(keys[0], 8) + " )";
        data[i++][1] = convert(FResult2D, 4);
        data[i][0] = convert(swapResultD, 4) + " ^ " + convert(FResult2D, 4);
        data[i++][1] = convert(eor2D, 4);
        data[i][0] = "Merge Segments";
        data[i++][1] = convert(fK1D, 8);
        data[i][0] = "f " + convert(keys[0], 8) + " ( " + convert(swapResultD, 4) + ", " + convert(swapResultD + 4, 4) + " )";
        data[i++][1] = convert(fK1D, 8);
        data[i][0] = "IPI ( " + convert(fK1D, 8) + " )";
        data[i++][1] = convert(decryptedText, 8);
        data[i][0] = "Plain Text";
        data[i++][1] = convert(decryptedText, 8);

        cout << "\t\t\t\t " << setfill((char)205) << setw(width*cols+cols-1) << (char)205 << endl;
        for (int i = 0; i < rows; i++) {
            cout << "\t\t\t\t";
            cout << (char)186;
            for (int j = 0; j < cols; j++) {
                int padding = (width - data[i][j].length()) / 2;
                cout << right << setfill(' ') << setw(padding) << ' ';
                cout << left << setfill(' ') << setw(width - padding) << data[i][j];
                cout << (char)186;
            }
            cout << endl;
            if (i != rows - 1)
                cout << "\t\t\t\t " << setfill((char)205) << setw(width*cols+cols-1) << (char)205 << endl;
        }
        cout << "\t\t\t\t " << setfill((char)205) << setw(width*cols+cols-1) << (char)205 << endl;
        cout << "\n\t\t\t\t--------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
        cout << "\t\t\t\t[0] Back to main menu" << endl << endl;
        cout << "\t\t\t\t--------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
        cout << "\t\t\t\tPlease enter option : ";
        cin >> option;
    }
}

void defaltInit(int plainText[], int key[], int P10[], int P8[], int IP[], int EP[], int P4[]) {
    string plainTextS, keyS, P10S, P8S, IPS, EPS, P4S;
    plainTextS = "00101000";
    keyS = "1100011110";
    P10S = "2416390875";
    P8S = "52637498";
    IPS = "15203746";
    EPS = "30121230";
    P4S = "1320";
    for (int i = 0; i < plainTextS.length(); i++)
        plainText[i] = plainTextS[i] - 48;
    for (int i = 0; i < keyS.length(); i++)
        key[i] = keyS[i] - 48;
    for (int i = 0; i < P10S.length(); i++)
        P10[i] = P10S[i] - 47;
    for (int i = 0; i < P8S.length(); i++)
        P8[i] = P8S[i] - 47;
    for (int i = 0; i < IPS.length(); i++)
        IP[i] = IPS[i] - 47;
    for (int i = 0; i < EPS.length(); i++)
        EP[i] = EPS[i] - 47;
    for (int i = 0; i < P4S.length(); i++)
        P4[i] = P4S[i] - 47;
}

void input(int a[], int n) {
    string text;
    loading();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    cout << "\n\n\n\n\t\t\t\t" << "Please enter key (" << n << " bit) : ";
    cin >> text;
    int i = text.length();
    while(i != n) {
        loading();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
        cout << "\n\n\n\n\t\t\t\t" << "Please enter valid key (" << n << " bit) : ";
        cin >> text;
        i = text.length();
    }
    while(i) {
        i--;
        if (text[i] != '1' && text[i] != '0') {
            loading();
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
            cout << "\n\n\n\n\t\t\t\t" << "Please enter valid key (" << n << " bit) : ";
            cin >> text;
            i = text.length();
        }
    }
    for (int i = 0; i < n; i++)
        a[i] = text[i] - 48;
}

void inputP(int p[], int n, string x) {
    bool flags[8];
    fill_n(flags, 8, true);
    int range;
    if (x == "P10" || x == "P8")
        range = 10;
    else if (x == "IP")
        range = 8;
    else if (x == "E/P" || x == "P4")
        range = 4;
    loading();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    int i = n;
    while(i) {
        system("cls");
        cout << "\n\n\n\n\t\t\t\t" << "Please enter " << x << "[" << n + 1 - i << "] (1-" << range <<") : " ;
        cin >> p[n-i];
        while (p[n-i] < 1 || p[n-i] > range || (!flags[p[n-i] - 1] && x == "IP")) {
            system("cls");
            cout << "\n\n\n\n\t\t\t\t" << "Please enter valid " << x << "[" << n + 1 - i << "] (1-" << range <<") : " ;
            cin >> p[n-i];
        }
        if (x == "IP")
            flags[p[n-i] - 1] = false;
        i--;
    }
}