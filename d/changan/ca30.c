// This is a room made by wsl.

inherit ROOM;

void create()
{
    set("short", "��ǽ");
    set("long", @LONG
�Գ�ǽΪ���壬�������Ǻӡ����š�բ¥����¥����¥����¥��
Ů��ǽ��ڡ����ŵ�һϵ�о�����ʩ�����ɳ��������������ķ�����
ϵ��
LONG
);
        set("outdoors","changan");
    set("exits", ([
       "down":__DIR__"dongmen",
]));
    setup();
    replace_program(ROOM);
}
