#include "Application.h"
#include "DoublyLinkedList.h"



// Program driver.
void Application::Run()
{
	//ó�� ���
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	cout << endl;
	cout << "    �����      ����      ��          �����     �����     ����� " << endl;
	cout << "    ��          ��      ��    ��          ��     ��    ��           ��     �� " << endl;
	cout << "    �����    ��      ��    ��          ��     ��    �����     ����� " << endl;
	cout << "    ��          ��      ��    ��          ��     ��    ��           ��     �� " << endl;
	cout << "    ��            ����      �����    �����     �����     ��     �� " << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	cout << "                �����      ����      ��           ����� " << endl;
	cout << "                ��              ��        ��           �� " << endl;
	cout << "                �����        ��        ��           ����� " << endl;
	cout << "                ��              ��        ��           �� " << endl;
	cout << "                ��            ����      �����     ����� " << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	cout << "  ��        ��     ���       ��      ��     ���       �����    ����� " << endl;
	cout << "  ���    ���    ��  ��      ���    ��    ��  ��     ��           �� " << endl;
	cout << "  �� ��  �� ��   �����     ��  ��  ��   �����    ��  ���     ����� " << endl;
	cout << "  ��  ���  ��  ��      ��    ��    ���  ��      ��   ��      ��   �� " << endl;
	cout << "  ��   ��   ��  ��      ��    ��      ��  ��      ��    �����    ����� " << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "\n\n\t\t\t�� Press Any Key ��" << endl;
	getchar();
	system("cls");


	int temp;
	while (1)
	{
		cout << endl;
		cout << "\t��������������������������������������  Choose ��������������������������������������" << endl;
		cout << "\t��   1. Folder Commands\t\t              ��" << endl;
		cout << "\t��   2. File Commands  \t\t              ��" << endl;
		cout << "\t��   0. Quit           \t\t              ��" << endl;
		cout << "\t����������������������������������������������������������������������������������������������" << endl;
		cout << "\t Choose a Command--> ";

		cin >> temp;
		if (temp == 0) {
			return;
		}
		else if (temp == 1) {
			m_Command = GetCommand();
			switch (m_Command)
			{
			case 1:		// ����������� �Է¹޾� ����Ʈ�� �߰�					
				NewFolder();
				break;
			case 2:		// ����Ʈ�� �ִ� ���� �˻��ϰ� ���������� ���
						// ��, �˻�� ������ �Ϻ����Խ� ���
				BinarySearchFolderByName();
				break;
			case 3:		// ���� ���� ����					
				DeleteFolder();
				break;
			case 4:		// ������ ã�� �������				
				DisplayFolder();
				break;
			case 5:		// ���� ������ �̵��ϱ�
				MoveSubFolder();
				break;
			case 6:		// ���� ������ �̵��ϱ�
				MoveBack();
				break;
			case 7:		// ���� ������ �̵��ϱ�
				MoveForward();
				break;
			case 8: // �ֱ� ��� ����
				OpenFolderList();
				break;
			case 9: //���� ���� �Ӽ�
				CurrentFolderProperty();
				break;
			case 10: //���� �������� �̸�����
				Renamefolder();
				break;
			case 11: //���� ����
				CopyFolder();
				break;
			case 12: //���� �ٿ��ֱ�
				PasteFolder();
				break;
			case 13: //���� �߶󳻱�
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
			case 1:		// ����������� �Է¹޾� ����Ʈ�� �߰�					
				NewFile();
				break;
			case 2:		// ����Ʈ�� �ִ� ���� �˻��ϰ� ���������� ���
						// ��, �˻�� ���ϸ� �Ϻ����Խ� ���
				BinarySearchFileByName();
				break;
			case 3:		// ���� ����					
				DeleteFile();
				break;
			case 4:		// ���� ����
				WriteToFile();
				break;
			case 5:		// ���� �б�
				ReadFromFile();
				break;
			case 6:		// ���� �̸� ����
				RenameFile();
				break;
			case 7:		// ���� �ֱ� 10�� ���
				OpenFileList();
				break;
			case 8:		// ���� ���
				DisplayFolder();
				break;
			case 9: //���� ����
				CopyFile();
				break;
			case 10: //���� �ٿ��ֱ�
				PasteFile();
				break;
			case 11: //���� �߶󳻱�
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
	cout << "\t������������������������������  Folder Commands ����������������������������" << endl;
	cout << "\t��   1 : New Folder\t\t              ��" << endl;
	cout << "\t��   2 : Search Folder by name  \t\t      ��" << endl;
	cout << "\t��   3 : Delete Folder          \t\t      ��" << endl;
	cout << "\t��   4 : Display Current Contents\t      ��" << endl;
	cout << "\t��   5 : Move to Sub-Folder \t\t      ��" << endl;
	cout << "\t��   6 : Move Back           \t\t      ��" << endl;
	cout << "\t��   7 : Move Forward           \t\t      ��" << endl;
	cout << "\t��   8 : Open Folder List      \t\t      ��" << endl;
	cout << "\t��   9 : Current folder properties\t      ��" << endl;
	cout << "\t��   10 : Rename a Folder  \t\t      ��" << endl;
	cout << "\t��   11 : Copy Folder           \t\t      ��" << endl;
	cout << "\t��   12 : Paste Folder         \t\t      ��" << endl;
	cout << "\t��   13 : Cut Folder           \t\t      ��" << endl;
	cout << "\t����������������������������������������������������������������������������������������������" << endl;
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
	cout << "\t��������������������������������  File Commands ������������������������������" << endl;
	cout << "\t��   1 : New File\t\t              ��" << endl;
	cout << "\t��   2 : Search File by name  \t\t      ��" << endl;
	cout << "\t��   3 : Delete File          \t\t      ��" << endl;
	cout << "\t��   4 : Write Data To File   \t\t      ��" << endl;
	cout << "\t��   5 : Read Data From File  \t\t      ��" << endl;
	cout << "\t��   6 : Rename a file        \t\t      ��" << endl;
	cout << "\t��   7 : Open File List       \t\t      ��" << endl;
	cout << "\t��   8 : Display Current Contents  \t      ��" << endl;
	cout << "\t��   9 : Copy File            \t\t      ��" << endl;
	cout << "\t��   10 : Paste File         \t\t      ��" << endl;
	cout << "\t��   11 : Cut File           \t\t      ��" << endl;
	cout << "\t����������������������������������������������������������������������������������������������" << endl;
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

// �л��� ������ ã�� �� �� ������ ����
void Application::DeleteFolder()
{
	m_curFolder->DeleteFolder();
	DisplayFolder();
}


//���� ������ �̵��ϴ� �Լ�
void Application::MoveSubFolder()
{
	iden = false; // false ��� MoveForward ���Ұ�
	FolderType data;
	data.SetFolderName(m_curFolder->GetFolderName());
	string temp;
	string temp2;
	int num = 0;
	// �� ��ġ �Է�
	cout << "\t�̵��� ���������� �Է� : ";
	cin >> temp;
	data.SetFolderPosition(temp);
	data.SetFolderName(temp);/////////////
	temp2 = m_curFolder->GetFolderPosition();  /////////////////////////
	//�� �� ������ ��
	if (m_curFolder->iExist(data)) {
		m_curFolder = &(m_curFolder->Exist(data));
		m_curFolder->SetFolderPosition(temp2 + '/' + temp); //
		cur++;
		Stack->subA(cur, *m_curFolder);
	}
	else {
		cout << "\t�� ������ �������� �ʽ��ϴ�." << endl;
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

	///  �ֱ� ��� ������ ����!   ///
	int id = 0;
	if (s_cur < 10) {
		for (int i = 0; i <= s_cur; i++) {
			//���� ��ġ�°��� �ִٸ� �����ϰ� �־���
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


//���� ������ �̵��ϴ� �Լ�
void Application::MoveBack()
{
	iden = true; // true��� MoveForward ��밡��
	if (cur == 0) {
		cout << "\t���� /root �Դϴ�!" << endl;
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

	///  �ֱ� ��� ������ ����!   ///
	int id = 0;
	if (s_cur < 10) {
		for (int i = 0; i <= s_cur; i++) {
			//���� ��ġ�°��� �ִٸ� �����ϰ� �־���
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

// ����Ʈ�� �ִ� ���� �˻� �� �������� ��� �����̶� ���ĵ� ��� ���
void Application::BinarySearchFolderByName()
{
	string s;
	cout << "\t �˻��� : ";
	cin >> s;
	cout << "\t\t      [�˻� ���]" << endl;
	cout << "\t---------------------------------------" << endl;
	m_RootFolder.BinarySearchFolderByName(s, m_RootFolder.GetSubFolderNum(), m_RootFolder);
	cout << "\t---------------------------------------" << endl;
}


//�ֱ� ��� ���� ���
void Application::OpenFolderList() {
	cout << "\t\t   [�ֱ� ��� ����]" << endl;
	cout << "\t---------------------------------------" << endl;
	for (int i = s_cur; i >= 0; i--) {
		cout << "\t" << s_Array[i] << endl;
	}
	cout << "\t---------------------------------------" << endl;
}

//���� ���� �Ӽ� ���
void Application::CurrentFolderProperty() {
	cout << "\t\t   [���� ���� �Ӽ�]" << endl;
	cout << "\t---------------------------------------" << endl;
	cout << "\t �̸� : " << m_curFolder->GetFolderName() << endl;
	cout << "\t ��� : " << m_curFolder->GetFolderPosition() << endl;
	cout << "\t �����ð� : " << m_curFolder->GetCreatTime() << endl;
	cout << "\t �������� �� : " << m_curFolder->GetSubFolderNum() << endl;
	cout << "\t---------------------------------------" << endl;
}

//���� ����
void Application::NewFile() {
	m_curFolder->AddFile();
	DisplayFolder();
}

// ���� �̸����� �˻�
void Application::BinarySearchFileByName() {
	string s;
	cout << "\t �˻��� : ";
	cin >> s;
	cout << "\t\t      [�˻� ���]" << endl;
	cout << "\t---------------------------------------" << endl;
	m_RootFolder.BinarySearchFileByName(s);
	cout << "\t---------------------------------------" << endl;
}

// ���� ����
void Application::DeleteFile() {
	m_curFolder->DeleteFile();
	DisplayFolder();
}

// ���� �̸� ����
void Application::Renamefolder() {
	m_curFolder->Rename();
	DisplayFolder();
}


// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadFromFile()
{
	m_curFolder->Execution2();


	//�ֱ� ��� ���� ����
	int id = 0;
	if (f_cur < 10 && m_curFolder->Execution1_FA1()) {
		for (int i = 0; i <= f_cur; i++) {
			//���� ��ġ�°��� �ִٸ� �����ϰ� �־���
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


	//�ֱ� ��� ���� ����
	int id = 0;
	if (f_cur < 10 && m_curFolder->Execution1_FA1()) {
		for (int i = 0; i <= f_cur; i++) {
			//���� ��ġ�°��� �ִٸ� �����ϰ� �־���
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

// ���� �̸� ����
void Application::RenameFile() {
	m_curFolder->RenameFi();


	//�ֱ� ��� ���� ����
	int id = 0;
	if (f_cur < 10 && m_curFolder->Execution1_FA1()) {
		for (int i = 0; i <= f_cur; i++) {
			//���� ��ġ�°��� �ִٸ� �����ϰ� �־���
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


//�ֱ� ��� ���� ���
void Application::OpenFileList() {
	//��ġ�� ����
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


	//���
	cout << "\t\t   [�ֱ� ��� ����]" << endl;
	cout << "\t---------------------------------------" << endl;
	for (int i = f_cur; i >= 0; i--) {
		cout << "\t" << f_Array[i] << endl;
	}
	cout << "\t---------------------------------------" << endl;
}

//���� ������ �̵�
void Application::MoveForward() {
	if (cur == tcur) {
		cout << "\t�̵��� �� �����ϴ�." << endl;
	}
	else if (iden == true) {
		cur++;
		m_curFolder = &(Stack->GoA(cur));
	}

	///  �ֱ� ��� ������ ����!   ///
	int id = 0;
	if (s_cur < 10) {
		for (int i = 0; i <= s_cur; i++) {
			//���� ��ġ�°��� �ִٸ� �����ϰ� �־���
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

//���� ����
void Application::CopyFolder() {
	string s;
	cout << "\t������ �������� �Է��ϼ��� : ";
	cin >> s;

	FolderType *temp;
	if (m_curFolder->CopySuccess(s)) {
		cout << "\t���� �Ϸ�!" << endl;
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
		cout << "\t���� ����" << endl;
	}
	DisplayFolder();
}

//���� �ٿ��ֱ�
void Application::PasteFolder() {
	if (CopyIden == false) {
		cout << "\t����� ������ �����ϴ�." << endl;
	}
	else {
		cout << "\t�ٿ��ֱ� ����!" << endl;
		m_curFolder->PasteF(Copy);
		m_curFolder->SetSubFolderNum(m_curFolder->GetSubFolderNum() + 1);
	}
	DisplayFolder();
}

//���� �߶󳻱�
void Application::CutFolder() {
	string s;

	cout << "\t�߶� �������� �Է��ϼ��� : ";
	cin >> s;

	if (m_curFolder->CopySuccess(s)) {
		cout << "\t�߶󳻱� �Ϸ�!" << endl;
		Copy = m_curFolder->CopyF(s);
		CopyIden = true;
		m_curFolder->CutDelete(s);
	}
	else {
		cout << "\t�߶󳻱� ����" << endl;
	}
	DisplayFolder();
}

//���� ����
void Application::CopyFile() {
	string s;
	cout << "\t������ ���ϸ��� �Է��ϼ��� : ";
	cin >> s;
	if (m_curFolder->CopySuccess2(s)) {
		cout << "\t���� �Ϸ�!" << endl;
		CopyFi = m_curFolder->CopyF2(s);
		CopyIdenFile = true;
	}
	else {
		cout << "\t���� ����" << endl;
	}
	DisplayFolder();
}

//���� �ٿ��ֱ�
void Application::PasteFile() {
	if (CopyIdenFile == false) {
		cout << "\t����� ������ �����ϴ�." << endl;
	}
	else {
		cout << "\t�ٿ��ֱ� ����!" << endl;
		m_curFolder->PasteF2(CopyFi);
	}
	DisplayFolder();
}

//���� �߶󳻱�
void Application::CutFile() {
	string s;
	cout << "\t�߶� ���ϸ��� �Է��ϼ��� : ";
	cin >> s;

	if (m_curFolder->CopySuccess2(s)) {
		cout << "\t�߶󳻱� �Ϸ�!" << endl;
		CopyFi = m_curFolder->CopyF2(s);
		CopyIdenFile = true;
		m_curFolder->CutDelete2(s);
	}
	else {
		cout << "\t�߶󳻱� ����" << endl;
	}
	DisplayFolder();
}
