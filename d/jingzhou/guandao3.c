// Room: /d/jingzhou/guandao3.c
// netkill /98/8/14/


inherit ROOM;

void create()
{
        set("short", "��ʯ��" );
        set("long", @LONG
�ӽ����ݣ�·�ɻ����������ʯ��·�����Խ������Կ���һЩũ�ᣬ
ũ����֣�������Ʈ���ųƾ���Ϊ����Ҫ�أ�����Ϊ��һ������Ϊ���
����������ȥ���ɼ����ݵĳ�¥��.
LONG
        );
        set("exits", ([
  "east" : __DIR__"guandao2",
  "west" : __DIR__"jzdongmen",
]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        replace_program(ROOM);
}

