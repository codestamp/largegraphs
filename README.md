#largegraphalgorithms

This repository deals with large graph representations on
computer. The adjacency matrix so derived is usually sparse and
different techniques are used to compress in order to save space as
well as processing time. One of the scheme is from Numerical Recipes
3rd edition book from the chapter Sparse Linear Systems (Section 2.7.5 
		Indexed Storage of Sparse Matrices)

File: sparseVectorAddMultiply.cpp

This code is also pasted on the Numerical Recipe's forum --> http://numerical.recipes/forum/showthread.php?p=5591#post5591

It can be seen that the time complexity of the following code is quadratic O(nvals)^2 
where nvals is the max number of non-zero elements in either of the two vectors. 
In normal case when we do not consider NRsparseCol representation it would have been a linear O(n). 
The NRsparseCol vector representation is suitable when n >> nvals.

