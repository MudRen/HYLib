// baling/edao1
// Room in ����
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵ����̣�
���Ŵ󳵵���������������ǳ����֡���ʱ����������������߷�
�۶���������һ·��������·��������������������֡�
LONG
	);

	set("exits", ([
		"northeast" : __DIR__"edao13",
    "south" : "/d/kunming/yunnan4",
	]));

 	set("outdoors", "baling");
	setup();
	replace_program(ROOM);
}


