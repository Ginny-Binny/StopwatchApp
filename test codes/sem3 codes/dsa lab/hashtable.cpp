#include<iostream>
#include<list>
#include<cstring>

using namespace std;

// hashtable to implement 905, jimmy

class HashTable {
    private:
    static const int hashGroups=10;
    list<pair<int, string >> table[hashGroups];// List 1, index 0 , list 2 , index 1.....

    public :
    bool isEmpty() const;
    int hashFunction(int key);
    void insertItem(int key, string value);
    void removeItem(int key);
    string searchTable(int key);
    void printTable();

};

bool HashTable::isEmpty()  const{
    int sum{};
    for(int i{}; i<hashGroups; i++){
        sum += table[i].size();

    }

    if(!sum){
        return true;
    }

    return false;

}

int HashTable::hashFunction(int key){
    return key % hashGroups; // key : 905 in return this function will spill out 5

}

void HashTable::insertItem(int key, string value){
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr= begin(cell);
    bool keyExists =false;
    for(; bItr!= end(cell); bItr++){
        if(bItr->first== key){
            keyExists=true;
            bItr->second=value;
            cout<<"warning key exists, value replaced "<<endl;
            break;

        }
    }
    if(!keyExists){
        cell.emplace_back(key, value);

    }
    return;
}

void HashTable::removeItem(int key){
    int hashValue= hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr= begin(cell);
    bool keyExists= false;
    for(; bItr != end(cell); bItr++){
        if(bItr->first==key){
            keyExists=true;
            bItr=cell.erase(bItr);
            cout<<"info, pair removed"<<endl;
            break;
        }
    }
    if(!keyExists){
            cout<<"warning ,key not found , pair not removed "<<endl;
            
        }
        return;
    }

    void HashTable::printTable(){
        for(int i{}; i<hashGroups;i++){
            if(table[i].size()==0) continue;
            
            auto bItr= table[i].begin();
            for(; bItr != table[i].end(); bItr++){
                cout<<"info , key: "<<bItr->first<<"Value: "<<bItr->second<<endl;

            }
        }
        return;
    }

int main(){
    HashTable HT;
    if(HT.isEmpty()){
        cout<<"correct answer, good job";
        
    }
    else{
        cout<<"oh we need to check out code"<<endl;
    }


    HT.insertItem(905,"Ram");
    HT.insertItem(201,"shayam");
    HT.insertItem(332,"roy");
    HT.insertItem(124,"Ramu");
    HT.insertItem(107,"shyam");
    HT.insertItem(929,"Rohit");
    HT.insertItem(928,"Rahul");
    HT.insertItem(928,"Rahim");

    HT.printTable();

    HT.removeItem(332);
    HT.removeItem(100);

    if(HT.isEmpty()){
        cout<<"oh we need to check out code"<<endl;
        
    }
    else{
        cout<<"correct ans "<<endl;
    }
return 0;
}