//
//  main.c
//  qsort
//
//  Created by 帅气的杨同学 on 2017/6/15.
//  Copyright © 2017年 帅气的杨同学. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    FILE *fp, *fr;
    int number[100], n, l=0, i, j;
    fr = fopen("//Users//y20161104577//Desktop//qsort//sort.txt","r+");
    if(fr == NULL) {
        printf("哈哈哈，文件打开失败！\n");
        return 0;
    }
    else {
        while(fscanf(fr,"%d",&n)!=EOF) {
            number[l] = n;
            l++;
        }
        for(i=0; i<l-1; i++) {
            for(j=0; j<l-i-1; j++) {
                if(number[j]>number[j+1]) {
                    number[j]   = number[j] + number[j+1];
                    number[j+1] = number[j] - number[j+1];
                    number[j]   = number[j] - number[j+1];
                }
            }
        }
        for(i=0; i<l; i++) {
            printf("%d ",number[i]);
        }
        printf("\n");
        fclose(fr);
    }
    //以上为从文件中读取数据并且排序；
    i = 0;
    fp = fopen("//Users//y20161104577//Desktop//qsort//sortnext.txt","w");
    if(fp == NULL) {
        printf("哈哈哈，文件打开失败！\n");
        return 0;
    }
    else {
        while(i!=l) {
            fprintf(fp,"%d",number[i]);
            i++;
        }
        printf("\n");
        fclose(fp);
    }
    return 0;
}
