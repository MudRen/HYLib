// majiu.c ���
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���Ǹ������֧������������ʮ���ɳ�������˩�ż���ƥ������
��࣬ȴ�ǰ����ֵַģ�ż���м���˻������������ԭ���ѱ��֮����ȷ
������һ���������Աߺ������������ּ�Ǯ�������ǵķ��κ����Ǵ�ңԶ
�Ĳ�˹������
LONG);
        set("resource/water", 1);
        set("exits", ([
            "north" : __DIR__"caoyuan1",
            "east" : __DIR__"hsk",            
        ]));
        set("objects", ([
                    __DIR__"npc/xiaoxiang" : 1,
        ])); 
        set("outdoors", "gaochang");        
        setup();
        replace_program(ROOM);
}
