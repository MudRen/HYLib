// baling/edao1
// Room in ����
inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
���Ų����У��ٲ�̤���ľ��ǰ������ݣ�����û��·��ÿ��һ����
���������̵�С�ȣ�����������塣
LONG);

	set("exits", ([
                "westdown" : __DIR__"shanjiao",
               "eastup" : __DIR__"shanlu",
               "eastdown" : __DIR__"xiagu1",
	]));

 	set("outdoors", "baling");
	setup();
	replace_program(ROOM);
}


