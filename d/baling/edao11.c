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
		"southwest" : __DIR__"edao12",
                "north" : __DIR__"edao10",
	]));

 	set("outdoors", "baling");
	setup();
	replace_program(ROOM);
}


