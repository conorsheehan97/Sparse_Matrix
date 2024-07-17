#include "Sparse.h"
#include <iomanip>
#include <iostream>

using namespace std;

void create_sparse_matrix(Sparse &s)
{
	cout << "Enter dimensions of matrix (rows followed by columns) \n"; 
	int row, column, num_non_zero;
	cin >> row >> column;
	s.rows = row;
	s.columns = column;
	cout << "Now please enter the number of non-zero elements \n";
	cin >> num_non_zero;
	s.num_val = num_non_zero;
	for (int i = 0; i < num_non_zero; i++)
	{
		int row_item, column_item, value_item; 
		cout << "Please enter row, then column, then value of the non-zero value \n";
		Element item;
		cin >> item.alpha >> item.beta >> item.gamma;
		s.elements.push_back(item);
	}
	s.num_val = s.elements.size();
}

void display(Sparse s)
{
	int i, j, k = 0;
	for (int i = 0; i < s.rows; i++)
	{
		for (int j = 0; j < s.columns; j++)
		{
			if (k >= s.elements.size())
			{
				cout << " 0 ";
			}
			else if (i == s.elements[k].alpha && j == s.elements[k].beta)
			{
				cout << " " <<  s.elements[k].gamma << " ";
				k++;
			}
			else
			{
				cout << " 0 ";
			}
		}
		cout << "\n";
	}
}

Sparse add(Sparse* s1, Sparse* s2)
{
	Sparse s3;
	int i, j, k;
	i = j = k = 0;
	while (i < (s1->num_val) && j < (s2->num_val))
	{
		if (s1->elements[i].alpha < s2->elements[j].alpha)
		{
			s3.elements.push_back(s1->elements[i]);
			i++;
		}
		else if (s1->elements[i].alpha > s2->elements[j].alpha)
		{
			s3.elements.push_back(s2->elements[j]);
			j++;
		}
		else
		{
			if (s1->elements[i].beta < s2->elements[j].beta)
			{
				s3.elements.push_back(s1->elements[i]);
				i++;
			}
			else if (s1->elements[i].beta > s2->elements[j].beta)
			{
				s3.elements.push_back(s2->elements[j]);
				j++;
			}
			else
			{
				s3.elements.push_back(s1->elements[i]);
				s3.elements.back().gamma += s2->elements[j].gamma;
				i++;
				j++;
			}
		}
	}
	for (;i < s1->num_val;i++)
	{
		s3.elements.push_back(s1->elements[i]);
		i++;
		k++;
	}
	for (; j < s2->num_val; j++)
	{
		s3.elements[k] = s2->elements[j];
		j++;
		k++;
	}
	s3.columns = s1->columns;
	s3.rows = s1->rows;
	s3.num_val = s3.elements.size();
	return s3;

}
int main()
{
	Sparse s1,s2,s3; 
	create_sparse_matrix(s1);
	create_sparse_matrix(s2);
	cout << "\n";
	s3 = add(&s1, &s2);
	cout << "Sparse Matrix 1\n";
	display(s1);
	cout << "Sparse Matrix 2\n";
	display(s2);
	cout << "Resultant Addition Matrix\n";
	display(s3);
	return 0;
}