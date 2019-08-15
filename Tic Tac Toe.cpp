//
//  main.cpp
//  Tic Tac Toe
//
//  Created by Lore Ang on 8/15/19.
//  Copyright © 2019 Lore Ang. All rights reserved.
//

#include <iostream>
#include <limits.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

// Declarar constantes globales
const int iCOL = 10;
const int iRENG = 10;

// Inicializa con valores consecutivos desde 0
void inicializa(int iMatM[][iCOL], int iReng, int iCol)
{
    for (int iR = 0, iValor = 0; iR < iReng; iR++)
    {
        for (int iC = 0; iC < iCol; iC++)
        {
            iMatM[iR][iC] = iValor++;
        }
    }
}

// Inicializa con strings
void inicializa2(string sMatM[][iCOL], int iReng, int iCol)
{
    for (int iR = 0; iR < iReng; iR++)
    {
        for (int iC = 0; iC < iCol; iC++)
        {
            sMatM[iR][iC] = "⬜️";
        }
    }
}

// Despliega el contenido de la matriz con ints
void despliega(int iMatM[][iCOL], int iReng, int iCol)
{
    cout << "\t";
    // Despliega número de columnas
    for (int iC = 0; iC < iCol; iC++)
    {
        cout << iC << "\t";
    }
    cout << "\n";
    // Despliega línea
    for (int iC = 0; iC < iCol; iC++)
    {
        cout << "_____";
    }
    cout << "\n";
    // Despliega número de renglones
    for (int iR = 0; iR < iReng; iR++)
    {
        cout << iR << "|";
        for (int iC = 0; iC < iCol; iC++)
        {
            cout << "\t" << iMatM[iR][iC];
        }
        cout<<"\n";
    }
    cout<<"\n";
}

// Despliega el contenido de la matriz con strings
void despliega2(string sMatM[][iCOL], int iReng, int iCol)
{
    cout << "\t";
    // Despliega número de columnas
    for (int iC = 0; iC < iCol; iC++)
    {
        cout << iC << "\t";
    }
    cout << "\n";
    // Despliega línea
    for (int iC = 0; iC < iCol; iC++)
    {
        cout << "_____";
    }
    cout << "\n";
    // Despliega número de renglones
    for (int iR = 0; iR < iReng; iR++)
    {
        cout << iR << "|";
        for (int iC = 0; iC < iCol; iC++)
        {
            cout << "\t" << sMatM[iR][iC];
        }
        cout<<"\n";
    }
    cout<<"\n";
}

// Tiro de jugador
void tiroJugador(int iMatM[][iCOL], string sMatM[][iCOL], int iReng, int iCol)
{
    int iR, iC, iTiro;
    
    // Leer tiro
    cout << "Teclea la posición en la que quieres tirar ❌ : ";
    cin >> iTiro;
    cout << endl;
    
    // Encontrar el renglón y columna de cada tiro deseado
    iR = iTiro / iReng;
    iC = iTiro % iReng;
    
    // Si el tiro se encuentra en una posición ocupada o inexistente, calcular cuantos tiros sea necesario hasta que esté correcto
    while (iTiro < 0 || iTiro > (iCol * iCol - 1) || sMatM[iR][iC] != "⬜️")
    {
        cout << "Error: posición ocupada o inexistente."<< "\n";
        cout << "Teclea otra posición ❌ : ";
        cin >> iTiro;
        cout << endl;
        iR = iTiro / iReng;
        iC = iTiro % iReng;
    }
    
    // Si está en el rango y no ha sido ocupado, actualizar la matriz y terminar el ciclo de tiro
    if (sMatM[iR][iC] == "⬜️" )
    {
        sMatM[iR][iC] = "❌";
    }
}

// Tiro de computadora
void tiroComputadora(int iMatM[][iCOL], string sMatM[][iCOL], int iReng, int iCol)
{
    int iR, iC, iTiro;
    bool bExiste = false, bSalir = true;
    
    // Inicializar semilla
    srand(time(NULL));
    
    while (!bExiste)
    {
        iTiro = rand() % (iCol * iReng);
        
        // Encontrar el renglón y columna de cada tiro deseado
        iR = iTiro / iReng;
        iC = iTiro % iReng;
        
        // Si la posición está ocupada, calcular un nuevo tiro cuantas veces sea necesario
        while (sMatM[iR][iC] != "⬜️" && bSalir)
        {
            iTiro = rand() % (iCol * iReng) + 1;
            bSalir = false;
        }
        
        // Si la posición no está ocupada, actualizar la matriz y terminar el ciclo de tiro
        if (sMatM[iR][iC] == "⬜️")
        {
            cout << "Tiro de la computadora ⭕️ : " << iTiro << "\n\n";
            sMatM[iR][iC] = "⭕";
            bExiste = true;
            bSalir = true;
        }
    }
}

//Funcion que verifica si gana con un tipo Gato
bool gana (string sMatM[][iCOL], int iReng, int iCol, string sValor)
{
    bool bGano = true;
    
    // Revisar si gana por renglón
    for (int iR = 0; iR < iReng; iR++)
    {
        bGano = true;
        for (int iC = 0; bGano && iC < iCol; iC++)
        {
            if (sMatM[iR][iC] != sValor)
            {
                bGano = false;
            }
        }
        // Revisar todas las casillas del renglon iR y revisar si ya ganó por renglón
        if (bGano)
        {
            return true;
        }
    }
    
    // Revisar si gana por columna
    for (int iC = 0; iC < iCol; iC++)
    {
        bGano = true;
        for (int iR = 0; bGano && iR < iReng; iR++)
        {
            if (sMatM[iR][iC] != sValor)
            {
                bGano = false;
            }
        }
        // Salir de la columna iC y revisar si gane por columna
        if (bGano)
        {
            return true;
        }
    }
    
    // Revisar si gana por diagonal principal
    bGano = true;
    for (int iRC = 0; bGano && iRC < iCol; iRC++)
    {
        if (sMatM[iRC][iRC] != sValor)
        {
            bGano = false;
        }
    }
    if (bGano)
    {
        return true;
    }
    
    bGano = true;
    
    // Revisar si gana por diagonal inversa
    for (int iR = 0, iC = iCol - 1; bGano && iR < iReng; iR++, iC--)
    {
        if (sMatM[iR][iC] != sValor)
        {
            bGano = false;
        }
    }
    if (bGano)
    {
        return true;
    }
    
    // Si no se gana por ningún caso
    return false;
}

int main()
{
    // Declaración de variables
    int iReng, iCol, iEnter;
    int iMatM[iRENG][iCOL];
    string sMatM[iRENG][iCOL];
    bool bGanaJ = false, bGanaC = false;
    
    do
    {
        // Desplegar datos de entrada y leer cantidad de renglones
        cout << "\n######## JUEGO DE GATO ########\n";
        cout << "\n< Para salir teclea >\n";
        cout << "\nTeclea el tamaño del juego (3-10): ";
        cin >> iReng;
        cout << endl;
        
        if (iReng == -1)
        {
            cout << "Gracias por jugar :)\n";
            return 0;
        }
        
        // Revisar que el tamaño ingresado sea válido
        while (iReng > 10 || iReng < 3)
        {
            cout << "Error, ingresa un valor válido: ";
            cin >> iReng;
            cout << endl;
        }
        
        iCol = iReng;
        
        // Desplegar e inicializar matrices
        inicializa(iMatM, iReng, iCol);
        despliega(iMatM, iReng, iCol);
        inicializa2(sMatM, iReng, iCol);
        despliega2(sMatM, iReng, iCol);
        
        // Inicializar variables
        bool bSeguir = true;
        int iTurno = 0;
        // Si se hace gato en algún turno, actualizar booleanas y salir del ciclo
        while (bSeguir)
        {
            tiroJugador(iMatM, sMatM, iReng, iCol);
            iTurno++;
            despliega(iMatM, iReng, iCol);
            despliega2(sMatM, iReng, iCol);
            if (gana(sMatM, iReng, iCol, "❌") && bSeguir)
            {
                bGanaJ = true;
                bGanaC = false;
                bSeguir = false;
            }
            else
            {
                tiroComputadora(iMatM, sMatM, iReng, iCol);
                iTurno++;
                despliega(iMatM, iReng, iCol);
                despliega2(sMatM, iReng, iCol);
                if (gana(sMatM, iReng, iCol, "⭕") && bSeguir)
                {
                    bGanaJ = false;
                    bGanaC = true;
                    bSeguir = false;
                }
            }
            
            // Si no se salió del ciclo en el último turno es porque no ganó nadie -> hay empate
            if (iTurno == iCol * iReng && bSeguir)
            {
                bGanaC = false;
                bGanaJ = false;
                bSeguir = false;
            }
        }
        
        if (bGanaC)
        {
            cout << "Gana la computadora, más suerte para la próxima.\n";
        }
        else if (bGanaJ)
        {
            cout << "¡Felicidades, ganaste!\n";
        }
        else if (!bGanaJ && !bGanaC)
        {
            cout << "Empate, más suerte para la próxima.\n";
        }
        
        cout << "Gracias por jugar :)\n\n";
        cout << "< Para continuar teclea 1 > ";
        cin >> iEnter;
        cout << "\n";
    }
    while (iEnter == 1);
    
    return 0;
}
