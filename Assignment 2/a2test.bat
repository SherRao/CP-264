rem the following command uses 7z program to extract the code and readme.txt
7z.exe e *.zip *.h *.c *.txt -r

echo a2 test > test_result.txt

IF EXIST "readme.txt" (
  echo readme.txt exist >> test_result.txt
) ELSE (
  echo readme.txt not exist >> test_result.txt
)

echo q1 >> test_result.txt

gcc fibonacci.h fibonacci_main.c -o fibonacci.exe
fibonacci.exe >> test_result.txt

echo q2 >> test_result.txt
gcc polynomial.h polynomial_main.c -o polynomial
polynomial >> test_result.txt

echo q3 >> test_result.txt
gcc matrix.c matrix_main.c -o matrix
matrix >> test_result.txt

fc test_result.txt solution_result.txt > test_report.txt
