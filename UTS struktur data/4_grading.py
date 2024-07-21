class Mahasiswa:
    def __init__(self):
        self.Nim = ""
        self.Nama = ""
        self.QuizStruData1 = 0
        self.QuizStruData2 = 0
        self.Rata2QuizStruData = 0.0
        self.Predikat = ""

def inputData(mhs):
    mhs.Nim = input("NIM: ")
    mhs.Nama = input("Nama: ")
    mhs.QuizStruData1 = int(input("Quiz Struktur Data 1: "))
    mhs.QuizStruData2 = int(input("Quiz Struktur Data 2: "))

    mhs.Rata2QuizStruData = (mhs.QuizStruData1 + mhs.QuizStruData2) / 2.0

    if mhs.Rata2QuizStruData >= 88:
        mhs.Predikat = "Cumlaude"
    elif mhs.Rata2QuizStruData >= 77 and mhs.Rata2QuizStruData < 88:
        mhs.Predikat = "Memuaskan"
    elif mhs.Rata2QuizStruData >= 60 and mhs.Rata2QuizStruData < 77:
        mhs.Predikat = "Cukup"
    else:
        mhs.Predikat = "Tidak Lulus"

def tampilkanData(mhs, n):
    print("Daftar Nilai MK Struktur Data Anggota Kelompok Belajar Struktur Data")
    print("="*90)
    print("{:<3} {:<15} {:<25} {:<30} {:<12}".format("No", "NIM", "Nama", "Rata2 Quiz Struktur Data", "Predikat"))
    print("="*90)
    for i in range(n):
        print("{:<3} {:<15} {:<30} {:<25.2f} {:<12}".format(i + 1, mhs[i].Nim, mhs[i].Nama, mhs[i].Rata2QuizStruData, mhs[i].Predikat))
    print("="*90)

if __name__ == "__main__":
    n = int(input("Jumlah mahasiswa: "))  # Number of students
    mhs = [Mahasiswa() for _ in range(n)]

    for i in range(n):
        print(f"Masukkan data Mahasiswa ke-{i+1}")
        inputData(mhs[i])

    tampilkanData(mhs, n)

    countCumlaude = 0
    countMemuaskan = 0
    countCukup = 0
    for i in range(n):
        if mhs[i].Predikat == "Cumlaude":
            countCumlaude += 1
        elif mhs[i].Predikat == "Memuaskan":
            countMemuaskan += 1
        elif mhs[i].Predikat == "Cukup":
            countCukup += 1

    print(f"Jumlah yang predikat 'Cumlaude': {countCumlaude} Orang")
    print(f"Jumlah yang predikat 'Memuaskan': {countMemuaskan} Orang")
    print(f"Jumlah yang predikat 'Cukup': {countCukup} Orang")
