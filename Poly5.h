#pragma once

class VMT3PolymorphismDemo
{
	class Dog
	{

		// void** __vfptr;
		// VPTR - указатель на таблицу VTABLE (по одному указателю на каждый объект!)

		// static void* Dog::vftable[2];
		// сама "таблица" (только одна на все объекты!)
		
	public:
		char* name;
		int age;

		/* Dog()
		{
			// __vfptr = Dog::vftable; // неявное связывание указателя с таблицей

			// ... другие явные действия программиста
		} */
		
		virtual void Guard() // &Guard (адрес метода) - by index 0 in vftable
		{
			cout << "Dog::Guard\n";
		}
		
		virtual void Bark() // &Bark - by index 1 in vftable
		{
			cout << "Dog::Bark\n";
		}

		static void Print()
		{
			cout << "Dog::Print\n";
		}
	};

	class Mops : public Dog
	{

		// отнаследованный
		// void** __vfptr; // VPTR - указатель на таблицу VTABLE (по одному указателю на каждый объект)

		// статические компоненты не наследуются, - это уже новая таблица!
		// static void* Mops::vftable[2]; // таблица (одна на класс)

	public:
		int mops_field;

		/* Mops()
		{
			// __vfptr = Mops::vftable; // неявное связывание указателя с новой таблицей

			// ... другие явные действия программиста
		} */
		
		virtual void Guard() override // переопределение метода есть, поэтому в "таблице" - новый адрес 
		{
			cout << "Mops::Guard\n";
		}
		
		virtual void Bark() override // то же самое для Bark
		{
			cout << "Mops::Bark\n";
		}
	};


public:
	static void Test()
	{
		Mops m;
		cout << "Адрес объекта m типа Mops: ";
		cout << &m << "\n";
		// здесь можно выставить брейкпоинт
		// и проверить начинку объекта Mops

		//////////////////////////////////////////////////////////////////////

		// псевдокод настройки VTABLE для класса Dog:
		// Dog::vftable[0] = &Dog::Guard;
		// Dog::vftable[1] = &Dog::Bark;

		Dog* d = new Dog;
		// в конструкторе Dog() для динамически созданного объекта произошло связывание VPTR и VTABLE
		// __vfptr = Dog::vftable;

		d->Guard(); // <--- мы, земляне, пишем так :)

		// а на самом деле, компилятор сюда подставляет что-то вроде:
		// d->__vfptr[0](); // 0 - это индекс метода Guard

		d->Bark(); // pd->__vfptr[1]();

		Dog* dd = new Mops();
		dd->Bark();
	}
};

// VMT3PolymorphismDemo::Test();