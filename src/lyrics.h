#ifndef LYRICS_H
#define LYRICS_H

#include "clay.h"

typedef struct Song {
    Clay_String title;
    Clay_String lyrics;
} Song;

typedef struct RedactedWord {
    int start_index;
    int len;
    char* word;
} RedactedWord;

typedef struct RedactedSong {
    Song* original;
    Clay_String redacted_lyrics;
    RedactedWord* redacted_words;
    int num_redacted;
} RedactedSong;

RedactedSong redact_song(Song* song, int num_to_redact);

#define NUM_LYRICS 63
extern Song LYRICS[];

#endif
