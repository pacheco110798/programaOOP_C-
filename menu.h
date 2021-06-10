#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <string.h>
#include "estudiante.h"
#include "docentes.h"
#include "materias.h"
using namespace::std;
void menu2(int campo);//prototipo fncion menu2
void Ejaccion(int tabla, int accion);//prototipo funcion para crear,modificar o eliminar un registro de la clase correspondiente

void menu1(){
    btn.clean();
    int opc;
    do{
    btn.titulo(" Menu principal");
    btn.boton("1.Estudiante");
    btn.boton("2.Docentes");
    btn.boton("3.Materias");
    cin>>opc;
    if(opc<1&&opc>3 != opc!=101)
        btn.aviso("Opcion no disponible");
    else
        menu2(opc);//abrimos el menu 2 con la clase determinada por el sario


    }while(opc!=101);//101 es para terminar con el programa
}
void menu2(int campo){
    btn.clean();//limpiamos la pantalla
int opc2;
do{
        //segun el campo que haya seleccionado el usuario en el menu anterior mostramos el mensaje
    switch(campo){
    case 1:
        btn.titulo("Estudiantes");
        break;
    case 2:
        btn.titulo("Docentes");

        break;
    case 3:
        btn.titulo("Materias");
        break;
    }
    btn.boton("1.Altas");
    btn.boton("2.Consultas");
    btn.boton("3.Todos");
    btn.boton("4.Volver");
    cin>>opc2;
    btn.clean();
    switch(opc2){
        case 1:case 2: case 3:
            Ejaccion(campo,opc2);//segun el campo que recibimos como parametro y la accion que haya seleccionado llamamos la fncion Ejaccion
            break;
        case 4:
            menu1();//volvemos a llamar a menu 1 para reinicia todo el proceso
            break;
        default:
            btn.aviso("Opcion no disponible");
            break;
        };
    }while(opc2!=4);//este menu se estará reiniciando despues de ejecutar las acciones que el usuario desee
}
void Ejaccion(int tabla,int accion){
    //muestra opciones para gestionar estudiantes
    if(tabla==1){
            if(accion==1)
                nvoEst();
            else if(accion==2)
                consultaxMat();
            else if(accion==3)
                listarEst();
    }
//muestra opciones para gestionar docentes
    else if(tabla==2){
            if(accion==1)
                nvoDoc();
            else if(accion==2)
                consultaxCod();
            else if(accion==3)
                listarDoc();
    }
    //muestra opciones para gestionar materias
    else if(tabla==3){
            if(accion==1)
                nvaMat();
            else if(accion==2)
                consultaxCodMat();
            else if(accion==3)
                listarMat();
    }
    else
    {
        menu2(tabla);
    }
}
#endif // MENU_H_INCLUDED
