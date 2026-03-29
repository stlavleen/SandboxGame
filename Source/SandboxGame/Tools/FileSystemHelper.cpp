// Fill out your copyright notice in the Description page of Project Settings.


#include "FileSystemHelper.h"
#include "DirectoryVisitor.h"

TArray<FString> UFileSystemHelper::GetFilesNames(const FString folderName) const
{
	auto& platformFile = FPlatformFileManager::Get().GetPlatformFile();
	auto gameDir = GetBuildGamePath();
	auto& path = gameDir.Append(folderName);
	
	if (!FPaths::DirectoryExists(path))
		return {};

	TArray<FString> out;
	DirectoryVisitor visitor(out);

	platformFile.IterateDirectoryRecursively(*path, visitor);
	
	return out;
}

FString UFileSystemHelper::GetBuildGamePath() const
{
	return FPaths::ConvertRelativePathToFull(FPaths::ProjectDir());
}

