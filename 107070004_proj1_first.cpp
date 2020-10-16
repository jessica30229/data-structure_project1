#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
using namespace std;

int ** gamebroad;
int blockbroad[4][4] = {0};
char command[1000][100];
int row, col;

// class block{
//   public:
//     void sort_T(int n);
//     void sort_L(int n);
//     void sort_J(int n);
//     void sort_S(int n);
//     void sort_Z(int n);
//     void sort_I(int n);
//     void sort_O();
//     //TLJSZIO
// };

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

void deleterow(){

}

void update_gameboard(int stop_col, int stop_row){
  // printf("update_gameboard\n");
  for(int i = stop_row; i > stop_row - 4; i--){
    for(int j = stop_col; j < stop_col + 4; j++){
      gamebroad[i][j] = blockbroad[i - stop_row + 3][j - stop_col];
    }
  }
}

bool fall(int start_col, int move){ //assume only valid testcase.(ver2)
//   for(int i = 3; i >= 0; i--){
//     for(int j = 3; j >= 0; i--){
//       if(blockbroad[i][j]){
//         //int now_col = start_col + j;
//         //int next_row = now_row - (3-i) + 1;
//         if(next_row >= 0){
//           // if(gamebroad[next_row][col]) cout << "illegal\n";
//           //gamebroad[next_row][now_col] = 1;
//         }
//       }
//     }
//   }
//   //now_row++;
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

  //read row, col
  stringstream ss(command[0]);
  ss >> row >> col; // string -> int
  //cout << "row=" << row << ", col=" << col << endl;

  gamebroad = new int*[row];
  for(int i = 0; i < row; i++){
      gamebroad[i] = new int[col]{0};
  }

  int index = 1;
  while(1){
    string sort;
    int start_col, move;
    
    stringstream cmd(command[index]);
    cmd >> sort >> start_col >> move;

    // for(int i = 0; i < 4; i++){
    //   for(int j = 0; j < 4;j++){
    //     blockbroad[i][j] = 0;
    //   }
    // }
    // the row and column all start from index 1 and all blocks shall never step out of boundary.
    
    if(sort == "End")
      break;
    const char* ch = sort.c_str();
    play(ch[0], ch[1]-'0', start_col, move);
    //cout << "sort=" << sort << ", start=" << start_col << ", move=" << last_move << endl;
    index++;
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

  if((command[0][0] - '0') > 15 || (command[0][2] - '0') > 40){
    //printf("invalid testcase.\n");
  }
  if(cnt - 1 > 1000){
    //printf("invalid testcase.\n");
  }else{
    start();
  }


  //ouput the file

  ofstream fout;
  fout.open("107070004_proj1.final", ios::out);
  if(!fout){
	  cout << "Fail to open file: " << "10707004_proj1.final" << endl;
  }
  //cout<<"File Descriptor: "<<fout<<endl;
  for(int i = 0; i < command[0][0] - '0'; i++){
    for(int j = 0; j < command[0][2] -'0' - 1; j++)
      fout << gamebroad[i][j] << " "; //write ans to the file
    fout << gamebroad[i][command[0][2] -'0' - 1] << '\n';
  }
  fout.close();

  return 0;
}


