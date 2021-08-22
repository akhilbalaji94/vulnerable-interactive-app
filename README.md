# HOW-TO EXPLOIT MOVIE RENTAL PROGRAM
Description: The program simulates a movie rental service which requires logging in, choosing an available movie and have the amount added to your total dues. The owner can login only to set the availability of a movie whereas the user can only rent a movie and will be charged the respective amount.

1.	Gaining access to owner account
Finding the stack entry for the authentication variable
 ![image](https://user-images.githubusercontent.com/16291248/130363833-c6f8e32f-885d-4bd5-b536-0c22f6cdb663.png)

Overflowing the buffer of userinput to overwrite auth variable to gain access to owner account
 ![image](https://user-images.githubusercontent.com/16291248/130363837-0c1508ad-9efc-46ab-b6fb-54402b16f25a.png)

2.	Gaining access to user account
Similarly access can be gained to user account
![image](https://user-images.githubusercontent.com/16291248/130363843-b4d9918c-3098-4298-aeb6-e46c924d8b37.png)

3.	Rent a movie and then reset dues to 0
Finding the stack entry for the checkout variable
 ![image](https://user-images.githubusercontent.com/16291248/130363845-65627c3b-2675-4f59-99af-a561c2e1a7e9.png)



Overwriting the checkout variable repeatedly which causes an integer overflow.

 ![image](https://user-images.githubusercontent.com/16291248/130363858-df445809-88aa-4da6-9924-9e7bf4033977.png)
![image](https://user-images.githubusercontent.com/16291248/130363864-b10968cc-34a8-446c-b678-eeeba742b372.png)
![image](https://user-images.githubusercontent.com/16291248/130363869-b1fd2f84-c2d6-4bc0-be60-740e545302e6.png)
![image](https://user-images.githubusercontent.com/16291248/130363870-4a3f39d5-e094-4e71-a454-239200db5cf7.png)


 
 

 
