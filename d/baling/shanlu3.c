// baling/edao1
// Room in ����
inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
��С������Ĵ���һ���ܶ��͵�ɽ·�ϣ�б�²������ɵ���ȥ��
����������ġ������Ӳݴ�����ʮ�ֻ���������ɢ�ż���Ǻ���
LONG);

	set("exits", ([
               "southdown" : __DIR__"shanlu4",
               "northup" : __DIR__"xiaoxi",
	]));

 	set("outdoors", "baling");
	setup();
	replace_program(ROOM);
}


