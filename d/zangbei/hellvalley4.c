 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "�����ȵ�");
        set("long", @LONG
�������ԭ�����Ǹ�ɽ�ȣ������Ǹ����²������ɵ�ɽ�ȣ��ȵص��ס�����̦��
�ݡ��١�Ҷ����ð�����������ۼ��ڶ��ϣ��γ�����ͬ����һ�����������ס�˹�
�׵���ʵ�����������������ж��ԣ�Ѱ���ķ�������մ��һ��ͻ��Ե���ȥ������
�ľ���ԶԶ�ܿ���ʹ���������������ѵ���Ȼ�������塣��
LONG
        );
        set("exits", ([ 
     //           "east":  __DIR__"diyugu",
        ]));
        set("objects", ([
                __DIR__"npc/xie":       1,
                __DIR__"npc/tianmei":   1,
        ]) );
        set("outdoors", "zangbei");
            set("coor/x",-1000);
        set("coor/y",2150);
        set("coor/z",30);
        setup(); 
}       
void init()
{
        add_action("climbing", "climb");
} 
int climbing(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("��Ҫ��ʲô��\n");
                return 1;
        }
        if( arg == "valley" || arg == "up" || arg == "ɽ��")
        {
        me = this_player();
        if (me->query_temp("climbup")) {
                        write("���Ѿ������ˡ�\n");
                        return 1;
                        }
        message_vision("$Nץ��ͻ����ʯ�ǣ�������˳�Źȱ�������ȥ��\n", me);
        me->start_busy(5);
        call_out("fliping",2,me);
//      me->stop_busy();
        me->set_temp("climbup",1);
        return 1;
        }
        else
        {
                write("�㲻������"+arg+"\n");
                return 1;
        }
}
void fliping(object me)
{
        object room;
        if( !me->is_ghost()) {
        room = find_object(__DIR__"cliff");
        if(!objectp(room)) room= load_object(__DIR__"hellvalley3.c");
        me->move(room);     
        message_vision("$N˳�Źȱ�����������\n", me);  
        }
        me->delete_temp("climbup");
        return;
}        
