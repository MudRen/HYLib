// Room: /u/bobo/tiezhang/taijie-1.c

inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
һ��ʯ�ױ�ֱ���£���ʧ��ŨŨ�ĺڰ��С�ʯ���ϳ�������ɫ����̦����
�����š�������Ŀ�������ǿ�����Զ�����龰��
LONG
        );

        set("exits", ([ 
"out" : __DIR__"trdx",
"westdown" : __DIR__"taijie-2",
]));

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

