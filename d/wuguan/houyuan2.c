//cool 98.4.18

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
������Ȼ�Ǻ�Ժ�����治ʱ������˻�����㿴��ȥ�������Ǹ�����
����������Ҳ�ǳ����ģ������Ǿ�ľͷ��������
LONG);
	set("exits", ([
	      "west" : __DIR__"mafang",
              "east" : __DIR__"mufang",
	      "south" : __DIR__"houyuan",
              "north" : __DIR__"houyuan3",

        ]));
        set("outdoors", "���");
	setup();
        replace_program(ROOM);
}

