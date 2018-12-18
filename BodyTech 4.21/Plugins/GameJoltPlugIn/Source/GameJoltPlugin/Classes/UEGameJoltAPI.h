// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
/*
By JvtheWanderer
*/
#pragma once
#include "UEGameJoltAPI.generated.h"

/**
 * 
 */
//DECLARE_LOG_CATEGORY_EXTERN(AuthorizeError, Log, All);

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGetResult);

// Generate a delegate for the OnFailed event
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFailed);

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EGameJoltComponentEnum : uint8
{
	GJ_USER_AUTH 	UMETA(DisplayName = "Authorize User"),
	GJ_USER_FETCH 	UMETA(DisplayName = "Fetch User"),
	GJ_SESSION_OPEN	    UMETA(DisplayName = "Open Session"),
	GJ_SESSION_PING 	UMETA(DisplayName = "Ping Session"),
	GJ_SESSION_CLOSE 	UMETA(DisplayName = "Close Session"),
	GJ_TROPHIES_FETCH 	UMETA(DisplayName = "Fetch Trophies"),
	GJ_TROPHIES_ADD 	UMETA(DisplayName = "Add Achieved Trophies"),
	GJ_SCORES_FETCH 	UMETA(DisplayName = "Fetch Score"),
	GJ_SCORES_ADD 		UMETA(DisplayName = "Add Score"),
	GJ_SCORES_TABLE 	UMETA(DisplayName = "Get Score Tables"),
	GJ_DATASTORE_FETCH	UMETA(DisplayName = "Fetch Data Store"),
	GJ_DATASTORE_SET	UMETA(DisplayName = "Set Data Store"),
	GJ_DATASTORE_UPDATE	UMETA(DisplayName = "Update Data Store"),
	GJ_DATASTORE_REMOVE UMETA(DisplayName = "Get Keys"),
	GJ_OTHER			UMETA(DisplayName = "Other")
};

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EGameJoltAchievedTrophies : uint8
{
	GJ_ACHIEVEDTROPHY_BLANK UMETA(DisplayName = "All Trophies"),
	GJ_ACHIEVEDTROPHY_USER UMETA(DisplayName = "User Achieved Trophies"),
	GJ_ACHIEVEDTROPHY_GAME UMETA(DisplayName = "Unachieved Trophies")
};
USTRUCT(BlueprintType)
struct FUserInfo
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User ID")
		int32 S_User_ID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User type")
		FString User_Type;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Username")
		FString User_Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User Avatar")
		FString User_AvatarURL;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User Signed up")
		FString Signed_up;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User Last Logged in")
		FString Last_Logged_in;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User Status")
		FString status;
};

USTRUCT(BlueprintType)
struct FTrophyInfo
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trophy ID")
	int32 Trophy_ID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trophy's Name")
		FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trophy's Description")
		FString Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trophy's Difficulty")
		FString Difficulty;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trophy's Image URL")
		FString image_url;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Achieved Time")
		FString achieved;
};

USTRUCT(BlueprintType)
struct FScoreInfo
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score String")
	FString ScoreString;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score Sort")
		int32 ScoreSort;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score Extra Data")
		FString extra_data;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score Username")
		FString UserName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score User ID")
		int32 User_Id;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score Guest Username")
		FString guestUser;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score Stored")
		FString stored;

};

USTRUCT(BlueprintType)
struct FScoreTableInfo
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scoreboard Table ID")
		int32 Id;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scoreboard Table Name")
		FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scoreboard Table Description")
		FString Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scoreboard Table Primary")
		FString Primary;

};


UCLASS(BlueprintType, Blueprintable)
class UUEGameJoltAPI : public UObject
{
	GENERATED_UCLASS_BODY()

private:

	/* Internal bind method for the IHTTPRequest::OnProcessRequestCompleted() event */
	void OnReady(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
	/* Reset Data*/
	void Reset();

	static FString CreateURL(FString inputURL);

	void WriteObject(TSharedRef<TJsonWriter<TCHAR>> writer, FString key, FJsonValue* value);

public:

	UObject* contextObject;

	UPROPERTY(BlueprintReadOnly, Category = "GameJolt")
		bool bGuest;
	UPROPERTY(BlueprintReadWrite, Category = "GameJolt")
		FString Guest_username;

	UPROPERTY(BlueprintReadOnly, Category = "GameJolt")
		bool m_LoggedIn;

	UPROPERTY(BlueprintReadWrite, Category = "GameJolt")
		EGameJoltComponentEnum GameJoltComponentEnum;

	/* The actual field data */
	TSharedPtr<FJsonObject> Data;

	/* Contains the actual page content, as a string */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GameJolt")
		FString Content;

	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameJolt")
		FOnGetResult OnGetResult;

	/* Event which triggers when the request failed */
	UPROPERTY(BlueprintAssignable, Category = "GameJolt")
		FOnFailed OnFailed;

	/* Creates new data from the input string */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "From String"), Category = "GameJolt")
		void FromString(const FString& dataString);

	/* Creates a new post data object */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Create GameJolt API Data", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"), Category = "GameJolt")
		static UUEGameJoltAPI* Create(UObject* WorldContextObject);

	UPROPERTY(BlueprintReadOnly, meta = (DisplayName = "Your Game ID"), Category = "GameJolt")
		int32 Game_ID;
	UPROPERTY(BlueprintReadOnly, meta = (DisplayName = "Your Game Private Key"), Category = "GameJolt")
		FString Game_PrivateKey;
	UPROPERTY(BlueprintReadOnly, meta = (DisplayName = "Players Username"), Category = "GameJolt")
		FString UserName;
	UPROPERTY(BlueprintReadOnly, meta = (DisplayName = "Players UserToken"), Category = "GameJolt")
		FString UserToken;
	UPROPERTY(BlueprintReadWrite, meta = (DisplayName = "GameJolt API Server"), Category = "GameJolt")
		FString GJAPI_SERVER;
	UPROPERTY(BlueprintReadWrite, meta = (DisplayName = "GameJolt API Root"), Category = "GameJolt")
		FString GJAPI_ROOT;
	UPROPERTY(BlueprintReadWrite, meta = (DisplayName = "GameJolt API Version"), Category = "GameJolt")
		FString GJAPI_VERSION;

	//Public Functions
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Your Game ID"), Category = "GameJolt")
		int32 GetGameID();
	UFUNCTION(Blueprintcallable, meta = (DeprecatedFunction, DeprecationMessage = "'SetGameID' is deprecated. Use 'Init' instead.", DisplayName = "Set Your Game ID"), Category = "GameJolt")
		bool SetGameID(int32 f_game_ID);
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Your Game Private Key"), Category = "GameJolt")
		FString GetGamePrivateKey();
	UFUNCTION(Blueprintcallable, meta = (DeprecatedFunction, DeprecationMessage = "'SetGamePrivateKey' is deprecated. Use 'Init' instead.", DisplayName = "Set Your Game Private Key"), Category = "GameJolt")
		bool SetGamePrivateKey(FString f_game_PrivateKey);
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Username"), Category = "GameJolt")
		FString GetUsername();
	UFUNCTION(Blueprintcallable, meta = (DisplayName = "Set Username"), Category = "GameJolt")
		bool SetUserName(FString f_Username);
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get User Token"), Category = "GameJolt")
		FString GetUserToken();
	UFUNCTION(Blueprintcallable, meta = (DisplayName = "Set User Token"), Category = "GameJolt")
		bool SetUserToken(FString f_UserToken);


	// By FreezerNick
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Init"), Category = "GameJolt|Init")
		void Init(FString PrivateKey, int32 GameID);

	//Sessions - by FreezerNick
	UFUNCTION(BlueprintCallable, meta = (DislayName = "Open Session"), Category = "GameJolt|Sessions")
		bool OpenSession();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Ping Session"), Category = "GameJolt|Sessions")
		bool PingSession();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Close Session"), Category = "GameJolt|Sessions")
		bool CloseSession();
	// End of work by FreezerNick

	// More stuff by FreezerNick

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Server Time"), Category = "GameJolt|Misc")
		int32 GetServerTime();

	UFUNCTION(Blueprintcallable, meta = (Displayname = " Send Request 1.2"), Category = "GameJolt")
		bool SendRequest12(const FString& output, FString url);

	// End of work by FreezerNick

	// User Stuff

	//Login 
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Login User"), Category = "GameJolt")
		bool AuthUser();
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Is User Login"), Category = "GameJolt")
		bool isUserAuthorize();
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Logoff User"), Category = "GameJolt")
		void LogOffUser();
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Login Status"), Category = "GameJolt")
		void LogInStatus();
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Fetch Users"), Category = "GameJolt")
		bool FetchUser();
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Array of Users"), Category = "GameJolt")
		TArray<FUserInfo> FetchArrayUsers();

	//Trophies Stuff

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Reward Trophies"), Category = "GameJolt")
		bool RewardTrophy(int32 Trophy_ID);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Fetch Trophies"), Category = "GameJolt")
		void FetchTrophies(EGameJoltAchievedTrophies AchievedType, TArray<int32> Trophies_ID);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Trophies"), Category = "GameJolt")
		TArray<FTrophyInfo> GetTrophies();

	//Score Stuff
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Fetch Scoreboard"), Category = "GameJolt")
		bool FetchScoreboard(int32 ScoreLimit, int32 Table_id);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Scoreboard"), Category = "GameJolt")
		TArray<FScoreInfo> GetScoreboard();
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Add Score to Scoreboard"), Category = "GameJolt")
		bool AddScore(FString UserScore, int32 UserScore_Sort, int32 Scoreboard_ID, FString GuestUser, FString extra_data, int32 table_id);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Fetch Scoreboard Table"), Category = "GameJolt")
		bool FetchScoreboardTable();
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Scoreboard Table"), Category = "GameJolt")
		TArray<FScoreTableInfo>  GetScoreboardTable();

	//Utilty Functions.
	UFUNCTION(Blueprintcallable, meta = (Displayname = " Send Request"), Category = "GameJolt")
		bool SendRequest(const FString& output, FString url);

	/* Fetches nested post data from the post data */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Data Field", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"), Category = "GameJolt")
		UUEGameJoltAPI* GetObject(const FString& key);

	/* Gets string data from the post data */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get String Field"), Category = "GameJolt")
		FString GetString(const FString& key) const;
	/* Gets string data from the post data */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Bool Field"), Category = "GameJolt")
		bool GetBool(const FString& key) const;
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Int Field"), Category = "GameJolt")
		int32 GetInt(const FString& key) const;
	/* Get all keys from the object */
	UFUNCTION(Blueprintpure, meta = (Displayname = "Get Object Keys", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"), Category = "GameJolt")
		TArray<FString> GetObjectKeys(UObject* WorldContextObject);

	/* Gets an array with post data with the specified key */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Object Array Field", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"), Category = "GameJolt")
		TArray<UUEGameJoltAPI*> GetObjectArray(UObject* WorldContextObject, const FString& key);
/*
	UFUNCTION(Blueprintcallable, meta = (DisplayName = "Encode URL"), Category = "GameJolt")
		FString EncodeURL(FString inputString);
	UFUNCTION(Blueprintcallable, meta = (DisplayName = "Char to Hex"), Category = "GameJolt")
		FString Char2Hex(FString character, int32 index);*/
	/*
		UFUNCTION(Blueprintcallable, meta = (DisplayName = "Get Image from URL"), Category = "GameJolt")
		bool GetIMGURL(const FString& output, FString url);
	*/
};
