// Room: /dream/qulang3.c

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
		"westup" : __DIR__ "jiaolou3",
		"east" : __DIR__ "ouxiang",
        ]));
	setup();
	replace_program(ROOM);
}

