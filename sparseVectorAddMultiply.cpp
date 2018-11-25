#include "./Numerical-Recipes-master/nr3.h"
#include "./Numerical-Recipes-master/sort.h"
#include "./Numerical-Recipes-master/sparse.h"

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int i;

	//Add two sparse col vectors

	NRsparseCol a(10,4);  //declare col vector: VecInt row_ind=10, VecDoub val=4
	NRsparseCol b(10,5);  //declare col vector: VecInt row_ind=10, VecDoub val=4
	NRsparseCol c(10,6); //store result in c
	/*
		NRsparseCol(Int m,Int nnvals) : nrows(m), nvals(nnvals),	
		row_ind(nnvals,0),val(nnvals,0.0) {}
	*/

	//assigning index of each nnon-zero elem in a
	a.row_ind[0]=2; b.row_ind[0]=2;
	a.row_ind[1]=4; b.row_ind[1]=3;
	a.row_ind[2]=5; b.row_ind[2]=4;
	a.row_ind[3]=9; b.row_ind[3]=8; b.row_ind[4]=9;

	a.val[0]=12.34;
	a.val[1]=45.67;
	a.val[2]=16.70;
	a.val[3]=8.53;

	b.val[0]=4.15;
	b.val[1]=32.59;
	b.val[2]=61.18;
	b.val[3]=93.83;
	b.val[4]=76.11;
	
	//adding two vectors a & b
	if(a.nrows!=b.nrows) {	
		cerr << "Vectors of different sizes!" << endl;
		return 1;
	}

	//c=a+b;
	int index=0;
	int maxNval=max(a.nvals,b.nvals);
	cout << "maxNval= " << maxNval << endl;
	bool flag;
	for(i=0;i<maxNval;i++) {
		flag=false;
		for(int s=0;s<a.nvals;s++) {
			if(b.row_ind[i]==a.row_ind[s]) {
				c.row_ind[index]=b.row_ind[i];
				c.val[index]=a.val[s]+b.val[i];
				++index;
				flag=true;
			}
			
			if((s>=(a.nvals-1)) && (flag==false) && (c.val[index]==0)) {
				c.row_ind[index]=b.row_ind[i];
				c.val[index]=b.val[i];
				index++;
			}
			
		} 
	}


	for(i=0;i<a.nvals;i++) {
		flag=false;
		for(int k=0;k<b.nvals;k++) {
			if(a.row_ind[i] == b.row_ind[k])
				flag=true;
		
			if((k>=(b.nvals-1)) && (flag==false) && (c.val[index]==0)) {
				c.row_ind[index]=a.row_ind[i];
				c.val[index]=a.val[i];
				++index;
			}
		}
	}

	cout << "Print c vector row indices." << endl;
	for(i=0;i<c.nvals;i++) {
		cout << "c.row_ind[" << i << "]=" << c.row_ind[i] << endl;
	}


	//cout << "\nPrint SparseCol details" << endl;	
	//cout << "# of rows: " << a.nrows << endl;
	//cout << "# of non-zero values: " << a.nvals << endl;
	
	cout << "\nPrint c vector values" << endl;

	for(i=0;i<c.nvals;i++)
	{
		cout <<	 "c.val["<<i<<"]= " << c.val[i] << endl;

	}

	
	return 0;
}

