#ifndef LYRICS_H
#define LYRICS_H

#include "clay.h"

typedef struct Song {
    Clay_String title;
    Clay_String lyrics;
} Song;

typedef struct RedactedSong {
    Song* original;
    Clay_String redacted_lyrics;
    Clay_String* redacted_words;
    int num_redacted;
} RedactedSong;

RedactedSong redact_song(Song* song, int num_to_redact);

extern int NUM_LYRICS;
extern Song LYRICS[];


#endif
