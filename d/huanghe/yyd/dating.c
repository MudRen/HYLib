// �������� dating.c
// zly 1999.06.10
 
inherit ROOM; 
 
void create() 
{ 
        set("short", "��������");
        set("long", @LONG
������������Ĵ��������ɷǷ���װ���ݻ�������һ��̫ʦ�Σ�����
�Ϻ�����գ��������е������ϣ�����һ����߼����Ľ�ɫ���١���
�����������������������к��������ٵ��ĸ�·Ӣ�ۡ�
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ 
            "north" : __DIR__"houyuan",
            "west" : __DIR__"chufang",
            "south" : __DIR__"damen",
            "east" : __DIR__"shufang"
]));

        set("objects", ([
            __DIR__"npc/xiao" : 1,
            __DIR__"npc/linyl" : 1,
            __DIR__"npc/renfy" : 1,
]));

        setup();
        replace_program(ROOM);
}
