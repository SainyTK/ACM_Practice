#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class FenwickTree
{
	private:
	vector<int> ft;
	
	inline int LSOne(int s)
    {
      return s & (-s);
    }

	public:
    FenwickTree() {}

  	FenwickTree(int n)
    {
      ft.assign(n + 1, 0);
    }

	int rsq(int b)
    {
      int sum = 0;

      for (; b; b -= LSOne(b))
        sum += ft[b];

      return sum;
    }

    int rsq(int a, int b)
    {
      return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
    }

    void adjust(int k, int v)
    {
      for (; k < (int) ft.size(); k += LSOne(k))
        ft[k] += v;
    }

    void set(int k, int v)
    {
      int diff = v - rsq(k, k);

      adjust(k, diff);
    }
};

int main(){
	ios_base::sync_with_stdio(false);

	int round = 0;
	while(1){
		int n;
		cin >> n;
		
		if(n==0)
		 break;
		
		FenwickTree ft(n+1);
		
		for(int i=1;i<=n;i++){
			int r;
			cin >> r;
			ft.set(i,r);
		}
		
		if(round!=0)
			cout << "\n";
		cout << "Case " << round+1 << ":\n";
		
		string s;
		int x;
		int y;
			
		do{
			cin >> s;
			if(s=="END"){
				break;
			}
			cin >> x >> y;
			switch(s[0]){
				case 'S':
					ft.set(x,y);
					break;
				case 'M':
					cout << ft.rsq(x,y) << "\n";
					break;
			}
		
		}while(1);
		round++;
	}
	
	return 0;
}
