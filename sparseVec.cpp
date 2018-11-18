#include "./Numerical-Recipes-master/nr3.h"
#include "./Numerical-Recipes-master/sort.h"
#include "./Numerical-Recipes-master/sparse.h"

#include <iostream>

using namespace std;

int main() {
	NRsparseCol a(10,4);  //declare col vector
	
	int i;
	//test a vector
	VecInt t(5,0);
	
	for(i=0;i<5;i++)
		t[i]=i+1;
	

	cout << "print vector" << endl;	
	for(i=0;i<5;i++)
		cout << t[i] << endl;
	//populate the vector


	for(i=0;i<4;i++) {
		a.row_ind[i]=i+1;
	}

	cout << "print SparseCol details" << endl;	
	cout << "# of rows: " << a.nrows << endl;
	cout << "# of non-zero values: " << a.nvals << endl;
		
	return 0;
}

