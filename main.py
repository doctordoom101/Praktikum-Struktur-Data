from prettytable import PrettyTable

MAX_SIZE = 100

class Peminjaman:
    def __init__(self, nama, nim, tanggal_peminjaman, kode_buku):
        self.nama = nama
        self.nim = nim
        self.tanggal_peminjaman = tanggal_peminjaman
        self.kode_buku = kode_buku

def tambah_data(data_peminjaman, nama, nim, tanggal_peminjaman, kode_buku):
    if len(data_peminjaman) >= MAX_SIZE:
        print("Data sudah penuh, tidak dapat menambah data lagi.")
        return

    data_peminjaman.append(Peminjaman(nama, nim, tanggal_peminjaman, kode_buku))
    print("Data berhasil ditambahkan.")

def edit_data(data_peminjaman, index, nama, nim, tanggal_peminjaman, kode_buku):
    if index < 0 or index >= len(data_peminjaman):
        print("Indeks tidak valid.")
        return

    data_peminjaman[index].nama = nama
    data_peminjaman[index].nim = nim
    data_peminjaman[index].tanggal_peminjaman = tanggal_peminjaman
    data_peminjaman[index].kode_buku = kode_buku
    print("Data berhasil diubah.")

def hapus_data(data_peminjaman, index):
    if index < 0 or index >= len(data_peminjaman):
        print("Indeks tidak valid.")
        return

    del data_peminjaman[index]
    print("Data berhasil dihapus.")

def tampil_data(data_peminjaman):
    table = PrettyTable(["Nama", "NIM", "Tanggal Peminjaman", "Kode Buku"])
    for peminjaman in data_peminjaman:
        table.add_row([peminjaman.nama, peminjaman.nim, peminjaman.tanggal_peminjaman, peminjaman.kode_buku])
    print(table)

def main():
    data_peminjaman = []

    while True:
        print("\nMenu:")
        print("1. Tambah Data")
        print("2. Edit Data")
        print("3. Hapus Data")
        print("4. Tampilkan Data")
        print("5. Keluar")

        choice = input("Pilihan Anda: ")

        if choice == '1':
            nama = input("Masukkan nama: ")
            nim = input("Masukkan NIM: ")
            tanggal_peminjaman = input("Masukkan tanggal peminjaman (dd/mm/yyyy): ")
            kode_buku = input("Masukkan kode buku (nomor rak-kategori, contoh: 1234-R): ")
            tambah_data(data_peminjaman, nama, nim, tanggal_peminjaman, kode_buku)
        elif choice == '2':
            index = int(input("Masukkan indeks data yang ingin diubah: "))
            nama = input("Nama baru: ")
            nim = input("NIM baru: ")
            tanggal_peminjaman = input("Tanggal peminjaman baru (dd/mm/yyyy): ")
            kode_buku = input("Kode buku baru: ")
            edit_data(data_peminjaman, index, nama, nim, tanggal_peminjaman, kode_buku)
        elif choice == '3':
            index = int(input("Masukkan indeks data yang ingin dihapus: "))
            hapus_data(data_peminjaman, index)
        elif choice == '4':
            tampil_data(data_peminjaman)
        elif choice == '5':
            print("Terima kasih telah menggunakan program ini.")
            break
        else:
            print("Pilihan tidak valid. Silakan coba lagi.")

if __name__ == "__main__":
    main()
