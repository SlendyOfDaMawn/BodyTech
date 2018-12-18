// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameJoltPlugin/Private/GameJoltPluginPCH.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameJoltPlugin_init() {}
	GAMEJOLTPLUGIN_API UFunction* Z_Construct_UDelegateFunction_GameJoltPlugin_OnGetResult__DelegateSignature();
	GAMEJOLTPLUGIN_API UFunction* Z_Construct_UDelegateFunction_GameJoltPlugin_OnFailed__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_GameJoltPlugin()
	{
		static UPackage* ReturnPackage = nullptr;
		if (!ReturnPackage)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_GameJoltPlugin_OnGetResult__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_GameJoltPlugin_OnFailed__DelegateSignature,
			};
			static const UE4CodeGen_Private::FPackageParams PackageParams = {
				"/Script/GameJoltPlugin",
				PKG_CompiledIn | 0x00000000,
				0x221E2F74,
				0x5F3CC612,
				SingletonFuncArray, ARRAY_COUNT(SingletonFuncArray),
				METADATA_PARAMS(nullptr, 0)
			};
			UE4CodeGen_Private::ConstructUPackage(ReturnPackage, PackageParams);
		}
		return ReturnPackage;
	}
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
