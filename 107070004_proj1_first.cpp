#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){
  if(!argc) {
    printf("usage: .exe filename\n");
    exit(-1);
  }
  ifstream fin;
  char line[128];
  fin.open(argv[1], ios::in);
  if(!fin){
    cout<<"Fail to open file: "<<argv[1]<<endl;
  }
  cout<<"File Descriptor: "<<fin<<endl;
  while(fin.getline(line, sizeof(line), '\n')){
      cout<<line<<endl;
  }
  fin.close();

  ofstream fout;
  fout.open("10707004_proj1.final", ios::out);
  if(!fout){
	  cout<<"Fail to open file: "<<"10707004_proj1.final"<<endl;
  }
  cout<<"File Descriptor: "<<fout<<endl;
  fout<<"ans"<<endl; //寫入字串
  fout.close();

  return 0;
}


