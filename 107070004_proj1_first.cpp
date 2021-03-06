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

// void dump()
// {
//   cout << "=================" << endl;
//   // cout << "1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0" << endl;
//   for(int i=0;i<row;i++){
//     for(int j=0;j<col;j++){
//       cout << gameboard[i][j] << " ";
//     }
//     cout << endl;
//   }
// }

// void dump_block(int* block)
// {
//   for(int i=0;i<4;i++) {
//     for(int j=0;j<4;j++){
//       cout << block[i*4+j] << " ";
//     }
//     cout << endl;
//   }
// }

void delete_row(){
  int dest_row = -1;

  for(int i = 0; i < row; i++) {
    int * ptr = &gameboard[row - i - 1][0];
    bool full = true;
    for(int j = 0; j < col; j++) {
      if(ptr[j] == 0){
        full = false;
        break;
      }
    }
    if(full) {
      if(dest_row == -1)
        dest_row = row - i - 1;
    } else {
      if(dest_row != -1) {
        int* dest = &gameboard[dest_row][0];
        for(int j = 0; j < col; j++){
          dest[j] = ptr[j];
        }
      dest_row--;
      } 
    }
  }
  // fill rest row
  while(dest_row>=0) {
      int* dest = &gameboard[dest_row][0];    
      for(int j=0;j<col;j++){
        dest[j] = 0;
      }
      dest_row--;
  }
}

void put_block(int*block, int h, int w, int ref_col, int ref_row) {
    for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++) {
        if(block[(3-i)*4+j])
          gameboard[ref_row-i][ref_col+j] = block[(3-i)*4+j]; 
      }
    }
}

bool test_collision(int* block, int w, int h, int ref_col, int ref_row) {
    for(int i = 0; i < h; i++) {
      int* ptr = &gameboard[ref_row-i][ref_col];
      int* bptr = &block[(3-i)*4]; //2-dimension to 1
      for(int j = 0; j < w; j++) {
        if(bptr[j] && ptr[j]) {
          return true;
        }
      }
    }
    return false;
}

//assume only valid testcase.(ver2)
 
void fall(int* block, int w, int h, int start_col, int move) {

  bool collision = false;
  int ref_row, ref_col;

  //collide
  int cur_row = h-1;
  while(cur_row < row) {
    collision = test_collision(block, w, h, start_col - 1, cur_row);
    if(collision == true) {
      // put block on cur_row-1
      if(cur_row >= h) {
        // valid on cur_row-1
        ref_col = start_col-1;
        ref_row = cur_row-1;
        break;
      } else {
        cout << "no space to put block (illegal testcase)" << endl;
        return;
      }
    } else if(cur_row == row-1) { //last row
        // valid on cur_row
        ref_col = start_col-1;
        ref_row = cur_row;
        break;
    }
    cur_row++;
  }
  
  //move
  if(move > 0){
    //move right one by one
    for(int i = 1; i < move; i++){
      if(test_collision(block, w, h, ref_col+i, ref_row)) return;
    }
    ref_col += move;
  }else{
    //move left one by one
    for(int i = 1; i < -move; i++){ //fix a bug
      if(test_collision(block, w, h, ref_col-i, ref_row)) return;
    }
    ref_col += move;
  }
  
  // try to move down if can
  while(ref_row < row-1) {
    // try next row
    collision = test_collision(block, w, h, ref_col, ref_row+1);
    if(collision) {
      break;
    }
    // move to next
    ref_row++;
  }
   
  put_block(block, h, w, ref_col, ref_row);
}

void play(char ch, int sort_num, int start_col, int move) {
  int* block;
  int h, w;
  
  //add (int*) -> cannot convert 'int (*)[4][4]' to 'int*' in assignment
  if(ch == 'O'){
    block = (int*) &O;
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
  // printf("start=%d move=%d\n", start_col, move);
  // dump_block(block);
  // dump();

  fall(block, w, h, start_col, move);
  // dump();
  delete_row();
  // dump();
}

void start() {
  gameboard = new int*[row];
  for(int i = 0; i < row; i++){
      gameboard[i] = new int[col]{0};
  }

  int index = 1;
  while(1){
    string sort;
    int start_col, move;
    
    stringstream cmd(command[index]);
    // try{
      cmd >> sort >> start_col >> move;   
      if(sort == "End")
        break;
      const char* ch = sort.c_str();
      play(ch[0], ch[1]-'0', start_col, move);
    // }catch(exit){
      
    // }
    index++;
  }
}

int main (int argc, char *argv[]) {
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
	  cout << "Fail to open file: " << "107070004_proj1.final" << endl;
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


