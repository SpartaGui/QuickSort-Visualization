#include <iostream>
#include <chrono>
#include <windows.h>
using namespace std;

const int tamanho = 200;
int num[tamanho];


void textcolor (int color)
{
    static int __BACKGROUND;

    HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;


    GetConsoleScreenBufferInfo(h, &csbiInfo);

    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
                             color + (__BACKGROUND << 4));
}


void gotoxy(int x, int y){
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void mostrar(){
    for(int i = 0;i<tamanho;i++){
        cout<<num[i]<<"|";
    }
    cout<<endl;
}
int parti(int c, int f){
    int index = c;
    for(int i = c;i<f;i++){
            //Sleep(100);
                        gotoxy(0, 0);
                        string tela = "";
                        for(int j = 0;j<tamanho;j++){
                            if(j == i){
                                cout<<tela;
                                tela = "";
                            }
                            for(int k = 0;k<tamanho;k++){
                                if(k < num[j])
                                tela+='#';
                                else
                                tela+=' ';
                            }
                            if(j == i){
                                textcolor(10);
                                cout<<tela;
                                tela = "";
                                textcolor(7);
                            }
                            tela+='\n';
                        }
                        cout<<tela;
        if(num[i] < num[f]){
                        gotoxy(0, 0);
                        string tela = "";
                        for(int j = 0;j<tamanho;j++){
                            if(j == i){
                                cout<<tela;
                                tela = "";
                            }
                            if(j == index){
                                cout<<tela;
                                tela = "";
                            }
                            for(int k = 0;k<tamanho;k++){
                                if(k < num[j])
                                tela+="#";
                                else
                                tela+=" ";
                            }
                            if(j == i){
                                textcolor(10);
                                cout<<tela;
                                tela = "";
                                textcolor(7);
                            }
                            if(index == j){
                                textcolor(4);
                                cout<<tela;
                                tela = "";
                                textcolor(7);
                            }
                            tela+="\n";
                        }
                        cout<<tela;
            int temp = num[i];
            num[i] = num[index];
            num[index] = temp;
            index++;
        }
    }
    int temp = num[index];
    num[index] = num[f];
    num[f] = temp;
    return index;
}
void quicksort(int c, int f){
    if(c>=f)
        return;
    int pivot = parti(c, f);

    quicksort(c, pivot-1);
    quicksort(pivot+1, f);
}


int main(){
    srand(time(NULL));
    system("cls");
    for(int i = 0;i<tamanho;i++){
        num[i] = rand()%tamanho+1;
    }

    quicksort(0, tamanho-1);

    return 0;
}
