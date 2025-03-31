// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include <unordered_map>

void frequency (string s)
{
    unordered_map<char,int> mp;
    // to access character by character use [] operator
    for(int i=0;i<s.length();i++)
    { 
        if (mp.find(s[i]) == mp.end())
        {
            mp.insert(make_pair(s[i],1));
        }
        else
        { //update frequency
            mp[s[i]]++;
        }
    }
    //traverse the map
    /*dont use this as we have key value:
    for(int i=0;i<s.length();i++)
    {
        
    }*/
    for(auto& i : mp )
    {
        cout<< i.first <<" "<<i.second <<"\n";
    }
}
int main() {
    // Write C++ code here
    cout << "Frequency of each character in a String";
    string s="geefforgeek";
    frequency(s);
    return 0;
}