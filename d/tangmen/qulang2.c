// Room: /dream/qulang2.c

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
	���������Ļ��ȣ����¾���ź���ˮ���������Ǵ��̵ĺ�Ҷ���м��׺�Ŷ�
���ɫ�ɻ���ż�����Կ�����������ںɼ���߮���ղŵ����������������������ǰ
�治Զ����
LONG
	);
        set("outdoors", "tangmen");
	set("exits", ([
		"northwest" : __DIR__ "qulang1",
		"southwest" : __DIR__ "ouxiang",
        ]));
	setup();
	replace_program(ROOM);
}

