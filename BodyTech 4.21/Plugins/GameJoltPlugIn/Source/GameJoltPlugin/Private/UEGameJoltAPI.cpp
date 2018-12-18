// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
/*
		By JvtheWanderer 
*/
#include "GameJoltPluginPCH.h"

/////
// UGameJoltAPI
////
/**
*  Constructor
*/
UUEGameJoltAPI::UUEGameJoltAPI(const class FObjectInitializer& PCIP)
: Super(PCIP)
{
	Reset();

	m_LoggedIn = false;
	bGuest = true;
	GJAPI_SERVER = "gamejolt.com";
	GJAPI_ROOT = "/api/game/";
	GJAPI_VERSION = "v1";
	Game_ID = 0;
	Game_PrivateKey = "";
	GameJoltComponentEnum = EGameJoltComponentEnum::GJ_USER_AUTH;
	
	
}
/**
*	Get the Game ID
*
*	@return Game_ID
*/
int32 UUEGameJoltAPI::GetGameID()
{
	return Game_ID;
}

// By FreezerNick
void UUEGameJoltAPI::Init(FString PrivateKey, int32 GameID)
{
	Game_ID = GameID;
	Game_PrivateKey = PrivateKey;
}

int32 UUEGameJoltAPI::GetServerTime()
{
	bool ret;
	FString GameIDString;
	FString output;
	GameIDString = FString::FromInt(Game_ID);
	ret = SendRequest12(output, TEXT("time/?format=json&game_id=") + GameIDString);
	int32 fasd;
	fasd = 20;
	return fasd;
}
// End of work by FreezerNick

/**
*	Set the Game ID
*
*	@param f_Game_ID
*
*	@return true
*/
bool UUEGameJoltAPI::SetGameID(int32 f_game_ID)
{
	Game_ID = f_game_ID;
		return true;
}


/**
*	Get the Game Private Key
*
*	
*
*	@return Game_ID
*/
FString UUEGameJoltAPI::GetGamePrivateKey()
{
	return Game_PrivateKey;
}

/**
*	Set the Game Private Key
*
*	@param F_game_PrivateKey	Games Private Key
*
*	@return true
*/
bool UUEGameJoltAPI::SetGamePrivateKey(FString f_game_PrivateKey)
{
	Game_PrivateKey = f_game_PrivateKey;
	return true;
}

/**
*	Get the Username
*
*
*
*	@return UserName
*/
FString UUEGameJoltAPI::GetUsername()
{
	return UserName;
}
/**
*	Set Username
*
*	@param f_Username	Username
*
*	@return true
*/
bool UUEGameJoltAPI::SetUserName(FString f_Username)
{
	UserName = f_Username;
	return true;
}

/**
*	Get User's Gamejolt Token
*
*	@return UserToken
*/
FString UUEGameJoltAPI::GetUserToken()
{
	return UserToken;
}

/**
*	Set User's Gamejolt Token
*
*	@param f_Username	UserToken
*
*	@return true
*/
bool UUEGameJoltAPI::SetUserToken(FString f_UserToken)
{
	UserToken = f_UserToken;
	return true;
}

/**
* Create a new instance of the UUEGameJoltAPI class, for use in Blueprint graphs.
*
* @param	WorldContextObject		The current context
*
* @return	A pointer to the newly created post data
*/
UUEGameJoltAPI* UUEGameJoltAPI::Create(UObject* WorldContextObject) {
	// Get the world object from the context
	UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject);

	// Construct the object and return it
	UUEGameJoltAPI* fieldData = NewObject<UUEGameJoltAPI>((UUEGameJoltAPI*)GetTransientPackage(), UUEGameJoltAPI::StaticClass());
	fieldData->contextObject = WorldContextObject;
	return fieldData;
}

/**
* Logs in the User using the given Username and Usertoken
*
* 
*
* @return	bool  True if it Successed, False if it failed
*/

bool UUEGameJoltAPI::AuthUser()
{
	bool ret = true;
	FString output;
	FString GameIDString;

	if (Game_ID <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("The Game ID must be set."));
		return false;

	}
	if (UserName == TEXT(""))
	{
		UE_LOG(LogTemp, Warning, TEXT("(The username must be set.)"));
		return false;
	}
	if (UserToken == TEXT(""))
	{
		UE_LOG(LogTemp, Warning, TEXT("(The user token must be set.)"));
		return false;
	}
	GameIDString = FString::FromInt(Game_ID);
	GameJoltComponentEnum = EGameJoltComponentEnum::GJ_USER_AUTH;
	ret = SendRequest(output, TEXT("/users/auth/?format=json&game_id=") + GameIDString + TEXT("&username=") + UserName + TEXT("&user_token=") + UserToken);

	if (!ret)
	{
		UE_LOG(LogTemp, Warning, TEXT("(Could not authenticate the user.)"));
		return false;
	}
	
	m_LoggedIn = true;
	bGuest = false;
	//
	return true;
}

/**
* Check if the user has logged in Succesfully
*
* @return	outAuthorize true if it Successed false if it fails
*/
bool UUEGameJoltAPI::isUserAuthorize()
{
	bool outAuthorize;
	UUEGameJoltAPI* responseField = NULL;
	responseField = GetObject("response");
	if (responseField == NULL)
	{
		UE_LOG(LogJson, Error, TEXT("responseField Return Null"));
		return false;
	}
	outAuthorize = responseField->GetBool("success");
	return outAuthorize;
}
/**
* Returns the Users info from Gamejolt
*
* @return	bool true if it Successed false if it failed
*/
bool UUEGameJoltAPI::FetchUser()
{
	bool ret = true;
	FString output;
	FString GameIDString;
	GameIDString = FString::FromInt(Game_ID);
	GameJoltComponentEnum = EGameJoltComponentEnum::GJ_USER_FETCH;
	ret = SendRequest(output, TEXT("/users/?format=json&game_id=") + GameIDString + TEXT("&username=") + UserName);
	if (!ret)
	{
		UE_LOG(LogTemp, Warning, TEXT("(Could not Fetch user.)"));
		return false;
	}
	return true;
}

/**
* LogoffUser Clears users Data
*/
void UUEGameJoltAPI::LogOffUser()
{
	m_LoggedIn = false;
	bGuest = true;
}

/** TODO: Add Fetch Function to LogInStatus()
*/
/*
Check if user is active
*/
void UUEGameJoltAPI::LogInStatus()
{

}

// By FreezerNick

bool UUEGameJoltAPI::OpenSession()
{
	bool ret;
	FString output;
	FString GameIDString;
	GameIDString = FString::FromInt(Game_ID);
	ret = SendRequest(output, TEXT("/sessions/open/?format=json&game_id=") + GameIDString + 
		TEXT("&username=") + UserName + TEXT("&user_token=") + UserToken);
	return true;
}

bool UUEGameJoltAPI::PingSession()
{
	bool ret;
	FString output;
	FString GameIDString;
	GameIDString = FString::FromInt(Game_ID);
	ret = SendRequest(output, TEXT("/sessions/ping/?format=json&status=active&game_id=") + GameIDString +
		TEXT("&username=") + UserName + TEXT("&user_token=") + UserToken);
	return true;
}

bool UUEGameJoltAPI::CloseSession()
{
	bool ret;
	FString output;
	FString GameIDString;
	GameIDString = FString::FromInt(Game_ID);
	ret = SendRequest(output, TEXT("/sessions/close/?format=json&game_id=") + GameIDString +
		TEXT("&username=") + UserName +
		TEXT("&user_token=") + UserToken);
	return true;
}

// End of work by FreezerNick

/***
* Get the array of users for Gamejolt and put it in a array of FUserInfo
*
*
*	@return returnUserInfo A struct array with users info
*/
TArray<FUserInfo>  UUEGameJoltAPI::FetchArrayUsers()
{
	TArray<UUEGameJoltAPI*> returnArray = GetObject("response")->GetObjectArray(GetObject("response"), "users");

	TArray<FUserInfo> returnUserInfo;
	
	FUserInfo tempUser;

	for (int i = 0; i< returnArray.Num(); i++)
	{

		tempUser.S_User_ID = returnArray[i]->GetInt("id");
		tempUser.User_Name = returnArray[i]->GetString("username");
		tempUser.User_Type = returnArray[i]->GetString("type");
		tempUser.User_AvatarURL = returnArray[i]->GetString("avatar_url");
		tempUser.Signed_up = returnArray[i]->GetString("signed_up");
		tempUser.Last_Logged_in = returnArray[i]->GetString("last_logged_in");
		tempUser.status = returnArray[i]->GetString("status");
		returnUserInfo.Add(tempUser);
		//UE_LOG(LogTemp, Error, TEXT("'%d'"), returnArray.Num());
	}
	
	return returnUserInfo;
}

/***
* Give the User Trophies
* Give the User Trophies
*
*
*	@return returnUserInfo A struct array with users info
*/
bool UUEGameJoltAPI::RewardTrophy(int32 Trophy_ID)
{

	bool ret = true;
	FString output;
	FString GameIDString;
	FString TrophyIDString;
	GameIDString = FString::FromInt(Game_ID);
	if (bGuest)
	{
		UE_LOG(LogTemp, Warning, TEXT("(User is not logged on)"));
		return false;
	}
	TrophyIDString = FString::FromInt(Trophy_ID);
	GameJoltComponentEnum = EGameJoltComponentEnum::GJ_TROPHIES_ADD;
	ret = SendRequest(output, TEXT("/trophies/add-achieved/?format=json&game_id=") + GameIDString +
							TEXT("&username=") + UserName + 
							TEXT("&user_token=") + UserToken +
							TEXT("&trophy_id=") + TrophyIDString);


	return true;
}

/* Get the List of Trophies from the GameJolt Server
*
*	@param	AchievedType	An Enum of EGameJoltAchievedTrophies that send what type to bring back
*	@param	Tropies_ID		An Array of int32 that search for specific trophies. If array is empty it return all trophies.
*	
*/
void UUEGameJoltAPI::FetchTrophies(EGameJoltAchievedTrophies AchievedType, TArray<int32> Trophies_ID)
{
	TArray<FTrophyInfo> returnTrophies;
	bool ret = true;
	FString output;
	FString GameIDString;
	FString TrophyIDString;
	FString AchievedString;

	if (!m_LoggedIn)
	{
		UE_LOG(LogTemp, Error, TEXT("User has not logged in!"));
		return;
	}
	
	GameJoltComponentEnum = EGameJoltComponentEnum::GJ_TROPHIES_FETCH;
	if(AchievedType == EGameJoltAchievedTrophies::GJ_ACHIEVEDTROPHY_GAME){

		AchievedString ="false";
	}
	else
	{
		AchievedString = "true";
	}

	GameIDString = FString::FromInt(Game_ID);
	for (int32 i = 0; i < Trophies_ID.Num(); i++){
		UE_LOG(LogTemp, Error, TEXT("HelloAll"));
		TrophyIDString += FString::FromInt(Trophies_ID[i]);
		//UE_LOG(LogTemp, Error, TEXT("%s"), TrophyIDString);
		if (i != Trophies_ID.Num()-1)
		{
			TrophyIDString += TEXT(",");
		}
	}
	if (AchievedType == EGameJoltAchievedTrophies::GJ_ACHIEVEDTROPHY_BLANK)//if We Want to get all trophies
	{
		ret = SendRequest(output, TEXT("/trophies/?format=json&game_id=") + GameIDString +
			TEXT("&username=") + UserName +
			TEXT("&user_token=") + UserToken +
			(Trophies_ID.Num() > 0 ? "&trophy_id=" : "") + TrophyIDString);
	}
	else //if We Want to get what trophies the User achieved have Not Achieved
	{
		ret = SendRequest(output, TEXT("/trophies/?format=json&game_id=") + GameIDString +
			TEXT("&username=") + UserName +
			TEXT("&user_token=") + UserToken +
			TEXT("&achieved=" ) + AchievedString +
			(Trophies_ID.Num() > 0 ? "&trophy_id=" : "") + TrophyIDString);
	}

	if (!ret)
	{
		UE_LOG(LogTemp, Warning, TEXT("(Could not Fetch Trophies.)"));
		return;
	}

	return;
}

/* Get the list of trophies from the Gamejolt server
*
*	@return	returnTrophy	A array of Struct FTrophyInfo
*
*/
TArray<FTrophyInfo> UUEGameJoltAPI::GetTrophies()
{
	TArray<FTrophyInfo> returnTrophy;
	TArray<UUEGameJoltAPI*> returnArray = GetObject("response")->GetObjectArray(GetObject("response"), "trophies");
	FTrophyInfo tempTrophies;
	UE_LOG(LogTemp, Error, TEXT("'%d'"), returnArray.Num());
	for (int i = 0; i< returnArray.Num(); i++)
	{
		
		tempTrophies.Trophy_ID = returnArray[i]->GetInt("id");
		tempTrophies.Name = returnArray[i]->GetString("title");
		tempTrophies.Description = returnArray[i]->GetString("description");
		tempTrophies.Difficulty = returnArray[i]->GetString("difficulty");
		tempTrophies.image_url = returnArray[i]->GetString("image_url");
		tempTrophies.achieved = returnArray[i]->GetString("achieved");

		returnTrophy.Add(tempTrophies);
		//UE_LOG(LogTemp, Error, TEXT("'%d'"), returnArray.Num());
	}

		return returnTrophy;
}

/* Fetch Returns a list of scores either for a user or globally for a game.
*
*	@return	returnTrophy	A array of Struct FTrophyInfo
*
*/
bool UUEGameJoltAPI::FetchScoreboard(int32 ScoreLimit, int32 Table_id)
{
	TArray<FTrophyInfo> returnTrophies;
	bool ret = true;
	FString output;
	FString GameIDString;
	FString TableIDString;
	FString ScoreLimitString;

	GameIDString = FString::FromInt(Game_ID);
	TableIDString = FString::FromInt(Table_id);
	ScoreLimitString = FString::FromInt(ScoreLimit);
	GameJoltComponentEnum = EGameJoltComponentEnum::GJ_SCORES_FETCH;

	ret = SendRequest(output, TEXT("/scores/?format=json&game_id=") + GameIDString +
		(!UserName.IsEmpty() || bGuest ? "&username=" : "") + UserName +
		(m_LoggedIn ? "&user_token=" : "") + UserToken +
		(ScoreLimit > 0 ? "&limit=" : "") + (ScoreLimit > 0 ? ScoreLimitString : "") +
		(Table_id > 0 ? "&table_id=" : "") + (Table_id > 0 ? TableIDString : ""));


	if (!ret)
	{
		UE_LOG(LogTemp, Warning, TEXT("(Could not Fetch Scoreboard.)"));
		return false;
	}

	return true;
}

/* Returns a list of scores either for a user or globally for a game.
*
*	@return	returnTrophy	A array of Struct FScoreInfo
*
*/
TArray<FScoreInfo> UUEGameJoltAPI::GetScoreboard()
{
	TArray<FScoreInfo> returnScoreInfo;
	TArray<UUEGameJoltAPI*> returnArray = GetObject("response")->GetObjectArray(GetObject("response"), "scores");
	FScoreInfo tempScore;
	UE_LOG(LogTemp, Error, TEXT("'%d'"), returnArray.Num());
	for (int i = 0; i < returnArray.Num(); i++)
	{
		tempScore.ScoreSort = returnArray[i]->GetInt("sort");
		tempScore.ScoreString = returnArray[i]->GetString("score");
		tempScore.extra_data = returnArray[i]->GetString("extra_data");
		tempScore.UserName = returnArray[i]->GetString("user");
		tempScore.User_Id = returnArray[i]->GetInt("user_id");
		tempScore.guestUser = returnArray[i]->GetString("guest");
		tempScore.stored = returnArray[i]->GetString("stored");
		//UE_LOG(LogTemp, Error, TEXT("'%d'"), returnArray.Num());

		returnScoreInfo.Add(tempScore);
	}
	//UE_LOG(LogTemp, Error, TEXT("NOPE!"));

	return returnScoreInfo;
}

/**TODO: Add More Functionality for Guest user on AddScore
*/
/* Adds a score for a user or guest.
*
*	@param	UserScore		A String Value associated with the score. Example: "234 Jumps".
*	@param	UserScore_Sort	A Int sorting value associated with the score. All sorting will work off of this number. Example: "234".
*	@param	GuestUser		The guest's name. Leave blank if you're storing for a user.
*	@param	extra_data		If there's any extra data you would like to store (as a string), you can use this variable. Note that this is only retrievable through the API. It never shows on the actual site.
*	@param	table_id		The id of the high score table that you want to submit to. If left blank the score will be submitted to the primary high score table.
*	
*	@return	bool			True if it  Succeed False if it Fails
*
*/
bool UUEGameJoltAPI::AddScore(FString UserScore, int32 UserScore_Sort, int32 Scoreboard_ID, FString GuestUser, FString extra_data, int32 table_id)
{
	bool ret = true;
	FString output;
	FString GameIDString;
	FString TableIDString;

	GameIDString = FString::FromInt(Game_ID);
	TableIDString = FString::FromInt(table_id);
	GameJoltComponentEnum = EGameJoltComponentEnum::GJ_SCORES_ADD;
	ret = SendRequest(output, TEXT("/scores/add/?format=json&game_id=") + GameIDString +
		TEXT("&score=") + UserScore +
		TEXT("&sort=") + FString::FromInt(UserScore_Sort) +
		(!UserName.IsEmpty() || m_LoggedIn ? "&username=" : "") + UserName +
		(!bGuest ? "&user_token=" : "") + UserToken +
		(bGuest ? "&guest=" : "") + GuestUser +
		(!extra_data.IsEmpty() ? "&extra_data=" : "") + extra_data +
		(table_id > 0 ? "&table_id=" : "") + (table_id > 0 ? TableIDString : ""));
	if (!ret)
	{
		UE_LOG(LogTemp, Warning, TEXT("(Failed to Add User's Score)"));
		return false;
	}

	return true;
}

/* Returns a list of high score tables for a game.
*
*	@return	bool	True if it Succeed False if it fails
*
*/
bool UUEGameJoltAPI::FetchScoreboardTable()
{
	bool ret = true;
	FString output;
	FString GameIDString;

	GameIDString = FString::FromInt(Game_ID);
	GameJoltComponentEnum = EGameJoltComponentEnum::GJ_SCORES_TABLE;

	ret = SendRequest(output, TEXT("/scores/tables/?format=json&game_id=") + GameIDString);

	if (!ret)
	{
		UE_LOG(LogTemp, Warning, TEXT("(Could not Fetch Scoreboard Table.)"));
		return false;
	}

	return true;
}


/* Geta list of high score tables for a game and put them in a Array of FScoreTableInfo.
*
*	@return	returnTableinfo	A array of Struct FScoreTableInfo
*
*/
TArray<FScoreTableInfo> UUEGameJoltAPI::GetScoreboardTable()
{
	TArray<FScoreTableInfo> returnTableinfo;
	FScoreTableInfo tempTable;
	TArray<UUEGameJoltAPI*> returnArray = GetObject("response")->GetObjectArray(GetObject("response"), "tables");
	for (int i = 0; i < returnArray.Num(); i++)
	{
		tempTable.Id = returnArray[i]->GetInt("id");
		tempTable.Name = returnArray[i]->GetString("name");
		tempTable.Description = returnArray[i]->GetString("description");
		tempTable.Primary = returnArray[i]->GetString("primary");
		returnTableinfo.Add(tempTable);
	}

	return returnTableinfo;
}

/**
*Gets the post data object from the post data with the given key
*
* @param	WorldContextObject		Array of strings
* @param	key						Key
*
* @return	The object itself
*/

UUEGameJoltAPI* UUEGameJoltAPI::GetObject(const FString& key)
{
	UUEGameJoltAPI* fieldObj = NULL;
	// Try to get the object field from the data
	const TSharedPtr<FJsonObject> *outPtr;
	if (!Data->TryGetObjectField(*key, outPtr)) {
		// Throw an error and return NULL when the key could not be found
		UE_LOG(LogJson, Error, TEXT("Entry '%s' not found in the field data!"), *key);
		return NULL;
	}

	// Create a new field data object and assign the data
	fieldObj = UUEGameJoltAPI::Create(contextObject);
	fieldObj->Data = *outPtr;

	// Return the newly created object
	return fieldObj;
}

FString UUEGameJoltAPI::GetString(const FString& key) const
{
	FString outString;
	if (!Data->TryGetStringField(*key, outString))
	{
		UE_LOG(LogTemp, Error, TEXT("Entry '%s' not found in the field data!"), *key);
		return "";
	}

	return outString;
}
bool UUEGameJoltAPI::GetBool(const FString& key)const
{
	bool outBool;
	if (!Data->TryGetBoolField(*key,outBool))
	{
		UE_LOG(LogTemp, Error, TEXT("Entry '%s' not found in the field data!"), *key);
		return false;
	}
	return outBool;
}
int32 UUEGameJoltAPI::GetInt(const FString& key) const
{
	int32 outInt;
	if (!Data->TryGetNumberField(*key, outInt))
	{
		UE_LOG(LogTemp, Error, TEXT("Entry '%s' not found in the field data!"), *key);
		return 0;
	}
	return outInt;
}

/**
* Gets a string array from the post data with the given key
*
* @param	key						Key
*
* @return	The requested array of strings
*/
TArray<FString> UUEGameJoltAPI::GetObjectKeys(UObject* WorldContextObject)
{
	TArray<FString> stringArray;
	
	for (auto currJsonValue = Data->Values.CreateConstIterator(); currJsonValue; ++currJsonValue) {
		stringArray.Add((*currJsonValue).Key);
	}

	// Return the array, will be empty if unsuccessful
	return stringArray;
}

TArray<UUEGameJoltAPI*> UUEGameJoltAPI::GetObjectArray(UObject* WorldContextObject, const FString& key)
{
	TArray<UUEGameJoltAPI*> objectArray;

	// Try to fetch and assign the array to the array pointer
	const TArray<TSharedPtr<FJsonValue>> *arrayPtr;
	if (Data->TryGetArrayField(*key, arrayPtr)) {
		// Iterate through the input array and create new post data objects for every entry and add them to the objectArray
		for (int32 i = 0; i < arrayPtr->Num(); i++) {
			UUEGameJoltAPI* pageData = Create(WorldContextObject);
			pageData->Data = (*arrayPtr)[i]->AsObject();
			objectArray.Add(pageData);
		}
	}
	else {
		// Throw an error, since the value with the supplied key could not be found
		UE_LOG(LogTemp, Error, TEXT("Array entry '%s' not found in the field data!"), *key);
	}

	// Return the array, will be empty if unsuccessful

	return objectArray;
}

bool UUEGameJoltAPI::SendRequest12(const FString& output, FString url)
{

	if (Game_PrivateKey == TEXT(""))
	{
		UE_LOG(LogTemp, Error, TEXT("(You must put in your game's private key before you can use any of the API functions.)"));
		return false;
	}

	FString outStr;
	TSharedRef<TJsonWriter<TCHAR>> JsonWriter = TJsonWriterFactory<TCHAR>::Create(&outStr);
	//Start writing the response
	WriteObject(JsonWriter, "", new FJsonValueObject(Data));
	JsonWriter->Close();
	//Create URL First

	url = TEXT("http://") + GJAPI_SERVER + GJAPI_ROOT + TEXT("v1.2") + url;
	//UE_LOG(LogTemp, Error, TEXT("%s"), *url);
	FString signature(FMD5::HashAnsiString(*(url + Game_PrivateKey))); //+ GJAPI_SERVER + url + Game_PrivateKey(TEXT("http://") + GJAPI_SERVER +
	url += TEXT("&signature=") + signature;
	UE_LOG(LogTemp, Error, TEXT("%s"), *url);


	TSharedRef< IHttpRequest > HttpRequest = FHttpModule::Get().CreateRequest();
	HttpRequest->SetVerb("POST");
	HttpRequest->SetURL(CreateURL(url));
	HttpRequest->SetHeader("Content-Type", "application/json");
	HttpRequest->SetContentAsString(output);

	HttpRequest->OnProcessRequestComplete().BindUObject(this, &UUEGameJoltAPI::OnReady);
	HttpRequest->ProcessRequest();

	return true;

}

bool UUEGameJoltAPI::SendRequest(const FString& output, FString url)
{

	if (Game_PrivateKey == TEXT(""))
	{
		UE_LOG(LogTemp, Error, TEXT("(You must put in your game's private key before you can use any of the API functions.)"));
		return false;
	}

	FString outStr;
	TSharedRef<TJsonWriter<TCHAR>> JsonWriter = TJsonWriterFactory<TCHAR>::Create(&outStr);
	//Start writing the response
	WriteObject(JsonWriter, "", new FJsonValueObject(Data));
	JsonWriter->Close();
	//Create URL First

	url = TEXT("http://") + GJAPI_SERVER + GJAPI_ROOT + GJAPI_VERSION + url;
	//UE_LOG(LogTemp, Error, TEXT("%s"), *url);
	FString signature(FMD5::HashAnsiString(*(url + Game_PrivateKey))); //+ GJAPI_SERVER + url + Game_PrivateKey(TEXT("http://") + GJAPI_SERVER +
	url += TEXT("&signature=") + signature;
	UE_LOG(LogTemp, Error, TEXT("%s"), *url);


	TSharedRef< IHttpRequest > HttpRequest = FHttpModule::Get().CreateRequest();
	HttpRequest->SetVerb("POST");
	HttpRequest->SetURL(CreateURL(url));
	HttpRequest->SetHeader("Content-Type", "application/json");
	HttpRequest->SetContentAsString(output);

	HttpRequest->OnProcessRequestComplete().BindUObject(this, &UUEGameJoltAPI::OnReady);
	HttpRequest->ProcessRequest();
	
	return true;
	
}

/**
* This function will write the supplied key and value to the JsonWriter
*
* @param	writer			The JsonWriter to use
* @param	key				Object key
* @param	value			Object value
*
*/
void UUEGameJoltAPI::WriteObject(TSharedRef<TJsonWriter<TCHAR>> writer, FString key, FJsonValue* value) {
	if (value->Type == EJson::String) {
		// Write simple string entry, don't a key when it isn't set
		if (key.Len() > 0) {
			writer->WriteValue(key, value->AsString());
		}
		else {
			writer->WriteValue(value->AsString());
		}
	}
	else if (value->Type == EJson::Object) {
		// Write object entry
		if (key.Len() > 0) {
			writer->WriteObjectStart(key);
		}
		else {
			writer->WriteObjectStart();
		}

		// Loop through all the values in the object data
		TSharedPtr<FJsonObject> objectData = value->AsObject();
		for (auto objectValue = objectData->Values.CreateIterator(); objectValue; ++objectValue) {
			// Using recursion to write the key and value to the writer
			WriteObject(writer, objectValue.Key(), objectValue.Value().Get());
		}

		writer->WriteObjectEnd();
	}
	else if (value->Type == EJson::Array) {
		// Process array entry
		writer->WriteArrayStart(key);

		TArray<TSharedPtr<FJsonValue>> objectArray = value->AsArray();
		for (int32 i = 0; i < objectArray.Num(); i++) {
			// Use recursion with an empty key to process all the values in the array
			WriteObject(writer, "", objectArray[i].Get());
		}

		writer->WriteArrayEnd();
	}
}

FString UUEGameJoltAPI::CreateURL(FString inputURL) {
	if (!inputURL.StartsWith("http")) {
		return "http://" + inputURL;
	}

	return inputURL;
}

/**TODO: Work on EncodeURL and Char2Hex to add some Protection to username and User Token
*/
//FString UUEGameJoltAPI::EncodeURL(FString inputString)
//{
//	FString escapedString = "";
//	int32 max = inputString.Len();
//
//	for (int32 i = 0; i < max; i++)
//	{
//		if
//			(
//				(48 <= inputString[i] && inputString[i] <= 57) || //0-9
//				(65 <= inputString[i] && inputString[i] <= 90) || //abc...xyz
//				(97 <= inputString[i] && inputString[i] <= 122) || //ABC...XYZ
//				(
//				inputString[i] == '~' || inputString[i] == '!' ||
//				inputString[i] == '*' || inputString[i] == '(' ||
//				inputString[i] == ')' || inputString[i] == '\''
//				)
//			)
//		{
//			escapedString += inputString[i];
//		}
//		else
//		{
//			escapedString += _T("%");
//			escapedString += Char2Hex(inputString, i); //converts char 255 to string "ff"
//		}
//	}
//
//	return "a";
//}
//
//FString UUEGameJoltAPI::Char2Hex(FString character, int32 index)
//{
//
//	return "b";
//}

/**
*TODO: Work on Funtionality of GetImgURL
*/
/* bool UUEGameJoltAPI::GetIMGURL(const FString& output, FString url)
{
	FString outStr;

	GameJoltComponentEnum = EGameJoltComponentEnum::GJ_OTHER;
	TSharedRef<TJsonWriter<TCHAR>> JsonWriter = TJsonWriterFactory<TCHAR>::Create(&outStr);
	//Start writing the response
	WriteObject(JsonWriter, "", new FJsonValueObject(Data));
	JsonWriter->Close();
	TSharedRef< IHttpRequest > HttpRequest = FHttpModule::Get().CreateRequest();
	HttpRequest->SetVerb("POST");
	HttpRequest->SetURL(CreateURL(url));
	HttpRequest->SetHeader("Content-Type", "application/json");
	HttpRequest->SetContentAsString(output);

	HttpRequest->OnProcessRequestComplete().BindUObject(this, &UUEGameJoltAPI::OnReady);
	HttpRequest->ProcessRequest();

	return true;
}
*/

/**
* Creates new data from the
*
* @param	key			Key
*
* @return	The requested string, empty if failed
*/
void UUEGameJoltAPI::FromString(const FString& dataString) {
	TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(dataString);

	// Deserialize the JSON data
	bool isDeserialized = FJsonSerializer::Deserialize(JsonReader, Data);

	if (!isDeserialized || !Data.IsValid()) {
		UE_LOG(LogJson, Error, TEXT("JSON data is invalid! Input:\n'%s'"), *dataString);
	}

	// Assign the request content
	Content = dataString;
}


/**
* Callback for IHttpRequest::OnProcessRequestComplete()
*
* @param	Request					HTTP request pointer
* @param	Response				Response pointer
* @param	bWasSuccessful			Whether the request was successful or not
*
*/
void UUEGameJoltAPI::OnReady(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful) {
	if (!bWasSuccessful) {
		UE_LOG(LogTemp, Error, TEXT("Response was invalid! Please check the URL."));

		// Broadcast the failed event
		OnFailed.Broadcast();
		return;
	}

	// Process the string
	FromString(Response->GetContentAsString());
	// Broadcast the result event
	OnGetResult.Broadcast();
}
void UUEGameJoltAPI::Reset()
{
	if (Data.IsValid()){
		Data.Reset();
	}

	//create a New JSON object
	Data = MakeShareable(new FJsonObject());
}