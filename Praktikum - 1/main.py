b = [int(input(f"Masukkan data ke {i + 1}: ")) for i in range(5)]

print("\nTampilan data dalam variabel array[5]:\n")
for i, data in enumerate(b):
    print(f"Tampilan data ke {i + 1}: {data}")

