# Data-Structures
This includes all the project done in Data Structure class

The data that we are going to be analyzing and querying are data about the amount of people 
who travelled in a specific year from the year 1970 up until 2021 split into multiple regions and 
countries. Each row in the data set given contains a country or a region name along with the 
specific unique country code. This is followed by the number of people/population that travelled 
from year 1970 to 2021 (51 years of data). At the last column we have the total of the 51 years.  
 
There are multiple queries that can be performed once this data is stored. The following are the 
various query options and their explanation.  
 
- C countryCode –  
o Option C followed by the country code will display the entire row with all the 
information and the total.  
- K kthNumber –  
o Option K followed by the kth index position would return the kth largest total 
row. This would require to temporarily sort the data with respect to the sumTotal 
and find the kth largest total record/row.  
- T countryCode year –  
o Option T followed by the country code and the year would return the number of 
people who travelled and this has to be displayed.  
- A year minTravelNum maxTravelNum –  
o Option A followed by the year, min number of people and max number of people 
would return all the country codes that fall under this range for the given year.

Data file (dataInput1.txt):  
o The first number is the number of records in the data file.  
o This is in txt format and contains the country name, country code followed by 51 
numbers (number of people who travelled from 1970 to 2021) and finally the total 
number of people who travelled.  

Query file (queryInput1):  
o This starts with the number of queries to be performed.  
o Following are the various characters that each correspond to a specific query to be 
performed.  
o Appropriate queries have their corresponding parameters.
