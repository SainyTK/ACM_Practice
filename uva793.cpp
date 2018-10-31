#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

class WQUPC
{
  private:
    vector<int> id, sz;

//    int root(int i)
//    {
//      while (id[i] != id[id[i]])
//      {
//        id[i] = id[id[i]];
//        i = id[i];
//      }
//
//      return i;
//    }
 	int root(int p)  // Recursive path compression
    {
      if (id[p] == p) return p;
      else return (id[p] = root(id[p]));
    }

  public:
    WQUPC(int N)
    {
      for (int i = 0; i < N; i++)
        id.push_back(i);

      sz.assign(N, 1);
    }

    bool find(int p, int q)
    {
      return root(p) == root(q);
    }

    void unite(int p, int q)
    {
      int x = root(p);
      int y = root(q);

      if (x == y) return;

      if (sz[x] < sz[y])
      {
        id[x] = y;
        sz[y] += sz[x];
      }
      else
      {
        id[y] = x;
        sz[x] += sz[y];
      }
    }
};

int main(){
	
	int num_case;
	cin >> num_case;
	cin;
	
	for(int idx = 0; idx < num_case; idx++){
		int n_com;
		string c;
		int i,j;
		int success=0,unsuccess=0;
		cin >> n_com ;
		WQUPC uf(n_com+1);
		do{
			fflush(stdin);
			getline(cin,c);

			if(c.empty()){
				break;
			}
		
			i = c[2] - '0';
			j = c[4] - '0';
		
			if(c[0]=='c'){
				uf.unite(i,j);
			}
		
			if(c[0]=='q'){
				if(uf.find(i,j))
					success++;
				else
					unsuccess++;
			}
		}while(1);
	
	cout << success << "," <<unsuccess << "\n\n";
	}
	
	return 0;
}
