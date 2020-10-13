#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int ** gamebroad;
int blockbroad[4][4] = {0};

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

void block::sort_T(int n){
  if(n == 1) { blockbroad[2][0] = 1; blockbroad[2][1] = 1; blockbroad[2][2] = 1; blockbroad[3][1] = 1;}
  if(n == 2) { blockbroad[1][1] = 1; blockbroad[2][0] = 1; blockbroad[2][1] = 1; blockbroad[3][1] = 1;}
  if(n == 3) { blockbroad[2][1] = 1; blockbroad[3][0] = 1; blockbroad[3][1] = 1; blockbroad[3][2] = 1;}
  if(n == 4) { blockbroad[1][0] = 1; blockbroad[2][0] = 1; blockbroad[2][1] = 1; blockbroad[3][0] = 1;}
}

void block::sort_L(int n){
  if(n == 1) { blockbroad[1][0] = 1; blockbroad[2][0] = 1; blockbroad[3][0] = 1; blockbroad[3][1] = 1;}
  if(n == 2) { blockbroad[2][0] = 1; blockbroad[2][1] = 1; blockbroad[2][2] = 1; blockbroad[3][0] = 1;}
  if(n == 3) { blockbroad[1][0] = 1; blockbroad[1][1] = 1; blockbroad[2][1] = 1; blockbroad[3][1] = 1;}
  if(n == 4) { blockbroad[2][0] = 1; blockbroad[3][1] = 1; blockbroad[3][2] = 1; blockbroad[2][2] = 1;}
}

void block::sort_J(int n){
  if(n == 1) { blockbroad[3][0] = 1; blockbroad[3][1] = 1; blockbroad[2][1] = 1; blockbroad[1][1] = 1;}
  if(n == 2) { blockbroad[1][1] = 1; blockbroad[2][0] = 1; blockbroad[2][1] = 1; blockbroad[3][1] = 1;}
  if(n == 3) { blockbroad[2][0] = 1; blockbroad[3][0] = 1; blockbroad[3][1] = 1; blockbroad[3][2] = 1;}
  if(n == 4) { blockbroad[2][0] = 1; blockbroad[2][1] = 1; blockbroad[2][2] = 1; blockbroad[3][2] = 1;}
}

void block::sort_S(int n){
  if(n == 1) { blockbroad[2][1] = 1; blockbroad[2][2] = 1; blockbroad[3][0] = 1; blockbroad[3][1] = 1;}
  if(n == 2) { blockbroad[1][0] = 1; blockbroad[2][0] = 1; blockbroad[2][1] = 1; blockbroad[3][2] = 1;}
}

void block::sort_Z(int n){
  if(n == 1) { blockbroad[2][0] = 1; blockbroad[2][1] = 1; blockbroad[3][1] = 1; blockbroad[3][2] = 1;}
  if(n == 2) { blockbroad[1][1] = 1; blockbroad[2][0] = 1; blockbroad[2][1] = 1; blockbroad[3][1] = 1;}
}

void block::sort_I(int n){
  if(n == 1) { blockbroad[0][0] = 1; blockbroad[1][0] = 1; blockbroad[2][0] = 1; blockbroad[3][0] = 1;}
  if(n == 2) { blockbroad[3][0] = 1; blockbroad[3][1] = 1; blockbroad[3][2] = 1; blockbroad[3][3] = 1;}
}

void block::sort_O(){
  blockbroad[2][0] = 1; blockbroad[2][1] = 1; blockbroad[3][0] = 1; blockbroad[3][1] = 1;
}

int main (int argc, char *argv[]){
  if (!argc) {
    printf("usage: .exe filename\n");
    exit(-1);
  }

  //read the file

  ifstream fin;
  char line[100];
  char command[1000][100];
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

  //judge
  int row = command[0][0] - '0', col = command[0][2] - '0';
  gamebroad = new int*[row];
  for(int i = 0; i < row; i++){
      gamebroad[i] = new int[col]{0};
  }

  int j = 1;
  while(command[j][0]!='E'){
    char ch = command[j][0];
    if(ch == 'O'){
      sort_O();
    } else if(ch == 'T'){
      printf("%d\n", command[j][1] - '0');
      sort_T(command[j][1] - '0');
    } else if(ch == 'L'){
      sort_L(command[j][1] - '0');
    } else if(ch == 'J'){
      sort_J(command[j][1] - '0');
    } else if(ch == 'S'){
      sort_S(command[j][1] - '0');
    } else if(ch == 'Z'){
      sort_Z(command[j][1] - '0');
    } else if(ch == 'I'){
      sort_I(command[j][1] - '0');
    }
    for(int i = 0; i < 4; i++){
      for(int i = 0; i < 4; i++){
        printf("%d ", blockbroad[i][j]);
      }
      printf("\n");
    } 
    printf("\n");
    j++;
  }
  //TLJSZIO
  
  //ouput the file

  ofstream fout;
  fout.open("10707004_proj1.final", ios::out);
  if(!fout){
	  cout << "Fail to open file: " << "10707004_proj1.final" << endl;
  }
  //cout<<"File Descriptor: "<<fout<<endl;
  fout << "ans" << endl; //寫入字串
  fout.close();

  return 0;
}


