// Room: /lanzhou/jioudian.c
// xws 1998/10/14 

inherit ROOM;

void create()
{
	set("short", "ӭ��Ƶ�");
	set("long", @LONG
    ��Բ����������������ӭ���¥����˵�����˲�֪�����˲��������������
��ӭ���¥�Ļ�����޲����ڡ���վ�ھƵ��ڣ����������ص���ζ����������
Ʈ����
LONG
	);

	set("exits", ([
		"north" : __DIR__"xiaojisi",
		]));

	set("objects", ([
		__DIR__"npc/xiaoer3" : 1,
	]));

	setup();
	replace_program(ROOM);
}

