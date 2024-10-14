#! /bin/sh 
echo TEST1 - Int 
./intern 123
echo TEST2 - Negative int
./intern -123
echo TEST3 - Int Zero
./intern 0
echo TEST4 - Printable Char
./intern a
echo TEST5 - Non Printable Char
./intern ñ
echo TEST6 - String - Error
./intern hola
echo TEST8 - Multiple argc
./intern 123 a
echo TEST9 - Empty argc
./intern 
echo TEST10 - Double
./intern 123.23
echo TEST11 - Negative double
./intern -32.71
echo TEST12 - Float
./intern 20.12f
echo TEST13 - Negative Float
./intern -20.12f
echo TEST14 - Incorrect format1
./intern 20f
echo TEST15 - Incorrect format2
./intern .0f
echo TEST16 - Incorrect format3
./intern 23.
echo TEST17 - Incorrect format4
./intern 23.0.
echo TEST18 - Incorrect format5
./intern 23.0.3
echo TEST19 - Incorrect format6
./intern 23ff
echo TEST20 - Incorrect format7
./intern 23ff
echo TEST21 - Int overflow
./intern  2147483648
echo TEST21 - Negative int overflow
./intern -2147483649
echo TEST21 - Float overflow
./intern 340282346638528859811704183484516925441212.0f
echo TEST21 - Negative Float overflow
./intern -340282346638528859811704183484516925441212.0f
echo TEST22 - Double overflow
./intern 1797693134862315708145274237317043567980705675258449965989174768031572607800285387605895586327668781715404589535143824642343213268894641827684675467035375169860499105765512820762454900903893289440758685084551339423045832369032229481658085593321233482747978262041447231687381771809192998812504040261841248583681123123123123123
echo TEST23 - Negative double overflow
./intern -179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368123123123
echo TEST23 - NAN
./intern nan
echo TEST24 - NANF
./intern nanf
echo TEST25 - +INF
./intern +inf
echo TEST26 - -INF
./intern -inf
echo TEST27 - INFF
./intern +inff
echo TEST28 - -INFF
./intern -inff