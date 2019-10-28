## 第一章 开始

### 编译器

Mac下使用clang编译器

* 编译 
  * `clang++ main.cc` 默认生成`a.out`
  * `clang++ -o main main.cc`  `-o`表示生成的可执行文件名
  * 更多 option 可参考 `man clang++` 或者 `g++ --help`
* 运行
  *  `./main`
* 查看返回值/输出
  * `echo $?`

### 函数

* 函数定义包括四部分：返回类型(return type)、函数名称(function name)、形参列表(parameter list)以及函数体(function body)

### 输入输出IO

C++标准库提供了`iostream`库提供IO机制。

* `iostream`
  * `istream`: 输入流
    * `cin`: 标准输入, `std::cin >>a;`
  * `ostream`: 输出流
    * `cout`: 标准输出, `std::cout << a;`
    * `cerr`: 标准错误, `std::
    * `clog`: 输出程序运行时的一般性信息
* `<<` 输出运算符：该运算符接受两个运算对象，左侧运算对象为`ostream`对象，右侧为输出值，该运算符将输出值写到给定的`ostream`对象中，返回值为其左侧运算对象，故可连用`<<`输出多个值；**`>>`同理**
* `endl` 操作符：表示结束当前行，并将缓冲区内容`flush`到设备中。
* **命名空间**：标准库定义在命名空间`std`中，需要使用 **作用域操作符`::`**访问，比如`std::cout`等

### 注释

* 单行注释`//`
* 多行注释`/* ... */`
* 注释不可嵌套，否则编译器可能爆出难以理解的错误

### 控制流

#### while

```c++
while (condition)
	statement
```

#### for

```c++
for(init-statement; condition; expression)
  statement
```

#### 文件结束符

* Windows: Ctrl-Z
* Unix/Mac OS X: Ctrl-D

#### if

```c++
if (condition)
  statement
```

### 类

为了使用标准库，需要包含其相关头文件，类似的，自定义类也需要头文件。

* 头文件：头文件`.h`中包含类定义，其实现在`.cpp`中。标准库头文件使用`<>`，自定义头文件使用`""`包含。
* 文件重定向：文件重定向允许将标准输入和标准输出与命名文件关联起来`$ ./a.out <infile >outfile`
* 成员函数：类函数/方法，类对象使用`.运算符`调用函数，`()调用运算符`调用函数

### 书店程序

`Sales_item`类用来表示一本书的总销售额、售出册数和平均售价。`Sales_item`类操作/行为如下: 

* `isbn()`: 返回该`Sales_item`对象的`isbn`书号
* `>>`和`<<`: 用输入操作符和输出操作符读写`Sales_item`类型对象
* `=`: 用赋值运算符将一个`Sales_item`对象值赋予到另一个`Sales_item`对象
* `+`: 用加法运算符将两个`Sales_item`对象相加，这两个对象为同一本书，结果是一个新的`Sales_item`对象，其`isbn`相同，总销售额和售出册数为两个对象对应值之和
* `+=`: 用复合赋值运算符将一个`Sales_item`对象加到另一个对象上



