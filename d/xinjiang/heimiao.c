 inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
������û�б����ɫ��ֻ�кڣ���Ϧ���ս����������һ�ֲ����������ɫ��
��ɫ����ᣵʹ���û�����ܿ��ü����湩�����ʲô���������Ϸ�������������
���аѵ���������ڣ�������ڡ�
LONG
        );
        set("exits", ([ 
  "northwest" : __DIR__"sichou5",
"south" : "/d/xingxiu/shanjiao",
]));

        set("objects", ([
        __DIR__"npc/furen" : 1,
//            "/obj/specials/ding/ding_xj" : 1,
                        ]) );
        
        
        set("NONPC",1);
        set("valid_startroom", 1);
        set("coor/x",-1000);
        set("coor/y",2000);
        set("coor/z",0);
        setup();
}

