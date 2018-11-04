
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"����֮ɭ"NOR);
	set("long", HIG @LONG
    ������һ�����ϵ�ԭʼɭ�֣������������ľ���������ǹ��϶�
��ɣ���ݷ������������µ�ĥ��������������ɭ�ֲ����ϣ�������ݺ
�������в����ܷҶྫ��޹�ա��ߴ����ľ��ס�����⣬��ʲôҲ�������ˡ�
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);
set("no_npc",1);
         set("objects", ([
              __DIR__"npc/lev2" : random(2),
              __DIR__"npc/lev3" : random(2),
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
    ������һ�����ϵ�ԭʼɭ�֣������������ľ���������ǹ��϶�
��ɣ���ݷ������������µ�ĥ��������������ɭ�ֲ����ϣ�������ݺ
�������в����ܷҶྫ��޹�ա��ڻ�����㿴���˳�·��
LONG
        );
	set("exits", ([
		"east" : __DIR__"dong14",
		"south" : __DIR__"dong11",
                "west" : __DIR__"dong12",
                "north" : __DIR__"dong13",
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
    ������һ�����ϵ�ԭʼɭ�֣������������ľ���������ǹ��϶�
��ɣ���ݷ������������µ�ĥ��������������ɭ�ֲ����ϣ�������ݺ
�������в����ܷҶྫ��޹�ա�
LONG
);
        room->delete("exits");
}