
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

//���� Ÿ��
class FileType {

public:
	//���� ����
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
	*	@brief	GET ���ϸ�
	*	@pre	none
	*	@post	GET ���ϸ�
	*	@return	���ϸ� ����
	*/
	string GetFileName() {
		return fileName;
	}

	/**
	*	@brief	SET ���ϸ�
	*	@pre	none
	*	@post	SET ���ϸ�
	*	@param	SET�� string ����
	*/
	void SetFileName(string temp) {
		fileName = temp;
	}

	/**
	*	@brief	GET Ȯ���ڸ�
	*	@pre	none
	*	@post	GET Ȯ���ڸ�
	*	@return	Ȯ���ڸ� ����
	*/
	string GetFileEx() {
		return fileEx;
	}

	/**
	*	@brief	SET Ȯ���ڸ�
	*	@pre	none
	*	@post	SET Ȯ���ڸ�
	*	@param	SET�� string ����
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
		time_t     now = time(0); //���� �ð��� time_t Ÿ������ ����
		struct tm  tstruct;
		char       buf[80];
		tstruct = *localtime(&now);
		strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct); // YYYY-MM-DD.HH:mm:ss ������ ��Ʈ��

		fileCreatTime = buf;
	}


	/**
	*	@brief	Set AccessTime.
	*	@pre	none.
	*	@post	AccessTime is set.
	*/
	void SetAccessTime()
	{
		time_t     now = time(0); //���� �ð��� time_t Ÿ������ ����
		struct tm  tstruct;
		char       buf[80];
		tstruct = *localtime(&now);
		strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct); // YYYY-MM-DD.HH:mm:ss ������ ��Ʈ��

		fileAccessTime = buf;
	}


	/**
	*	@brief	�����ð� �߰�
	*	@pre	none
	*	@post	�����ð� �߰��Ϸ�
	*/
	void Add() {
		SetCreatTime();
	}

	/**
	*	@brief	�������� ���
	*	@pre	none
	*	@post	�������� ��¿Ϸ�
	*/
	void fileShow() {
		if (fileAccessTime == "") {
			cout << "\t��  ";
			cout.width(5);
			cout.fill(' ');
			cout << fileName << fileEx;
			cout.width(33);
			cout.fill(' ');
			cout << fileCreatTime << "\t\t\t��" << endl;
		}
		else {
			cout << "\t��  ";
			cout.width(5);
			cout.fill(' ');
			cout << fileName << fileEx;
			cout.width(33);
			cout.fill(' ');
			cout << fileCreatTime;
			cout << "\t\t\t��" << "\t";
			cout << fileAccessTime << endl;
		}
	}

	/**
	*	@brief	���� ����
	*	@pre	none
	*	@post	���� ���� �Ϸ�
	*/
	void WriteTxt() {
		string s;
		string temp;
		if (fileEx == ".txt") {
			ofstream out(fileName + ".txt");
			cout << "\t������ ����( '0' �� ���Ե� �� ���峻�� ����) : ";
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
			cout << "�ش� ������ .txt������ �ƴմϴ�." << endl;
		}
	}

	/**
	*	@brief	���� �б�
	*	@pre	none
	*	@post	���� �б� �Ϸ�
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
				cout << "\t�������!" << endl;
			}
			else if (fileEx == ".mp3") {
				cout << "\t��������!" << endl;
			}

		}

	}
private:
	string fileName; //���ϸ�
	string fileCreatTime; //���� �����ð�
	string fileAccessTime; //������ �ð�
	string fileEx; //Ȯ����

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
	*	@brief	Get ���� ��
	*	@pre	���� �� is set.
	*	@post	none.
	*	@return	���� ��.
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
		time_t     now = time(0); //���� �ð��� time_t Ÿ������ ����
		struct tm  tstruct;
		char       buf[80];
		tstruct = *localtime(&now);
		strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct); // YYYY-MM-DD.HH:mm:ss ������ ��Ʈ��

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
	*	@param	�Է¹��� string�� inFolderName.
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
		cout << "\t������ : " << fName << endl;
	};

	/**
	*	@brief	Display FolderPosition on screen.
	*	@pre	FolderPosition is set.
	*	@post	FolderPosition is on screen.
	*/
	void DisplayFolderPositionOnScreen()
	{
		cout << "\t��ġ  " << fPath << endl;
	};

	/**
	*	@brief	Display CreatTime on screen.
	*	@pre	CreatTime is set.
	*	@post	CreatTime is on screen.
	*/
	void DisplayCreatTimeOnScreen()
	{
		cout << "\t������ �ð� : " << fCreatTime << endl;
	};


	/**
	*	@brief	Display FolderSize on screen.
	*	@pre	FolderSize is set.
	*	@post	FolderSize is on screen.
	*/
	void DisplayFolderNumOnScreen()
	{
		cout << "\t���Ե� ���� �� : " << fSubFolderNum << endl;
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
			cout << "\t����������������������������������������������������������������������������������������������������������������������������������" << endl;
			for (int i = 0; i < fileNum; i++) {
				file[i].fileShow();
			}
			cout << "\t����������������������������������������������������������������������������������������������������������������������������������" << endl;
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
	*	@brief	���� �����ϴ� �Լ�
	*	@pre	none.
	*	@post	���� ����.
	*	@return	add������ 1, �ƴҽ� 0 ��ȯ.
	*/
	int AddFolder();


	/**
	*	@brief	���� ���� �Լ�
	*	@pre	none.
	*	@post	���� ����.
	*	@return	�������� ������� 1 ��ȯ.
	*/
	int DeleteFolder();


	/**
	*	@brief	�˻����� �������
	*	@pre	���� �Է� �Ϸ�.
	*	@post	�˻���� ���
	*	@return	������� 1 ��ȯ.
	*/
	int BinarySearchFolderByName(string temp, int num, FolderType &Ft);

	/**
	*	@brief	�˻����� �������
	*	@pre	���� �Է� �Ϸ�.
	*	@post	�˻���� ���
	*	@return	������� 1 ��ȯ.
	*/
	int BinarySearchFileByName(string temp);


	/**
	*	@brief	���������� ���� m_CurPoint�� ���� �Լ�.
	*	@pre	���� �Է�.
	*	@post	���������� �̵�.
	*	@param	foldertype �ּҰ��� ��.
	*	@return	�������� ���� �� �ִٸ� �ּҷ� �޾Ƽ� m_CurPoint�� ����Ŵ.
	*/
	FolderType& Exist(FolderType &data);

	/**
	*	@brief	���������� ���� m_CurPoint�� ���� �Լ�.
	*	@pre	���� �Է�.
	*	@post	���������� �̵�.
	*	@param	foldertype �ּҰ��� ��.
	*	@return	���������� ��ġ�� ���� ������ 1, �ƴϸ� 0��ȯ.
	*/
	int iExist(FolderType data);


	/**
	*	@brief	fList ���� �Ҵ�.
	*	@pre	none.
	*	@post	fList ���� �Ҵ�Ϸ�.
	*	@param	���� ��ġ �޾ƿ�.
	*/
	void NewfList(string temp) {
		fList = new DoublyLinkedList<FolderType>;
	}

	/**
	*	@brief	���� �״� �����Լ�.
	*	@pre	none.
	*	@post	���� �״� �����Լ�.
	*	@param	������� cur�� foldertype�ּҰ� m_Cur�޾ƿ�.
	*/
	void subA(int cur, FolderType &m_Cur) {
		cur--;
		fList->subB(cur, m_Cur);
	}

	/**
	*	@brief	MoveBack�Լ����� �������� �ּҰ� �ޱ�.
	*	@pre	���� �Է� �Ϸ�.
	*	@post	MoveBack�Լ����� �������� �ּҰ� �ޱ�.
	*	@param	������� cur.
	*	@return	�������� �ּҰ� �ޱ�.
	*/
	FolderType& GoA(int cur) {
		cur--;
		return fList->GoB(cur);
	}

	/**
	*	@brief	���� �߰�.
	*	@pre	none.
	*	@post	���� �߰� �Ϸ�.
	*/
	void AddFile();


	/**
	*	@brief	���ϸ����� ����.
	*	@pre	�� ����� ����.
	*	@post	���ϸ����� ���ĿϷ�.
	*/
	void SortedFileName();


	/**
	*	@brief	���� ����
	*	@pre	�� ����� ����.
	*	@post	���� ����.
	*/
	void DeleteFile();


	/**
	*	@brief	���� 1 : ���� ����
	*	@pre	none
	*	@post	���� 1 : ���� ���� �Ϸ�
	*/
	void Execution1();


	/**
	*	@brief	���� 2 : ���� �б�
	*	@pre	none
	*	@post	���� 2 : ���� �б� �Ϸ�
	*/
	void Execution2();

	/**
	*	@brief	������ ����
	*	@pre	none
	*	@post	������ ���� �Ϸ�
	*/
	void Rename() {
		string s;
		cout << "\t������ : ";
		cin >> s;
		fList->fRename(s);
	}

	/**
	*	@brief	���ϸ� ����
	*	@pre	none
	*	@post	���ϸ� ���� �Ϸ�
	*/
	void RenameFi();

	/**
	*	@brief	�ֱ� ��� ���� ������� �Լ�
	*	@pre	none
	*	@post	�ֱ� ��� ���� ������� �Լ�
	*	@return	���� �ֱ� 10�� ��� ��� ��ġ���� ����
	*/
	bool Execution1_FA1() {
		return fArrayIden;
	}

	/**
	*	@brief	�ֱ� ��� ���� ������� �Լ�
	*	@pre	none
	*	@post	�ֱ� ��� ���� ������� �Լ�
	*	@return	���ϸ� ��ȯ
	*/
	string Execution1_FA2() {
		return fArrayString;
	}


	/**
	*	@brief	�������� ��������
	*	@pre	none
	*	@post	�������� �������� ����
	*	@param	������
	*	@return	���簡���� ������ �ִٸ� true, �ƴ϶�� false
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
	*	@brief	���Ϻ��� ��������
	*	@pre	none
	*	@post	���Ϻ��� �������� ����
	*	@param	���ϸ�
	*	@return	���簡���� ���ϸ� �ִٸ� true, �ƴ϶�� false
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
	*	@brief	�������� �Լ�
	*	@pre	none
	*	@post	�������� �Ϸ�
	*	@param	������
	*	@return	���� ��ȯ
	*/
	FolderType& CopyF(string s) {
		FolderType *temp = &fList->GetCopy(s);
		return *temp;

	}

	/**
	*	@brief	���Ϻ��� �Լ�
	*	@pre	none
	*	@post	���Ϻ��� �Ϸ�
	*	@param	���ϸ�
	*	@return	���� ��ȯ
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
	*	@brief	�����ٿ��ֱ� �Լ�
	*	@pre	none
	*	@post	�����ٿ��ֱ� �Ϸ�
	*	@param	�ٿ����� ����
	*/
	void PasteF(FolderType Copy) {
		fList->SetCopy(Copy);
	}

	/**
	*	@brief	���Ϻٿ��ֱ� �Լ�
	*	@pre	none
	*	@post	���Ϻٿ��ֱ� �Ϸ�
	*	@param	�ٿ����� ����
	*/
	void PasteF2(FileType &CopyFi) {
		file[fileNum] = CopyFi;
		fileNum++;
	}

	/**
	*	@brief	���� �߶󳻱�
	*	@pre	none
	*	@post	���� �߶󳻱� �Ϸ�
	*	@param	�߶� ������
	*/
	void CutDelete(string s) {
		FolderType *temp = &fList->GetCopy(s);

		if (fSubFolderNum != 0)
		{
			int num = fList->Delete(*temp);

			if (num)
			{
				cout << "\t���� �Ϸ�!" << endl;
				fSubFolderNum--;
			}
		}
	}

	/**
	*	@brief	���� �߶󳻱�
	*	@pre	none
	*	@post	���� �߶󳻱� �Ϸ�
	*	@param	�߶� ���ϸ�
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
	*	@brief	���� ��ȯ
	*	@pre	none.
	*	@post	���� ��ȯ �Ϸ�
	*	@return	����
	*/
	int GetLen() {
		return fSubFolderNum;
	}

protected:

	DoublyLinkedList<FolderType> *fList; // DoublyLinkedList�� ����
	DoublyLinkedList<FileType> *fileList; // DoublyLinkedList�� ����

	string fName;			//�����̸�
	string fPath;			//������ġ
	string fCreatTime;		//�����ð�
	int fSubFolderNum;		//�������� ��
	bool iden; //�������� �ѹ� �������� Ȯ���ϴ� ����
	FileType *file; //���� ������
	int fileNum; //���� ����
	int fileMax; //���� �ִ� ����

	bool fArrayIden;		//�Է¹��� ���ϸ�� �����ϴ� ���ϸ��� ���ٸ� true
	string fArrayString;	//��� ���ϸ� ��ȯ
	string fArrayEx;		//��� ���ϸ��� Ȯ����
};

#endif	// _FolderType_H
