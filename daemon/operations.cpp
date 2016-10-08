//
// Created by josep on 8/10/16.
//

#include "operations.h"


libtorrent::session *s;
libtorrent::error_code ec;

bool init_session() {
    printf( "Init session... \n");
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

bool kill_session() {
    printf( "Killing session \n");
    libtorrent::session_proxy proxy = s->abort();
    printf( "Kill successful! \n");
}

bool pause_torrent(boost::uint32_t id) {
    printf( "Pausing torrent \n");
    std::vector<libtorrent::torrent_handle> vec = s->get_torrents();
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i].is_valid() && vec[i].id() == id && !vec[i].status().paused) vec[i].pause();
        printf( "Torrent paused! \n");
        return true;
    }
    printf( "Failed to pause \n");
    return false;
}

void pause_all() {
    printf( "Pausing all \n");
    std::vector<libtorrent::torrent_handle> vec = s->get_torrents();
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i].is_valid() && !vec[i].status().paused) vec[i].pause();
    }
    printf( "All paused! \n");
}

bool resume_torrent(boost::uint32_t id) {
    printf( "Resuming torrent \n");
    std::vector<libtorrent::torrent_handle> vec = s->get_torrents();
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i].is_valid() && vec[i].id() == id && vec[i].status().paused) vec[i].resume();
        printf( "Torrent resumed! \n");
        return true;
    }
    printf( "Failed to resume \n");
    return false;
}

void resume_all() {
    printf( "Resuming all torrents \n");
    std::vector<libtorrent::torrent_handle> vec = s->get_torrents();
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i].is_valid() && vec[i].status().paused) vec[i].resume();
    }
    printf( "All torrents resumed! \n");
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

std::vector<Stat>* get_all_torrents() {
    printf( "Getting torrent stats... \n");
    std::vector<libtorrent::torrent_handle> vec = s->get_torrents();
    std::vector<Stat> *res = new std::vector<Stat>(vec.size());
    for (int i = 0; i < vec.size(); ++i) {
        Stat &current_stat = (*res)[i];
        libtorrent::torrent_handle &current_handle = vec[i];
        if(current_handle.is_valid()) {
            current_stat.name = current_handle.status().name;
            current_stat.torrent_id = current_handle.id();
            current_stat.progress = current_handle.status().progress;
            current_stat.seeder_count = current_handle.status().num_seeds;
            current_stat.download_speed = current_handle.status().download_rate;
            current_stat.upload_speed = current_handle.status().upload_rate;
        }
    }
    printf( "All stats retrieved! \n");
    return res;
}