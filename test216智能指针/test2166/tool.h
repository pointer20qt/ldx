#pragma once
//模板化，可以接受任意一个类型
//构造方法，赋值一个指针
//析构方法，释放指针
//不标准的复制构造（转移内部指针控制权)
//不标准的复制赋值（转移内部指针控制权)
//reset  释放之前的，获得新的指针
//release 释放控制权，返回指针
//operator* () 模拟指针访问方法
//operator-> () 模拟指针箭头式访问方法
//get()   获得指针指向的指针
template<class T>		//模板化，可以接受任意一个类型
class L_autoPtr{
	T* obj = nullptr;
public:
	int value = 0;
	//构造方法，赋值一个指针
	L_autoPtr(T* ptr) :obj(ptr){
		
	}
	L_autoPtr() = default;

	//析构方法，释放指针
	~L_autoPtr(){
		delete ptr;
	}

	//不标准的复制构造（转移内部指针控制权)
	L_autoPtr(L_autoPtr<T>& ptr){
		obj = ptr.obj;
		ptr.obj = nullptr;
	}

	//不标准的复制赋值（转移内部指针控制权)
	L_autoPtr& operator=(L_autoPtr<T>& ptr){
		delete obj;
		obj = ptr.obj;
		ptr.obj = nullptr;
		return *this;
	}

	//reset  释放之前的，获得新的指针
	void reset(T* newptr = nullptr)
	{
		delete obj;
		obj = newptr;
	}

	//release 释放控制权，返回指针
	T* release()
	{
		auto tmp = obj;
		obj = nullptr;
		return tmp;
	}

	//operator* () 模拟指针访问方法
	T& operator*()
	{
		return *obj;
	}

	//operator-> () 模拟指针箭头式访问方法
	T* operator->()
	{
		return obj;
	}

	//get()   获得指针指向的指针
	T* get()
	{
		return obj;
	}

};