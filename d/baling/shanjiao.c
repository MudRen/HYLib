// baling/edao1
// Room in ����
inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
������һ����������Ĵ�����ϡ�������һ��ɽ����ǰ�棬�����
˳ɽ���ޣ����ѵ��򱱶�ȥ��һ��С��˳ɽ�ƽ���ɽ�ϵ������С�
LONG
	);

	set("exits", ([
		"west" : __DIR__"edao2",
                "northwest" : __DIR__"edao3",
                "eastup" : __DIR__"shanru",
                "south" : __DIR__"edao10",
	]));

 	set("outdoors", "baling");
	setup();
	replace_program(ROOM);
}


