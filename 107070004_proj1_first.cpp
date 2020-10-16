#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
using namespace std;

int ** gameboard;
char command[1000][100];
int row, col;

//TLJSZIO

int T[4][4][4] = { 
  {
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },  
    { 1, 1, 1, 0 },
    { 0, 1, 0, 0 },
  },
  { 
    { 0, 0, 0, 0 },
    { 0, 1, 0, 0 },  
    { 1, 1, 0, 0 },
    { 0, 1, 0, 0 },
  },
  { 
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },  
    { 0, 1, 0, 0 },
    { 1, 1, 1, 0 },
  },
  { 
    { 0, 0, 0, 0 },
    { 1, 0, 0, 0 },  
    { 1, 1, 0, 0 },
    { 1, 0, 0, 0 },
  }
};
int Th[4] = { 2, 3, 2, 3};
int Tw[4] = { 3, 2, 3, 2};

int L[4][4][4] = {
  {
    0, 0, 0, 0,
    1, 0, 0, 0,  
    1, 0, 0, 0,
    1, 1, 0, 0,
  },
  {
    0, 0, 0, 0,
    0, 0, 0, 0,  
    1, 1, 1, 0,
    1, 0, 0, 0,
  },
  {
    0, 0, 0, 0,
    1, 1, 0, 0,  
    0, 1, 0, 0,
    0, 1, 0, 0,
  },
  {
    0, 0, 0, 0,
    0, 0, 0, 0,  
    0, 0, 1, 0,
    1, 1, 1, 0,
  },
};
int Lh[4] = { 3, 2, 3, 2};
int Lw[4] = { 2, 3, 2, 3};

int J[4][4][4] = { 
  {
    0, 0, 0, 0,
    0, 1, 0, 0,  
    0, 1, 0, 0,
    1, 1, 0, 0,
  },
  {
    0, 0, 0, 0,
    0, 0, 0, 0,  
    1, 0, 0, 0,
    1, 1, 1, 0,
  },
  {
    0, 0, 0, 0,
    1, 1, 0, 0,  
    1, 0, 0, 0,
    1, 0, 0, 0,
  },
  {
    0, 0, 0, 0,
    0, 0, 0, 0,  
    1, 1, 1, 0,
    0, 0, 1, 0,
  },
};
int Jh[4] = { 3, 2, 3, 2};
int Jw[4] = { 2, 3, 2, 3};

int S[2][4][4] = { 
  {
    0, 0, 0, 0,
    0, 0, 0, 0,  
    0, 1, 1, 0,
    1, 1, 0, 0,
  },
  {
    0, 0, 0, 0,
    1, 0, 0, 0,  
    1, 1, 0, 0,
    0, 1, 0, 0,
  },
};
int Sh[2] = { 2, 3 };
int Sw[2] = { 3, 2 };

int  Z[2][4][4] = { 
  {
    0, 0, 0, 0,
    0, 0, 0, 0,  
    1, 1, 0, 0,
    0, 1, 1, 0,
  },
  {
    0, 0, 0, 0,
    0, 1, 0, 0,  
    1, 1, 0, 0,
    1, 0, 0, 0,
  },
};
int Zh[2] = { 2, 3 };
int Zw[2] = { 3, 2 };

int I[2][4][4] = { 
  {
    1, 0, 0, 0,
    1, 0, 0, 0,  
    1, 0, 0, 0,
    1, 0, 0, 0,
  },
  {
    0, 0, 0, 0,
    0, 0, 0, 0,  
    0, 0, 0, 0,
    1, 1, 1, 1,
  }
};
int Ih[2] = { 4, 1 };
int Iw[2] = { 1, 4 };

int O[4][4] = { 
  0, 0, 0, 0,
  0, 0, 0, 0,  
  1, 1, 0, 0,
  1, 1, 0, 0,
};
int Oh[1] = { 2 };
int Ow[1] = { 2 };


void deleterow(){

}

void update_gameboard(int stop_col, int stop_row){
  // printf("update_gameboard\n");
  for(int i = stop_row; i > stop_row - 4; i--){
    for(int j = stop_col; j < stop_col + 4; j++){
      gameboard[i][j] = gameboard[i - stop_row + 3][j - stop_col];
    }
  }
}

void fall(int* block, int w, int h, int start_col, int move){ //assume only valid testcase.(ver2)
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
  int* block;
  int h, w;
  
  if(ch == 'O'){
    block = (int *) &O;
    h = Oh[0];
    w = Ow[0];
  } else if (ch == 'T'){
    block = (int*) &T[sort_num-1];
    h = Th[sort_num-1];
    w = Tw[sort_num-1];
  } else if (ch == 'L'){
    block = (int*) &L[sort_num-1];
    h = Lh[sort_num-1];
    w = Lw[sort_num-1];
  } else if (ch == 'J'){
    block = (int*) &J[sort_num-1];
    h = Jh[sort_num-1];
    w = Jw[sort_num-1];
  } else if (ch == 'S'){
    block = (int*) &S[sort_num-1];
    h = Sh[sort_num-1];
    w = Sw[sort_num-1];
  } else if (ch == 'Z'){
    block = (int*) &Z[sort_num-1];
    h = Zh[sort_num-1];
    w = Zw[sort_num-1];
  } else if (ch == 'I'){
    block = (int*) &I[sort_num-1];
    h = Ih[sort_num-1];
    w = Iw[sort_num-1];
  }


  fall(block, w, h, start_col, move);
  dump();
  elimiation();
  dump();
}

void start(){
  gamebroad = new int*[row];
  for(int i = 0; i < row; i++){
      gameboard[i] = new int[col]{0};
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

  //read row, col
  stringstream ss(command[0]);
  ss >> row >> col; // string -> int

  //cout << "row=" << row << ", col=" << col << endl;
  if(row > 15 || col > 40){
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
  for(int i = 0; i < row ; i++){
    for(int j = 0; j < col - 1; j++)
      fout << gameboard[i][j] << " "; //write ans to the file
    fout << gameboard[i][col - 1] << '\n';
  }
  fout.close();

  return 0;
}


