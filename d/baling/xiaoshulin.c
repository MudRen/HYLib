// baling/edao1
// Room in ����
inherit ROOM;

void create()
{
	set("short", "С����");
	set("long", @LONG
��˳��Ͽ�ȼ��ѵ����ţ�����һƬ�����֣�ï�����ְ����ⶼ��ס
�ˣ�һ���������۵�С·��֪ͨ�����
LONG);

	set("exits", ([
                "west" : __DIR__"xiagu",
	]));

 	set("outdoors", "baling");
        set("objects", ([
		__DIR__"npc/she" : 2
	]));
	setup();
	replace_program(ROOM);
}


