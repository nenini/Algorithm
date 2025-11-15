#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=1;i<=10;i++){
        vector<int> box;
        int dump;
        cin>>dump;
        for(int j=0;j<100;j++){
            int num;
            cin>>num;
            box.push_back(num);
        }
        for(int j=0;j<dump;j++){
            int max_index=max_element(box.begin(),box.end())-box.begin();
            int min_index=min_element(box.begin(),box.end())-box.begin();
            box[max_index]--;
            box[min_index]++;
        }
        int max_num=*max_element(box.begin(),box.end());
        int min_num=*min_element(box.begin(),box.end());
        cout<<"#"<<i<<" "<<max_num-min_num<<"\n";
        
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}