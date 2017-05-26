#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define N_SIZE 10
#define Z_SIZE 20
int n,m;
struct book_record
{
       char book_name[100];
       char author[100];
       int pub_year;
       int available_copies;
}list1, list2, list3, list4, list5, list;

//INITIALIZE FUNCTION
void initialize(struct book_record list[])
{
     int i;
     for(i=0;i<N_SIZE;i++)
     {
                     list[i].author[i]='\0';
                     list[i].book_name[i]='\0';
                     list[i].pub_year=0;
                     list[i].available_copies=0;
     }
                    
                     
}


//DISPLAY FUNCTION
void display(struct book_record list[], int n)
{
     int i;
     for(i=0;i<n;i++)
     {
     	             printf("\n");
                     printf("%s",list[i].author);
                     printf("\n");
                     printf("%s",list[i].book_name);
                     printf("\n");
                     printf("%d", list[i].pub_year);
                     printf("\n");
                     printf("%d", list[i].available_copies);
                     printf("\n");
     }
}

// SORT FUNCTION
void sort(struct book_record list[], int n)
{
     int i, j;
     struct book_record t;  //temporary record
     char null[]="\0";
	 
	 for(i=0;i<n-1;++i)
     {
                       for(j=0;j<n-i-1;++j)
                       {

                                           if((strcmp(list[j].author, list[j+1].author)>0)&&(list[j+1].pub_year!=0))    //first sort by author name
                                           {
                                                                     t=list[j];
                                                                     list[j]=list[j+1];
                                                                     list[j+1]=t;
                                           }
                                           if((strcmp(list[j].author, list[j+1].author)==0)&&(list[j+1].pub_year!=0))
                                           {
                                                                     if(strcmp(list[j].book_name, list[j+1].book_name)>0)
                                                                     {
                                                                                                  t=list[j];
                                                                                                  list[j]=list[j+1];
                                                                                                  list[j+1]=t;
                                                                     }
                                           }
                       }
     }
}
                                                                 
                                                                  
//SEARCH FUNCTION                                                                                                  
                                                                                                                                                                     
int search_record(struct book_record list[],int n, char book_name[], char author[])
{
     int i=0,j,found=0;
     while((i<N_SIZE)&&(found==0))                     //iterate until the desired record is not found
     {
                             if((strcmp(list[i].book_name, book_name)==0)&&(strcmp(list[i].author,author)==0))
                             {
                                                           found=1;
                             }
                             else
                             {
                                 i++;
                             }
     }
      
      return i;
}

//FREE INDEX FUNCTION
int free_index(struct book_record list[])
{
    int free=0, i=0;
     
           while((i<N_SIZE)&&(free==0))
           {
                                        if(list[i].pub_year==0)
                                        {
                                                                free=1;
                                        }
                                        else
                                        {
                                            i++;
                                        }
           }
     
     
     
     return i;
}

// INSERT FUNCTION
int insert(struct book_record list[], int n,char book_name[], char author[], int pub_year, int available_copies)
{
     int i, free, status;
     status=1;

     i= search_record(list,n, book_name, author);  //to find record to be updated
     if(i<N_SIZE)                                  //the entry belong to the record, 'i' is the position of the to be updated entry
     {
                strcpy(list[i].author,author);
                strcpy(list[i].book_name,book_name);
                list[i].pub_year=pub_year;
                list[i].available_copies=available_copies;
     }
     else                                          //if such record does not exist
     {
          i=free_index(list);
          
           
           if(i>=N_SIZE)
           {
                             status=0;
           }
           else
           {
                strcpy(list[i].author,author);
                strcpy(list[i].book_name,book_name);
                list[i].pub_year=pub_year;
                list[i].available_copies=available_copies;
           }
           sort(list, N_SIZE);
    }
           
     return status;
}

// DELETE FUNCTION

int delete_record(struct book_record list[], int n, char author[], char book_name[])
{
    int i, status=0, j;
    i= search_record( list,n, book_name, author);  //entry to be deleted is found
    if(i<n)
    {
           status=1;
    }
    for(j=i;j<n-1;j++)
    {
       strcpy(list[j].author, list[j+1].author);
       strcpy(list[j].book_name, list[j+1].book_name);
       list[j].pub_year=list[j+1].pub_year;
       list[j].available_copies=list[j+1].available_copies;
    	
    }

	list[n-1].author[i]='\0';
	list[n-1].book_name[i]='\0';
	list[n-1].pub_year=0;
	list[n-1].available_copies=0;      
    
    
    return status;
}

//IS-EMPTY FUNCTION
void is_empty(struct book_record list[])
{
	int i=0, record=0;
	for(i=0;((i<N_SIZE)&&(record==0));i++)
	{
		
		if(list[i].pub_year!=0)
		{
			record=1;
		}
		
	}
	if(record==1)
	{
		printf("list is not empty");
		
	}
	else
	{
		printf("list is empty");
	}
}


//IS_FULL FUNCTION
void isFull(struct book_record list[])
{
     int i=0;
     i=free_index(list);
     if(i>=N_SIZE)
     {
                  printf("record is full"); 
     }
     else
     {
         printf("record is not full");
     }
}

// GET-TOPMOST-BOOK-AUTHOR FUNCTION
void getTopMostBookAuthor(struct book_record list[],int n, char book_name[])
{
     int i=0, j=0, max=0, k=0;
     struct book_record required1[N_SIZE];
     
     while(i<n)
     {
               if(strcmp(list[i].book_name,book_name)==0)  //records containing the given book name are separated
               {
                  strcpy(required1[j].book_name, book_name);
                  strcpy(required1[j].author,list[i].author);              // making a seperate structure of entries having same book name
                  required1[j].available_copies=list[i].available_copies;
                  j++;
                  if(max<list[i].available_copies)
                  {
                           max=list[i].available_copies;
                           i++;
                        printf("%d",max);
                  }
                i++;
               }
               else
               {
                   i++;
               }
        
    }
    
     while(k<j)
     {
                if(max==required1[k].available_copies)
                {
                     printf("%c",required1[k].author);
                     k++;
               }
                else
                {
                    k++;
               }
    }
}

//"LIST-UNIQUE" FUNCTION
void list_unique(struct book_record list[], int n, struct book_record list5[])
{
     int i=1, j=0;

     while(i<n)
     {
                 
                 if((strcmp(list[i-1].author,list[i].author)==0)&&(strcmp(list[i-1].book_name,list[i].book_name)==0))
                 {
                                                            
																		   	
				   if(list[i-1].pub_year>list[i].pub_year)
				   																		   	
				
				   {
				   	   strcpy(list5[j].author, list[i-1].author);
                       strcpy(list5[j].book_name, list[i-1].book_name);
                       list5[j].pub_year=list[i-1].pub_year;
                       list5[j].available_copies=list[i-1].available_copies;
				       j++;                                                     	
                       i=i+1;
                     
                   }
                   
                   else
                   {
                   	   strcpy(list5[j].author, list[i].author);
                       strcpy(list5[j].book_name, list[i].book_name);
                       list5[j].pub_year=list[i].pub_year;
                       list5[j].available_copies=list[i].available_copies;
                       j++;
                       i++;
                   	
                   }
                   
                   i++;
                 }
                                                                
                 else
                 {
                 	 strcpy(list5[j].author, list[i-1].author);
                     strcpy(list5[j].book_name, list[i-1].book_name);
                     list5[j].pub_year=list[i-1].pub_year;
                     list5[j].available_copies=list[i-1].available_copies;
                     i=i+1;
                     
                     j++;
                 }
     }
     sort(list5,j);
}


// MERGE FUNCTION
int merge(struct book_record list1[], struct book_record list2[], int n, int m,  struct book_record list3[])
{
      int i=0,j=0, k=0;
      
       
       while((i<n)&&(j<m))
       {
	      if(strcmp(list1[i].author,list2[j].author)<0)
	      {
	            strcpy(list3[k].author,list1[i].author);
	            strcpy(list3[k].book_name,list1[i].book_name);
	            list3[k].pub_year=list1[i].pub_year;
	            list3[k].available_copies=list1[i].available_copies;
	            i++;
	            k++;
	      }
	      else
	      {
	          if(strcmp(list1[i].author,list2[j].author)==0)
	          {
	                if(strcmp(list1[i].book_name, list2[j].book_name)==0)
	                {
	                  if(list1[i].pub_year<list2[j].pub_year)
	                  {
	                         strcpy(list3[k].author,list1[i].author);
	                         strcpy(list3[k].book_name,list1[i].book_name);
	                         list3[k].pub_year=list1[i].pub_year;
	                         list3[k].available_copies=list1[i].available_copies;
	                         k++;
	                         i++;
	                         j++;
	                  }
	                  else //list1[j].pub_year<list2[i].pub_year
	                  {
	                         strcpy(list3[k].author,list2[j].author);
	                         strcpy(list3[k].book_name,list2[j].book_name);
	                         list3[k].pub_year=list2[j].pub_year;
	                         list3[k].available_copies=list2[j].available_copies;
	                         k++;
	                         i++;
	                         j++;
	                  }
	                }
	                else
	                {
	                    if(strcmp(list1[i].book_name, list2[j].book_name)<0)
	                    {
                           strcpy(list3[k].author,list1[i].author);
                           strcpy(list3[k].book_name,list1[i].book_name);
                           list3[k].pub_year=list1[i].pub_year;
                           list3[k].available_copies=list1[i].available_copies;
                           k++;
                           i++;
                    	}
	                    else //if(strcmp(list1[i].book_name, list2[j].book_name)>0)
	                    {
	                         strcpy(list3[k].author,list2[j].author);
	                         strcpy(list3[k].book_name,list2[j].book_name);
	                         list3[k].pub_year=list2[j].pub_year;
	                         list3[k].available_copies=list2[j].available_copies;
	                         k++;
	                         j++;
	                    }
	                }
	          }
	          if(strcmp(list1[i].author,list2[j].author)>0)
			  {
                    strcpy(list3[k].author,list2[j].author);
                    strcpy(list3[k].book_name,list2[j].book_name);
                    list3[k].pub_year=list2[j].pub_year;
                    list3[k].available_copies=list2[j].available_copies;
                    j++;
                    k++;

	          }
	      }
      }
       if(i<n)
       {
              while(i<n)
              {
                        strcpy(list3[k].author,list1[i].author);
                        strcpy(list3[k].book_name,list1[i].book_name);
                        list3[k].pub_year=list1[i].pub_year;
                        list3[k].available_copies=list1[i].available_copies;
                        k++;
                        i++;
               }
       }
       else   //if(j<m)
       {
              while(j<m)
              {
                        strcpy(list3[k].author,list2[j].author);
                        strcpy(list3[k].book_name,list2[j].book_name);
                        list3[k].pub_year=list2[j].pub_year;
                        list3[k].available_copies=list2[j].available_copies;
                        k++;
                        j++;
              }
       }
    printf("%d",k);

return k;
}

//LIST-INTERSECTION
int list_intersection(struct book_record list1[], struct book_record list2[], int n, int m,  struct book_record list3[])
{
       int i=0, j=0, k=0;
      
      
              while(i<n)
              {
                        j=search_record(list2, m, list1[i].book_name, list1[i].author);
                        if(j<m)
                        {
                                        if(list2[j].available_copies<list1[i].available_copies)
                                        {
                                                                                strcpy(list3[k].book_name,list2[j].book_name);
                                                                                strcpy(list3[k].author,list2[j].author);
                                                                                list3[k].pub_year=list2[j].pub_year;
                                                                                list3[k].available_copies=list2[j].available_copies;
                                                                                k++;
                                        }
                                        else 
                                        {
                                                                                strcpy(list3[k].book_name,list1[i].book_name);
                                                                                strcpy(list3[k].author,list1[i].author);
                                                                                list3[k].pub_year=list1[i].pub_year;
                                                                                list3[k].available_copies=list1[i].available_copies;
                                                                                k++;
                                        }
                                            
                        }
                        i++;
                        
              }

      
return k;
}

//LIST-DIFFERENCE FUNCTION
int list_diff(struct book_record list1[], struct book_record list2[], int n, int m, struct book_record list3[])
{

       int j=0,i=0, k=0;
       
       
       while(i<n)
       {
                 j=search_record(list2, m, list1[i].book_name, list1[i].author);
                 if(j>=m)
                 {
                         strcpy(list3[k].book_name,list1[i].book_name);
                         strcpy(list3[k].author,list1[i].author);
                         list3[k].pub_year=list1[i].pub_year;
                         list3[k].available_copies=list1[i].available_copies;
                         k++;
                }
                 i++;
       }
sort(list3, k);


return k;
}


//LIST-UNION FUNCTION
int list_union(struct book_record list1[], struct book_record list2[], int n, int m, struct book_record list3[])
{
       int k;
       sort(list1, n);
       sort(list2, m);
       k=merge(list1, list2, n, m, list3);
  return k;     
}

//LIST-SYMMETRIC-DIFFERENCE
int list_sym_diff(struct book_record list1[], struct book_record list2[], int n, int m,  struct book_record list3[])
{
       int p, q, k;

       struct book_record list4[N_SIZE],list5[N_SIZE];
       
       p=list_diff(list1, list2, n, m, list4);
                          
       q=list_diff(list2, list1, m, n, list5);
       
       k=merge(list4, list5, p,q, list3);
       return k;
}


main()
{
    char book_name[100], author[100];
    struct book_record list[N_SIZE], list1[N_SIZE], list2[N_SIZE], list3[Z_SIZE], list4[N_SIZE], list5[N_SIZE];
    int pub_year, available_copies, contd=1, done, choice, count, n=0,m=0, opt, t=2,flag1, k, i;    //'done'-to know the status of operation, 'contd'-to knw if user want to contd on same list.
    
    
    initialize(list1);
    initialize(list2);
    initialize(list3);
    initialize(list4);
    initialize(list5);
                                              
    printf("enter the operation to be executed\n");
    printf("Please select one from the options given below:\n");
	printf("1  - Insert a entry into the record.\n");
	printf("2  - Delete a entry from the record.\n");
	printf("3  - To get the number of active record.\n");
	printf("4  - To check if the list is empty.\n");
	printf("5  - To check if the list is full.\n");
	printf("6  - To get topmost book author.\n");
	printf("7  - To remove duplicates from the record.\n");
	printf("8  - To get Union of two lists.\n");
	printf("9  - To get Intersection of two lists.\n");
	printf("10 - To get the Difference of two lists.\n");
	printf("11 - To get the Symmetric Difference of two lists.\n");
	printf("12 - To display list1\n");
	printf("13 - To display list2\n");
	printf("14 - To exit the program.\n");
    scanf("%d", &choice);
    while(choice!=14)
    {
    switch(choice)
    {
                  case 1:     //insert function
                        {		
                        		printf("\nInsert\n");
                        		printf("Which list is to be operated?\n 1.list1\n2.list2\n");
                                scanf("%d",&opt);                    //list which is to be operated is selected
                                
                                
                                                  printf("Enter book name:");
                                                  getchar();
                                                  gets(book_name);
                                                  printf("Enter author name:");
                                                  gets(author);
                                                  getchar();
                                                  printf("Enter publication year:");
                                                  scanf("%d", &pub_year);
                                                  printf("Enter available copies");
                                                  scanf("%d", &available_copies);
                                                  
                                                  if(opt==1)
                                                  {
                                                            n=n+1;
                                                            done=insert(list1,n ,book_name, author, pub_year, available_copies);
                                                  }
                                                  else     //opt==2
                                                  {
                                                            m=m+1;
                                                            done=insert(list2, m, book_name, author, pub_year, available_copies);
                                                  }
                                                            
                                                  if(done==1)
                                                  {
                                                             printf("successfull\n");
                                                  }
                                                  else
                                                  {
                                                      printf("not successfull\n");
                                                  }
                                                    
                        
                        }    // case1 ends
                        break;
                        
                        case 2:    //delete function
						{
							printf("\nDelete\n");
                        	printf("Which list is to be operated?\n 1.list1\n2.list2\n");
                            scanf("%d",&opt);
							printf("enter the details of the record to be deleted-\n");
							printf("author name:");
							getchar();
							gets(author);
							printf("\nbook:");
							gets(book_name);
							
							if(opt==1)
                                                  {
                                        
                                                            done=delete_record(list1,n ,author, book_name);
                                                            flag1=1;
    
                                                  }
                                                  else     //opt==2
                                                  {
                                                            
                                                            done=delete_record(list2, m, author, book_name);
                                                            flag1=2;
                                                  }
                                                            
                                                  if(done==1)
                                                  {
                                                             printf("\nSuccessfull\n");
                                                             if(flag1==1)
                                                             {
                                                             	n=n-1;
                                                             }
                                                             else
                                                             {
                                                             	m=m-1;
                                                             }
                                                  }
                                                  else    //done==0
                                                  {
                                                      printf("\nNot successfull\n");
												  }
                                                      sort(list1, N_SIZE);
                                                      break;
							
						}  
						
						    case 3:            //active records function
							{
							   	printf("\nfinding active records:\n");
							   	if(opt==1)
							    {
						   	        printf("\nThe numberof active records in list1=%d",n);
						        }
							    if(opt==2)
							    {
							    	printf("\nThe numberof active records in list2=%d",m);
							    }
							    break;
							}  
				                            
                                                  
                                             
                                                  
                                case 4:     //is-empty function
                                	{
                                		printf("\nis-empty function:\n");
                                		if(opt==1)
                                                  {
                                        
                                                            is_empty(list1);
                                                            
                                                  }
                                                  else     //opt==2
                                                  {
                                                            
                                                            is_empty(list2);
                                                  }
                                    break;
                                		
                                	}
                                	case 5:     ///is-full function
                                		{
                                			printf("\nIs-full function:\n");
                                			if(opt==1)
                                                  {
                                        
                                                            isFull(list1);
                                                     
                                                  }
                                                  else     //opt==2
                                                  {
                                                            
                                                            isFull(list2);
                                                  }
                                    break;
                                			
                                		}
                                		
                                		case 6:          //getTopMostBookAuthor function
                                			{
                                				printf("\ntop most author function:\n");
                                				printf("\nenter the book name:");
                                				getchar();
                                				gets(book_name);
                                			
                                				if(opt==1)
                                                  {
                                        
                                                            getTopMostBookAuthor(list1,n,book_name);
                                                            
                                                  }
                                                  else     //opt==2
                                                  {
                                                            
                                                            getTopMostBookAuthor(list2,m,book_name);
                                                  }
                                                  
                                                  break;
                                			}
                                			
                                		case 7:           //is-unique function
                                			{
                                				printf("\nis-unique function:\n");
                                				for(i=0;i<3;i++)
                                				{
                                					
                                				  printf("Enter book name:");     //give space n then write input to be given
                                                  getchar();
                                                  gets(list4[i].book_name);
                                                  printf("Enter author name:");
                                                  //getchar();
                                                  gets(list4[i].author);
                                                  printf("Enter publication year:");
                                            
                                                  scanf("%d", &list4[i].pub_year);
                                                  printf("Enter available copies");
                                                  getchar();
                                                  scanf("%d", &list4[i].available_copies);
                                					
                                				}
                                				sort(list4,3);
                                				
                                				
                                				printf("\nlist5:\n");
                                			
                                				list_unique(list4,3, list5);
                                				display(list5,3);
                                				
                                                 break;
                                				
                                			}
                                			
                                		case 8:      //list-union function
                                			{
                                				printf("\nlist-union function:\n");
                                				k=list_union(list1,list2,n,m,list3);
                                			
                                				printf("list-3");
                                				getchar();
                                				display(list3,k);
                                				break;
                                				
                                			}
                                		case 9:   //list-intersection function
                                		{
                                			printf("\nlist-intersection:\n");
                                			k=list_intersection(list1,list2,n,m,list3);
                                				printf("list-3");
                                				printf("%d",k);
                                				display(list3,k);
                                				break;
                                				
                                			
                                		}
                                		
                                		case 10:     //list-difference
                                			{
                                				printf("\nlist difference function:\n");
                                				k=list_diff(list1,list2,n,m,list3);
                                				printf("list-3");
                                				display(list3,k);
                                				break;
                                				
                                			}
                                	 case 11:
                                	 	{
                                	 		printf("list sym difference function\n");
                                	 		k=list_sym_diff(list1,list2,n,m,list3);
                                				printf("list-3");
                                				display(list3,k);
                                				break;
                                	 		
                                	 	}
                                	 	
                                	case 12:
                                		{
                                			printf("\nlist-1");
                                			display(list1,N_SIZE);
                                			break;	
                                			
                                		}
                                	case 13:
                                		{
                                			printf("\nlist-2");
                                			display(list2,N_SIZE);
                                			break;
                                		}
                                			
                                		
                                			
                                	 default:
                                        {
                                                  break;
                                        }
                                    }
    
                                                
                                                          
    printf("Enter the operation to be performed:");
    scanf("%d",&choice);
    }
    if(choice==14)
    {
    	printf("Program is over!");
    }


                                                  
    getch();
}

                                                  

       
       
       


                         
                        
                  
       
       
       
        
                                                                                
                                             
                                                                                           
                                        
                                        
                        
       

                   

                        
                        
              
                                                                                     
                                                                                     
                                                                                     
                                                                                     
                                                                                     
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                                                                   
                                                                                                               
                                                                                                                                               
                                                                                                               
                                                                                                               
                                                                                                              
                                                                                                              
                                                                                                                                                 
                                                                                                                                                  
                                                                                                                                                         
                                                                                                      

     
                        
                                            
                                            
                                            




     
  
    

           
         

                                 
     

       
