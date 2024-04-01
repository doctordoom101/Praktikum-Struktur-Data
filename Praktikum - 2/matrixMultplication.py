def multiply_matrices(matrix1, matrix2):
    rows1, cols1 = len(matrix1), len(matrix1[0])
    cols2 = len(matrix2[0])
    result = [[0 for _ in range(cols2)] for _ in range(rows1)]

    for i in range(rows1):
        for j in range(cols2):
            for k in range(cols1):
                result[i][j] += matrix1[i][k] * matrix2[k][j]

    return result

def display_matrix(matrix):
    for row in matrix:
        print(" ".join(map(str, row)))

if __name__ == "__main__":
    print("##  Program Python Perkalian Matriks  ##")
    print("=======================================")

    rows1 = int(input("Masukkan jumlah baris matriks pertama: "))
    cols1 = int(input("Masukkan jumlah kolom matriks pertama: "))

    rows2 = int(input("Masukkan jumlah baris matriks kedua: "))
    cols2 = int(input("Masukkan jumlah kolom matriks kedua: "))

    if cols1 != rows2:
        print("Error: Jumlah kolom matriks pertama tidak sama dengan jumlah baris matriks kedua.")
        exit(1)

    print("Masukkan elemen matriks pertama:")
    matrix1 = [[int(input(f"Baris {i + 1}, kolom {j + 1} = ")) for j in range(cols1)] for i in range(rows1)]

    print("\nMasukkan elemen matriks kedua:")
    matrix2 = [[int(input(f"Baris {i + 1}, kolom {j + 1} = ")) for j in range(cols2)] for i in range(rows2)]
    
    print("\nMatriks Pertama:")
    display_matrix(matrix1)

    print("\nMatriks Kedua:")
    display_matrix(matrix2)

    result = multiply_matrices(matrix1, matrix2)

    print("\nMatriks Hasil:")
    display_matrix(result)
