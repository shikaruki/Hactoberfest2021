#include<stdio.h>
#include<conio.h>
#include<string.h>

struct product
{
    int id;
    char name[40];
    int unit;
    float price;
};
struct product p;
int main()
{
	
    int ch,ro;
    FILE *fp,*ft;
    int a=0;
    while(ch!=6){
    
        printf("\t*****\t\tWELCOME TO product MANAGEMENT PROGRAM\t\t*****\n");
        printf("\t\t1: Insert product \n");
        printf("\t\t2: Display product\n");
        printf("\t\t3: Search product \n");
        printf("\t\t4: Delete product \n");
        printf("\t\t5: Update product \n");
        printf("\t\t6: Exit\n\n");
        fflush(stdin);
        printf("\t\tEnter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                fp=fopen("pro.txt","ab+");

                if(fp==NULL)
                {
                printf("\n\t\tError: Cannot Open the File!!!");
                return;
                }
                
                   
                printf("\n\t\tEnter product id Number: ");
                scanf("%d",&p.id);
                fflush(stdin);
                printf("\n\t\tEnter product Name: ");
                gets(p.name);
                printf("\n\t\tEnter number of product: ");
                scanf("%d",&p.unit);
                printf("\n\t\tEnter product price: ");
                scanf("%f",&p.price);
                fwrite(&p,sizeof(p),1,fp);
                printf("\n\n\t !!! product Record Inserted Sucessfully\n");
    
                fclose(fp);
    
                break;
            case 2:
                fp=fopen("pro.txt","rb");

                if(fp==NULL){
                    printf("\n\t\tError : Cannot open the File !!!");
                    return;
                }

                printf("\nid.No\tName\tunit\tprice\n\n");
    
                while(fread(&p,sizeof(p),1,fp)==1){
                printf("%d\t%s\t%d\t%f\n",p.id,p.name,p.unit,p.price);
                }
                fclose(fp);
                break;

            case 3:    
                fp=fopen("pro.txt","rb");
                if(fp==NULL){
                    printf("\n\t\tError: Cannot Open the File!!!");
                    return;
                }
                printf("\n\n\tEnter product id Number Which You Want To Search: ");
                scanf("%d",&ro);
                while(fread(&p,sizeof(p),1,fp)>0 && a==0){
                    if(p.id==ro){
                        a=1;
                        printf("\n\n\tSearch Sucessfull And product Records Is as Follows: \n\n");
                        printf("\nid.No\tName of product\tunit\tprice\n\n");
                        printf("%d\t%s\t%d\t%f\n",p.id,p.name,p.unit,p.price);
                    }
                }
                if(a==0){
                    printf("\n\n\t\tNo Such Record Found !!!!!\n");
                }
                fclose(fp); 
                break;

            case 4:
            	fp=fopen("pro.txt","rb");
                ft=fopen("pro1.txt","ab+");
                if(fp==NULL){
                    printf("\n\t\tError: Cannot Open the File!!!");
                    return;
                }
                fflush(stdin);
                printf("\n\n\tEnter product id Number Which You Want to Delete ");
                scanf("%d",&ro);
                while(fread(&p,sizeof(p),1,fp)>0 && a==0){
                    if(p.id==ro){
                        a=1;
                        printf("\n\t\tRecord Deleted Sucessfully \n");
                    }
                    else{
                        fwrite(&p,sizeof(p),1,ft);
                    }
                }
                if(a==0)
                {
                printf("\n\n\t\tNo Such Record Found !!!");
                }
                fclose(fp);
                fclose(ft);
                remove("pro.txt");
                rename("pro1.txt","pro.txt");
                break;
            
			case 5:
                fp=fopen("pro.txt","rb+");
                if(fp==NULL){
                    printf("\n\t\tError: Cannot Open the File!!!");
                    return;
                    } 
                printf("\n\n\tEnter id Number of product Whose Record You Want To Update: ");
                scanf("%d",&ro);
                while(fread(&p,sizeof(p),1,fp)>0 && a==0){
                    if(p.id==ro){
                        a=1;
                        printf("\nid.No\tName\tunit\tprice\n\n");
                        printf("%d\t%s\t%d\t%f\n",p.id,p.name,p.unit,p.price);
                        printf("\n\t\t*** Now Enter the New Record ***\n\n");

                        printf("\n\t\tUpdated product id Number: ");
                        scanf("%d",&p.id);
                        fflush(stdin);
                        printf("\n\t\tUpdated product Name: ");
                        gets(p.name);
                        printf("\n\t\tUpdated product unit: ");
                        scanf("%d",&p.unit);
                        printf("\n\t\tUpdated product price: ");
                        scanf("%f",&p.price);
                        fseek(fp,-(long)sizeof(p),1);
                        fwrite(&p,sizeof(p),1,fp);
                        printf("\n\n\t\tRecord Updated Successfully \n\t\t");
                    }
               }
               if(a==0){
                   printf("\n\t\tError : Something went wrong!!!");
                }
                fclose(fp);
				
                break;
            case 6: 
			    exit(0);
                default:
                printf("\n\t\tprogram ended");
                break;
        }
        getch();
    }
       return 0;
}

