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
               "southeast" : __DIR__"shanyabei",
               "northup" : __DIR__"shanlu3",
	]));

 	set("outdoors", "baling");
	setup();
	replace_program(ROOM);
}


