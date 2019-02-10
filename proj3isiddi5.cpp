/*
 * Project 4: Trinity Game
 */
#include<stdio.h>

#include <string.h>
#include <fstream>
#include <stdlib.h>

using namespace std;

// Display your identifying information (Name, lab day and time)
void displayIdentifyingInformation()
{
    printf("Author: Mohamed Imran Mohamed Siddique \n");
    
    printf("Class: CS 141, Spring 2016 \n");
    
    printf("Program #3: Decipher  \n");
    
    printf("System: XCode on Mac \n");
    
    printf(" \n");
}

void displayIdentifyingInstruction()
{
    printf("Choose from the following options: \n");
    
    printf("\t 1. Encode some text \n");
    
    printf("\t 2. Decode using user-entered values \n");
    
    printf("\t 3. Decode automatically \n");
    
    printf("\t 4. Exit program \n");
    
    printf(" \n");
}

int main(){
    const int NUM_ELEMENTS = 81;
    char userInput[ NUM_ELEMENTS];
    
    char tranposed[ NUM_ELEMENTS];
    char opposite[ NUM_ELEMENTS];
    char reverseTranposed[ NUM_ELEMENTS];
    int i;
    int direction;
    int transpose;
    int choice;
    long long int stringSize = 0;
    char returnChar;
    std::ifstream inStream;
    int position = 0;
    int array_size = 34840;
    char * array = new char[array_size];
    int transposisitonNumber = 0;

    // display identifying information
    displayIdentifyingInformation();
    
    // display instructions
    displayIdentifyingInstruction();
    
    printf("Enter number: ");
    scanf("%d%c", &choice, &returnChar);

    if (choice==1){
    printf("Enter the text to be encoded: ");
    fgets(userInput, 80, stdin);
        
    stringSize=strlen(userInput);
    
    printf("Enter direction (1 Forwards or 2 Reverse): ");
    scanf("%d", &direction);
    
    printf("Enter transposition value: ");
    scanf("%d", &transpose);
    
    if (direction==1){
        for (i=0;i<stringSize-1;i++){
            if ((userInput[i]+(transpose))<32){
                tranposed[i]=((userInput[i]+(transpose)))+95;
            }
            else if ((userInput[i]+(transpose))>126){
                tranposed[i]=((userInput[i]+(transpose)))-95;
            }
            else (tranposed[i]=((userInput[i]+(transpose))));
            
            
            
            //tranposed[i]=((userInput[i]+(transpose)));
        }
        printf("Original and changed text are:\n");
        printf("%s", userInput);
        printf("%s\n", tranposed);
        printf("Done.\n");
    }
    else if (direction==2){
        for(i=0;i<strlen(userInput);i++)
        {
            opposite[i]=userInput[strlen(userInput)-i-1];
        }
        for (i=0;i<stringSize;i++){
            reverseTranposed[i]=opposite[i]+(transpose);
        }
        printf("Original and changed text are: ");
        printf("%s", opposite);
        printf("%s \n",reverseTranposed);
        printf("\n");
        printf("Done.\n");

    }
    else {
        printf("The value is not valid\n");
        return 0;
    }}
    else if (choice==2){
        printf("Enter the text to be decoded: ");
        fgets(userInput, 80, stdin);
        
        printf("Enter transposition value: ");
        scanf("%d", &transpose);
        
        for (i=0;i<strlen(userInput);i++){
            tranposed[i]=userInput[i]+(transpose);
        }
        
        for(i=0;i<strlen(tranposed);i++)
        {
            opposite[i]=tranposed[strlen(tranposed)-i-1];
        }
        
        printf("Original and changed text are:\n");
        printf("%s", userInput);
        printf("%s   <-- Forwards\n", tranposed);
        printf("%s   <-- Reverse\n", opposite);
        printf("Done.\n");
    }
    else if (choice==3){
        printf("Enter the text to be decoded: ");
        fgets(userInput, 80, stdin);
        
        
                inStream.open( "dictionaryMax6.txt");
        if(inStream.is_open())
        {
            for (transposisitonNumber = 0; transposisitonNumber <= 95; transposisitonNumber++)
            {
            
                for (i=0;i<strlen(userInput);i++){
                    tranposed[i]=userInput[i]-(transposisitonNumber);
                }
                
                printf("transposisitonNumber: %d\n", transposisitonNumber);
                printf("%s", userInput);
                printf("%s\n", tranposed);
            }

           
            //this loop run until end of file (eof) does not occur
            while(!inStream.eof() && position < array_size)
            {
                inStream.get(array[position]); //reading one character from file to array
                position++;
            }
            array[position-1] = '\0'; //placing character array terminating character
            char * pch;
            
            
            pch = strtok (userInput," ");
            while (pch != NULL)
            {
                pch = strtok (NULL, " ");
                if  (strstr(&array[position],pch) != NULL) {
                    printf(" %s: word is found\n",pch);
                }
                else {printf("%s: Word wasn't found \n", pch);}
            
        }
       
    }
    }
    
}//end main()
