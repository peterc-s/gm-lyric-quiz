#ifndef LYRICS_H
#define LYRICS_H

#include "clay.h"

typedef struct Song {
    const Clay_String title;
    const Clay_String lyrics;
} Song;


const Song LYRICS[1] = {
    (Song) {
        .title = CLAY_STRING("Careless Whisper"),
        .lyrics = CLAY_STRING("I feel so unsure\n"
                "as I take your hand and lead to the dance floor\n"
                "as the music dies, something in your eyes\n"
                "calls to mind the silver screen\n"
                "and all its sad good-byes\n"
                "\n"
                "I'm never gonna dance again\n"
                "guilty feet have got no rhythm\n"
                "though it's easy to pretend\n"
                "I know you're not a fool\n"
                "\n"
                "Should've known better than to cheat a friend\n"
                "and waste the chance that I've been given\n"
                "so I'm never gonna dance again\n"
                "the way I danced with you\n"
                "\n"
                "Time can never mend\n"
                "the careless whispers of a good friend\n"
                "to the heart and mind\n"
                "ignorance is kind\n"
                "there's no comfort in the truth\n"
                "pain is all you'll find\n"
                "\n"
                "I'm never gonna dance again\n"
                "guilty feet have got no rhythm\n"
                "though it's easy to pretend\n"
                "I know you're not a fool\n"
                "\n"
                "Should've known better than to cheat a friend\n"
                "and waste this chance that I've been given\n"
                "so I'm never gonna dance again\n"
                "the way I danced with you\n"
                "\n"
                "Never without your love\n"
                "\n"
                "Tonight the music seems so loud\n"
                "I wish that we could lose this crowd\n"
                "Maybe it's better this way\n"
                "We'd hurt each other with the things we'd want to say\n"
                "\n"
                "We could have been so good together\n"
                "We could have lived this dance forever\n"
                "But now whose gonna dance with me\n"
                "Please stay\n"
                "\n"
                "And I'm never gonna dance again\n"
                "guilty feet have got no rhythm\n"
                "though it's easy to pretend\n"
                "I know you're not a fool\n"
                "\n"
                "Should've known better than to cheat a friend\n"
                "and waste the chance that I've been given\n"
                "so I'm never gonna dance again\n"
                "the way I danced with you\n"
                "\n"
                "(Now that you're gone) Now that you're gone\n"
                "(Now that you're gone) What I did's so wrong, so wrong\n"
                "that you had to leave me alone\n"
        ),
    },
};

#endif
