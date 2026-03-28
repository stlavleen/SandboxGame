


#include "DirectoryVisitor.h"

bool DirectoryVisitor::Visit(const TCHAR* FilenameOrDirectory, bool bIsDirectory)
{
	if (!bIsDirectory) 
		paths.Add(FilenameOrDirectory);

	return true;
}
