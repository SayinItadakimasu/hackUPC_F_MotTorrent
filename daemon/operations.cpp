//
// Created by josep on 8/10/16.
//

#include "operations.h"


libtorrent::session *s;
libtorrent::error_code ec;

bool init_session() {
    printf( "Init session \n");
    libtorrent::settings_pack sett;
    sett.set_str(libtorrent::settings_pack::listen_interfaces, "0.0.0.0:6881");
    s = new libtorrent::session(sett);
    if (ec)
    {
        fprintf(stderr, "failed to open listen socket: %s\n", ec.message().c_str());
        return false;
    }
    printf( "Session complete! \n");
    return true;
}

bool add_torrent(char url[]) {
    printf( "Making params... \n");
    libtorrent::add_torrent_params p;
    p.save_path = "./";
    p.url = url;
    printf( "Adding torrent... \n");
    s->add_torrent(p,ec);
    if (ec)
    {
        fprintf(stderr, "%s\n", ec.message().c_str());
        return false;
    }
    printf( "Torrent added! \n");
    return true;
}

bool rm_torrent(boost::uint32_t id) {
    std::vector<libtorrent::torrent_handle> vec = s->get_torrents();
    for (int i = 0; i < vec.size(); ++i) {
        if(vec[i].is_valid() && vec[i].id() == id) {
            s->remove_torrent(vec[i],libtorrent::session::delete_files);
            if (ec)
            {
                fprintf(stderr, "%s\n", ec.message().c_str());
                return false;
            }
            printf( "Successful remove! \n");
            return true;
        }
    }
}

std::vector<Stat> get_all_torrents() {
    std::vector<Stat> res;
    std::vector<libtorrent::torrent_handle> vec = s->get_torrents();
    for (int i = 0; i < vec.size(); ++i) {
        res[i].name = vec[i].status().name;
        res[i].torrent_id = vec[i].id();
        res[i].progress = vec[i].status().progress;
        std::copy(vec[i].url_seeds().begin(),vec[i].url_seeds().end(),std::back_inserter(res[i].seeders));
        //printf("Torrent ID: %u\tTorret name: %s\n",torrent_id,s.c_str());
        //printf("Prog: %f \n",prog);
    }
    return res;
}