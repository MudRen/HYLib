// Room: /d/wizhome/incahome/nroad1.c
// Date: inca 98/08/13

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵġ�����
�ġ����Ŵ󳵵���򡢴�����˶�������ȥ���ǣ������������ǳ����֡�
��ʱ����������������߷ɳ۶���������һ·��������·����������
����������֡�������ԶԶ�ľͿ������������ǵı����š�
LONG
	);

	set("exits", ([
		"south" : __DIR__"beimen",
		"north" : __DIR__"nroad2",
	]));

        set("outdoors", "changcheng");

	setup();
	replace_program(ROOM);
}



