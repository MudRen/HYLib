inherit ROOM;
void create()
{
        set("short", "�򸣵䵱");
        set("long", @LONG
������Ƿ�Բ������һ�������򸣵䵱�С�
LONG );
        set("exits", ([
                "west" : __DIR__"stbeijie1",
	]));

	set("no_fight",1);
        set("no_sleep_room",1);

	set("objects", ([
                __DIR__"npc/yin" : 1,
      	]));

	setup();
}
