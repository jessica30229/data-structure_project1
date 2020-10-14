#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int ** gamebroad;
int blockbroad[4][4] = {0};
char command[1000][100];

class block{
  public:
    void sort_T(int n);
    void sort_L(int n);
    void sort_J(int n);
    void sort_S(int n);
    void sort_Z(int n);
    void sort_I(int n);
    void sort_O();
    //TLJSZIO
};

void sort_T(int n){
  if(n == 1) { blockbroad[2][0] = 1; blockbroad[2][1] = 1; blockbroad[2][2] = 1; blockbroad[3][1] = 1;}
  if(n == 2) { blockbroad[1][1] = 1; blockbroad[2][0] = 1; blockbroad[2][1] = 1; blockbroad[3][1] = 1;}
  if(n == 3) { blockbroad[2][1] = 1; blockbroad[3][0] = 1; blockbroad[3][1] = 1; blockbroad[3][2] = 1;}
  if(n == 4) { blockbroad[1][0] = 1; blockbroad[2][0] = 1; blockbroad[2][1] = 1; blockbroad[3][0] = 1;}
}

void sort_L(int n){
  if(n == 1) { blockbroad[1][0] = 1; blockbroad[2][0] = 1; blockbroad[3][0] = 1; blockbroad[3][1] = 1;}
  if(n == 2) { blockbroad[2][0] = 1; blockbroad[2][1] = 1; blockbroad[2][2] = 1; blockbroad[3][0] = 1;}
  if(n == 3) { blockbroad[1][0] = 1; blockbroad[1][1] = 1; blockbroad[2][1] = 1; blockbroad[3][1] = 1;}
  if(n == 4) { blockbroad[2][2] = 1; blockbroad[3][0] = 1; blockbroad[3][1] = 1; blockbroad[3][2] = 1;}
}

void sort_J(int n){
  if(n == 1) { blockbroad[3][0] = 1; blockbroad[3][1] = 1; blockbroad[2][1] = 1; blockbroad[1][1] = 1;}
  if(n == 2) { blockbroad[2][0] = 1; blockbroad[3][0] = 1; blockbroad[3][1] = 1; blockbroad[3][2] = 1;}
  if(n == 3) { blockbroad[1][0] = 1; blockbroad[1][1] = 1; blockbroad[2][0] = 1; blockbroad[3][0] = 1;}
  if(n == 4) { blockbroad[2][0] = 1; blockbroad[2][1] = 1; blockbroad[2][2] = 1; blockbroad[3][2] = 1;}
}

void sort_S(int n){
  if(n == 1) { blockbroad[2][1] = 1; blockbroad[2][2] = 1; blockbroad[3][0] = 1; blockbroad[3][1] = 1;}
  if(n == 2) { blockbroad[1][0] = 1; blockbroad[2][0] = 1; blockbroad[2][1] = 1; blockbroad[3][1] = 1;}
}

void sort_Z(int n){
  if(n == 1) { blockbroad[2][0] = 1; blockbroad[2][1] = 1; blockbroad[3][1] = 1; blockbroad[3][2] = 1;}
  if(n == 2) { blockbroad[1][1] = 1; blockbroad[2][0] = 1; blockbroad[2][1] = 1; blockbroad[3][0] = 1;}
}

void sort_I(int n){
  if(n == 1) { blockbroad[0][0] = 1; blockbroad[1][0] = 1; blockbroad[2][0] = 1; blockbroad[3][0] = 1;}
  if(n == 2) { blockbroad[3][0] = 1; blockbroad[3][1] = 1; blockbroad[3][2] = 1; blockbroad[3][3] = 1;}
}

void sort_O(){
  blockbroad[2][0] = 1; blockbroad[2][1] = 1; blockbroad[3][0] = 1; blockbroad[3][1] = 1;
}

void fall(int start_col, int move){
  printf("%d %d\n", start_col, move);
}

void play(char ch, int sort_num, int start_col, int move){
  if(ch == 'O'){
      sort_O();
    } else if(ch == 'T'){
      sort_T(sort_num);
    } else if(ch == 'L'){
      sort_L(sort_num);
    } else if(ch == 'J'){
      sort_J(sort_num);
    } else if(ch == 'S'){
      sort_S(sort_num);
    } else if(ch == 'Z'){
      sort_Z(sort_num);
    } else if(ch == 'I'){
      sort_I(sort_num);
    }
    fall(start_col, move);
}

void start(){
  int row = command[0][0] - '0', col = command[0][2] - '0';
  gamebroad = new int*[row];
  for(int i = 0; i < row; i++){
      gamebroad[i] = new int[col]{0};
  }

  int j = 1;
  while(command[j][0]!='E'){
    char ch = command[j][0];
    for(int i = 0; i < 4; i++){
      for(int j = 0; j < 4;j++){
        blockbroad[i][j] = 0;
      }
    }
    if(ch == 'O'){
      int move = command[j][4] - '0';
      if(command[j][4] == '-')  move = - (command[j][5] - '0');
      play(ch, 0, command[j][2] - '0', move);
    } else {
      int move = command[j][5] - '0';
      if(command[j][5] == '-')  move = - (command[j][6] - '0');
      play(ch, command[j][1] - '0', command[j][3] - '0', move);
    }
    j++;
  }
}

int main (int argc, char *argv[]){
  if (!argc) {
    printf("usage: .exe filename\n");
    exit(-1);
  }

  //read the file

  ifstream fin;
  char line[100];
  
  fin.open(argv[1], ios::in);
  if(!fin){
    cout <<"Fail to open file: " << argv[1]<<endl;
  }
  //cout<<"File Descriptor: "<<fin<<endl;
  int cnt = 0;
  while(fin.getline(line, sizeof(line), '\n')){
      strcpy(command[cnt++], line);
      // cout << command[i-1] << endl;
  }
  fin.close();

  start();

  //ouput the file

  ofstream fout;
  fout.open("10707004_proj1.final", ios::out);
  if(!fout){
	  cout << "Fail to open file: " << "10707004_proj1.final" << endl;
  }
  //cout<<"File Descriptor: "<<fout<<endl;
  for(int i = 0; i < command[0][0] - '0'; i++){
    for(int j = 0; j < command[0][2] -'0' - 1; j++)
      fout << gamebroad[i][j] << " "; //寫入字串
    fout << gamebroad[i][command[0][2] -'0' - 1] << '\n';
  }
  fout.close();

  return 0;
}


