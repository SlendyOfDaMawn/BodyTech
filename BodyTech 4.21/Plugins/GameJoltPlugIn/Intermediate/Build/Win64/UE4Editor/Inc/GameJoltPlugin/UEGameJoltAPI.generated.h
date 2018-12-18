// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
class UUEGameJoltAPI;
struct FScoreTableInfo;
struct FScoreInfo;
struct FTrophyInfo;
enum class EGameJoltAchievedTrophies : uint8;
struct FUserInfo;
#ifdef GAMEJOLTPLUGIN_UEGameJoltAPI_generated_h
#error "UEGameJoltAPI.generated.h already included, missing '#pragma once' in UEGameJoltAPI.h"
#endif
#define GAMEJOLTPLUGIN_UEGameJoltAPI_generated_h

#define Compiler_Plugins_GameJoltPlugIn_Source_GameJoltPlugin_Classes_UEGameJoltAPI_h_111_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FScoreTableInfo_Statics; \
	GAMEJOLTPLUGIN_API static class UScriptStruct* StaticStruct();


#define Compiler_Plugins_GameJoltPlugIn_Source_GameJoltPlugin_Classes_UEGameJoltAPI_h_89_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FScoreInfo_Statics; \
	GAMEJOLTPLUGIN_API static class UScriptStruct* StaticStruct();


#define Compiler_Plugins_GameJoltPlugIn_Source_GameJoltPlugin_Classes_UEGameJoltAPI_h_70_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FTrophyInfo_Statics; \
	GAMEJOLTPLUGIN_API static class UScriptStruct* StaticStruct();


#define Compiler_Plugins_GameJoltPlugIn_Source_GameJoltPlugin_Classes_UEGameJoltAPI_h_49_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FUserInfo_Statics; \
	GAMEJOLTPLUGIN_API static class UScriptStruct* StaticStruct();


#define Compiler_Plugins_GameJoltPlugIn_Source_GameJoltPlugin_Classes_UEGameJoltAPI_h_17_DELEGATE \
static inline void FOnFailed_DelegateWrapper(const FMulticastScriptDelegate& OnFailed) \
{ \
	OnFailed.ProcessMulticastDelegate<UObject>(NULL); \
}


#define Compiler_Plugins_GameJoltPlugIn_Source_GameJoltPlugin_Classes_UEGameJoltAPI_h_14_DELEGATE \
static inline void FOnGetResult_DelegateWrapper(const FMulticastScriptDelegate& OnGetResult) \
{ \
	OnGetResult.ProcessMulticastDelegate<UObject>(NULL); \
}


#define Compiler_Plugins_GameJoltPlugIn_Source_GameJoltPlugin_Classes_UEGameJoltAPI_h_128_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetObjectArray) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_PROPERTY(UStrProperty,Z_Param_key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<UUEGameJoltAPI*>*)Z_Param__Result=P_THIS->GetObjectArray(Z_Param_WorldContextObject,Z_Param_key); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetObjectKeys) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FString>*)Z_Param__Result=P_THIS->GetObjectKeys(Z_Param_WorldContextObject); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetInt) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetInt(Z_Param_key); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBool) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetBool(Z_Param_key); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetString) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetString(Z_Param_key); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetObject) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UUEGameJoltAPI**)Z_Param__Result=P_THIS->GetObject(Z_Param_key); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSendRequest) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_output); \
		P_GET_PROPERTY(UStrProperty,Z_Param_url); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->SendRequest(Z_Param_output,Z_Param_url); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetScoreboardTable) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FScoreTableInfo>*)Z_Param__Result=P_THIS->GetScoreboardTable(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFetchScoreboardTable) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->FetchScoreboardTable(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddScore) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_UserScore); \
		P_GET_PROPERTY(UIntProperty,Z_Param_UserScore_Sort); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Scoreboard_ID); \
		P_GET_PROPERTY(UStrProperty,Z_Param_GuestUser); \
		P_GET_PROPERTY(UStrProperty,Z_Param_extra_data); \
		P_GET_PROPERTY(UIntProperty,Z_Param_table_id); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->AddScore(Z_Param_UserScore,Z_Param_UserScore_Sort,Z_Param_Scoreboard_ID,Z_Param_GuestUser,Z_Param_extra_data,Z_Param_table_id); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetScoreboard) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FScoreInfo>*)Z_Param__Result=P_THIS->GetScoreboard(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFetchScoreboard) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_ScoreLimit); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Table_id); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->FetchScoreboard(Z_Param_ScoreLimit,Z_Param_Table_id); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetTrophies) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FTrophyInfo>*)Z_Param__Result=P_THIS->GetTrophies(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFetchTrophies) \
	{ \
		P_GET_ENUM(EGameJoltAchievedTrophies,Z_Param_AchievedType); \
		P_GET_TARRAY(int32,Z_Param_Trophies_ID); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->FetchTrophies(EGameJoltAchievedTrophies(Z_Param_AchievedType),Z_Param_Trophies_ID); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRewardTrophy) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Trophy_ID); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->RewardTrophy(Z_Param_Trophy_ID); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFetchArrayUsers) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FUserInfo>*)Z_Param__Result=P_THIS->FetchArrayUsers(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFetchUser) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->FetchUser(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLogInStatus) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->LogInStatus(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLogOffUser) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->LogOffUser(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execisUserAuthorize) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->isUserAuthorize(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAuthUser) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->AuthUser(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSendRequest12) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_output); \
		P_GET_PROPERTY(UStrProperty,Z_Param_url); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->SendRequest12(Z_Param_output,Z_Param_url); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetServerTime) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetServerTime(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCloseSession) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->CloseSession(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPingSession) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->PingSession(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOpenSession) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->OpenSession(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execInit) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_PrivateKey); \
		P_GET_PROPERTY(UIntProperty,Z_Param_GameID); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Init(Z_Param_PrivateKey,Z_Param_GameID); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetUserToken) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_f_UserToken); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->SetUserToken(Z_Param_f_UserToken); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetUserToken) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetUserToken(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetUserName) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_f_Username); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->SetUserName(Z_Param_f_Username); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetUsername) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetUsername(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetGamePrivateKey) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_f_game_PrivateKey); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->SetGamePrivateKey(Z_Param_f_game_PrivateKey); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetGamePrivateKey) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetGamePrivateKey(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetGameID) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_f_game_ID); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->SetGameID(Z_Param_f_game_ID); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetGameID) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetGameID(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCreate) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UUEGameJoltAPI**)Z_Param__Result=UUEGameJoltAPI::Create(Z_Param_WorldContextObject); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFromString) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_dataString); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->FromString(Z_Param_dataString); \
		P_NATIVE_END; \
	}


#define Compiler_Plugins_GameJoltPlugIn_Source_GameJoltPlugin_Classes_UEGameJoltAPI_h_128_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetObjectArray) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_PROPERTY(UStrProperty,Z_Param_key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<UUEGameJoltAPI*>*)Z_Param__Result=P_THIS->GetObjectArray(Z_Param_WorldContextObject,Z_Param_key); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetObjectKeys) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FString>*)Z_Param__Result=P_THIS->GetObjectKeys(Z_Param_WorldContextObject); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetInt) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetInt(Z_Param_key); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBool) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetBool(Z_Param_key); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetString) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetString(Z_Param_key); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetObject) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UUEGameJoltAPI**)Z_Param__Result=P_THIS->GetObject(Z_Param_key); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSendRequest) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_output); \
		P_GET_PROPERTY(UStrProperty,Z_Param_url); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->SendRequest(Z_Param_output,Z_Param_url); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetScoreboardTable) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FScoreTableInfo>*)Z_Param__Result=P_THIS->GetScoreboardTable(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFetchScoreboardTable) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->FetchScoreboardTable(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddScore) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_UserScore); \
		P_GET_PROPERTY(UIntProperty,Z_Param_UserScore_Sort); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Scoreboard_ID); \
		P_GET_PROPERTY(UStrProperty,Z_Param_GuestUser); \
		P_GET_PROPERTY(UStrProperty,Z_Param_extra_data); \
		P_GET_PROPERTY(UIntProperty,Z_Param_table_id); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->AddScore(Z_Param_UserScore,Z_Param_UserScore_Sort,Z_Param_Scoreboard_ID,Z_Param_GuestUser,Z_Param_extra_data,Z_Param_table_id); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetScoreboard) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FScoreInfo>*)Z_Param__Result=P_THIS->GetScoreboard(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFetchScoreboard) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_ScoreLimit); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Table_id); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->FetchScoreboard(Z_Param_ScoreLimit,Z_Param_Table_id); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetTrophies) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FTrophyInfo>*)Z_Param__Result=P_THIS->GetTrophies(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFetchTrophies) \
	{ \
		P_GET_ENUM(EGameJoltAchievedTrophies,Z_Param_AchievedType); \
		P_GET_TARRAY(int32,Z_Param_Trophies_ID); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->FetchTrophies(EGameJoltAchievedTrophies(Z_Param_AchievedType),Z_Param_Trophies_ID); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRewardTrophy) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Trophy_ID); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->RewardTrophy(Z_Param_Trophy_ID); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFetchArrayUsers) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FUserInfo>*)Z_Param__Result=P_THIS->FetchArrayUsers(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFetchUser) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->FetchUser(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLogInStatus) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->LogInStatus(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLogOffUser) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->LogOffUser(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execisUserAuthorize) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->isUserAuthorize(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAuthUser) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->AuthUser(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSendRequest12) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_output); \
		P_GET_PROPERTY(UStrProperty,Z_Param_url); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->SendRequest12(Z_Param_output,Z_Param_url); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetServerTime) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetServerTime(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCloseSession) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->CloseSession(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPingSession) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->PingSession(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOpenSession) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->OpenSession(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execInit) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_PrivateKey); \
		P_GET_PROPERTY(UIntProperty,Z_Param_GameID); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Init(Z_Param_PrivateKey,Z_Param_GameID); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetUserToken) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_f_UserToken); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->SetUserToken(Z_Param_f_UserToken); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetUserToken) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetUserToken(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetUserName) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_f_Username); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->SetUserName(Z_Param_f_Username); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetUsername) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetUsername(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetGamePrivateKey) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_f_game_PrivateKey); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->SetGamePrivateKey(Z_Param_f_game_PrivateKey); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetGamePrivateKey) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetGamePrivateKey(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetGameID) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_f_game_ID); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->SetGameID(Z_Param_f_game_ID); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetGameID) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetGameID(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCreate) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UUEGameJoltAPI**)Z_Param__Result=UUEGameJoltAPI::Create(Z_Param_WorldContextObject); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFromString) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_dataString); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->FromString(Z_Param_dataString); \
		P_NATIVE_END; \
	}


#define Compiler_Plugins_GameJoltPlugIn_Source_GameJoltPlugin_Classes_UEGameJoltAPI_h_128_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUUEGameJoltAPI(); \
	friend struct Z_Construct_UClass_UUEGameJoltAPI_Statics; \
public: \
	DECLARE_CLASS(UUEGameJoltAPI, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GameJoltPlugin"), NO_API) \
	DECLARE_SERIALIZER(UUEGameJoltAPI)


#define Compiler_Plugins_GameJoltPlugIn_Source_GameJoltPlugin_Classes_UEGameJoltAPI_h_128_INCLASS \
private: \
	static void StaticRegisterNativesUUEGameJoltAPI(); \
	friend struct Z_Construct_UClass_UUEGameJoltAPI_Statics; \
public: \
	DECLARE_CLASS(UUEGameJoltAPI, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GameJoltPlugin"), NO_API) \
	DECLARE_SERIALIZER(UUEGameJoltAPI)


#define Compiler_Plugins_GameJoltPlugIn_Source_GameJoltPlugin_Classes_UEGameJoltAPI_h_128_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UUEGameJoltAPI(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UUEGameJoltAPI) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UUEGameJoltAPI); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UUEGameJoltAPI); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UUEGameJoltAPI(UUEGameJoltAPI&&); \
	NO_API UUEGameJoltAPI(const UUEGameJoltAPI&); \
public:


#define Compiler_Plugins_GameJoltPlugIn_Source_GameJoltPlugin_Classes_UEGameJoltAPI_h_128_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UUEGameJoltAPI(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UUEGameJoltAPI(UUEGameJoltAPI&&); \
	NO_API UUEGameJoltAPI(const UUEGameJoltAPI&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UUEGameJoltAPI); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UUEGameJoltAPI); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UUEGameJoltAPI)


#define Compiler_Plugins_GameJoltPlugIn_Source_GameJoltPlugin_Classes_UEGameJoltAPI_h_128_PRIVATE_PROPERTY_OFFSET
#define Compiler_Plugins_GameJoltPlugIn_Source_GameJoltPlugin_Classes_UEGameJoltAPI_h_125_PROLOG
#define Compiler_Plugins_GameJoltPlugIn_Source_GameJoltPlugin_Classes_UEGameJoltAPI_h_128_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Compiler_Plugins_GameJoltPlugIn_Source_GameJoltPlugin_Classes_UEGameJoltAPI_h_128_PRIVATE_PROPERTY_OFFSET \
	Compiler_Plugins_GameJoltPlugIn_Source_GameJoltPlugin_Classes_UEGameJoltAPI_h_128_RPC_WRAPPERS \
	Compiler_Plugins_GameJoltPlugIn_Source_GameJoltPlugin_Classes_UEGameJoltAPI_h_128_INCLASS \
	Compiler_Plugins_GameJoltPlugIn_Source_GameJoltPlugin_Classes_UEGameJoltAPI_h_128_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Compiler_Plugins_GameJoltPlugIn_Source_GameJoltPlugin_Classes_UEGameJoltAPI_h_128_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Compiler_Plugins_GameJoltPlugIn_Source_GameJoltPlugin_Classes_UEGameJoltAPI_h_128_PRIVATE_PROPERTY_OFFSET \
	Compiler_Plugins_GameJoltPlugIn_Source_GameJoltPlugin_Classes_UEGameJoltAPI_h_128_RPC_WRAPPERS_NO_PURE_DECLS \
	Compiler_Plugins_GameJoltPlugIn_Source_GameJoltPlugin_Classes_UEGameJoltAPI_h_128_INCLASS_NO_PURE_DECLS \
	Compiler_Plugins_GameJoltPlugIn_Source_GameJoltPlugin_Classes_UEGameJoltAPI_h_128_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class UEGameJoltAPI."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Compiler_Plugins_GameJoltPlugIn_Source_GameJoltPlugin_Classes_UEGameJoltAPI_h


#define FOREACH_ENUM_EGAMEJOLTACHIEVEDTROPHIES(op) \
	op(EGameJoltAchievedTrophies::GJ_ACHIEVEDTROPHY_BLANK) \
	op(EGameJoltAchievedTrophies::GJ_ACHIEVEDTROPHY_USER) \
	op(EGameJoltAchievedTrophies::GJ_ACHIEVEDTROPHY_GAME) 
#define FOREACH_ENUM_EGAMEJOLTCOMPONENTENUM(op) \
	op(EGameJoltComponentEnum::GJ_USER_AUTH) \
	op(EGameJoltComponentEnum::GJ_USER_FETCH) \
	op(EGameJoltComponentEnum::GJ_SESSION_OPEN) \
	op(EGameJoltComponentEnum::GJ_SESSION_PING) \
	op(EGameJoltComponentEnum::GJ_SESSION_CLOSE) \
	op(EGameJoltComponentEnum::GJ_TROPHIES_FETCH) \
	op(EGameJoltComponentEnum::GJ_TROPHIES_ADD) \
	op(EGameJoltComponentEnum::GJ_SCORES_FETCH) \
	op(EGameJoltComponentEnum::GJ_SCORES_ADD) \
	op(EGameJoltComponentEnum::GJ_SCORES_TABLE) \
	op(EGameJoltComponentEnum::GJ_DATASTORE_FETCH) \
	op(EGameJoltComponentEnum::GJ_DATASTORE_SET) \
	op(EGameJoltComponentEnum::GJ_DATASTORE_UPDATE) \
	op(EGameJoltComponentEnum::GJ_DATASTORE_REMOVE) \
	op(EGameJoltComponentEnum::GJ_OTHER) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
