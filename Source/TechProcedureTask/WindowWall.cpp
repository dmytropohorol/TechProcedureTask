// Fill out your copyright notice in the Description page of Project Settings.

#include "WindowWall.h"
#include "ProceduralMeshComponent.h"
#include "KismetProceduralMeshLibrary.h"
#include "Components/MeshComponent.h"

// Sets default values
AWindowWall::AWindowWall()
{
	MeshComponent = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("ProceduralMeshComponent"));
	RootComponent = MeshComponent;
}

void AWindowWall::CreateMesh()
{
    TArray<FVector> Vertices;
    TArray<int32> Triangles;
    TArray<FVector> Normals;
    TArray<FVector2D> UVs;
    TArray<FProcMeshTangent> Tangents;

    //Right side of wall
    AddQuad(Vertices, Triangles, UVs, Normals, Tangents,
        FVector(0),
        FVector(0, 0, WallHeight),
        FVector(0, WallThickness, WallHeight), 
        FVector(0, WallThickness, 0), 
        FProcMeshTangent(-1, 0,0), FVector(-1, 0, 0), 2, true);

    //Left side of wall
    AddQuad(Vertices, Triangles, UVs, Normals, Tangents, 
        FVector(WallWidth, 0, WallHeight),
        FVector(WallWidth, WallThickness, WallHeight),
        FVector(WallWidth, WallThickness, 0), 
        FVector(WallWidth, 0, 0), 
        FProcMeshTangent(1, 0, 0),FVector(1, 0, 0), 2);

    //Bottom side of wall
    AddQuad(Vertices, Triangles, UVs, Normals, Tangents, 
        FVector(WallWidth, WallThickness, 0), FVector(WallWidth, 0, 0),
        FVector(0), 
        FVector(0, WallThickness, 0), 
        FProcMeshTangent(0, 0, -1),FVector(0, 0, -1), 1, true);

    //Upper side of wall
    AddQuad(Vertices, Triangles, UVs, Normals, Tangents, 
        FVector(0, 0, WallHeight), 
        FVector(0, WallThickness, WallHeight),
        FVector(WallWidth, WallThickness, WallHeight), 
        FVector(WallWidth, 0, WallHeight), 
        FProcMeshTangent(0, 0, 1),FVector(0, 0, 1), 1);

    //Right front side of wall
    AddQuad(Vertices, Triangles, UVs, Normals, Tangents, 
        FVector(0), FVector(0, 0, WallHeight),
        FVector(WindowPositionLeft, 0, WindowPositionUp + WindowHeight), 
        FVector(WindowPositionLeft, 0, WindowPositionUp), 
        FProcMeshTangent(0, -1, 0),FVector(0, -1, 0), 0);

    //Upper front side of wall
    AddQuad(Vertices, Triangles, UVs, Normals, Tangents, 
        FVector(0,0, WallHeight), FVector(WallWidth, 0, WallHeight),
        FVector(WindowPositionLeft + WindowWidth, 0, WindowPositionUp + WindowHeight), 
        FVector(WindowPositionLeft, 0, WindowPositionUp + WindowHeight), 
        FProcMeshTangent(0, -1, 0), FVector(0, -1, 0), 0);

    //Left front side of wall
    AddQuad(Vertices, Triangles, UVs, Normals, Tangents, 
        FVector(WallWidth, 0, 0), 
        FVector(WindowPositionLeft + WindowWidth, 0, WindowPositionUp),
        FVector(WindowPositionLeft + WindowWidth, 0, WindowPositionUp + WindowHeight), 
        FVector(WallWidth, 0, WallHeight), 
        FProcMeshTangent(0, -1, 0),FVector(0, -1, 0), 0);

    //Bottom front side of wall
    AddQuad(Vertices, Triangles, UVs, Normals, Tangents, 
        FVector(0), FVector(WindowPositionLeft, 0, WindowPositionUp),
        FVector(WindowPositionLeft + WindowWidth, 0, WindowPositionUp), 
        FVector(WallWidth, 0, 0), 
        FProcMeshTangent(0, -1, 0),FVector(0, -1, 0), 0);

    //Right back side of wall
    AddQuad(Vertices, Triangles, UVs, Normals, Tangents, 
        FVector(0, WallThickness, 0), 
        FVector(0, WallThickness, WallHeight),
        FVector(WindowPositionLeft, WallThickness, WindowPositionUp + WindowHeight), 
        FVector(WindowPositionLeft, WallThickness, WindowPositionUp), 
        FProcMeshTangent(0, 1, 0), FVector(0, 1, 0), 0, true);

    //Upper back side of wall
    AddQuad(Vertices, Triangles, UVs, Normals, Tangents, 
        FVector(0, WallThickness, WallHeight), 
        FVector(WallWidth, WallThickness, WallHeight),
        FVector(WindowPositionLeft + WindowWidth, WallThickness, WindowPositionUp + WindowHeight), 
        FVector(WindowPositionLeft, WallThickness, WindowPositionUp + WindowHeight), 
        FProcMeshTangent(0, 1, 0), FVector(0, 1, 0), 0, true);

    //Left back side of wall
    AddQuad(Vertices, Triangles, UVs, Normals, Tangents, 
        FVector(WallWidth, WallThickness, 0), 
        FVector(WindowPositionLeft + WindowWidth, WallThickness, WindowPositionUp),
        FVector(WindowPositionLeft + WindowWidth, WallThickness, WindowPositionUp + WindowHeight), 
        FVector(WallWidth, WallThickness, WallHeight), 
        FProcMeshTangent(0, 1, 0), FVector(0, 1, 0), 0, true);

    //Bottom back side of wall
    AddQuad(Vertices, Triangles, UVs, Normals, Tangents, 
        FVector(0, WallThickness, 0), 
        FVector(WindowPositionLeft, WallThickness, WindowPositionUp),
        FVector(WindowPositionLeft + WindowWidth, WallThickness, WindowPositionUp), 
        FVector(WallWidth, WallThickness, 0), 
        FProcMeshTangent(0, 1, 0), FVector(0, 1, 0), 0,true);

    //Bottom side of window
    AddQuad(Vertices, Triangles, UVs, Normals, Tangents, 
        FVector(WindowPositionLeft, 0, WindowPositionUp), 
        FVector(WindowPositionLeft, WallThickness, WindowPositionUp),
        FVector(WindowPositionLeft + WindowWidth, WallThickness, WindowPositionUp), 
        FVector(WindowPositionLeft + WindowWidth, 0, WindowPositionUp), 
        FProcMeshTangent(0, 0, 1),FVector(0, 0, 1), 1);

    //Upper side of window
    AddQuad(Vertices, Triangles, UVs, Normals, Tangents, 
        FVector(WindowPositionLeft + WindowWidth, WallThickness, WindowPositionUp + WindowHeight), 
        FVector(WindowPositionLeft + WindowWidth, 0, WindowPositionUp + WindowHeight),
        FVector(WindowPositionLeft, 0, WindowPositionUp + WindowHeight) , 
        FVector(WindowPositionLeft, WallThickness, WindowPositionUp + WindowHeight), 
        FProcMeshTangent(0, 0, -1),FVector(0, 0, -1), 1, true);

    //Right side of window
    AddQuad(Vertices, Triangles, UVs, Normals, Tangents, 
        FVector(WindowPositionLeft, 0, WindowPositionUp), 
        FVector(WindowPositionLeft, 0, WindowPositionUp + WindowHeight),
        FVector(WindowPositionLeft, WallThickness, WindowPositionUp+WindowHeight), 
        FVector(WindowPositionLeft, WallThickness, WindowPositionUp), 
        FProcMeshTangent(1, 0, 0),FVector(1, 0, 0), 2);

    //Left side of window
    AddQuad(Vertices, Triangles, UVs, Normals, Tangents, 
        FVector(WindowPositionLeft + WindowWidth, WallThickness, WindowPositionUp + WindowHeight), 
        FVector(WindowPositionLeft + WindowWidth, WallThickness, WindowPositionUp),
        FVector(WindowPositionLeft + WindowWidth, 0, WindowPositionUp), 
        FVector(WindowPositionLeft + WindowWidth, 0, WindowPositionUp + WindowHeight), 
        FProcMeshTangent(-1, 0, 0), FVector(-1, 0, 0), 2, true);

    // Creating section grid
    MeshComponent->CreateMeshSection(0, Vertices, Triangles, Normals, UVs, TArray<FColor>(), Tangents, true);
}

void AWindowWall::AddQuad(TArray<FVector>& Vertices, TArray<int32>& Triangles, TArray<FVector2D>& UVs, TArray<FVector>& Normals, TArray<FProcMeshTangent>& Tangents, FVector V0, FVector V1, FVector V2, FVector V3, FProcMeshTangent Tangent, FVector Normal, int32 LookingAt, bool bReversedOrder)
{
    //Gets number of verticies for further using in triangels generation
    int32 StartIndex = Vertices.Num();

    //Fills verticies array with input V0, V1, V2 and V3
    Vertices.Add(V0);
    Vertices.Add(V1);
    Vertices.Add(V2);
    Vertices.Add(V3);

    //Generates UVs for every vertices. LookingAt determines from which axes the U-axis and V-axis should be derived
    if (LookingAt == 0) {
        UVs.Add(FVector2d(V0.X, V0.Z) / UVScale);
        UVs.Add(FVector2d(V1.X, V1.Z) / UVScale);
        UVs.Add(FVector2d(V2.X, V2.Z) / UVScale);
        UVs.Add(FVector2d(V3.X, V3.Z) / UVScale);
    }
    else if (LookingAt == 1){
        UVs.Add(FVector2d(V0.X, V0.Y) / UVScale);
        UVs.Add(FVector2d(V1.X, V1.Y) / UVScale);
        UVs.Add(FVector2d(V2.X, V2.Y) / UVScale);
        UVs.Add(FVector2d(V3.X, V3.Y) / UVScale);
    }
    else if (LookingAt == 2) {
        UVs.Add(FVector2d(V0.Y, V0.Z) / UVScale);
        UVs.Add(FVector2d(V1.Y, V1.Z) / UVScale);
        UVs.Add(FVector2d(V2.Y, V2.Z) / UVScale);
        UVs.Add(FVector2d(V3.Y, V3.Z) / UVScale);
    }

    //Generates normals and tangents
    for (int i = 0; i < 4; i++) {
        Tangents.Add(Tangent);
        Normals.Add(Normal);
    }

    //Generates triangels. bReversedOrder changes the facing side of a triangle by using reverse order
    if (bReversedOrder) {
        Triangles.Add(StartIndex + 3);
        Triangles.Add(StartIndex + 1);
        Triangles.Add(StartIndex + 0);

        Triangles.Add(StartIndex + 3);
        Triangles.Add(StartIndex + 2);
        Triangles.Add(StartIndex + 1);
    }
    else {
        Triangles.Add(StartIndex + 0);
        Triangles.Add(StartIndex + 1);
        Triangles.Add(StartIndex + 3);

        Triangles.Add(StartIndex + 1);
        Triangles.Add(StartIndex + 2);
        Triangles.Add(StartIndex + 3);
    }
}

