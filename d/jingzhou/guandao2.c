// Room: /d/jingzhou/guandao2.c
// netkill /98/8/14/


inherit ROOM;

void create()
{
        set("short", "�ٵ�" );
        set("long", @LONG
������һ����ٵ��ϣ����Բ�ʱ���˴�������߹������Էֱ�
���м����ǽ������ˡ�������Լ���Կ������ݣ����ߺ�һ��С·������
LONG
        );
        set("exits", ([
  "east" : __DIR__"guandao1",
  "west" : __DIR__"guandao3",
]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        replace_program(ROOM);
}

