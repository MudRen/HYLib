//cool 98.4.18
inherit ROOM;
void create()
{
	set("short", "��Ժ");
	set("long", @LONG
�����Ǻ�Ժ������Щ�ɻ����µĵط��������ȥ���ǲ񷿣�������
һ��ˮ��������ææµµ�Ľ����������Լ��Ļ
LONG);
	set("exits", ([
               "east" : __DIR__"chaifang",
               "west" : __DIR__"shuifang",
	       "north" : __DIR__"houyuan2",
	       "south" : __DIR__"shilu-3",
        ]));
        set("outdoors", "���");
	setup();
        replace_program(ROOM);
}

