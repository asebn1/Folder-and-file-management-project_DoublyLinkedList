#ifndef _UNDoublyLinkedList_H
#define _UNDoublyLinkedList_H

#include <iostream>
#include <fstream>	
#include <string>
#include <iomanip>
#include <stdio.h>
using namespace std;

#include "FolderType.h"
#pragma warning(disable:4996)
/**
*	array based simple unsorted list.
*/

template<class T>
struct DoublyNodeType
{
	T info;
	DoublyNodeType *pre;
	DoublyNodeType *next;
};


template<class T>
class DoublyLinkedList
{
public:
	/**
	*	default constructor.
	*/
	DoublyLinkedList();

	/**
	*	destructor.
	*/
	~DoublyLinkedList() {}


	/**
	*	@brief	add a new data into list.
	*	@pre	list should be initialized.
	*	@post	added the new record into the list.
	*	@param	data	new data.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int Add(T data);

	/**
	*	@brief	������ ���ڵ带 ����
	*	@pre	DoublyLinkedList ������ ����
	*	@post	������ ������ ��� ����
	*	@param	�����͸� �����ϱ����� ����ϴ� �ӽú���
	*	@return	�׻� 1��ȯ
	*/
	int Delete(T data);


	/**
	*	@brief	������ ù �̸����� ����
	*	@pre	DoublyLinkedList ������ ����
	*	@post	���� �Ϸ�
	*/
	void SortedFolderName();

	/**
	*	@brief	����� ���� ���� ���
	*	@pre	DoublyLinkedList ������ ����
	*	@post	��� �Ϸ�
	*/
	void Display(T data);

	/**
	*	@brief	����� ������ ���� �̸����� �˻�
	*	@pre	DoublyLinkedList ������ ����
	*	@post	�˻� ��� ���
	*	@param	�˻��� string ����
	*/
	void RetrieveFolder(string temp, T &Ft);

	/**
	*	@brief	����� ������ ���� �̸����� �˻�
	*	@pre	DoublyLinkedList ������ ����
	*	@post	�˻� ��� ���
	*	@param	�˻��� string ����
	*/
	void RetrieveFile(string temp);
	/**
	*	@brief	�ߺ��˻�
	*	@pre	DoublyLinkedList ������ ����
	*	@post	�ߺ� ����
	*	@param	�ߺ����� �˻��ϴ� �ӽú���
	*	@return	�׻� 1��ȯ
	*/
	int Overlap(T data);

	/**
	*	@brief	���������� ���� m_CurPoint�� ���� �Լ�.
	*	@pre	���� �Է�.
	*	@post	���������� �̵�.
	*	@param	foldertype �ּҰ��� ��.
	*	@return	�������� ���� �� �ִٸ� �ּҷ� �޾Ƽ� m_CurPoint�� ����Ŵ.
	*/
	T& PathExist(T &data);

	/**
	*	@brief	���������� ���� m_CurPoint�� ���� �Լ�.
	*	@pre	���� �Է�.
	*	@post	���������� �̵�.
	*	@param	foldertype �ּҰ��� ��.
	*	@return	���������� ��ġ�� ���� ������ 1, �ƴϸ� 0��ȯ.
	*/
	int IntPathExist(T &data);


	/**
	*	@brief	���� �״� �����Լ�.
	*	@pre	none.
	*	@post	���� �״� �����Լ�.
	*	@param	������� cur�� foldertype�ּҰ� m_Cur�޾ƿ�.
	*/
	void subB(int cur, T &m_Sub);


	/**
	*	@brief	MoveBack�Լ����� �������� �ּҰ� �ޱ�.
	*	@pre	���� �Է� �Ϸ�.
	*	@post	MoveBack�Լ����� �������� �ּҰ� �ޱ�.
	*	@param	������� cur.
	*	@return	�������� �ּҰ� �ޱ�.
	*/
	T& GoB(int cur);


	/**
	*	@brief	���ϸ� ����.
	*	@pre	none.
	*	@post	���ϸ� ����.
	*	@param	���ϸ� ������ string��.
	*/
	void fRename(string s);

	/**
	*	@brief	���� ����
	*	@pre	none.
	*	@post	���� ���� �Ϸ�
	*	@param	������ ������
	*	@return	���� ��ȯ
	*/
	T& GetCopy(string s);

	/**
	*	@brief	���� ���� ���� ����
	*	@pre	none.
	*	@post	���� ���� ���� ����
	*	@param	������ ������
	*	@return	���簡�� true, �Ұ��� false
	*/
	bool Copysu(string s);

	/**
	*	@brief	���� �ٿ��ֱ�
	*	@pre	none.
	*	@post	���� �ٿ��ֱ�
	*	@param	�ٿ����� ����
	*/
	void SetCopy(T Copy);

private:
	DoublyNodeType<T> *m_pList;
	DoublyNodeType<T> *m_pCurPointer;
	int m_nLength;
	T *fd;				//���ýױ����� �ӽú���

};

template<class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	m_nLength = 0;
	DoublyNodeType<T> *m_pList = new DoublyNodeType<T>;
	DoublyNodeType<T> *m_pCurPointer = new DoublyNodeType<T>;

	fd = new T;
}



// add a new data into list.
template<class T>
int DoublyLinkedList<T>::Add(T inData)
{
	DoublyNodeType<T> *location;
	location = new DoublyNodeType<T>;
	if (m_nLength == 0) {
		location->info = inData;
		location->next = m_pList;
		m_pList = location;
	}
	else {
		location->info = inData;
		location->next = m_pList;
		m_pList->pre = location;
		m_pList = location;
	}
	m_nLength++;

	return 1;
}



//����
template<class T>
int DoublyLinkedList<T>::Delete(T data)
{
	DoublyNodeType<T> *cur = m_pList;
	DoublyNodeType<T> *pre = m_pList;
	//ù������ ����
	if (cur->info.GetFolderName() == data.GetFolderName()) {
		m_pList = cur->next;
		delete cur;
		m_nLength--;
		return 1;
	}
	cur = cur->next;
	//�Է¹��� �������� �й��� ���� �����͸� ���ؼ� �����Ϸ��� �ݺ���
	for (int i = 1; i < m_nLength; i++)
	{
		//m_Array[i]�� �й��� data�� �й��� ��ġ�� ��
		if (cur->info.GetFolderName() == data.GetFolderName())
		{
			if (m_nLength <= 2) {
				pre->next = cur->next;
			}
			else {
				pre->next = cur->next;
				cur->next->pre = pre; //doubly
			}
			delete cur;
			m_nLength--;
			return 1;
		}
		else
		{
			pre = cur;
			cur = cur->next;
		}
	}
	return 0;
}


// ������ ���ڷ� ����
template<class T>
void DoublyLinkedList<T>::SortedFolderName()
{
	DoublyNodeType<T> *cur = m_pList;
	DoublyNodeType<T> *pro = cur->next;
	T temp;
	if (m_nLength >= 2) {

		//���� for������ ���� �ϱ�
		for (int i = 0; i < m_nLength; i++)
		{
			for (int j = i + 1; j < m_nLength; j++)
			{
				if (cur->info.GetFolderName() > pro->info.GetFolderName())
				{
					temp = cur->info;
					cur->info = pro->info;
					pro->info = temp;

				}
				pro = pro->next;
			}
			cur = cur->next;
			if (i != (m_nLength - 1)) {
				pro = cur->next;
			}
			else {
				break;
			}
		}
	}
}

// ���� ���
template<class T>
void DoublyLinkedList<T>::Display(T data)
{

	cout << "��";
	for (int i = 0; i < data.GetFolderPosition().length() + 21; i++) {
		cout << "��";
	}
	cout << "��" << endl;
	cout << "�� Current Directory : " << data.GetFolderPosition() << "��" << endl;

	cout << "��";

	for (int i = 0; i < data.GetFolderPosition().length() + 21; i++) {
		cout << "��";
	}
	cout << "��" << endl;


	DoublyNodeType<T> *cur;
	cur = m_pList;

	cout << "\t [Folder]" << endl;
	cout << "\t����������������������������������������������������������������������������������������������������������������������������������" << endl;
	cout << "\t��   Folder Name\t\tCreated Time\t\t                ��" << endl;
	for (int i = 0; i < m_nLength; i++)
	{
		cout << "\t��  ";
		cout.width(5);
		cout.fill(' ');
		cout << cur->info.GetFolderName();
		cout.width(33);
		cout.fill(' ');
		cout << cur->info.GetCreatTime();
		cout << "\t\t\t��" << endl;
		cur = cur->next;
	}
	cout << "\t����������������������������������������������������������������������������������������������������������������������������������" << endl;

}

//����� ������ ���� �̸����� �˻�
template<class T>
void DoublyLinkedList<T>::RetrieveFolder(string temp, T &Ft)
{
	DoublyNodeType<T>	*cur = m_pList;

	if (m_nLength != 0) {
		for (int i = 0; i < m_nLength; i++)
		{
			if (cur->info.GetFolderName().find(temp) != -1)
			{
				//���� ���� ���� �����ؾ���
				cout << "\t" << cur->info.GetFolderName() << "\t��ġ : " << Ft.GetFolderPosition() << endl;
			}
			cur->info.BinarySearchFolderByName(temp, cur->info.GetSubFolderNum(), cur->info);
			cur = cur->next;
		}
	}
}

// ������ �ߺ� ���� �˻�
template<class T>
int DoublyLinkedList<T>::Overlap(T data)
{
	DoublyNodeType<T>	*cur = m_pList;
	for (int i = 0; i < m_nLength; i++) {
		if (cur->info.GetFolderName() == data.GetFolderName()) {
			return 1;
		}
		cur = cur->next;
	}
	return 0;
}

//���������� ���� m_CurPoint�� ���� �Լ�1
template<class T>
T& DoublyLinkedList<T>::PathExist(T &data) {

	DoublyNodeType<T>	*cur = m_pList;

	for (int i = 0; i < m_nLength; i++) {
		if (cur->info.GetFolderName() == data.GetFolderName())
		{
			return cur->info;
		}
		cur = cur->next;
	}

	return cur->info;
}

//���������� ���� m_CurPoint�� ���� �Լ�2
template<class T>
int DoublyLinkedList<T>::IntPathExist(T &data) {

	DoublyNodeType<T>	*cur = m_pList;

	for (int i = 0; i < m_nLength; i++) {
		if (cur->info.GetFolderName() == data.GetFolderPosition())
		{
			data.SetFolderPosition(cur->info.GetFolderPosition() + '/' + cur->info.GetFolderName());
			return 1;
		}
		cur = cur->next;
	}
	return 0;
}

//���� �ױ� �����Լ�
template<class T>
void DoublyLinkedList<T>::subB(int cur, T &m_Sub)
{
	if (cur == 0) {

		fd = &m_Sub;

	}
	else {
		fd->subA(cur, m_Sub);
	}
}

//MoveBack�Լ����� �������� �ּҰ� �ޱ�
template<class T>
T& DoublyLinkedList<T>::GoB(int c)
{
	if (c == 0) {
		return *fd;
	}
	else {
		fd->GoA(c);
	}
}

//����� ������ ���� �̸����� �˻�
template<class T>
void DoublyLinkedList<T>::RetrieveFile(string temp)
{
	DoublyNodeType<T>	*cur = m_pList;

	if (m_nLength != 0) {
		for (int i = 0; i < m_nLength; i++)
		{
			cur->info.BinarySearchFileByName(temp);
			cur = cur->next;
		}
	}
}

//������ ����
template<class T>
void DoublyLinkedList<T>::fRename(string s)
{
	int id = 0;
	string temp;
	DoublyNodeType<T>	*cur = m_pList;
	for (int i = 0; i < m_nLength; i++)
	{
		if (cur->info.GetFolderName() == s) {
			cout << "\t� �̸����� �ٲٽðڽ��ϱ�? : ";
			cin >> temp;
			//���ϸ� ����
			cur->info.SetFolderName(temp);
			id++;
		}
		cur = cur->next;
	}
	if (id == 0) {
		cout << "\t�˻��� �������� �������� �ʽ��ϴ�." << endl;
	}
}

//���� ����
template<class T>
T& DoublyLinkedList<T>::GetCopy(string s) {
	T* temp = &m_pList->info;
	DoublyNodeType<T> *te = m_pList;

	for (int i = 0; i < m_nLength; i++) {
		if (te->info.GetFolderName() == s) {
			temp = &te->info;
			return *temp;
		}
		te = te->next;
	}
	return *temp;
}

//���� ���� ���ɿ���
template<class T>
bool DoublyLinkedList<T>::Copysu(string s) {
	for (int i = 0; i < m_nLength; i++) {
		if (m_pList->info.GetFolderName() == s) {
			return true;
		}
	}
	return false;
}

//���� �ٿ��ֱ�
template<class T>
void DoublyLinkedList<T>::SetCopy(T Copy) {
	if (m_nLength == 0) {
		DoublyNodeType<T> *m_pList = new DoublyNodeType<T>;
		DoublyNodeType<T> *m_pCurPointer = new DoublyNodeType<T>;
	}
	DoublyNodeType<T> *t = new DoublyNodeType<T>;
	t->info = Copy;
	t->next = m_pList;
	m_pList = t;
	m_nLength++;
}

#endif	// _UNDoublyLinkedList_H 