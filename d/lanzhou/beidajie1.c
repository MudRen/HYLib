// Room: /lanzhou/beidajie1.c
// xws 1998/10/14 
inherit ROOM;
void create()
{
	set("short", "�����");
	set("long", @LONG
	������һ����æ�Ľֵ��ϣ����Ų�����ǻ������������ɫ�Ҵң������
�����ϱ���ȥ��������һ�����ֵĹ㳡��������һ�����ֵĲ��г�����������������
����
LONG
	);
        set("outdoors", "lanzhou");
	set("exits", ([
		"east" : __DIR__"caisicang",
		"south" : __DIR__"guangchang",
		"north" : __DIR__"beidajie2",
	]));
	setup();
	replace_program(ROOM);
}

