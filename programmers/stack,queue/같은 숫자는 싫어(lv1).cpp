#include <vector>
#include <iostream> 
using namespace std;

// vector.back()  맨 뒤 참조
// vector.push_back(); // 맨 뒤 반환

vector<int> solution(vector<int> arr) 
{
    vector<int> answer; 
    
    for (int i : arr) { 
        int item = -1;
        if(answer.size() > 0) {
            item = answer.back();
        } 
        if(item != i) {
            answer.push_back(i); 
        }
    }
  
    return answer;
}
