//
// Created by josep on 8/10/16.
//

#include <stdlib.h>
#include <string.h>
#include <boost/make_shared.hpp>
#include "libtorrent/entry.hpp"
#include "libtorrent/bencode.hpp"
#include "libtorrent/session.hpp"
#include "libtorrent/torrent_info.hpp"
#include "operations.h"

using namespace libtorrent;
namespace lt = libtorrent;

char g[]="get";
char a[]="add";
char r[]="remove";
char q[]="quit";


int main()
{
    init_session();
    char str[100];
    printf( "Order me senpai! (add, remove, get, quit)\n");
    scanf("%s", str);
    while(strcmp(str,q) != 0) {
        if(strcmp(str,a) == 0) {
            char url[100];
            printf( "input url: \n");
            scanf("%s", url);
            add_torrent(url);
        }
        else if (strcmp(str,g) == 0){
            std::vector<stat> res = get_all_torrents();
            for (int i = 0; i < res.size(); ++i) {
                printf("Torrent ID: %u\n",res[i].torrent_id);
                printf("Name: %s\n",res[i].name);
                printf("Prog: %f \n",prog);
                for (int j = 0; j < res[i].seeders.size(); ++j) {
                    printf("Seed %d: %s \t",j,res[i].seeders[j]);
                }
                printf("\n");
            }

        }
        else {
            printf( "input id: \n");
            boost::uint32_t id;
            std::cin >> id;
            rm_torrent(id);
        }
        memset(str, 0, sizeof(str));
        printf( "Order me senpai! (add, remove, get, quit)\n");
        scanf("%s", str);
    }
}


