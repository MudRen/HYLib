// Room: /dream/qulang4.c

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
	���������Ļ��ȣ����¾���ź���ˮ���������Ǵ��̵ĺ�Ҷ���м��׺�Ŷ�
���ɫ�ɻ���ż�����Կ�����������ںɼ���߮��Զ��Ʈ��ʱ��ʱ����������������
��������Ȼ���ˡ�
LONG
	);
        set("outdoors", "tangmen");
	set("exits", ([
		"west" : __DIR__ "ouxiang",
		"east" : __DIR__ "jingyitang",
        ]));
	setup();
	replace_program(ROOM);
}

