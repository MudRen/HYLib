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
           "south":__DIR__"shidao3",
           "west":__DIR__"staffroom",
           "east":__DIR__"whiproom",
           "north":__DIR__"shidao5",
]));
        set("objects", ([
             __DIR__"obj/skeleton" : 1+random(10),
]));
    setup();
}
