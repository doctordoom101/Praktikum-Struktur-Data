import tkinter as tk
from tkinter import ttk
from prettytable import PrettyTable

MAX_SIZE = 100

class Peminjaman:
    def __init__(self, nama, nim, tanggal_peminjaman, kode_buku):
        self.nama = nama
        self.nim = nim
        self.tanggal_peminjaman = tanggal_peminjaman
        self.kode_buku = kode_buku

class Perpustakaan:
    def __init__(self):
        self.data_peminjaman = []

    def tambah_data(self, nama, nim, tanggal_peminjaman, kode_buku):
        if len(self.data_peminjaman) >= MAX_SIZE:
            print("Data sudah penuh, tidak dapat menambah data lagi.")
            return

        self.data_peminjaman.append(Peminjaman(nama, nim, tanggal_peminjaman, kode_buku))
        print("Data berhasil ditambahkan.")
        self.update_table()

    def edit_data(self, index, nama, nim, tanggal_peminjaman, kode_buku):
        if index < 0 or index >= len(self.data_peminjaman):
            print("Indeks tidak valid.")
            return

        self.data_peminjaman[index].nama = nama
        self.data_peminjaman[index].nim = nim
        self.data_peminjaman[index].tanggal_peminjaman = tanggal_peminjaman
        self.data_peminjaman[index].kode_buku = kode_buku
        print("Data berhasil diubah.")
        self.update_table()

    def hapus_data(self, index):
        if index < 0 or index >= len(self.data_peminjaman):
            print("Indeks tidak valid.")
            return

        del self.data_peminjaman[index]
        print("Data berhasil dihapus.")
        self.update_table()

    def update_table(self):
        self.table.delete(*self.table.get_children())
        for peminjaman in self.data_peminjaman:
            self.table.insert("", "end", values=[peminjaman.nama, peminjaman.nim, peminjaman.tanggal_peminjaman, peminjaman.kode_buku])

def main():
    root = tk.Tk()
    root.title("Perpustakaan")

    perpustakaan = Perpustakaan()

    frame = ttk.Frame(root)
    frame.pack(padx=10, pady=10)

    # Create Treeview widget
    columns = ("Nama", "NIM", "Tanggal Peminjaman", "Kode Buku")
    perpustakaan.table = ttk.Treeview(frame, columns=columns, show="headings")
    perpustakaan.table.heading("Nama", text="Nama")
    perpustakaan.table.heading("NIM", text="NIM")
    perpustakaan.table.heading("Tanggal Peminjaman", text="Tanggal Peminjaman")
    perpustakaan.table.heading("Kode Buku", text="Kode Buku")
    perpustakaan.table.pack(side="left")

    # Add scrollbar
    scrollbar = ttk.Scrollbar(frame, orient="vertical", command=perpustakaan.table.yview)
    scrollbar.pack(side="right", fill="y")
    perpustakaan.table.configure(yscrollcommand=scrollbar.set)

    # Create buttons
    button_frame = ttk.Frame(root)
    button_frame.pack(pady=10)

    ttk.Button(button_frame, text="Tambah Data", command=lambda: tambah_data()).pack(side="left")
    ttk.Button(button_frame, text="Edit Data", command=lambda: edit_data()).pack(side="left")
    ttk.Button(button_frame, text="Hapus Data", command=lambda: hapus_data()).pack(side="left")
    ttk.Button(button_frame, text="Keluar", command=root.destroy).pack(side="left")

    def tambah_data():
        top = tk.Toplevel(root)
        top.title("Tambah Data")

        ttk.Label(top, text="Nama:").grid(row=0, column=0, padx=5, pady=5)
        nama_entry = ttk.Entry(top)
        nama_entry.grid(row=0, column=1, padx=5, pady=5)

        ttk.Label(top, text="NIM:").grid(row=1, column=0, padx=5, pady=5)
        nim_entry = ttk.Entry(top)
        nim_entry.grid(row=1, column=1, padx=5, pady=5)

        ttk.Label(top, text="Tanggal Peminjaman (dd/mm/yyyy):").grid(row=2, column=0, padx=5, pady=5)
        tanggal_entry = ttk.Entry(top)
        tanggal_entry.grid(row=2, column=1, padx=5, pady=5)

        ttk.Label(top, text="Kode Buku:").grid(row=3, column=0, padx=5, pady=5)
        kode_entry = ttk.Entry(top)
        kode_entry.grid(row=3, column=1, padx=5, pady=5)

        ttk.Button(top, text="Tambah", command=lambda: add_entry()).grid(row=4, column=0, columnspan=2, padx=5, pady=5)

        def add_entry():
            nama = nama_entry.get()
            nim = nim_entry.get()
            tanggal = tanggal_entry.get()
            kode = kode_entry.get()
            perpustakaan.tambah_data(nama, nim, tanggal, kode)
            top.destroy()

    def edit_data():
        selected = perpustakaan.table.selection()
        if not selected:
            print("Tidak ada data yang dipilih.")
            return

        index = perpustakaan.table.index(selected[0])
        peminjaman = perpustakaan.data_peminjaman[index]

        top = tk.Toplevel(root)
        top.title("Edit Data")

        ttk.Label(top, text="Nama:").grid(row=0, column=0, padx=5, pady=5)
        nama_entry = ttk.Entry(top, text=peminjaman.nama)
        nama_entry.grid(row=0, column=1, padx=5, pady=5)

        ttk.Label(top, text="NIM:").grid(row=1, column=0, padx=5, pady=5)
        nim_entry = ttk.Entry(top, text=peminjaman.nim)
        nim_entry.grid(row=1, column=1, padx=5, pady=5)

        ttk.Label(top, text="Tanggal Peminjaman (dd/mm/yyyy):").grid(row=2, column=0, padx=5, pady=5)
        tanggal_entry = ttk.Entry(top, text=peminjaman.tanggal_peminjaman)
        tanggal_entry.grid(row=2, column=1, padx=5, pady=5)

        ttk.Label(top, text="Kode Buku:").grid(row=3, column=0, padx=5, pady=5)
        kode_entry = ttk.Entry(top, text=peminjaman.kode_buku)
        kode_entry.grid(row=3, column=1, padx=5, pady=5)

        ttk.Button(top, text="Simpan", command=lambda: save_entry()).grid(row=4, column=0, columnspan=2, padx=5, pady=5)

        def save_entry():
            nama = nama_entry.get()
            nim = nim_entry.get()
            tanggal = tanggal_entry.get()
            kode = kode_entry.get()
            perpustakaan.edit_data(index, nama, nim, tanggal, kode)
            top.destroy()

    def hapus_data():
        selected = perpustakaan.table.selection()
        if not selected:
            print("Tidak ada data yang dipilih.")
            return

        index = perpustakaan.table.index(selected[0])
        perpustakaan.hapus_data(index)

    root.mainloop()

if __name__ == "__main__":
    main()
