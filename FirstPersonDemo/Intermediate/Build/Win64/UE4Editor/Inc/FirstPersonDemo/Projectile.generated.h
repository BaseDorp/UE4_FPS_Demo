// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef FIRSTPERSONDEMO_Projectile_generated_h
#error "Projectile.generated.h already included, missing '#pragma once' in Projectile.h"
#endif
#define FIRSTPERSONDEMO_Projectile_generated_h

#define FirstPersonDemo_Source_FirstPersonDemo_Projectile_h_14_SPARSE_DATA
#define FirstPersonDemo_Source_FirstPersonDemo_Projectile_h_14_RPC_WRAPPERS
#define FirstPersonDemo_Source_FirstPersonDemo_Projectile_h_14_RPC_WRAPPERS_NO_PURE_DECLS
#define FirstPersonDemo_Source_FirstPersonDemo_Projectile_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAProjectile(); \
	friend struct Z_Construct_UClass_AProjectile_Statics; \
public: \
	DECLARE_CLASS(AProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FirstPersonDemo"), NO_API) \
	DECLARE_SERIALIZER(AProjectile)


#define FirstPersonDemo_Source_FirstPersonDemo_Projectile_h_14_INCLASS \
private: \
	static void StaticRegisterNativesAProjectile(); \
	friend struct Z_Construct_UClass_AProjectile_Statics; \
public: \
	DECLARE_CLASS(AProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FirstPersonDemo"), NO_API) \
	DECLARE_SERIALIZER(AProjectile)


#define FirstPersonDemo_Source_FirstPersonDemo_Projectile_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AProjectile(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AProjectile) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProjectile); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AProjectile(AProjectile&&); \
	NO_API AProjectile(const AProjectile&); \
public:


#define FirstPersonDemo_Source_FirstPersonDemo_Projectile_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AProjectile(AProjectile&&); \
	NO_API AProjectile(const AProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AProjectile)


#define FirstPersonDemo_Source_FirstPersonDemo_Projectile_h_14_PRIVATE_PROPERTY_OFFSET
#define FirstPersonDemo_Source_FirstPersonDemo_Projectile_h_11_PROLOG
#define FirstPersonDemo_Source_FirstPersonDemo_Projectile_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FirstPersonDemo_Source_FirstPersonDemo_Projectile_h_14_PRIVATE_PROPERTY_OFFSET \
	FirstPersonDemo_Source_FirstPersonDemo_Projectile_h_14_SPARSE_DATA \
	FirstPersonDemo_Source_FirstPersonDemo_Projectile_h_14_RPC_WRAPPERS \
	FirstPersonDemo_Source_FirstPersonDemo_Projectile_h_14_INCLASS \
	FirstPersonDemo_Source_FirstPersonDemo_Projectile_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FirstPersonDemo_Source_FirstPersonDemo_Projectile_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FirstPersonDemo_Source_FirstPersonDemo_Projectile_h_14_PRIVATE_PROPERTY_OFFSET \
	FirstPersonDemo_Source_FirstPersonDemo_Projectile_h_14_SPARSE_DATA \
	FirstPersonDemo_Source_FirstPersonDemo_Projectile_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FirstPersonDemo_Source_FirstPersonDemo_Projectile_h_14_INCLASS_NO_PURE_DECLS \
	FirstPersonDemo_Source_FirstPersonDemo_Projectile_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FIRSTPERSONDEMO_API UClass* StaticClass<class AProjectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FirstPersonDemo_Source_FirstPersonDemo_Projectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
