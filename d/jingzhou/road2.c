// Room: /d/jingzhou/road2.c

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
����һ����ʯ�����������Լ���Կ������ݳǵĳ�ǽ������
��ȥ��ֻ��Ⱥɽ����������̣���֪ͨ�����
LONG
        );
        set("exits", ([
  "east" : __DIR__"road1",
  "west" : __DIR__"road3",
]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        replace_program(ROOM);
}

