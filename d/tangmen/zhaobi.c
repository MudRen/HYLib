// Room: /dream/zhaobi.c
// HEM 1998/11/5
inherit ROOM;
void create()
{
	set("short", "�ձ�");
	set("long", @LONG
	����һ��������ձڣ���������������룬������֣��·�Ҫ�Ʊڶ���������
����һͨ�����ƹ��ձڣ��Ϳ��Խ��롰�����á���
LONG
	);
        set("outdoors", "tangmen");
	set("exits", ([
		"north" : __DIR__ "damen",
		"southwest" : __DIR__ "liujiantang",
                "southeast" : __DIR__ "liujiantang",
	]));
	setup();
	replace_program(ROOM);
}

