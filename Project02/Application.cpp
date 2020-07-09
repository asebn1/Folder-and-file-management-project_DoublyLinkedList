#include "Application.h"
#include "DoublyLinkedList.h"



// Program driver.
void Application::Run()
{
	//처음 출력
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	cout << endl;
	cout << "    ■■■■      ■■■      ■          ■■■■     ■■■■     ■■■■ " << endl;
	cout << "    ■          ■      ■    ■          ■     ■    ■           ■     ■ " << endl;
	cout << "    ■■■■    ■      ■    ■          ■     ■    ■■■■     ■■■■ " << endl;
	cout << "    ■          ■      ■    ■          ■     ■    ■           ■     ■ " << endl;
	cout << "    ■            ■■■      ■■■■    ■■■■     ■■■■     ■     ■ " << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	cout << "                ■■■■      ■■■      ■           ■■■■ " << endl;
	cout << "                ■              ■        ■           ■ " << endl;
	cout << "                ■■■■        ■        ■           ■■■■ " << endl;
	cout << "                ■              ■        ■           ■ " << endl;
	cout << "                ■            ■■■      ■■■■     ■■■■ " << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	cout << "  ■        ■     ■■       ■      ■     ■■       ■■■■    ■■■■ " << endl;
	cout << "  ■■    ■■    ■  ■      ■■    ■    ■  ■     ■           ■ " << endl;
	cout << "  ■ ■  ■ ■   ■■■■     ■  ■  ■   ■■■■    ■  ■■     ■■■■ " << endl;
	cout << "  ■  ■■  ■  ■      ■    ■    ■■  ■      ■   ■      ■   ■ " << endl;
	cout << "  ■   ■   ■  ■      ■    ■      ■  ■      ■    ■■■■    ■■■■ " << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "\n\n\t\t\t□ Press Any Key □" << endl;
	getchar();
	system("cls");


	int temp;
	while (1)
	{
		cout << endl;
		cout << "\t┌──────────────────  Choose ──────────────────┐" << endl;
		cout << "\t│   1. Folder Commands\t\t              │" << endl;
		cout << "\t│   2. File Commands  \t\t              │" << endl;
		cout << "\t│   0. Quit           \t\t              │" << endl;
		cout << "\t└─────────────────────────────────────────────┘" << endl;
		cout << "\t Choose a Command--> ";

		cin >> temp;
		if (temp == 0) {
			return;
		}
		else if (temp == 1) {
			m_Command = GetCommand();
			switch (m_Command)
			{
			case 1:		// 사용자정보를 입력받아 리스트에 추가					
				NewFolder();
				break;
			case 2:		// 리스트에 있는 폴더 검색하고 세부정보를 출력
						// 단, 검색어가 폴더명에 일부포함시 출력
				BinarySearchFolderByName();
				break;
			case 3:		// 서브 폴더 삭제					
				DeleteFolder();
				break;
			case 4:		// 폴더를 찾아 정보출력				
				DisplayFolder();
				break;
			case 5:		// 서브 폴더로 이동하기
				MoveSubFolder();
				break;
			case 6:		// 상위 폴더로 이동하기
				MoveBack();
				break;
			case 7:		// 상위 폴더로 이동하기
				MoveForward();
				break;
			case 8: // 최근 열어본 폴더
				OpenFolderList();
				break;
			case 9: //현재 폴더 속성
				CurrentFolderProperty();
				break;
			case 10: //현재 폴더에서 이름변경
				Renamefolder();
				break;
			case 11: //폴더 복사
				CopyFolder();
				break;
			case 12: //폴더 붙여넣기
				PasteFolder();
				break;
			case 13: //폴더 잘라내기
				CutFolder();
				break;
			default:
				cout << "\tIllegal selection...\n";
				break;
			}
		}
		else if (temp == 2) {
			m_Command = GetCommand2();
			switch (m_Command)
			{
			case 1:		// 사용자정보를 입력받아 리스트에 추가					
				NewFile();
				break;
			case 2:		// 리스트에 있는 파일 검색하고 세부정보를 출력
						// 단, 검색어가 파일명에 일부포함시 출력
				BinarySearchFileByName();
				break;
			case 3:		// 파일 삭제					
				DeleteFile();
				break;
			case 4:		// 파일 쓰기
				WriteToFile();
				break;
			case 5:		// 파일 읽기
				ReadFromFile();
				break;
			case 6:		// 파일 이름 변경
				RenameFile();
				break;
			case 7:		// 파일 최근 10개 출력
				OpenFileList();
				break;
			case 8:		// 정보 출력
				DisplayFolder();
				break;
			case 9: //파일 복사
				CopyFile();
				break;
			case 10: //파일 붙여넣기
				PasteFile();
				break;
			case 11: //파일 잘라내기
				CutFile();
			default:
				cout << "\tIllegal selection...\n";
				break;
			}
		}
	}
}



// Display command on screen and get a input from keyboard.
int Application::GetCommand()
{

	int command;
	cout << endl << endl;
	cout << "\t┌──────────────  Folder Commands ─────────────┐" << endl;
	cout << "\t│   1 : New Folder\t\t              │" << endl;
	cout << "\t│   2 : Search Folder by name  \t\t      │" << endl;
	cout << "\t│   3 : Delete Folder          \t\t      │" << endl;
	cout << "\t│   4 : Display Current Contents\t      │" << endl;
	cout << "\t│   5 : Move to Sub-Folder \t\t      │" << endl;
	cout << "\t│   6 : Move Back           \t\t      │" << endl;
	cout << "\t│   7 : Move Forward           \t\t      │" << endl;
	cout << "\t│   8 : Open Folder List      \t\t      │" << endl;
	cout << "\t│   9 : Current folder properties\t      │" << endl;
	cout << "\t│   10 : Rename a Folder  \t\t      │" << endl;
	cout << "\t│   11 : Copy Folder           \t\t      │" << endl;
	cout << "\t│   12 : Paste Folder         \t\t      │" << endl;
	cout << "\t│   13 : Cut Folder           \t\t      │" << endl;
	cout << "\t└─────────────────────────────────────────────┘" << endl;
	cout << "\t Choose a Command--> ";

	cin >> command;
	cout << endl;

	return command;
}

// Display command on screen and get a input from keyboard.
int Application::GetCommand2()
{
	

	int command;
	cout << endl << endl;
	cout << "\t┌───────────────  File Commands ──────────────┐" << endl;
	cout << "\t│   1 : New File\t\t              │" << endl;
	cout << "\t│   2 : Search File by name  \t\t      │" << endl;
	cout << "\t│   3 : Delete File          \t\t      │" << endl;
	cout << "\t│   4 : Write Data To File   \t\t      │" << endl;
	cout << "\t│   5 : Read Data From File  \t\t      │" << endl;
	cout << "\t│   6 : Rename a file        \t\t      │" << endl;
	cout << "\t│   7 : Open File List       \t\t      │" << endl;
	cout << "\t│   8 : Display Current Contents  \t      │" << endl;
	cout << "\t│   9 : Copy File            \t\t      │" << endl;
	cout << "\t│   10 : Paste File         \t\t      │" << endl;
	cout << "\t│   11 : Cut File           \t\t      │" << endl;
	cout << "\t└─────────────────────────────────────────────┘" << endl;
	cout << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

// Add new record into list.
void Application::NewFolder()
{
	m_curFolder->AddFolder();
	DisplayFolder();
}


// Display all records in the list on screen.
void Application::DisplayFolder()
{
	m_curFolder->DisplayRecordOnScreen(*m_curFolder);
}

// 학생의 정보를 찾은 후 그 정보를 삭제
void Application::DeleteFolder()
{
	m_curFolder->DeleteFolder();
	DisplayFolder();
}


//하위 폴더로 이동하는 함수
void Application::MoveSubFolder()
{
	iden = false; // false 라면 MoveForward 사용불가
	FolderType data;
	data.SetFolderName(m_curFolder->GetFolderName());
	string temp;
	string temp2;
	int num = 0;
	// 들어갈 위치 입력
	cout << "\t이동할 서브폴더명 입력 : ";
	cin >> temp;
	data.SetFolderPosition(temp);
	data.SetFolderName(temp);/////////////
	temp2 = m_curFolder->GetFolderPosition();  /////////////////////////
	//들어갈 수 있으면 들어감
	if (m_curFolder->iExist(data)) {
		m_curFolder = &(m_curFolder->Exist(data));
		m_curFolder->SetFolderPosition(temp2 + '/' + temp); //
		cur++;
		Stack->subA(cur, *m_curFolder);
	}
	else {
		cout << "\t들어갈 폴더가 존재하지 않습니다." << endl;
		num++;
	}

	if (m_curFolder->GetSubFolderNum() == 0 && num == 0) {

		m_curFolder->NewfList(temp);
		if (m_curFolder->GetIden() == true) {
		}
		else {
			data.SetFolderPosition(temp2 + '/' + temp);
			m_curFolder->SetFolderPosition(data.GetFolderPosition());
		}
		m_curFolder->SetIden(true);

	}

	///  최근 열어본 폴더에 저장!   ///
	int id = 0;
	if (s_cur < 10) {
		for (int i = 0; i <= s_cur; i++) {
			//만약 겹치는것이 있다면 삭제하고 넣어줌
			if (s_Array[i] == m_curFolder->GetFolderPosition()) {
				for (int j = i; j <= s_cur - 1; j++) {
					s_Array[j] = s_Array[j + 1];
				}
				s_Array[s_cur] = m_curFolder->GetFolderPosition();
				id++;
				break;
			}
		}
		if (id == 0) {
			s_cur++;
			if (s_cur == 10) {
				for (int i = 0; i < 9; i++) {
					s_Array[i] = s_Array[i + 1];
				}
				s_cur--;
			}
			s_Array[s_cur] = m_curFolder->GetFolderPosition();
		}
	}

	tcur = cur;
	DisplayFolder();
}


//상위 폴더로 이동하는 함수
void Application::MoveBack()
{
	iden = true; // true라면 MoveForward 사용가능
	if (cur == 0) {
		cout << "\t현재 /root 입니다!" << endl;
	}
	else {
		if (cur == 1) {
			m_curFolder = Stack;
			cur--;
		}
		else {
			cur--;
			m_curFolder = &(Stack->GoA(cur));
		}
	}

	///  최근 열어본 폴더에 저장!   ///
	int id = 0;
	if (s_cur < 10) {
		for (int i = 0; i <= s_cur; i++) {
			//만약 겹치는것이 있다면 삭제하고 넣어줌
			if (s_Array[i] == m_curFolder->GetFolderPosition()) {
				for (int j = i; j <= s_cur - 1; j++) {
					s_Array[j] = s_Array[j + 1];
				}
				s_Array[s_cur] = m_curFolder->GetFolderPosition();
				id++;
				break;
			}
		}
		if (id == 0) {
			s_cur++;
			if (s_cur == 10) {
				for (int i = 0; i < 9; i++) {
					s_Array[i] = s_Array[i + 1];
				}
				s_cur--;
			}
			s_Array[s_cur] = m_curFolder->GetFolderPosition();
		}
	}


	DisplayFolder();
}

// 리스트에 있는 폴더 검색 후 세부정보 출력 조금이라도 겹쳐도 모두 출력
void Application::BinarySearchFolderByName()
{
	string s;
	cout << "\t 검색명 : ";
	cin >> s;
	cout << "\t\t      [검색 결과]" << endl;
	cout << "\t---------------------------------------" << endl;
	m_RootFolder.BinarySearchFolderByName(s, m_RootFolder.GetSubFolderNum(), m_RootFolder);
	cout << "\t---------------------------------------" << endl;
}


//최근 열어본 폴더 출력
void Application::OpenFolderList() {
	cout << "\t\t   [최근 열어본 폴더]" << endl;
	cout << "\t---------------------------------------" << endl;
	for (int i = s_cur; i >= 0; i--) {
		cout << "\t" << s_Array[i] << endl;
	}
	cout << "\t---------------------------------------" << endl;
}

//현재 폴더 속성 출력
void Application::CurrentFolderProperty() {
	cout << "\t\t   [현재 폴더 속성]" << endl;
	cout << "\t---------------------------------------" << endl;
	cout << "\t 이름 : " << m_curFolder->GetFolderName() << endl;
	cout << "\t 경로 : " << m_curFolder->GetFolderPosition() << endl;
	cout << "\t 생성시간 : " << m_curFolder->GetCreatTime() << endl;
	cout << "\t 하위폴더 수 : " << m_curFolder->GetSubFolderNum() << endl;
	cout << "\t---------------------------------------" << endl;
}

//파일 생성
void Application::NewFile() {
	m_curFolder->AddFile();
	DisplayFolder();
}

// 파일 이름으로 검색
void Application::BinarySearchFileByName() {
	string s;
	cout << "\t 검색명 : ";
	cin >> s;
	cout << "\t\t      [검색 결과]" << endl;
	cout << "\t---------------------------------------" << endl;
	m_RootFolder.BinarySearchFileByName(s);
	cout << "\t---------------------------------------" << endl;
}

// 파일 삭제
void Application::DeleteFile() {
	m_curFolder->DeleteFile();
	DisplayFolder();
}

// 폴더 이름 변경
void Application::Renamefolder() {
	m_curFolder->Rename();
	DisplayFolder();
}


// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadFromFile()
{
	m_curFolder->Execution2();


	//최근 열어본 파일 저장
	int id = 0;
	if (f_cur < 10 && m_curFolder->Execution1_FA1()) {
		for (int i = 0; i <= f_cur; i++) {
			//만약 겹치는것이 있다면 삭제하고 넣어줌
			if (f_Array[i] == (m_curFolder->GetFolderPosition() + "/" + m_curFolder->Execution1_FA2() + m_curFolder->GetEx())) {
				for (int j = i; j <= f_cur - 1; j++) {
					f_Array[j] = f_Array[j + 1];
				}
				f_Array[f_cur] = m_curFolder->GetFolderPosition() + "/" + m_curFolder->Execution1_FA2() + m_curFolder->GetEx();
				id++;
				break;
			}
		}
		if (id == 0) {
			f_cur++;
			if (f_cur == 10) {
				for (int i = 0; i < 9; i++) {
					f_Array[i] = f_Array[i + 1];
				}
				f_cur--;
			}
			f_Array[f_cur] = m_curFolder->GetFolderPosition() + "/" + m_curFolder->Execution1_FA2() + m_curFolder->GetEx();
		}
	}
	cout << endl;
	DisplayFolder();
	return 0;
}


// Open a file as a write mode, and write all data into the file,
int Application::WriteToFile()
{
	m_curFolder->Execution1();


	//최근 열어본 파일 저장
	int id = 0;
	if (f_cur < 10 && m_curFolder->Execution1_FA1()) {
		for (int i = 0; i <= f_cur; i++) {
			//만약 겹치는것이 있다면 삭제하고 넣어줌
			if (f_Array[i] == (m_curFolder->GetFolderPosition() + "/" + m_curFolder->Execution1_FA2() + m_curFolder->GetEx())) {
				for (int j = i; j <= f_cur - 1; j++) {
					f_Array[j] = f_Array[j + 1];
				}
				f_Array[f_cur] = m_curFolder->GetFolderPosition() + "/" + m_curFolder->Execution1_FA2() + m_curFolder->GetEx();
				id++;
				break;
			}
		}
		if (id == 0) {
			f_cur++;
			if (f_cur == 10) {
				for (int i = 0; i < 9; i++) {
					f_Array[i] = f_Array[i + 1];
				}
				f_cur--;
			}
			f_Array[f_cur] = m_curFolder->GetFolderPosition() + "/" + m_curFolder->Execution1_FA2() + m_curFolder->GetEx();
		}
	}

	DisplayFolder();

	return 0;
}

// 파일 이름 변경
void Application::RenameFile() {
	m_curFolder->RenameFi();


	//최근 열어본 파일 저장
	int id = 0;
	if (f_cur < 10 && m_curFolder->Execution1_FA1()) {
		for (int i = 0; i <= f_cur; i++) {
			//만약 겹치는것이 있다면 삭제하고 넣어줌
			if (f_Array[i] == m_curFolder->Execution1_FA2()) {
				for (int j = i; j <= f_cur - 1; j++) {
					f_Array[j] = f_Array[j + 1];
				}
				f_Array[f_cur] = m_curFolder->GetFolderPosition() + m_curFolder->Execution1_FA2() + m_curFolder->GetEx();
				id++;
				break;
			}
		}
		if (id == 0) {
			f_cur++;
			if (f_cur == 10) {
				for (int i = 0; i < 9; i++) {
					f_Array[i] = f_Array[i + 1];
				}
				f_cur--;
			}
			f_Array[f_cur] = m_curFolder->GetFolderPosition() + "/" + m_curFolder->Execution1_FA2() + m_curFolder->GetEx();
		}
	}
	DisplayFolder();
}


//최근 열어본 폴더 출력
void Application::OpenFileList() {
	//겹치면 제거
	string temp;
	for (int i = 0; i < f_cur; i++) {
		for (int j = i + 1; j <= f_cur; j++) {
			if (f_Array[i] == f_Array[j]) {
				temp = f_Array[j];
				f_Array[j] = f_Array[f_cur];
				f_Array[f_cur] = temp;
				f_cur--;
			}
		}
	}


	//출력
	cout << "\t\t   [최근 열어본 파일]" << endl;
	cout << "\t---------------------------------------" << endl;
	for (int i = f_cur; i >= 0; i--) {
		cout << "\t" << f_Array[i] << endl;
	}
	cout << "\t---------------------------------------" << endl;
}

//하위 폴더로 이동
void Application::MoveForward() {
	if (cur == tcur) {
		cout << "\t이동할 수 없습니다." << endl;
	}
	else if (iden == true) {
		cur++;
		m_curFolder = &(Stack->GoA(cur));
	}

	///  최근 열어본 폴더에 저장!   ///
	int id = 0;
	if (s_cur < 10) {
		for (int i = 0; i <= s_cur; i++) {
			//만약 겹치는것이 있다면 삭제하고 넣어줌
			if (s_Array[i] == m_curFolder->GetFolderPosition()) {
				for (int j = i; j <= s_cur - 1; j++) {
					s_Array[j] = s_Array[j + 1];
				}
				s_Array[s_cur] = m_curFolder->GetFolderPosition();
				id++;
				break;
			}
		}
		if (id == 0) {
			s_cur++;
			if (s_cur == 10) {
				for (int i = 0; i < 9; i++) {
					s_Array[i] = s_Array[i + 1];
				}
				s_cur--;
			}
			s_Array[s_cur] = m_curFolder->GetFolderPosition();
		}
	}


	DisplayFolder();
}

//폴더 복사
void Application::CopyFolder() {
	string s;
	cout << "\t복사할 폴더명을 입력하세요 : ";
	cin >> s;

	FolderType *temp;
	if (m_curFolder->CopySuccess(s)) {
		cout << "\t복사 완료!" << endl;
		temp = &m_curFolder->CopyF(s);
		Copy = *temp;
		/*
		while (1) {
			FolderType *te;
			if (temp->GetLen() == 0)
				break;
			else {
				Copy->next() = temp->next();
			}
		}*/
		CopyIden = true;
	}
	else {
		cout << "\t복사 실패" << endl;
	}
	DisplayFolder();
}

//폴더 붙여넣기
void Application::PasteFolder() {
	if (CopyIden == false) {
		cout << "\t복사된 폴더가 없습니다." << endl;
	}
	else {
		cout << "\t붙여넣기 성공!" << endl;
		m_curFolder->PasteF(Copy);
		m_curFolder->SetSubFolderNum(m_curFolder->GetSubFolderNum() + 1);
	}
	DisplayFolder();
}

//폴더 잘라내기
void Application::CutFolder() {
	string s;

	cout << "\t잘라낼 폴더명을 입력하세요 : ";
	cin >> s;

	if (m_curFolder->CopySuccess(s)) {
		cout << "\t잘라내기 완료!" << endl;
		Copy = m_curFolder->CopyF(s);
		CopyIden = true;
		m_curFolder->CutDelete(s);
	}
	else {
		cout << "\t잘라내기 실패" << endl;
	}
	DisplayFolder();
}

//파일 복사
void Application::CopyFile() {
	string s;
	cout << "\t복사할 파일명을 입력하세요 : ";
	cin >> s;
	if (m_curFolder->CopySuccess2(s)) {
		cout << "\t복사 완료!" << endl;
		CopyFi = m_curFolder->CopyF2(s);
		CopyIdenFile = true;
	}
	else {
		cout << "\t복사 실패" << endl;
	}
	DisplayFolder();
}

//파일 붙여넣기
void Application::PasteFile() {
	if (CopyIdenFile == false) {
		cout << "\t복사된 파일이 없습니다." << endl;
	}
	else {
		cout << "\t붙여넣기 성공!" << endl;
		m_curFolder->PasteF2(CopyFi);
	}
	DisplayFolder();
}

//파일 잘라내기
void Application::CutFile() {
	string s;
	cout << "\t잘라낼 파일명을 입력하세요 : ";
	cin >> s;

	if (m_curFolder->CopySuccess2(s)) {
		cout << "\t잘라내기 완료!" << endl;
		CopyFi = m_curFolder->CopyF2(s);
		CopyIdenFile = true;
		m_curFolder->CutDelete2(s);
	}
	else {
		cout << "\t잘라내기 실패" << endl;
	}
	DisplayFolder();
}
