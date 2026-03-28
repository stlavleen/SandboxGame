

#pragma once

#include "GenericPlatform/GenericPlatformFile.h"

/**
 * 
 */
class DirectoryVisitor : public IPlatformFile::FDirectoryVisitor
{
private:
	TArray<FString>& paths;
public:
	DirectoryVisitor(TArray<FString>& paths) : paths(paths)
	{
	}

	bool Visit(const TCHAR* FilenameOrDirectory, bool bIsDirectory) override;
};
