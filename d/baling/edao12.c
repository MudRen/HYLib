// baling/edao1
// Room in ����
inherit ROOM;

void create()
{
	set("short", "�뽭��");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵ����̣�
���Ŵ󳵵���������������ǳ����֡���ʱ����������������߷�
�۶���������һ·��������·��������������������֡�
LONG
	);

	set("exits", ([
                "northeast" : __DIR__"edao11",
	]));

 	set("outdoors", "baling");
	setup();
	replace_program(ROOM);
}


