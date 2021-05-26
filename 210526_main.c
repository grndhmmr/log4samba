#include <stdio.h>
#include <stdlib.h>

int main()
{
//***ABSCHNITT 1: Erzeugung und Öffnen zur Bearbeitung einer Textdatei zur Dokumentation***//

        FILE *fp;
        fp=fopen("./Beleg_Samba_Logfiles.txt","w+");
        const char *pfadzufp;
        pfadzufp="./Beleg_Samba_Logfiles.txt";

    //Fehlermeldung, falls die Datei nicht erzeugt bzw. geöffnet werden kann//

        if(fp==NULL)
        {
            printf("Die Datei kann nicht geöffnet werden!");
            exit(1);
        }
        else
            {
            puts("Mit Start des Programms wurde eine Datei erzeugt, die die vorliegende Auswertung dokumentiert.");
            }

    //Dateikopf//

        fprintf(fp,"\n\n\n************************************************* Belegarbeit im Modul 'Programmierung 1' *************************************************\n\n\nThema: \t\t\tErstellung eines Programms in der Programmiersprache 'C' zur Auswertung von Samba Logfiles\n\n\n*******************************************************************************************************************************************\n\nBearbeitet durch:\tRafael Gründhammer\t(CC20w1-B)\n\t\t\tAnne Pörs\t\t(CC20w1-B)\n");

    //Anzeige des Speicherortes der Datei//

    printf("Die im Rahmen der Erstellung des vorliegenden Beleges generierte Datei kann unter\n\n---     %s     ---\n\ngeöffnet werden.\n\n",pfadzufp);

//***ABSCHNITT 2: Frage,ob die Ergebnisse der Auswertung gleich angezeigt werden sollen***//

    printf("--> Möchten Sie die Ergebnisse der Auswertung zunächst einmal gleich hier angezeigt bekommen (J/N)?\n\n");
        char antwort;
        antwort=getchar();

    //Weitere Anzeige in Abhängigkeit von der Beantwortung der vorstehenden Frage//

    {
    if(antwort=='N')
    {
        printf("\nIch wünsche Ihnen noch einen schönen Tag. Bis zum nächsten Mal!\n");
        return 0;
    }
    else if(antwort=='J')
    {
        //Anzeige des Inhalts der Datei 'Beleg_Samba_Logfiles.txt'

            if(fp==NULL)
            {
            printf("Datei konnte nicht geoeffnet werden.\n");
            }
            else
            {
            // komplette Datei zeichenweise ausgeben

            int groesse=sizeof(pfadzufp);
            char buffer[groesse];                                        //Eingabepuffer wird benötigt//

            fp=fopen(pfadzufp,"r");
            if(fp==NULL)
                {
                printf("Die Datei kann nicht gelesen werden.\n");
                exit(1);
                }
            while(fgets(buffer,groesse,fp))
                {
                fread(pfadzufp,groesse,buffer);
                printf("%c",buffer);
                }
            fclose(fp);
            printf("\n");
            return (0);
            }}
    else
        {
        printf("Falsche Eingabe, es werden nur die Optionen 'J' oder 'N' akzeptiert.");
        fclose(fp);
        return (1);
        }
    }
    return (0);
}
