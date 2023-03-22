#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<string>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    map<string, set<string> > rep_info;
    /*
        report 정보를 저장할 map
         - key : 신고받은 사람(string)
         - value : 신고한 사람(set - 중복허용 X)
    */
    for (auto i : report) {
        int pos = i.find(" ");
        rep_info[i.substr(pos + 1, i.length())].insert(i.substr(0, pos));
    }
    map<string, int> count;
    /*
        신고자가 몇번의 처리메일을 받는지 저장할 map
         - key : 신고자
         - value : 처리 메일 수
    */
    for (auto i : rep_info) {
        if (i.second.size() >= k) {
            for (string j : i.second) {
                count[j]++;
            }
        }
    }
    vector<int> answer;
    
    for (auto i : id_list) {
        answer.push_back(count[i]);
    }
    return answer;
}

