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
           "west":__DIR__"swordroom",
           "north":__DIR__"shidao3",
           "east":__DIR__"uroom",
]));
        set("objects", ([
            __DIR__"obj/skeleton" : 1+random(10),
]));
    setup();
}
