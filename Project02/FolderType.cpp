#include "FolderType.h"
#include "DoublyLinkedList.h"


// Set FolderName from keyboard.
void FolderType::SetFolderNameFromKB()
{
	cout << "\t폴더명 : ";
	cin >> fName;
}

// Set FolderPosition from keyboard.
void FolderType::SetFolderPositionFromKB()
{
	cout << "\t폴더 위치 : ";
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

// operator= 정의
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

// 폴더 생성하는 함수
int FolderType::AddFolder()
{

	FolderType data;
	data.SetRecordFromKB();


	if (fList->Overlap(data) == 1) { //중복있다면 1반환
		cout << "\n\t폴더명 중복! 추가실패" << endl;
		return 0;
	}

	if (fList->Add(data))
		fSubFolderNum++;

	//정렬
	fList->SortedFolderName();


	return 1;
}

//폴더 삭제하는 함수
int FolderType::DeleteFolder()
{
	if (fSubFolderNum != 0)
	{
		FolderType data;
		data.SetFolderNameFromKB();

		int num = fList->Delete(data);

		if (num)
		{
			cout << "\t삭제 완료!" << endl;
			fSubFolderNum--;
		}
		else
		{
			cout << "\t삭제 실패! 일치하는 이름이 없습니다." << endl;
		}
	}

	return 1;
}


//이름으로 검색
int FolderType::BinarySearchFolderByName(string temp, int num, FolderType &Ft)
{
	int start = 0, end;
	int middle;
	if (num != 0) {
		fList->RetrieveFolder(temp, Ft); //검색 결과 출력
	}

	return 1;
}

// 하위폴더에 들어가는 m_CurPoint를 위한 함수
FolderType& FolderType::Exist(FolderType &data) {
	if (fList->IntPathExist(data)) {
		return fList->PathExist(data);
	}
	else {
		return data;
	}

}

// 하위폴더에 들어가는 m_CurPoint를 위한 함수
int FolderType::iExist(FolderType data) {
	return fList->IntPathExist(data);
}




//이름으로 검색
int FolderType::BinarySearchFileByName(string temp)
{
	if (fileNum != 0) {
		for (int i = 0; i < fileNum; i++) {
			if (file[i].GetFileName().find(temp) != -1)
			{
				cout << "\t" << file[i].GetFileName() << "\t위치 : " << fPath << endl;
			}
		}
	}
	fList->RetrieveFile(temp); //검색 결과 출력


	return 1;
}

//파일 추가
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
	cout << "\t파일명 : ";
	cin >> temp;
	int iden = 0;
	for (int i = 0; i < fileNum; i++) {
		if (file[i].GetFileName() == temp) {
			iden++;
		}
	}
	if (iden > 0) {
		cout << "\n\t파일명 중복! 추가실패" << endl;
	}
	else {
		cout << "\t텍스트(1), 사진(2), 음원(3) 중 무엇입니까? : ";
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

//파일명으로 정렬
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

//파일 삭제
void FolderType::DeleteFile()
{
	string temp;
	cout << "\t삭제할 파일명 : ";
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
				remove(ch);  // txt파일 삭제
				file[i] = file[fileNum - 1];
				iden++;
			}
		}

		if (iden > 0) {
			fileNum--;
			cout << "\t삭제 완료!" << endl;
		}

		else {
			cout << "\t삭제 실패! 일치하는 이름이 없습니다." << endl;
		}

	}
	else
	{
		cout << "\t삭제 실패! 일치하는 이름이 없습니다." << endl;
	}
}

// 파일 쓰기
void FolderType::Execution1() {
	fArrayIden = false;
	fArrayString = "";
	fArrayEx = "";
	string temp;
	cout << "\t저장할 파일명 : ";
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
			cout << "\t실행 실패! 일치하는 이름이 없습니다." << endl;
		}
	}
	else
	{
		cout << "\t실행 실패! 일치하는 이름이 없습니다." << endl;
	}
}

//파일 읽기
void FolderType::Execution2() {
	fArrayIden = false;
	fArrayString = "";
	fArrayEx = "";

	string temp;
	cout << "\t읽을 파일명 : ";
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
			cout << "\t실행 실패! 일치하는 이름이 없습니다." << endl;
		}
	}
	else
	{
		cout << "\t실행 실패! 일치하는 이름이 없습니다." << endl;
	}
}

//파일명 변경
void FolderType::RenameFi() {

	fArrayIden = false;
	fArrayString = "";

	string temp;
	cout << "\t파일명 : ";
	cin >> temp;
	int iden = 0;
	string temp2;
	const char *ch;
	const char *ch2;
	if (fileNum != 0)
	{
		for (int i = 0; i < fileNum; i++) {
			if (file[i].GetFileName() == temp) {

				cout << "\t어떤 이름으로 변경하시겠습니까? : ";
				cin >> temp2;
				//파일 이름 변경
				file[i].SetFileName(temp2);

				fArrayString = temp2;
				fArrayIden = true;

				// 이름 변경
				if (file[i].GetFileEx() == ".txt") {
					temp2 = temp2 + ".txt";
					ch2 = temp2.c_str();
					temp = temp + ".txt";
					ch = temp.c_str();
					rename(ch, ch2);  // txt파일 이름변경
				}
				iden++;
				cout << "\t변경 완료" << endl;
			}
		}
		if (iden == 0) {
			cout << "\t변경 실패! 일치하는 이름이 없습니다." << endl;
		}
	}
	else
	{
		cout << "\t변경 실패! 일치하는 이름이 없습니다." << endl;
	}

}