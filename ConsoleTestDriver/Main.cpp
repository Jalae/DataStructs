#include "../console/console.h"

void main()
{
	nitrocorp::console::console_T * c = nitrocorp::console::console_T::GetConsole();
	c->SetConsoleSize(100,50);
	c->Write(L"test\n");
	c->Write(L"$CRED $$ text\n");
	c->Write(L"$AGREEN $$ text\n");
	c->Write(L"$9BLUE $$ text$F\n");
	c->Write(L"#CRED ## Background\n");
	c->Write(L"#AGREEN ## Background\n");
	c->Write(L"Just the same! \n$$$B##CYAN!\n");
	c->Write(L"#9BLUE ## Background\n");
	c->Write(L"\n#0\n$FNormal $# Text");
	c->Draw();
	std::system("pause");
		
}