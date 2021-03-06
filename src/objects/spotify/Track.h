/**
The MIT License (MIT)

Copyright (c) <2013> <Moritz Schulze>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
**/

#ifndef _TRACK_H
#define _TRACK_H

#include <libspotify/api.h>
#include <string>
#include <vector>
#include <memory>

#include "Artist.h"
#include "Album.h"

class Album;
class Artist;

class Track {
friend class Player;
friend class NodeTrack;
public:
  Track(sp_track* _track);
  Track(const Track& other) : track(other.track) {
      sp_track_add_ref(track);
    };
  ~Track() {
    sp_track_release(track);
  };

  std::string name();
  std::string link();
  std::vector<std::shared_ptr<Artist>> artists();
  std::shared_ptr<Album> album();
  int duration();
  bool starred();
  void setStarred(bool starred);
  int popularity();
  bool isLoaded();
private:
  sp_track* track;
};

#endif
