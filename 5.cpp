#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}
int nextPrime(int n) {
    if (n <= 1) return 2;
    int prime = n;
    bool found = false;
    while (!found) {
        prime++;
        if (isPrime(prime)) found = true;
    }
    return prime;
}
vector<list<int>> rehash(const vector<list<int>>& oldHashTable) {
    int newSize = nextPrime(oldHashTable.size() * 2);
    vector<list<int>> newHashTable(newSize);
    for (const auto& chain : oldHashTable) {
        for (int key : chain) {
            int hashValue = key % newSize;
            newHashTable[hashValue].push_back(key);
        }
    }
    return newHashTable;
}
void insert(vector<list<int>>& hashTable, int key) {
    int hashValue = key % hashTable.size();
    hashTable[hashValue].push_back(key);
}
void printHashTable(const vector<list<int>>& hashTable) {
    cout << "Hash Table:" << endl;
    for (int i = 0; i < hashTable.size(); ++i) {
        cout << "[" << i << "]: ";
        for (int key : hashTable[i]) {
            cout << key << " -> ";
        }
        cout << "NULL" << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of integers to store: ";
    cin >> n;

    int size = nextPrime(n);
    vector<list<int>> hashTable(size);
    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        insert(hashTable, num);
    }
    printHashTable(hashTable);

    cout << "Performing rehashing..." << endl;
    hashTable = rehash(hashTable);
    printHashTable(hashTable);

    return 0;
}
