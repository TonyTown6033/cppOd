/* 
 * BUG REPORT:
 * if 0 in this num array this program will not perform normally
 * example :
 * 1000001
 * 3
 * the answer should be 000
 * but if you run this case the program will dump

*/

#include<iostream>
#include<string>
#include<vector>
#include<cassert>
using namespace std;
/*
 here we need to update the stragedy for update numbers
 paper and pen 


*/
void solution(vector<int> array, int N_0){
  long unsigned int N = (long unsigned int ) N_0;
  if (N >= array.size()) cout<<0<<endl;
  for(long unsigned int i = 0 ; i < array.size() ; i++){
    if(N==0) break;
    if (array[i]==1)
      continue;
    
    if (array[i] > array[i+1]){
      array.erase(array.begin()+ i );
      i--;
      N--;
    }else if (array[i] < array[i+1])
    {
      array.erase(array.begin() + i + 1);
      i--;
      N--;
    } 
  }

  for(long unsigned int i = 0; i < N ; i++ ){
    array.pop_back();
  }


  for(const auto temp : array){
    cout<<temp;
  }
  cout<<endl;

}


int main(){
    string input1;
    string input2;
		vector<int> array;
    int N;
		cout<<"this program have bug , you can find it on the sc head"<<endl;
		assert(0);
    while(true){
			input1.clear();
			input2.clear();

			getline(cin,input1);
      getline(cin,input2);
				
      N = int(input2[0] - '0');
      array.clear();
      for (long unsigned int i = 0 ; i < input1.size();i++){
        array.push_back((int)(input1[i] - '0'));
      }

      if (cin.eof() || cin.fail()) break;
      solution(array,N);


    }

    return 0;
}
