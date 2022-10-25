#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define endl '\n'

void BubbleSort(int arr[], int n) {
    int flag;           // flag is used to check whether any swap takes place in current iteration or not
    for (int i = 0; i < n - 1; i++) {
        flag = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if(arr[j] > arr[j + 1]) {       
                // previous element greater than current element thus breaking rule of sorted array so we swap it
                swap(arr[j], arr[j + 1]);
                flag = 1;         
            }
        }
        if (!flag) break;        // means no swapping takes place in this iteration, so the array is now sorted 
    }
}

void SelectionSort(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
    	int minIndex = i;
	for (int j = i + 1; j < n; ++j) {
	    if (arr[minIndex] > arr[j]) {
	    	minIndex = j;
	    }
	}
	swap(arr[i], arr[minIndex]);
    }
}

int maximum_flow(){
    int ans=0,temp,now,pre;
    vector<int> v(n+1);
    while(temp=bfs(v)){
        now=sink;
        ans+=temp;
        while(now!=src){
            pre=v[now];
            flow_cap[pre][now]-=temp;
            flow_cap[now][pre]+=temp;
            now=pre;
        }
    }
    return ans;
}

int main()
{   
    string key,msg;
    int rn = 0;
    //cin >> rn;
    cin >> key >> msg >> rn;
    int ip[] = {58,50,42,34,26,18,10,2,60,52,44,36,28,20,12,4,62,54,46,38,30,22,14,6,
    64,56,48,40,32,24,16,8,57,49,41,33,25,17,9,1,59,51,43,35,27,19,11,3,
    61,53,45,37,29,21,13,5,63,55,47,39,31,23,15,7};
    string aip;
    for(int i = 0; i < 64; i++) {
        aip.pb(msg[ip[i]-1]);
    }
    //string z = "0000001000000000000000101000101000000000000000000000001010100010";
   // if(aip == z) {
      //  cout << "Jeet\n";
   // }
   // else {
     //   cout << "HHAR\n";
   // }
    cout << "Initial permutation: ";
    cout << aip << endl;
    string lmsg, rmsg;
    for(int i = 0; i < 32; i++){
        lmsg.pb(aip[i]);
    }
    for(int i = 32; i < 64; i++){
        rmsg.pb(aip[i]);
    }
    string aexp;
    int expt[] = {32,1,2,3,4,5,
                    4,5,6,7,8,9,
                    8,9,10,11,12,13,
                    12,13,14,15,16,17,
                    16,17,18,19,20,21,
                    20,21,22,23,24,25,
                    24,25,26,27,28,29,
                    28,29,30,31,32,1};
    
    for(int i = 0; i < 48; i++) {
        aexp.pb(rmsg[expt[i]-1]);
    }               
    string ck = "000000000000000000000000000000000101010100000100";
    cout << "After expansion aexp:- ";
    cout << aexp << endl;
    int pc1[] = {57,49,41,33,25,17,9,
                1,58,50,42,34,26,18,
                10,2,59,51,43,35,27,
                19,11,3,60,52,44,36,
                63,55,47,39,31,23,15,
                7,62,54,46,38,30,22,
                14,6,61,53,45,37,29,
                21,13,5,28,20,12,4};
                
    string kpc1;
    for(int i = 0; i < 56; i++) {
        kpc1.pb(key[pc1[i]-1]);
    }
    //string ckk = "00000000010000000001010000010000000000000000000000000001";
    cout << " Key  After pc1 :- ";
    cout << kpc1 << endl;
    
    int shift[] = {1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
    
    string kshift;
    for(int i = shift[rn-1]; i < kpc1.size(); i++) {
        kshift.pb(kpc1[i]);
    }
    kshift.pb(kpc1[0]);
    if(shift[rn-1] == 2) {
        kshift.pb(kpc1[1]);
    }
    cout << "After shifting of keypc1:- ";
    cout << kshift <<endl;
    
    string kpc2;
    int pc2[] = {14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10, 23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2, 41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32};
    
    for(int i = 0; i < 48; i++) {
        kpc2.pb(kshift[pc2[i]-1]);
    }
    cout << "key after keypc2:- ";
    cout << kpc2 <<endl;
    
    string rxor;
    for(int i = 0; i < 48; i++) {
        if(kpc2[i] == aexp[i]) {
            rxor.pb('0');
        }
        else {
            rxor.pb('1');
        }
    }
    cout << "After xor:- ";
    cout << rxor <<endl;
    int sbox[8][4][16]=  
	{{ 
        14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7, 
        0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8, 
        4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0, 
        15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13 
    }, 
    { 
        15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10, 
        3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5, 
        0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15, 
        13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9 
    }, 
    { 
        10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8, 
        13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1, 
        13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7, 
        1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12 
    }, 
    { 
        7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15, 
        13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9, 
        10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4, 
        3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14 
    }, 
    { 
        2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9, 
        14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6, 
        4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14, 
        11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3 
    }, 
    { 
        12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11, 
        10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8, 
        9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6, 
        4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13 
    }, 
    { 
        4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1, 
        13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6, 
        1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2, 
        6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12 
    }, 
    { 
        13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7, 
        1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2, 
        7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8, 
        2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11 
    }};
    
    string rsbox;
    for(int i = 0; i < 8; i++) {
        int r = 0;
        int temp = 0;
        r = (rxor[i*6]-'0')*2 + (rxor[i*6+5] - '0');
        int c = 0;
        c = (rxor[i*6 + 1]-'0')*8 + (rxor[i*6+2]-'0')*4 + (rxor[i*6+3]-'0')*2 + (rxor[i*6+4]-'0');
        temp = sbox[i][r][c];
        string stemp;
        for(int j = 0; j < 4; j++) {
            if(temp%2) {
                stemp.pb('1');
            }
            else {
                stemp.pb('0');
            }
            temp = temp/2;
        }
        reverse(stemp.begin(),stemp.end());
        rsbox += stemp;
    }
    cout << "Rxor after applying s-box:- ";
    cout << rsbox << endl;
    
    
    int bitsf[] = {16, 7, 20, 21, 29, 12, 28, 17, 1, 15, 23, 26, 5, 18, 31, 10, 2, 8, 24, 14, 32, 27, 3, 9, 19, 13, 30, 6, 22, 11, 4, 25};
    string rbs;
    for(int i = 0; i < 32; i++) {
        rbs.pb(rsbox[bitsf[i]-1]);
    }
    cout << "Rsbox after applying bitshuffle:- ";
    cout << rbs << endl;
    
    string rans;
    for(int i = 0; i < 32; i++) {
        if(rbs[i] == lmsg[i]) {
            rans.pb('0');
        }
        else {
            rans.pb('1');
        }
    }
    
    string finalans;
    finalans = rmsg;
    finalans += rans;
    cout << "final ans:- ";
    cout << finalans << endl;
    string ans;
    for(int i = 0; i < 16; i++) {
        int tt;
        tt = (finalans[i*4]-'0')*8 + (finalans[i*4 + 1]-'0')*4 + (finalans[i*4 + 2]-'0')*2 + (finalans[i*4 + 3]-'0');
        if(tt < 10) {
            ans += (char)(tt+48);
        }
        else {
            ans += (char)('a'+(tt-10));
        }
    }
    cout << "Ans in hexadecimal:- \n";
    cout << ans << endl;
    

}
