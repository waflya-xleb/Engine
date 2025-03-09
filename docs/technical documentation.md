## 1. правила систаксиса
___
1.1 ставить пробел после круглых скобочек ( если это НЕ будет ухудшать читабельность кода или мешать его работе. )
пример как надо:
```c
void foo( int a, int b )
```
пример как НЕ надо:
```c
void foo(int a, int b)
```
___
1.2 называть константные переменные большими буквами.
пример как надо:
```c
const int SIZE = 25;
```
пример как НЕ надо:
```c
const int size = 25;
```
___
1.3 оставлять рефлёные скобки на строке функции.
пример как надо:
```c
void foo() {
	std::cout << "hello!\n";
}
```
пример как НЕ надо:
```c
void foo()
{
	std::cout << "hello!\n";
}
```
___
1.4 не использовать namespace std.
пример как надо:
```c

```
пример как НЕ надо:
```c
using namespace std;
```
___
### 2. warning system
чтобы программа не падала от каждого чиха был придумал стандарт для абсолютно любой функций.
#### 2.1 проверка входных данных
#### 2.2 try catch
___
### custom_exception

___
### arg_function
функция обработки аргументов переданных при запуске программы.

___
### text color
#### $\textcolor{white}{\textsf{white = just text}}$
#### $\textcolor{red}{\textsf{blue = notification text}}$
#### $\textcolor{red}{\textsf{magneta = list}}$
#### $\textcolor{red}{\textsf{red = error}}$
#### $\textcolor{yellow}{\textsf{yellow = warning}}$
#### $\textcolor{green}{\textsf{green = success}}$
#### $\textcolor{cyan}{\textsf{cyan = пок ане придумано.}}$ 
___
### 3. список библиотек для проекта
___
1. vulkan
2. glfw
3. glm (ещё нет но потом нужна будет)
___

###### © 06.3.2025 делайте как надо, а как не надо само получится.
