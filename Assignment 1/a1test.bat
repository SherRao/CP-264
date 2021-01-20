rem the following command uses 7z program to extract the code and readme.txt
7z.exe e *.zip *.c *.txt -r

echo a1 test > test_result.txt

IF EXIST "readme.txt" (
  echo readme.txt exist >> test_result.txt
) ELSE (
  echo readme.txt not exist >> test_result.txt
)

echo q1 >> test_result.txt

gcc caseflip.c -o caseflip.exe
caseflip.exe < caseflip_test.txt >> test_result.txt

echo q2 >> test_result.txt
gcc factorial.c -o factorial.exe
factorial.exe 6 >> test_result.txt
factorial.exe 10 >> test_result.txt
factorial.exe 15 >> test_result.txt

echo q3 >> test_result.txt
gcc quadratic.c -o quadratic.exe
quadratic.exe < quadratic_test.txt >> test_result.txt

fc test_result.txt solution_result.txt > test_report.txt

