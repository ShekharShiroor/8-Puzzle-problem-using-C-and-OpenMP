#include <iostream>
#include<omp.h>
using namespace std;

int Global_flag=0;

class puzzle
{
  public:
  int pz[3][3],goal[3][3];

  friend class ptree;
  void tree(puzzle ,int );
  void start(int[3][3] ,int[3][3] );

  puzzle()
  {
      for(int i=0;i<3;i++)
      {
          for(int j=0;j<3;j++)
          {
              goal[i][j]=(i*3)+j;
              pz[i][j]=0;
          }
      }

  }
};

/*class ptree
{
  public:
  friend class puzzle;
  void tree(puzzle );
};*/

void puzzle::start(int root[3][3],int goal1[3][3])
{


}

void puzzle::tree(puzzle root,int thread=0)
{
	if(Global_flag==1)
	{
		return;
	}
	int flag=0,posi,posj;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(root.pz[i][j] == 0)
			{
				posi = i;
				posj = j;
			}
		}
	}


    for(int i=0;i<3;i++)
      {
          for(int j=0;j<3;j++)
          {
              if(root.goal[i][j]!=root.pz[i][j])
              {
                  flag=1;
                  break;
              }

          }
          if(flag==1)
              {
                  break;
              }
      }

    if(flag == 0)
    {
    	cout<<"Solution found by thread :- "<<thread<<"\n";
    	Global_flag=1;
    	return;
    }


    //Logic for placeholder

    if(posi == 1 && posj == 1)
    {
       #pragma omp parallel
    	{
    		#pragma omp for nowait
    		
    		    for(int i=0;i<4;i++)
    		    {
    		        if(i==0)
    		        {
    		            puzzle temp = root;
    		            int numtemp=temp.pz[posi][posj];
    		            temp.pz[posi][posj]=temp.pz[posi][posj+1];
    		            temp.pz[posi][posj+1]=numtemp;
    		            tree(temp,i);
    		        }
    		        if(i==1)
    		        {
    		            puzzle temp = root;
    		            int numtemp=temp.pz[posi][posj];
    		            temp.pz[posi][posj]=temp.pz[posi][posj-1];
    		            temp.pz[posi][posj-1]=numtemp;
    		            tree(temp,i);
    		        }
    		        if(i==2)
    		        {
    		            puzzle temp = root;
    		            int numtemp=temp.pz[posi][posj];
    		            temp.pz[posi][posj]=temp.pz[posi+1][posj];
    		            temp.pz[posi+1][posj]=numtemp;
    		            tree(temp,i);
    		        }
    		        if(i==3)
    		        {
    		            puzzle temp = root;
    		            int numtemp=temp.pz[posi][posj];
    		            temp.pz[posi][posj]=temp.pz[posi-1][posj];
    		            temp.pz[posi-1][posj]=numtemp;
    		            tree(temp,i);
    		        }
    		    }
    		
    	}
    }



   else if(posi == 0 && posj == 0)
    {
       #pragma omp parallel
    	{
    		#pragma omp for nowait
    		
    		    for(int i=0;i<2;i++)
    		    {
    		        if(i==0)
    		        {
    		            puzzle temp = root;
    		            int numtemp=temp.pz[posi][posj];
    		            temp.pz[posi][posj]=temp.pz[posi][posj+1];
    		            temp.pz[posi][posj+1]=numtemp;
    		            tree(temp,i);
    		        }
    		        if(i==1)
    		        {
    		            puzzle temp = root;
    		            int numtemp=temp.pz[posi][posj];
    		            temp.pz[posi][posj]=temp.pz[posi+1][posj];
    		            temp.pz[posi+1][posj]=numtemp;
    		            tree(temp,i);
    		        }

    		    }
    		
    	}
    }



  else if(posi == 2 && posj == 2)
    {
       #pragma omp parallel
    	{
    		#pragma omp for nowait
    		
    		    for(int i=0;i<2;i++)
    		    {
    		        if(i==0)
    		        {
    		            puzzle temp = root;
    		            int numtemp=temp.pz[posi][posj];
    		            temp.pz[posi][posj]=temp.pz[posi][posj-1];
    		            temp.pz[posi][posj-1]=numtemp;
    		            tree(temp,i);
    		        }
    		        if(i==1)
    		        {
    		            puzzle temp = root;
    		            int numtemp=temp.pz[posi][posj];
    		            temp.pz[posi][posj]=temp.pz[posi-1][posj];
    		            temp.pz[posi-1][posj]=numtemp;
    		            tree(temp,i);
    		        }

    		    }
    		
    	}
    }

   else if(posi == 0 && posj == 2)
    {
       #pragma omp parallel
    	{
    		#pragma omp for nowait
    		
    		    for(int i=0;i<2;i++)
    		    {
    		        if(i==0)
    		        {
    		            puzzle temp = root;
    		            int numtemp=temp.pz[posi][posj];
    		            temp.pz[posi][posj]=temp.pz[posi][posj-1];
    		            temp.pz[posi][posj-1]=numtemp;
    		            tree(temp,i);
    		        }
    		        if(i==1)
    		        {
    		            puzzle temp = root;
    		            int numtemp=temp.pz[posi][posj];
    		            temp.pz[posi][posj]=temp.pz[posi+1][posj];
    		            temp.pz[posi+1][posj]=numtemp;
    		            tree(temp,i);
    		        }

    		    }
    		
    	}
    }


  else if(posi == 2 && posj == 0)
    {
       #pragma omp parallel
    	{
    		#pragma omp for nowait
    		
    		    for(int i=0;i<2;i++)
    		    {
    		        if(i==0)
    		        {
    		            puzzle temp = root;
    		            int numtemp=temp.pz[posi][posj];
    		            temp.pz[posi][posj]=temp.pz[posi][posj+1];
    		            temp.pz[posi][posj+1]=numtemp;
    		            tree(temp,i);
    		        }
    		        if(i==1)
    		        {
    		            puzzle temp = root;
    		            int numtemp=temp.pz[posi][posj];
    		            temp.pz[posi][posj]=temp.pz[posi-1][posj];
    		            temp.pz[posi-1][posj]=numtemp;
    		            tree(temp,i);
    		        }

    		    }
    		
    	}
    }




    else if(posi == 0 && posj == 1)
    {
       #pragma omp parallel
    	{
    		#pragma omp for nowait
    		
    		    for(int i=0;i<3;i++)
    		    {
    		        if(i==0)
    		        {
    		            puzzle temp = root;
    		            int numtemp=temp.pz[posi][posj];
    		            temp.pz[posi][posj]=temp.pz[posi][posj+1];
    		            temp.pz[posi][posj+1]=numtemp;
    		            tree(temp,i);
    		        }
    		        if(i==1)
    		        {
    		            puzzle temp = root;
    		            int numtemp=temp.pz[posi][posj];
    		            temp.pz[posi][posj]=temp.pz[posi][posj-1];
    		            temp.pz[posi][posj-1]=numtemp;
    		            tree(temp,i);
    		        }
    		        if(i==2)
    		        {
    		            puzzle temp = root;
    		            int numtemp=temp.pz[posi][posj];
    		            temp.pz[posi][posj]=temp.pz[posi+1][posj];
    		            temp.pz[posi+1][posj]=numtemp;
    		            tree(temp,i);
    		        }

    		    }
    		
    	}
    }



    else if(posi == 2 && posj == 1)
    {
       #pragma omp parallel
    	{
    		#pragma omp for nowait
    		
    		    for(int i=0;i<3;i++)
    		    {
    		        if(i==0)
    		        {
    		            puzzle temp = root;
    		            int numtemp=temp.pz[posi][posj];
    		            temp.pz[posi][posj]=temp.pz[posi][posj+1];
    		            temp.pz[posi][posj+1]=numtemp;
    		            tree(temp,i);
    		        }
    		        if(i==1)
    		        {
    		            puzzle temp = root;
    		            int numtemp=temp.pz[posi][posj];
    		            temp.pz[posi][posj]=temp.pz[posi][posj-1];
    		            temp.pz[posi][posj-1]=numtemp;
    		            tree(temp,i);
    		        }
    		        if(i==2)
    		        {
    		            puzzle temp = root;
    		            int numtemp=temp.pz[posi][posj];
    		            temp.pz[posi][posj]=temp.pz[posi-1][posj];
    		            temp.pz[posi-1][posj]=numtemp;
    		            tree(temp,i);
    		        }

    		    }
    		
    	}
    }



   else if(posi == 1 && posj == 0)
    {
       #pragma omp parallel
    	{
    		#pragma omp for nowait
    		
    		    for(int i=0;i<3;i++)
    		    {
    		        if(i==0)
    		        {
    		            puzzle temp = root;
    		            int numtemp=temp.pz[posi][posj];
    		            temp.pz[posi][posj]=temp.pz[posi][posj+1];
    		            temp.pz[posi][posj+1]=numtemp;
    		            tree(temp,i);
    		        }
    		        if(i==1)
    		        {
    		            puzzle temp = root;
    		            int numtemp=temp.pz[posi][posj];
    		            temp.pz[posi][posj]=temp.pz[posi+1][posj];
    		            temp.pz[posi+1][posj]=numtemp;
    		            tree(temp,i);
    		        }
    		        if(i==2)
    		        {
    		            puzzle temp = root;
    		            int numtemp=temp.pz[posi][posj];
    		            temp.pz[posi][posj]=temp.pz[posi-1][posj];
    		            temp.pz[posi-1][posj]=numtemp;
    		            tree(temp,i);
    		        }

    		    }
    		
    	}
    }

   else if(posi == 1 && posj == 2)
    {
       #pragma omp parallel
    	{
    		#pragma omp for nowait
    		
    		    for(int i=0;i<3;i++)
    		    {
    		        if(i==0)
    		        {
    		            puzzle temp = root;
    		            int numtemp=temp.pz[posi][posj];
    		            temp.pz[posi][posj]=temp.pz[posi][posj-1];
    		            temp.pz[posi][posj-1]=numtemp;
    		            tree(temp,i);
    		        }
    		        if(i==1)
    		        {
    		            puzzle temp = root;
    		            int numtemp=temp.pz[posi][posj];
    		            temp.pz[posi][posj]=temp.pz[posi+1][posj];
    		            temp.pz[posi+1][posj]=numtemp;
    		            tree(temp,i);
    		        }
    		        if(i==2)
    		        {
    		            puzzle temp = root;
    		            int numtemp=temp.pz[posi][posj];
    		            temp.pz[posi][posj]=temp.pz[posi-1][posj];
    		            temp.pz[posi-1][posj]=numtemp;
    		            tree(temp,i);
    		        }

    		    }
    		
    	}
    }




}

int main()
{

   puzzle obj,root;
  // ptree new_obj;
   cout<<"\n\nGoal State is :- \n";
   for(int i=0;i<3;i++)
   {
       for(int j=0;j<3;j++)
       {
           cout<<obj.goal[i][j]<<" ";
       }
       cout<<"\n";
   }


   {
       obj.pz[0][0] = 1;
       obj.pz[0][1] = 3;
       obj.pz[0][2] = 2;
       obj.pz[1][0] = 0;
       obj.pz[1][1] = 5;
       obj.pz[1][2] = 4;
       obj.pz[2][0] = 7;
       obj.pz[2][1] = 6;
       obj.pz[2][2] = 8;

   }

   cout<<"\n Start State is :- \n";

   for(int i=0;i<3;i++)
   {
       for(int j=0;j<3;j++)
       {
           cout<<obj.pz[i][j]<<" ";
       }
       cout<<"\n";
   }
    root=obj;
   //obj.start(obj.pz,obj.goal);
   obj.tree(root);

   return 0;
}
