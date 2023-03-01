#Exporting The Library RWeka  
library("RWeka")  

#Checking wether the path has been set Or Not 
getwd()  
setwd("C:\\Users\\gaura\\OneDrive\\Pictures\\Screenshots\\Documents\\semester 6\\dm lab")
getwd()
#Assigning The Values With Concatination And Compilation Operations  
UID<- 1:5 
NAME<-c('Rahul','Sham','Ram','Rohit','Geeta') 
AGE<-c(21,21,20,19,21) 
GENDER<-c('M','M','M','M','F') 
SECTION<-c(54,54,54,54,54) 
COURSE<-c('CSE','CSE','CSE','CSE','CSE') 
SUBJECT1<-c(95,94,84,89,90) 
SUBJECT2<-c(94,94,84,89,92) 
SUBJECT3<-c(93,94,82,92,93) 
TOTAL<-SUBJECT1+SUBJECT2+SUBJECT3 

stud_data <- data.frame(UID,NAME,AGE,GENDER,SECTION,COURSE,SUBJECT1,SUBJECT2,SUBJECT3,TOTAL,stringsAsFactors = FALSE) 
stud_data 

#print the data saved in the structured form of the experiment   
print(stud_data)  
#print the datatype of the data saved in the tabular form  
print(class(stud_data))  
print(str(stud_data))  

#Now Reading and Writing The Data In The .arff file  #Full Form of .arff file is attribute relation file format   
write.arff(stud_data,"experiment2.arff")  
#Reading the Data From The .arff File Saved At The Location Set In The Folder   
N=read.arff("experiment2.arff")
print(N)  


#Performing The Stastical And Simple And Complex Calculations On The Data Saved In The Structured Form   

#To Show The Maximum Element Of That Particular Attribute  
max(N["SUBJECT1"])  
#To Find The Minimum Element Of That Particular Attribute   
min(N["SUBJECT1"])  
#To Find The Sum Of Each Instance In The Attribute   
sum(N["SUBJECT1"])  

#Statsical Functions Such As Mean,Median,Mode And Standard Deviation   
mean(SUBJECT1)  
median(SUBJECT1)  
sd(SUBJECT1) 
