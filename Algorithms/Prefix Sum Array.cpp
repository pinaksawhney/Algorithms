// Prefix Sum Algorithm
// Time Complexity for any number of queries 0(n)
// Space complexity O(1)
#include <iostream>
#include <vector>

using namespace std;
int main(){
    int n{}; int data{};
    vector<int>vec(n,0);
    cout<<"Enter size of array: "<<endl;
    cin>>n;int a{};int b{};
    for(int i=0;i<n;i++){
        cout<<"Enter Data: "<<endl;
        cin>>data;
        vec.push_back(data);
    }
    for(int i=0;i<n;i++){
        vec[i] = vec[i]+vec[i-1];
    }
    int m{};
    cout<<"No. of queries:"<<endl;
    cin>>m;
    while(m) {
        cout << "Find sum from a to b: " << endl;
        cin >> a >> b;
        cout<<vec[b]-vec[a-1]<<endl;
        m-=1;
    }
    return 0;
}