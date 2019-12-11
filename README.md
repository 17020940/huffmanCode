# Mã hóa và giải mã file văn bản bằng huffmanCode
# Mô tả chương trình :
- Gồm 2 chương trình Huffman.cpp và decodeHuffman.cpp
- Chương trình Huffman.cpp nhận file văn bản có tên là test.txt và trả về file mã hóa encode.txt và file bảng má hóa các kí tự Bit_Code.txt
- Chương trình decodeHuffman.cpp nhận file mã hóa encode.txt và bảng mã hóa Bit_Code.txt và trả về file decode.txt 
- Kiểm tra bằng cách so sánh 2 file test.txt và decode.txt
- Sửa nội dung test.txt để test nhiều trường hợp
# Hướng dẫn chạy chương trình :
Chạy file Huffman.cpp:
- g++ Huffman.cpp -o Huffman
- ./Huffman
Chạy file decodeHuffman.cpp : Cần chạy file Huffman.cpp trước để tạo ra 2 file encode.txt và Bit_Code.txt để làm đầu vào.
- g++ decodeHuffman.cpp -o decodeHuffman
- ./decodeHuffman


