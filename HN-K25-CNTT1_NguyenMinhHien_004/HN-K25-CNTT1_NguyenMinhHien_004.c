#include <stdio.h>
#include <stdlib.h>
#define MAXARRAY 100
int main(){
	
	int i, j, k,f, l,choice; 
	int index, currentIndex = 0, currentIndex1 =0;
	int arr[MAXARRAY], arrCurrent[MAXARRAY];
	int left, right , mid;
	int hasChoice = 0;
	int sum = 0;
	int average;
	
	int min, minIndex;
	int temp;
	int value;
	int change =0;
	int found;
	int count;
	int exist;
	
	int deleteIndex;
	int addNumber;
	

	
	int searchValue;

do{
	printf("\n\t***************MENU*******************\n");
	printf("\t1. Nhap gia tri phan tu(n nhap tu ban phim)\n");
	printf("\t2. In ra \n");
	printf("\t3. In ra cac so lon hon trung binh cac phan tu\n");
	printf("\t4. In ra Gia tri nho nhat cua cac phan tu trong mang\n");
	printf("\t5. Them 1 phan tu vao dau mang\n");
	printf("\t6. Xoa phan tu tai vi tri cu the\n");
	printf("\t7. Sap xep mang theo thu tu tang dan\n");
	printf("\t8. Tim keim cac phan tu trong mang\n");
	printf("\t9. In ra cac phan tu Xuat Hien 2 lan trong mang\n");
	printf("\t10. In ra so lan xuat hien cua phan tu\n");
	printf("\t11. thoat \n");
	printf("\tLUA CHON CUA BAN: ");
	scanf("%d", &choice);	
	switch (choice){
		case 1 :
			printf("nhap kich thuoc phan tu trong mang: ");
			do{
				fflush(stdin);
				scanf("%d", &index);
				if(index<=0){
					printf("Loi ! Vui long nhap lai: ");
				}
			}while(index <= 0);
			printf("nhap gia tri trong mang: \n");
			for(i =0 ; i < index;i++){
				printf("Array[%d] = ",currentIndex );
				scanf("%d", &arr[currentIndex]);
				currentIndex++;
			}
			hasChoice = 1;
			break;
		case 2 : 
			if(hasChoice){
				printf("\t---VAY MANG LA---\n");
				for(i = 0; i < currentIndex; i++){
					printf("\t%5d", arr[i]);
				}
			}else{
				printf("Vui long nhap so phan tu cua mang truoc !");
			}
			break;
		case 3:
			if(hasChoice){
				for(i = 0; i < currentIndex;i++ ){
					sum += arr[i];
				}
				average = sum/currentIndex;
				printf("\n");
				printf("\t---VAY CAC SO LON HON TRUNG BINH CONG LA : ");
				for(i= 0; i < currentIndex;i++){
					if(arr[i] > average){
						printf("\t%5d", arr[i]);
					}
				}
			}else{
				printf("Vui long nhap so phan tu cua mang truoc !");
			}
			break;
		case 4:
			if(hasChoice){
			printf("\t---VAY GIA TRI NHO NHAT LA : ");
			min = arr[0];
			for(i= 1; i < currentIndex;i++){
				if(min > arr[i]){
					min = arr[i];
				}
			}
			printf("%d", min);
			}else{
				printf("Vui long nhap so phan tu cua mang truoc !");
			}
			break;
		case 5: 
		if(hasChoice){
			printf("Vui long nhap gia Tri can them vao phan tu dau: ");
			scanf("%d", &addNumber);
			for(i=currentIndex-1; i >= 0; i--){
				arr[i+1] = arr[i];
			}
			arr[0] = addNumber;
			currentIndex++;
		}else{
			printf("Vui long nhap so phan tu cua mang truoc !");
		}
		break;
		case 6 : 
			if(hasChoice){
				printf("Vui long nhap chi so can xoa (0->%d): ",currentIndex);
			do{
				scanf("%d",deleteIndex);
				if(deleteIndex < 0){
					printf("Loi ! Vui long nhap lai: ");
				}
			}while(deleteIndex < 0);
				for(i = deleteIndex; i<currentIndex-1;i++){
					arr[i] = arr[i+1];
				}
				currentIndex--;
			}else{
				printf("Vui long nhap so phan tu cua mang truoc !");
			}
			break;
		case 7:
			if(hasChoice){
				printf("Vay sap xep theo thu tu tang dan la:");
				for(i = 0; i < currentIndex-1; i++){
					minIndex = i;
					for(j = i+1; j<currentIndex; j++){
						if(arr[i] > arr[j]){
							minIndex = j;
						}
					}
					if(minIndex != i){
						temp = arr[minIndex];
						arr[minIndex] = arr[i];
						arr[i] = temp;
					}	
				}
				change = 1;
			}else{
				printf("Vui long nhap so phan tu cua mang truoc !");
			}
			break;
		case 8: 
			if(hasChoice){
				if(!change){
					printf("Vui long sap xep truoc khi tim kiem gia tri !");
				}else{
					found = 0;
					printf("Nhap gia tri can tim kiem: ");
					scanf("%d",&searchValue);
					left = 0, right=  currentIndex -1, mid;
					while(left <= right){
						mid = left + (right-left)/2;
						if(arr[mid] == searchValue){
							found = 1;
							break;
						}else if(arr[mid] > searchValue){
							right = mid -1;
						}else if(arr[mid] < searchValue){
							left = mid +1;
						}
					}
					if(found){
						printf("Vay tim thay %d o vi tri %d",searchValue,mid);
					}else{
						printf("Khong co gia tri can tim kiem !");
					}
				}
			}else{
				printf("Vui long nhap so phan tu cua mang truoc !");
			}
			break;
		case 9 :
			if(hasChoice){
				
				printf("Cac phan tu xuat hien 2 lan trong mang la \n");
				for(i = 0; i < currentIndex; i++){
					value = arr[i];
					count = 0;
					for(j= 0; j < currentIndex; j++){
						if(value == arr[j]){
							count++;
						}
					}
					if(count == 2){
						arrCurrent[currentIndex1] = value;
						currentIndex1++;
						for(f = 0 ; f < currentIndex1 ; f++){
							for(l = f+1; l < currentIndex1; l++){
								if(arrCurrent[f] == arrCurrent[l]){
									for(k = l; k < currentIndex1 - 1;k++){
										arrCurrent[k] = arrCurrent[k+1];
									}
								--currentIndex1;
								--k;
								}	
							}
						}
					}
				}
				for(i = 0; i < currentIndex1; i++){
					printf("\t%5d", arrCurrent[i]);
				}
			}else{
				printf("Vui long nhap so phan tu cua mang truoc !");
			}
			break;		
		case 10 : 
			printf("Nhap gia tri can tim: ");
			scanf("%d",&searchValue);
			count = 0;
				for(i =0;i <currentIndex; i++){
					if(arr[i] == searchValue){
						count++;
					}
				}
			printf("Vay so %d xuat hien: %d lan",searchValue,count);
		break;
		case 11 : 
			exit(0);
	}
	
}while(1);
	return 0;
	
}
