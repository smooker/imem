#include <Wire.h>
void setup() {
Wire.begin();
}
byte v = 0;
void loop()
{
Wire.beginTransmission(59); // начало передачи устройству с адресом “44” (0x3B)
//Word 1
Wire.write(byte(0x80));
Wire.write(byte(0x34));
Wire.write(byte(0x80));
Wire.write(byte(0x0c));
Wire.write(byte(0x80));
Wire.write(byte(0x06));
Wire.write(byte(0x80));
Wire.write(byte(0x35));
Wire.write(byte(0x80));
Wire.write(byte(0xff));
Wire.write(byte(0x80));
Wire.write(byte(0x9d));
Wire.write(byte(0x80));// 80
Wire.write(byte(0x03)); //03
Wire.write(byte(0x80));
Wire.write(byte(0x04));// переворот контраст и пр
Wire.write(byte(0x80));
Wire.write(byte(0x08)); // переворот контраст и пр
Wire.write(byte(0x80));
Wire.write(byte(0x34));
Wire.endTransmission();
delay (200);
Wire.beginTransmission(59);
//Word 2
Wire.write(byte(0x80));
Wire.write(byte(0x80));
Wire.write(byte(0x40));
Wire.write(byte(0xCD)); //1 ряд 1 символ
Wire.write(byte(0x43));// 1 ряд 2 символ
Wire.write(byte(0x3A));// 1 ряд 3 символ
Wire.write(byte(0x34));// 1 ряд 4 символ
Wire.write(byte(0x34));// 1 ряд 5 символ
Wire.write(byte(0x32));// малый верхний ряд 1 символ
Wire.write(byte(0x35));// малый верхний ряд 2 символ
Wire.write(byte(0x00));// малый верхний ряд 3 символ
Wire.write(byte(0xCD));// малый верхний ряд 4 символ
Wire.write(byte(0x43));// малый верхний ряд 5 символ
Wire.write(byte(55));//малый нижний ряд 1 символ
Wire.write(byte(55));// малый нижний ряд 2 символ
Wire.write(byte(0x20));
Wire.endTransmission();
delay (150);
Wire.beginTransmission(59);
//Word 3
Wire.write(byte(0x80));
Wire.write(byte(0xc0));
Wire.write(byte(0x40));
Wire.write(byte(49)); //2 ряд 1 символ
Wire.write(byte(50));//2 ряд 2 символ
Wire.write(byte(51));//2 ряд 3 символ
Wire.write(byte(49)); //2 ряд 4 символ
Wire.write(byte(0x32)); //2 ряд 7 символ
Wire.write(byte(0x33));//2 ряд 5 символ
Wire.write(byte(0x34)); //2 ряд 6 символ
Wire.write(byte(0x35)); //малый нижний ряд 3 символ
Wire.write(byte(0x36)); //малый нижний ряд 4 символ
Wire.write(byte(0x37)); //малый нижний ряд 5 символ
Wire.write(byte(0x38)); //2 ряд 8 символ
Wire.write(byte(0x39)); //2 ряд 9 символ
Wire.endTransmission();
delay (150);

Wire.beginTransmission(59);
//Word 4
Wire.write(byte(0x80));
Wire.write(byte(0x80));
Wire.write(byte(0x80));
Wire.write(byte(0x40));
Wire.write(byte(0x40)); //мигание нижнего ряда 80 вместо 40
Wire.write(byte(0x00)); // мигае левый набор символов
/* 01 стакан
02 палка
03 палка со стаканом
04 дворник
05 дворник и пустой стакан
06 палка и дворник
07 палка стакан дворник
08 “ofset”
09 “ofset” и стакан
10 “MEAS”
11 “MEAS” и стакан
12 “MEAS” палка*/
Wire.write(byte(0x00)); //mts err ATC
/*00 пусто
01 ATC
02 MTC
03 ATC+ MTC
04ERR
05 ERR+ATC*/
Wire.write(byte(0x00)); //setup и точка “реле 3”,было 08
Wire.write(byte(0x00));//было 01
/*01 setup
02 точка в “реле 3”
10 Redy
redy setup
redy setup.*/
Wire.write(byte(0x00)); //ready rel3 кружек 3 реле и точка 4рел //было 08
/*HOLD
REL3
REL30
*/
Wire.write(byte(0x00)); // точки 1 ряда
Wire.write(byte(0x00)); // точки 2 ряда
Wire.write(byte(0x00)); // тире в верхнем правом углу//было 20
Wire.write(byte(0x20));
Wire.endTransmission();
delay (150);
/
Wire.beginTransmission(59);// этот модуль на экран не выводится
Wire.write(byte(0x80));
Wire.write(byte(0x80));
Wire.write(byte(0x80));
Wire.write(byte(0x60));
Wire.write(byte(0x40));
Wire.write(byte(0x00));
Wire.write(byte(0x00));
Wire.write(byte(0x00));
Wire.write(byte(0x00));
Wire.write(byte(0x00));
Wire.write(byte(0x00));
Wire.write(byte(v)); //замените подбором
Wire.write(byte(0x00));
Wire.endTransmission();
delay (150);
*/
Wire.beginTransmission(59);
//Word 6
Wire.write(byte(0x80));
Wire.write(byte(0x35));
Wire.write(byte(0x80));
Wire.write(byte(0x00)); // разные режимы работы дисплея,было 03
Wire.write(byte(0x00));
Wire.write(byte(0x00)); // разные режимы работы дисплея
Wire.write(byte(0x40)); //если установить 80 то дисплей мигает
Wire.write(byte(0x00));
Wire.endTransmission();
delay (150);
v++;
if (v>255) v=0;
}
