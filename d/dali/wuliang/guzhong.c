// Room: guzhong.c
// By River 98/12
inherit ROOM;
void create()
{
        set("short", "��ٹ�");
        set("long", @LONG
����������ٹ��ڣ����治Զ���Ǽ����߷������ױ�����һ��С�߷�����
�ߵ�ɽ�ںܶ��ͣ�������û�����µġ�����һ��С·�ƹ�����ķ���ͨ���Ⱥ�
��֪ȥ��ʲô�ط���
LONG
        );
        set("exits", ([
            "north" : __DIR__"xiaojing",
            "south" : __DIR__"keting",
            "west" : __DIR__"xiaoting",
        ]));

        set("objects", ([
              __DIR__"npc/laifu_er" : 1,
              __DIR__"npc/jinxi_er" : 1,
        ]));
        
        set("outdoors", "����");

        setup();
        replace_program(ROOM);
}
