// This is a room made by wsl.

inherit ROOM;

void create()
{
    set("short", "ʯ��");
    set("long", @LONG
����һ����ɭ�ĵ�·��������һ������ٸ�ӣ����������ĺ��ǣ�
������ʼ�ʽ���������Ĺ�󣬰�ȫ����ʩ���߶�ɱ���������ˣ���ֻ
�����е�ë���Ȼ��
LONG
);
        set("exits", ([
           "south":__DIR__"shidao4",
           "north":__DIR__"outroom",
           "west":__DIR__"clubroom",
           "east":__DIR__"axeroom",
]));
        set("objects", ([
             __DIR__"obj/skeleton" : 1+random(10),
]));
    setup();
}
