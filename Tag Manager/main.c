//
//  main.c
//  Tag Manager
//
//  Created by Ethan Cho on 6/15/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "data_manager.h"
#include "helper.h"

int main(int argc, const char * argv[]) {
    if(argc == 1) { // too little argument
        printf("etndb [DBFile] [options] ...\n");
        return EXIT_SUCCESS;
    }
    
    FILE *fp = fopen(argv[1], "r"); // open the file
    if(!fp) { // file open gone wrong
        perror("File open Error");
        return EXIT_FAIL;
    }
    
    int cmd_number = 1;
    while(1) { // read the file, line by line
        char line[1010];
        char cmd;
        
        char category[10]; // Two letters
        int number; /// 품번. 본래 3자리이지만 1자리로 인식한 후에 사용할 때만 바꾸는 방식 차용.
        
        fgets(line, 1000, fp);
        strtok(line, "\n\r"); // removing the last \r
        if(verify_cmd(line)) {
            fprintf(stderr, "Bad Syntax at cmd number %d", cmd_number);
            return EXIT_FAIL;
        }
        
        sscanf(line, "%c", &cmd);
        if(cmd == 'i') { // include new file
            sscanf(line, "%s %d", category, &number);
            if(include_file(category, number)) {
                fprintf(stderr, "Internal Error at cmd number %d", cmd_number);
                return EXIT_FAIL;
            }
        } else if(cmd == 'a') { // add new tag(information)
            sscanf(line, "%s %d", category, &number);
            if(read_add_tag(fp, category, number)) {
                fprintf(stderr, "Internal Error at cmd number %d", cmd_number);
                return EXIT_FAIL;
            }
        } else if(cmd == 'e') {
            data_end(); // Index all data
            break;
        } else {
            fprintf(stderr, "Internal Error at cmd number %d", cmd_number);
            return EXIT_FAIL;
        }
        
        if(feof(fp)) {
            fprintf(stderr, "File Has No End -- Add 'e' at the end of the DBFile.\n");
            return EXIT_FAIL;
        }
        ++cmd_number;
    }
    fclose(fp);
    
    return EXIT_SUCCESS;
}
