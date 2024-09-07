//
//  helper.h
//  Tag Manager
//
//  Created by Ethan Cho on 8/16/24.
//

#ifndef helper_h
#define helper_h

#include "data_manager.h"
#include <ctype.h>

#define EXIT_FAIL 1

int read_add_tag(FILE *fp, char *category, int number) {
    char tagname[100], tagcontents[100];
    fscanf(fp, "%s", tagname);
    if(isinfo(tagname)) {
        fscanf(fp, "%s", tagcontents);
        return add_info(category, number, tagname, tagcontents);
    }
    return add_tag(category, number, tagname);
}

int verify_cmd(char* line) { //TODO
    //Verify command syntax before the data goes into sscanf. This doesn't catch internal errors, but it catches the bad data format.
    char cmd_list[] = "iae";
    int cmd_count = 3;
    int cmd_code = -1;
    for(int i=0;i < cmd_count;++i) {
        if(line[0] == cmd_list[i]) {
            cmd_code = i;
            break;
        }
    }
    
    return 0;
}

#endif /* helper_h */
