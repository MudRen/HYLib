inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "ֱ����");
        set("long", @LONG
ֱ����Ϊ���ص�������֮һ����ľ��ͽ��죬���ڴ��пں������������ݵ���
�ܵ���һ�𡣸��¹�ľ���죬�������ţ��������ﻨ�㡣��Ⱥ��ӵĲ����洦��
�����������������������𲻶ϣ�ǰ����ʥ�����䲻����
LONG
        );
        set("exits", ([ 
                "south" : __DIR__"wild6",
                
        ]));
       /* set("item_desc", ([
                "tree": "ֱ���¹�ľ���죬ÿ�ö����ϰ������ʷ��\n",
                "��ľ": "ֱ���¹�ľ���죬ÿ�ö����ϰ������ʷ��\n",
                "pine": "������������ڽ��µ��������µģ�������Ѿ֦�����εĴ�Ҷ����ס�˰����ա�\n",
                "����": "������������ڽ��µ��������µģ�������Ѿ֦�����εĴ�Ҷ����ס�˰����ա�\n",
        ]));*/
        
        set("objects", ([
                __DIR__"npc/chicken":   2,
                __DIR__"obj/statue5":   1,
                __DIR__"npc/monk5":     1,
        ]) );
        set("coor/x",-1080);
        set("coor/y",170);
        set("coor/z",0);
        setup(); 
} 
/*void init(){ 
        add_action("do_climb","climb");
} */
void reset()
{
        object statue,incense;
               
        ::reset();
        statue = present("statue", this_object());
        if (!present("incense",statue)) {
                incense=new(__DIR__"obj/incense");
                incense->move(statue);
        }
}  
/*int do_climb(string arg){ 
        object me,room;
        me=this_player();
        if (!arg || (arg!="pine" && arg!="����")) 
                return 0;
        if (!me->query_temp("zangbei/������")) 
                return notify_fail("��Ե�޹���ʲô����\n");
        room=find_object(__DIR__"pine1");
        if (!objectp(room)) room=load_object(__DIR__"pine1");
        message_vision("$N�ֽŲ��ã����ݵ�������������\n",me);
        tell_room(room, this_player()->name() + "����������������\n");
        this_player()->move(room);
}    
*/