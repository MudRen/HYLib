// Room: /lanzhou/beidajie2.c
// xws 1998/10/14 
inherit ROOM;
void create()
{
	set("short", "�����");
	set("long", @LONG
	������һ����æ�Ľֵ��ϣ����Ų�����ǻ������������ɫ�Ҵң������
�����ϱ���ȥ��������һ�����ֵĹ㳡��������һ��С�Թݣ�������ζƮ������
��ֱ����ˮ��
LONG
	);
        set("outdoors", "lanzhou");
	set("exits", ([
		"west" : __DIR__"xiaochidian",
		"south" : __DIR__"beidajie1",
		"north" : "/d/lanzhouchen/road2",
	]));
	setup();
	replace_program(ROOM);
}

