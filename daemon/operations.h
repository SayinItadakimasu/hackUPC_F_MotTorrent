//
// Created by josep on 8/10/16.
//

#ifndef HACKUPC_FALL_2016_MOTTORRENT_OPERATIONS_H
#define HACKUPC_FALL_2016_MOTTORRENT_OPERATIONS_H

#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <vector>
#include <boost/make_shared.hpp>
#include "libtorrent/entry.hpp"
#include "libtorrent/bencode.hpp"
#include "libtorrent/session.hpp"
#include "libtorrent/torrent_info.hpp"
#include "libtorrent/torrent_status.hpp"

typedef struct {
    std::string name;
    boost::uint32_t torrent_id;
    float progress;
    int upload_speed;
    int download_speed;
    int seeder_count;
} Stat;


//Initializes session, returns true if success, false otherwise
//TODO: resume previous session
bool init_session();

//Kills the session, returns true if success, false otherwise
bool kill_session();

//Pauses a torrent
bool pause_torrent(boost::uint32_t id);

//Pauses all torrents
void pause_all();

//Resume a torrent
bool resume_torrent(boost::uint32_t id);

//Resume all torrents
void resume_all();

//Adds torrent to current session, returns true if success, false otherwise
//TODO: doesn't check repeated ones
bool add_torrent(char magnet_URL[]);

//Removes a torrent from current session, returns true if success, false otherwise
//It removes all trace of the torrent.
bool rm_torrent(boost::uint32_t id);

//Returns statistics for all torrents
std::vector<Stat>* get_all_torrents();


#endif //HACKUPC_FALL_2016_MOTTORRENT_OPERATIONS_H
