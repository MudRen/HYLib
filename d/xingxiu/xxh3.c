// Room: /d/xingxiu/xxh3.c
// Jay 3/18/96

inherit ROOM;

void create()
{
        set("short", "���޺�");
        set("long", @LONG
���������޺��ߡ�˵�Ǻ�����ʵ��Ƭ���������󣬵���ʮ���ն�
����ͨ�����޺������
LONG );
        set("objects", ([
                __DIR__"npc/gushou"  : 1,
    "quest/menpai/xingxiu/shi" : 1,
	]) );
        set("exits", ([
             "southwest" : __DIR__"xxh2",
             "northwest" : __DIR__"xxh5",
        ]));
//        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");
    set_temp("wayao2",2);
        setup();
        replace_program(ROOM);
}

