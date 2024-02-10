#include <bits/stdc++.h>
using namespace std;

vector<int> sortAndMerge(const vector<int>& vec1, const vector<int>& vec2) {
    vector<int> merged;
    int i = 0, j = 0;
    while (i < vec1.size() && j < vec2.size()) {
        if (vec1[i] < vec2[j])
            merged.push_back(vec1[i++]);
        else
            merged.push_back(vec2[j++]);
    }
    while (i < vec1.size())
        merged.push_back(vec1[i++]);
    while (j < vec2.size())
        merged.push_back(vec2[j++]);

    return merged;
}

int main() {
    vector<int> vec1, vec2;
    int n, m;
    
    cout << "Enter the size of the first vector: ";
    cin >> n;
    cout << "Enter the elements of the first vector: ";
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        vec1.push_back(x);
    }

    cout << "Enter the size of the second vector: ";
    cin >> m;
    cout << "Enter the elements of the second vector: ";
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        vec2.push_back(x);
    }
    sort(vec1.begin(),vec1.end());
    sort(vec2.begin(),vec2.end());
    vector<int> sortedAndMerged = sortAndMerge(vec1, vec2);

    cout << "Merged and sorted vector: ";
    for (int x : sortedAndMerged) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

