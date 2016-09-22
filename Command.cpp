#include "Command.h"

Command::Command()
{
	Free();
}

Command::~Command()
{
	Free();
}

void Command::Free()
{
	Data = nullptr;
	Path = nullptr;
}

void Command::Open(MyString Path)
{
	if (this->Path != nullptr)
	{
		std::cout << "Another file is in use. Close first!\n";
		return;
	}
	std::fstream File((char*)Path, std::ios::in);

	if (!File)
	{
		const MyString BegTag = "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">\n";
		File.open((char*)Path, std::ios::out);
		std::cout << "Created empty file!\n";
		File.write((char*)BegTag, BegTag.StrLen()*sizeof(char));
		this->Path = Path;
		return;
	}
	this->Path = Path;
	/*const size_t size = sizeof(char);
	char data[size];
	File.seekg(0, std::ios::beg);
	while (File)
	{
		File.read(data, size);
		std::cout<<data[size - 1];
	}*/

}
