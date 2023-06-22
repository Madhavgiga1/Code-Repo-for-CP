#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool comparePairs(pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
}
int main(){
	vector<pair<int, int>> myPairs = { {1, 4}, {2, 2}, {3, 7}, {4, 1} };

    sort(myPairs.begin(), myPairs.end(), comparePairs);
	for(auto g:myPairs){
		cout<<g.first<<" "<<g.second;
		cout<<endl;
	}
	return 0;
}
/*#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool comparePairs(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.second < b.second;
}

int main() {
    std::vector<std::pair<int, int>> myPairs = { {1, 4}, {2, 2}, {3, 7}, {4, 1} };

    std::sort(myPairs.begin(), myPairs.end(), comparePairs);

    for (const auto& pair : myPairs) {
        std::cout << "(" << pair.first << ", " << pair.second << ") ";
    }

    return 0;
}*/
