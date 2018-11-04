
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", BLK"��֮����"NOR);
	set("long", BLK @LONG
   һ�������������, �������ƺ��������µ��������������ȥ, ��
����С��Խ�����������ˮ��Խ��, �����������Ҳ��������ȫ����
ס��. ��������Ѿ��޷�����ؿ������ܵ�״����, ֻ֪����Ľ��Ѿ�
���������������.
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);


         set("objects", ([
"/clone/box/gboxm" : random(2),
              __DIR__"npc/lev4" : random(3),
              __DIR__"npc/player" : random(1),
         ]));
	set("no_clean_up", 0);
	setup();
}

void init()
{
        add_action("do_use", "use");
}
int do_use(string arg)
{
        object me,ob;
        me = this_player();
        if( !arg || arg=="" ) return 0;
        if (!present("fire",me)) return 0;
        if( arg=="fire" ) {
        remove_call_out("close");
        call_out("close", 15, this_object());
        message("vision","�ڻ���£��㿴����Χ�������!!\n", me);
        set("long", @LONG
   һ�������������, �������ƺ��������µ��������������ȥ, ��
����С��Խ�����������ˮ��Խ��, �����������Ҳ��������ȫ����
ס��. ��������Ѿ��޷�����ؿ������ܵ�״����, ֻ֪����Ľ��Ѿ�
���������������.�ڻ�����㿴���˳�·!!
LONG
        );

	set("exits", ([
		"east" : __DIR__"dong1"+(random(6)+3),
		"south" : __DIR__"dong1"+(random(6)+3),
                "west" : __DIR__"dong18",
                "north" : __DIR__"dong1"+(random(6)+3),
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong1"+(random(6)+3),
                "west" : __DIR__"dong18",
	]));
if (random(4)==1)
	set("exits", ([
		"south" : __DIR__"dong1"+(random(6)+3),
                "north" : __DIR__"dong1"+(random(6)+5),
	]));
           if ( objectp(ob=present("fire", this_player())) )     {
            destruct(ob);
        return 1;
       }
        return notify_fail("������ʲô�������\n");
        }
}

void close(object room)
{
        message("vision","��һ�������Ϩ���ˡ�\n", room);
        set("long", @LONG
   һ�������������, �������ƺ��������µ��������������ȥ, ��
����С��Խ�����������ˮ��Խ��, �����������Ҳ��������ȫ����
ס��. ��������Ѿ��޷�����ؿ������ܵ�״����, ֻ֪����Ľ��Ѿ�
���������������.
LONG
);
        room->delete("exits");
}