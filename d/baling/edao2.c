// baling/edao1
// Room in ����
inherit ROOM;

void create()
{
	set("short", "�潭��");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵ����̣�
���Ŵ󳵵���������������ǳ����֡���ʱ����������������߷�
�۶���������һ·��������·��������������������֡�
LONG
	);

	set("exits", ([
		"east" : __DIR__"shanjiao",
                "west" : __DIR__"edao1",
	]));

 	set("outdoors", "baling");
	setup();
	replace_program(ROOM);
}


