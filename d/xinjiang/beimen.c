 inherit ROOM;
void create()
{
        set("short", "������������");
        set("long", @LONG
����������Ԫ�����������������ֵĳ�������İ�����������ʷ�ƾ�
�������������������й�ǧ�����ʷ���������ν��ʮ�ﳤ�֣������Ƽ�����
���Ͼ��Ǵ��������������һ���������ֵı�����
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"tulu",
  "south" : __DIR__"wuming",
]));
        set("objects", ([
        __DIR__"npc/wall_solider" : 2,
                        ]) );
        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
        set("coor/x",-1120);
        set("coor/y",2110);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}    
