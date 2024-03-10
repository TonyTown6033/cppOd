/* mem allocate 
 * 	best allocate 
 */

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;


vector<string> SplitString(const string &input, const char deli){
	stringstream ss(input);
	string token;
	vector<string> tokens;

	while (getline(ss,token,deli))
	{
		tokens.push_back(token);
	}

	return tokens;
}
bool compareFunction(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0]; // 根据第一列的值进行比较
}

vector<bool> Myallocate(vector<vector<int>> memPool, vector<int>request){
	vector<bool> response;
	bool state;
	for(auto memReq : request){
		state = false;
		for(long unsigned int  i=0;i<memPool.size();i++){
			if (memReq <= memPool[i][0])
				if(memPool[i][1] >= 1 ) { memPool[i][1]-=1 ; state = true ; break;}
		}
		response.push_back(state);
	}

	return response;
}


int main(){
	vector<vector<int>> memPool;
	vector<int> request;
	vector<string> tokens;
	vector<string> member;
	string token;
	vector<bool> states;
	while(true){
		memPool.clear();
		request.clear();
		tokens.clear();
		token.clear();
		getline(cin,token);
		tokens = SplitString(token,',');
		for(auto str : tokens){
			member.clear();
			member = SplitString(str,':');
			memPool.push_back({stoi(member[0]),stoi(member[1])});
			}

		token.clear();
		tokens.clear();
		getline(cin,token);
		tokens = SplitString(token,',');
		for(auto str: tokens){
			request.push_back(stoi(str));
		}

		sort(memPool.begin(),memPool.end(),compareFunction);

		if(cin.eof() || cin.fail()) break;
		states = Myallocate(memPool,request);
		for(const auto state : states){
			cout << state << ',' ;
		}
		cout<<endl;

		
	}
	return 0;
}
