#pragma once
/**
 * @file
 * @brief Working with files
 * @author Maximilian Panteleev
 * @copyright Managed under the Rinemest License (see LICENSE file).
 * @ingroup Kernel
 */


#undef RG_HERE_FILE_NAME
#define RG_HERE_FILE_NAME "def/files"
namespace Rinegine::Kernel {


	// #ifdef RG_SYS_WINDOWS
	// 	std::wstring utf8_to_utf16(const Rinegine::Kernel::String& str);
	// 	Rinegine::Kernel::String utf16_to_utf8(const std::wstring& wstr);
	// #endif
		// namespace Rinegine::Kernel {

	Rinegine::Kernel::String FileLoad(Rinegine::Kernel::String path);


	bool RG_IsFile(Rinegine::Kernel::String path);

	// namespace Rinegine::Kernel {
	Rinegine::Kernel::String GetTypePath(Rinegine::Kernel::String path);



#ifdef RG_SYS_WINDOWS



	struct FileFindType : public WIN32_FIND_DATA {
		Rinegine::Kernel::String get_name() {
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
		FileFindType* init(const Rinegine::Kernel::String& path);

		FileFindType* next();
		void close();

		~FileFinder();
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
		FileFindType* init(const Rinegine::Kernel::String& path);
		FileFindType* next();
		void close();
		~FileFinder();
	};


#endif
}