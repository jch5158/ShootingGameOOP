//#define _CRT_SECURE_NO_WARNINGS
//
//#include "stdafx.h"
//
//#undef new
//
//
//
//CMemoryLick LickObject;
//
//MemmoryInfo* memmoryinfo[INFO_COUNT] = { nullptr };
//
//
//
//void* operator new(size_t size, const char* File, int Line)
//
//{
//
//	return MemoryAlloc(size, File, Line, false);
//
//}
//
//
//
//void* operator new[](size_t size, const char* File, int Line)
//
//{
//
//	return MemoryAlloc(size, File, Line, true);
//
//}
//
//
//
//void operator delete (void* p)
//
//{
//
//	MemoryDelete(p, true);
//
//}
//
//
//
//void operator delete[](void* p)
//
//{
//
//	MemoryDelete(p, false);
//
//}
//
//
//
//void* MemoryAlloc(size_t size, const char* File, int Line, bool ArrayCheck)
//
//{
//
//	void* p = malloc(size);
//
//
//
//	for (int i = 0; i < INFO_COUNT; i++)
//
//	{
//
//		if (memmoryinfo[i] != nullptr) continue;
//
//
//
//		memmoryinfo[i] = (MemmoryInfo*)malloc(sizeof(MemmoryInfo));
//
//		strcpy_s(memmoryinfo[i]->file_name, 128, File);
//
//		memmoryinfo[i]->Line = Line;
//
//		memmoryinfo[i]->p = p;
//
//		memmoryinfo[i]->size = size;
//
//		memmoryinfo[i]->arr = ArrayCheck;
//
//		break;
//
//	}
//
//
//
//	return p;
//
//}
//
//
//
//void MemoryDelete(void* p, bool ArrayCheck)
//
//{
//
//	for (int i = 0; i < INFO_COUNT; i++)
//
//	{
//
//		if (memmoryinfo[i] == nullptr) continue;
//
//
//
//		if (memmoryinfo[i]->p != p) continue;
//
//
//
//		if (memmoryinfo[i]->arr == ArrayCheck) // ¿¡·¯ Ãâ·ÂÈÄ return
//
//		{
//
//			char error[128];
//
//			sprintf(error, "ARRAY   [%x] [   %d] %s : %d \n", memmoryinfo[i]->p, memmoryinfo[i]->size, memmoryinfo[i]->file_name, memmoryinfo[i]->Line);
//
//			FILE* fp = fopen(LickObject.file_name, "at");
//
//			fwrite(error, strlen(error), 1, fp);
//
//			fclose(fp);
//
//			return;
//
//		}
//
//
//
//		free(memmoryinfo[i]);
//
//		free(p);
//
//		memmoryinfo[i] = nullptr;
//
//		return;
//
//	}
//
//
//
//	// NOALLOC Ãâ·Â ·ÎÁ÷ºÎ
//
//	char Error_msg[128];
//
//	sprintf(Error_msg, "NOALLOC [%x] \n", p);
//
//	FILE* fp = fopen(LickObject.file_name, "at");
//
//	fwrite(Error_msg, strlen(Error_msg), 1, fp);
//
//	fclose(fp);
//
//}
//
//
//
//
//
//CMemoryLick::CMemoryLick()
//
//{
//
//	tm timeInfo;
//
//	time_t now = time(NULL);
//
//	localtime_s(&timeInfo, &now);
//
//	sprintf(file_name, "Alloc_%d%d%d_%d%d%d.txt", timeInfo.tm_year + 1900, timeInfo.tm_mon + 1, timeInfo.tm_mday, timeInfo.tm_hour, timeInfo.tm_min, timeInfo.tm_sec);
//
//}
//
//
//
//CMemoryLick::~CMemoryLick()
//
//{
//
//	FILE* fp = fopen(LickObject.file_name, "at");
//
//
//
//	for (int i = 0; i < INFO_COUNT; i++)
//
//	{
//
//		if (memmoryinfo[i] == nullptr) continue;
//
//
//
//		char Error_msg[_MAX_PATH];
//
//		sprintf(Error_msg, "LEAK   [%x] [   %d] %s : %d \n", memmoryinfo[i]->p, memmoryinfo[i]->size, memmoryinfo[i]->file_name, memmoryinfo[i]->Line);
//
//		fwrite(Error_msg, strlen(Error_msg), 1, fp);
//
//	}
//
//	fclose(fp);
//
//}