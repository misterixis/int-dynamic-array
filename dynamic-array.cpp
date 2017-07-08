#include <iostream>
#include <cassert>

using namespace std;

//Указатель, который используется для хранения адреса памяти под массив.
int* buffer; 

//Текущее колличество элементво в массиве. 
unsigned array_size; 

//Максимальное количество элементов в массиве.
unsigned capacity;

//Инициализация массива. 
//Выполняется один раз перед тем, как будет использоваться массив. 
void init_array() {

}

//Освобождение ресурсов массива. 
//Выполняется один раз перед тем, как массив прекратит использоваться. 
void destroy_array() {

}

//Добавление нового элемента в массив. 
void add_element(const int& element) {

}

//Удаление элемента из массива. 
//Функция возвращает true, если элемент был удален корректно, иначе - false. 
bool delete_element(const int& element) {
	return false;
}

//Удаление элемента по индексу из массива. 
//Функция возвращает true, если элемент был удален корректно, иначе - false. 
bool delete_element_by_index(const unsigned& index) {
	return false;
}

//Поиск элемента в массиве.
//Функция возвращает true, если элемент был найден в массиве, иначе - false. 
bool find_element(const int& element) {
	return false;
}

//Получить значение элемента по его индексу
const int& get_element(const unsigned& index) {
	return 42;
}

//Получить текущее количество элементов в массиве. 
unsigned get_array_size() {
	return array_size;
}

//Следующие тесты должны выполняться (программа должна успешно запускаться).
//Менять тесты нельзя. 
//Менять мои заглушки на функции нельзя.

void can_init_and_destroy_new_array_test() {
	init_array();
	destroy_array();
	assert(array_size == 0);
	assert(capacity == 0);
	assert(buffer == nullptr);
}

int main()
{
	can_init_and_destroy_new_array_test();

	system("PAUSE");
	return 0;
}