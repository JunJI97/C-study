#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> arr(n,1); // 1로 채운 n크기의 배열을 선언한다는 의미
    
    for(int i=0; i<lost.size(); i++) {
        arr[lost[i]-1] -=1;      
    }
    
    for(int i=0; i<reserve.size(); i++) {
        arr[reserve[i]-1] +=1;      
    }
    
    for(int i=0; i<n; i++) { 
        int item = arr[i];
        int prev = 1;
        if(i !=0) {
            prev = arr[i-1];
        }
        int next = 1;
        if(i != n-1) {
            next = arr[i+1]; 
        } 
        
        if(item == 1) { // 본인 체육복만 가진 경우
            answer++;
        } else if (item == 2) { // 여벌 옷을 가진 경우
            answer++;
            if(prev == 0) { // 왼쪽에 빌려줌
                arr[i]--;
                answer++;
            } else if (next == 0) { // 오른쪽에 빌려줌
                arr[i]--;
                arr[i+1]++; 
            }
        }  
    } 
    return answer;
}
