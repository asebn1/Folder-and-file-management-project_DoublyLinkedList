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
		//root ����
		m_RootFolder.SetFolderName("root");
		m_RootFolder.SetFolderPosition("/root");
		m_RootFolder.SetCreatTime();
		m_RootFolder.SetSubFolderNum(0);

		//�������� ����
		m_curFolder = &m_RootFolder;
		m_curFolder->NewfList(m_RootFolder.GetFolderPosition());

		//����
		Stack = &m_RootFolder;

		//�ֱٿ������ ����
		s_Array[0] = m_RootFolder.GetFolderPosition();
		s_cur = 0;
		f_cur = -1;

		//���翩�� false ����
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
	*	@brief	���� ������ �����ϱ� ���ؼ� ����Ǵ� �Լ�
	*	@pre	���ڵ忡 ������ ����
	*	@post	�˻����� ���õ� �����Ͱ� �����ž���.
	*	@return	�������� ������� �׻� 1�� ����
	*/
	void DeleteFolder();



	/**
	*	@brief  ���� ������ �̵��ϴ� �Լ�
	*	@pre	none.
	*	@post	���� ������ �̵�
	*/
	void MoveSubFolder();


	/**
	*	@brief  ���� ������ �̵��ϴ� �Լ�
	*	@pre	none.
	*	@post	���� ������ �̵�
	*/
	void MoveBack();

	/**
	*	@brief  ���� ������ �̵��ϴ� �Լ�
	*	@pre	none.
	*	@post	���� ������ �̵�
	*/
	void MoveForward();

	/**
	*	@brief	����Ʈ�� �ִ� ���� �˻� �� �������� ��� �����̶� ���ĵ� ��� ���
	*	@pre	none.
	*	@post	�˻����� ���õ� �������� ������ ��µž���.
	*/
	void BinarySearchFolderByName();

	/**
	*	@brief  �ֱ� ��� ���� 10������ ��� queue�� ����
	*	@pre	none.
	*	@post	�ֱ� ��� ���� 10������ ��¿Ϸ�
	*/
	void OpenFolderList();



	/**
	*	@brief  ���� ������ �Ӽ� ���
	*	@pre	none.
	*	@post	���� ������ �Ӽ� ��¿Ϸ�
	*/
	void CurrentFolderProperty();

	/**
	*	@brief  ���� ����
	*	@pre	none.
	*	@post	���� ���� �Ϸ�
	*/
	void NewFile();

	/**
	*	@brief  �����̸����� �˻�
	*	@pre	���� ���� ����.
	*	@post	�����̸����� �˻� ���
	*/
	void BinarySearchFileByName();


	/**
	*	@brief  ���� ����
	*	@pre	none.
	*	@post	���� ���� �Ϸ�
	*/
	void DeleteFile();

	/**
	*	@brief  ���� �̸� ����
	*	@pre	none.
	*	@post	���� �̸� ���� �Ϸ�
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
	*	@brief  ���� �̸� ����
	*	@pre	none.
	*	@post	���� �̸� ���� �Ϸ�
	*/
	void RenameFile();

	/**
	*	@brief  �ֱ� ��� ���� 10������ ��� queue�� ����
	*	@pre	none.
	*	@post	�ֱ� ��� ���� 10������ ��¿Ϸ�
	*/
	void OpenFileList();

	/**
	*	@brief  ���� ����
	*	@pre	none.
	*	@post	���� ���� �Ϸ�
	*/
	void CopyFolder();

	/**
	*	@brief  ���� �ٿ��ֱ�
	*	@pre	none.
	*	@post	���� �ٿ��ֱ� �Ϸ�
	*/
	void PasteFolder();

	/**
	*	@brief  ���� �߶󳻱�
	*	@pre	none.
	*	@post	���� �߶󳻱� �Ϸ�
	*/
	void CutFolder();

	/**
	*	@brief  ���� ����
	*	@pre	none.
	*	@post	���� ���� �Ϸ�
	*/
	void CopyFile();

	/**
	*	@brief  ���� �ٿ��ֱ�
	*	@pre	none.
	*	@post	���� �ٿ��ֱ� �Ϸ�
	*/
	void PasteFile();

	/**
	*	@brief  ���� �߶󳻱�
	*	@pre	none.
	*	@post	���� �߶󳻱� �Ϸ�
	*/
	void CutFile();

private:
	//	ifstream m_InFile;		///< input file descriptor.
	//	ofstream m_OutFile;		///< output file descriptor.

	FolderType m_RootFolder;		// item list.criptor.
	FolderType *m_curFolder;		// item list.
	FolderType *Stack;				// �ڷΰ��� ��� ���� �ִ� ����
	int m_Command;			///< current command number.
	int cur = 0;			// ���� ������ ��ġ
	int tcur = 0;			// ���� ���� ������ ��ġ
	bool iden;				// ������ �̵� �������� ����

	string s_Array[10];    //�ֱ� ��� ���� �� ����
	string f_Array[10];    //�ֱ� ��� ���� �� ����
	int s_cur;			//s_Array�� ��ġ
	int f_cur;			//s_Array�� ��ġ

	ifstream InFile;		///< input file descriptor.
	ofstream OutFile;		///< output file descriptor.

	FolderType Copy;		// ���� ����
	bool CopyIden;			// ����Ǿ������� true, �ƴ϶�� false

	FileType CopyFi;		// ���� ����
	bool CopyIdenFile;		// ����Ǿ������� true, �ƴ϶�� false

};

#endif	// _APPLICATION_H