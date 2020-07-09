#include "FolderType.h"
#include "DoublyLinkedList.h"


// Set FolderName from keyboard.
void FolderType::SetFolderNameFromKB()
{
	cout << "\t������ : ";
	cin >> fName;
}

// Set FolderPosition from keyboard.
void FolderType::SetFolderPositionFromKB()
{
	cout << "\t���� ��ġ : ";
	cin >> fPath;
}




// Set student record from keyboard.
void FolderType::SetRecordFromKB()
{
	SetFolderNameFromKB();
	SetFolderPosition(fPath);
	SetCreatTime();
}


// Compare two FolderTypes.
RelationType FolderType::CompareByID(const FolderType &data)
{
	if (this->fName > data.fName)
		return GREATER;
	else if (this->fName < data.fName)
		return LESS;
	else
		return EQUAL;
}

// operator= ����
FolderType& FolderType::operator= (const FolderType& data)
{
	this->fName = data.fName;
	this->fPath = data.fPath;
	this->fCreatTime = data.fCreatTime;
	this->fSubFolderNum = data.fSubFolderNum;
	this->iden = data.iden;

	if (fSubFolderNum != 0)
	{
		this->fList = data.fList;
	}
	this->fileNum = data.fileNum;
	this->fileMax = data.fileMax;
	FileType t;

	for (int i = 0; i < fileNum; i++) {
		t = data.file[i];
		this->file[i] = t;

	}
	return *this;
}

// ���� �����ϴ� �Լ�
int FolderType::AddFolder()
{

	FolderType data;
	data.SetRecordFromKB();


	if (fList->Overlap(data) == 1) { //�ߺ��ִٸ� 1��ȯ
		cout << "\n\t������ �ߺ�! �߰�����" << endl;
		return 0;
	}

	if (fList->Add(data))
		fSubFolderNum++;

	//����
	fList->SortedFolderName();


	return 1;
}

//���� �����ϴ� �Լ�
int FolderType::DeleteFolder()
{
	if (fSubFolderNum != 0)
	{
		FolderType data;
		data.SetFolderNameFromKB();

		int num = fList->Delete(data);

		if (num)
		{
			cout << "\t���� �Ϸ�!" << endl;
			fSubFolderNum--;
		}
		else
		{
			cout << "\t���� ����! ��ġ�ϴ� �̸��� �����ϴ�." << endl;
		}
	}

	return 1;
}


//�̸����� �˻�
int FolderType::BinarySearchFolderByName(string temp, int num, FolderType &Ft)
{
	int start = 0, end;
	int middle;
	if (num != 0) {
		fList->RetrieveFolder(temp, Ft); //�˻� ��� ���
	}

	return 1;
}

// ���������� ���� m_CurPoint�� ���� �Լ�
FolderType& FolderType::Exist(FolderType &data) {
	if (fList->IntPathExist(data)) {
		return fList->PathExist(data);
	}
	else {
		return data;
	}

}

// ���������� ���� m_CurPoint�� ���� �Լ�
int FolderType::iExist(FolderType data) {
	return fList->IntPathExist(data);
}




//�̸����� �˻�
int FolderType::BinarySearchFileByName(string temp)
{
	if (fileNum != 0) {
		for (int i = 0; i < fileNum; i++) {
			if (file[i].GetFileName().find(temp) != -1)
			{
				cout << "\t" << file[i].GetFileName() << "\t��ġ : " << fPath << endl;
			}
		}
	}
	fList->RetrieveFile(temp); //�˻� ��� ���


	return 1;
}

//���� �߰�
void FolderType::AddFile() {
	if (fileNum > fileMax - 1) {
		FileType *temp = new FileType[fileMax];
		for (int i = 0; i < fileMax; i++) {
			temp[i] = file[i];
		}
		fileMax += 5;
		file = new FileType[fileMax];

		for (int i = 0; i < fileMax - 5; i++) {
			file[i] = temp[i];
		}
	}

	string temp;
	int n;
	cout << "\t���ϸ� : ";
	cin >> temp;
	int iden = 0;
	for (int i = 0; i < fileNum; i++) {
		if (file[i].GetFileName() == temp) {
			iden++;
		}
	}
	if (iden > 0) {
		cout << "\n\t���ϸ� �ߺ�! �߰�����" << endl;
	}
	else {
		cout << "\t�ؽ�Ʈ(1), ����(2), ����(3) �� �����Դϱ�? : ";
		cin >> n;
		if (n == 1 || n == 2 || n == 3) {
			if (n == 1) {
				file[fileNum].SetFileEx(".txt");
			}
			else if (n == 2) {
				file[fileNum].SetFileEx(".jpg");
			}
			else if (n == 3) {
				file[fileNum].SetFileEx(".mp3");
			}
			file[fileNum].SetFileName(temp);
			file[fileNum].Add();
			fileNum++;
		}
	}
	//
	SortedFileName();
}

//���ϸ����� ����
void FolderType::SortedFileName() {
	FileType temp;
	for (int i = 0; i < fileNum; i++)
	{
		for (int j = i + 1; j < fileNum; j++)
		{
			if (file[i].GetFileName() > file[j].GetFileName())
			{
				temp = file[i];
				file[i] = file[j];
				file[j] = temp;
			}
		}
	}
}

//���� ����
void FolderType::DeleteFile()
{
	string temp;
	cout << "\t������ ���ϸ� : ";
	cin >> temp;
	const char *ch;
	string temp2;
	if (fileNum != 0)
	{

		int iden = 0;
		for (int i = 0; i < fileNum; i++) {
			if (file[i].GetFileName() == temp) {
				temp2 = file[i].GetFileName() + ".txt";
				ch = temp2.c_str();
				remove(ch);  // txt���� ����
				file[i] = file[fileNum - 1];
				iden++;
			}
		}

		if (iden > 0) {
			fileNum--;
			cout << "\t���� �Ϸ�!" << endl;
		}

		else {
			cout << "\t���� ����! ��ġ�ϴ� �̸��� �����ϴ�." << endl;
		}

	}
	else
	{
		cout << "\t���� ����! ��ġ�ϴ� �̸��� �����ϴ�." << endl;
	}
}

// ���� ����
void FolderType::Execution1() {
	fArrayIden = false;
	fArrayString = "";
	fArrayEx = "";
	string temp;
	cout << "\t������ ���ϸ� : ";
	cin >> temp;

	int iden = 0;

	if (fileNum != 0)
	{
		for (int i = 0; i < fileNum; i++) {
			if (file[i].GetFileName() == temp) {
				file[i].WriteTxt();
				file[i].SetAccessTime();
				iden++;
				fArrayIden = true;
				fArrayString = temp;
				fArrayEx = file[i].GetFileEx();
			}
		}
		if (iden == 0) {
			cout << "\t���� ����! ��ġ�ϴ� �̸��� �����ϴ�." << endl;
		}
	}
	else
	{
		cout << "\t���� ����! ��ġ�ϴ� �̸��� �����ϴ�." << endl;
	}
}

//���� �б�
void FolderType::Execution2() {
	fArrayIden = false;
	fArrayString = "";
	fArrayEx = "";

	string temp;
	cout << "\t���� ���ϸ� : ";
	cin >> temp;

	int iden = 0;

	if (fileNum != 0)
	{
		for (int i = 0; i < fileNum; i++) {
			if (file[i].GetFileName() == temp) {
				file[i].ReadTxt();
				file[i].SetAccessTime();
				iden++;
				fArrayIden = true;
				fArrayString = temp;
				fArrayEx = file[i].GetFileEx();
			}
		}
		if (iden == 0) {
			cout << "\t���� ����! ��ġ�ϴ� �̸��� �����ϴ�." << endl;
		}
	}
	else
	{
		cout << "\t���� ����! ��ġ�ϴ� �̸��� �����ϴ�." << endl;
	}
}

//���ϸ� ����
void FolderType::RenameFi() {

	fArrayIden = false;
	fArrayString = "";

	string temp;
	cout << "\t���ϸ� : ";
	cin >> temp;
	int iden = 0;
	string temp2;
	const char *ch;
	const char *ch2;
	if (fileNum != 0)
	{
		for (int i = 0; i < fileNum; i++) {
			if (file[i].GetFileName() == temp) {

				cout << "\t� �̸����� �����Ͻðڽ��ϱ�? : ";
				cin >> temp2;
				//���� �̸� ����
				file[i].SetFileName(temp2);

				fArrayString = temp2;
				fArrayIden = true;

				// �̸� ����
				if (file[i].GetFileEx() == ".txt") {
					temp2 = temp2 + ".txt";
					ch2 = temp2.c_str();
					temp = temp + ".txt";
					ch = temp.c_str();
					rename(ch, ch2);  // txt���� �̸�����
				}
				iden++;
				cout << "\t���� �Ϸ�" << endl;
			}
		}
		if (iden == 0) {
			cout << "\t���� ����! ��ġ�ϴ� �̸��� �����ϴ�." << endl;
		}
	}
	else
	{
		cout << "\t���� ����! ��ġ�ϴ� �̸��� �����ϴ�." << endl;
	}

}