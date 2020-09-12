#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<fstream>
using namespace std;
int main(){
    ifstream ifs("music.txt");
    ofstream ofs_pitch("pitch.txt"),ofs_until_second("until_second.txt");
    vector<int>pitch;
    vector<double>until_second;
    int bpm;
    ifs>>bpm;
    string p;
    double l,sum=0;
    map<string,int>p2num={{"ド",60},{"レ",62},{"ミ",64},{"ファ",65},{"ファ#",66},{"ソ",67},{"ソ#",68},{"ラ",69},{"シ",71},{"高ド",72},{"休",0}};
    while(ifs>>p>>l){
        sum+=l*60/bpm;
        pitch.push_back(p2num[p]);
        until_second.push_back(sum);
    }
    int sz=pitch.size();
    for(int i=0;i<sz;i++){
        ofs_pitch<<pitch[i];
        ofs_until_second<<until_second[i];
        if(i!=sz-1){
            ofs_pitch<<endl;
            ofs_until_second<<endl;
        }
    }
    return 0;
}
