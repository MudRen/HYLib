inherit ROOM;

void create()
{
        set("short", "���µ�");
        set("long", @LONG
�����ǳ������¹󸾳���֮��������Ҳ��������Ҳң�֬�ۺ�ɡ���Ϊ
��������ʱ�У�һֱ�����������Ե�װ�硣�����Ǹ��ܿ��˵�СŮ��������
��һ������ʱ���������������Ů�˼���һ�𣬻�������������
    ���ſں�������д�ż�������(zi)����������С���ֱʡ�
LONG );
        set("item_desc", ([
                "zi": "list ����\"buy\" ��\n",
        ]));
        set("exits", ([
                "east" : __DIR__"ca7",
        ]));
        set("objects", ([
                __DIR__"npc/zeng": 1,
        ]));
//      set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

