//zongtai ��̨

#include <ansi.h>
#include <room.h>

inherit ROOM;
void create()
{
        set("short",HIR"�Խ�ɽׯ"NOR);
        set("long", @LONG
        /J_____________________L\                        
            /|||||||||||||||||||||||||\                      
        {\/LLLLLLLLLLLLLLLLLLLLLLLLLLLLLL\/}          
         ^^^^||^^^^ ���Խ�ɽׯ�� ^^^||^^^^   
          /|||||||||||||||||||||||||||||\
          ^^^||^^��^^��^^  ^^��^^��^||^^^
             ||       ��������      ||
             ||1.��å������         ||  
             ||2.�����Ϲ���ȡ       ||
             ||3.����ع���         ||
   I-I-I-I-I-||_________||__________||-I-I-I-I-I
  /__|__|__|__|__|_______________|__|__|__|__|__\
 /__|__|__|__|__||_______________|_|__|__|__|__|_\
LONG
        );
        set("exits", ([        
        "1" : __DIR__"kantaie",
        "2" : __DIR__"kantaiw",
        "up" : "/d/city/guangchang",
        
        ]));
        
        set("no_fight", "1");
        set("no_sleep_room", 1);
        setup();
}

