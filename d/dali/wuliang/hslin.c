// Room: hslin.c
// By River 98/12
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "��ɭ��");
        set("long", @LONG
��첽���У�ֻ��ӭ���ѹѹ��һ����ɭ�֡��߽�ǰȥ��ֻ������һ�ž�
����������첢�У�������Щ������ 
LONG
        );
        set("exits", ([
            "south" : __DIR__"tiesuo",
        ]));
 
        set("outdoors", "����");

        setup();
}

void init()
{
        add_action("do_enter","enter");
}

int do_enter(string arg)
{
        object me=this_player();
        if ( !arg ) return 0;
        if ( arg=="������" ){
        write(HIW"\n���Ƶ����������󣬲������ݣ����ϳ���һ������������������ֲ����ݲݣ�\n"+
              "��������һ������������������ľ���ƿ����������һ��ʯ�������¼�����\n"+
              "˫������ľ��Ż�ԭ������ʯ��������ȥ����ʮ�༶��ʯ����ת�����ɺ��۶�\n"+
              "���ϣ�������ʮ�༶������ƽ�ء�\n\n"NOR,me);
        me->move(__DIR__"caodi");
        return 1;
        }
       return 0;
}
