#include <stdio.h>

int main()
{
	int size,arr[50],option,num,pos;

	printf("\nEnter the size of the array :");
	scanf("%d", &size);

	printf("\nEnter the elements : ");
	for(int i=0;i<size;i++)
	{
		printf("\nEnter %d element :",i);
		scanf("%d",&arr[i]);
	}
	

	do
	{
		printf("\n **********Enter the operation you want to perfor5m in the array**********");
		printf("\n 1.Inserion");
		printf("\n 2.Deletion");
		printf("\n 3.Display");
		printf("\n 4.Exit\n");

		scanf("\n%d",&option);

		switch(option)
		{
			case 1:
			printf("\n Enter the number you want to insert : ");
			scanf("%d",&num);

			printf("\n Enter the position you want to insert : ");
			scanf("%d",&pos);


			for(int i=size;i>pos-1;i--)
			{
				arr[i]=arr[i-1];
			}
			arr[pos-1]=num;
			size++;

			printf("\nYour new array is :");
			for(int j=0;j<size;j++)
			{
				printf("\t%d",arr[j]);
			}
			break;

			case 2:
			printf("\n Enter the position you want to delete the element : ");
			scanf("%d",&pos);

			for(int i=pos-1;i<size;i++)
			{
				arr[i]=arr[i+1];
			}
			size--;
			printf("\nYour new array is :");
			for(int j=0;j<size;j++)
			{
				printf("\t%d",arr[j]);
			}
			break;

			case 3:
			printf("\nYour array is :");
			for(int i=0;i<size;i++)
			{
				printf("\t%d",arr[i]);
			}
			break;

		}


	}while(option != 4);
}