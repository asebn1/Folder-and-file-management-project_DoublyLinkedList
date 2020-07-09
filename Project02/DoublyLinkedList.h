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
	*	@brief	기존의 레코드를 삭제
	*	@pre	DoublyLinkedList 데이터 저장
	*	@post	삭제할 데이터 목록 삭제
	*	@param	데이터를 삭제하기위해 사용하는 임시변수
	*	@return	항상 1반환
	*/
	int Delete(T data);


	/**
	*	@brief	폴더명 첫 이름으로 정렬
	*	@pre	DoublyLinkedList 데이터 저장
	*	@post	정렬 완료
	*/
	void SortedFolderName();

	/**
	*	@brief	저장된 폴더 정보 출력
	*	@pre	DoublyLinkedList 데이터 저장
	*	@post	출력 완료
	*/
	void Display(T data);

	/**
	*	@brief	저장된 폴더에 폴더 이름으로 검색
	*	@pre	DoublyLinkedList 데이터 저장
	*	@post	검색 결과 출력
	*	@param	검색할 string 변수
	*/
	void RetrieveFolder(string temp, T &Ft);

	/**
	*	@brief	저장된 폴더에 폴더 이름으로 검색
	*	@pre	DoublyLinkedList 데이터 저장
	*	@post	검색 결과 출력
	*	@param	검색할 string 변수
	*/
	void RetrieveFile(string temp);
	/**
	*	@brief	중복검사
	*	@pre	DoublyLinkedList 데이터 저장
	*	@post	중복 여부
	*	@param	중복여부 검사하는 임시변수
	*	@return	항상 1반환
	*/
	int Overlap(T data);

	/**
	*	@brief	하위폴더에 들어가는 m_CurPoint를 위한 함수.
	*	@pre	폴더 입력.
	*	@post	하위폴더로 이동.
	*	@param	foldertype 주소값을 줌.
	*	@return	하위폴더 받을 수 있다면 주소로 받아서 m_CurPoint가 가르킴.
	*/
	T& PathExist(T &data);

	/**
	*	@brief	하위폴더에 들어가는 m_CurPoint를 위한 함수.
	*	@pre	폴더 입력.
	*	@post	하위폴더로 이동.
	*	@param	foldertype 주소값을 줌.
	*	@return	하위폴더에 겹치는 값이 있으면 1, 아니면 0반환.
	*/
	int IntPathExist(T &data);


	/**
	*	@brief	스택 쌓는 위한함수.
	*	@pre	none.
	*	@post	스택 쌓는 위한함수.
	*	@param	현재길이 cur와 foldertype주소값 m_Cur받아옴.
	*/
	void subB(int cur, T &m_Sub);


	/**
	*	@brief	MoveBack함수에서 상위폴더 주소값 받기.
	*	@pre	폴더 입력 완료.
	*	@post	MoveBack함수에서 상위폴더 주소값 받기.
	*	@param	현재길이 cur.
	*	@return	상위폴더 주소값 받기.
	*/
	T& GoB(int cur);


	/**
	*	@brief	파일명 변경.
	*	@pre	none.
	*	@post	파일명 변경.
	*	@param	파일명 변경할 string값.
	*/
	void fRename(string s);

	/**
	*	@brief	폴더 복사
	*	@pre	none.
	*	@post	폴더 복사 완료
	*	@param	복사할 폴더명
	*	@return	폴더 반환
	*/
	T& GetCopy(string s);

	/**
	*	@brief	폴더 복사 가능 여부
	*	@pre	none.
	*	@post	폴더 복사 가능 여부
	*	@param	복사할 폴더명
	*	@return	복사가능 true, 불가능 false
	*/
	bool Copysu(string s);

	/**
	*	@brief	폴더 붙여넣기
	*	@pre	none.
	*	@post	폴더 붙여넣기
	*	@param	붙여넣을 폴더
	*/
	void SetCopy(T Copy);

private:
	DoublyNodeType<T> *m_pList;
	DoublyNodeType<T> *m_pCurPointer;
	int m_nLength;
	T *fd;				//스택쌓기위한 임시변수

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



//삭제
template<class T>
int DoublyLinkedList<T>::Delete(T data)
{
	DoublyNodeType<T> *cur = m_pList;
	DoublyNodeType<T> *pre = m_pList;
	//첫데이터 제거
	if (cur->info.GetFolderName() == data.GetFolderName()) {
		m_pList = cur->next;
		delete cur;
		m_nLength--;
		return 1;
	}
	cur = cur->next;
	//입력받은 데이터의 학번과 기존 데이터를 비교해서 삭제하려는 반복문
	for (int i = 1; i < m_nLength; i++)
	{
		//m_Array[i]의 학번과 data의 학번이 일치할 때
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


// 폴더명 글자로 정렬
template<class T>
void DoublyLinkedList<T>::SortedFolderName()
{
	DoublyNodeType<T> *cur = m_pList;
	DoublyNodeType<T> *pro = cur->next;
	T temp;
	if (m_nLength >= 2) {

		//이중 for문으로 정렬 하기
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

// 정보 출력
template<class T>
void DoublyLinkedList<T>::Display(T data)
{

	cout << "┌";
	for (int i = 0; i < data.GetFolderPosition().length() + 21; i++) {
		cout << "─";
	}
	cout << "┐" << endl;
	cout << "│ Current Directory : " << data.GetFolderPosition() << "│" << endl;

	cout << "└";

	for (int i = 0; i < data.GetFolderPosition().length() + 21; i++) {
		cout << "─";
	}
	cout << "┘" << endl;


	DoublyNodeType<T> *cur;
	cur = m_pList;

	cout << "\t [Folder]" << endl;
	cout << "\t┌───────────────────────────────────────────────────────────────┐" << endl;
	cout << "\t│   Folder Name\t\tCreated Time\t\t                │" << endl;
	for (int i = 0; i < m_nLength; i++)
	{
		cout << "\t│  ";
		cout.width(5);
		cout.fill(' ');
		cout << cur->info.GetFolderName();
		cout.width(33);
		cout.fill(' ');
		cout << cur->info.GetCreatTime();
		cout << "\t\t\t│" << endl;
		cur = cur->next;
	}
	cout << "\t└───────────────────────────────────────────────────────────────┘" << endl;

}

//저장된 폴더에 폴더 이름으로 검색
template<class T>
void DoublyLinkedList<T>::RetrieveFolder(string temp, T &Ft)
{
	DoublyNodeType<T>	*cur = m_pList;

	if (m_nLength != 0) {
		for (int i = 0; i < m_nLength; i++)
		{
			if (cur->info.GetFolderName().find(temp) != -1)
			{
				//들어가고 들어가서 수행 수정해야함
				cout << "\t" << cur->info.GetFolderName() << "\t위치 : " << Ft.GetFolderPosition() << endl;
			}
			cur->info.BinarySearchFolderByName(temp, cur->info.GetSubFolderNum(), cur->info);
			cur = cur->next;
		}
	}
}

// 폴더명 중복 여부 검사
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

//하위폴더에 들어가는 m_CurPoint를 위한 함수1
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

//하위폴더에 들어가는 m_CurPoint를 위한 함수2
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

//스택 쌓기 위한함수
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

//MoveBack함수에서 상위폴더 주소값 받기
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

//저장된 폴더에 폴더 이름으로 검색
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

//폴더명 변경
template<class T>
void DoublyLinkedList<T>::fRename(string s)
{
	int id = 0;
	string temp;
	DoublyNodeType<T>	*cur = m_pList;
	for (int i = 0; i < m_nLength; i++)
	{
		if (cur->info.GetFolderName() == s) {
			cout << "\t어떤 이름으로 바꾸시겠습니까? : ";
			cin >> temp;
			//파일명 변경
			cur->info.SetFolderName(temp);
			id++;
		}
		cur = cur->next;
	}
	if (id == 0) {
		cout << "\t검색한 폴더명이 존재하지 않습니다." << endl;
	}
}

//폴더 복사
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

//폴더 복사 가능여부
template<class T>
bool DoublyLinkedList<T>::Copysu(string s) {
	for (int i = 0; i < m_nLength; i++) {
		if (m_pList->info.GetFolderName() == s) {
			return true;
		}
	}
	return false;
}

//폴더 붙여넣기
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