#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "FolderType.h"

#define FILENAMESIZE 1024

/**
*	application class for Folder management simply.
*/
class Application
{
public:
	/**
	*	default constructor.
	*/
	Application()
	{
		m_Command = 0;
		//root 설정
		m_RootFolder.SetFolderName("root");
		m_RootFolder.SetFolderPosition("/root");
		m_RootFolder.SetCreatTime();
		m_RootFolder.SetSubFolderNum(0);

		//현재폴더 설정
		m_curFolder = &m_RootFolder;
		m_curFolder->NewfList(m_RootFolder.GetFolderPosition());

		//설정
		Stack = &m_RootFolder;

		//최근열어본폴더 설정
		s_Array[0] = m_RootFolder.GetFolderPosition();
		s_cur = 0;
		f_cur = -1;

		//복사여부 false 설정
		CopyIden = false;
		CopyIdenFile = false;
	}

	/**
	*	destructor.
	*/
	~Application() {}

	/**
	*	@brief	Program driver.
	*	@pre	program is started.
	*	@post	program is finished.
	*/
	void Run();

	/**
	*	@brief	Display command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*	@return	user's command.
	*/
	int GetCommand();

	/**
	*	@brief	Display command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*	@return	user's command.
	*/
	int GetCommand2();

	/**
	*	@brief	Add new record into list.
	*	@pre	list should be initialized.
	*	@post	new record is added into the list.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	void NewFolder();

	/**
	*	@brief	Display all records in the list on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayFolder();



	/**
	*	@brief	폴더 정보를 삭제하기 위해서 실행되는 함수
	*	@pre	레코드에 내용이 저장
	*	@post	검색으로 선택된 데이터가 삭제돼야함.
	*	@return	삭제여부 관계없이 항상 1을 리턴
	*/
	void DeleteFolder();



	/**
	*	@brief  하위 폴더로 이동하는 함수
	*	@pre	none.
	*	@post	하위 폴더로 이동
	*/
	void MoveSubFolder();


	/**
	*	@brief  상위 폴더로 이동하는 함수
	*	@pre	none.
	*	@post	상위 폴더로 이동
	*/
	void MoveBack();

	/**
	*	@brief  하위 폴더로 이동하는 함수
	*	@pre	none.
	*	@post	하위 폴더로 이동
	*/
	void MoveForward();

	/**
	*	@brief	리스트에 있는 폴더 검색 후 세부정보 출력 조금이라도 겹쳐도 모두 출력
	*	@pre	none.
	*	@post	검색으로 선택된 데이터의 정보가 출력돼야함.
	*/
	void BinarySearchFolderByName();

	/**
	*	@brief  최근 열어본 폴더 10개까지 출력 queue로 진행
	*	@pre	none.
	*	@post	최근 열어본 폴더 10개까지 출력완료
	*/
	void OpenFolderList();



	/**
	*	@brief  현재 폴더의 속성 출력
	*	@pre	none.
	*	@post	현재 폴더의 속성 출력완료
	*/
	void CurrentFolderProperty();

	/**
	*	@brief  파일 생성
	*	@pre	none.
	*	@post	파일 생성 완료
	*/
	void NewFile();

	/**
	*	@brief  파일이름으로 검색
	*	@pre	파일 저장 상태.
	*	@post	파일이름으로 검색 출력
	*/
	void BinarySearchFileByName();


	/**
	*	@brief  파일 삭제
	*	@pre	none.
	*	@post	파일 삭제 완료
	*/
	void DeleteFile();

	/**
	*	@brief  폴더 이름 변경
	*	@pre	none.
	*	@post	폴더 이름 변경 완료
	*/
	void Renamefolder();

	/**
	*	@brief	Open a file as a write mode, and write all data into the file,
	*	@pre	The file is not opened.
	*	@post	the list is stored in the output file.
	*	@return	return 0.
	*/
	int WriteToFile();

	/**
	*	@brief	Open a file as a read mode, read all data on the file, and set list by the data.
	*	@pre	The file is not opened.
	*	@post	list holds all records from the file.
	*	@return	return 0.
	*/
	int ReadFromFile();

	/**
	*	@brief  파일 이름 변경
	*	@pre	none.
	*	@post	파일 이름 변경 완료
	*/
	void RenameFile();

	/**
	*	@brief  최근 열어본 파일 10개까지 출력 queue로 진행
	*	@pre	none.
	*	@post	최근 열어본 파일 10개까지 출력완료
	*/
	void OpenFileList();

	/**
	*	@brief  폴더 복사
	*	@pre	none.
	*	@post	폴더 복사 완료
	*/
	void CopyFolder();

	/**
	*	@brief  폴더 붙여넣기
	*	@pre	none.
	*	@post	폴더 붙여넣기 완료
	*/
	void PasteFolder();

	/**
	*	@brief  폴더 잘라내기
	*	@pre	none.
	*	@post	폴더 잘라내기 완료
	*/
	void CutFolder();

	/**
	*	@brief  파일 복사
	*	@pre	none.
	*	@post	파일 복사 완료
	*/
	void CopyFile();

	/**
	*	@brief  파일 붙여넣기
	*	@pre	none.
	*	@post	파일 붙여넣기 완료
	*/
	void PasteFile();

	/**
	*	@brief  파일 잘라내기
	*	@pre	none.
	*	@post	파일 잘라내기 완료
	*/
	void CutFile();

private:
	//	ifstream m_InFile;		///< input file descriptor.
	//	ofstream m_OutFile;		///< output file descriptor.

	FolderType m_RootFolder;		// item list.criptor.
	FolderType *m_curFolder;		// item list.
	FolderType *Stack;				// 뒤로가기 기능 위해 있는 스택
	int m_Command;			///< current command number.
	int cur = 0;			// 현재 내려간 위치
	int tcur = 0;			// 가장 많이 내려간 위치
	bool iden;				// 앞으로 이동 가능한지 여부

	string s_Array[10];    //최근 열어본 폴더 값 저장
	string f_Array[10];    //최근 열어본 파일 값 저장
	int s_cur;			//s_Array의 위치
	int f_cur;			//s_Array의 위치

	ifstream InFile;		///< input file descriptor.
	ofstream OutFile;		///< output file descriptor.

	FolderType Copy;		// 폴더 복사
	bool CopyIden;			// 복사되어있으면 true, 아니라면 false

	FileType CopyFi;		// 파일 복사
	bool CopyIdenFile;		// 복사되어있으면 true, 아니라면 false

};

#endif	// _APPLICATION_H