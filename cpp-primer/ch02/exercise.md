## 第二章 变量和基本类型

### 练习2.1

类型int、long、long long和short的区别是什么？无符号类型和带符号类型的区别是什么？float和double的区别是什么？

类型比特数不同，且表示的数据范围不同。`short <= int <= long <= long long`

带符号类型可表示正数、负数或0，而无符号类型只能表示大于等于0的值

`float`为单精度，`7`个有效位，`double`为双精度，有`16`个有效位

Reference

* [What are the criteria for choosing between short / int / long data types?](https://isocpp.org/wiki/faq/newbie#choosing-int-size)
* [Difference between float and double](http://stackoverflow.com/questions/2386772/difference-between-float-and-double)

### 练习2.2

计算按揭贷款时，对于利率、本金和付款分别应选择何种数据类型？说明你的理由。

需要使用`double`或者`float`类型，因为需要进行浮点数运算

### 练习2.3

读程序写结果

```c++
unsigned u = 10, u2 = 42;
std::cout << u2 - u << std::endl;
std::cout << u - u2 << std::endl;
int i = 10, i2 = 42;
std::cout << i2 - i << std::endl;
std::cout << i - i2 << std::endl;
std::cout << i - u << std::endl;
std::cout << u - i << std::endl;
```

输出(clang-1001.0.46.4)

> 32
>
> 4294967264
>
> 32
>
> -32
>
> 0
>
> 0

### 练习2.4

编写程序检查你的估计是否正确，如果不正确，请仔细研读本节知道弄明白问题所在。

### 练习2.5

指出下述字面值的数据类型并说明每一组内几种字面值的区别：

```c++
(a) 'a', L'a', "a", L"a"
(b) 10, 10u, 10L, 10uL, 012, 0xC
(c) 3.14, 3.14f, 3.14L
(d) 10, 10u, 10., 10e-2
```

(a) 字符字面值，宽字符字面值，字符串字面值，宽字符串字面值

(b) 十进制整型，无符号十进制整型，十进制长整型，无符号十进制长整型，八进制整型，16进制整型

(c) double, float, long double

(d) 十进制整形，无符号十进制整型，double, double

### 练习2.6

下面两组定义是否有区别，如果有，请叙述之：

```c++
int month = 9, day = 7;
int month = 09, day = 07;
```

有区别，第一行为十进制整型，而第二行为八进制整型，且`09`是无效的八进制整型常量，报错

### 练习2.7

下述字面值表示何种含义？他们各自的数据类型是什么？

> (a) "Who goes with F\145rgus?\012"
>
> (b) 3.14e1L    (c) 1024f    (d) 3.14L

(a) Who goes with Fergus?(换行符) string

(b) 31.4 long double

(c) Error: 后缀`f`仅对浮点型有效，而`1024`为整型

(d) long double

### 练习2.8

请利用转义序列编写一段程序，要求先输出`2M`，然后转到新一行。修改程序使其先输出`2`，然后输出制表符，在输出`M`，最后转到新一行。

```c++
#include <iostream>

int main()
{
    std::cout << "2\115\012";
    std::cout << "2\t\115\012";
    return 0;
}
```

### 练习2.9

解释下列定义的含义。对于非法的定义，请说明错在何处并将其改正。

```c++
(a) std::cin >> int input_value;    (b) int i = {3.14 };
(c) double salary = wage = 9999.99; (d) int i = 3.14;
```

(a) `error: expected '(' for function-style cast or type construction` 可修改为

```c++
int input_value;
std::cin >> input_value;
```

(b) 编译选项未指定`-std=c++11`时，会报`warning: implicit conversion from 'double' to 'int' changes value from 3.14 to 3`；若编译选项中指定`-std=c++11`时，会报` error: type 'double' cannot be narrowed to 'int' in initializer list`；结论表明列表初始化在`c++11`中变得严格，即若有丢失信息的风险，将会报错

(c) 如果提前定义好`wage`的话，该语句无问题；否则会报错`error: use of undeclared identifier 'wage'`

(d) 正确，但信息会丢失；且编译会报`warning: implicit conversion from 'double' to 'int' changes value from 3.14 to 3`

### 练习2.10

下列变量的初值分别是什么？

```c++
std::string global_str;
int global_int;
int main()
{
  int local_int;
  std::string local_str;
}
```

* `global_str` 是全局变量，未在任何函数内，故会进行默认初始化，为空字符串；同理，`global_int`为`0`；
* `local_int`位于`main`函数内，而函数内的局部变量不会默认初始化，故`local_int`未定义；而`local_str`为类对象，函数内定义的类变量会由类控制进行默认初始化，其值为空字符串
* P40默认初始化小节讲述了关于默认初始化的位置和时机

### 练习2.11

指出下面的语句是声明还是定义：

```c++
(a) extern int ix = 1024;
(b) int iy;
(c) extern int iz;
```

(a) 定义，但是在`mac`中使用`gcc`或`clang`编译时，会报错`error: 'extern' variable cannot have an initializer`

(b) 定义 (c) 声明

### 练习2.12

请指出下面的名字中哪些是非法的？

```c++
(a) int double = 3.14;        (b) int _;
(c) int catch-22;             (d) int 1_or_2 = 1;
(e) double Double = 3.14
```

(a) (c) (d) 非法

### 练习2.13

下面程序中`j`的值是多少？

```c++
#include <iostream>

int i = 42;
int main()
{
  int i = 100;
  int j = i;

  std::cout << j << std::endl;
  return 0;
}
```

`j`的值是`100`

### 练习2.14

下面的程序合法吗？如果合法，它将输出什么？

```c++
#include <iostream>

int main()
{
  int i = 100, sum = 0;
  for (int i = 0; i != 10; ++i)
    sum += i;

  std::cout << i << " " << sum << std::endl;
  return 0;
}
```

`i`和`sum`的值分别是`100, 45`

### 练习2.15

下面的那个定义是不合法的？为什么？

```
(a) int ival = 1.01;    (b) int &rval1 = 1.01;
(c) int &rval2 = ival;  (d) int &rval3;
```

(b) 引用无法绑定字面值

(d) 引用必须初始化

### 练习2.16

考查下面的所有赋值然后回答：那些赋值是不合法的？为什么？那些赋值是合法的？他们执行了什么样的操作?

```c++
int i = 0, &r1 = i; double d = 0, &r2 = d;
(a) r2 = 3.14159;   (b) r2 = r1;
(c) i = r2;         (d) r1 = d;
```

(a) 合法，赋值 d 为 3.14159

(b) 合法，会发生自动类型转换

(c) 合法，自动类型转换，精度丢失

(d) 合法，同C

### 练习2.17

执行下面的代码段将输出什么结果？

```c++
int i, &ri = i;
i = 5; ri = 10;
std::cout << i << " " << ri << std::endl;
```

`10, 10`

### 练习2.18

编写代码分别更改指针的值以及指针所指对象的值

```c++
#include <iostream>

int main()
{
  double d = 10.0, dd = 100.;
  double *pd = &d;
  std::cout << pd << " " << (*pd) << std::endl;
  pd = &dd;
  std::cout << pd << " " << (*pd) <<  std::endl;
  (*pd) = 110.;
  std::cout << pd << " " << (*pd) << std::endl;
  return 0;
}
```

### 练习2.19

说明指针和引用的主要区别

* 引用对已存在对象的别名，本身不是对象，逻辑上不独立；而指针本身是一个对象
* 引用必须被初始化，不可为空；而指针无需在定义时初始化，可为空
* 引用在其生命周期内无法更改绑定对象，而指针可以更改其指向对象
* 指针是对象，允许赋值和拷贝

### 练习2.20

请叙述下面这段代码的作用

```c++
int i = 42;
int *p1 = &i;
*p1 = *p1 * *p1;
```

`p1`指向对象`i`, `i`的值变为`42 * 42`

### 练习2.21

请解释下属定义。在这些定义中有非法的吗？如果有，为什么？

```c++
int i = 0;
(a) double *dp = &i；  (b) int *ip = i;  (c) int *p = &i;
```

(a) 非法，不能将`double*`指针指向`int`类型对象 `error: cannot initialize a variable of type 'double *' with an rvalue of type 'int *'`

(b) 非法，不能将`int`变量赋给指针`error: cannot initialize a variable of type 'int *' with an lvalue of type 'int'`

(c) 合法

### 练习2.22

假设`p`是一个`int`型指针，请说明下述代码的含义

```
if (p) // ...
if (*p) // ...
```

`if (p)` 表示判断`p`是否为空指针

`if (*p)`表示`p`指针指向的值是否为`0`

### 练习2.23

给定指针`p`，你能知道它是否指向了一个合法的对象吗？如果能，叙述判断的思路；如果不能，也请说明原因。

不能，只能判断指针是否合法，无法确定指针指向的内容是否合法。

### 练习2.24

在下面这段代码中为什么`p`合法而`lp`非法

```c++
int i = 42;    void *p = &i;    long *lp = &i;
```

`void*`指针从C语言继承而来，可以指向任何类型，故第二条语句合法；而C++语言规定其他指针类型必须与所指对象类型严格匹配，故第三条语句不合法。

### 练习2.25

说明下列变量的类型和值

```c++
(a) int *ip, i, &r = i;    (b) int i, *ip = 0;    (c) int *ip, ip2;
```

(a) int指针、int、int引用    (b) int、int空指针    (c) int指针、int

### 练习2.26

下面哪些句子是合法的？如果有不合法的句子，请说明为什么？

```c++
(a) const int buf;         (b) int cnt = 0;
(c) const int sz = cnt;    (d) ++cnt; ++sz;
```

(a) 不合法，const必须被初始化

(d) 不合法，const对象不允许改变

### 练习2.27

下面的那些初始化是合法的？请说明原因。

```c++
(a) int i = -1, &r = 0;        // 不合法，r必须引用一个对象   
(b) int *const p2 = &i2;       // 合法
(c) const int i = -1, &r = 0;  // 合法
(d) const int *const p3 = &i2; // 合法
(e) const int *p1 = &i2;       // 合法
(f) const int &const r2;       // 不合法，引用不是对象，故不能是const
(g) const int i2 = i, &r = i;  // 合法
```

### 练习2.28

说明下面的这些定义是什么意思，挑出其中不合法的。

```c++
(a) int i, *const cp;      // 不合法，cp为const指针，必须初始化
(b) int *p1, *const p2;    // 不合法，p2为const指针，必须初始化
(c) const int ic, &r = ic; // ic 为const对象，必须初始化
(d) const int *const p3;   // p3为const指针，必读初始化
(e) const int *p;          // 合法
```

### 练习2.29

假设已有上一个练习中定义的哪些变量，则下面的哪些语句是合法的？请说明原因

```c++
(a) i = ic;   // 合法
(b) p1 = p3;  // 不合法，非常量指针不能够指向常量对象
(c) p1 = &ic; // 不合法，同上
(d) p3 = *ic; // 不合法，p3是常量指针，初始化后不可更改指向对象
(e) p2 = p1;  // 不合法，同上
(f) ic = *p3; // 不合法，ic为常量对象，初始化后不可改变值
```

### 练习2.30

对于下面的这些语句，请说明对象被声明成了顶层const还是底层const？

```c++
const int v2 = 0;                              // 顶层const
int v1 = v2;             
int *p1 = &v1, &r1 = v1;                       
const int *p2 = &v2, *const p3 = &i, &r2 = v2; // p2为底层const，p3为顶层和底层const，r2为底层const
```

### 练习2.31

假设已有上一个练习中所做的那些声明，则下面的哪些语句是合法的？请说明顶层const和底层const在每个例子中有何体现。

```c++
r1 = v2;          // 合法，r1引用v1, v1为int，可改变其值
p1 = p2; p2 = p1; // 不合法，p1为int*,不可指向常量对象; 合法，p2为const int*,可指向非常量对象
p1 = p3; p2 = p3; // 不合法，同上; 合法，p2和p3都有底层const
```

### 练习2.32

下面的代码是否合法？如果非法，请设法将其修改正确

```c++
int null = 0, *p = null; // 非法，error: cannot initialize a variable of type 'int *' with an lvalue of type 'int'
int null = 0, *p = &null;    // 修改1
int null = 0, *p = nullptr;  // 修改2
```

### 练习2.33

利用本节定义的变量，判断下列语句的运行结果

```c++
a = 42;  // 42
b = 42;  // 42
c = 42;  // 42
d = 42;  // 失败，d为int*指针
e = 42;  // 失败，e为const int* 指针
g = 42;  // 失败，g为const int& 引用
```

### 练习2.34

基于上一个练习中的变量和语句编写一段程序，输出赋值前后变量的内容，你刚才的推断正确吗？如果不对，请反复研读本节的示例直到你明白错在何处为止。

[ex2-34](ex2-34.cc)在此

### 练习2.35

判断下列定义推断出的类型是什么，然后编写程序进行验证。

```c++
const int i = 42;
auto j = i; const auto &k = i; auto *p = &i;  // j: int; k: const int&; p: const int*;
const auto j2 = i, &k2 = i;                   // j2: cosnt int; k2: k2: const int&;
```

### 练习2.36

关于下面的代码，请指出每一个变量的类型以及程序结束时他们各自的值。

```c++
int a = 3, b = 4;    // a: 3; b: 4;
decltype(a) c = a;   // a: 3; b: 4; c: int, 3;
decltype((b)) d = a; // a: 3; b: 4; c: 3; d: int&, 4;
++c;                 // a: 3; b: 4; c: 4; d: 4;
++d;                 // a: 4; b: 4; c: 4; d: 4;
```

[ex2-36](ex2-36.cc)在此

### 练习2.37

赋值是会产生引用的一类典型表达式，引用的类型就是左值的类型。也就是说，如果i是int，则表达式i=x的类型是int&。根据这一特点，请指出下面的代码中每一个变量的类型和值。

```c++
int a = 3, b = 4;
decltype(a) c = a;     // c: int, 3;
decltype(a = b) d = a; // d: int&, 绑定到a;
```

### 练习2.38

说明由decltype指定类型和由auto指定类型有何区别。请举出一个例子，decltype指定的类型与auto指定的类型一样：再举一个例子，decltype指定的类型与auto指定的类型不一样。

1. auto 会忽略顶层const，若希望auto变量有const特性，则需要显示声明const；auto由初始值推断类型，故auto声明的变量必须有初始值；引用作为auto初始值时，推断类型会引用所引用的值类型；显示声明auto引用时，会把初始值的const当做底层const保留；
2. decltype是分析表达式，得到其数据类型。若表达式不是变量，则返回表达式结果对应的类型（包括const和引用）；若表达式是解引用操作，则decltype得到引用类型；若表达式是变量，若变量不加括号，则得到该变量类型；否则得到其引用类型；

```c++
int i = 0, r = &i;
//same
auto a = i;
decltype(a) d = i;

// different
auto ar = r;  // ar: int
decltype(r) dr = r;  // dr: int&
```

### 练习2.39

编译下面的程序观察其运行结果，注意，如果忘记写类定义体后面的分号会发生什么情况？记录下相关信息，以后可能会有用。

```c++
struct Foo { /* 此处为空 */ }  // 注意：没有分号
int main()
{
  return 0;
}
```

报错，错误信息为`error: expected ';' after struct`

### 练习2.40

根据自己的理解写出Sales_data类，最好与书中的例子有所区别

```c++
struct Sales_data{
  std::string bookNo;
  std::string author;
  unsigned int units_sold = 0;
  double revenue = 0.0;
}
```

### 练习2.41

使用你自己的Sales_data类重写1.5.1节（第20页）、1.5.2节（第21页）和1.6节（第22页）的练习。眼下先把Sales_data类的定义和main函数放在同一个文件里。

* 1.5.1

  ```c++
  #include <iostream>
  #include <string>
  
  struct Sales_data
  {
      std::string bookNo;
      unsigned units_sold = 0;
      double revenue = 0.0;
  };
  
  int main()
  {
      Sale_datas book;
      double price;
      std::cin >> book.bookNo >> book.units_sold >> price;
      book.revenue = book.units_sold * price;
      std::cout << book.bookNo << " " << book.units_sold << " " << book.revenue << " " << price;
  
      return 0;
  }
  ```

* 1.5.2

  ```c++
  #include <iostream>
  #include <string>
  
  struct Sales_data {
    std::string bookNo;
    unsigned int units_sold = 0;
    double revenue = 0;
  };
  
  int main() {
    Sales_data sd1, sd2;
    double price1, price2;
    std::cin >> sd1.bookNo >> sd1.units_sold >> price1;
    std::cin >> sd2.bookNo >> sd2.units_sold >> price2;
    sd1.revenue = sd1.units_sold * price1;
    sd2.revenue = sd2.units_sold * price2;
  
    if (sd1.bookNo == sd2.bookNo) {
      unsigned int total_sold = sd1.units_sold + sd2.units_sold;
      double total_revenue = sd1.revenue + sd2.revenue;
      std::cout << sd1.bookNo << " " << total_sold << " " << total_revenue;
      if (total_sold != 0) {
        std::cout << " " << total_revenue / total_sold << std::endl;
      } else {
        std::cout << "No Sales" << std::endl;
      }
    } else {
      std::cout << "These books' bookNo are different" << std::endl;
    }
    return 0;
  }
  ```

* 1.6

  ```c++
  #include <iostream>
  #include <string>
  
  struct Sales_data {
    std::string bookNo;
    unsigned int units_sold = 0;
    double revenue = 0.0;
  };
  
  int main() {
    Sales_data total;
    double total_price;
    if (std::cin >> total.bookNo >> total.units_sold >> total_price) {
      total.revenue = total.units_sold * total_price;
      Sales_data trans;
      double price;
      while (std::cin >> trans.bookNo >> trans.units_sold >> price) {
        trans.revenue = trans.units_sold * price;
  
        if (total.bookNo == trans.bookNo) {
          total.units_sold += trans.units_sold;
          total.revenue += trans.revenue;
        } else {
          std::cout << total.bookNo << " " << total.units_sold << " "
                    << total.revenue << " ";
          if (total.units_sold != 0) {
            std::cout << total.revenue / total.units_sold << std::endl;
          } else {
            std::cout << "No Sales!" << std::endl;
          }
  
          total.bookNo = trans.bookNo;
          total.units_sold = trans.units_sold;
          total.revenue = trans.revenue;
        }
      }
  
      std::cout << total.bookNo << " " << total.units_sold << " " << total.revenue
                << " ";
      if (total.units_sold != 0) {
        std::cout << total.revenue / total.units_sold << std::endl;
      } else {
        std::cout << "No Sales!" << std::endl;
      }
    } else {
      std::cout << "No data?" << std::endl;
    }
    return 0;
  }
  ```

### 练习2.42

根据你自己的理解重写一个Sales_data.h头文件，并以此为基础重做2.6.2节（第67页）的练习。

* [1.5.1](ex2-42-1.cc)
* [1.5.2](ex2-42-2.cc)
* [1.6](ex2-42-3.cc)