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

//Получить значение элемента по его индексу.
//Если индекс некорректный (меньше 0, или слишком большой) - нужно кинуть исключение
// (я показываю в примере ниже, как это делать).
const int& get_element(const unsigned& index) {
	return 42;
	//throw std::runtime_error("index is invalid");
}

//Получить текущее количество элементов в массиве. 
unsigned get_array_size() {
	return array_size;
}

//Следующие тесты должны выполняться (программа должна успешно запускаться).
//Менять тесты нельзя. 
//Менять мои заглушки на функции нельзя.

void check_preconditions() {
	assert(array_size == 0);
	assert(capacity == 0);
	assert(buffer == nullptr);
}

void can_init_and_destroy_new_array_test() {
	init_array();
	destroy_array();
	check_preconditions();
}

void can_add_elements_to_array_test() {
	init_array();

	for (int i = 0; i < 2000; ++i) {
		add_element(i);
	}

	for (int i = 0; i < 2000; ++i) {
		int current_element = get_element(i);
		assert(current_element == i);
	}

	destroy_array();
	check_preconditions();
}

void cannot_delete_not_existed_element_test() {
	init_array();

	for (int i = 0; i < 2000; ++i) {
		add_element(i);
	}

	assert(delete_element(3000) == false);

	for (int i = 0; i < 2000; ++i) {
		int current_element = get_element(i);
		assert(current_element == i);
	}

	destroy_array();
	check_preconditions();
}

void cannot_delete_not_existed_element_test2() {
	init_array();

	for (int i = 0; i < 2000; ++i) {
		add_element(i);
	}

	assert(delete_element_by_index(3000) == false);

	for (int i = 0; i < 2000; ++i) {
		int current_element = get_element(i);
		assert(current_element == i);
	}

	destroy_array();
	check_preconditions();
}

void can_delete_existed_element_test() {
	init_array();

	for (int i = 0; i < 5; ++i) {
		add_element(i + 2);
	}

	int size_before_removing_element = get_array_size();

	assert(delete_element(3) == true);

	int size_after_removing_element = get_array_size();

	assert(size_after_removing_element + 1 == size_before_removing_element);
	assert(size_after_removing_element == 4);

	assert(get_element(0) == 2);
	assert(get_element(1) == 4);
	assert(get_element(2) == 5);
	assert(get_element(3) == 6);

	destroy_array();
	check_preconditions();
}

void can_delete_existed_element_test2() {
	init_array();

	for (int i = 0; i < 5; ++i) {
		add_element(i + 2);
	}

	int size_before_removing_element = get_array_size();

	assert(delete_element_by_index(3) == true);

	int size_after_removing_element = get_array_size();

	assert(size_after_removing_element + 1 == size_before_removing_element);
	assert(size_after_removing_element == 4);

	assert(get_element(0) == 2);
	assert(get_element(1) == 3);
	assert(get_element(2) == 4);
	assert(get_element(3) == 6);

	assert(find_element(2) == true);
	assert(find_element(3) == true);
	assert(find_element(4) == true);
	assert(find_element(5) == false);
	assert(find_element(6) == true);

	destroy_array();
	check_preconditions();
}

void exception_occurred_when_getiing_element_with_invalid_index_test() {
	init_array();

	for (int i = 0; i < 5; ++i) {
		add_element(i + 2);
	}

	assert(get_element(0) == 2);

	bool has_exception = false;

	try {
		get_element(5);
	}
	catch (...) 
	{
		has_exception = true;
	}

	assert(has_exception == true);
	
	destroy_array();
	check_preconditions();
}

void exception_occurred_when_getiing_element_with_invalid_index_test2() {
	init_array();

	for (int i = 0; i < 5; ++i) {
		add_element(i + 2);
	}

	assert(get_element(0) == 2);

	bool has_exception = false;

	try {
		get_element(-1);
	}
	catch (...)
	{
		has_exception = true;
	}

	assert(has_exception == true);

	destroy_array();
	check_preconditions();
}

int main()
{
	can_init_and_destroy_new_array_test();
	can_add_elements_to_array_test();
	cannot_delete_not_existed_element_test();
	cannot_delete_not_existed_element_test2();
	can_delete_existed_element_test();
	can_delete_existed_element_test2();
	exception_occurred_when_getiing_element_with_invalid_index_test();
	exception_occurred_when_getiing_element_with_invalid_index_test2();
	can_init_and_destroy_new_array_test();

	system("PAUSE");
	return 0;
}