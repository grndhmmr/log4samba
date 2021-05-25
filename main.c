#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Erzeugung und Öffnen zur Bearbeitung einer Textdatei zur Dokumentation//

        FILE *fh_ptr;
        const char *pfadzufh;
        fh_ptr=fopen("Beleg_Samba_Logfiles.txt","w+");
        pfadzufh="./Beleg_Samba_Logfiles.txt";

    //Fehlermeldung, falls die Datei nicht erzeugt bzw. geöffnet werden kann//

        if(fh_ptr==NULL)
        {
            puts("Die Datei kann nicht geöffnet werden!");
            exit(1);
        }

    //Dateikopf//

        fprintf(fh_ptr,"\n\n\n************************************************* Belegarbeit im Modul 'Programmierung 1' *************************************************\n\n\nThema: \t\t\tErstellung eines Programms in der Programmiersprache 'C' zur Auswertung von Samba Logfiles\n\n\n*******************************************************************************************************************************************\n\nBearbeitet durch:\tRafael Gründhammer\t(CC20w1-B)\n\t\t\tAnne Pörs\t\t(CC20w1-B)\n");

    //Anzeige des Speicherortes der Datei//

    printf("Die im Rahmen der Erstellung des vorliegenden Beleges generierte Datei kann unter\n\n---     %s     ---\n\ngeöffnet werden.\n\n",pfadzufh);

    //Frage,ob die Ergebnisse der Auswertung gleich angezeigt werden sollen//

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

            if(fh_ptr==NULL)
            {
            printf("Datei konnte nicht geoeffnet werden.\n");
            }

            else
            {
            // komplette Datei zeichenweise ausgeben
                int lesen;
            // Bereits deklariert: fh_ptr=fopen("./Beleg_Samba_Logfiles.txt","w+");
                while((lesen=fgetc(fh_ptr))!=EOF)
                {
                putchar(lesen);
                }
            fclose(fh_ptr);
            printf("\n");
            return (0);
            }
            }

    else
        {
        printf("Falsche Eingabe, es werden nur die Optionen 'J' oder 'N' akzeptiert.");
        return (1);
        }
    }



    fclose(fh_ptr);
    return 0;
}
