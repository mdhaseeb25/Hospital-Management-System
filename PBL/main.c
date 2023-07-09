#include<stdio.h>
#include<stdlib.h>
typedef struct patient
{
     char name[20];
     int age;
     char disease[20];
     int ph_no;
     int room_no;
     char dep[20];
     }patient;

 typedef  struct staff
{
     int id;
     char desg[20];
     char name[20];
     int age;
     int ph_no;
     char dep[20];
     int expr;
}staff;

void create()
{
    FILE *fp,*fp1;
    int q,n,i;
    patient *b;
    staff *c;
    printf("Create Information Records of:\n");
    printf("1.Patients 2.Staff ");
    scanf("%d",&q);
    switch(q)
    {
        case 1:
       printf("Enter the number of patients  ");
        scanf("%d/n",&n);

        b=(patient*)calloc(n,sizeof(patient));

        fp=fopen("patient.txt","w");

        for(i=0;i<n;i++)
        {
          printf("Enter patients name ");
           scanf("%s/n",b[i].name);

           printf("Enter patients age ");
           scanf("%d/n",&b[i].age);

           printf("Enter patients suffering disease ");
           scanf("%s/n",b[i].disease);

           printf("Enter patients phone number ");
           scanf("%d/n",&b[i].ph_no);

           printf("Enter patients department ");
           scanf("%s/n",b[i].dep);

           printf("Enter patients room number ");
           scanf("%d/n",&b[i].room_no);

           printf("Insertion Successfull \n");
           printf("\n");

            fwrite(&b[i],sizeof(patient),1,fp);
        }

        fclose(fp);
        break;

        case 2:
            printf("Enter the number of staff  ");
            scanf("%d/n",&n);

        c=(staff*)calloc(n,sizeof(staff));

        fp1=fopen("staff.txt","w");

        for(i=0;i<n;i++)
        {
            printf("Enter Staff id ");
           scanf("%d/n",&c[i].id);

           printf("Enter Staff name ");
           scanf("%s/n",c[i].name);

           printf("Enter Staff age ");
           scanf("%d/n",&c[i].age);

           printf("Enter Staff Designation ");
           scanf("%s/n",c[i].desg);

           printf("Enter Staff phone number ");
           scanf("%d/n",&c[i].ph_no);

           printf("Enter Staff department ");
           scanf("%s/n",c[i].dep);

           printf("Enter Staff experience ");
           scanf("%d/n",&c[i].expr);

           printf("Insertion Successfull\n");
           printf("\n");

        fwrite(&c[i],sizeof(staff),1,fp1);
    }
         fclose(fp1);
        }


}

void display()
{
    int w;
    patient b1;
    staff c1;
    FILE *fp,*fp1;
    printf("Display Information records of:\n");
    printf("1.Patients 2.Staff ");
    scanf("%d",&w);
    printf("\n");
    switch(w)
    {
   case 1:
    fp=fopen("patient.txt","r");
    while(fread(&b1,sizeof(patient),1,fp))
    {

               printf("%1s",b1.name);

               printf("%5d",b1.age);

               printf("%9s",b1.disease);

               printf("%13d",b1.ph_no);

               printf("%16s",b1.dep);

               printf("%18d",b1.room_no);


               printf("\n");
    }
    fclose(fp);
    break;

   case 2:
    fp1=fopen("staff.txt","r");
    while(fread(&c1,sizeof(staff),1,fp1))
    {
                   printf("%s",c1.name);

                   printf("%5d",c1.id);

                   printf("%8s",c1.desg);

                   printf("%11d",c1.age);

                   printf("%14s",c1.dep);

                   printf("%17d",c1.ph_no);

                   printf("%19d",c1.expr);

                   printf("\n");

    }
    fclose(fp1);
    }
}





 void Insert()
 {
     FILE *fp,*fp1;
    int q,n,i;
    patient *b;
    staff *c;
    printf("Insert Information of:\n");
    printf("1.Patients 2.Staff ");
    scanf("%d",&q);
    printf("\n");
    switch(q)
    {
        case 1:
       printf("Enter the number of patients  ");
        scanf("%d/n",&n);

        b=(patient*)calloc(n,sizeof(patient));

        fp=fopen("patient.txt","a");

        for(i=0;i<n;i++)
        {
          printf("Enter patients name ");
           scanf("%s/n",b[i].name);

           printf("Enter patients age ");
           scanf("%d/n",&b[i].age);

           printf("Enter patients suffering disease ");
           scanf("%s/n",b[i].disease);

           printf("Enter patients phone number ");
           scanf("%d/n",&b[i].ph_no);

           printf("Enter patients department ");
           scanf("%s/n",b[i].dep);

           printf("Enter patients room number ");
           scanf("%d/n",&b[i].room_no);

           printf("Insertion Successfull \n");
           printf("\n");

            fwrite(&b[i],sizeof(patient),1,fp);
        }

        fclose(fp);
        break;

        case 2:
            printf("Enter the number of staff  ");
            scanf("%d/n",&n);

        c=(staff*)calloc(n,sizeof(staff));

        fp1=fopen("staff.txt","a");

        for(i=0;i<n;i++)
        {
            printf("Enter Staff id ");
           scanf("%d/n",&c[i].id);

           printf("Enter Staff name ");
           scanf("%s/n",c[i].name);

           printf("Enter Staff age ");
           scanf("%d/n",&c[i].age);

           printf("Enter Staff Designation ");
           scanf("%s/n",c[i].desg);

           printf("Enter Staff phone number ");
           scanf("%d/n",&c[i].ph_no);

           printf("Enter Staff department ");
           scanf("%s/n",c[i].dep);

           printf("Enter Staff experience ");
           scanf("%d/n",&c[i].expr);

           printf("Insertion Successfull\n");
           printf("\n");

        fwrite(&c[i],sizeof(staff),1,fp1);
    }
         fclose(fp1);
        }
 }

 void record()
 {
     patient b1;
     staff c1;
     int e,rec;
     FILE *fp,*fp1;
     printf("No of Records of:\n");
     printf("1.Patients 2.Staff ");
     scanf("%d",&e);
     switch(e)
     {

     case 1:
         fp=fopen("patient.txt","r");
         fseek(fp,0,SEEK_END);
         rec=ftell(fp)/sizeof(patient);
         printf("No of patient records are : %d",rec);
         printf("\n");
         fclose(fp);
         break;

     case 2:
         fp1=fopen("staff.txt","r");
         fseek(fp1,0,SEEK_END);
         rec=ftell(fp1)/sizeof(staff);

         printf("No of Staff records are : %d",rec);
         printf("\n");
         fclose(fp1);


     }


 }


 void search()
 {
         int w;
    patient b1;
    staff c1;
    FILE *fp,*fp1;
    int room,flag=0,id;
    printf("Search Information of:\n");
    printf("1.Patients 2.Staff ");
    scanf("%d",&w);
    switch(w)
    {
   case 1:
    fp=fopen("patient.txt","r");
    printf("Enter the room number of patient to be searched ");
    scanf("%d",&room);
    while(fread(&b1,sizeof(patient),1,fp))
    {
            if(b1.room_no==room)
            {
               flag=1;
               printf("%2s",b1.name);

               printf("%7d",b1.age);

               printf("%13s",b1.disease);

               printf("%16d",b1.ph_no);

               printf("%19s",b1.dep);

               printf("%19d",b1.room_no);


               printf("\n");
    }
    }
        if(flag==0)
        {
            printf("NO patient in this room");
            printf("\n");
        }
    fclose(fp);
    break;

   case 2:
    fp1=fopen("staff.txt","r");
    printf("Enter Staff id to be searched ");
     scanf("%d",&id);
    while(fread(&c1,sizeof(staff),1,fp1))
    {
        if(c1.id==id)
        {

              flag=1;
                   printf("%s",c1.name);

                   printf("%5d",c1.id);

                   printf("%8s",c1.desg);

                   printf("%11d",c1.age);

                   printf("%14s",c1.dep);

                   printf("%17d",c1.ph_no);

                   printf("%19d",c1.expr);

                   printf("\n");
        }


    }

     if(flag==0)
     {

         printf("No staff with this ID number");
         printf("\n");
     }
    fclose(fp1);
    }
 }


 void edit()
 {
         int w;
    patient b1;
    staff c1;
    FILE *fp,*fp1;
    FILE *fp2,*fp3;
    int room,flag=0,id;
    printf("Edit Information of:\n");
    printf("1.Patients 2.Staff ");
    scanf("%d",&w);
    switch(w)
    {
   case 1:
    fp=fopen("patient.txt","r");
    fp2=fopen("temp.txt","w");
    printf("Enter the room number of patient whose information is edited ");
    scanf("%d",&room);
    while(fread(&b1,sizeof(patient),1,fp))
    {
            if(b1.room_no==room)
            {
               flag=1;
               printf("Enter patients new name ");
               scanf("%s/n",b1.name);

                printf("Enter patients new age ");
                scanf("%d/n",&b1.age);

                printf("Enter patients suffering disease ");
                scanf("%s/n",b1.disease);

                 printf("Enter patients new phone number ");
                 scanf("%d/n",&b1.ph_no);

                  printf("Enter patients department ");
                  scanf("%s/n",b1.dep);


               printf("\n");
    }
     fwrite(&b1,sizeof(patient),1,fp2);

    }
    fclose(fp);
    fclose(fp2);

    if (flag==1)
    {

        fp2=fopen("temp.txt","r");
        fp=fopen("patient.txt","w");
        while(fread(&b1,sizeof(patient),1,fp2))
        {
            fwrite(&b1,sizeof(patient),1,fp);

        }
        fclose(fp);
        fclose(fp2);
    }
        if(flag==0)
        {
            printf("Record not found");
            printf("\n");
        }

    break;

   case 2:
    fp1=fopen("staff.txt","r");
    fp3=fopen("temp1.txt","w");
    printf("Enter Staff id whose information is be edited ");
     scanf("%d",&id);
    while(fread(&c1,sizeof(staff),1,fp1))
    {
        if(c1.id==id)
        {

              flag=1;
              printf("Enter Staff new name ");
              scanf("%s/n",c1.name);

              printf("Enter Staff new age ");
              scanf("%d/n",&c1.age);

              printf("Enter Staff Designation ");
              scanf("%s/n",c1.desg);

              printf("Enter Staff phone number ");
              scanf("%d/n",&c1.ph_no);

              printf("Enter Staff new department ");
              scanf("%s/n",c1.dep);

              printf("Enter Staff experience ");
              scanf("%d/n",&c1.expr);

                   printf("\n");

        }
        fwrite(&c1,sizeof(staff),1,fp3);
    }

    fclose(fp1);
    fclose(fp3);


    if(flag==1)
    {
        fp3=fopen("temp1.txt","r");
        fp1=fopen("staff.txt","w");
        while(fread(&c1,sizeof(staff),1,fp3))
        {
            fwrite(&c1,sizeof(staff),1,fp1);

        }
        fclose(fp1);
        fclose(fp3);

    }
     if(flag==0)
     {

         printf("Record not found");
         printf("\n");
     }

    }
 }


 void Delete()
 {
         int w;
    patient b1;
    staff c1;
    FILE *fp,*fp1;
    FILE *fp2,*fp3;
    int room,flag=0,id;
    printf("Delete Information of:\n");
    printf("1.Patients 2.Staff ");
    scanf("%d",&w);
    switch(w)
    {


   case 1:
    fp=fopen("patient.txt","r");
    fp2=fopen("temp.txt","w");
    printf("Enter the room number to be deleted ");
    scanf("%d",&room);
    while(fread(&b1,sizeof(patient),1,fp))
    {
            if(b1.room_no==room)
            {
               flag=1;
            }
            else
            {
                     fwrite(&b1,sizeof(patient),1,fp2);

            }
    }


    fclose(fp);
    fclose(fp2);

    if (flag==1)
    {

        fp2=fopen("temp.txt","r");
        fp=fopen("patient.txt","w");
        while(fread(&b1,sizeof(patient),1,fp2))
        {
            fwrite(&b1,sizeof(patient),1,fp);

        }
        fclose(fp);
        fclose(fp2);
    }
        if(flag==0)
        {
            printf("Record not found");
            printf("\n");
        }

    break;

   case 2:
    fp1=fopen("staff.txt","r");
    fp3=fopen("temp1.txt","w");
    printf("Enter Staff id to be deleted ");
     scanf("%d",&id);
    while(fread(&c1,sizeof(staff),1,fp1))
    {
        if(c1.id==id)
        {

              flag=1;
        }
        else
        {
            fwrite(&c1,sizeof(staff),1,fp3);
        }

        }



    fclose(fp1);
    fclose(fp3);


    if(flag==1)
    {
        fp3=fopen("temp1.txt","r");
        fp1=fopen("staff.txt","w");
        while(fread(&c1,sizeof(staff),1,fp3))
        {
            fwrite(&c1,sizeof(staff),1,fp1);

        }
        fclose(fp1);
        fclose(fp3);

    }
     if(flag==0)
     {

         printf("Record not found");
         printf("\n");
     }

    }
 }



void main()
{
    printf("         HOSPITAL MANAGEMENT SYSTEM     ");
  int ch;
  for(;;)
  {

       printf("\n1.Create Records");
       printf("\n2.Display Records");
       printf("\n3.Insert Records");
       printf("\n4.Delete Records");
       printf("\n5.Total No of Records");
       printf("\n6.Searching of Records");
       printf("\n7.Editing Records");
       printf("\n8.Exit");

       printf("\nEnter your choice ");
       scanf("%d",&ch);
       printf("\n");

       switch(ch)
       {
         case 1: create();
                  break;
          case 2: display();
                   break;
           case 3: Insert();
                   break;
           case 4: Delete();
                    break;
           case 5:
                  record();
                  break;
           case 6:
                   search();
                   break;
           case 7:
                  edit();
                  break;

           case 8:exit(0);
       }
  }
}



