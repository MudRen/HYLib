// This is a room made by wsl.
inherit ROOM;
void create()
{
    set("short", "�����Ǵ��");
    set("long",@LONG
�����ڳ����ǵĴ���ϣ�������������ﲻ���������ȥ������
�����ݵ�������Ů����˵�����и������ӣ�������׼�ģ���Ҳ���
�㣬��ȥ�۸�ͷ��������������һ����Ρ�
LONG
);
        set("outdoors","changan");
    set("exits", ([
        "south" :__DIR__"ca7",
        "west" :__DIR__"ca10",
       "north":__DIR__"ca21",
        "east" :__DIR__"ca11",
]));
    setup();
    replace_program(ROOM);
}
