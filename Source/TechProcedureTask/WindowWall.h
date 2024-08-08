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

	//Calculates and creates mesh. Must be placed in construction script
	UFUNCTION(BlueprintCallable)
	void CreateMesh();

	/* 
	*  Generates triangles, UVs, normals and tangents based on 4 verticies
	*  @param Vertices			: Outputs for buffer
	*  @param Triangles, UVs, Normals, Tangents : Generated out buffer for further using
	*  @param V0, V1, V2, V3	: The vertives of quad must be organized to be able to create 2 triangels with (0,1,3) and (1,2,3) orders
	*  @param Tangent, Normal	: The rotation in which a triangle is facing
	*  @param LookingAt			: Determines from which axes the U-axis and V-axis should be derived. 0 is X-axis and Z-axis, 1 is X-axis and Y-axis and 2 is Y-axis and-Z axis
	*  @param bReversedOrder	: Changes the facing side of a triangle by using reverse order
	*/
	UFUNCTION()
	void AddQuad(TArray<FVector>& Vertices, TArray<int32>& Triangles, TArray<FVector2D>& UVs, TArray<FVector>& Normals, TArray<FProcMeshTangent>& Tangents, FVector V0, FVector V1, FVector V2, FVector V3, FProcMeshTangent Tangent, FVector Normal, int32 LookingAt, bool bReversedOrder=false);

private:

	//Wall width
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = Wall)
	float WallWidth = 300.f;

	//Wall height
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = Wall)
	float WallHeight = 100.f;

	//Thickness of the wall
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = Wall)
	float WallThickness = 20.f;

	//Vertical position of the window relative to the starting coordinates of the object
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = Window)
	float WindowPositionUp = 20.f;

	//Horizontal position of the window relative to the starting coordinates of the object
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = Window)
	float WindowPositionLeft = 100.f;

	//Window height
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = Window)
	float WindowHeight = 80.f;

	//Window width
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = Window)
	float WindowWidth = 100.f;

	//Scales size of UV: 1 means the same amount of repeated texture as object size. It can't be zero.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = UV)
	float UVScale = 10.f;

	UPROPERTY(VisibleAnywhere)
	class UProceduralMeshComponent* MeshComponent = nullptr;
};
