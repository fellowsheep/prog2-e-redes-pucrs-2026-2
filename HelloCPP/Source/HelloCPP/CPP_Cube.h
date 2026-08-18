#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_Cube.generated.h" // Ajustado para corresponder ao nome do arquivo .h

UCLASS()
class HELLOCPP_API ACPP_Cube : public AActor
{
    GENERATED_BODY()
    
public:    
    ACPP_Cube();

protected:
    virtual void BeginPlay() override;

public:    
    virtual void Tick(float DeltaTime) override;

    // ==========================================
    // 1. ATRIBUTOS E COMPONENTES (Onde armazenar)
    // ==========================================

    // O componente visual do cubo (a malha estática)
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    class UStaticMeshComponent* CubeMesh;

    // Posição Z inicial capturada no BeginPlay para servir de âncora para o seno
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement")
    float InitialZ;

    // Parâmetros configuráveis de movimento (editáveis no Editor/Blueprint)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
    float VelocidadeRotacao = 90.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
    float AmplitudeFlutuacao = 50.0f;

    // ==========================================
    // 2. MÉTODOS DE COMPORTAMENTO (O que fazer)
    // ==========================================

    // Método para aplicar a rotação por segundo
    UFUNCTION(BlueprintCallable, Category = "Movement")
    void Girar(float DeltaTime);

    // Método para aplicar o movimento senoidal
    UFUNCTION(BlueprintCallable, Category = "Movement")
    void Flutuar(float DeltaTime);
};