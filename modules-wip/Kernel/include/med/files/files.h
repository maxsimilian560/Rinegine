#pragma once
#undef RG_HERE_FILE_NAME
#define RG_HERE_FILE_NAME "def/files"
namespace Rinegine::Kernel {

	
#ifdef RG_SYS_WINDOWS
	std::wstring utf8_to_utf16(const Rinegine::Kernel::String& str);
	Rinegine::Kernel::String utf16_to_utf8(const std::wstring& wstr);
#endif
	// namespace Rinegine::Kernel {

		

	std::wstring WFileLoad(Rinegine::Kernel::String path);
	
	Rinegine::Kernel::String AFileLoad(Rinegine::Kernel::String path);
	std::wstring WFileLoad(std::wstring path);


	bool RG_IsFile(Rinegine::Kernel::String path);

	// namespace Rinegine::Kernel {
	Rinegine::Kernel::String GetTypePath(Rinegine::Kernel::String path);



#ifdef RG_SYS_WINDOWS
	
	
	
	struct FileFindType : public WIN32_FIND_DATA {
		rg_string get_name() {
			return this->cFileName;
		}
	};
	struct FileFindTypeA : public WIN32_FIND_DATAA {
		Rinegine::Kernel::String get_name() {
			return this->cFileName;
		}
	};
	struct FileFindTypeW : public WIN32_FIND_DATAW {
		std::wstring get_name() {
			return this->cFileName;
		}
	};
	class FileFinder {
		HANDLE hFindFile;
		FileFindType findFileData; 
		bool _init = false;
		bool _eof = false;

	public:
		bool eof();
		FileFindType* init(const rg_string& path);

		FileFindType* next();
		void close();

		~FileFinder();
	};
	class FileFinderA {
		HANDLE hFindFile;
		FileFindTypeA findFileData; 
		bool _init = false;
		bool _eof = false;

	public:
		bool eof();

		FileFindTypeA* init(const Rinegine::Kernel::String& path);
		FileFindTypeA* next();

		void close();

		~FileFinderA();
	};

	class FileFinderW {
		HANDLE hFindFile;
		FileFindTypeW findFileData; 
		bool _init = false;
		bool _eof = false;
		public:
		bool eof();
		FileFindTypeW* init(const std::wstring& path);
		FileFindTypeW* next();
		void close();
		~FileFinderW();
	};


	

#elif defined(RG_SYS_LINUX)
	struct FileFindType : public dirent {
		Rinegine::Kernel::String get_name() {
			return this->d_name;
		}
	};
	

	class FileFinder {
		DIR* dir;
		
		FileFindType* ent;
		bool _init;
		bool _eof;
	public:
		FileFinder() : dir(nullptr), _init(false), _eof(false) {}
		bool eof();
		FileFindType* init(const rg_string& path);
		FileFindType* next();
		void close();
		~FileFinder();
	};

	class FileFinderA {
		DIR* dir = nullptr;
		FileFindType* ent = nullptr;
		bool _init = false;
		bool _eof = false;

	public:
		bool eof();
		FileFindType* init(const Rinegine::Kernel::String& path);
		FileFindType* next();
		void close();
		~FileFinderA();
	};

	class FileFinderW {
		DIR* dir = nullptr;
		FileFindType* ent = nullptr;
		bool _init = false;
		bool _eof = false;
	public:
		bool eof();
		FileFindType* init(const std::wstring& path);
		FileFindType* next();
		void close();
		~FileFinderW();
};
#endif
}