#include "evenement.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>

evenement::evenement()
{
    IDEvent=0;
    NomEvent="";
    DateEvent="";
    Theme="";
    NbEmployes=0;

}

evenement::evenement(int IDEvent,QString NomEvent,QString DateEvent,QString Theme,int NbEmployes)
{
    this->IDEvent=IDEvent;
    this->NomEvent=NomEvent;
    this->DateEvent=DateEvent;
    this->Theme=Theme;
    this->NbEmployes= NbEmployes;


}

int evenement::get_IDEvent(){return IDEvent;}
QString evenement::get_NomEvent(){return NomEvent;}
QString evenement::get_DateEvent(){return DateEvent;}
QString evenement::get_Theme(){return Theme;}
int evenement::get_NbEmployes(){return NbEmployes;}

void evenement::setIDEvent(int ID){this->IDEvent=ID;}
void evenement::setNomEvent(QString Nom){this->NomEvent=Nom;}
void evenement::setDateEvent(QString Date){this->DateEvent=Date;}
void evenement::setTheme(QString Theme){this->Theme=Theme;}
void evenement::setNbEmployes(int NbEmployes){this->NbEmployes=NbEmployes;}

/*******************************************************************************************************************************/
/**********************************************Ajouter************************************************************************/


bool evenement::ajouterEvent()
{

    QString ID_string = QString::number(IDEvent);
    QString NbEmployes_string = QString::number(NbEmployes);
    QSqlQuery query;
       query.prepare("INSERT INTO evenements (id,nom,datee,theme,nb_employes) "
                     "VALUES (:ID, :Nom, :Date, :Theme, :NbEmployes)");
       query.bindValue(":ID", ID_string);
       query.bindValue(":Nom", NomEvent);
       query.bindValue(":Date", DateEvent);
       query.bindValue(":Theme", Theme);
       query.bindValue(":NbEmployes", NbEmployes_string);
       return query.exec();

}
/*******************************************************************************************************************************/
/**********************************************Afficher*************************************************************************/

QSqlQueryModel* evenement::afficherEvent()

{
     QSqlQueryModel* model=new QSqlQueryModel();

     model->setQuery("SELECT *  FROM EVENEMENTS ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("Theme"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("NbEmployes"));



     return model;

}

/*******************************************************************************************************************************/
/**********************************************Supprimer************************************************************************/

bool evenement::supprimerEvent(int ID)

{

    QSqlQuery query;

    query.prepare(" Delete from EVENEMENTS where id=:ID ");

    query.bindValue(":ID",ID);



    return query.exec();


}


bool evenement::supprimerToutEvent()
{ QSqlQuery query;

   query.prepare("delete from EVENEMENTS ");

  return query.exec();
}

/*******************************************************************************************************************************/
/***************************************************Modifier********************************************************************/


bool evenement::modifierEvent(int ID,QString Nom,QString Date,QString Theme,int NbEmployes)

{



    QSqlQuery query;

    query.prepare("update EVENEMENTS set nom=:Nom, datee=:Date, theme=:Theme, nb_employes=:NbEmployes where id=:ID");
    query.bindValue(":ID",ID);
    query.bindValue(":Nom",Nom);
    query.bindValue(":Date",Date);
    query.bindValue(":Theme",Theme);
    query.bindValue(":NbEmployes",NbEmployes);

    return query.exec();



}


/*******************************************************************************************************************************/
/***************************************************Recherche********************************************************************/



QSqlQueryModel* evenement::rechercheEvent(int ID, QString Nom, QString Date, QString Theme)

 {

     QSqlQueryModel * model= new QSqlQueryModel();
     QSqlQuery query;
     query.prepare("select * from EVENEMENTS where id like :ID or nom like :Nom or datee like :Date or theme like :Theme");
     query.bindValue(":ID",ID);// ID VARIABLE LOCAL BA3D BCH NA3MALOU APPEL BIL getID()
     query.bindValue(":Nom",Nom);
     query.bindValue(":Date",Date);
     query.bindValue(":Theme",Theme);
     query.exec();
     model->setQuery(query);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("Date"));
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("Theme"));
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("NbEmployes"));

     return model;

}

QSqlQueryModel * evenement::RechercheEvent(QString a)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM EVENEMENTS WHERE (ID LIKE '%"+a+"%' OR nom LIKE '%"+a+"%' OR datee LIKE '%"+a+"%' OR theme LIKE '%"+a+"%'  ) ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Theme"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("NbEmployes"));

    return model;
}

/*******************************************************************************************************************************/
/***************************************************Trier********************************************************************/



/*QSqlQueryModel * Evenement::trierEvent(Evenement)

{



    QSqlQuery * q = new  QSqlQuery ();

           QSqlQueryModel * model = new  QSqlQueryModel ();

           q->prepare("SELECT * FROM EVENEMENTS order by ID ASC");

           q->exec();

           model->setQuery(*q);

           return model;

}*/

QSqlQueryModel* evenement::trierEvent(evenement)
{
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select *FROM EVENEMENTS ORDER BY ID ASC");


        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Theme"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("NbEmployes"));

    return model;
}

QSqlQueryModel* evenement::trierEventNom()
{

    QSqlQueryModel* model = new QSqlQueryModel();

     model->setQuery("select *FROM EVENEMENTS ORDER BY nom ASC");


     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("Theme"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("NbEmployes"));

return model;
}


/*QSqlQueryModel* Evenement::trierEventDate()
{
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select *FROM EVENEMENTS ORDER BY datee ASC");


        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Theme"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("NbEmployes"));

}*/

QSqlQueryModel* evenement::trierEventTheme()
{
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select *FROM EVENEMENTS ORDER BY theme ASC");


        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Theme"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("NbEmployes"));

    return model;
}

/*******************************************************************************************************************************/
/***************************************************PDF********************************************************************/

void evenement::CREATION_PDF()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    QSqlQuery q;
    q.prepare("SELECT * FROM EVENEMENTS ");
    q.exec();
    QString pdf="<br> <h1  style='color:blue'>LISTE DES EVENEMENTS  <br></h1>\n <br> <table>  <tr>  <th>ID </th> <th>NOM </th> <th>DATE  </th> <th>THEME </th><th>NBR_EMPLOYES </tr>" ;


    while ( q.next()) {


        pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+" " + q.value(1).toString() +"</td>   <td>" +q.value(2).toString() +" <td>" +q.value(3).toString() +" <td>" +q.value(4).toString() +" <td>" +q.value(5).toString() +" "" " "</td> </td>" ;
    }
    doc.setHtml(pdf);
    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
    doc.print(&printer);


}





