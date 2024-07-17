class Element:
    def __init__(self, alpha, beta, gamma):
        self.alpha = alpha
        self.beta = beta
        self.gamma = gamma


class Sparse:
    def __init__(self):
        self.rows = 0
        self.columns = 0
        self.num_val = 0
        self.elements = []


def create_sparse_matrix(s):
    row = int(input("Enter dimensions of matrix (rows followed by columns): "))
    column = int(input())
    s.rows = row
    s.columns = column

    num_non_zero = int(input("Now please enter the number of non-zero elements: "))
    s.num_val = num_non_zero

    for _ in range(num_non_zero):
        print("Please enter row, then column, then value of the non-zero value")
        row_item = int(input())
        column_item = int(input())
        value_item = int(input())
        item = Element(row_item, column_item, value_item)
        s.elements.append(item)

    s.num_val = len(s.elements)


def display(s):
    k = 0
    for i in range(s.rows):
        for j in range(s.columns):
            if k >= len(s.elements):
                print(" 0 ", end=" ")
            elif i == s.elements[k].alpha and j == s.elements[k].beta:
                print(f" {s.elements[k].gamma} ", end=" ")
                k += 1
            else:
                print(" 0 ", end=" ")
        print("\n")

def add(s1, s2):
    s3 = Sparse()
    i = j = k = 0

    while i < s1.num_val and j < s2.num_val:
        if s1.elements[i].alpha < s2.elements[j].alpha:
            s3.elements.append(s1.elements[i])
            i += 1
        elif s1.elements[i].alpha > s2.elements[j].alpha:
            s3.elements.append(s2.elements[j])
            j += 1
        else:
            if s1.elements[i].beta < s2.elements[j].beta:
                s3.elements.append(s1.elements[i])
                i += 1
            elif s1.elements[i].beta > s2.elements[j].beta:
                s3.elements.append(s2.elements[j])
                j += 1
            else:
                new_element = Element(s1.elements[i].alpha, s1.elements[i].beta, s1.elements[i].gamma + s2.elements[j].gamma)
                s3.elements.append(new_element)
                i += 1
                j += 1

    while i < s1.num_val:
        s3.elements.append(s1.elements[i])
        i += 1

    while j < s2.num_val:
        s3.elements.append(s2.elements[j])
        j += 1

    s3.columns = s1.columns
    s3.rows = s1.rows
    s3.num_val = len(s3.elements)

    return s3

# Example usage
sparse_matrix1 = Sparse()
create_sparse_matrix(sparse_matrix1)

sparse_matrix2 = Sparse()
create_sparse_matrix(sparse_matrix2)

sparse_matrix3 = add(sparse_matrix1, sparse_matrix2)
print("Sparse Matrix 1:")
display(sparse_matrix1)
print("Sparse Matrix 2:")
display(sparse_matrix2)
print("Resultant Additional Matrix:")
display(sparse_matrix3)
display(sparse_matrix3)