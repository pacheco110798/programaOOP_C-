#ifndef DOCENTES_H_INCLUDED
#define DOCENTES_H_INCLUDED
using namespace::std;
#include <vector>
#include <iostream>
#include <list>
#include <string.h>

class docente {
private:
    int codigo;//codigo de empleado del docente
    string nombre;//nombre del docente
    string carrera;//nombre de la carrera del docente
    int antiguedad;//antiguedad del docente
public:
    bool activo;//estado del docente
    docente(int cod, string nom,string carr);//constructor parametrizado
    docente(){};//constructor por defecto
    ~docente(){};//destructor por defecto
    bool registrarDoc();//prototipo función para registrar a un nuevo docente(regresa verdadero si se pudo registrar adecuadamente)
    void datosDoc();//prototipo de funcion para desplegar la informacion
    void modificarDoc();//funcion para modificar la información registrada del docente
    //void eliminarDoc(){};
    void borrarDoc();//funcion para borrar al docente de la lista (solo de manera logica)

    bool buscarDoc(int id){
        //compara un valor externo con el del objeto para ver si ya se había registrado
    if(id==codigo)
        return true;
    else
        return false;
    }
};
vector <docente> listadoc;// vector que almacena los objetos docente

docente::docente(int cod,string nom,string car){
 nombre=nom;
 carrera=car;
 codigo=cod;
 antiguedad=0;//nuevo hasta que se demuestre lo contrario
 activo=true;//en la creación de cada objeto se activará por defecto
}
bool docente::registrarDoc(){

    cout<<"Codigo de empleado:"<<endl;
    cin >>codigo;
        bool existe=false;
        for(int i = 0; i < listadoc.size(); i++)
        {
            //se va a iterar a través de la lista para ver si coincide con un código ya deefinido
            if(listadoc[i].buscarDoc(codigo)==true)
            {
                //si coincide con el codigo de otro objeto se le notifica al usuario
                btn.aviso("Este codigo ya existe");
                existe=true;//se activa la bandera
            }
        }
        if (existe!=true){
                //solamente si no existe solicitará el resto de los datos
            cout<<"Nombre del docente"<<endl;
            cin>>nombre;
            cout<<"Carrera del docente"<<endl;
            cin>>carrera;
            cout<<"Antiguedad del docente"<<endl;
            cin>>antiguedad;
            activo=true;
        }
   return existe;//si existe el codigo regresa verdadero por lo que no se podrá agregar al vector
}
void docente::datosDoc(){
    //impresión de los datos almacenados
    cout<<"|-----------------------|"<<endl;
    cout<<"|Codigo:     |"<<codigo<<"\t"<<"|"<<endl;
    cout<<"|Nombre:     |"<<nombre<<"\t"<<"|"<<endl;
    cout<<"|Carrera:    |"<<carrera<<"\t"<<"|"<<endl;
    cout<<"|Antiguedad: |"<<antiguedad<<"\t"<<"|"<<endl;
}
void docente::modificarDoc(){
   int opc;
   //despliega opciones a modificar
    btn.boton("1. Nombre");
    btn.boton("2. Carrera");
    btn.boton("3. Codigo");
    btn.boton("4. Antigedad");
    cin>>opc;
    switch(opc){
        case 1:
            cout<<"Nuevo nombre: "<<endl;
            cin>>nombre;
            break;
        case 2:
            cout<<"Nueva carrera: "<<endl;
            cin>>carrera;
            break;
        case 3:
            cout<<"Nuevo código: "<<endl;
            cin>>codigo;
            break;
        case 4:
            cout<<"Nueva antiguedad: "<<endl;
            cin>>antiguedad;
            break;
        default:
            btn.aviso("Opcion no disponible");
            break;
        btn.pausa();
    }
    btn.aviso("Cambios guardados con exito");

}
void docente::borrarDoc(){
    activo=false;//simplemante cambiamos su estado para que lo descarte en fuuras iteraciones
    btn.aviso("El docente se ha eliminado");
}
void listarDoc(){
    bool disponible;
    if (listadoc.empty())
        disponible = false;
    else{
          for(int i = 0; i < listadoc.size(); i++)
          {
              if (listadoc[i].activo == true) {
                listadoc[i].datosDoc();//solamente imprimirá los datos de los docentes que se encuentren activos
                disponible = true;//si al menos un docnete esta activo significa que hay docentes disponibles
              }
                    
          }
    }
    if (disponible == false)
        btn.aviso("No existen docentes disponibles");
    btn.pausa();//este metodo simplemente borra la pantalla y espera cualquier entrada del usuario
}
void consultaxCod(){

if(listadoc.empty())
    btn.aviso("No existen docentes dados de alta");//si esta vacio no puede consultar nada
else{
    int cod;
    cout<<"Ingresa la matricula del docente a consultar:"<<endl;
    cin >>cod;
        for(int i = 0; i < listadoc.size(); i++)
        {
            if (listadoc[i].buscarDoc(cod)==true && listadoc[i].activo==true)
            {
                //cuando encuentre una coincidencia y esta este activa imprimira la informacion y dara la opcion de modificarlo
                listadoc[i].datosDoc();
                int opc;
                btn.boton("1.Modificar");
                btn.boton("2.Eliminar");
                btn.boton("3.Volver");
                cin>>opc;
                btn.clean();
                if(opc==1)
                {

                    listadoc[i].datosDoc();
                    listadoc[i].modificarDoc();
                }
                if(opc==2)
                {
                    listadoc[i].borrarDoc();
                    break;
                }
            }
            else {
                if (listadoc[i].buscarDoc(cod) == true && listadoc[i].activo == false)//si encuentra coincidencias pero no esta activa entonces no se mostrara
                {
                    btn.aviso("El docente no se encuentra disponible");//si se encuentra una coincidencia pero pero no esta activo
                    break;
                }    
                if (listadoc[i].buscarDoc(cod) == false && i==listadoc.size()-1)
                    btn.aviso("El docente no se encuentra registrado");//si no se encuentran coincidencias y ya es elultimo elemento de la lista
            }
             
        }

    }
    btn.pausa();
}
void nvoDoc(){
    btn.titulo("Nuevo docente:");
    docente doc;//objeto temporal docente
    if(doc.registrarDoc()!=true)
    {
        //llaamrá a la funcion registrar y en base al valor que regrese es decir que no existiera ningun docente con el mismo codigo permitira agregar al nuevo docente al vector
        listadoc.push_back(doc);
        btn.aviso("Docente registrado con exito");
    }
    btn.pausa();
}

#endif // DOCENTES_H_INCLUDED
