// Room: /lanzhou/nandajie1.c
// xws 1998/10/14 
inherit ROOM;
void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
������һ����æ�Ľֵ��ϣ����Ų�����ǻ������������ɫ�Ҵң�����˶�����
����ȥ��������һ�����ֵĹ㳡�����ߴ���һ��������ײ�����������Ƕ���һ����
�ֺŵ����ţ�
LONG
	);
        set("outdoors", "lanzhou");
	set("exits", ([
		"south" : __DIR__"nandajie2",
		"north" : __DIR__"guangchang",
		"east" : __DIR__"qianzhuang",
	]));
	setup();
	replace_program(ROOM);
}

