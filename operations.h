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



void init_session();
void add_torrent(char url[]);
void rm_torrent(boost::uint32_t id);
void get_all_torrents();


#endif //HACKUPC_FALL_2016_MOTTORRENT_OPERATIONS_H
