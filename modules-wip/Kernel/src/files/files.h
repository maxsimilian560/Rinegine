#pragma once
#undef RG_HERE_FILE_NAME
#define RG_HERE_FILE_NAME "def/files"
#define RG_ERROR_STRING "E6filenofound"
#define RG_ERROR_WSTRING L"E6filenofound"
namespace Rinegine::Kernel {

	
#ifdef RG_SYS_WINDOWS
	// std::wstring utf8_to_utf16(const Rinegine::Kernel::String& str) {
	// 	if (str.empty()) return {};
	// 	int size_needed = MultiByteToWideChar(CP_UTF8, 0, str.data(), (int)str.size(), nullptr, 0);
	// 	std::wstring result(size_needed, 0);
	// 	MultiByteToWideChar(CP_UTF8, 0, str.data(), (int)str.size(), &result[0], size_needed);
	// 	return result;
	// }
	// Rinegine::Kernel::String utf16_to_utf8(const std::wstring& wstr) {
	// 	if (wstr.empty()) return {};
	// 	int size_needed = WideCharToMultiByte(CP_UTF8, 0, wstr.data(), (int)wstr.size(), nullptr, 0, nullptr, nullptr);
	// 	Rinegine::Kernel::String result(size_needed, 0);
	// 	WideCharToMultiByte(CP_UTF8, 0, wstr.data(), (int)wstr.size(), &result[0], size_needed, nullptr, nullptr);
	// 	return result;
	// }
#endif
	
	Rinegine::Kernel::String FileLoad(Rinegine::Kernel::String path) {
	
		if (path[0] == '"') {
			path.erase(0, 1);
			path.erase(path.size() - 1, 1);
			rg_cout << std::endl << (path.c_str()) << std::endl;
		}
		Rinegine::Kernel::String text;

		std::ifstream file;

		file.open(path.c_str());

		if (!file.is_open()) return RG_ERROR_STRING;
		
		
		int ch;
		while ((ch = file.get()) != EOF) {
			text += (char)(ch);
		}
		file.close();
		return text;
	}
	
	
	

		


	bool RG_IsFile(Rinegine::Kernel::String path) {
		std::ifstream test(path.c_str());
		if (test.is_open()) { test.close(); return true; }
		else { test.close(); return false; }
	}

	// namespace Rinegine::Kernel {
	Rinegine::Kernel::String GetTypePath(Rinegine::Kernel::String path) {
		Rinegine::Kernel::String out;
		for (long i = (long)path.size() - 1; i >= 0; i--) {
			if (path[(size_t)i] == '.') {
				for (size_t j = (size_t)i + 1; j < path.size(); j++) {
					out += path[j];
				}
				return out;
			}
		}
		return out;
	}



#ifdef RG_SYS_WINDOWS

	//[TODO this is probably doesn't work]
	bool FileFinder::eof() { return _eof; }

	FileFindType* FileFinder::init(const rg_string& path) {
		if (!_init) {
			hFindFile = FindFirstFile(path.c_str(), &findFileData);
			if (hFindFile == INVALID_HANDLE_VALUE) {
				_eof = true;
				return nullptr;
			}
			_init = true;
		}
		else {
			RG_LOG_LOCK_ERROR("FileFinder is already initialized");
			if (!FindNextFile(hFindFile, &findFileData)) _eof = true;
		}
		return &findFileData;
	}

	FileFindType* FileFinder::next() {
		if (!_init) {
			RG_LOG_LOCK_ERROR("FileFinder is not initialized");
			return nullptr;
		}
		if (!FindNextFile(hFindFile, &findFileData)) {
			_eof = true;
			return nullptr;
		}
		return &findFileData;
	}

	void FileFinder::close() {
		if (_init) {
			FindClose(hFindFile);
			_init = false;
			_eof = false;
		}
	}

	FileFinder::~FileFinder() {
		close();
	}
	
	
	

	/* 
	bool FileFinder::eof() { return _eof; }

	FileFindType* FileFinder::init(const Rinegine::Kernel::String& path) {
		if (!_init) {
			hFindFile = FindFirstFileA(path.c_str(), &findFileData);
			if (hFindFile == INVALID_HANDLE_VALUE) {
				_eof = true;
				return nullptr;
			}
			_init = true;
		}
		else {
			RG_LOG_LOCK_ERROR("FileFinder is already initialized");
			if (!FindNextFileA(hFindFile, &findFileData)) _eof = true;
		}
		return &findFileData;
	}

	FileFindType* FileFinder::next() {
		if (!_init) {
			RG_LOG_LOCK_ERROR("FileFinder is not initialized");
			return nullptr;
		}
		if (!FindNextFileA(hFindFile, &findFileData)) {
			_eof = true;
			return nullptr;
		}
		return &findFileData;
	}

	void FileFinder::close() {
		if (_init) {
			FindClose(hFindFile);
			_init = false;
			_eof = false;
		}
	}

	FileFinder::~FileFinderA() {
		close();
	}
	
*/

#elif defined(RG_SYS_LINUX)

	
	
	
	
	
	
	
	bool FileFinder::eof() { return _eof; }

	FileFindType* FileFinder::init(const rg_string& path) {
		if (!_init) {
			dir = opendir(std::filesystem::path(path.c_str()).string().c_str());
			if (!dir) {
				_eof = true;
				return nullptr;
			}
			_init = true;
			ent = static_cast<FileFindType*>(readdir(dir));
			if (!ent) {
				_eof = true;
				return nullptr;
			}
			return ent;
		}
		else {
			RG_LOG_LOCK_ERROR("FileFinder is already initialized");
			ent = static_cast<FileFindType*>(readdir(dir));
			if (!ent) _eof = true;
			return ent;
		}
	}

	FileFindType* FileFinder::next() {
		if (!_init) {
			RG_LOG_LOCK_ERROR("FileFinder is not initialized");
			return nullptr;
		}
		ent = static_cast<FileFindType*>(readdir(dir));
		if (!ent) {
			_eof = true;
			return nullptr;
		}
		return ent;
	}

	void FileFinder::close() {
		if (_init) {
			closedir(dir);
			dir = nullptr;
			ent = nullptr;
			_init = false;
			_eof = false;
		}
	}

	FileFinder::~FileFinder() {
		close();
	}
	

	
	
	
	
	
	
	
	bool FileFinderA::eof() { return _eof; }

	FileFindType* FileFinderA::init(const Rinegine::Kernel::String& path) {
		if (!_init) {
			dir = opendir(path.c_str());
			if (!dir) {
				_eof = true;
				return nullptr;
			}
			_init = true;
			ent = static_cast<FileFindType*>(readdir(dir));
			if (!ent) {
				_eof = true;
				return nullptr;
			}
			return ent;
		}
		else {
			RG_LOG_LOCK_ERROR("FileFinderA is already initialized");
			ent = static_cast<FileFindType*>(readdir(dir));
			if (!ent) _eof = true;
			return ent;
		}
	}

	FileFindType* FileFinderA::next() {
		if (!_init) {
			RG_LOG_LOCK_ERROR("FileFinderA is not initialized");
			return nullptr;
		}
		ent = static_cast<FileFindType*>(readdir(dir));
		if (!ent) {
			_eof = true;
			return nullptr;
		}
		return ent;
	}

	void FileFinderA::close() {
		if (_init) {
			closedir(dir);
			dir = nullptr;
			ent = nullptr;
			_init = false;
			_eof = false;
		}
	}

	FileFinderA::~FileFinderA() {
		close();
	}
	

	
	
	
	
	
	
	
	bool FileFinderW::eof() { return _eof; }

	FileFindType* FileFinderW::init(const std::wstring& path) {
		if (!_init) {
			
			Rinegine::Kernel::String utf8_path = std::filesystem::path(path).string();
			dir = opendir(utf8_path.c_str());
			if (!dir) {
				_eof = true;
				return nullptr;
			}
			_init = true;
			ent = static_cast<FileFindType*>(readdir(dir));
			if (!ent) {
				_eof = true;
				return nullptr;
			}
			return ent;
		}
		else {
			RG_LOG_LOCK_ERROR("FileFinderW is already initialized");
			ent = static_cast<FileFindType*>(readdir(dir));
			if (!ent) _eof = true;
			return ent;
		}
	}

	FileFindType* FileFinderW::next() {
		if (!_init) {
			RG_LOG_LOCK_ERROR("FileFinderW is not initialized");
			return nullptr;
		}
		ent = static_cast<FileFindType*>(readdir(dir));
		if (!ent) {
			_eof = true;
			return nullptr;
		}
		return ent;
	}

	void FileFinderW::close() {
		if (_init) {
			closedir(dir);
			dir = nullptr;
			ent = nullptr;
			_init = false;
			_eof = false;
		}
	}

	FileFinderW::~FileFinderW() {
		close();
	}
	
#endif
	


	// namespace Rinegine::Kernel {
	// 	namespace File {
			/**
			* Reads the contents of a file character by character and applies a provided lambda function
			* to each character. This is useful for processing large files without loading the entire
			* file into memory.
			*
			* The lambda function should take a `char&` as its parameter, allowing you to modify the
			* character if necessary.
			*
			* The file is automatically closed after reading.
			*
			* Use lamda like [&file_out](char& file_char_in){file_out += file_char_in;}
			*
			* @template lamda
			* @param {Rinegine::Kernel::String} path - The path to the file to be read.
			* @param {function(char&): void} func - A lambda function that processes each character in the file. The character is passed by reference, so it can be modified.
			*
			* @example
			* 
			* 
			* Rinegine::Kernel::String result;
			* Read("example.txt", [&result](char& file_char_in) {
			*     result += file_char_in;
			* });
			*/
	template<typename lamda>
	void Read(Rinegine::Kernel::String path, lamda func) {
		std::ifstream file(path.c_str());
		char temp = (char)file.get();
		while (!file.eof()) {
			func(temp);
			temp = (char)file.get();
		}

		file.close();
	}

	void Write(Rinegine::Kernel::String path, const Rinegine::Kernel::String& in) {
		std::ofstream file(path.c_str());

		file << in;

		file.close();
	}

	
	
}