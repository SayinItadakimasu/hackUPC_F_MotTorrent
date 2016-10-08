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
char p[]="pause";
char pa[]="pall";
char r[]="resume";
char ra[]="rall";
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
        else if (strcmp(str,g) == 0) {
            std::vector<Stat> *res = get_all_torrents();
            for (int i = 0; i < res->size(); ++i) {
                Stat &current_stat = (*res)[i];
                printf("Torrent ID: %u\n", current_stat.torrent_id);
                printf("Name: %s\n", current_stat.name.c_str());
                printf("Prog: %f \n", current_stat.progress);
                printf("Seed count: %d\n", current_stat.seeder_count);
                printf("Upload speed: %d\n", current_stat.upload_speed);
                printf("Download speed: %d\n", current_stat.download_speed);
                printf("\n");
            }
        }
        else if(strcmp(str,p) == 0) {
            printf( "input id: \n");
            boost::uint32_t id;
            std::cin >> id;
            pause_torrent(id);
        }
        else if(strcmp(str,pa) == 0) {
            pause_all();
        }
        else if(strcmp(str,r) == 0) {
            printf( "input id: \n");
            boost::uint32_t id;
            std::cin >> id;
            resume_torrent(id);
        }
        else if(strcmp(str,ra) == 0) {
            resume_all();
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


