#include<iostream>
//�������� ������
/*
- ���������� �������� ������ . � ����� � ��������
- ���������� ����������

*/



class Vector
{
private:
	int* _ptr = nullptr;
	int _size = 0;
public:
	void Push_back(int data) // ��������� ������� � ����� �������
	{
		_size++;//1 ��������� ������ ������� �� 1 
		
		int *newMass = new int[_size];//�������� ������ ��� ����� ������ newMass �������� _size

		if (_ptr == nullptr) // ��������� ���� �� ������ ������ �� ������� ��������� ���� _ptr
		{
			newMass[0] = data; //  � �  ������� newMass[0] ������� ������ ������� ������ �������� data ([0]) - �.� ��� ����� ������ �������
			_ptr = newMass;  // ��������� ��������� _ptr �� ����� ������ newMass
			return; // � ������� �� ������� void Push_back(int data)
		}
		for (int i = 0; i < _size-1; ++i)// ����������� ������ �������� � ����� ������		
			newMass[i] = _ptr[i];	// �������� ��� ������ �������� � ����� ������

		newMass[_size - 1] = data; // (�������� ����� ������� � ����� �������) �������������� ��������� ������� [_size - 1] ������� newMass ���������� ������� data
		delete[]_ptr; //������� ������ ������ 
		_ptr = newMass; // ��������� ��������� _ptr �� ����� ������ newMass
	}
		
	int At(int index)// ������� �������� �������� �������� �� ������� (��� ��������� �� ������� � ��������� �������)
	{
		return _ptr[index];
	}

	int GetSize()// ������ ��� ������ ������� _ptr
	{
		return _size;
	}

	int operator[] (int index) { return _ptr[index]; } // ���������� ��������� [] ������� ���������� �������� �� �������.

	void Push_element(int index, int data)
	{
		if (index > _size || index < 0) return;
		_size++;
		int* newArray = new int[_size];
		if(_ptr == nullptr)
		{
			newArray[0] = data;
			_ptr = newArray;
			return;
		}
		for (int i = 0; i < index; ++i)
			newArray[i] = _ptr[i];
		
		newArray[index] = data;

		for (int i = index + 1; i < _size; ++i)
			newArray[i] = _ptr[i - 1];
		delete[]_ptr;
		_ptr = newArray;
	}


	void Push_front(int data)// ���������� �������� � ������
	{
		_size++;
		int* newArr = new int[_size];
		if(_ptr == nullptr)
		{
			newArr[0] = data;
			_ptr = newArr;
			return;
		}
		for(int i = 1; i <_size; ++i)			
			newArr[i] = _ptr[i - 1];
		newArr[0] = data;
		delete[]_ptr;
		_ptr = newArr;
	}

	// ���������� ��������� +
	int operator +(int* Arr)
	{
		int sum = 0;
		for (int i = 0; i < _size; ++i)		
			sum += _ptr[i] + Arr[i];
		return sum;
	}
	void EraseElem(int index)
	{ 
		_size--;
		int* newArray = new int[_size];

		for (int i = 0; i < index; ++i)			
			newArray[i] = _ptr[i];			
		
		for (int i = index + 1; i < _size + 1; ++i)
			newArray[i - 1] = _ptr[i];

		delete[]_ptr;	
		_ptr = newArray;
	}

};



int main()
{
	Vector vec;
	vec.Push_back(10);
	vec.Push_back(20);
	vec.Push_back(30);
	vec.Push_back(40);
	vec.Push_front(1);
	vec.Push_front(2);
	vec.Push_front(3);
	vec.Push_front(4);


	vec.Push_element(2, 6);
	for (int i = 0; i < vec.GetSize(); ++i)	
		//std::cout<<"Element[" << i << "] = " <<	vec.At(i) << '\n';
		std::cout<<"Element[" << i << "] = " <<	vec[i] << '\n';// ��� � �������������� int operator[] (int index) { return _ptr[index]; }
	vec.EraseElem(3);
	std::cout << "\n\n";

	for (int i = 0; i < vec.GetSize(); ++i)
		std::cout << "Element[" << i << "] = " << vec[i] << '\n';


	return{};
}