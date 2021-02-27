rem the following command uses 7z program to extract the code and readme.txt
7z.exe e *.zip *.c *.h *.txt -r

echo a5 test > test_result.txt

IF EXIST "readme.txt" (
  echo readme.txt exist >> test_result.txt
) ELSE (
  echo readme.txt not exist >> test_result.txt
)

echo q1 >> test_result.txt

gcc myrecord_llist.c myrecord_llist_main.c -o q1
q1 >> test_result.txt

echo q2 >> test_result.txt
gcc dllist.c dllist_main.c -o q2
q2
q2 >> test_result.txt

echo q3 >> test_result.txt
gcc dllist.c bigint.c bigint_main.c -o q3
q3
q2 >> test_result.txt

fc test_result.txt solution_result.txt > test_report.txt
fc report.txt report_solution.txt >> test_report.txt
