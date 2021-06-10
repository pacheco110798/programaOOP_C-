using namespace::std;
#include <vector>
#include "iostream"
#include <string.h>
#include "botones.h"
class estudiante {
private:
    int matricula;//matricula de estudiante
    double promedio;//promedio del estudiante
    string nombre;//nombre del estudiante
    string carrera;//carrera del estudiante
public:
    bool activo;//estado del estudiante
    estudiante(int mat, string nom);//cosntructor parametrizado
    estudiante(){};//constructor por defecto
    ~estudiante(){};//destructor por defecto
    bool registrarEst();//registro de estudiantes
    void datosEst();//despliegue de los datos del estudiante
    void modificaEst();//modificar estudiante
    void borrarEst();//método para borrar estudiante
    bool aprueba();//indica si el estudiante aprobó o no según su promedio

    bool buscarEst(int id){
        //método para comparar un nuevo id con el propio para saber si se encuentra disponible la nueva matrícula
    if(id==matricula)
        return true;
    else
        return false;
    }
};
vector <estudiante> Vest;//vector para almacenar los nuevos estudiantes
botones btn;//pone un marco a las opciones, se usa a trave´s de todas las clases
estudiante::estudiante(int mat,string nom){
 matricula=mat;
 nombre=nom;
 promedio=0;
 carrera="";
 activo=true;//si inicializará en estado activo
}
bool estudiante::registrarEst(){

    cout<<"Matricula del estudiante:"<<endl;
    cin >>matricula;
        bool existe=false;
        for(int i = 0; i < Vest.size(); i++)
        {
            if (Vest[i].buscarEst(matricula)==true)
            {
                //se compara la matricula ingresada con la de cada objeto a traves de su respectivo  método
                btn.aviso("Esta matricula ya existe");//si existe la la matrícula se le notifica al usuario y se activa la vandera existe
                existe=true;
            }

        }
        if (existe!=true){
            //si no existe la matrícula entonces continua pidiendo más infomación de ingreso
            cout<<"Nombre del estudiante:"<<endl;
            cin>>nombre;
            cout<<"Carrera del estudiante:"<<endl;
            cin>>carrera;
            cout<<"Promedio del estudiante:"<<endl;
            cin>>promedio;
            activo=true;
        }
   return existe;
}
bool estudiante::aprueba(){
    if(promedio>=7){
        btn.aviso("El estudiante ha aprobado exitosamente");//Si el promedio es superior o igual a 7 aprueba
        return true;
    }
    else{
        btn.aviso("El estudiante se encuentra reprobado");
        return false;
    }

}
void estudiante::datosEst(){
    cout<<"|Nombre:   |"<<nombre<<"\t|"<<endl;
    cout<<"|Carrrera: |"<<carrera<<"\t|"<<endl;
    cout<<"|Matricula:|"<<matricula<<"\t|"<<endl;
    cout<<"|Promedio: |"<<promedio<<"\t|"<<endl;
    cout<<"|-----------------------|"<<endl;
    aprueba();
}
void estudiante::modificaEst(){
   int opc;
    btn.boton("1. Nombre");
    btn.boton("2. Carrera");
    btn.boton("3. Matricula");
    btn.boton("4. Promedio");
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
            cout<<"Nueva matricula: "<<endl;
            cin>>matricula;
            break;
        case 4:
            cout<<"Nuevo promedio: "<<endl;
            cin>>promedio;
            break;
        default:
            btn.aviso("Opcion no disponible");
            break;
        cin.ignore();
    }
    btn.aviso("Cambios guardados con exito");
}
void estudiante::borrarEst(){
    activo=false;
    btn.aviso("El alumno se ha eliminado");
}
void listarEst(){
    bool disponible;
    if(Vest.empty())
        disponible = false;//si el vector de alumnos esta vacio no hay  alumnos disponibles
    else{
          for(int i = 0; i < Vest.size(); i++)
          {
              if (Vest[i].activo == true)// si el estudinte se encuentra activo imprime sus datos
              {
                  Vest[i].datosEst();
                  disponible = true;//si al menos una materia esta activa significa que hay materias disponibles
              }
                    
          }
    }
    if (disponible == false)
        btn.aviso("No existen estudiantes disponibles");
    btn.pausa();
}
void consultaxMat(){

if(Vest.empty()){
     btn.aviso("No existen estudiantes dados de alta");
     btn.pausa();
}

else{
    int mat;
    cout<<"Ingresa la matricula del estudiante a consultar:"<<endl;
    cin >>mat;
        for(int i = 0; i < Vest.size(); i++)
        {
            if (Vest[i].buscarEst(mat)==true && Vest[i].activo==true)
            {
                //si el estudiante existe y se encuentra activo se despliega la información y las opciones
                btn.clean();
                Vest[i].datosEst();
                int opc;
                btn.boton("1.Modificar");
                btn.boton("2.Eliminar");
                btn.boton("3.Volver");
                cin>>opc;
                if(opc==1)
                {
                    btn.clean();
                    Vest[i].datosEst();
                    Vest[i].modificaEst();
                }
                if(opc==2)
                {
                    Vest[i].borrarEst();
                    break;
                }
            }
            else {
                if (Vest[i].buscarEst(mat) == true && Vest[i].activo == false) {
                    btn.aviso("El alumno no se encuentra disponible");//si se encuentra una coincidencia pero no esta activo
                    break;
                }
                if (Vest[i].buscarEst(mat) == false && i == Vest.size() - 1)
                    btn.aviso("El docente no se encuentra registrado");//si no se encuentra coincidencia pero ya es el ultimo elemento de la lista
            }
        }
    btn.pausa();
    }
}
void nvoEst(){
    btn.titulo("Nuevo estudiante:");
    estudiante est;
    if(est.registrarEst()!=true)
    {
        // se ejecuta el metodo registrar y si devuelve un valor falso(no existia dicho estudiante antes) entonces se "empuja al final del vector"
        Vest.push_back(est);
        btn.aviso("Alumno registrado con exito");
    }
    btn.pausa();
}
