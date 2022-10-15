#include <stdio.h> 
// #include <stdbool.h>
#include <stdlib.h>
#include <math.h> 

#define true 1;
#define false 0;


int check_in_area(int i_point, int j_point)
{
    int i_centre = 10;
    int j_centre = 10;        

    double dist = sqrt((i_centre - i_point)*(i_centre - i_point) + (j_centre - j_point)*(j_centre - j_point));

    if(dist > 5 && dist <= 10)    
    {
        return true; 
    }
    else
        return false;
}

int testCheck_in_area() 
{
    if(check_in_area(10, 10))
        return false;    

    return true;
}

int min(int num1, int num2) 
{
    if(num1 <= num2)
    {
        return num1; 
    }
    else
        return num2;
}

int test_min()
{
    if(min(3, 9) == 3)
        if(min(-5, -1) == -5)
            if(min(1, 1) == 1)
                return true;
    
    return false;
}

int max(int num1, int num2, int num3) 
{
    if(num1 >= num2 && num1 >= num3)             
        return num1;
    
    if(num2 >= num1 && num2 >= num3)
        return num2;
             
    return num3;
}

int test_max()
{
    if(max(1, 2, 3) == 3)
    {
        if(max(1, 1, 1) == 1)
            return true;
    }   
    
    return false;
}


int sign(int num)
{
    if(num > 0)
        return 1; 

    if(num == 0)
        return 0; 
    
    return -1;  
}

int test_sign()
{
    if(sign(5) == 1)
        if(sign(0) == 0)
            if(sign(-5) == -1)
                return true;

    return false;
}

int i_increase(int i, int j, int k, int l)
{
    return (min(i + j, i + l) * (k + 1))%30;
}

int test_i_increase()
{
    if(i_increase(0, 10, 3, 10) != 10)
        return false; 
    
    return true;
}

int j_increase(int j, int i, int k, int l)
{
    return j + ((l * sign(j))%20) + ((k * sign(i))%10);
}

int test_j_increase()
{
    if(j_increase(0, 1, 20, 1) != 0)
        return false; 
    
    return true;
}

int l_increase(int l, int i, int j)
{
    return (max(i*j, i*l, j*l))%30;
}

int test_l_increase()
{
    if(l_increase(30, 1, 1) != 0)
        return false; 
    
    return true;
}

int test_general()
{
    if(test_min())
        if(test_max())    
            if(test_sign())    
                if(testCheck_in_area())
                    if(test_i_increase())
                        if(test_j_increase())
                            if(test_l_increase())
                                return true;
    
    return false;
}

int lab9(int i, int j, int l) 
{
    if(test_general())
    {   
        int k = 0;
        while(k <= 50)
        {
            if(check_in_area(i, j))
            {
                printf("i = %d; j = %d; l = %d\nk = %d;\n", i, j, l, k);
                printf("Popal\n");
                return 1;                
            }
            
            //printf("i = %d j = %d l = %d\n", i, j, l);

            i = i_increase(i, j, k, l);
            j = j_increase(j, i, k, l);
            l = l_increase(l, i, j);
            
            k++;
        }
        printf("i = %d; j = %d; l = %d\nk = %d;\n", i, j, l, k);
        printf("NE Popal\n");
        return 0;
    }
    else
    {    
        printf("Жопа\n");;    
        return -1;
    }
}


int main()
{   
    int i = 26;
    int j =  8;
    int l = -3;
    
    lab9(i, j, l);

    return 0;
}
