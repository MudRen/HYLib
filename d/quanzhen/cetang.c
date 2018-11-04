// cetang.c ����
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����Ǵ����Աߵ�һ��������Ҳ�ǽӴ���Ҫ���˵ĵط�������
��ֻ�ڷ���һ�����Ӻͼ�������(chair)�����ϰڷ���һ������
ɽʯ���辰��ǽ���Ϲ���һЩ�ֻ���һ��ʮ�����С��ʿ����æǰ
æ���д����ˡ�
LONG
        );
        set("exits", ([
                "east" : __DIR__"guozhendian",
                "west" : __DIR__"huizhentang",
                "north" : __DIR__"shiweishi",
                "south" : __DIR__"datang2",
        ]));
        set("objects", ([
                __DIR__"npc/li" : 1,
                __DIR__"npc/daotong2" : 1,
        ]));

        setup();
//        replace_program(ROOM);
}
void init()
{
        add_action("do_sit", "sit");
}

int do_sit(string arg)
{

        object me;
        object daotong;

        me = this_player();
        if ( !arg || (arg != "chair") )
                return notify_fail("��ϯ�ض���������������㵵�Ŀ�⡣\n");

		  if( !objectp(daotong = present("daotong", environment(me))) )
                return notify_fail("����������Ϣ��û����������㡣\n");

        if( me->query_temp("marks/served") )
        {
                message_vision("С��ʿЦ�Ŷ�$N˵���һ�æ���ţ���������Ϣ��Ϣ�ɡ�\n", me);
                return notify_fail("");
        }

        message_vision("$N������ǰ��С��ʿЦ�Ź����д���\n", me);
        daotong->serve_tea(me) ;
        
        me->set_temp("marks/served", 1);
        call_out("delete_served", 10, me);
        return 1;
}



void delete_served(object me)
{
        if ( objectp(me) ) me->delete_temp("marks/served");
}

int valid_leave(object me, string dir)
{
        if (( present("xiang cha", this_player())
                || present("dian xin", this_player()) ) 
			  && objectp(present("daotong", environment(me))) ) {
        message_vision("С��ʿ��$N��û���꣬˵������λ�������������߰ɡ�", me);
        return notify_fail("\n");
        }

        return ::valid_leave(me, dir);
}


