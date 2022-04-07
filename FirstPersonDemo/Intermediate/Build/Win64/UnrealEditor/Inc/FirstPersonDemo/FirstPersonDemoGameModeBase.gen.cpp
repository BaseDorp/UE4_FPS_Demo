// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FirstPersonDemo/FirstPersonDemoGameModeBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFirstPersonDemoGameModeBase() {}
// Cross Module References
	FIRSTPERSONDEMO_API UClass* Z_Construct_UClass_AFirstPersonDemoGameModeBase_NoRegister();
	FIRSTPERSONDEMO_API UClass* Z_Construct_UClass_AFirstPersonDemoGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_FirstPersonDemo();
// End Cross Module References
	void AFirstPersonDemoGameModeBase::StaticRegisterNativesAFirstPersonDemoGameModeBase()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AFirstPersonDemoGameModeBase);
	UClass* Z_Construct_UClass_AFirstPersonDemoGameModeBase_NoRegister()
	{
		return AFirstPersonDemoGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AFirstPersonDemoGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFirstPersonDemoGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_FirstPersonDemo,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFirstPersonDemoGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "FirstPersonDemoGameModeBase.h" },
		{ "ModuleRelativePath", "FirstPersonDemoGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFirstPersonDemoGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFirstPersonDemoGameModeBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AFirstPersonDemoGameModeBase_Statics::ClassParams = {
		&AFirstPersonDemoGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AFirstPersonDemoGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AFirstPersonDemoGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AFirstPersonDemoGameModeBase()
	{
		if (!Z_Registration_Info_UClass_AFirstPersonDemoGameModeBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AFirstPersonDemoGameModeBase.OuterSingleton, Z_Construct_UClass_AFirstPersonDemoGameModeBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AFirstPersonDemoGameModeBase.OuterSingleton;
	}
	template<> FIRSTPERSONDEMO_API UClass* StaticClass<AFirstPersonDemoGameModeBase>()
	{
		return AFirstPersonDemoGameModeBase::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFirstPersonDemoGameModeBase);
	struct Z_CompiledInDeferFile_FID_FirstPersonDemo_Source_FirstPersonDemo_FirstPersonDemoGameModeBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FirstPersonDemo_Source_FirstPersonDemo_FirstPersonDemoGameModeBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AFirstPersonDemoGameModeBase, AFirstPersonDemoGameModeBase::StaticClass, TEXT("AFirstPersonDemoGameModeBase"), &Z_Registration_Info_UClass_AFirstPersonDemoGameModeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFirstPersonDemoGameModeBase), 1160189541U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FirstPersonDemo_Source_FirstPersonDemo_FirstPersonDemoGameModeBase_h_2411795179(TEXT("/Script/FirstPersonDemo"),
		Z_CompiledInDeferFile_FID_FirstPersonDemo_Source_FirstPersonDemo_FirstPersonDemoGameModeBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FirstPersonDemo_Source_FirstPersonDemo_FirstPersonDemoGameModeBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
