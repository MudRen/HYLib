// baling/edao1
// Room in ����
inherit ROOM;

void create()
{
	set("short", "�ɽ��");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵ����̣�
���Ŵ󳵵���������������ǳ����֡���ʱ����������������߷�
�۶���������һ·��������·��������������������֡�
LONG
	);

	set("exits", ([
		"east" : __DIR__"edao2",
                "west" : __DIR__"dongmen",
	]));

 	set("outdoors", "baling");
	setup();
	replace_program(ROOM);
}


