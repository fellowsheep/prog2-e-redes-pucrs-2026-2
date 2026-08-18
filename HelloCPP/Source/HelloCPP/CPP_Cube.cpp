#include "CPP_Cube.h" // Ajustado para refletir o nome do arquivo .h no disco
#include "Components/StaticMeshComponent.h"

// Construtor: Criação e alocação de componentes
ACPP_Cube::ACPP_Cube()
{
    PrimaryActorTick.bCanEverTick = true;

    // Cria o componente de malha e o define como a raiz do ator
    CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
    RootComponent = CubeMesh;

    InitialZ = 0.0f;
}

// BeginPlay: Inicialização de estados baseados no mundo
void ACPP_Cube::BeginPlay()
{
    Super::BeginPlay();
    
    // Captura a altura exata onde o cubo foi colocado na cena
    InitialZ = GetActorLocation().Z;
}

// Tick: Orquestração do comportamento quadro a quadro
void ACPP_Cube::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// Implementação do método Girar
void ACPP_Cube::Girar(float DeltaTime)
{
    FRotator DeltaRotation(0.0f, VelocidadeRotacao * DeltaTime, 0.0f);
    AddActorLocalRotation(DeltaRotation);
}

// Implementação do método Flutuar
void ACPP_Cube::Flutuar(float DeltaTime)
{
    // Usa o tempo global do jogo para alimentar a função seno
    float GameTime = GetWorld()->GetTimeSeconds();
    float ZOffset = FMath::Sin(GameTime) * AmplitudeFlutuacao;

    FVector NovaPosicao = GetActorLocation();
    NovaPosicao.Z = InitialZ + ZOffset;

    SetActorLocation(NovaPosicao);
}