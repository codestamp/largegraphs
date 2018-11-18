#include "./Numerical-Recipes-master/nr3.h"
#include "./Numerical-Recipes-master/sort.h"
#include "./Numerical-Recipes-master/sparse.h"

#include <iostream>

using namespace std;

int main() {
	/* create a vector of 5 sparse cols --> 2D (10 x 5) matrix
		
	   -----------
	   |0|1|2|3|4|   --> NRvector of size 5
	   -----------
	    | .....  --> so 5 NRsparse cols depicted as rows each of size 10
	    |
	    |  -------------
	    -->|0|1| ... |9|
	       ------------- 
	*/
	const int n=5;  //# of sparse cols
	int nvals,i,j; //# non-zero values in each col
	NRvector<NRsparseCol *> b(n);  // declare NRvector of size n
	
	for(j=0;j<n;j++) {
		nvals=5;
		//each NRsparseCol of size 10 with 4 non-zero value elems 
		b[j]=new NRsparseCol(10,nvals); //each NRsparseCol of size 10 with 
	}

	//populate NRvector 'b'
	int count=0;
	for(j=0;j<n;j++) {
		b[j]->row_ind[count]=j; //row indices of non-zeros
		b[j]->val[count]=(float)(j+count+1.3)/5.2; //array of non-zero values
		count++;
	}

	count=0;
	//print the compressed sparse matrix
	for(j=0;j<n;j++) {
		cout << "Row Index: "<< b[j]->row_ind[count] 
			<< ", Value: " << b[j]->val[count]<< endl;
			count++;
	}



	
	NRsparseCol a(10,4);  //declare col vector
	
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

