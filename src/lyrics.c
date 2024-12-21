#include "lyrics.h"
#include "clay.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int NUM_LYRICS = 11;
Song LYRICS[] = {
    (Song) {
        .title = CLAY_STRING( "Faith" ),
        .lyrics = CLAY_STRING("Well, I guess it would be nice if I could touch your body\n"
                "I know not everybody has got a body like you\n"
                "But I gotta think twice before I give my heart away\n"
                "And I know all the games you play because I played them too\n"
                "\n"
                "Oh, but I need some time off from that emotion\n"
                "Time to pick my heart up off the floor\n"
                "Oh, when that love comes down without devotion\n"
                "Well it takes a strong man, baby\n"
                "But I'm showin' you the door\n"
                "\n"
                "'Cause I gotta' have faith\n"
                "I gotta have faith\n"
                "Because I gotta have faith, faith, faith\n"
                "I got to have faith, faith, faith\n"
                "\n"
                "Baby, I know you're askin' me to stay\n"
                "Say, \"Please, please, please don't go away\"\n"
                "You say I'm givin' you the blues\n"
                "Maybe (Huh) you mean every word you say\n"
                "Can't help but think of yesterday\n"
                "And another who tied me down to loverboy rules\n"
                "\n"
                "Before this river becomes an ocean\n"
                "Before you throw my heart back on the floor\n"
                "Oh, baby, I reconsider my foolish notion\n"
                "Well, I need someone to hold me\n"
                "But I'll wait for somethin' more\n"
                "\n"
                "Yes I gotta have faith\n"
                "Ooh, I gotta have faith\n"
                "Because I gotta have faith, faith, faith\n"
                "I gotta have faith, faith, faith\n"
                "\n"
                "I'll just have to wait\n"
                "Because I've got to have faith\n"
                "I gotta have faith\n"
                "I've got to, got to, got to have faith\n"
                "\n"
                "Before this river becomes an ocean\n"
                "Before you throw my heart back on the floor\n"
                "Oh, oh, baby, I reconsider my foolish notion\n"
                "Well, I need someone to hold me\n"
                "But I'll wait for somethin' more\n"
                "\n"
                "'Cause I gotta' have faith\n"
                "Ooh, I gotta have faith\n"
                "Because I gotta have faith, faith, faith\n"
                "I gotta have faith, faith, faith\n"
                ),
    },
    (Song) {
        .title = CLAY_STRING( "Father Figure" ),
        .lyrics = CLAY_STRING("That's all I wanted\n"
                "Something special, someone sacred in your eyes\n"
                "For just one moment\n"
                "To be bold and naked at your side\n"
                "\n"
                "Sometimes I think that you'll never understand me\n"
                "Maybe this time is forever, say it can be, whoa\n"
                "\n"
                "That's all you wanted\n"
                "Somethin' special, someone sacred in your life\n"
                "Just for one moment, to be warm and naked at my side\n"
                "\n"
                "Sometimes I think that you'll never understand me\n"
                "(Understand me)\n"
                "But somethin' tells me together, we'd be happy, whoa baby\n"
                "\n"
                "I will be your father figure\n"
                "Put your tiny hand in mine\n"
                "I will be your preacher teacher\n"
                "Anything you have in mind\n"
                "I will be your father figure\n"
                "I have had enough of crime\n"
                "I will be the one who loves you\n"
                "'Til the end of time\n"
                "\n"
                "That's all I wanted\n"
                "But sometimes love can be mistaken for a crime\n"
                "That's all I wanted\n"
                "Just to see my baby's blue eyes shine\n"
                "\n"
                "This time I think that my lover understands me\n"
                "(Understands me)\n"
                "If we have faith in each other then we can be strong\n"
                "\n"
                "I will be your father figure\n"
                "Put your tiny hand in mine\n"
                "I will be your preacher teacher\n"
                "Anything you have in mind\n"
                "I will be your father figure\n"
                "I have had enough of crime\n"
                "I will be the one who loves you\n"
                "'Til the end of time\n"
                "\n"
                "If you are the desert, I'll be the sea\n"
                "If you ever hunger, hunger for me\n"
                "Whatever you ask for, that's what I'll be\n"
                "So when you remember the ones who have lied\n"
                "Who said that they cared but then\n"
                "Laughed as you cried\n"
                "Beautiful darling, don't think of me\n"
                "Because all I ever wanted\n"
                "It's in your eyes baby (baby)\n"
                "And love can't lie, no\n"
                "\n"
                "Greet me with the eyes of a child\n"
                "My love is always tellin' me so\n"
                "Heaven is a kiss and a smile\n"
                "Just hold on, hold on\n"
                "I won't let you go, my baby\n"
                "\n"
                "I will be your father figure\n"
                "Put your tiny hand in mine\n"
                "I will be your preacher teacher\n"
                "Anything you have in mind\n"
                "I will be your father figure\n"
                "I have had enough of crime\n"
                "I will be the one who loves you\n"
                "'Til the end of time\n"
                "\n"
                "I will be your father (I will be your)\n"
                "I will be your (father) preacher teacher\n"
                "I will be your (I'll be your daddy, oh)\n"
                "I will be the one who loves you\n"
                "'Til the end of time \n"),
    },
    (Song) { 
        .title = CLAY_STRING( "I Want Your Sex Part I" ),
        .lyrics = CLAY_STRING("There's things that you guess\n"
                "And a'things a'that you know\n"
                "There's boys you can trust\n"
                "And a'girls that you don't\n"
                "There's little things you hide\n"
                "And little things that you show\n"
                "Sometimes you think you're gonna get it\n"
                "But you don't and that's just the way it goes\n"
                "\n"
                "I swear I won't tease you\n"
                "Won't tell you no lies\n"
                "Don't need no Bible\n"
                "Just look in my eyes\n"
                "I've a'waited so long baby\n"
                "Now that we're friends\n"
                "Every man's got his patience\n"
                "And here's where mine ends\n"
                "\n"
                "I want your sex\n"
                "I want your love\n"
                "I want your sex\n"
                "I want your...sex\n"
                "\n"
                "It's playin' on my mind\n"
                "It's dancin' on my soul\n"
                "It's taken so much time\n"
                "So why don't you just let me go\n"
                "I'd really like to try\n"
                "Oh, I'd really love to know\n"
                "When you tell me you're gonna regret it\n"
                "Then I tell you that I love you but you still say no\n"
                "\n"
                "I swear I won't tease you\n"
                "Won't tell you no lies\n"
                "Don't need no Bible\n"
                "Just look in my eyes (Oooh)\n"
                "I've waited so long baby\n"
                "Out in the cold\n"
                "I can't take much more girl\n"
                "I'm losing control\n"
                "\n"
                "I want your sex\n"
                "I want your love\n"
                "I want your sex\n"
                "I want your...sex (sex! Ow!)\n"
                "\n"
                "It's natural, it's chemical (let's do it)\n"
                "It's logical habitual (can we do it?)\n"
                "It's sensual but most of all\n"
                "Sex is something that we should do\n"
                "Sex is something for me and you\n"
                "\n"
                "Sex is natural, sex is good\n"
                "Not everybody does it\n"
                "But everybody should\n"
                "Sex is natural, sex is fun\n"
                "Sex is best when it's one on one\n"
                "One on one\n"
                "\n"
                "Hoo ah (sex) I'm not your father\n"
                "Hoo ah (sex) I'm not your brother\n"
                "Hoo ah (sex) talk to your sister\n"
                "Hoo ah (sex) I am a lover\n"
                "Hoo ah (sex)\n"
                "Hoo ah (sex)\n"
                "Hoo ah (sex)\n"
                "C-c-c-c-c-c-come on\n"
                "\n"
                "What's your definition of dirty baby?\n"
                "What do you consider pornography?\n"
                "Don't you know I love it 'til it hurts me baby?\n"
                "Don't you think it's time you had sex with me?\n"
                "What's your definition of dirty baby?\n"
                "What do you call pornography?\n"
                "Don't you know I love it 'til it hurts me baby?\n"
                "Don't you think it's time you had sex with me?\n"
                "Ow! Sex with me\n"
                "Ow! Sex with me\n"
                "Mmmm have sex with me\n"
                "C-c-c-c-c-c-come on\n"),
    },
    (Song) {
        .title = CLAY_STRING( "I Want Your Sex Part II" ),
        .lyrics = CLAY_STRING("Oh so much love, that you've never seen\n"
                "Let's make love, put your trust in me (hmm)\n"
                "Don't you listen to what they told you\n"
                "Because I love you, let me hold you\n"
                "\n"
                "Oh, I'm not your brother\n"
                "I'm not your father\n"
                "Oh will you ever change your mind?\n"
                "I'm a gentle lover with a heart of gold\n"
                "But baby you've been so unkind...oh\n"
                "\n"
                "Come on\n"
                "I want your sex\n"
                "Come on, I want your sex\n"
                "That's right, all night\n"
                "Oh, I want your sex\n"
                "I want your...sex\n"
                "\n"
                "Sexy baby's (Sexy baby's)\n"
                "Sexy body (Sexy body)\n"
                "Keeps me guessing (Keeps me guessing)\n"
                "With a promise (Oh)\n"
                "I know we can come together\n"
                "But the question is will we ever ever?\n"
                "\n"
                "Sexy baby's (Sexy baby's)\n"
                "Sexy body (Sexy body)\n"
                "Keeps me guessing (Keeps me guessing)\n"
                "With a promise (Oh)\n"
                "I know we can come together\n"
                "But the question is will we ever ever?\n"
                "\n"
                "Ohhh together\n"
                "You and me\n"
                "\n"
                "I want your love \n"),
    },
    (Song) {
        .title = CLAY_STRING( "One More Try" ),
        .lyrics = CLAY_STRING("I've had enough of danger\n"
                "And people on the streets\n"
                "I'm lookin' out for angels\n"
                "Just tryin' to find some peace\n"
                "Now I think it's time\n"
                "That you let me know\n"
                "So if you love me\n"
                "Say you love me\n"
                "But if you don't\n"
                "Just let me go\n"
                "\n"
                "'Cause teacher\n"
                "There are things that I don't want to learn\n"
                "And the last one I had\n"
                "Made me cry\n"
                "So I don't want to learn to\n"
                "Hold you, touch you\n"
                "Think that you're mine\n"
                "Because it ain't no joy\n"
                "For an uptown boy\n"
                "Whose teacher has told him goodbye, goodbye, goodbye\n"
                "\n"
                "When you were just a stranger\n"
                "And I was at your feet\n"
                "I didn't feel the danger\n"
                "Now I feel the heat\n"
                "That look in your eyes\n"
                "Telling me \"No\"\n"
                "So you think that you love me\n"
                "Know that you need me\n"
                "I wrote the song, I know it's wrong\n"
                "Just let me go\n"
                "\n"
                "'Cause teacher\n"
                "There are things that I don't want to learn\n"
                "And the last one I had\n"
                "Made me cry\n"
                "So I don't want to learn to\n"
                "Hold you, touch you\n"
                "Think that you're mine\n"
                "Because it ain't no joy\n"
                "For an uptown boy\n"
                "Whose teacher has told him goodbye, goodbye, goodbye\n"
                "\n"
                "So when you say that you need me\n"
                "That you'll never leave me\n"
                "I know you're wrong, you're not that strong\n"
                "Let me go\n"
                "\n"
                "And teacher\n"
                "There are things that I still have to learn\n"
                "But the one thing I have is my pride\n"
                "Oh, so I don't want to learn to\n"
                "Hold you, touch you\n"
                "Think that you're mine\n"
                "Because there ain't no joy\n"
                "For an uptown boy\n"
                "Who just isn't willin' to try\n"
                "\n"
                "I'm so cold inside\n"
                "Maybe just one more try \n"),
    },
    (Song) {
        .title = CLAY_STRING( "Hard Day" ),
        .lyrics = CLAY_STRING("Don't bring me down\n"
                "Don't bring me down\n"
                "Don't bring me down\n"
                "\n"
                "I've never been one for playin' games\n"
                "You can move your mouth forever\n"
                "But the words sound just the same\n"
                "Somethin' like, \"Bang bang, you're dead\"\n"
                "Couldn't we just make love instead?\n"
                "Say yes because it's what we do best\n"
                "And I've had such a hard day\n"
                "\n"
                "Take me where their eyes can't find us\n"
                "Without you I may as well just\n"
                "\n"
                "How much do I have to say?\n"
                "What more do you have to see?\n"
                "What will it take to make you love me?\n"
                "Well you're not the first, you're not the last\n"
                "You're not even the one who loves me the best\n"
                "But all I think about is you\n"
                "\n"
                "So take me where their eyes can't find us\n"
                "Without you I may as well just\n"
                "So take me where their eyes can't find us\n"
                "Without you I may as well just\n"
                "\n"
                "Don't bring me down\n"
                "Don't bring me down\n"
                "Don't bring me down\n"
                "Please don't wander from my door\n"
                "\n"
                "I've never been one for playin' games\n"
                "You can move your mouth forever\n"
                "But the words sound just the same\n"
                "Somethin' like, \"Bang bang, you're dead\"\n"
                "Couldn't we just make love instead?\n"
                "Say yes because it's what we do best\n"
                "And I've had such a hard day\n"
                "\n"
                "(Don't bring me down)\n"
                "So don't bring me down\n"
                "Won't ya give me a break?\n"
                "Somebody give me a break now!\n"
                "Don't bring me down\n"
                "Don't bring me down\n"
                "Don't bring me down\n"
                "\n"
                "Sweet little boy with oh, such a big mouth\n"
                "Harsh words can get (don't bring me down) you into hot water\n"
                "When people don't understand ya baby\n"
                "I'm always (don't bring me down) here for ya\n"
                "And I, and I will never (don't bring me down) bring you down, down, down, down, down my (don't bring me down) baby\n"
                "\n"
                "Trust me\n"
                "(Don't bring me down)\n"
                "I want you to trust me\n"
                "Oh trust me\n"
                "'Cause I won't bring you down\n"
                "(Don't bring me down)\n"
                "I won't bring you down\n"
                "Do you trust me?\n"
                "Yeah\n"),
    },
    (Song) {
        .title = CLAY_STRING( "Hand To Mouth" ),
        .lyrics = CLAY_STRING("Jimmy Got Nothin' made himself a name\n"
                "With a gun that he polished for a rainy day\n"
                "A smile and a quote from a vigilante movie\n"
                "Our boy Jimmy just blew them all away\n"
                "He said it made him crazy\n"
                "Twenty five years livin' hand to mouth\n"
                "Hand to mouth, hand to mouth, hand to mouth\n"
                "\n"
                "Sweet little baby on a big white doorstep\n"
                "She needs her mother but her mother is dead\n"
                "Just another hooker that the lucky can forget\n"
                "Just another hooker\n"
                "It happens everyday\n"
                "She loved her little baby\n"
                "But she couldn't bare to see her livin' hand to mouth\n"
                "Hand to mouth, hand to mouth, hand to mouth\n"
                "\n"
                "I believe in the gods of America\n"
                "I believe in the land of the free\n"
                "But no one told me (no one told me)\n"
                "That the gods believe in nothing\n"
                "So with empty hands I pray\n"
                "And from day to hopeless day\n"
                "They still don't see me (see me)\n"
                "\n"
                "Everybody talks about the new generation\n"
                "Jump on the wagon or they'll leave you behind\n"
                "But no one gave a thought to the rest of the nation\n"
                "\"Like to help you buddy, but I haven't got the time\"\n"
                "Somebody shouted save me\n"
                "But everybody started livin' hand to mouth\n"
                "Hand to mouth, hand to mouth, hand to mouth\n"
                "\n"
                "There's a big white lady\n"
                "On a big white doorstep\n"
                "She asked her daddy and her daddy said \"Yes\"\n"
                "Has to give a little for the dollars that we get\n"
                "Has to give a little\n"
                "They say it's for the best\n"
                "Somebody shouted maybe\n"
                "But they kept on livin' from hand to mouth\n"
                "Hand to mouth, hand to mouth, hand to mouth\n"
                "\n"
                "So she ran to the arms of America (America)\n"
                "And she kissed the powers that be\n"
                "And someone told me (someone told me)\n"
                "That the gods believe in nothing\n"
                "So with empty hands I pray\n"
                "And I tell myself\n"
                "One day\n"
                "They just might see me\n"),
    },
    (Song) {
        .title = CLAY_STRING( "Look At Your Hands" ),
        .lyrics = CLAY_STRING("I loved you once but look at you now\n"
                "You're in someone else's bed\n"
                "I loved you once so I don't know how\n"
                "You're with a man like that\n"
                "You'd be better off dead\n"
                "He don't care, he don't treat you right\n"
                "It's not fair, I still want you at night\n"
                "Can't you see you made a mistake, girl\n"
                "He treats you like dirt and I hate it\n"
                "\n"
                "Na na na na na na, lady\n"
                "Look at your hands\n"
                "You got two fat children and a drunken man\n"
                "Betcha don't, betcha don't, betcha don't like your life\n"
                "Betcha don't, betcha don't, betcha don't like it\n"
                "Ma ma ma ma ma ma, baby\n"
                "Look at your hands\n"
                "You should have been my woman when you had the chance\n"
                "Betcha don't, betcha don't, betcha don't like your life\n"
                "Betcha don't, betcha don't, betcha don't like your life now\n"
                "\n"
                "He hits you once, he hits you twice\n"
                "He don't care about the blood on his hands\n"
                "But that's okay 'cause it's his wife\n"
                "\"It's the only thing she understands,\" he says\n"
                "\n"
                "Say you're gonna leave him, say you're gonna try\n"
                "But you're only talkin' (only talkin')\n"
                "Oh, I know you think I'm a young boy\n"
                "But I'm good and I think we can make it\n"
                "\n"
                "Na na na na na na, lady\n"
                "Look at your hands\n"
                "You got two fat children and a drunken man\n"
                "Betcha don't, betcha don't, betcha don't like your life\n"
                "Betcha don't, betcha don't, betcha don't like it\n"
                "Ma ma ma ma ma ma, baby\n"
                "Look at your hands\n"
                "You should have been my woman when you had the chance\n"
                "Betcha don't, betcha don't, betcha don't like your life\n"
                "Betcha don't, betcha don't, betcha don't like your life now\n"
                "(Don't like your guy now)\n"
                "\n"
                "Well, excuse me baby but it's makin' me mad\n"
                "The only one you want is the only one you'll never have\n"
                "Betcha don't, betcha don't, betcha don't like your\n"
                "It's so sad\n"
                "The only one you'll never have\n"
                "It's too bad, only one you'll never have\n"
                "\n"
                "Na na na na na na, lady\n"
                "Look at your hands\n"
                "You've got two fat children and a drunken man\n"
                "And I betcha don't like your life now \n"),
    },
    (Song) {
        .title = CLAY_STRING( "Monkey" ),
        .lyrics = CLAY_STRING("Why can't you do it?\n"
                "Why can't you set your monkey free?\n"
                "Always givin' into it\n"
                "Do you love your monkey or do you love me?\n"
                "Why can't you do it?\n"
                "Why do I have to share my baby with a monkey (monkey)\n"
                "With a monkey? (monkey)\n"
                "\n"
                "Oh I count to ten\n"
                "But I don't know how and I don't know when\n"
                "To open my eyes\n"
                "If you kiss me again\n"
                "Like you did just now, like you did just then (just do it again)\n"
                "\n"
                "I've had the rest\n"
                "Now it's time I had the best\n"
                "So you tell me that you won't do anymore\n"
                "Well I'd write your heart a letter\n"
                "But I think you know me better\n"
                "If I keep on askin' baby, maybe\n"
                "I'll get what I'm askin' for\n"
                "\n"
                "Why can't you do it?\n"
                "Why can't you set your monkey free?\n"
                "Always givin' into it\n"
                "Do you love your monkey or do you love me?\n"
                "Why can't you do it?\n"
                "Why do I have to share my baby with a monkey (monkey)\n"
                "With a monkey? (monkey)\n"
                "\n"
                "Oh I hate your friends\n"
                "But I don't know how and I don't know when\n"
                "To open your eyes\n"
                "Yes the monkey's back again\n"
                "Do you want him now like you did back then? (don't do it again)\n"
                "Back, then, then, back, then, then\n"
                "Back, back (do it again)\n"
                "\n"
                "I tried my best\n"
                "But your head is such a mess\n"
                "So I guess that I don't want you anymore\n"
                "Well you say you care about me\n"
                "That you just can't do without me\n"
                "But you keep on dancin' baby\n"
                "'Til that monkey has you on the floor\n"
                "\n"
                "Why can't you do it?\n"
                "Why can't you set your monkey free?\n"
                "Always givin' into it\n"
                "Do you love your monkey or do you love me?\n"
                "Why can't you do it?\n"
                "Why do I have to share my baby with a monkey (monkey)\n"
                "With a monkey? (monkey)\n"
                "\n"
                "(Monkey, monkey...)\n"
                "Don't look now\n"
                "There's a monkey on your back\n"
                "Don't look now\n"
                "There's a monkey on you\n"
                "Don't look now\n"
                "There's a monkey on your back\n"
                "Don't look now\n"
                "There's a monkey on you\n"
                "\n"
                "So you tell me that you won't do anymore\n"
                "Keep on askin' baby, maybe\n"
                "I'll get what I'm askin' for\n"
                "\n"
                "Why can't you do it?\n"
                "Why can't you set your monkey free?\n"
                "Always givin' into it\n"
                "Do you love your monkey or do you love me?\n"
                "Why can't you do it?\n"
                "Why do I have to share my baby with a monkey (monkey)\n"
                "With a monkey? (monkey)\n"
                "Why can't you do it?\n"
                "Why can't you set your monkey free?\n"
                "Always givin' into it\n"
                "Do you love your monkey or do you love me?\n"
                "Why can't you do it?\n"
                "Why do I have to share my baby with a monkey (monkey)\n"
                "With a monkey? (monkey)\n"
                "\n"
                "(Monkey, monkey, monkey)\n"
                "(Monkey, monkey, monkey)\n"
                "(Monkey, monkey, monkey)\n"
                "(Monkey, monkey, mon-mon-mon-mon-monkey)\n"),
    },
    (Song) {
        .title = CLAY_STRING( "Kissing A Fool" ),
        .lyrics = CLAY_STRING("You are far\n"
                "When I could have been your star\n"
                "You listened to people\n"
                "Who scared you to death and from my heart\n"
                "Strange that you were strong enough\n"
                "To even make a start\n"
                "But you'll never find peace of mind\n"
                "'Til you listen to your heart\n"
                "\n"
                "People\n"
                "You can never change the way they feel\n"
                "Better let them do just what they will\n"
                "For they will\n"
                "If you let them steal your heart from you\n"
                "People\n"
                "Will always make a lover feel a fool\n"
                "But you knew I loved you\n"
                "We could have shown them all\n"
                "We should have seen love through\n"
                "\n"
                "Fooled me with the tears in your eyes\n"
                "Covered me with kisses and lies\n"
                "So goodbye\n"
                "But please don't take my heart\n"
                "\n"
                "You are far\n"
                "I'm never gonna be your star\n"
                "I'll pick up the pieces and mend my heart\n"
                "Maybe I'll be strong enough\n"
                "I don't know where to start\n"
                "But I'll never find peace of mind\n"
                "While I listen to my heart\n"
                "\n"
                "People\n"
                "You can never change the way they feel\n"
                "Better let them do just what they will\n"
                "For they will\n"
                "If you let them steal your heart from you\n"
                "People\n"
                "Will always make a lover feel a fool\n"
                "But you knew I loved you\n"
                "We could have shown them all\n"
                "We should have seen love through\n"
                "\n"
                "Ba da da ah ah ah\n"
                "\n"
                "But remember this\n"
                "Every other kiss\n"
                "That you ever give\n"
                "Long as we both live\n"
                "When you need the hand of another man\n"
                "One you really can surrender with\n"
                "I will wait for you like I always do\n"
                "There's something there\n"
                "That can't compare with any other\n"
                "\n"
                "You are far\n"
                "When I could have been your star\n"
                "You listened to people\n"
                "Who scared you to death and from my heart\n"
                "Strange that I was wrong enough\n"
                "To think you'd love me too\n"
                "Guess you were kissing a fool\n"
                "\n"
                "You must have been kissing a fool\n"),
    },
    (Song) {
        .title = CLAY_STRING( "A Last Request (I Want Your Sex Part III)" ),
        .lyrics = CLAY_STRING("It's late\n"
                "Time for bed\n"
                "So I sit and I wait\n"
                "For that gin and tonic\n"
                "To go to your head\n"
                "\n"
                "I know\n"
                "It's a devious plan\n"
                "But it's the only way that I know\n"
                "To get those big bad car keys\n"
                "Out of your hand\n"
                "\n"
                "You know\n"
                "That I remain a gentleman\n"
                "But even so\n"
                "There's only so much\n"
                "A gentleman can stand\n"
                "Sleep with me\n"
                "Oh\n"
                "Sleep with me, tonight\n"
                "\n"
                "My cards are on your table\n"
                "My dreams are in your bed\n"
                "Oh, if I was able\n"
                "I'd be there instead\n"
                "\n"
                "Oh, oh\n"
                "Oh, sleep with me tonight \n"),
    }
};


const int MAX_WORD_SKIP = 50;

int cmp_redacted_words(const void* a, const void* b) {
    RedactedWord* word_a = (RedactedWord*)a;
    RedactedWord* word_b = (RedactedWord*)b;

    return word_a->start_index - word_b->start_index;
}

RedactedSong redact_song(Song* song, int num_to_redact) {
    srand(time(NULL));
    int words_until_redact = rand() % MAX_WORD_SKIP;

    // create redacted string
    char* redacted_lyrics = malloc(song->lyrics.length);
    if (!redacted_lyrics) {
        fprintf(stderr, "ERROR: Unable to malloc redacted lyrics.");
        exit(EXIT_FAILURE);
    }
    memcpy(redacted_lyrics, song->lyrics.chars, song->lyrics.length);

    RedactedWord* redacted_words = malloc(num_to_redact * sizeof(RedactedWord));
    if (!redacted_words) {
        fprintf(stderr, "ERROR: Unable to malloc redacted words array.");
        exit(EXIT_FAILURE);
    }
    int num_redacted = 0;

    // loop until no more words need
    // to be redacted
    int index = 0;
    while (num_to_redact) {
        // check for space at current index
        if (song->lyrics.chars[index % song->lyrics.length] == ' ') {
            // if no words left until redact,
            if (!words_until_redact) {
                // skip to first letter of word
                int word_start = index + 1;
                
                // check if already redacted
                if (redacted_lyrics[word_start % song->lyrics.length] == '_') {
                    // if it is, then redact next word
                    ++words_until_redact;
                } else {
                    // otherwise, redact the word
                    int word_end = word_start;
                    while(song->lyrics.chars[word_end % song->lyrics.length] != ' '
                       && song->lyrics.chars[word_end % song->lyrics.length] != '\n'
                       && song->lyrics.chars[word_end % song->lyrics.length] != '\0') {
                        redacted_lyrics[word_end % song->lyrics.length] = '_';
                        ++word_end;
                        ++index;
                    }

                    int word_length = word_end - word_start;
                    char* redacted_word = malloc(word_length + 1);
                    if (!redacted_word) {
                        fprintf(stderr, "ERROR: Unable to malloc redacted word.");
                        exit(EXIT_FAILURE);
                    }
                    memcpy(redacted_word, &song->lyrics.chars[word_start % song->lyrics.length], word_length);
                    redacted_word[word_length] = '\0';

                    redacted_words[num_redacted++] = (RedactedWord) {
                        .start_index = word_start % song->lyrics.length,
                        .len = word_length,
                        .word = redacted_word,
                    };

                    // decrement amount to redact
                    --num_to_redact;
                    words_until_redact = rand() % MAX_WORD_SKIP;
                }
            } else {
                // otherwise, decrement words until redact
                --words_until_redact;
            }
        }

        // if no space at current index then just skip ahead
        ++index;
    }

    qsort(redacted_words, num_redacted, sizeof(RedactedWord), cmp_redacted_words);

    return (RedactedSong) {
        .original = song,
        .redacted_lyrics = (Clay_String) {
            .chars = redacted_lyrics,
            .length = song->lyrics.length,
        },
        .num_redacted = num_redacted,
        .redacted_words = redacted_words,
    };
}