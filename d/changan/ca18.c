// This is a room made by Wsl.
inherit ROOM;
void create()
{
        set("short", "�����Ǵ��");
        set("long", @LONG
�����̿����ﲻ����ɽ�˺�����������һƬ�����ľ��󣬱�����
��һ���Ҵ�ġ��ơ������ƣ�������Ǿ��ǳ��������������򸣾�¥
��������һ��С���֪����ȥ�����
LONG
);
        set("outdoors","changan");
        set("exits", ([
       "east":__DIR__"ca",
       "west":__DIR__"ximen",
       "south":__DIR__"ca23",
      "north" :__DIR__"ca2",
]));

        setup();
        replace_program(ROOM);
}

