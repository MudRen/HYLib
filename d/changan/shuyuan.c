inherit ROOM;
void create()
{
        set("short", "̫�׾�");
        set("long", @LONG
������̫����������������������һ����Ⱦ��������������������ѧ��ѧ����
һ�Ź��ⰻȻ���鰸����̫��������ǰ�棬���ϰ��ż��������˵���װ�鼮��̫��
�����������һ�����(shujia)�����ڶ��������ʯ�̣����Ϸ����и����ң�pai)
��  
LONG
        );
        set("exits", ([
                "north" : __DIR__"shuyuan2",
                "northeast" : __DIR__"dongmen",
        ]));
        set("item_desc", ([
                   "pai" : "\n���ڳ���������������Fͬ���ơ�"
                           "\n�ⰶң�ٺ�ʿǰ�������������˺�"
                           "\n���Ӻ��������꣬��̨��������ޡ�"
                           "\n������������������������ۡ�\n\n",
        "shujia":"�����һ����Ⱦ��������̫������������д����ʫƪ��\n",
        ]));
        
        set("objects", ([
                __DIR__"npc/libai": 1,
        ]));
        setup();
}
int valid_leave(object me, string dir)
{
        if (dir == "north" && (userp(me) && !wizardp(me)))
                return notify_fail("����̫��������˽�����ң�\n");
        return 1;
}

