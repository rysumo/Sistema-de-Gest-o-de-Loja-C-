@echo off
:: Configura a codificação do console para UTF-8 para exibir caracteres especiais corretamente
chcp 65001 > nul

echo ==================================================
echo   Compilador do Sistema de Gestão de Loja
echo ==================================================
echo.

:: Verifica se o GCC está instalado e disponível no PATH
where gcc >nul 2>nul
if %errorlevel% neq 0 (
    echo [ERRO] O compilador GCC não foi encontrado no seu sistema.
    echo Certifique-se de que o MinGW/GCC está instalado e adicionado ao PATH.
    echo.
    pause
    exit /b 1
)

echo Compilando os arquivos do projeto...
echo.

:: Navega até o diretório do projeto para usar os caminhos relativos corretos
::pushd "%~dp0Sistema-de-Gest-o-de-Loja-C-"

:: Executa a compilação com GCC
gcc -Wall -I include src/main.c src/utils.c src/produto.c src/cliente.c src/venda.c src/relatorio.c -o sistema_loja.exe

:: Retorna ao diretório anterior
echo.
popd

:: Verifica o código de retorno da compilação
if %errorlevel% equ 0 (
    echo.
    echo ==================================================
    echo   [SUCESSO] Projeto compilado com sucesso!
    echo   Executável gerado: sistema_loja.exe
    echo ==================================================
    echo.
    
    :: Pergunta se o usuário deseja executar o programa agora
    set /p rodar="Deseja iniciar o sistema agora? (S/N): "
    if /i "%rodar%"=="S" (
        echo.
        echo Iniciando o sistema...
        echo.
        .\sistema_loja.exe
    )
) else (
    echo.
    echo ==================================================
    echo   [ERRO] Ocorreu um erro durante a compilação.
    echo   Verifique as mensagens de erro acima.
    echo ==================================================
    echo.
    pause
)