// Room: /dream/qulang1.c
// BY hem
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
		"north" : __DIR__ "paifang",
		"southeast" : __DIR__ "qulang2",
        ]));
	setup();
	replace_program(ROOM);
}

