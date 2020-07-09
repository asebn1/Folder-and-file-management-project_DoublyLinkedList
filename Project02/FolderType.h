
#ifndef _FolderType_H
#define _FolderType_H
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <stdio.h>
#include <Windows.h>

using namespace std;
/**
*	Relation between two Folders.
*/
enum RelationType { LESS, GREATER, EQUAL };


#include "DoublyLinkedList.h"
#pragma warning(disable:4996)

//파일 타입
class FileType {

public:
	//파일 생성
	FileType()
	{
		fileName = "";
		fileCreatTime = "";
		fileAccessTime = "";
		fileEx = "";
	}

	~FileType() {}

	FileType& operator= (const FileType& data) {
		this->fileName = data.fileName;
		this->fileCreatTime = data.fileCreatTime;
		this->fileAccessTime = data.fileAccessTime;
		this->fileEx = data.fileEx;
		return *this;
	}


	/**
	*	@brief	GET 파일명
	*	@pre	none
	*	@post	GET 파일명
	*	@return	파일명 리턴
	*/
	string GetFileName() {
		return fileName;
	}

	/**
	*	@brief	SET 파일명
	*	@pre	none
	*	@post	SET 파일명
	*	@param	SET할 string 변수
	*/
	void SetFileName(string temp) {
		fileName = temp;
	}

	/**
	*	@brief	GET 확장자명
	*	@pre	none
	*	@post	GET 확장자명
	*	@return	확장자명 리턴
	*/
	string GetFileEx() {
		return fileEx;
	}

	/**
	*	@brief	SET 확장자명
	*	@pre	none
	*	@post	SET 확장자명
	*	@param	SET할 string 변수
	*/
	void SetFileEx(string temp) {
		fileEx = temp;
	}

	/**
	*	@brief	Set CreatTime.
	*	@pre	none.
	*	@post	CreatTime is set.
	*/
	void SetCreatTime()
	{
		time_t     now = time(0); //현재 시간을 time_t 타입으로 저장
		struct tm  tstruct;
		char       buf[80];
		tstruct = *localtime(&now);
		strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct); // YYYY-MM-DD.HH:mm:ss 형태의 스트링

		fileCreatTime = buf;
	}


	/**
	*	@brief	Set AccessTime.
	*	@pre	none.
	*	@post	AccessTime is set.
	*/
	void SetAccessTime()
	{
		time_t     now = time(0); //현재 시간을 time_t 타입으로 저장
		struct tm  tstruct;
		char       buf[80];
		tstruct = *localtime(&now);
		strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct); // YYYY-MM-DD.HH:mm:ss 형태의 스트링

		fileAccessTime = buf;
	}


	/**
	*	@brief	생성시간 추가
	*	@pre	none
	*	@post	생성시간 추가완료
	*/
	void Add() {
		SetCreatTime();
	}

	/**
	*	@brief	파일정보 출력
	*	@pre	none
	*	@post	파일정보 출력완료
	*/
	void fileShow() {
		if (fileAccessTime == "") {
			cout << "\t│  ";
			cout.width(5);
			cout.fill(' ');
			cout << fileName << fileEx;
			cout.width(33);
			cout.fill(' ');
			cout << fileCreatTime << "\t\t\t│" << endl;
		}
		else {
			cout << "\t│  ";
			cout.width(5);
			cout.fill(' ');
			cout << fileName << fileEx;
			cout.width(33);
			cout.fill(' ');
			cout << fileCreatTime;
			cout << "\t\t\t│" << "\t";
			cout << fileAccessTime << endl;
		}
	}

	/**
	*	@brief	파일 쓰기
	*	@pre	none
	*	@post	파일 쓰기 완료
	*/
	void WriteTxt() {
		string s;
		string temp;
		if (fileEx == ".txt") {
			ofstream out(fileName + ".txt");
			cout << "\t저장할 내용( '0' 이 포함될 시 저장내용 종료) : ";
			while (1) {
				cin >> temp;
				if (temp.find('0') != -1) {
					break;
				}
				s += temp;
			}
			out << s;
			out.close();
		}
		else {
			cout << "해당 파일은 .txt파일이 아닙니다." << endl;
		}
	}

	/**
	*	@brief	파일 읽기
	*	@pre	none
	*	@post	파일 읽기 완료
	*/
	void ReadTxt() {
		string in_line;

		if (fileEx == ".txt") {
			ifstream in(fileName + ".txt");
			cout << "\t";
			while (getline(in, in_line)) {
				cout << in_line << endl;
			}
			in.close();
		}
		else {
			if (fileEx == ".jpg") {
				cout << "\t사진출력!" << endl;
			}
			else if (fileEx == ".mp3") {
				cout << "\t음원실행!" << endl;
			}

		}

	}
private:
	string fileName; //파일명
	string fileCreatTime; //파일 생성시간
	string fileAccessTime; //엑세스 시간
	string fileEx; //확장자

	ifstream InFile;		///< input file descriptor.
	ofstream OutFile;		///< output file descriptor.
};





/**
*	Folder information class.
*/
class FolderType
{
public:
	/**
	*	default constructor.
	*/
	FolderType()
	{
		fName = "";
		fPath = "";
		fCreatTime = "";
		fSubFolderNum = 0;
		iden = false;

		fileNum = 0;
		fileMax = 5;
		file = new FileType[fileMax];

	}

	/**
	*	destructor.
	*/
	~FolderType() {}

	// ------------------------Get ---------------------------

	/**
	*	@brief	Get FolderName.
	*	@pre	FolderName is set.
	*	@post	none.
	*	@return	FolderName.
	*/
	string GetFolderName()
	{
		return fName;
	}

	/**
	*	@brief	Get FolderPosition.
	*	@pre	FolderPosition is set.
	*	@post	none.
	*	@return	FolderPosition.
	*/
	string GetFolderPosition()
	{
		return fPath;
	}
	/**
	*	@brief	Get CreatTime.
	*	@pre	CreatTime name is set.
	*	@post	none.
	*	@return	CreatTime.
	*/
	string GetCreatTime()
	{
		return fCreatTime;
	}


	/**
	*	@brief	Get 폴더 수
	*	@pre	폴더 수 is set.
	*	@post	none.
	*	@return	폴더 수.
	*/
	int GetSubFolderNum()
	{
		return fSubFolderNum;
	}

	/**
	*	@brief	Get Iden
	*	@pre	Iden is set.
	*	@post	none.
	*	@return	Iden.
	*/
	bool GetIden() {
		return iden;
	}


	// -------------------------------------------------------

	// ------------------------Set ---------------------------

	/**
	*	@brief	Set FolderName.
	*	@pre	none.
	*	@post	FolderName is set.
	*	@param	inFolderName.
	*/
	void SetFolderName(string inFolderName)
	{
		fName = inFolderName;
	}

	/**
	*	@brief	Set FolderPosition.
	*	@pre	none.
	*	@post	FolderPosition is set.
	*	@param	inFolderPosition.
	*/
	void SetFolderPosition(string inFolderPosition)
	{
		fPath = inFolderPosition;
	}

	/**
	*	@brief	Set CreatTime.
	*	@pre	none.
	*	@post	CreatTime is set.
	*/
	void SetCreatTime()
	{
		time_t     now = time(0); //현재 시간을 time_t 타입으로 저장
		struct tm  tstruct;
		char       buf[80];
		tstruct = *localtime(&now);
		strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct); // YYYY-MM-DD.HH:mm:ss 형태의 스트링

		fCreatTime = buf;
	}

	/**
	*	@brief	Set Iden.
	*	@pre	none.
	*	@post	Iden is set.
	*/
	void SetIden(bool num) {
		iden = num;
	}

	/**
	*	@brief	Set FolderSize.
	*	@pre	none.
	*	@post	FolderSize is set.
	*	@param	입력받은 string값 inFolderName.
	*/
	void SetSubFolderNum(int inFolderNum)
	{
		fSubFolderNum = inFolderNum;
	}

	/**
	*	@brief	Set File record.
	*	@pre	none.
	*	@post	File record is set.
	*	@param	inFolderName.
	*	@param	inFolderPosition.
	*	@param	inCreatTime.
	*	@param	inFolderSize.
	*/
	void SetRecord(string inFolderName, string inFolderPosition, string inFolderSize, int inFolderNum)
	{
		SetFolderName(inFolderName);
		SetFolderPosition(inFolderPosition);
		SetCreatTime();
		SetSubFolderNum(inFolderNum);
	}

	// -----------------------------------------------------------
// ------------------------Display ---------------------------


	/**
	*	@brief	Display FolderName on screen.
	*	@pre	FolderName is set.
	*	@post	FolderName is on screen.
	*/
	void DisplayFolderNameOnScreen()
	{
		cout << "\t폴더명 : " << fName << endl;
	};

	/**
	*	@brief	Display FolderPosition on screen.
	*	@pre	FolderPosition is set.
	*	@post	FolderPosition is on screen.
	*/
	void DisplayFolderPositionOnScreen()
	{
		cout << "\t위치  " << fPath << endl;
	};

	/**
	*	@brief	Display CreatTime on screen.
	*	@pre	CreatTime is set.
	*	@post	CreatTime is on screen.
	*/
	void DisplayCreatTimeOnScreen()
	{
		cout << "\t생성한 시간 : " << fCreatTime << endl;
	};


	/**
	*	@brief	Display FolderSize on screen.
	*	@pre	FolderSize is set.
	*	@post	FolderSize is on screen.
	*/
	void DisplayFolderNumOnScreen()
	{
		cout << "\t포함된 폴더 수 : " << fSubFolderNum << endl;
	};

	/**
	*	@brief	Display an Folder record on screen.
	*	@pre	Folder record is set.
	*	@post	Folder record is on screen.
	*/
	void DisplayRecordOnScreen(FolderType data)
	{
		fList->Display(data);
		if (fileNum >= 1) {
			cout << "\t [File]" << endl;
			cout << "\t┌───────────────────────────────────────────────────────────────┐" << endl;
			for (int i = 0; i < fileNum; i++) {
				file[i].fileShow();
			}
			cout << "\t└───────────────────────────────────────────────────────────────┘" << endl;
		}
	};



	// -----------------------------------------------------------


	// ------------------------SetFromKB ---------------------------


	/**
	*	@brief	Set FolderName from keyboard.
	*	@pre	none.
	*	@post	FolderName is set.
	*/
	void SetFolderNameFromKB();
	/**
	*	@brief	Set FolderPosition from keyboard.
	*	@pre	none.
	*	@post	FolderPosition is set.
	*/
	void SetFolderPositionFromKB();


	/**
	*	@brief	Set FileRecord from keyboard.
	*	@pre	none.
	*	@post	FileRecord is set.
	*/
	void SetRecordFromKB();

	void nullSet() {
		fName = "0";
		fPath = "0";
		fCreatTime = "0";
		fSubFolderNum = 0;
	}



	/**
	*	Compare two FolderTypes.
	*	@brief	Compare two Folder types by Folder id.
	*	@pre	two Folder types should be initialized.
	*	@post	the target file is included the new Folder record.
	*	@param	data	target Folder for comparing.
	*	@return	return LESS if this.id < data.id,
	*			return GREATER if this.id > data.id then,
	*			otherwise return EQUAL.
	*/
	RelationType CompareByID(const FolderType &data);

	FolderType& operator= (const FolderType& data);


	/**
	*	@brief	폴더 생성하는 함수
	*	@pre	none.
	*	@post	폴더 생성.
	*	@return	add성공시 1, 아닐시 0 반환.
	*/
	int AddFolder();


	/**
	*	@brief	폴더 삭제 함수
	*	@pre	none.
	*	@post	폴더 삭제.
	*	@return	삭제여부 상관없이 1 반환.
	*/
	int DeleteFolder();


	/**
	*	@brief	검색내용 출력해줌
	*	@pre	폴더 입력 완료.
	*	@post	검색결과 출력
	*	@return	상관없이 1 반환.
	*/
	int BinarySearchFolderByName(string temp, int num, FolderType &Ft);

	/**
	*	@brief	검색내용 출력해줌
	*	@pre	파일 입력 완료.
	*	@post	검색결과 출력
	*	@return	상관없이 1 반환.
	*/
	int BinarySearchFileByName(string temp);


	/**
	*	@brief	하위폴더에 들어가는 m_CurPoint를 위한 함수.
	*	@pre	폴더 입력.
	*	@post	하위폴더로 이동.
	*	@param	foldertype 주소값을 줌.
	*	@return	하위폴더 받을 수 있다면 주소로 받아서 m_CurPoint가 가르킴.
	*/
	FolderType& Exist(FolderType &data);

	/**
	*	@brief	하위폴더에 들어가는 m_CurPoint를 위한 함수.
	*	@pre	폴더 입력.
	*	@post	하위폴더로 이동.
	*	@param	foldertype 주소값을 줌.
	*	@return	하위폴더에 겹치는 값이 있으면 1, 아니면 0반환.
	*/
	int iExist(FolderType data);


	/**
	*	@brief	fList 동적 할당.
	*	@pre	none.
	*	@post	fList 동적 할당완료.
	*	@param	폴더 위치 받아옴.
	*/
	void NewfList(string temp) {
		fList = new DoublyLinkedList<FolderType>;
	}

	/**
	*	@brief	스택 쌓는 위한함수.
	*	@pre	none.
	*	@post	스택 쌓는 위한함수.
	*	@param	현재길이 cur와 foldertype주소값 m_Cur받아옴.
	*/
	void subA(int cur, FolderType &m_Cur) {
		cur--;
		fList->subB(cur, m_Cur);
	}

	/**
	*	@brief	MoveBack함수에서 상위폴더 주소값 받기.
	*	@pre	폴더 입력 완료.
	*	@post	MoveBack함수에서 상위폴더 주소값 받기.
	*	@param	현재길이 cur.
	*	@return	상위폴더 주소값 받기.
	*/
	FolderType& GoA(int cur) {
		cur--;
		return fList->GoB(cur);
	}

	/**
	*	@brief	파일 추가.
	*	@pre	none.
	*	@post	파일 추가 완료.
	*/
	void AddFile();


	/**
	*	@brief	파일명으로 정렬.
	*	@pre	값 저장된 상태.
	*	@post	파일명으로 정렬완료.
	*/
	void SortedFileName();


	/**
	*	@brief	파일 삭제
	*	@pre	값 저장된 상태.
	*	@post	파일 삭제.
	*/
	void DeleteFile();


	/**
	*	@brief	실행 1 : 파일 쓰기
	*	@pre	none
	*	@post	실행 1 : 파일 쓰기 완료
	*/
	void Execution1();


	/**
	*	@brief	실행 2 : 파일 읽기
	*	@pre	none
	*	@post	실행 2 : 파일 읽기 완료
	*/
	void Execution2();

	/**
	*	@brief	폴더명 변경
	*	@pre	none
	*	@post	폴더명 변경 완료
	*/
	void Rename() {
		string s;
		cout << "\t폴더명 : ";
		cin >> s;
		fList->fRename(s);
	}

	/**
	*	@brief	파일명 변경
	*	@pre	none
	*	@post	파일명 변경 완료
	*/
	void RenameFi();

	/**
	*	@brief	최근 열어본 파일 목록위한 함수
	*	@pre	none
	*	@post	최근 열어본 파일 목록위한 함수
	*	@return	파일 최근 10개 목록 사용 겹치는지 여부
	*/
	bool Execution1_FA1() {
		return fArrayIden;
	}

	/**
	*	@brief	최근 열어본 파일 목록위한 함수
	*	@pre	none
	*	@post	최근 열어본 파일 목록위한 함수
	*	@return	파일명 반환
	*/
	string Execution1_FA2() {
		return fArrayString;
	}


	/**
	*	@brief	폴더복사 가능한지
	*	@pre	none
	*	@post	폴더복사 가능한지 여부
	*	@param	폴더명
	*	@return	복사가능한 폴더명 있다면 true, 아니라면 false
	*/
	bool CopySuccess(string s) {
		if (fList->Copysu(s)) {
			return true;
		}
		else {
			false;
		}

	}


	/**
	*	@brief	파일복사 가능한지
	*	@pre	none
	*	@post	파일복사 가능한지 여부
	*	@param	파일명
	*	@return	복사가능한 파일명 있다면 true, 아니라면 false
	*/
	bool CopySuccess2(string s) {
		for (int i = 0; i < fileNum; i++) {
			if (file[i].GetFileName() == s) {
				return true;
			}
		}
		return false;
	}


	/**
	*	@brief	폴더복사 함수
	*	@pre	none
	*	@post	폴더복사 완료
	*	@param	폴더명
	*	@return	폴더 반환
	*/
	FolderType& CopyF(string s) {
		FolderType *temp = &fList->GetCopy(s);
		return *temp;

	}

	/**
	*	@brief	파일복사 함수
	*	@pre	none
	*	@post	파일복사 완료
	*	@param	파일명
	*	@return	파일 반환
	*/
	FileType& CopyF2(string s) {
		for (int i = 0; i < fileNum; i++) {
			if (file[i].GetFileName() == s) {
				return file[i];
			}
		}
		return file[0];
	}

	/**
	*	@brief	폴더붙여넣기 함수
	*	@pre	none
	*	@post	폴더붙여넣기 완료
	*	@param	붙여넣을 폴더
	*/
	void PasteF(FolderType Copy) {
		fList->SetCopy(Copy);
	}

	/**
	*	@brief	파일붙여넣기 함수
	*	@pre	none
	*	@post	파일붙여넣기 완료
	*	@param	붙여넣을 파일
	*/
	void PasteF2(FileType &CopyFi) {
		file[fileNum] = CopyFi;
		fileNum++;
	}

	/**
	*	@brief	폴더 잘라내기
	*	@pre	none
	*	@post	폴더 잘라내기 완료
	*	@param	잘라낼 폴더명
	*/
	void CutDelete(string s) {
		FolderType *temp = &fList->GetCopy(s);

		if (fSubFolderNum != 0)
		{
			int num = fList->Delete(*temp);

			if (num)
			{
				cout << "\t삭제 완료!" << endl;
				fSubFolderNum--;
			}
		}
	}

	/**
	*	@brief	파일 잘라내기
	*	@pre	none
	*	@post	파일 잘라내기 완료
	*	@param	잘라낼 파일명
	*/
	void CutDelete2(string s) {
		for (int i = 0; i < fileNum; i++) {
			if (file[i].GetFileName() == s) {
				file[i] = file[fileNum - 1];
				fileNum--;
			}
		}
	}
	string GetEx() {
		return fArrayEx;
	}


	/**
	*	@brief	길이 반환
	*	@pre	none.
	*	@post	길이 반환 완료
	*	@return	길이
	*/
	int GetLen() {
		return fSubFolderNum;
	}

protected:

	DoublyLinkedList<FolderType> *fList; // DoublyLinkedList로 구현
	DoublyLinkedList<FileType> *fileList; // DoublyLinkedList로 구현

	string fName;			//폴더이름
	string fPath;			//폴더위치
	string fCreatTime;		//생성시간
	int fSubFolderNum;		//서브폴더 수
	bool iden; //하위폴더 한번 갔었는지 확인하는 변수
	FileType *file; //파일 포인터
	int fileNum; //파일 개수
	int fileMax; //파일 최대 개수

	bool fArrayIden;		//입력받은 파일명과 존재하는 파일명이 같다면 true
	string fArrayString;	//열어본 파일명 반환
	string fArrayEx;		//열어본 파일명의 확장자
};

#endif	// _FolderType_H
