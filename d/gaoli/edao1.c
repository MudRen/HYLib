// /d/gaoli/xuanwumen
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
		"east" : __DIR__"qinglongmen",
		"west" : __DIR__"edao2",
	]));

 	set("outdoors", "/d/gaoli");
	setup();
	replace_program(ROOM);
}


