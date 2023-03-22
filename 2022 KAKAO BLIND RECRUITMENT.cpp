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
        report ������ ������ map
         - key : �Ű���� ���(string)
         - value : �Ű��� ���(set - �ߺ���� X)
    */
    for (auto i : report) {
        int pos = i.find(" ");
        rep_info[i.substr(pos + 1, i.length())].insert(i.substr(0, pos));
    }
    map<string, int> count;
    /*
        �Ű��ڰ� ����� ó�������� �޴��� ������ map
         - key : �Ű���
         - value : ó�� ���� ��
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

