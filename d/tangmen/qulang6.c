// Room: /dream/qulang6.c
// xws 1998/11/05
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
		"northeast" : __DIR__ "qulang5",
		"southeast" : __DIR__ "kuixinlou",
        ]));
	setup();
	replace_program(ROOM);
}

