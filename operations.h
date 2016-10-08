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

struct Stat {
    std::string name;
    boost::uint32_t torrent_id;
    float progress;
    //speed
    std::vector<std::string> seeders;
};

//Initializes session, returns true if success, false otherwise
//TODO: resume previous session
bool init_session();

//Adds torrent to current session, returns true if success, false otherwise
//TODO: doesn't check repeated ones
bool add_torrent(char url[]);

//Removes a torrent from current session, returns true if success, false otherwise
//It removes all trace of the torrent.
bool rm_torrent(boost::uint32_t id);


std::vector<Stat> get_all_torrents();


#endif //HACKUPC_FALL_2016_MOTTORRENT_OPERATIONS_H
