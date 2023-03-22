#include <string>
#include <vector>

using namespace std;

int cnt = 0;

void DFS(vector<int> numbers, int target, int L, int sum) {
    if (L == numbers.size()) {
        if (sum == target) {
            cnt++;
        }
    }
    else {
        DFS(numbers, target, L + 1, sum + numbers[L]);
        DFS(numbers, target, L + 1, sum - numbers[L]);
    }
}
int solution(vector<int> numbers, int target) {
    int answer = 0; 
    DFS(numbers, target, 0, 0);
    answer = cnt;
    return answer;
}