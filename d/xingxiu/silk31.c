// /d/xingxiu/silk1.c
// June 97
// by pishou

inherit ROOM;

void create()
{
        set("short", "˿��֮·");
        set("long", @LONG
�������������˿���̵���ӭ���������һ����ɳ���������岼춻�ԭ֮
�ϡ�һ���ɳ�������󵶸�һ��˺��������������Ϲ����ɽͨ�������أ���
��������Ħ�¡�
LONG);
        set("outdoors", "yili");

        set("exits", ([
                "westup" : __DIR__"silk32",
                "south" : __DIR__"silk3",
        ]));


        setup();
//        replace_program(ROOM);
}

