// This is a room made by wsl.

inherit ROOM;

void create()
{
    set("short", "��վ");
    set("long",@LONG
�����ǳ�����վ�����ڸ������н������������ʴ��Ͷ�Ҫͨ�����
�����վ����Ⱥ����������һƬæµ�ľ���վǰ����һ��ʯ׮������
һЩ����ʹ󳵣��������������Ĵ��������⡣
LONG
);
    set("exits", ([
       "east":__DIR__"ca21",
]));
    setup();
    replace_program(ROOM);
}
