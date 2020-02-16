#pragma once
//ģ�廯�����Խ�������һ������
//���췽������ֵһ��ָ��
//�����������ͷ�ָ��
//����׼�ĸ��ƹ��죨ת���ڲ�ָ�����Ȩ)
//����׼�ĸ��Ƹ�ֵ��ת���ڲ�ָ�����Ȩ)
//reset  �ͷ�֮ǰ�ģ�����µ�ָ��
//release �ͷſ���Ȩ������ָ��
//operator* () ģ��ָ����ʷ���
//operator-> () ģ��ָ���ͷʽ���ʷ���
//get()   ���ָ��ָ���ָ��
template<class T>		//ģ�廯�����Խ�������һ������
class L_autoPtr{
	T* obj = nullptr;
public:
	int value = 0;
	//���췽������ֵһ��ָ��
	L_autoPtr(T* ptr) :obj(ptr){
		
	}
	L_autoPtr() = default;

	//�����������ͷ�ָ��
	~L_autoPtr(){
		delete ptr;
	}

	//����׼�ĸ��ƹ��죨ת���ڲ�ָ�����Ȩ)
	L_autoPtr(L_autoPtr<T>& ptr){
		obj = ptr.obj;
		ptr.obj = nullptr;
	}

	//����׼�ĸ��Ƹ�ֵ��ת���ڲ�ָ�����Ȩ)
	L_autoPtr& operator=(L_autoPtr<T>& ptr){
		delete obj;
		obj = ptr.obj;
		ptr.obj = nullptr;
		return *this;
	}

	//reset  �ͷ�֮ǰ�ģ�����µ�ָ��
	void reset(T* newptr = nullptr)
	{
		delete obj;
		obj = newptr;
	}

	//release �ͷſ���Ȩ������ָ��
	T* release()
	{
		auto tmp = obj;
		obj = nullptr;
		return tmp;
	}

	//operator* () ģ��ָ����ʷ���
	T& operator*()
	{
		return *obj;
	}

	//operator-> () ģ��ָ���ͷʽ���ʷ���
	T* operator->()
	{
		return obj;
	}

	//get()   ���ָ��ָ���ָ��
	T* get()
	{
		return obj;
	}

};