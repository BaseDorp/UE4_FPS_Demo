// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FirstPersonDemo/PlatformTrigger.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePlatformTrigger() {}
// Cross Module References
	FIRSTPERSONDEMO_API UClass* Z_Construct_UClass_APlatformTrigger_NoRegister();
	FIRSTPERSONDEMO_API UClass* Z_Construct_UClass_APlatformTrigger();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_FirstPersonDemo();
// End Cross Module References
	void APlatformTrigger::StaticRegisterNativesAPlatformTrigger()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(APlatformTrigger);
	UClass* Z_Construct_UClass_APlatformTrigger_NoRegister()
	{
		return APlatformTrigger::StaticClass();
	}
	struct Z_Construct_UClass_APlatformTrigger_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APlatformTrigger_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_FirstPersonDemo,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APlatformTrigger_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "PlatformTrigger.h" },
		{ "ModuleRelativePath", "PlatformTrigger.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_APlatformTrigger_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APlatformTrigger>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_APlatformTrigger_Statics::ClassParams = {
		&APlatformTrigger::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_APlatformTrigger_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_APlatformTrigger_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APlatformTrigger()
	{
		if (!Z_Registration_Info_UClass_APlatformTrigger.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APlatformTrigger.OuterSingleton, Z_Construct_UClass_APlatformTrigger_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_APlatformTrigger.OuterSingleton;
	}
	template<> FIRSTPERSONDEMO_API UClass* StaticClass<APlatformTrigger>()
	{
		return APlatformTrigger::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(APlatformTrigger);
	struct Z_CompiledInDeferFile_FID_FirstPersonDemo_Source_FirstPersonDemo_PlatformTrigger_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FirstPersonDemo_Source_FirstPersonDemo_PlatformTrigger_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_APlatformTrigger, APlatformTrigger::StaticClass, TEXT("APlatformTrigger"), &Z_Registration_Info_UClass_APlatformTrigger, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APlatformTrigger), 47200699U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FirstPersonDemo_Source_FirstPersonDemo_PlatformTrigger_h_2220700297(TEXT("/Script/FirstPersonDemo"),
		Z_CompiledInDeferFile_FID_FirstPersonDemo_Source_FirstPersonDemo_PlatformTrigger_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FirstPersonDemo_Source_FirstPersonDemo_PlatformTrigger_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
