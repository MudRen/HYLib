// baling/edao1
// Room in ����
inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
�����Ǹ�б�£���С����������ţ�б�²������ɵ���ȥ����
��������ġ������Ӳݴ�����ʮ�ֻ���������ɢ�ż���Ǻ���
LONG
	);

	set("exits", ([
                "westdown" : __DIR__"shanru",
               "eastup" : __DIR__"shanding",
	]));

 	set("outdoors", "baling");
	setup();
	replace_program(ROOM);
}


