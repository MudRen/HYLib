inherit ROOM;

void create()
{
        set("short", "���ݱ���");
        set("long", @LONG
�����Ѿ��������ݵı����ˣ��߸ߵĳ�ǽ��ש���ﳤ����
�ݡ��߹����ţ��ٹ��˻��Ǻӣ����ǳ����ˡ�
LONG);
        set("outdoors", "zhongzhou");
        set("exits", ([
  		"north" : __DIR__"to_zhongzhou3",
  		"south" : __DIR__"wendingbei4",
	]));
        set("objects", ([
                __DIR__"npc/walker" : 1,
  		"/d/city/npc/bing" : 4,
  		"/d/city/npc/xunbu" : 1,
	]));
        set("no_clean_up", 0);

        set("coor/x", -230);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
