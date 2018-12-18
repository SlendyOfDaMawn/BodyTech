/* Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
 * 
 *
 * 
 */

namespace UnrealBuildTool.Rules
{
	public class GameJoltPlugin : ModuleRules
	{
        public GameJoltPlugin(ReadOnlyTargetRules Target) : base (Target)
		{
			PublicIncludePaths.AddRange(
				new string[] {
					// ... add public include paths required here ...
				}
				);

			PrivateIncludePaths.AddRange(
				new string[] {
					"GameJoltPlugin/Private",
					// ... add other private include paths required here ...
				}
				);

			PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"Core",
                    "HTTP",
                    "CoreUObject",
                    "Engine",
                    "Json",
					// ... add other public dependencies that you statically link with here ...
				}
				);

			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					"Engine",
                    "Core",
                    "CoreUObject",
                    "HTTP",
                    "JSON",
				}
				);

			DynamicallyLoadedModuleNames.AddRange(
				new string[]
				{
					// ... add any modules that your module loads dynamically here ...
				}
				);
		}
	}
}