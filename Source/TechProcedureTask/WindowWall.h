// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WindowWall.generated.h"

UCLASS()
class TECHPROCEDURETASK_API AWindowWall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWindowWall();

	UFUNCTION(BlueprintCallable)
	void CreateMesh();

	UFUNCTION()
	void AddQuad(TArray<FVector>& Vertices, TArray<int32>& Triangles, TArray<FVector2D>& UVs, TArray<FVector>& Normals, TArray<FProcMeshTangent>& Tangents, FVector V0, FVector V1, FVector V2, FVector V3, FProcMeshTangent Tangent, FVector Normal, int32 LookingAt, bool bReversedOrder=false);

private:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = Wall)
	float WallWidth = 300.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = Wall)
	float WallHeight = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = Wall)
	float WallThickness = 20.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = Window)
	float WindowPositionUp = 20.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = Window)
	float WindowPositionLeft = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = Window)
	float WindowHeight = 80.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = Window)
	float WindowWidth = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = UV)
	float UVScale = 10.f;

	UPROPERTY(VisibleAnywhere)
	class UProceduralMeshComponent* MeshComponent = nullptr;
};
