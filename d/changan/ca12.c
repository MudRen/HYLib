
// This is a room made by wsl.
inherit ROOM;
void create()
{
    set("short", "�����Ǵ��");
    set("long", @LONG
�����ڳ����ǵĴ���ϣ��������������������ǳ������������
��ҩ�̣�����
LONG
);
        set("outdoors","changan");
    set("exits", ([
       "south" :__DIR__"ca13",
       "west" :__DIR__"ca14",
       "east" :__DIR__"ca15",
       "north" :__DIR__"ca",
]));
    setup();
    replace_program(ROOM);
}
